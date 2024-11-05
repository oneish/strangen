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
        auto dest_ = dest._dynamic<baggage_<strange::implementation::baggage>>();
        if (dest_._something())
        {
            dest_._thing().packet = packet;
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
        auto src_ = src._dynamic<baggage_<strange::implementation::baggage>>();
        if (src_._something())
        {
            packet = src_._thing().packet;
        }
        */
    }

    inline auto unpack(bag const & src, std::vector<any> & unique) -> void
    {
        unpack(src);
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
        }
    }

    inline auto to_array() const -> std::vector<bag>
    {
        auto dest = std::vector<bag>{};
        for (auto const & item : packet)
        {
            // dest.push_back(baggage_._make<strange::implementation::baggage>(strange::implementation::baggage{.packet = item}));
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
            auto item_ = item._dynamic<baggage_<strange::implementation::baggage>>();
            if (item_._something())
            {
                packet.push_back(item_._thing().packet);
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
            auto item_ = item._dynamic<baggage_<strange::implementation::baggage>>();
            if (item_._something())
            {
                pack.push_back(item_._thing().packet);
            }
            */
        }
        // return baggage_._make<strange::implementation::baggage>(strange::implementation::baggage{.packet = pack});
        return strange::bag{};
    }

    inline auto get_array(std::size_t index) const -> bag
    {
        // return baggage_._make<strange::implementation::baggage>(strange::implementation::baggage{.packet = packet.get(index)});
        return strange::bag{};
    }

    inline auto set_array(std::size_t index, bag const & value) -> void
    {
        /*
        auto value_ = value._dynamic<baggage_<strange::implementation::baggage>>();
        if (value_._something())
        {
            packet.at(index) = value_._thing().packet;
        }
        */
    }

    inline auto front_array() const -> bag
    {
        // return baggage_._make<strange::implementation::baggage>(strange::implementation::baggage{.packet = packet.front()});
        return strange::bag{};
    }

    inline auto back_array() const -> bag
    {
        // return baggage_._make<strange::implementation::baggage>(strange::implementation::baggage{.packet = packet.back()});
        return strange::bag{};
    }

    inline auto empty_array() const -> bool
    {
        return packet.empty();
    }

    inline auto size_array() const -> std::size_t
    {
        return packet.size();
    }

    inline auto reserve_array(std::size_t new_cap) -> void
    {
        packet.reserve(new_cap);
    }

    inline auto capacity_array() const -> std::size_t
    {
        return packet.capacity();
    }

    inline auto clear_array() -> void
    {
        packet.clear();
    }

    inline auto insert_array(std::size_t pos, bag const & value) -> void
    {
        /*
        auto value_ = value._dynamic<baggage_<strange::implementation::baggage>>();
        if (value_._something())
        {
            packet.at(index) = value_._thing().packet;
        }
        */
    }

    inline auto erase_array(std::size_t pos) -> void
    {
        packet.erase(pos);
    }

    inline auto push_front_array(bag const & value) -> void
    {
        /*
        auto value_ = value._dynamic<baggage_<strange::implementation::baggage>>();
        if (value_._something())
        {
            packet.push_front(value_._thing().packet);
        }
        */
    }

    inline auto push_back_array(bag const & value) -> void
    {
        /*
        auto value_ = value._dynamic<baggage_<strange::implementation::baggage>>();
        if (value_._something())
        {
            packet.push_back(value_._thing().packet);
        }
        */
    }

    inline auto pop_front_array() -> bag
    {
        // return baggage_._make<strange::implementation::baggage>(strange::implementation::baggage{.packet = packet.pop_front()});
        return strange::bag{};
    }

    inline auto pop_back_array() -> bag
    {
        // return baggage_._make<strange::implementation::baggage>(strange::implementation::baggage{.packet = packet.pop_back()});
        return strange::bag{};
    }

    inline auto resize_array(std::size_t count) -> void
    {
        packet.resize(count);
    }

    inline auto is_object() const -> bool
    {
        return packet.is_object();
    }

    inline auto as_object(std::unordered_map<std::string, bag> & dest) const -> void
    {
        dest.clear();
        for (auto const & pair : packet)
        {
            // dest.insert(pair.first, baggage_._make<strange::implementation::baggage>(strange::implementation::baggage{.packet = pair.second}));
        }
    }

    inline auto to_object() const -> std::unordered_map<std::string, bag>
    {
        auto dest = std::unordered_map<std::string, bag>{};
        for (auto const & pair : packet)
        {
            // dest.insert(pair.first, baggage_._make<strange::implementation::baggage>(strange::implementation::baggage{.packet = pair.second}));
        }
        return dest;
    }

    inline auto from_object() -> void
    {
        packet = dart::packet::make_object();
    }

    inline auto from_object(std::unordered_map<std::string, bag> const & src) -> void
    {
        packet = dart::packet::make_object();
        for (auto const & pair : src)
        {
            /*
            auto second_ = pair.second._dynamic<baggage_<strange::implementation::baggage>>();
            if (second_._something())
            {
                packet.insert(pair.first, second_._thing().packet);
            }
            */
        }
    }

    inline auto make_object() const -> bag
    {
        // return baggage_._make<strange::implementation::baggage>(strange::implementation::baggage{.packet = dart::packet::make_object()});
        return strange::bag{};
    }

    inline auto make_object(std::unordered_map<std::string, bag> const & src) const -> bag
    {
        auto pack = dart::packet::make_object();
        for (auto const & pair : src)
        {
            /*
            auto second_ = pair.second._dynamic<baggage_<strange::implementation::baggage>>();
            if (second_._something())
            {
                pack.insert(pair.first, second_._thing().packet);
            }
            */
        }
        // return baggage_._make<strange::implementation::baggage>(strange::implementation::baggage{.packet = pack});
        return strange::bag{};
    }

    inline auto empty_object() const -> bool
    {
        return packet.empty();
    }

    inline auto size_object() const -> std::size_t
    {
        return packet.size();
    }

    inline auto clear_object() -> void
    {
        packet.clear();
    }

    inline auto insert_object(std::string const & key, bag const & value) -> bool
    {
        /*
        auto value_ = value._dynamic<baggage_<strange::implementation::baggage>>();
        if (value_._something())
        {
            packet.insert(key, value_._thing().packet);
        }
        */
    }

    inline auto erase_object(std::string const & key) -> bool
    {
        packet.erase(key);
    }

    inline auto get_object(std::string const & key) const -> bag
    {
        // return baggage_._make<strange::implementation::baggage>(strange::implementation::baggage{.packet = packet.get(key)});
        return strange::bag{};
    }

    inline auto set_object(std::string const & key, bag const & value) -> bool
    {
        /*
        auto value_ = value._dynamic<baggage_<strange::implementation::baggage>>();
        if (value_._something())
        {
            packet.insert_or_assign(key, value_._thing().packet);
        }
        */
    }

    inline auto contains_object(std::string const & key) const -> bool
    {
        return packet.has_key(key);
    }

    inline auto is_any() const -> bool
    {
        return packet.is_null() || packet.is_integer() || packet.is_str() || (packet.is_array() && packet.size() >= 2 && packet.at(0).is_str());
    }

    inline auto as_any(any & dest) const -> void
    {
        std::vector<any> unique;
        return as_any(dest, unique);
    }

    inline auto as_any(any & dest, std::vector<any> & unique) const -> void
    {
        if (packet.is_null())
        {
            dest = any{};
        }
        else if (packet.is_integer())
        {
            dest = unique.at(packet.integer());
        }
        else if (packet.is_str())
        {
            dest = _common::_construct<any>(packet.str());
        }
        else if (packet.is_array() && packet.size() >= 2 && packet.at(0).is_str())
        {
            _common::_construct<any>(packet.at(0).str());
            // dest._static<stuff>().unpack(baggage_._make<strange::implementation::baggage>(strange::implementation::baggage{.packet = packet.at(1)}), unique);
        }
    }

    inline auto to_any() const -> any;
    inline auto to_any(std::vector<any> & unique) const -> any;
    inline auto from_any() -> void;
    inline auto from_any(any const & src) -> void;
    inline auto from_any(any const & src, std::unordered_map<void const *, std::size_t> & unique) -> void;
    inline auto make_any() const -> bag;
    inline auto make_any(any const & src) const -> bag;
    inline auto make_any(any const & src, std::unordered_map<void const *, std::size_t> & unique) const -> bag;

    inline auto seal() -> void;
    inline auto unseal() -> void;
    inline auto sealed() const -> bool;

    inline auto is_binary() const -> bool;
    inline auto as_binary(std::string & binary) const -> void;
    inline auto to_binary() const -> std::string;
    inline auto from_binary(std::string const & binary) -> void;

    inline auto is_json() const -> bool;
    inline auto as_json(std::string & json) const -> void;
    inline auto to_json() const -> std::string;
    inline auto from_json(std::string const & json) -> void;

    inline auto is_yaml() const -> bool;
    inline auto as_yaml(std::string & yaml) const -> void;
    inline auto to_yaml() const -> std::string;
    inline auto from_yaml(std::string const & yaml) -> void;
};
}
}
