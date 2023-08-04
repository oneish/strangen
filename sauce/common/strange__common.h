#pragma once
#include <memory>
#include <string>

namespace strange
{

struct _common
{
protected:
    struct _base
    {
        virtual ~_base() = default;

        virtual auto _address() const -> void const * = 0;
        virtual auto _sizeof() const -> size_t = 0;
        virtual auto _clone() const -> std::shared_ptr<_common::_base> = 0;

        virtual inline auto _error() const -> std::string
        {
            return std::string{};
        }
    };

    std::shared_ptr<_common::_base> _shared;

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

    inline auto _mutate() -> void
    {
        if (_shared.use_count() > 1)
        {
            try
            {
                _shared = _shared->_clone();
            }
            catch(bool const &)
            {
            }
        }
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
            throw false;
        }

        inline auto _error() const -> std::string final
        {
            return message;
        }

    private:
        std::string const message;
    };

public:
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