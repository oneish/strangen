#pragma once

#include <dart.h>

namespace strange
{
namespace implementation
{
struct baggage
{
    dart::packet packet = dart::packet::make_null();

    inline auto pack(bag & dest) const -> void
    {
        /*
        auto baggage_ = dest._dynamic<baggage_<strange::implementation::baggage>>();
        if (baggage_._something())
        {
            baggage_._thing().packet = packet;
        }
        */
    }

    inline auto pack(bag & dest, std::unordered_map<void const *, std::size_t> & unique) const -> void
    {
        pack(dest);
    }

    inline auto unpack(bag const & src) -> void
    {
        /*
        auto baggage_ = dest._dynamic<baggage_<strange::implementation::baggage>>();
        if (baggage_._something())
        {
            packet = baggage_._thing().packet;
        }
        */
    }

    inline auto unpack(bag const & src, std::vector<any> & unique) -> void
    {
        unpack(src);
    }

    inline auto swap(bag & other) -> void
    {
        /*
        auto baggage_ = dest._dynamic<baggage_<strange::implementation::baggage>>();
        if (baggage_._something())
        {
            packet.swap(baggage_._thing().packet);
        }
        */
    }

    inline auto is_null() const -> bool
    {
        return packet.is_null();
    }

    inline auto from_null() -> void
    {
        packet = dart::packet::make_null();
    }

    inline auto make_null() const -> bag
    {
        // return baggage_._make<strange::implementation::baggage>();
        return strange::bag{};
    }

    inline auto is_bool() const -> bool
    {
        return packet.is_boolean();
    }

    inline auto as_bool(bool & dest) const -> void
    {
        dest = packet.boolean();
    }

    inline auto to_bool() const -> bool
    {
        return packet.boolean();
    }

    inline auto from_bool() -> void
    {
        packet = dart::packet::make_boolean(false);
    }

    inline auto from_bool(bool src) -> void
    {
        packet = dart::packet::make_boolean(src);
    }

    inline auto make_bool() const -> bag
    {
        // return baggage_._make<strange::implementation::baggage>(strange::implementation::baggage{.packet = dart::packet::make_boolean(false)});
        return strange::bag{};
    }

    inline auto make_bool(bool src) const -> bag
    {
        // return baggage_._make<strange::implementation::baggage>(strange::implementation::baggage{.packet = dart::packet::make_boolean(src)});
        return strange::bag{};
    }

    inline auto is_int64() const -> bool
    {
        return packet.is_integer();
    }

    inline auto as_int64(int64_t & dest) const -> void
    {
        dest = packet.integer();
    }

    inline auto to_int64() const -> int64_t
    {
        return packet.integer();
    }

    inline auto from_int64() -> void
    {
        packet = dart::packet::make_integer(0);
    }

    inline auto from_int64(int64_t src) -> void
    {
        packet = dart::packet::make_integer(src);
    }

    inline auto make_int64() const -> bag
    {
        // return baggage_._make<strange::implementation::baggage>(strange::implementation::baggage{.packet = dart::packet::make_integer(0)});
        return strange::bag{};
    }

    inline auto make_int64(int64_t src) const -> bag
    {
        // return baggage_._make<strange::implementation::baggage>(strange::implementation::baggage{.packet = dart::packet::make_integer(src)});
        return strange::bag{};
    }

    inline auto is_double() const -> bool
    {
        return packet.is_decimal();
    }

    inline auto as_double(double & dest) const -> void
    {
        dest = packet.decimal();
    }

    inline auto to_double() const -> double
    {
        return packet.decimal();
    }

    inline auto from_double() -> void
    {
        packet = dart::packet::make_decimal(0.0);
    }

    inline auto from_double(double src) -> void
    {
        packet = dart::packet::make_decimal(src);
    }

    inline auto make_double() const -> bag
    {
        // return baggage_._make<strange::implementation::baggage>(strange::implementation::baggage{.packet = dart::packet::make_decimal(0.0)});
        return strange::bag{};
    }

    inline auto make_double(int64_t src) const -> bag
    {
        // return baggage_._make<strange::implementation::baggage>(strange::implementation::baggage{.packet = dart::packet::make_decimal(src)});
        return strange::bag{};
    }

    inline auto is_string() const -> bool
    {
        return packet.is_str();
    }

    inline auto as_string(std::string & dest) const -> void
    {
        dest = packet.str();
    }

    inline auto to_string() const -> std::string
    {
        return packet.str();
    }

    inline auto from_string() -> void
    {
        packet = dart::packet::make_string(std::string{});
    }

    inline auto from_string(std::string const & src) -> void
    {
        packet = dart::packet::make_string(src);
    }

    inline auto make_string() const -> bag
    {
        // return baggage_._make<strange::implementation::baggage>(strange::implementation::baggage{.packet = dart::packet::make_string(std::string{})});
        return strange::bag{};
    }

    inline auto make_string(std::string const & src) const -> bag
    {
        // return baggage_._make<strange::implementation::baggage>(strange::implementation::baggage{.packet = dart::packet::make_string(src)});
        return strange::bag{};
    }

    inline auto is_array() const -> bool
    {
        return packet.is_array();
    }

    inline auto as_array(std::vector<bag> & dest) const -> void
    {
        dest.clear();
        for (auto const & item : packet)
        {
            // dest.push_back(baggage_._make<strange::implementation::baggage>(strange::implementation::baggage{.packet = item}));
            dest.push_back(strange::bag{});
        }
    }

    inline auto to_array() const -> std::vector<bag>
    {
        auto dest = std::vector<bag>{};
        for (auto const & item : packet)
        {
            // dest.push_back(baggage_._make<strange::implementation::baggage>(strange::implementation::baggage{.packet = item}));
            dest.push_back(strange::bag{});
        }
        return dest;
    }

    inline auto from_array() -> void
    {
        packet = dart::packet::make_array();
    }

    inline auto from_array(std::vector<bag> const & src) -> void
    {
        packet = dart::packet::make_array();
        for (auto const & item : src)
        {
            /*
            auto baggage_ = item._dynamic<baggage_<strange::implementation::baggage>>();
            if (baggage_._something())
            {
                packet.push_back(baggage_._thing().packet);
            }
            */
        }
    }

    inline auto make_array() const -> bag
    {
        // return baggage_._make<strange::implementation::baggage>(strange::implementation::baggage{.packet = dart::packet::make_array()});
        return strange::bag{};
    }

    inline auto make_array(std::vector<bag> const & src) const -> bag
    {
        auto pack = dart::packet::make_array();
        for (auto const & item : src)
        {
            /*
            auto baggage_ = item._dynamic<baggage_<strange::implementation::baggage>>();
            if (baggage_._something())
            {
                pack.push_back(baggage_._thing().packet);
            }
            */
        }
        // return baggage_._make<strange::implementation::baggage>(strange::implementation::baggage{.packet = pack});
        return strange::bag{};
    }
};
}
}
