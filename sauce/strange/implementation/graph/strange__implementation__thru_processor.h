#pragma once

#include <functional>
#include <vector>

namespace strange
{
namespace implementation
{
template<typename Config, typename Signal>
struct thru_processor
{
    inline thru_processor(std::vector<uint64_t> types)
    :_ins(types.size())
    ,_outs(types.size())
    ,_types(std::move(types))
    ,_own_id(0)
    {
    }

    inline auto pack(strange::bag & dest) const -> void
    {
        dest.from_object();
        dest.insert_object("types", dest.make_array_uint64(_types));
        dest.insert_object("owner", dest.make_any(_owner));
        dest.insert_object("own_id", dest.make_uint64(_own_id));
    }

    inline auto unpack(strange::bag const & src) -> void
    {
        src.get_object("types").as_array_uint64(_types);
        _ins = _types.size();
        _outs = _types.size();
        src.get_object("owner").as_any(_owner);
        src.get_object("own_id").as_uint64(_own_id);
    }

    inline auto ins() const -> uint64_t const &
    {
        return _ins;
    }

    inline auto input_types() const -> std::vector<uint64_t> const &
    {
        return _types;
    }

    inline auto outs() const -> uint64_t const &
    {
        return _outs;
    }

    inline auto output_types() const -> std::vector<uint64_t> const &
    {
        return _types;
    }

    inline auto owned(strange::graph<Config, Signal> const & owner, uint64_t id) -> void
    {
        _owner = owner._weak();
        _own_id = id;
    }

    inline auto latency(Config const & config = Config{}) const -> uint64_t
    {
        return 0;
    }

    inline auto closure(Config const & config = Config{}) const -> std::function<auto (std::vector<Signal>) -> std::vector<Signal>>
    {
        return [*this](std::vector<Signal> inputs) {
            inputs.resize(_outs);
            return inputs;
        };
    }

private:
    uint64_t _ins;
    uint64_t _outs;
    std::vector<uint64_t> _types;
    strange::graph<Config, Signal> _owner;
    uint64_t _own_id;
};
}
}
