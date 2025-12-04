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
                        _inputs[_connected_ins[0].first] = connected_input;
                        send();
                    };
                break;
            case 2:
                combine_receivers<2>();
                break;
            case 3:
                combine_receivers<3>();
                break;
            case 4:
                combine_receivers<4>();
                break;
            case 5:
                combine_receivers<5>();
                break;
            case 6:
                combine_receivers<6>();
                break;
            case 7:
                combine_receivers<7>();
                break;
            case 8:
                combine_receivers<8>();
                break;
            case 9:
                combine_receivers<9>();
                break;
            case 10:
                combine_receivers<10>();
                break;
            case 11:
                combine_receivers<11>();
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
    template<std::size_t>
    using SignalTypeFromSizeType = Signal;

    template<std::size_t Size>
    inline auto combine_receivers() -> void
    {
        combine_recs(std::make_index_sequence<Size>{});
    }

    template<std::size_t... Index>
    inline auto combine_recs(std::index_sequence<Index...>) -> void
    {
        _zip = stlab::zip(stlab::high_executor,
            _receivers[_connected_ins[Index].first][_connected_ins[Index].second]...) |
            [this](std::tuple<SignalTypeFromSizeType<Index>...> connected_inputs) {
                std::apply([this](auto && ...args) {
                    auto it = _connected_ins.cbegin();
                    ((assign_input(*it++, std::forward<decltype(args)>(args))), ...);
                }, connected_inputs);
                send();
            };
    }

    inline auto assign_input(std::pair<uint64_t, uint64_t> const & connected_in, Signal signal) -> void
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
    {
        dest.from_object();
        dest.insert_object("ins", dest.make_uint64(ins()));
        dest.insert_object("outs", dest.make_uint64(outs()));
    }

    inline auto unpack(strange::bag const & src) -> void
    {
        src.get_object("ins").as_uint64(ins());
        src.get_object("outs").as_uint64(outs());
    }

    inline auto ins() const -> uint64_t const &
    {
        return _ins;
    }

    inline auto ins() -> uint64_t &
    {
        return _ins;
    }

    inline auto outs() const -> uint64_t const &
    {
        return _outs;
    }

    inline auto outs() -> uint64_t &
    {
        return _outs;
    }

    inline auto closure() -> std::function<auto (std::vector<Signal>) -> std::vector<Signal>>
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
    {
        dest.from_object();
        dest.insert_object("ins", dest.make_uint64(ins()));
        dest.insert_object("outs", dest.make_uint64(outs()));
        {
            auto _array = dest.make_array();
            for (auto const & _item : processors())
            {
                _array.push_back_array(dest.make_any(_item));
            }
            dest.insert_object("processors", _array);
        }
        {
            auto _array = dest.make_array();
            for (auto const & _item : connections())
            {
                _array.push_back_array(dest.make_any(_item));
            }
            dest.insert_object("connections", _array);
        }
    }

    inline auto unpack(strange::bag const & src) -> void
    {
        src.get_object("ins").as_uint64(ins());
        src.get_object("outs").as_uint64(outs());
        {
            auto _array = src.get_object("processors").to_array();
            auto _size = _array.size();
            processors().clear();
            processors().resize(_size);
            for (std::size_t _index = 0; _index < _size; ++_index)
            {
                _array[_index].as_any(processors()[_index]);
            }
        }
        {
            auto _array = src.get_object("connections").to_array();
            auto _size = _array.size();
            connections().clear();
            connections().resize(_size);
            for (std::size_t _index = 0; _index < _size; ++_index)
            {
                _array[_index].as_any(connections()[_index]);
            }
        }
    }

    inline auto ins() const -> uint64_t const &
    {
        return _ins;
    }

    inline auto ins() -> uint64_t &
    {
        return _ins;
    }

    inline auto outs() const -> uint64_t const &
    {
        return _outs;
    }

    inline auto outs() -> uint64_t &
    {
        return _outs;
    }

    inline auto closure() -> std::function<auto (std::vector<Signal>) -> std::vector<Signal>>
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

    inline auto remove_processor(uint64_t id) -> bool
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

    inline auto add_connection(strange::connection conn) -> uint64_t
    {
        auto id = _connections.size();
        _connections.push_back(conn);
        return id;
    }

    inline auto remove_connection(uint64_t id) -> bool
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
