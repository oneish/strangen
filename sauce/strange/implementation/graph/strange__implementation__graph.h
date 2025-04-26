#pragma once

#include <stlab/concurrency/concurrency.hpp>
#include <stlab/pre_exit.hpp>

#include <functional>
#include <utility>
#include <tuple>
#include <thread>
#include <any>
#include <string>
#include <vector>
#include <set>
#include <future>

namespace strange
{
namespace implementation
{
template<typename Signal>
struct process
{
    inline process(
        uint64_t ins,
        uint64_t outs,
        std::function<auto (std::vector<Signal>) -> std::vector<Signal>> fun = nullptr)
        :_receivers(ins)
        ,_senders(outs)
        ,_function(fun)
        ,_inputs(ins)
    {
    }

    inline process(std::vector<process> && subprocs)
        :_subprocs(std::move(subprocs))
    {
        // output
        if (_subprocs.size() > 0 && !_subprocs[0]._function)
        {
            _subprocs[0]._function = [this](std::vector<Signal> inputs) {
                _outputs.set_value(inputs);
                return std::vector<Signal>{};
            };
        }
        // input
        if (_subprocs.size() > 1 && !_subprocs[1]._function)
        {
            _subprocs[1]._function = [this](std::vector<Signal> inputs) {
                return _inputs;
            };
        }
    }

    inline auto ins() const -> uint64_t
    {
        if (_subprocs.size() > 1)
        {
            return _subprocs[1].ins(); // TODO: check if this is correct
        }
        if (_subprocs.size() > 0)
        {
            return 0;
        }
        return _receivers.size();
    }

    inline auto outs() const -> uint64_t
    {
        if (_subprocs.size() > 0)
        {
            return _subprocs[0].outs(); // TODO: check if this is correct
        }
        return _senders.size();
    }

    inline auto from(process & other, uint64_t in, uint64_t out) -> void
    {
        if (_subprocs.size() > 1)
        {
            _subprocs[1].from(other, in, out);
            return;
        }
        if (other._subprocs.size() > 0)
        {
            from(other._subprocs[0], in, out);
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

    inline auto to(process & other, uint64_t out, uint64_t in) -> void
    {
        if (_subprocs.size() > 0)
        {
            _subprocs[0].to(other, out, in);
            return;
        }
        if (other._subprocs.size() > 1)
        {
            to(other._subprocs[1], out, in);
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
        for (auto & subproc : _subprocs)
        {
            subproc.on_your_marks();
        }
        std::vector<uint64_t> connected_ins{_set_receivers.cbegin(), _set_receivers.cend()};
        switch (connected_ins.size())
        {
            case 0:
                break;
            case 1:
                _zip = _receivers[connected_ins[0]] | [this](Signal connected_input) {
                        proc(std::tuple<Signal>{connected_input});
                    };
                break;
            case 2:
                _zip = stlab::zip(stlab::high_executor,
                    _receivers[connected_ins[0]],
                    _receivers[connected_ins[1]]) |
                    [this](std::tuple<Signal, Signal> connected_inputs) {
                        proc(connected_inputs);
                    };
                break;
            case 3:
                _zip = stlab::zip(stlab::high_executor,
                    _receivers[connected_ins[0]],
                    _receivers[connected_ins[1]],
                    _receivers[connected_ins[2]]) |
                    [this](std::tuple<Signal, Signal, Signal> connected_inputs) {
                        proc(connected_inputs);
                    };
                break;
            case 4:
                _zip = stlab::zip(stlab::high_executor,
                    _receivers[connected_ins[0]],
                    _receivers[connected_ins[1]],
                    _receivers[connected_ins[2]],
                    _receivers[connected_ins[3]]) |
                    [this](std::tuple<Signal, Signal, Signal, Signal> connected_inputs) {
                        proc(connected_inputs);
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
                        proc(connected_inputs);
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
                        proc(connected_inputs);
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
                        proc(connected_inputs);
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
                        proc(connected_inputs);
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
                        proc(connected_inputs);
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
                        proc(connected_inputs);
                    };
                break;
            default:
                throw std::runtime_error("too many connected ins");
        }
    }

    inline auto get_set() -> void
    {
        for (auto & subproc : _subprocs)
        {
            subproc.get_set();
        }
        for (auto in : _set_receivers)
        {
            _receivers[in].set_ready();
        }
    }

    inline auto go() const -> void
    {
        for (auto & subproc : _subprocs)
        {
            subproc.go();
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
    template<typename Tuple>
    inline auto proc(Tuple connected_inputs) -> void
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
    std::set<uint64_t> _set_receivers;
    std::set<uint64_t> _set_senders;
    std::vector<Signal> _inputs;
    std::any _zip;
    std::vector<process> _subprocs;
    std::promise<std::vector<Signal>> _outputs;
};

template<typename Signal>
struct processor
{
    inline processor(strange::implementation::process<Signal> && process)
    :_process(std::move(process))
    ,_ins(_process.ins())
    ,_outs(_process.outs())
    {
    }

    inline auto pack(strange::bag & dest) const -> void
    {}

    inline auto unpack(strange::bag const & src) -> void
    {}

    inline auto ins(std::unique_ptr<Signal> && overload) const -> uint64_t const &
    {
        return _ins;
    }

    inline auto ins(std::unique_ptr<Signal> && overload) -> uint64_t &
    {
        return _ins;
    }

    inline auto outs(std::unique_ptr<Signal> && overload) const -> uint64_t const &
    {
        return _outs;
    }

    inline auto outs(std::unique_ptr<Signal> && overload) -> uint64_t &
    {
        return _outs;
    }

    inline auto closure(std::unique_ptr<Signal> && overload) -> std::function<auto (std::vector<Signal>) -> std::vector<Signal>>
    {
        return [this](std::vector<Signal> inputs) {
            return _process(inputs);
        };
    }

private:
    strange::implementation::process<Signal> _process;
    uint64_t _ins;
    uint64_t _outs;
};

template<typename Signal>
struct example_processor
{
    inline example_processor()
    :_ins(0)
    ,_outs(0)
    {
    }

    inline auto pack(strange::bag & dest) const -> void
    {}

    inline auto unpack(strange::bag const & src) -> void
    {}

    inline auto ins(std::unique_ptr<Signal> && overload) const -> uint64_t const &
    {
        return _ins;
    }

    inline auto ins(std::unique_ptr<Signal> && overload) -> uint64_t &
    {
        return _ins;
    }

    inline auto outs(std::unique_ptr<Signal> && overload) const -> uint64_t const &
    {
        return _outs;
    }

    inline auto outs(std::unique_ptr<Signal> && overload) -> uint64_t &
    {
        return _outs;
    }

    inline auto closure(std::unique_ptr<Signal> && overload) -> std::function<auto (std::vector<Signal>) -> std::vector<Signal>>
    {
        return [this](std::vector<Signal> inputs) {
            return std::vector<Signal>(_outs);
        };
    }

private:
    uint64_t _ins;
    uint64_t _outs;
};

template<typename Signal>
struct graph
{
    inline graph()
    :_ins(0)
    ,_outs(0)
    {}

    inline auto pack(strange::bag & dest) const -> void
    {}

    inline auto unpack(strange::bag const & src) -> void
    {}

    inline auto ins(std::unique_ptr<Signal> && overload) const -> uint64_t const &
    {
        return _ins;
    }

    inline auto ins(std::unique_ptr<Signal> && overload) -> uint64_t &
    {
        return _ins;
    }

    inline auto outs(std::unique_ptr<Signal> && overload) const -> uint64_t const &
    {
        return _outs;
    }

    inline auto outs(std::unique_ptr<Signal> && overload) -> uint64_t &
    {
        return _outs;
    }

    inline auto add_processor(strange::processor<Signal> proc) -> uint64_t
    {
        auto id = _processors.size();
        _processors.push_back(proc);
        return id;
    }

    inline auto remove_processor(uint64_t id, std::unique_ptr<Signal> && overload) -> bool
    {
        if (id < _processors.size() && _processors[id]._something())
        {
            _processors[id] = strange::processor<Signal>{};
            return true;
        }
        return false;
    }

    inline auto add_connection(strange::connection conn, std::unique_ptr<Signal> && overload) -> uint64_t
    {
        auto id = _connections.size();
        _connections.push_back(conn);
        return id;
    }

    inline auto remove_connection(uint64_t id, std::unique_ptr<Signal> && overload) -> bool
    {
        if (id < _connections.size() && _connections[id]._something())
        {
            _connections[id] = strange::connection{};
            return true;
        }
        return false;
    }

    inline auto closure(std::unique_ptr<Signal> && overload) -> std::function<auto (std::vector<Signal>) -> std::vector<Signal>>
    {
        return [this](std::vector<Signal> inputs) {
            return std::vector<Signal>(_outs);
        };
    }

private:
    uint64_t _ins;
    uint64_t _outs;
    std::vector<strange::processor<Signal>> _processors;
    std::vector<strange::connection> _connections;
};
}
}
