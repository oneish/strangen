#pragma once

#define DART_HAS_RAPIDJSON 1
#define DART_USE_SAJSON 1
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#include <dart.h>
#pragma GCC diagnostic pop

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
        auto dest_ = dest._dynamic_<baggage_<strange::implementation::baggage>>();
        if (dest_._something())
        {
            dest_._thing().packet = packet;
        }
        else if (is_null())
        {
            dest.from_null();
        }
        else if (is_bool())
        {
            dest.from_bool(to_bool());
        }
        else if (is_int64())
        {
            dest.from_int64(to_int64());
        }
        else if (is_uint64())
        {
            dest.from_uint64(to_uint64());
        }
        else if (is_double())
        {
            dest.from_double(to_double());
        }
        else if (is_string())
        {
            dest.from_string(to_string());
        }
        else if (is_array())
        {
            dest.from_array(to_array());
        }
        else if (is_object())
        {
            dest.from_object(to_object());
        }
        else if (is_any())
        {
            dest.from_any(to_any());
        }
    }

    inline auto unpack(bag const & src) -> void
    {
        auto src_ = src._dynamic_<baggage_<strange::implementation::baggage>>();
        if (src_._something())
        {
            packet = src_._thing().packet;
        }
        else if (src.is_null())
        {
            from_null();
        }
        else if (src.is_bool())
        {
            from_bool(src.to_bool());
        }
        else if (src.is_int64())
        {
            from_int64(src.to_int64());
        }
        else if (src.is_uint64())
        {
            from_uint64(src.to_uint64());
        }
        else if (src.is_double())
        {
            from_double(src.to_double());
        }
        else if (src.is_string())
        {
            from_string(src.to_string());
        }
        else if (src.is_array())
        {
            from_array(src.to_array());
        }
        else if (src.is_object())
        {
            from_object(src.to_object());
        }
        else if (src.is_any())
        {
            from_any(src.to_any());
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
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.pack_unique = pack_unique});
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
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = dart::packet::make_boolean(false), .pack_unique = pack_unique});
    }

    inline auto make_bool(bool src) const -> bag
    {
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = dart::packet::make_boolean(src), .pack_unique = pack_unique});
    }

    inline auto is_int64() const -> bool
    {
        return packet.is_integer();
    }

    inline auto as_int64(int64_t & dest) const -> void
    {
        dest = packet.as<int64_t>();
    }

    inline auto to_int64() const -> int64_t
    {
        return packet.as<int64_t>();
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
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = dart::packet::make_integer(0), .pack_unique = pack_unique});
    }

    inline auto make_int64(int64_t src) const -> bag
    {
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = dart::packet::make_integer(src), .pack_unique = pack_unique});
    }

    inline auto is_uint64() const -> bool
    {
        return packet.is_integer();
    }

    inline auto as_uint64(uint64_t & dest) const -> void
    {
        dest = packet.as<uint64_t>();
    }

    inline auto to_uint64() const -> uint64_t
    {
        return packet.as<uint64_t>();
    }

    inline auto from_uint64() -> void
    {
        packet = dart::packet::make_integer(0);
    }

    inline auto from_uint64(uint64_t src) -> void
    {
        packet = dart::packet::make_integer(src);
    }

    inline auto make_uint64() const -> bag
    {
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = dart::packet::make_integer(0), .pack_unique = pack_unique});
    }

    inline auto make_uint64(uint64_t src) const -> bag
    {
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = dart::packet::make_integer(src), .pack_unique = pack_unique});
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
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = dart::packet::make_decimal(0.0), .pack_unique = pack_unique});
    }

    inline auto make_double(double src) const -> bag
    {
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = dart::packet::make_decimal(src), .pack_unique = pack_unique});
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
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = dart::packet::make_string(std::string{}), .pack_unique = pack_unique});
    }

    inline auto make_string(std::string const & src) const -> bag
    {
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = dart::packet::make_string(src), .pack_unique = pack_unique});
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
            auto item_ = item._dynamic_<baggage_<strange::implementation::baggage>>();
            if (!item_._something())
            {
                item_ = strange::baggage_<strange::implementation::baggage>::_make_(strange::implementation::baggage{.pack_unique = pack_unique});
                item.pack(item_);
            }
            packet.push_back(item_._thing().packet);
        }
    }

    inline auto make_array() const -> bag
    {
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = dart::packet::make_array(), .pack_unique = pack_unique});
    }

    inline auto make_array(std::vector<bag> const & src) const -> bag
    {
        auto pack = dart::packet::make_array();
        for (auto const & item : src)
        {
            auto item_ = item._dynamic_<baggage_<strange::implementation::baggage>>();
            if (!item_._something())
            {
                item_ = strange::baggage_<strange::implementation::baggage>::_make_(strange::implementation::baggage{.pack_unique = pack_unique});
                item.pack(item_);
            }
            pack.push_back(item_._thing().packet);
        }
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = pack, .pack_unique = pack_unique});
    }

    inline auto get_array(std::size_t index) const -> bag
    {
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = packet.get(index), .unpack_unique = unpack_unique});
    }

    inline auto set_array(std::size_t index, bag const & value) -> void
    {
        auto value_ = value._dynamic_<baggage_<strange::implementation::baggage>>();
        if (!value_._something())
        {
            value_ = strange::baggage_<strange::implementation::baggage>::_make_(strange::implementation::baggage{.pack_unique = pack_unique});
            value.pack(value_);
        }
        packet.set(index, value_._thing().packet);
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
        auto value_ = value._dynamic_<baggage_<strange::implementation::baggage>>();
        if (!value_._something())
        {
            value_ = strange::baggage_<strange::implementation::baggage>::_make_(strange::implementation::baggage{.pack_unique = pack_unique});
            value.pack(value_);
        }
        packet.insert(pos, value_._thing().packet);
    }

    inline auto erase_array(std::size_t pos) -> void
    {
        packet.erase(pos);
    }

    inline auto push_front_array(bag const & value) -> void
    {
        auto value_ = value._dynamic_<baggage_<strange::implementation::baggage>>();
        if (!value_._something())
        {
            value_ = strange::baggage_<strange::implementation::baggage>::_make_(strange::implementation::baggage{.pack_unique = pack_unique});
            value.pack(value_);
        }
        packet.push_front(value_._thing().packet);
    }

    inline auto push_back_array(bag const & value) -> void
    {
        auto value_ = value._dynamic_<baggage_<strange::implementation::baggage>>();
        if (!value_._something())
        {
            value_ = strange::baggage_<strange::implementation::baggage>::_make_(strange::implementation::baggage{.pack_unique = pack_unique});
            value.pack(value_);
        }
        packet.push_back(value_._thing().packet);
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

    inline auto as_array_bool(std::vector<bool> & dest) const -> void
    {
        dest = packet.as<std::vector<bool>>();
    }

    inline auto as_array_int64(std::vector<int64_t> & dest) const -> void
    {
        dest = packet.as<std::vector<int64_t>>();
    }

    inline auto as_array_uint64(std::vector<uint64_t> & dest) const -> void
    {
        dest = packet.as<std::vector<uint64_t>>();
    }

    inline auto as_array_double(std::vector<double> & dest) const -> void
    {
        dest = packet.as<std::vector<double>>();
    }

    inline auto as_array_string(std::vector<std::string> & dest) const -> void
    {
        dest = packet.as<std::vector<std::string>>();
    }

    inline auto as_array_any(std::vector<strange::any> & dest) const -> void
    {
        dest.clear();
        if (!packet.empty())
        {
            bool reset = !unpack_unique;
            if (reset)
            {
                unpack_unique = std::make_shared<std::vector<stuff>>();
            }
            for (auto const & item : packet)
            {
                dest.push_back(strange::implementation::baggage{.packet = item, .unpack_unique = unpack_unique}.to_any());
            }
            if (reset)
            {
                unpack_unique.reset();
            }
        }
    }

    inline auto to_array_bool() const -> std::vector<bool>
    {
        return packet.as<std::vector<bool>>();
    }

    inline auto to_array_int64() const -> std::vector<int64_t>
    {
        return packet.as<std::vector<int64_t>>();
    }

    inline auto to_array_uint64() const -> std::vector<uint64_t>
    {
        return packet.as<std::vector<uint64_t>>();
    }

    inline auto to_array_double() const -> std::vector<double>
    {
        return packet.as<std::vector<double>>();
    }

    inline auto to_array_string() const -> std::vector<std::string>
    {
        return packet.as<std::vector<std::string>>();
    }

    inline auto to_array_any() const -> std::vector<strange::any>
    {
        auto dest = std::vector<strange::any>{};
        if (!packet.empty())
        {
            bool reset = !unpack_unique;
            if (reset)
            {
                unpack_unique = std::make_shared<std::vector<stuff>>();
            }
            for (auto const & item : packet)
            {
                dest.push_back(strange::implementation::baggage{.packet = item, .unpack_unique = unpack_unique}.to_any());
            }
            if (reset)
            {
                unpack_unique.reset();
            }
        }
        return dest;
    }

    inline auto from_array_bool(std::vector<bool> const & src) -> void
    {
        packet = dart::packet::make_array();
        for (auto const item : src)
        {
            packet.push_back(dart::packet::make_boolean(item));
        }
    }

    inline auto from_array_int64(std::vector<int64_t> const & src) -> void
    {
        packet = src;
    }

    inline auto from_array_uint64(std::vector<uint64_t> const & src) -> void
    {
        packet = src;
    }

    inline auto from_array_double(std::vector<double> const & src) -> void
    {
        packet = src;
    }

    inline auto from_array_string(std::vector<std::string> const & src) -> void
    {
        packet = src;
    }

    inline auto from_array_any(std::vector<strange::any> const & src) -> void
    {
        packet = dart::packet::make_array();
        if (!src.empty())
        {
            bool reset = !pack_unique;
            if (reset)
            {
                pack_unique = std::make_shared<std::unordered_map<void const *, std::size_t>>();
            }
            for (auto const & item : src)
            {
                auto item_ = strange::implementation::baggage{.pack_unique = pack_unique};
                item_.from_any(item);
                packet.push_back(item_.packet);
            }
            if (reset)
            {
                pack_unique.reset();
            }
        }
    }

    inline auto make_array_bool(std::vector<bool> const & src) const -> bag
    {
        auto pack = dart::packet::make_array();
        for (auto const item : src)
        {
            pack.push_back(dart::packet::make_boolean(item));
        }
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = pack, .pack_unique = pack_unique});
    }

    inline auto make_array_int64(std::vector<int64_t> const & src) const -> bag
    {
        dart::packet pack;
        pack = src;
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = pack, .pack_unique = pack_unique});
    }

    inline auto make_array_uint64(std::vector<uint64_t> const & src) const -> bag
    {
        dart::packet pack;
        pack = src;
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = pack, .pack_unique = pack_unique});
    }

    inline auto make_array_double(std::vector<double> const & src) const -> bag
    {
        dart::packet pack;
        pack = src;
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = pack, .pack_unique = pack_unique});
    }

    inline auto make_array_string(std::vector<std::string> const & src) const -> bag
    {
        dart::packet pack;
        pack = src;
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = pack, .pack_unique = pack_unique});
    }

    inline auto make_array_any(std::vector<strange::any> const & src) const -> bag
    {
        auto pack = dart::packet::make_array();
        if (!src.empty())
        {
            bool reset = !pack_unique;
            if (reset)
            {
                pack_unique = std::make_shared<std::unordered_map<void const *, std::size_t>>();
            }
            for (auto const & item : src)
            {
                auto item_ = strange::implementation::baggage{.pack_unique = pack_unique};
                item_.from_any(item);
                pack.push_back(item_.packet);
            }
            if (reset)
            {
                pack_unique.reset();
            }
        }
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = pack, .pack_unique = pack_unique});
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
            auto second_ = pair.second._dynamic_<baggage_<strange::implementation::baggage>>();
            if (!second_._something())
            {
                second_ = strange::baggage_<strange::implementation::baggage>::_make_(strange::implementation::baggage{.pack_unique = pack_unique});
                pair.second.pack(second_);
            }
            packet.insert(pair.first, second_._thing().packet);
        }
    }

    inline auto make_object() const -> bag
    {
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = dart::packet::make_object(), .pack_unique = pack_unique});
    }

    inline auto make_object(std::unordered_map<std::string, bag> const & src) const -> bag
    {
        auto pack = dart::packet::make_object();
        for (auto const & pair : src)
        {
            auto second_ = pair.second._dynamic_<baggage_<strange::implementation::baggage>>();
            if (!second_._something())
            {
                second_ = strange::baggage_<strange::implementation::baggage>::_make_(strange::implementation::baggage{.pack_unique = pack_unique});
                pair.second.pack(second_);
            }
            pack.insert(pair.first, second_._thing().packet);
        }
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = pack, .pack_unique = pack_unique});
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
        auto value_ = value._dynamic_<baggage_<strange::implementation::baggage>>();
        if (!value_._something())
        {
            value_ = strange::baggage_<strange::implementation::baggage>::_make_(strange::implementation::baggage{.pack_unique = pack_unique});
            value.pack(value_);
        }
        packet.insert(key, value_._thing().packet);
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
        auto value_ = value._dynamic_<baggage_<strange::implementation::baggage>>();
        if (!value_._something())
        {
            value_ = strange::baggage_<strange::implementation::baggage>::_make_(strange::implementation::baggage{.pack_unique = pack_unique});
            value.pack(value_);
        }
        packet.set(key, value_._thing().packet);
    }

    inline auto contains_object(std::string const & key) const -> bool
    {
        return packet.has_key(key);
    }

    inline auto is_any() const -> bool
    {
        return packet.is_null() || packet.is_integer() || packet.is_str() || (packet.is_array() && packet.size() >= 2 && packet.at(0).is_integer() && packet.at(1).is_str());
    }

    inline auto as_any(any & dest) const -> void
    {
        if (packet.is_null())
        {
            dest = any{};
            return;
        }
        if (packet.is_str())
        {
            dest = any::_manufacture(packet.str());
            return;
        }
        bool reset = !unpack_unique;
        if (reset)
        {
            unpack_unique = std::make_shared<std::vector<stuff>>();
        }
        else if (packet.is_integer())
        {
            auto idx = packet.as<int64_t>();
            bool is_weak = (idx < 0);
            auto index = static_cast<std::size_t>(is_weak ? (-1 - idx) : idx);
            if (unpack_unique->size() > index)
            {
                if (is_weak)
                {
                    dest = unpack_unique->at(index)._weak();
                }
                else
                {
                    dest = unpack_unique->at(index);
                }
            }
            return;
        }
        std::size_t size = packet.is_array() ? packet.size() : 0;
        if (size >= 2 && packet.at(0).is_integer() && packet.at(1).is_str())
        {
            auto idx = packet.at(0).as<int64_t>();
            bool is_weak = (idx < 0);
            auto index = static_cast<std::size_t>(is_weak ? (-1 - idx) : idx);
            if (unpack_unique->size() <= index)
            {
                unpack_unique->resize(index + 1);
            }
            unpack_unique->at(index) = stuff::_manufacture(packet.at(1).str());
            if (size >= 3)
            {
                unpack_unique->at(index).unpack(strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = packet.at(2), .unpack_unique = unpack_unique}));
            }
            if (is_weak)
            {
                dest = unpack_unique->at(index)._weak();
            }
            else
            {
                dest = unpack_unique->at(index);
            }
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
        bool is_weak = src._is_weak();
        any const strong = is_weak ? src._strong() : any{src};
        if (!strong._something())
        {
            packet = dart::packet::make_null();
            return;
        }
        auto address = strong._address();
        auto stu = strong._dynamic<stuff>();
        std::size_t index = 0;
        bool reset = !pack_unique;
        if (reset)
        {
            if (!stu._something())
            {
                packet = dart::packet::make_string(strong._name());
                return;
            }
            pack_unique = std::make_shared<std::unordered_map<void const *, std::size_t>>();
        }
        else
        {
            auto it = pack_unique->find(address);
            if (it != pack_unique->end())
            {
                packet = dart::packet::make_integer(is_weak ? (-1 - static_cast<int64_t>(it->second)) : static_cast<int64_t>(it->second));
                return;
            }
            index = pack_unique->size();
        }
        pack_unique->emplace(address, index);
        packet = dart::packet::make_array();
        packet.push_back(dart::packet::make_integer(is_weak ? (-1 - static_cast<int64_t>(index)) : static_cast<int64_t>(index)));
        packet.push_back(dart::packet::make_string(strong._name()));
        if (stu._something())
        {
            auto pack_ = strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.pack_unique = pack_unique});
            stu.pack(pack_);
            packet.push_back(pack_._static<baggage_<strange::implementation::baggage>>()._thing().packet);
        }
        if (reset)
        {
            pack_unique.reset();
        }
    }

    inline auto make_any() const -> bag
    {
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.pack_unique = pack_unique});
    }

    inline auto make_any(any const & src) const -> bag
    {
        auto imp = strange::implementation::baggage{.pack_unique = pack_unique};
        imp.from_any(src);
        return strange::baggage::_make<strange::implementation::baggage>(imp);
    }

    inline auto seal() -> void
    {
        if (packet.is_object())
        {
            packet.finalize();
        }
    }

    inline auto unseal() -> void
    {
        if (packet.is_object())
        {
            packet.definalize();
        }
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
        if (packet.is_finalized())
        {
            auto buffer = packet.get_bytes();
            binary = std::string{reinterpret_cast<char const*>(buffer.data()), buffer.size()};
        }
        else if (packet.is_object())
        {
            auto buf = packet;
            buf.finalize();
            auto buffer = buf.get_bytes();
            binary = std::string{reinterpret_cast<char const*>(buffer.data()), buffer.size()};
        }
        else
        {
            auto buf = dart::buffer::object{"", packet};
            auto buffer = buf.get_bytes();
            binary = std::string{reinterpret_cast<char const*>(buffer.data()), buffer.size()};
        }
    }

    inline auto to_binary() const -> std::string
    {
        if (packet.is_finalized())
        {
            auto buffer = packet.get_bytes();
            return std::string{reinterpret_cast<char const*>(buffer.data()), buffer.size()};
        }
        if (packet.is_object())
        {
            auto buf = packet;
            buf.finalize();
            auto buffer = buf.get_bytes();
            return std::string{reinterpret_cast<char const*>(buffer.data()), buffer.size()};
        }
        auto buf = dart::buffer::object{"", packet};
        auto buffer = buf.get_bytes();
        return std::string{reinterpret_cast<char const*>(buffer.data()), buffer.size()};
    }

    inline auto from_binary(std::string const & binary) -> void
    {
        packet = dart::packet{gsl::make_span(reinterpret_cast<std::byte const*>(binary.data()), binary.size())};
        if (packet.size() == 1 && packet.has_key(""))
        {
            packet = packet.get("");
        }
    }

    inline auto make_binary(std::string const & binary) const -> package
    {
        auto pack = dart::packet{gsl::make_span(reinterpret_cast<std::byte const*>(binary.data()), binary.size())};
        if (pack.size() == 1 && pack.has_key(""))
        {
            pack = pack.get("");
        }
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = pack});
    }

    inline auto is_json() const -> bool
    {
#if DART_HAS_RAPIDJSON
        return true;
#else
        return false;
#endif
    }

    inline auto as_json(std::string & json) const -> void
    {
#if DART_HAS_RAPIDJSON
        if (packet.is_object())
        {
            json = packet.to_json();
        }
        else
        {
            auto obj = dart::packet::make_object("", packet);
            json = obj.to_json();
        }
#else
        json = std::string{};
#endif
    }

    inline auto to_json() const -> std::string
    {
#if DART_HAS_RAPIDJSON
        if (packet.is_object())
        {
            return packet.to_json();
        }
        auto obj = dart::packet::make_object("", packet);
        return obj.to_json();
#else
        return std::string{};
#endif
    }

    inline auto from_json(std::string const & json) -> void
    {
#if DART_HAS_RAPIDJSON
        packet = dart::packet::from_json(json);
        if (packet.size() == 1 && packet.has_key(""))
        {
            packet = packet.get("");
        }
#else
        packet = dart::packet::make_null();
#endif
    }

    inline auto make_json(std::string const & json) const -> package
    {
#if DART_HAS_RAPIDJSON
        auto pack = dart::packet::from_json(json);
        if (pack.size() == 1 && pack.has_key(""))
        {
            pack = pack.get("");
        }
        return strange::baggage::_make<strange::implementation::baggage>(strange::implementation::baggage{.packet = pack});
#else
        return strange::package{};
#endif
    }
};
}
}
