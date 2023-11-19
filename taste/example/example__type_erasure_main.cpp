#include "../../sauce/strange/strange.h"
#include "example__type_erasure.h"

namespace temp
{
#include "example__space_transformation_3.h"
}
#include <iostream>

struct implementation
{
    // implementation() = default;
    // implementation(implementation const&) = delete;

    int x = 0;
 
    inline void display(example::button b) const
    {
        std::cout << "display: " << x << std::endl;
    }

    inline void inc()
    {
        std::cout << "inc: " << x << " -> " << (x + 1) << std::endl;
        ++x;
    }

    inline void operator++()
    {
        std::cout << "operator++: " << x << " -> " << (x + 1) << std::endl;
        ++x;
    }

    inline void operator--(int)
    {
        std::cout << "operator--: " << x << " -> " << (x - 1) << std::endl;
        x--;
    }

    inline void push()
    {
        std::cout << "push: " << x << " -> " << (x - 1) << std::endl;
        --x;
    }

    inline void dec()
    {
        std::cout << "dec: " << x << " -> " << (x - 1) << std::endl;
        --x;
    }

    inline int get() const
    {
        std::cout << "get: " << x << std::endl;
        return x;
    }
};

template<typename Datatype>
struct implementation_template
{
    // implementation() = default;
    // implementation(implementation const&) = delete;

    Datatype x = 0;
 
    inline void display(example::button b) const
    {
        std::cout << "display: " << x << std::endl;
    }

    inline void inc()
    {
        std::cout << "inc: " << x << " -> " << (x + 1) << std::endl;
        ++x;
    }

    inline void operator++()
    {
        std::cout << "operator++: " << x << " -> " << (x + 1) << std::endl;
        ++x;
    }

    inline void operator--(int)
    {
        std::cout << "operator--: " << x << " -> " << (x - 1) << std::endl;
        x--;
    }

    inline void push()
    {
        std::cout << "push: " << x << " -> " << (x - 1) << std::endl;
        --x;
    }

    inline void dec()
    {
        std::cout << "dec: " << x << " -> " << (x - 1) << std::endl;
        --x;
    }

    inline Datatype get() const
    {
        std::cout << "get: " << x << std::endl;
        return x;
    }
};

void increment(example::number & num)
{
    num.inc();
}

namespace strange
{

template<typename _Thing, typename T = typename _Thing::value_type>
struct vector_a_;

template<typename _Thing, typename T>
struct vector_a_ : vector_a<T>
{
private:
    struct _tag_ {};

    explicit inline vector_a_(_tag_, std::shared_ptr<strange::_common::_base> && shared = std::shared_ptr<strange::_common::_base>{})
    :strange::_common{std::move(shared)}
    ,vector_a<T>{}
    {
    }

public:
    inline static auto _null() -> vector_a_
    {
        return vector_a_{_tag_{}};
    }

    template<bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _make(_Args && ... _args) -> vector_a_
    {
        return vector_a_{_tag_{}, vector_a_::_derived::_static_shared_to_base(std::make_shared<typename vector_a_::template _instance<_Thing, _Copy>>(std::forward<_Args>(_args) ...))};
    }

    template<bool _Copy = std::is_copy_constructible_v<_Thing>, typename ... _Args>
    inline static auto _incognito(_Args && ... _args) -> vector_a<T>
    {
        return vector_a<T>{vector_a_::_derived::_static_shared_to_base(std::make_shared<typename vector_a_::template _instance<_Thing, _Copy>>(std::forward<_Args>(_args) ...))};
    }

    template<typename ... _Args>
    explicit inline vector_a_(_Args && ... _args)
    :strange::_common{vector_a_::_derived::_static_shared_to_base(std::make_shared<typename vector_a_::template _instance<_Thing, std::is_copy_constructible_v<_Thing>>>(std::forward<_Args>(_args) ...))}
    ,vector_a<T>{}
    {
    }

    inline auto operator=(vector_a_ const & other) -> vector_a_ &
    {
        strange::_common::operator=(other);
        return *this;
    }

    inline auto operator=(vector_a_ && other) -> vector_a_ &
    {
        strange::_common::operator=(std::move(other));
        return *this;
    }

    inline auto _thing() const -> _Thing const &
    {
        return std::dynamic_pointer_cast<typename vector_a_::template _instance<_Thing, std::is_copy_constructible_v<_Thing>>>(strange::_common::_shared)->_thing;
    }

    inline auto _thing() -> _Thing &
    {
        strange::_common::_mutate();
        return std::dynamic_pointer_cast<typename vector_a_::template _instance<_Thing, std::is_copy_constructible_v<_Thing>>>(strange::_common::_shared)->_thing;
    }
};

}

int main()
{
    auto v1 = strange::vector_a_<std::vector<int>>::_null();
    auto v2 = strange::vector_a_<std::vector<int>>::_make();
    auto v3 = strange::vector_a_<std::vector<int>>::_make(1,2,3);
    auto v4 = strange::vector_a_<std::vector<int>>::_incognito();
    auto v5 = strange::vector_a_<std::vector<int>>::_incognito(1,2,3);
    auto v6 = strange::vector_a_<std::vector<int>>{};
    auto v7 = strange::vector_a_<std::vector<int>>{1,2,3};
    v2._thing().push_back(123);
    v4.push_back(123);
    v6._thing().push_back(123);

    auto w1 = example::widget::_make<implementation>();
    w1.inc();
    auto w2 = ++w1;
    w1.display();
    w2.display();
    w2.inc();
    w1.display();
    w2.display();

    auto b1 = example::button::_make<implementation>()--;
    if (b1._something())
    {
        std::cout << "yes" << b1._error() << std::endl;
    }
    else
    {
        std::cout << "no" << b1._error() << std::endl;
    }
    b1.push();

    w1 = b1;
    b1 = w1._static<example::button>();
    if (b1._valid())
    {
        std::cout << "yes" << b1._error() << std::endl;
    }
    else
    {
        std::cout << "no" << b1._error() << std::endl;
    }

    if (w1._static<example::number>()._valid())
    {
        std::cout << "yes" << b1._error() << std::endl;
    }
    else
    {
        std::cout << "no" << b1._error() << std::endl;
    }

    if (w1._dynamic<example::number>()._something())
    {
        std::cout << "yes" << b1._error() << std::endl;
    }
    else
    {
        std::cout << "no" << b1._error() << std::endl;
    }

    std::cout << w1._error("help!") << std::endl;
    std::cout << w1._error() << std::endl;

    auto n1 = example::number::_make<implementation>();
    n1.inc();
    n1.dec();

    auto wn1 = example::widget_number::_make<implementation>();
    wn1.inc();
    wn1.display();

    example::number wn2 = wn1;
    wn2.inc();

    example::widget wn3 = wn1;
    wn3.inc();
    wn3.display();

    wn1.display();
    increment(wn1);
    wn1.display();

    increment(wn2);

    auto ni1 = example::numeric<int>::_make<implementation>();
    ni1.inc();
    auto ni2 = ni1;
    ni2.x() = 2;
    std::cout << ni1.get() << ni1.x() << ni2.x() << std::endl;

    auto wt = example::widget::_make<implementation_template<int>>();
    auto bt = example::button::_make<implementation_template<int>>()--;
    auto nt = example::number::_make<implementation_template<int>>();
    auto wnt = example::widget_number::_make<implementation_template<int>>();
    auto nit = example::numeric<int>::_make<implementation_template<int>>();

    return 0;
}