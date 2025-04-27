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
struct processor
{
    processor() = delete;
    processor(processor const &) = delete;
    processor(processor &&) = delete;
    processor & operator=(processor const &) = delete;
    processor & operator=(processor &&) = delete;
    ~processor() = default;

    inline processor(
        uint64_t ins,
        uint64_t outs,
        std::function<auto (std::vector<Signal>) -> std::vector<Signal>> fun = nullptr)
        :_receivers(ins)
        ,_senders(outs)
        ,_function(fun)
        ,_inputs(ins)
    {
    }

    inline processor(std::vector<std::unique_ptr<processor>> && subprocs)
        :_subprocs(std::move(subprocs))
    {
        // output
        if (_subprocs.size() > 0 && !_subprocs[0]->_function)
        {
            _subprocs[0]->_function = [this](std::vector<Signal> inputs) {
                _outputs.set_value(inputs);
                return std::vector<Signal>{};
            };
        }
        // input
        if (_subprocs.size() > 1 && !_subprocs[1]->_function)
        {
            _subprocs[1]->_function = [this](std::vector<Signal> inputs) {
                return _inputs;
            };
        }
    }

    inline auto from(processor & other, uint64_t in, uint64_t out) -> void
    {
        if (_subprocs.size() > 1)
        {
            _subprocs[1]->from(other, in, out);
            return;
        }
        if (other._subprocs.size() > 0)
        {
            from(*other._subprocs[0], in, out);
            return;
        }
        other._senders[out].push_back(stlab::sender<Signal>{});
        _receivers[in].push_back(stlab::receiver<Signal>{});
        std::tie(other._senders[out].back(), _receivers[in].back()) = stlab::channel<Signal>(stlab::high_executor);
    }

    inline auto to(processor & other, uint64_t out, uint64_t in) -> void
    {
        if (_subprocs.size() > 0)
        {
            _subprocs[0]->to(other, out, in);
            return;
        }
        if (other._subprocs.size() > 1)
        {
            to(*other._subprocs[1], out, in);
            return;
        }
        _senders[out].push_back(stlab::sender<Signal>{});
        other._receivers[in].push_back(stlab::receiver<Signal>{});
        std::tie(_senders[out].back(), other._receivers[in].back()) = stlab::channel<Signal>(stlab::high_executor);
    }

    inline auto on_your_marks() -> void
    {
        for (auto & subproc : _subprocs)
        {
            if (subproc)
            {
                subproc->on_your_marks();
            }
        }
        for (uint64_t i = 0; i < _receivers.size(); ++i)
        {
            for (uint64_t j = 0; j < _receivers[i].size(); ++j)
            {
                _connected_ins.emplace_back(i, j);
            }
        }
        for (uint64_t i = 0; i < _senders.size(); ++i)
        {
            for (uint64_t j = 0; j < _senders[i].size(); ++j)
            {
                _connected_outs.emplace_back(i, j);
            }
        }
        switch (_connected_ins.size())
        {
            case 0:
                break;
            case 1:
                _zip = _receivers[_connected_ins[0].first][_connected_ins[0].second] | [this](Signal connected_input) {
                        proc(std::tuple<Signal>{connected_input});
                    };
                break;
            case 2:
                _zip = stlab::zip(stlab::high_executor,
                    _receivers[_connected_ins[0].first][_connected_ins[0].second],
                    _receivers[_connected_ins[0].first][_connected_ins[0].second]) |
                    [this](std::tuple<Signal, Signal> connected_inputs) {
                        proc(connected_inputs);
                    };
                break;
            case 3:
                _zip = stlab::zip(stlab::high_executor,
                    _receivers[_connected_ins[0].first][_connected_ins[0].second],
                    _receivers[_connected_ins[1].first][_connected_ins[1].second],
                    _receivers[_connected_ins[2].first][_connected_ins[2].second]) |
                    [this](std::tuple<Signal, Signal, Signal> connected_inputs) {
                        proc(connected_inputs);
                    };
                break;
            case 4:
                _zip = stlab::zip(stlab::high_executor,
                    _receivers[_connected_ins[0].first][_connected_ins[0].second],
                    _receivers[_connected_ins[1].first][_connected_ins[1].second],
                    _receivers[_connected_ins[2].first][_connected_ins[2].second],
                    _receivers[_connected_ins[3].first][_connected_ins[3].second]) |
                    [this](std::tuple<Signal, Signal, Signal, Signal> connected_inputs) {
                        proc(connected_inputs);
                    };
                break;
            case 5:
                _zip = stlab::zip(stlab::high_executor,
                    _receivers[_connected_ins[0].first][_connected_ins[0].second],
                    _receivers[_connected_ins[1].first][_connected_ins[1].second],
                    _receivers[_connected_ins[2].first][_connected_ins[2].second],
                    _receivers[_connected_ins[3].first][_connected_ins[3].second],
                    _receivers[_connected_ins[4].first][_connected_ins[4].second]) |
                    [this](std::tuple<Signal, Signal, Signal, Signal, Signal> connected_inputs) {
                        proc(connected_inputs);
                    };
                break;
            case 6:
                _zip = stlab::zip(stlab::high_executor,
                    _receivers[_connected_ins[0].first][_connected_ins[0].second],
                    _receivers[_connected_ins[1].first][_connected_ins[1].second],
                    _receivers[_connected_ins[2].first][_connected_ins[2].second],
                    _receivers[_connected_ins[3].first][_connected_ins[3].second],
                    _receivers[_connected_ins[4].first][_connected_ins[4].second],
                    _receivers[_connected_ins[5].first][_connected_ins[5].second]) |
                    [this](std::tuple<Signal, Signal, Signal, Signal, Signal, Signal> connected_inputs) {
                        proc(connected_inputs);
                    };
                break;
            case 7:
                _zip = stlab::zip(stlab::high_executor,
                    _receivers[_connected_ins[0].first][_connected_ins[0].second],
                    _receivers[_connected_ins[1].first][_connected_ins[1].second],
                    _receivers[_connected_ins[2].first][_connected_ins[2].second],
                    _receivers[_connected_ins[3].first][_connected_ins[3].second],
                    _receivers[_connected_ins[4].first][_connected_ins[4].second],
                    _receivers[_connected_ins[5].first][_connected_ins[5].second],
                    _receivers[_connected_ins[6].first][_connected_ins[6].second]) |
                    [this](std::tuple<Signal, Signal, Signal, Signal, Signal, Signal, Signal> connected_inputs) {
                        proc(connected_inputs);
                    };
                break;
            case 8:
                _zip = stlab::zip(stlab::high_executor,
                    _receivers[_connected_ins[0].first][_connected_ins[0].second],
                    _receivers[_connected_ins[1].first][_connected_ins[1].second],
                    _receivers[_connected_ins[2].first][_connected_ins[2].second],
                    _receivers[_connected_ins[3].first][_connected_ins[3].second],
                    _receivers[_connected_ins[4].first][_connected_ins[4].second],
                    _receivers[_connected_ins[5].first][_connected_ins[5].second],
                    _receivers[_connected_ins[6].first][_connected_ins[6].second],
                    _receivers[_connected_ins[7].first][_connected_ins[7].second]) |
                    [this](std::tuple<Signal, Signal, Signal, Signal, Signal, Signal, Signal, Signal> connected_inputs) {
                        proc(connected_inputs);
                    };
                break;
            case 9:
                _zip = stlab::zip(stlab::high_executor,
                    _receivers[_connected_ins[0].first][_connected_ins[0].second],
                    _receivers[_connected_ins[1].first][_connected_ins[1].second],
                    _receivers[_connected_ins[2].first][_connected_ins[2].second],
                    _receivers[_connected_ins[3].first][_connected_ins[3].second],
                    _receivers[_connected_ins[4].first][_connected_ins[4].second],
                    _receivers[_connected_ins[5].first][_connected_ins[5].second],
                    _receivers[_connected_ins[6].first][_connected_ins[6].second],
                    _receivers[_connected_ins[7].first][_connected_ins[7].second],
                    _receivers[_connected_ins[8].first][_connected_ins[8].second]) |
                    [this](std::tuple<Signal, Signal, Signal, Signal, Signal, Signal, Signal, Signal, Signal> connected_inputs) {
                        proc(connected_inputs);
                    };
                break;
            case 10:
                _zip = stlab::zip(stlab::high_executor,
                    _receivers[_connected_ins[0].first][_connected_ins[0].second],
                    _receivers[_connected_ins[1].first][_connected_ins[1].second],
                    _receivers[_connected_ins[2].first][_connected_ins[2].second],
                    _receivers[_connected_ins[3].first][_connected_ins[3].second],
                    _receivers[_connected_ins[4].first][_connected_ins[4].second],
                    _receivers[_connected_ins[5].first][_connected_ins[5].second],
                    _receivers[_connected_ins[6].first][_connected_ins[6].second],
                    _receivers[_connected_ins[7].first][_connected_ins[7].second],
                    _receivers[_connected_ins[8].first][_connected_ins[8].second],
                    _receivers[_connected_ins[9].first][_connected_ins[9].second]) |
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
            if (subproc)
            {
                subproc->get_set();
            }
        }
        for (auto const & connected_in : _connected_ins)
        {
            _receivers[connected_in.first][connected_in.second].set_ready();
        }
    }

    inline auto go() const -> void
    {
        for (auto & subproc : _subprocs)
        {
            if (subproc)
            {
                subproc->go();
            }
        }
        if (_function && _connected_ins.empty())
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
                auto it = _connected_ins.cbegin();
                ((helper(*it++, std::forward<decltype(args)>(args))), ...);
            }, connected_inputs);
        send();
    }

    inline auto helper(std::pair<uint64_t, uint64_t> const & connected_in, Signal signal) -> void
    {
        if (!connected_in.second)
        {
            _inputs[connected_in.first] = signal;
        }
        else
        {
            _inputs[connected_in.first] += signal;
        }
    }

    inline auto send() const -> void
    {
        auto outputs = _function(_inputs);
        for (auto const & connected_out : _connected_outs)
        {
            _senders[connected_out.first][connected_out.second](outputs[connected_out.first]);
        }
    }

    std::vector<std::vector<stlab::receiver<Signal>>> _receivers;
    std::vector<std::vector<stlab::sender<Signal>>> _senders;
    std::function<auto (std::vector<Signal>) -> std::vector<Signal>> _function;
    std::vector<std::pair<uint64_t, uint64_t>> _connected_ins;
    std::vector<std::pair<uint64_t, uint64_t>> _connected_outs;
    std::any _zip;
    std::vector<Signal> _inputs;
    std::promise<std::vector<Signal>> _outputs;
    std::vector<std::unique_ptr<processor>> _subprocs;
};

template<typename Signal>
struct thru_processor
{
    inline thru_processor()
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
        return [*this](std::vector<Signal> inputs) {
            inputs.resize(_outs);
            return inputs;
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
    ,_processors(2)
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
        std::vector<std::unique_ptr<strange::implementation::processor<Signal>>> subprocs;
        subprocs.push_back(std::make_unique<strange::implementation::processor<Signal>>(_outs, 0)); // [0] output
        subprocs.push_back(std::make_unique<strange::implementation::processor<Signal>>(0, _ins)); // [1] input
        iterate(_processors, _connections, subprocs);
        auto proc = std::make_shared<strange::implementation::processor<Signal>>(std::move(subprocs));
        proc->on_your_marks();
        proc->get_set();
        return [proc](std::vector<Signal> inputs) {
            return (*proc)(inputs);
        };
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

    inline auto processors() const -> std::vector<strange::processor<Signal>> const &
    {
        return _processors;
    }

    inline auto processors() -> std::vector<strange::processor<Signal>> &
    {
        return _processors;
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

    inline auto connections() const -> std::vector<strange::connection> const &
    {
        return _connections;
    }

    inline auto connections() -> std::vector<strange::connection> &
    {
        return _connections;
    }

private:
    static inline auto iterate(std::vector<strange::processor<Signal>> & processors,
        std::vector<strange::connection> const & connections,
        std::vector<std::unique_ptr<strange::implementation::processor<Signal>>> & subprocs) -> void
    {
        uint64_t skip = 2;
        for (auto & proc : processors)
        {
            if (skip)
            {
                --skip;
                continue;
            }
            if (proc._something())
            {
                auto subgraph = proc.template _dynamic<strange::graph<Signal>>();
                if (subgraph._something())
                {
                    subprocs.push_back(recurse(subgraph));
                }
                else
                {
                    subprocs.push_back(std::make_unique<strange::implementation::processor<Signal>>(proc.ins(), proc.outs(), proc.closure()));
                }
            }
            else
            {
                subprocs.emplace_back();
            }
        }
        for (auto & conn : connections)
        {
            if (conn._something())
            {
                subprocs[conn.from_id()]->to(*subprocs[conn.to_id()], conn.from_out(), conn.to_in());
            }
        }
    }

    static inline auto recurse(strange::graph<Signal> & subgraph) -> std::unique_ptr<strange::implementation::processor<Signal>>
    {
        std::vector<std::unique_ptr<strange::implementation::processor<Signal>>> subprocs;
        subprocs.push_back(std::make_unique<strange::implementation::processor<Signal>>(subgraph.outs(), subgraph.outs(), [](std::vector<std::string> outputs){ return outputs; })); // [0] output
        subprocs.push_back(std::make_unique<strange::implementation::processor<Signal>>(subgraph.ins(), subgraph.ins(), [](std::vector<std::string> inputs){ return inputs; })); // [1] input
        iterate(subgraph.processors(), subgraph.connections(), subprocs);
        return std::make_unique<strange::implementation::processor<Signal>>(std::move(subprocs));
    }

    uint64_t _ins;
    uint64_t _outs;
    std::vector<strange::processor<Signal>> _processors;
    std::vector<strange::connection> _connections;
};
}
}
