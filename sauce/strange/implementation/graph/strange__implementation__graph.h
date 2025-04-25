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
}
}
