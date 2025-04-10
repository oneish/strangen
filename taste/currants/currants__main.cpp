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
            std::apply([this](auto && ... recv) {
                _zip = stlab::zip(stlab::default_executor,
                    recv ...) | [this](Inputs const & inputs) {
                        go(inputs);
                    };
            }, _receivers);
        }
    }

    inline auto get_set() -> void
    {
        if constexpr (std::tuple_size_v<Inputs> != 0)
        {
            std::apply([](auto && ... recv) {
                ((recv.set_ready()), ...);
            }, _receivers);
        }
    }

    inline auto go(Inputs const & inputs) const -> void
    {
        send(process(inputs));
    }

    inline auto send(Outputs const & outputs) const -> void
    {
        send_rest(outputs);
    }

    static inline auto process(Inputs const & inputs) -> Outputs
    {
        std::string concat = ":";
        if (std::tuple_size_v<Inputs> != 0)
        {
            std::apply([&concat](auto && ... inpt) {
                ((concat += inpt), ...);
            }, inputs);
        }
        concat += ".";
        Outputs outputs;
        if (std::tuple_size_v<Outputs> != 0)
        {
            std::apply([&concat](auto && ... outp) {
                ((outp = concat), ...);
            }, outputs);
        }
        std::cout << "operator() " << concat << "\n";
        return outputs;
    }

private:
    template <std::size_t Index>
    inline auto send_one(Outputs const & outputs) const -> void
    {
        std::get<Index>(_senders)(std::get<Index>(outputs));
    }

    template <std::size_t Index = 0>
    inline auto send_rest(Outputs const & outputs) const -> void
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
    std::cout << "before pre_exit()\n";
    stlab::pre_exit();
    std::cout << "after pre_exit()\n";
    return 0;
}
