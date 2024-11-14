#pragma once
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>

namespace strange
{
struct _no_copy_constructor {};

// _common is the base class for all strange abstractions
// _common does not have any virtual functions or a v-table itself
// _common has a single data member, which is shared pointer to _common::_base
// _common::_base encapsulates the polymorphism and has virtual functions and a v-table
// _common has some boilerplate functions for casting, copy-on-write, reflection, memory and error handling
struct _common
{
protected:
    struct _base
    {
        virtual ~_base() = default;

        virtual auto _address() const -> void const * = 0;
        virtual auto _sizeof() const -> size_t = 0;
        virtual auto _clone() const -> std::shared_ptr<_common::_base> = 0;
        virtual inline auto _cat() const -> std::string = 0;
        virtual inline auto _cats() const -> std::unordered_set<std::string> = 0;
        virtual inline auto _copy() const -> bool = 0;
        virtual inline auto _name() const -> std::string = 0;

        virtual inline auto _error() const -> std::string
        {
            return std::string{};
        }
    };

    std::shared_ptr<_common::_base> _shared;

    static inline std::unordered_map<std::string, std::function<std::shared_ptr<_common::_base>()>> _factory_;

    inline _common() = default;
    inline _common(_common const &) = default;
    inline _common(_common &&) = default;
    inline auto operator=(_common const &) -> _common & = default;
    inline auto operator=(_common &&) -> _common & = default;

    explicit inline _common(std::shared_ptr<_common::_base> const & shared)
    :_shared{shared}
    {
    }

    explicit inline _common(std::shared_ptr<_common::_base> && shared)
    :_shared{std::move(shared)}
    {
    }

private:
    struct _message final : _common::_base
    {
        template<typename Message>
        inline _message(Message && msg)
        :message{std::forward<Message>(msg)}
        {
        }

        inline auto _address() const -> void const * final
        {
            return &message;
        }

        inline auto _sizeof() const -> size_t final
        {
            return sizeof(message);
        }

        inline auto _clone() const -> std::shared_ptr<_common::_base> final
        {
            throw _no_copy_constructor{};
        }

        virtual inline auto _cat() const -> std::string final
        {
            return std::string{};
        }

        virtual inline auto _cats() const -> std::unordered_set<std::string> final
        {
            return std::unordered_set<std::string>{};
        }

        virtual inline auto _copy() const -> bool final
        {
            return false;
        }

        virtual inline auto _name() const -> std::string final
        {
            return std::string{};
        }

        inline auto _error() const -> std::string final
        {
            return message;
        }

    private:
        std::string const message;
    };

public:
    inline auto _mutate() -> bool
    {
        if (_shared.use_count() > 1)
        {
            try
            {
                _shared = _shared->_clone();
                return true;
            }
            catch(_no_copy_constructor const &)
            {
            }
        }
        return false;
    }

    inline auto _address() const -> void const *
    {
        if (_shared)
        {
            return _shared->_address();
        }
        return nullptr;
    }

    inline auto _sizeof() const -> size_t
    {
        if (_shared)
        {
            return _shared->_sizeof();
        }
        return static_cast<size_t>(0);
    }

    inline auto _cat() const -> std::string
    {
        if (_shared)
        {
            return _shared->_cat();
        }
        return std::string{};
    }

    inline auto _cats() const -> std::unordered_set<std::string>
    {
        if (_shared)
        {
            return _shared->_cats();
        }
        return std::unordered_set<std::string>{};
    }

    inline auto _copy() const -> bool
    {
        if (_shared)
        {
            return _shared->_copy();
        }
        return false;
    }

    inline auto _name() const -> std::string
    {
        if (_shared)
        {
            return _shared->_name();
        }
        return std::string{};
    }

    inline auto _something() const -> bool
    {
        return _shared.operator bool();
    }

    template<typename Message>
    inline auto _error(Message && message) -> std::string
    {
        _shared = std::make_shared<_common::_message>(std::forward<Message>(message));
        return _shared->_error();
    }

    inline auto _error() const -> std::string
    {
        if (_shared)
        {
            return _shared->_error();
        }
        return std::string{};
    }

    template<typename Other>
    inline auto _static() const -> Other
    {
        return Other{_shared};
    }

    template<typename Other>
    inline auto _dynamic() const -> Other
    {
        Other other{_shared};
        if (other._valid())
        {
            return other;
        }
        return Other{};
    }
};
}
