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
    inline thru_processor(std::vector<uint64_t> types, bool feedback = false)
    :_ins(types.size())
    ,_outs(types.size())
    ,_types(std::move(types))
    ,_feedback(feedback)
    {
    }

    inline auto pack(strange::bag & dest) const -> void
    {
        dest.from_object();
        dest.insert_object("types", dest.make_array_uint64(_types));
        dest.insert_object("feedback", dest.make_bool(_feedback));
    }

    inline auto unpack(strange::bag const & src) -> void
    {
        src.get_object("types").as_array_uint64(_types);
        _ins = _types.size();
        _outs = _types.size();
        src.get_object("feedback").as_bool(_feedback);
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

    inline auto feedback() const -> bool
    {
        return _feedback;
    }

    inline auto latency(Config const & config = Config{}) const -> uint64_t
    {
        return 0;
    }

    inline auto closure(Config const & config) const -> std::function<auto (std::vector<Signal>) -> std::vector<Signal>>
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
    bool _feedback;
};
}
}
