#pragma once
#include "../common/strange__common.h"
#include <string>
#include <vector>

#include <memory>
#include <type_traits>

namespace strange
{

struct parameter_a;

struct operation_a;

struct abstraction_a;

struct space_a;

struct parameter_a : virtual strange::_common
{
    inline parameter_a() = default;

    inline parameter_a(parameter_a const & other)
    :strange::_common{other}
    {
    }

    inline parameter_a(parameter_a && other)
    :strange::_common{std::move(other)}
    {
    }

    inline auto operator=(parameter_a const & other) -> parameter_a &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(parameter_a && other) -> parameter_a &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline parameter_a(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    {
    }

    explicit inline parameter_a(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    {
    }

protected:
    struct _derived : strange::_common::_base
    {
        static inline auto _static_shared_to_base(std::shared_ptr<parameter_a::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return derived;
        }

        virtual auto type() const -> std::string const & = 0;

        virtual auto type() -> std::string & = 0;

        virtual auto name() const -> std::string const & = 0;

        virtual auto name() -> std::string & = 0;

        virtual auto argument() const -> std::string const & = 0;

        virtual auto argument() -> std::string & = 0;
    };

private:
    template<typename _Thing, bool _Copy>
    struct _instance final : parameter_a::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :parameter_a::_derived{}
        ,_thing{std::forward<_Args>(_args) ...}
        {
        }

        inline auto _address() const -> void const * final
        {
            return &_thing;
        }

        inline auto _sizeof() const -> size_t final
        {
            return sizeof(_thing);
        }

        inline auto _clone() const -> std::shared_ptr<strange::_common::_base> final
        {
            if constexpr (_Copy)
            {
                return parameter_a::_derived::_static_shared_to_base(std::make_shared<parameter_a::_instance<_Thing, _Copy>>(_thing));
            }
            else
            {
                throw true;
            }
        }

        inline auto type() const -> std::string const & final;

        inline auto type() -> std::string & final;

        inline auto name() const -> std::string const & final;

        inline auto name() -> std::string & final;

        inline auto argument() const -> std::string const & final;

        inline auto argument() -> std::string & final;

    private:
        _Thing _thing;
    };

public:
    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> parameter_a
    {
        return parameter_a{parameter_a::_derived::_static_shared_to_base(std::make_shared<parameter_a::_instance<_Thing, _Copy>>(std::forward<_Args>(_args) ...))};
    }

    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<parameter_a::_derived>(strange::_common::_shared).operator bool();
    }

    inline auto type() const -> std::string const &;

    inline auto type() -> std::string &;

    inline auto name() const -> std::string const &;

    inline auto name() -> std::string &;

    inline auto argument() const -> std::string const &;

    inline auto argument() -> std::string &;
};

struct operation_a : virtual strange::_common
{
    inline operation_a() = default;

    inline operation_a(operation_a const & other)
    :strange::_common{other}
    {
    }

    inline operation_a(operation_a && other)
    :strange::_common{std::move(other)}
    {
    }

    inline auto operator=(operation_a const & other) -> operation_a &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(operation_a && other) -> operation_a &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline operation_a(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    {
    }

    explicit inline operation_a(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    {
    }

protected:
    struct _derived : strange::_common::_base
    {
        static inline auto _static_shared_to_base(std::shared_ptr<operation_a::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return derived;
        }

        virtual auto name() const -> std::string const & = 0;

        virtual auto name() -> std::string & = 0;

        virtual auto parameters() const -> std::vector<parameter_a> const & = 0;

        virtual auto parameters() -> std::vector<parameter_a> & = 0;

        virtual auto constness() const -> bool const & = 0;

        virtual auto constness() -> bool & = 0;

        virtual auto result() const -> std::string const & = 0;

        virtual auto result() -> std::string & = 0;

        virtual auto data() const -> bool const & = 0;

        virtual auto data() -> bool & = 0;
    };

private:
    template<typename _Thing, bool _Copy>
    struct _instance final : operation_a::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :operation_a::_derived{}
        ,_thing{std::forward<_Args>(_args) ...}
        {
        }

        inline auto _address() const -> void const * final
        {
            return &_thing;
        }

        inline auto _sizeof() const -> size_t final
        {
            return sizeof(_thing);
        }

        inline auto _clone() const -> std::shared_ptr<strange::_common::_base> final
        {
            if constexpr (_Copy)
            {
                return operation_a::_derived::_static_shared_to_base(std::make_shared<operation_a::_instance<_Thing, _Copy>>(_thing));
            }
            else
            {
                throw true;
            }
        }

        inline auto name() const -> std::string const & final;

        inline auto name() -> std::string & final;

        inline auto parameters() const -> std::vector<parameter_a> const & final;

        inline auto parameters() -> std::vector<parameter_a> & final;

        inline auto constness() const -> bool const & final;

        inline auto constness() -> bool & final;

        inline auto result() const -> std::string const & final;

        inline auto result() -> std::string & final;

        inline auto data() const -> bool const & final;

        inline auto data() -> bool & final;

    private:
        _Thing _thing;
    };

public:
    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> operation_a
    {
        return operation_a{operation_a::_derived::_static_shared_to_base(std::make_shared<operation_a::_instance<_Thing, _Copy>>(std::forward<_Args>(_args) ...))};
    }

    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<operation_a::_derived>(strange::_common::_shared).operator bool();
    }

    inline auto name() const -> std::string const &;

    inline auto name() -> std::string &;

    inline auto parameters() const -> std::vector<parameter_a> const &;

    inline auto parameters() -> std::vector<parameter_a> &;

    inline auto constness() const -> bool const &;

    inline auto constness() -> bool &;

    inline auto result() const -> std::string const &;

    inline auto result() -> std::string &;

    inline auto data() const -> bool const &;

    inline auto data() -> bool &;
};

struct abstraction_a : virtual strange::_common
{
    inline abstraction_a() = default;

    inline abstraction_a(abstraction_a const & other)
    :strange::_common{other}
    {
    }

    inline abstraction_a(abstraction_a && other)
    :strange::_common{std::move(other)}
    {
    }

    inline auto operator=(abstraction_a const & other) -> abstraction_a &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(abstraction_a && other) -> abstraction_a &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline abstraction_a(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    {
    }

    explicit inline abstraction_a(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    {
    }

protected:
    struct _derived : strange::_common::_base
    {
        static inline auto _static_shared_to_base(std::shared_ptr<abstraction_a::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return derived;
        }

        virtual auto parameters() const -> std::vector<parameter_a> const & = 0;

        virtual auto parameters() -> std::vector<parameter_a> & = 0;

        virtual auto name() const -> std::string const & = 0;

        virtual auto name() -> std::string & = 0;

        virtual auto parents() const -> std::vector<std::string> const & = 0;

        virtual auto parents() -> std::vector<std::string> & = 0;

        virtual auto operations() const -> std::vector<operation_a> const & = 0;

        virtual auto operations() -> std::vector<operation_a> & = 0;
    };

private:
    template<typename _Thing, bool _Copy>
    struct _instance final : abstraction_a::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :abstraction_a::_derived{}
        ,_thing{std::forward<_Args>(_args) ...}
        {
        }

        inline auto _address() const -> void const * final
        {
            return &_thing;
        }

        inline auto _sizeof() const -> size_t final
        {
            return sizeof(_thing);
        }

        inline auto _clone() const -> std::shared_ptr<strange::_common::_base> final
        {
            if constexpr (_Copy)
            {
                return abstraction_a::_derived::_static_shared_to_base(std::make_shared<abstraction_a::_instance<_Thing, _Copy>>(_thing));
            }
            else
            {
                throw true;
            }
        }

        inline auto parameters() const -> std::vector<parameter_a> const & final;

        inline auto parameters() -> std::vector<parameter_a> & final;

        inline auto name() const -> std::string const & final;

        inline auto name() -> std::string & final;

        inline auto parents() const -> std::vector<std::string> const & final;

        inline auto parents() -> std::vector<std::string> & final;

        inline auto operations() const -> std::vector<operation_a> const & final;

        inline auto operations() -> std::vector<operation_a> & final;

    private:
        _Thing _thing;
    };

public:
    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> abstraction_a
    {
        return abstraction_a{abstraction_a::_derived::_static_shared_to_base(std::make_shared<abstraction_a::_instance<_Thing, _Copy>>(std::forward<_Args>(_args) ...))};
    }

    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<abstraction_a::_derived>(strange::_common::_shared).operator bool();
    }

    inline auto parameters() const -> std::vector<parameter_a> const &;

    inline auto parameters() -> std::vector<parameter_a> &;

    inline auto name() const -> std::string const &;

    inline auto name() -> std::string &;

    inline auto parents() const -> std::vector<std::string> const &;

    inline auto parents() -> std::vector<std::string> &;

    inline auto operations() const -> std::vector<operation_a> const &;

    inline auto operations() -> std::vector<operation_a> &;
};

struct space_a : virtual strange::_common
{
    inline space_a() = default;

    inline space_a(space_a const & other)
    :strange::_common{other}
    {
    }

    inline space_a(space_a && other)
    :strange::_common{std::move(other)}
    {
    }

    inline auto operator=(space_a const & other) -> space_a &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(space_a && other) -> space_a &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    explicit inline space_a(std::shared_ptr<strange::_common::_base> const & shared)
    :strange::_common{shared}
    {
    }

    explicit inline space_a(std::shared_ptr<strange::_common::_base> && shared)
    :strange::_common{std::move(shared)}
    {
    }

protected:
    struct _derived : strange::_common::_base
    {
        static inline auto _static_shared_to_base(std::shared_ptr<space_a::_derived> derived) -> std::shared_ptr<strange::_common::_base>
        {
            return derived;
        }

        virtual auto name() const -> std::string const & = 0;

        virtual auto name() -> std::string & = 0;

        virtual auto abstractions() const -> std::vector<abstraction_a> const & = 0;

        virtual auto abstractions() -> std::vector<abstraction_a> & = 0;
    };

private:
    template<typename _Thing, bool _Copy>
    struct _instance final : space_a::_derived
    {
        template<typename ... _Args>
        inline _instance(_Args && ... _args)
        :space_a::_derived{}
        ,_thing{std::forward<_Args>(_args) ...}
        {
        }

        inline auto _address() const -> void const * final
        {
            return &_thing;
        }

        inline auto _sizeof() const -> size_t final
        {
            return sizeof(_thing);
        }

        inline auto _clone() const -> std::shared_ptr<strange::_common::_base> final
        {
            if constexpr (_Copy)
            {
                return space_a::_derived::_static_shared_to_base(std::make_shared<space_a::_instance<_Thing, _Copy>>(_thing));
            }
            else
            {
                throw true;
            }
        }

        inline auto name() const -> std::string const & final;

        inline auto name() -> std::string & final;

        inline auto abstractions() const -> std::vector<abstraction_a> const & final;

        inline auto abstractions() -> std::vector<abstraction_a> & final;

    private:
        _Thing _thing;
    };

public:
    template<typename _Thing, bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> space_a
    {
        return space_a{space_a::_derived::_static_shared_to_base(std::make_shared<space_a::_instance<_Thing, _Copy>>(std::forward<_Args>(_args) ...))};
    }

    inline auto _valid() const -> bool
    {
        return std::dynamic_pointer_cast<space_a::_derived>(strange::_common::_shared).operator bool();
    }

    inline auto name() const -> std::string const &;

    inline auto name() -> std::string &;

    inline auto abstractions() const -> std::vector<abstraction_a> const &;

    inline auto abstractions() -> std::vector<abstraction_a> &;
};

template<typename _Thing, bool _Copy>
inline auto parameter_a::_instance<_Thing, _Copy>::type() const -> std::string const &
{
    return _thing.type;
}

template<typename _Thing, bool _Copy>
inline auto parameter_a::_instance<_Thing, _Copy>::type() -> std::string &
{
    return _thing.type;
}

template<typename _Thing, bool _Copy>
inline auto parameter_a::_instance<_Thing, _Copy>::name() const -> std::string const &
{
    return _thing.name;
}

template<typename _Thing, bool _Copy>
inline auto parameter_a::_instance<_Thing, _Copy>::name() -> std::string &
{
    return _thing.name;
}

template<typename _Thing, bool _Copy>
inline auto parameter_a::_instance<_Thing, _Copy>::argument() const -> std::string const &
{
    return _thing.argument;
}

template<typename _Thing, bool _Copy>
inline auto parameter_a::_instance<_Thing, _Copy>::argument() -> std::string &
{
    return _thing.argument;
}

inline auto parameter_a::type() const -> std::string const &
{
    return std::dynamic_pointer_cast<parameter_a::_derived>(strange::_common::_shared)->type();
}

inline auto parameter_a::type() -> std::string &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<parameter_a::_derived>(strange::_common::_shared)->type();
}

inline auto parameter_a::name() const -> std::string const &
{
    return std::dynamic_pointer_cast<parameter_a::_derived>(strange::_common::_shared)->name();
}

inline auto parameter_a::name() -> std::string &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<parameter_a::_derived>(strange::_common::_shared)->name();
}

inline auto parameter_a::argument() const -> std::string const &
{
    return std::dynamic_pointer_cast<parameter_a::_derived>(strange::_common::_shared)->argument();
}

inline auto parameter_a::argument() -> std::string &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<parameter_a::_derived>(strange::_common::_shared)->argument();
}

template<typename _Thing, bool _Copy>
inline auto operation_a::_instance<_Thing, _Copy>::name() const -> std::string const &
{
    return _thing.name;
}

template<typename _Thing, bool _Copy>
inline auto operation_a::_instance<_Thing, _Copy>::name() -> std::string &
{
    return _thing.name;
}

template<typename _Thing, bool _Copy>
inline auto operation_a::_instance<_Thing, _Copy>::parameters() const -> std::vector<parameter_a> const &
{
    return _thing.parameters;
}

template<typename _Thing, bool _Copy>
inline auto operation_a::_instance<_Thing, _Copy>::parameters() -> std::vector<parameter_a> &
{
    return _thing.parameters;
}

template<typename _Thing, bool _Copy>
inline auto operation_a::_instance<_Thing, _Copy>::constness() const -> bool const &
{
    return _thing.constness;
}

template<typename _Thing, bool _Copy>
inline auto operation_a::_instance<_Thing, _Copy>::constness() -> bool &
{
    return _thing.constness;
}

template<typename _Thing, bool _Copy>
inline auto operation_a::_instance<_Thing, _Copy>::result() const -> std::string const &
{
    return _thing.result;
}

template<typename _Thing, bool _Copy>
inline auto operation_a::_instance<_Thing, _Copy>::result() -> std::string &
{
    return _thing.result;
}

template<typename _Thing, bool _Copy>
inline auto operation_a::_instance<_Thing, _Copy>::data() const -> bool const &
{
    return _thing.data;
}

template<typename _Thing, bool _Copy>
inline auto operation_a::_instance<_Thing, _Copy>::data() -> bool &
{
    return _thing.data;
}

inline auto operation_a::name() const -> std::string const &
{
    return std::dynamic_pointer_cast<operation_a::_derived>(strange::_common::_shared)->name();
}

inline auto operation_a::name() -> std::string &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<operation_a::_derived>(strange::_common::_shared)->name();
}

inline auto operation_a::parameters() const -> std::vector<parameter_a> const &
{
    return std::dynamic_pointer_cast<operation_a::_derived>(strange::_common::_shared)->parameters();
}

inline auto operation_a::parameters() -> std::vector<parameter_a> &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<operation_a::_derived>(strange::_common::_shared)->parameters();
}

inline auto operation_a::constness() const -> bool const &
{
    return std::dynamic_pointer_cast<operation_a::_derived>(strange::_common::_shared)->constness();
}

inline auto operation_a::constness() -> bool &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<operation_a::_derived>(strange::_common::_shared)->constness();
}

inline auto operation_a::result() const -> std::string const &
{
    return std::dynamic_pointer_cast<operation_a::_derived>(strange::_common::_shared)->result();
}

inline auto operation_a::result() -> std::string &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<operation_a::_derived>(strange::_common::_shared)->result();
}

inline auto operation_a::data() const -> bool const &
{
    return std::dynamic_pointer_cast<operation_a::_derived>(strange::_common::_shared)->data();
}

inline auto operation_a::data() -> bool &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<operation_a::_derived>(strange::_common::_shared)->data();
}

template<typename _Thing, bool _Copy>
inline auto abstraction_a::_instance<_Thing, _Copy>::parameters() const -> std::vector<parameter_a> const &
{
    return _thing.parameters;
}

template<typename _Thing, bool _Copy>
inline auto abstraction_a::_instance<_Thing, _Copy>::parameters() -> std::vector<parameter_a> &
{
    return _thing.parameters;
}

template<typename _Thing, bool _Copy>
inline auto abstraction_a::_instance<_Thing, _Copy>::name() const -> std::string const &
{
    return _thing.name;
}

template<typename _Thing, bool _Copy>
inline auto abstraction_a::_instance<_Thing, _Copy>::name() -> std::string &
{
    return _thing.name;
}

template<typename _Thing, bool _Copy>
inline auto abstraction_a::_instance<_Thing, _Copy>::parents() const -> std::vector<std::string> const &
{
    return _thing.parents;
}

template<typename _Thing, bool _Copy>
inline auto abstraction_a::_instance<_Thing, _Copy>::parents() -> std::vector<std::string> &
{
    return _thing.parents;
}

template<typename _Thing, bool _Copy>
inline auto abstraction_a::_instance<_Thing, _Copy>::operations() const -> std::vector<operation_a> const &
{
    return _thing.operations;
}

template<typename _Thing, bool _Copy>
inline auto abstraction_a::_instance<_Thing, _Copy>::operations() -> std::vector<operation_a> &
{
    return _thing.operations;
}

inline auto abstraction_a::parameters() const -> std::vector<parameter_a> const &
{
    return std::dynamic_pointer_cast<abstraction_a::_derived>(strange::_common::_shared)->parameters();
}

inline auto abstraction_a::parameters() -> std::vector<parameter_a> &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<abstraction_a::_derived>(strange::_common::_shared)->parameters();
}

inline auto abstraction_a::name() const -> std::string const &
{
    return std::dynamic_pointer_cast<abstraction_a::_derived>(strange::_common::_shared)->name();
}

inline auto abstraction_a::name() -> std::string &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<abstraction_a::_derived>(strange::_common::_shared)->name();
}

inline auto abstraction_a::parents() const -> std::vector<std::string> const &
{
    return std::dynamic_pointer_cast<abstraction_a::_derived>(strange::_common::_shared)->parents();
}

inline auto abstraction_a::parents() -> std::vector<std::string> &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<abstraction_a::_derived>(strange::_common::_shared)->parents();
}

inline auto abstraction_a::operations() const -> std::vector<operation_a> const &
{
    return std::dynamic_pointer_cast<abstraction_a::_derived>(strange::_common::_shared)->operations();
}

inline auto abstraction_a::operations() -> std::vector<operation_a> &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<abstraction_a::_derived>(strange::_common::_shared)->operations();
}

template<typename _Thing, bool _Copy>
inline auto space_a::_instance<_Thing, _Copy>::name() const -> std::string const &
{
    return _thing.name;
}

template<typename _Thing, bool _Copy>
inline auto space_a::_instance<_Thing, _Copy>::name() -> std::string &
{
    return _thing.name;
}

template<typename _Thing, bool _Copy>
inline auto space_a::_instance<_Thing, _Copy>::abstractions() const -> std::vector<abstraction_a> const &
{
    return _thing.abstractions;
}

template<typename _Thing, bool _Copy>
inline auto space_a::_instance<_Thing, _Copy>::abstractions() -> std::vector<abstraction_a> &
{
    return _thing.abstractions;
}

inline auto space_a::name() const -> std::string const &
{
    return std::dynamic_pointer_cast<space_a::_derived>(strange::_common::_shared)->name();
}

inline auto space_a::name() -> std::string &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<space_a::_derived>(strange::_common::_shared)->name();
}

inline auto space_a::abstractions() const -> std::vector<abstraction_a> const &
{
    return std::dynamic_pointer_cast<space_a::_derived>(strange::_common::_shared)->abstractions();
}

inline auto space_a::abstractions() -> std::vector<abstraction_a> &
{
    strange::_common::_mutate();
    return std::dynamic_pointer_cast<space_a::_derived>(strange::_common::_shared)->abstractions();
}

}
