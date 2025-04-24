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

namespace abstract
{

template <typename Signal>
struct processor // : strange::any
{
    auto ins(std::unique_ptr<Signal> type) const -> std::size_t const &;
    auto ins(std::unique_ptr<Signal> type) -> std::size_t &;
    auto outs(std::unique_ptr<Signal> type) const -> std::size_t const &;
    auto outs(std::unique_ptr<Signal> type) -> std::size_t &;
    auto closure(std::unique_ptr<Signal> type) -> std::function<auto (std::vector<Signal>) -> std::vector<Signal>>;
};

template <typename Signal>
struct graph // : strange::any
{
    auto ins(std::unique_ptr<Signal> type) const -> std::size_t const &;
    auto ins(std::unique_ptr<Signal> type) -> std::size_t &;
    auto outs(std::unique_ptr<Signal> type) const -> std::size_t const &;
    auto outs(std::unique_ptr<Signal> type) -> std::size_t &;
    auto add_processor(processor<Signal> proc) -> std::size_t;
    auto remove_processor(std::size_t id) -> bool;
    auto add_connection(std::size_t from_id, std::size_t from_out,
        std::size_t to_id, std::size_t to_in) -> std::size_t;
    auto remove_connection(std::size_t id) -> bool;
    auto add_subgraph(graph<Signal> subgraph) -> std::size_t;
    auto remove_subgraph(std::size_t id) -> bool;
    auto convert_to_processor(std::unique_ptr<Signal> type) const -> processor<Signal>;
};

} // namespace abstract

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

namespace imp
{

template <typename Signal>
struct processor
{
    inline processor(
        std::size_t ins,
        std::size_t outs,
        std::function<auto (std::vector<Signal>) -> std::vector<Signal>> fun = nullptr)
        :_receivers(ins)
        ,_senders(outs)
        ,_function(fun)
        ,_inputs(ins)
    {
    }

    inline processor(std::vector<processor> && subprocs)
        :_subprocessors(std::move(subprocs))
    {
        // output
        if (_subprocessors.size() > 0 && !_subprocessors[0]._function)
        {
            _subprocessors[0]._function = [this](std::vector<Signal> inputs) {
                _outputs.set_value(inputs);
                return std::vector<Signal>{};
            };
        }
        // input
        if (_subprocessors.size() > 1 && !_subprocessors[1]._function)
        {
            _subprocessors[1]._function = [this](std::vector<Signal> inputs) {
                return _inputs;
            };
        }
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
        std::tie(other._senders[out], _receivers[in]) = stlab::channel<Signal>(stlab::high_executor);
        if (!other._set_senders.insert(out).second)
        {
            throw std::runtime_error("other sender already connected");
        }
        if (!_set_receivers.insert(in).second)
        {
            throw std::runtime_error("receiver already connected");
        }
    }

    inline auto to(processor & other, std::size_t out, std::size_t in) -> void
    {
        if (_subprocessors.size() > 0)
        {
            _subprocessors[0].to(other, out, in);
            return;
        }
        if (other._subprocessors.size() > 1)
        {
            to(other._subprocessors[1], out, in);
            return;
        }
        std::tie(_senders[out], other._receivers[in]) = stlab::channel<Signal>(stlab::high_executor);
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
        std::vector<std::size_t> connected_ins{_set_receivers.cbegin(), _set_receivers.cend()};
        switch (connected_ins.size())
        {
            case 0:
                break;
            case 1:
                _zip = _receivers[connected_ins[0]] | [this](Signal connected_input) {
                        process(std::tuple<Signal>{connected_input});
                    };
                break;
            case 2:
                _zip = stlab::zip(stlab::high_executor,
                    _receivers[connected_ins[0]],
                    _receivers[connected_ins[1]]) |
                    [this](std::tuple<Signal, Signal> connected_inputs) {
                        process(connected_inputs);
                    };
                break;
            case 3:
                _zip = stlab::zip(stlab::high_executor,
                    _receivers[connected_ins[0]],
                    _receivers[connected_ins[1]],
                    _receivers[connected_ins[2]]) |
                    [this](std::tuple<Signal, Signal, Signal> connected_inputs) {
                        process(connected_inputs);
                    };
                break;
            case 4:
                _zip = stlab::zip(stlab::high_executor,
                    _receivers[connected_ins[0]],
                    _receivers[connected_ins[1]],
                    _receivers[connected_ins[2]],
                    _receivers[connected_ins[3]]) |
                    [this](std::tuple<Signal, Signal, Signal, Signal> connected_inputs) {
                        process(connected_inputs);
                    };
                break;
            case 5:
                _zip = stlab::zip(stlab::high_executor,
                    _receivers[connected_ins[0]],
                    _receivers[connected_ins[1]],
                    _receivers[connected_ins[2]],
                    _receivers[connected_ins[3]],
                    _receivers[connected_ins[4]]) |
                    [this](std::tuple<Signal, Signal, Signal, Signal, Signal> connected_inputs) {
                        process(connected_inputs);
                    };
                break;
            case 6:
                _zip = stlab::zip(stlab::high_executor,
                    _receivers[connected_ins[0]],
                    _receivers[connected_ins[1]],
                    _receivers[connected_ins[2]],
                    _receivers[connected_ins[3]],
                    _receivers[connected_ins[4]],
                    _receivers[connected_ins[5]]) |
                    [this](std::tuple<Signal, Signal, Signal, Signal, Signal, Signal> connected_inputs) {
                        process(connected_inputs);
                    };
                break;
            case 7:
                _zip = stlab::zip(stlab::high_executor,
                    _receivers[connected_ins[0]],
                    _receivers[connected_ins[1]],
                    _receivers[connected_ins[2]],
                    _receivers[connected_ins[3]],
                    _receivers[connected_ins[4]],
                    _receivers[connected_ins[5]],
                    _receivers[connected_ins[6]]) |
                    [this](std::tuple<Signal, Signal, Signal, Signal, Signal, Signal, Signal> connected_inputs) {
                        process(connected_inputs);
                    };
                break;
            case 8:
                _zip = stlab::zip(stlab::high_executor,
                    _receivers[connected_ins[0]],
                    _receivers[connected_ins[1]],
                    _receivers[connected_ins[2]],
                    _receivers[connected_ins[3]],
                    _receivers[connected_ins[4]],
                    _receivers[connected_ins[5]],
                    _receivers[connected_ins[6]],
                    _receivers[connected_ins[7]]) |
                    [this](std::tuple<Signal, Signal, Signal, Signal, Signal, Signal, Signal, Signal> connected_inputs) {
                        process(connected_inputs);
                    };
                break;
            case 9:
                _zip = stlab::zip(stlab::high_executor,
                    _receivers[connected_ins[0]],
                    _receivers[connected_ins[1]],
                    _receivers[connected_ins[2]],
                    _receivers[connected_ins[3]],
                    _receivers[connected_ins[4]],
                    _receivers[connected_ins[5]],
                    _receivers[connected_ins[6]],
                    _receivers[connected_ins[7]],
                    _receivers[connected_ins[8]]) |
                    [this](std::tuple<Signal, Signal, Signal, Signal, Signal, Signal, Signal, Signal, Signal> connected_inputs) {
                        process(connected_inputs);
                    };
                break;
            case 10:
                _zip = stlab::zip(stlab::high_executor,
                    _receivers[connected_ins[0]],
                    _receivers[connected_ins[1]],
                    _receivers[connected_ins[2]],
                    _receivers[connected_ins[3]],
                    _receivers[connected_ins[4]],
                    _receivers[connected_ins[5]],
                    _receivers[connected_ins[6]],
                    _receivers[connected_ins[7]],
                    _receivers[connected_ins[8]],
                    _receivers[connected_ins[9]]) |
                    [this](std::tuple<Signal, Signal, Signal, Signal, Signal, Signal, Signal, Signal, Signal, Signal> connected_inputs) {
                        process(connected_inputs);
                    };
                break;
            default:
                throw std::runtime_error("too many connected ins");
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
        for (auto & subprocessor : _subprocessors)
        {
            subprocessor.go();
        }
        if (_function && _set_receivers.empty())
        {
            send();
        }
    }

    inline auto operator()(std::vector<Signal> inputs) -> std::vector<Signal>
    {
        _inputs = inputs;
        _outputs = std::promise<std::vector<Signal>>{};
        auto future = _outputs.get_future();
        go();
        return future.get();
    }

private:
    template <typename Tuple>
    inline auto process(Tuple connected_inputs) -> void
    {
        std::apply([this](auto && ... args) {
                auto it = _set_receivers.cbegin();
                ((_inputs[*it++] = std::forward<decltype(args)>(args)), ...);
            }, connected_inputs);
        send();
    }

    inline auto send() const -> void
    {
        auto outputs = _function(_inputs);
        for (auto out : _set_senders)
        {
            _senders[out](outputs[out]);
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
    std::promise<std::vector<Signal>> _outputs;
};

} // namespace imp

int main()
{
    std::cout << "currants\n";
    {   // single channel
        stlab::sender<int> send;
        stlab::receiver<int> receive;
        std::tie(send, receive) = stlab::channel<int>(stlab::high_executor);
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
        std::tie(send, receive) = stlab::channel<int>(stlab::high_executor);
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
        std::tie(send1, receive1) = stlab::channel<int>(stlab::high_executor);
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
        std::tie(send1, receive1) = stlab::channel<int>(stlab::high_executor);
        stlab::sender<int> send2;
        stlab::receiver<int> receive2;
        std::tie(send2, receive2) = stlab::channel<int>(stlab::high_executor);
        stlab::sender<int> send3;
        stlab::receiver<int> receive3;
        std::tie(send3, receive3) = stlab::channel<int>(stlab::high_executor);
        auto hold1a = receive1
            | [&send2](int x){ send2(x*10+2); };
        auto hold1b = receive1
            | [&send3](int x){ send3(x*10+3); };
        auto zipped = stlab::zip(stlab::high_executor,
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
        std::tie(send1, receive1) = stlab::channel<int>(stlab::high_executor);
        stlab::sender<int> send2;
        stlab::receiver<int> receive2;
        std::tie(send2, receive2) = stlab::channel<int>(stlab::high_executor);
        stlab::sender<int> send3;
        stlab::receiver<int> receive3;
        std::tie(send3, receive3) = stlab::channel<int>(stlab::high_executor);
        stlab::sender<int> send4;
        stlab::receiver<int> receive4;
        std::tie(send4, receive4) = stlab::channel<int>(stlab::high_executor);
        auto hold1a = receive1
            | [&send2](int x){ send2(x*10+2); };
        auto hold1b = receive1
            | [&send3](int x){ send3(x*10+3); };
        auto hold1c = receive1
            | [&send4](int x){ send4(x*10+4); };
        auto zipped = stlab::zip(stlab::high_executor,
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
        imp::processor<std::string> proc0{0, 1, fun};
        imp::processor<std::string> proc1{1, 3, fun};
        imp::processor<std::string> proc2{3, 1, fun};
        imp::processor<std::string> proc3{1, 0, fun};
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
        std::vector<imp::processor<std::string>> subsubprocs;
        subsubprocs.emplace_back(1, 1, [](std::vector<std::string> inputs){ return inputs; }); // output [0] "A"
        subsubprocs.emplace_back(1, 1, [](std::vector<std::string> inputs){ return inputs; }); // input [1] "B"
        subsubprocs[1].to(subsubprocs[0], 0, 0); // B0 -> A0
        std::vector<imp::processor<std::string>> subprocs;
        subprocs.emplace_back(3, 0); // output [0] "C"
        subprocs.emplace_back(0, 3); // input [1] "D"
        subprocs.emplace_back(std::move(subsubprocs)); // [2] "E"
        subprocs.emplace_back(1, 1, [](std::vector<std::string> inputs){ return inputs; }); // [3] "F"
        subprocs[1].to(subprocs[2], 0, 0); // D0 -> E0
        subprocs[0].from(subprocs[2], 0, 0); // C0 <- E0
        subprocs[1].to(subprocs[3], 1, 0); // D1 -> F0
        subprocs[0].from(subprocs[3], 1, 0); // C1 <- F0
        subprocs[1].to(subprocs[0], 2, 2); // D2 -> C2
        imp::processor<std::string> proc{std::move(subprocs)};
        proc.on_your_marks();
        proc.get_set();
        std::vector<std::string> inputs {"hello", "world", "!"};
        for (auto input : inputs)
        {
            auto outputs = proc(inputs);
            std::cout << "graph outputs: ";
            for (auto output : outputs)
            {
                std::cout << output << " ";
            }
            std::cout << "\n";
            std::swap(inputs[0], inputs[1]);
            std::swap(inputs[1], inputs[2]);
        }
        // no sleep
    }
    std::cout << "before pre_exit()\n";
    stlab::pre_exit();
    std::cout << "after pre_exit()\n";
    return 0;
}
