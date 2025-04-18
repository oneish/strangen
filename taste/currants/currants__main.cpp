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
#include <set>
#include <future>

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

template <typename Signal>
struct processor
{
    inline processor(
        std::size_t ins,
        std::size_t outs,
        std::function<auto (std::vector<Signal>) -> std::vector<Signal>> fun)
        :_receivers(ins)
        ,_senders(outs)
        ,_function(fun)
        ,_inputs(ins)
    {
    }

    inline auto from(processor & other, std::size_t in, std::size_t out) -> void
    {
        if (_subprocessors.size() > 1)
        {
            _subprocessors[1].from(other, in, out);
            return;
        }
        if (other._subprocessors.size() > 0)
        {
            from(other._subprocessors[0], in, out);
            return;
        }
        std::tie(other._senders[out], _receivers[in]) = stlab::channel<Signal>(stlab::default_executor);
        if (!other._set_senders.insert(out).second)
        {
            throw std::runtime_error("other sender already connected");
        }
        if (!_set_receivers.insert(in).second)
        {
            throw std::runtime_error("receiver already connected");
        }
    }

    inline auto to(processor & other, std::size_t in, std::size_t out) -> void
    {
        if (_subprocessors.size() > 0)
        {
            _subprocessors[0].to(other, in, out);
            return;
        }
        if (other._subprocessors.size() > 1)
        {
            to(other._subprocessors[1], in, out);
            return;
        }
        std::tie(_senders[out], other._receivers[in]) = stlab::channel<Signal>(stlab::default_executor);
        if (!_set_senders.insert(out).second)
        {
            throw std::runtime_error("sender already connected");
        }
        if (!other._set_receivers.insert(in).second)
        {
            throw std::runtime_error("other receiver already connected");
        }
    }

    inline auto on_your_marks() -> void
    {
        for (auto & subprocessor : _subprocessors)
        {
            subprocessor.on_your_marks();
        }
        std::vector<stlab::receiver<Signal> *> connected_receivers;
        connected_receivers.reserve(_set_receivers.size());
        for (auto in : _set_receivers)
        {
            connected_receivers.push_back(&_receivers[in]);
        }
        switch (connected_receivers.size())
        {
            case 0:
                return;
            case 1:
                _zip = (*connected_receivers[0]) | [this](Signal connected_input) {
                        process(std::tuple<Signal>{connected_input});
                    };
                return;
            case 2:
                _zip = stlab::zip(stlab::default_executor,
                    *connected_receivers[0],
                    *connected_receivers[1]) |
                    [this](std::tuple<Signal, Signal> connected_inputs) {
                        process(connected_inputs);
                    };
                return;
            case 3:
                _zip = stlab::zip(stlab::default_executor,
                    *connected_receivers[0],
                    *connected_receivers[1],
                    *connected_receivers[2]) |
                    [this](std::tuple<Signal, Signal, Signal> connected_inputs) {
                        process(connected_inputs);
                    };
                return;
            case 4:
                _zip = stlab::zip(stlab::default_executor,
                    *connected_receivers[0],
                    *connected_receivers[1],
                    *connected_receivers[2],
                    *connected_receivers[3]) |
                    [this](std::tuple<Signal, Signal, Signal, Signal> connected_inputs) {
                        process(connected_inputs);
                    };
                return;
            case 5:
                _zip = stlab::zip(stlab::default_executor,
                    *connected_receivers[0],
                    *connected_receivers[1],
                    *connected_receivers[2],
                    *connected_receivers[3],
                    *connected_receivers[4]) |
                    [this](std::tuple<Signal, Signal, Signal, Signal, Signal> connected_inputs) {
                        process(connected_inputs);
                    };
                return;
            case 6:
                _zip = stlab::zip(stlab::default_executor,
                    *connected_receivers[0],
                    *connected_receivers[1],
                    *connected_receivers[2],
                    *connected_receivers[3],
                    *connected_receivers[4],
                    *connected_receivers[5]) |
                    [this](std::tuple<Signal, Signal, Signal, Signal, Signal, Signal> connected_inputs) {
                        process(connected_inputs);
                    };
                return;
            case 7:
                _zip = stlab::zip(stlab::default_executor,
                    *connected_receivers[0],
                    *connected_receivers[1],
                    *connected_receivers[2],
                    *connected_receivers[3],
                    *connected_receivers[4],
                    *connected_receivers[5],
                    *connected_receivers[6]) |
                    [this](std::tuple<Signal, Signal, Signal, Signal, Signal, Signal, Signal> connected_inputs) {
                        process(connected_inputs);
                    };
                return;
            case 8:
                _zip = stlab::zip(stlab::default_executor,
                    *connected_receivers[0],
                    *connected_receivers[1],
                    *connected_receivers[2],
                    *connected_receivers[3],
                    *connected_receivers[4],
                    *connected_receivers[5],
                    *connected_receivers[6],
                    *connected_receivers[7]) |
                    [this](std::tuple<Signal, Signal, Signal, Signal, Signal, Signal, Signal, Signal> connected_inputs) {
                        process(connected_inputs);
                    };
                return;
            case 9:
                _zip = stlab::zip(stlab::default_executor,
                    *connected_receivers[0],
                    *connected_receivers[1],
                    *connected_receivers[2],
                    *connected_receivers[3],
                    *connected_receivers[4],
                    *connected_receivers[5],
                    *connected_receivers[6],
                    *connected_receivers[7],
                    *connected_receivers[8]) |
                    [this](std::tuple<Signal, Signal, Signal, Signal, Signal, Signal, Signal, Signal, Signal> connected_inputs) {
                        process(connected_inputs);
                    };
                return;
            case 10:
                _zip = stlab::zip(stlab::default_executor,
                    *connected_receivers[0],
                    *connected_receivers[1],
                    *connected_receivers[2],
                    *connected_receivers[3],
                    *connected_receivers[4],
                    *connected_receivers[5],
                    *connected_receivers[6],
                    *connected_receivers[7],
                    *connected_receivers[8],
                    *connected_receivers[9]) |
                    [this](std::tuple<Signal, Signal, Signal, Signal, Signal, Signal, Signal, Signal, Signal, Signal> connected_inputs) {
                        process(connected_inputs);
                    };
                return;
            default:
                throw std::runtime_error("too many connected receivers");
        }
    }

    inline auto get_set() -> void
    {
        for (auto & subprocessor : _subprocessors)
        {
            subprocessor.get_set();
        }
        for (auto in : _set_receivers)
        {
            _receivers[in].set_ready();
        }
    }

    inline auto go() const -> void
    {
        switch (_subprocessors.size())
        {
            case 0:
                send(_function(_inputs));
                break;
            case 1:
                _subprocessors[0].go();
                break;
            default:
                _subprocessors[1].go();
        }
    }

private:
    template <typename Tuple>
    inline auto process(Tuple connected_inputs) -> void
    {
        std::apply([this](auto && ... args) {
                auto it = _set_receivers.cbegin();
                ((_inputs[*it++] = std::forward<decltype(args)>(args)), ...);
            }, connected_inputs);
        go();
    }

    inline auto send(std::vector<Signal> outputs) const -> void
    {
        for (auto out : _set_senders)
        {
            _senders[out](outputs[out]);
            std::cout << "sent\n";
        }
    }

    std::vector<stlab::receiver<Signal>> _receivers;
    std::vector<stlab::sender<Signal>> _senders;
    std::function<auto (std::vector<Signal>) -> std::vector<Signal>> _function;
    std::set<std::size_t> _set_receivers;
    std::set<std::size_t> _set_senders;
    std::vector<Signal> _inputs;
    std::any _zip;
    std::vector<processor> _subprocessors;
};

template <typename Signal>
struct graph
{
    inline graph(
        std::size_t ins,
        std::size_t outs)
        :_inputs(ins)
    {
        // output processor [0]:
        _processors.emplace_back(outs, 0, [this](std::vector<Signal> inputs) {
            _promise.set_value(inputs);
            return std::vector<Signal>{};
        });
        // input processor [1]:
        _processors.emplace_back(0, ins, [this](std::vector<Signal> inputs) {
            return _inputs;
        });
    }

    inline auto interconnect() -> void
    {
        for (std::size_t in = 0; in < _inputs.size(); ++in)
        {
            _processors[1].to(_processors[0], in, in);
        }
    }

    inline auto on_your_marks() -> void
    {
        for (auto & proc : _processors)
        {
            proc.on_your_marks();
        }
    }

    inline auto get_set() -> void
    {
        for (auto & proc : _processors)
        {
            proc.get_set();
        }
    }

    inline auto operator()(std::vector<Signal> inputs) -> std::vector<Signal>
    {
        std::cout << "graph operator()\n";
        _inputs = inputs;
        _promise = std::promise<std::vector<Signal>>{};
        auto future = _promise.get_future();
        _processors[1].go();
        return future.get();
    }

private:
    std::vector<processor<Signal>> _processors;
    std::vector<Signal> _inputs;
    std::promise<std::vector<Signal>> _promise;
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
        std::function<auto (std::vector<std::string>) -> std::vector<std::string>> fun = [](std::vector<std::string> inputs) {
            std::string concat = ":";
            for (auto input : inputs)
            {
                concat += input;
            }
            concat += ".";
            std::cout << "process " << concat << "\n";
            return std::vector<std::string>(3, concat);
        };
        processor<std::string> proc0{0, 1, fun};
        processor<std::string> proc1{1, 3, fun};
        processor<std::string> proc2{3, 1, fun};
        processor<std::string> proc3{1, 0, fun};
        proc0.to(proc1, 0, 0);
        //proc1.to(proc2, 0, 0);
        proc2.from(proc1, 1, 1);
        //proc2.from(proc1, 2, 2);
        proc2.to(proc3, 0, 0);
        proc0.on_your_marks();
        proc1.on_your_marks();
        proc2.on_your_marks();
        proc3.on_your_marks();
        proc0.get_set();
        proc1.get_set();
        proc2.get_set();
        proc3.get_set();
        proc0.go();
        proc0.go();
        proc0.go();
        std::cout << "sleep\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    {   // graph
        graph<std::string> g(3, 3);
        g.interconnect();
        g.on_your_marks();
        g.get_set();
        std::vector<std::string> inputs {"hello", "world", "!"};
        for (auto input : inputs)
        {
            auto outputs = g(inputs);
            std::cout << "graph outputs: ";
            for (auto output : outputs)
            {
                std::cout << output << " ";
            }
            std::cout << "\n";
            std::swap(inputs[0], inputs[1]);
            std::swap(inputs[1], inputs[2]);
        }
    }
    std::cout << "before pre_exit()\n";
    stlab::pre_exit();
    std::cout << "after pre_exit()\n";
    return 0;
}
