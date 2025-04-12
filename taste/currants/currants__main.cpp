#include <stlab/concurrency/concurrency.hpp>
#include <stlab/pre_exit.hpp>
#include <iostream>
#include <functional>
#include <utility>
#include <chrono>
#include <tuple>
#include <thread>
#include <any>
#include <string>
#include <vector>

struct sum
{
    stlab::process_state _state = stlab::process_state::await;
    int _sum = 0;
    void await(int n) { _sum += n; }
    int yield() { _state = stlab::process_state::await; return _sum; }
    void close() { _state = stlab::process_state::yield; }
    auto state() const { return std::make_pair(_state, std::chrono::milliseconds(0)); }
};

auto get_fun() -> std::function<auto (std::tuple<int, int, int> v) -> void>
{
    return [](std::tuple<int, int, int> v) {
        std::cout << "receive zip:" << std::get<0>(v) << "," << std::get<1>(v) << "," << std::get<2>(v) << '\n';
    };
}

template <typename Inputs = std::tuple<>, typename Outputs = std::tuple<>>
struct processor;

template <typename Inputs, typename Outputs>
struct processor
{
    template <std::size_t From, std::size_t To, typename Processor>
    inline auto from(Processor & other) -> void
    {
        std::tie(std::get<From>(other._senders), std::get<To>(_receivers)) = stlab::channel<std::tuple_element_t<To, Inputs>>(stlab::default_executor);
    }

    template <std::size_t From, std::size_t To, typename Processor>
    inline auto to(Processor & other) -> void
    {
        std::tie(std::get<From>(_senders), std::get<To>(other._receivers)) = stlab::channel<std::tuple_element_t<From, Outputs>>(stlab::default_executor);
    }

    inline auto on_your_marks() -> void
    {
        if constexpr (std::tuple_size_v<Inputs> != 0)
        {
            std::apply([this](auto const & ... recv) {
                _zip = stlab::zip(stlab::default_executor,
                    recv ...) | [this](Inputs inputs) {
                        go(inputs);
                    };
            }, _receivers);
        }
    }

    inline auto get_set() -> void
    {
        if constexpr (std::tuple_size_v<Inputs> != 0)
        {
            std::apply([](auto & ... recv) {
                ((recv.set_ready()), ...);
            }, _receivers);
        }
    }

    inline auto go(Inputs inputs) const -> void
    {
        send(process(inputs));
    }

    inline auto send(Outputs outputs) const -> void
    {
        send_rest(outputs);
    }

    static inline auto process(Inputs inputs) -> Outputs
    {
        std::string concat = ":";
        if (std::tuple_size_v<Inputs> != 0)
        {
            std::apply([&concat](auto ... inpt) {
                ((concat += inpt), ...);
            }, inputs);
        }
        concat += ".";
        Outputs outputs;
        if (std::tuple_size_v<Outputs> != 0)
        {
            std::apply([&concat](auto & ... outp) {
                ((outp = concat), ...);
            }, outputs);
        }
        std::cout << "process " << concat << "\n";
        return outputs;
    }

private:
    template <std::size_t Index>
    inline auto send_one(Outputs outputs) const -> void
    {
        std::get<Index>(_senders)(std::get<Index>(outputs));
    }

    template <std::size_t Index = 0>
    inline auto send_rest(Outputs outputs) const -> void
    {
        if constexpr (Index < std::tuple_size_v<Outputs>)
        {
            send_one<Index>(outputs);
            std::cout << "sent\n";
            send_rest<Index + 1>(outputs);
        }
    }

    template <typename Tuple>
    struct _tuple_senders;

    template <typename ... Elements>
    struct _tuple_senders<std::tuple<Elements ...>>
    {
        using type = std::tuple<stlab::sender<Elements> ...>;
    };

    template <typename Tuple>
    struct _tuple_receivers;

    template <typename ... Elements>
    struct _tuple_receivers<std::tuple<Elements ...>>
    {
        using type = std::tuple<stlab::receiver<Elements> ...>;
    };

    typename _tuple_senders<Outputs>::type _senders;
    typename _tuple_receivers<Inputs>::type _receivers;
    std::any _zip;

    template <typename Ins, typename Outs>
    friend struct processor;
};

template <typename Signal>
struct signal_processor
{
    inline signal_processor(std::size_t inputs, std::size_t outputs)
        : _receivers(inputs), _senders(outputs), _zip{}
    {
    }

    inline auto from(signal_processor & other, std::size_t input, std::size_t output) -> void
    {
        std::tie(other._senders[output], _receivers[input]) = stlab::channel<Signal>(stlab::default_executor);
    }

    inline auto to(signal_processor & other, std::size_t input, std::size_t output) -> void
    {
        std::tie(_senders[output], other._receivers[input]) = stlab::channel<Signal>(stlab::default_executor);
    }

    inline auto on_your_marks() -> void
    {
        switch (_receivers.size())
        {
            case 0:
                return;
            case 1:
                _zip = _receivers[0] | [this](Signal input) {
                        go(std::vector<Signal>{input});
                    };
                return;
            case 2:
                _zip = stlab::zip(stlab::default_executor,
                    _receivers[0],
                    _receivers[1]) | [this](std::tuple<Signal, Signal> inputs) {
                        go(std::apply([](auto ... input) {
                            return std::vector<Signal>{input ...};
                        }, inputs));
                    };
                return;
            case 3:
                _zip = stlab::zip(stlab::default_executor,
                    _receivers[0],
                    _receivers[1],
                    _receivers[2]) | [this](std::tuple<Signal, Signal, Signal> inputs) {
                        go(std::apply([](auto ... input) {
                            return std::vector<Signal>{input ...};
                        }, inputs));
                    };
                return;
            default:
                throw std::runtime_error("too many inputs");
        }
    }

    inline auto get_set() -> void
    {
        for (auto & recv : _receivers)
        {
            recv.set_ready();
        }
    }

    inline auto go(std::vector<Signal> inputs) const -> void
    {
        send(process(inputs));
    }

    inline auto send(std::vector<Signal> outputs) const -> void
    {
        for (std::size_t i = 0; i < outputs.size(); ++i)
        {
            _senders[i](outputs[i]);
            std::cout << "sent\n";
        }
    }

    inline auto process(std::vector<Signal> inputs) const -> std::vector<Signal>
    {
        std::string concat = ":";
        for (auto input : inputs)
        {
            concat += input;
        }
        concat += ".";
        std::cout << "process signal " << concat << "\n";
        return std::vector<Signal>(_senders.size(), concat);
    }

private:
    std::vector<stlab::receiver<Signal>> _receivers;
    std::vector<stlab::sender<Signal>> _senders;
    std::any _zip;
};

int main()
{
    std::cout << "currants\n";
    {   // single channel
        stlab::sender<int> send;
        stlab::receiver<int> receive;
        std::tie(send, receive) = stlab::channel<int>(stlab::default_executor);
        auto discard = receive | [](int x) {
            std::cout << "received: " << x << "\n";
        };
        std::cout << "receive.ready(): " << receive.ready() << "\n";
        receive.set_ready();
        std::cout << "receive.ready(): " << receive.ready() << "\n";
        send(42);
        std::cout << "sleep\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    {   // non-std coroutine
        stlab::sender<int> send;
        stlab::receiver<int> receive;
        std::tie(send, receive) = stlab::channel<int>(stlab::default_executor);
        auto hold = receive
            | sum()
            | [](int x){ std::cout << x << '\n'; };
        receive.set_ready();
        send(1);
        send(2);
        send(3);
        std::cout << "sleep\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        /*prints 1 3 6*/
    }
    {   // split
        stlab::sender<int> send1;
        stlab::receiver<int> receive1;
        std::tie(send1, receive1) = stlab::channel<int>(stlab::default_executor);
        auto hold1a = receive1
            | [](int x){ std::cout << "receive1a:" << x << '\n'; };
        auto hold1b = receive1
            | [](int x){ std::cout << "receive1b:" << x << '\n'; };
        receive1.set_ready();
        send1(1);
        send1(2);
        send1(3);
        std::cout << "sleep\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        /*prints 1 1 2 2 3 3*/
    }
    {   // split & join
        stlab::sender<int> send1;
        stlab::receiver<int> receive1;
        std::tie(send1, receive1) = stlab::channel<int>(stlab::default_executor);
        stlab::sender<int> send2;
        stlab::receiver<int> receive2;
        std::tie(send2, receive2) = stlab::channel<int>(stlab::default_executor);
        stlab::sender<int> send3;
        stlab::receiver<int> receive3;
        std::tie(send3, receive3) = stlab::channel<int>(stlab::default_executor);
        auto hold1a = receive1
            | [&send2](int x){ send2(x*10+2); };
        auto hold1b = receive1
            | [&send3](int x){ send3(x*10+3); };
        auto zipped = stlab::zip(stlab::default_executor,
                receive2,
                receive3)
            | [](std::tuple<int, int> v) {
                std::cout << "receive zip:" << std::get<0>(v) << "," << std::get<1>(v) << '\n';
            };

        receive1.set_ready();
        receive2.set_ready();
        receive3.set_ready();
        send1(1);
        send1(2);
        send1(3);
        std::cout << "sleep\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        /*prints 12,13 22,23 32,33*/
    }
    {   // three-way split & join
        stlab::sender<int> send1;
        stlab::receiver<int> receive1;
        std::tie(send1, receive1) = stlab::channel<int>(stlab::default_executor);
        stlab::sender<int> send2;
        stlab::receiver<int> receive2;
        std::tie(send2, receive2) = stlab::channel<int>(stlab::default_executor);
        stlab::sender<int> send3;
        stlab::receiver<int> receive3;
        std::tie(send3, receive3) = stlab::channel<int>(stlab::default_executor);
        stlab::sender<int> send4;
        stlab::receiver<int> receive4;
        std::tie(send4, receive4) = stlab::channel<int>(stlab::default_executor);
        auto hold1a = receive1
            | [&send2](int x){ send2(x*10+2); };
        auto hold1b = receive1
            | [&send3](int x){ send3(x*10+3); };
        auto hold1c = receive1
            | [&send4](int x){ send4(x*10+4); };
        auto zipped = stlab::zip(stlab::default_executor,
                receive2,
                receive3,
                receive4)
            | get_fun();

        receive1.set_ready();
        receive2.set_ready();
        receive3.set_ready();
        receive4.set_ready();
        send1(1);
        send1(2);
        send1(3);
        std::cout << "sleep\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        /*prints 12,13,14 22,23,24 32,33,34*/
    }
    {   // processors
        processor<std::tuple<>,
            std::tuple<std::string>>
            proc0;
        processor<std::tuple<std::string>,
            std::tuple<std::string, std::string, std::string>>
            proc1;
        processor<std::tuple<std::string, std::string, std::string>,
            std::tuple<std::string>>
            proc2;
        processor<std::tuple<std::string>>
            proc3;
        proc0.to<0, 0>(proc1);
        proc1.to<0, 0>(proc2);
        proc2.from<1, 1>(proc1);
        proc2.from<2, 2>(proc1);
        proc2.to<0, 0>(proc3);
        proc0.on_your_marks();
        proc1.on_your_marks();
        proc2.on_your_marks();
        proc3.on_your_marks();
        proc0.get_set();
        proc1.get_set();
        proc2.get_set();
        proc3.get_set();
        proc0.go(std::make_tuple());
        proc0.go(std::make_tuple());
        proc0.go(std::make_tuple());
        std::cout << "sleep\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    {   // signal processors
        signal_processor<std::string> proc0{0, 1};
        signal_processor<std::string> proc1{1, 3};
        signal_processor<std::string> proc2{3, 1};
        signal_processor<std::string> proc3{1, 0};
        proc0.to(proc1, 0, 0);
        proc1.to(proc2, 0, 0);
        proc2.from(proc1, 1, 1);
        proc2.from(proc1, 2, 2);
        proc2.to(proc3, 0, 0);
        proc0.on_your_marks();
        proc1.on_your_marks();
        proc2.on_your_marks();
        proc3.on_your_marks();
        proc0.get_set();
        proc1.get_set();
        proc2.get_set();
        proc3.get_set();
        proc0.go(std::vector<std::string>{});
        proc0.go(std::vector<std::string>{});
        proc0.go(std::vector<std::string>{});
        std::cout << "sleep\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "before pre_exit()\n";
    stlab::pre_exit();
    std::cout << "after pre_exit()\n";
    return 0;
}
