#pragma once

#define DART_HAS_RAPIDJSON 1
#define DART_USE_SAJSON 1
#include <dart.h>

namespace strange
{
namespace implementation
{
struct baggage
{
    dart::packet packet = dart::packet::make_null();
    mutable std::shared_ptr<std::vector<stuff>> unpack_unique;
    mutable std::shared_ptr<std::unordered_map<void const *, std::size_t>> pack_unique;

    inline auto pack(bag & dest) const -> void
    {
        auto dest_ = dest._dynamic<baggage_<strange::implementation::baggage>>();
        if (dest_._something())
        {
            dest_._thing().packet = packet;
        }
    }

    inline auto unpack(bag const & src) -> void
    {
        auto src_ = src._dynamic<baggage_<strange::implementation::baggage>>();
        if (src_._something())
        {
            packet = src_._thing().packet;
        }
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
        return strange::baggage::_make<strange::implementation::baggage>();
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
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = dart::packet::make_boolean(false)});
    }

    inline auto make_bool(bool src) const -> bag
    {
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = dart::packet::make_boolean(src)});
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
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = dart::packet::make_integer(0)});
    }

    inline auto make_int64(int64_t src) const -> bag
    {
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = dart::packet::make_integer(src)});
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
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = dart::packet::make_decimal(0.0)});
    }

    inline auto make_double(int64_t src) const -> bag
    {
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = dart::packet::make_decimal(src)});
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
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = dart::packet::make_string(std::string{})});
    }

    inline auto make_string(std::string const & src) const -> bag
    {
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = dart::packet::make_string(src)});
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
            dest.push_back(strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = item, .unpack_unique = unpack_unique}));
        }
    }

    inline auto to_array() const -> std::vector<bag>
    {
        auto dest = std::vector<bag>{};
        for (auto const & item : packet)
        {
            dest.push_back(strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = item, .unpack_unique = unpack_unique}));
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
            auto item_ = item._dynamic<baggage_<strange::implementation::baggage>>();
            if (item_._something())
            {
                packet.push_back(item_._thing().packet);
            }
        }
    }

    inline auto make_array() const -> bag
    {
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = dart::packet::make_array()});
    }

    inline auto make_array(std::vector<bag> const & src) const -> bag
    {
        auto pack = dart::packet::make_array();
        for (auto const & item : src)
        {
            auto item_ = item._dynamic<baggage_<strange::implementation::baggage>>();
            if (item_._something())
            {
                pack.push_back(item_._thing().packet);
            }
        }
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = pack});
    }

    inline auto get_array(std::size_t index) const -> bag
    {
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = packet.get(index), .unpack_unique = unpack_unique});
    }

    inline auto set_array(std::size_t index, bag const & value) -> void
    {
        auto value_ = value._dynamic<baggage_<strange::implementation::baggage>>();
        if (value_._something())
        {
            packet.set(index, value_._thing().packet);
        }
    }

    inline auto front_array() const -> bag
    {
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = packet.front(), .unpack_unique = unpack_unique});
    }

    inline auto back_array() const -> bag
    {
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = packet.back(), .unpack_unique = unpack_unique});
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
        auto value_ = value._dynamic<baggage_<strange::implementation::baggage>>();
        if (value_._something())
        {
            packet.insert(pos, value_._thing().packet);
        }
    }

    inline auto erase_array(std::size_t pos) -> void
    {
        packet.erase(pos);
    }

    inline auto push_front_array(bag const & value) -> void
    {
        auto value_ = value._dynamic<baggage_<strange::implementation::baggage>>();
        if (value_._something())
        {
            packet.push_front(value_._thing().packet);
        }
    }

    inline auto push_back_array(bag const & value) -> void
    {
        auto value_ = value._dynamic<baggage_<strange::implementation::baggage>>();
        if (value_._something())
        {
            packet.push_back(value_._thing().packet);
        }
    }

    inline auto pop_front_array() -> bag
    {
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = packet.pop_front(), .unpack_unique = unpack_unique});
    }

    inline auto pop_back_array() -> bag
    {
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = packet.pop_back(), .unpack_unique = unpack_unique});
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
        for (auto [key, value] = packet.kvbegin(); value != packet.end(); ++key, ++value)
        {
            dest.emplace(key->str(), strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = *value, .unpack_unique = unpack_unique}));
        }
    }

    inline auto to_object() const -> std::unordered_map<std::string, bag>
    {
        auto dest = std::unordered_map<std::string, bag>{};
        for (auto [key, value] = packet.kvbegin(); value != packet.end(); ++key, ++value)
        {
            dest.emplace(key->str(), strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = *value, .unpack_unique = unpack_unique}));
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
            auto second_ = pair.second._dynamic<baggage_<strange::implementation::baggage>>();
            if (second_._something())
            {
                packet.insert(pair.first, second_._thing().packet);
            }
        }
    }

    inline auto make_object() const -> bag
    {
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = dart::packet::make_object()});
    }

    inline auto make_object(std::unordered_map<std::string, bag> const & src) const -> bag
    {
        auto pack = dart::packet::make_object();
        for (auto const & pair : src)
        {
            auto second_ = pair.second._dynamic<baggage_<strange::implementation::baggage>>();
            if (second_._something())
            {
                pack.insert(pair.first, second_._thing().packet);
            }
        }
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = pack});
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

    inline auto insert_object(std::string const & key, bag const & value) -> void
    {
        auto value_ = value._dynamic<baggage_<strange::implementation::baggage>>();
        if (value_._something())
        {
            packet.insert(key, value_._thing().packet);
        }
    }

    inline auto erase_object(std::string const & key) -> void
    {
        packet.erase(key);
    }

    inline auto get_object(std::string const & key) const -> bag
    {
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = packet.get(key), .unpack_unique = unpack_unique});
    }

    inline auto set_object(std::string const & key, bag const & value) -> void
    {
        auto value_ = value._dynamic<baggage_<strange::implementation::baggage>>();
        if (value_._something())
        {
            packet.set(key, value_._thing().packet);
        }
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
        if (packet.is_null())
        {
            dest = any{};
            return;
        }
        bool reset = !unpack_unique;
        if (packet.is_str())
        {
            if (reset)
            {
                dest = any::_manufacture(packet.str());
            }
            else
            {
                unpack_unique->push_back(stuff::_manufacture(packet.str()));
                dest = unpack_unique->back();
            }
            return;
        }
        if (reset)
        {
            unpack_unique = std::make_shared<std::vector<stuff>>();
        }
        else if (packet.is_integer())
        {
            dest = unpack_unique->at(packet.integer());
            return;
        }
        if (packet.is_array() && packet.size() >= 2 && packet.at(0).is_str())
        {
            auto index = unpack_unique->size();
            unpack_unique->push_back(stuff::_manufacture(packet.at(0).str()));
            unpack_unique->at(index).unpack(strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = packet.at(1), .unpack_unique = unpack_unique}));
            dest = unpack_unique->at(index);
        }
        if (reset)
        {
            unpack_unique.reset();
        }
    }

    inline auto to_any() const -> any
    {
        auto dest = any{};
        as_any(dest);
        return dest;
    }

    inline auto from_any() -> void
    {
        packet = dart::packet::make_null();
    }

    inline auto from_any(any const & src) -> void
    {
        if (!src._something())
        {
            packet = dart::packet::make_null();
            return;
        }
        auto address = src._address();
        auto stuff_ = src._dynamic<stuff>();
        bool reset = stuff_._something() && !pack_unique;
        if (reset)
        {
            pack_unique = std::make_shared<std::unordered_map<void const *, std::size_t>>();
            pack_unique->emplace(address, 0);
        }
        else if (pack_unique)
        {
            auto it = pack_unique->find(address);
            if (it != pack_unique->end())
            {
                packet = dart::packet::make_integer(it->second);
                return;
            }
            pack_unique->emplace(address, pack_unique->size());
        }
        if (!stuff_._something())
        {
            packet = dart::packet::make_string(src._name());
        }
        else
        {
            packet = dart::packet::make_array();
            packet.push_back(dart::packet::make_string(src._name()));
            auto pack_ = strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.pack_unique = pack_unique});
            stuff_.pack(pack_);
            packet.push_back(pack_._static<baggage_<strange::implementation::baggage>>()._thing().packet);
        }
        if (reset)
        {
            pack_unique.reset();
        }
    }

    inline auto make_any() const -> bag
    {
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{});
    }

    inline auto make_any(any const & src) const -> bag
    {
        if (!src._something())
        {
            return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{});
        }
        auto address = src._address();
        auto stuff_ = src._dynamic<stuff>();
        bool reset = stuff_._something() && !pack_unique;
        dart::packet pack;
        if (reset)
        {
            pack_unique = std::make_shared<std::unordered_map<void const *, std::size_t>>();
            pack_unique->emplace(address, 0);
        }
        else if (pack_unique)
        {
            auto it = pack_unique->find(address);
            if (it != pack_unique->end())
            {
                return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = dart::packet::make_integer(it->second)});
            }
            pack_unique->emplace(address, pack_unique->size());
        }
        if (!stuff_._something())
        {
            pack = dart::packet::make_string(src._name());
        }
        else
        {
            pack = dart::packet::make_array();
            pack.push_back(dart::packet::make_string(src._name()));
            auto pack_ = strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.pack_unique = pack_unique});
            stuff_.pack(pack_);
            pack.push_back(pack_._static<baggage_<strange::implementation::baggage>>()._thing().packet);
        }
        if (reset)
        {
            pack_unique.reset();
        }
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = pack});
    }

    inline auto seal() -> void
    {
        packet.finalize();
    }

    inline auto unseal() -> void
    {
        packet.definalize();
    }

    inline auto sealed() const -> bool
    {
        return packet.is_finalized();
    }

    inline auto is_binary() const -> bool
    {
        return packet.is_finalized();
    }

    inline auto as_binary(std::string & binary) const -> void
    {
        auto buffer = packet.get_bytes();
        binary = std::string{reinterpret_cast<char const*>(buffer.data()), buffer.size()};
    }

    inline auto to_binary() const -> std::string
    {
        auto buffer = packet.get_bytes();
		return std::string{reinterpret_cast<char const*>(buffer.data()), buffer.size()};
    }

    inline auto from_binary(std::string const & binary) -> void
    {
        packet = dart::packet{gsl::make_span(reinterpret_cast<gsl::byte const*>(binary.data()), binary.size())};
    }

    inline auto make_binary(std::string const & binary) const -> package
    {
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = dart::packet{gsl::make_span(reinterpret_cast<gsl::byte const*>(binary.data()), binary.size())}});
    }

    inline auto is_json() const -> bool
    {
#if DART_HAS_RAPIDJSON
        return packet.is_finalized();
#else
        return false;
#endif
    }

    inline auto as_json(std::string & json) const -> void
    {
#if DART_HAS_RAPIDJSON
        json = packet.to_json();
#endif
    }

    inline auto to_json() const -> std::string
    {
#if DART_HAS_RAPIDJSON
        return packet.to_json();
#else
        return std::string{};
#endif
    }

    inline auto from_json(std::string const & json) -> void
    {
#if DART_HAS_RAPIDJSON
        packet = dart::packet::from_json(json);
#endif
    }

    inline auto make_json(std::string const & json) const -> package
    {
#if DART_HAS_RAPIDJSON
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = dart::packet::from_json(json)});
#else
        return strange::package{};
#endif
    }
};
}
}
