#include "../../sauce/strange/strange.h"
//#include "example__type_erasure.h"
#include "example__space_transformation_3.h"

#include <iostream>
#include <algorithm>

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

template<>
struct reflection<implementation>
{
    inline static auto name() -> std::string
    {
        return "implementation";
    }
};

template<typename Datatype>
struct reflection<implementation_template<Datatype>>
{
    inline static auto name() -> std::string
    {
        return "implementation_template<" + reflection<Datatype>::name() + ">";
    }
};

}

int main()
{
    auto i1 = strange::forward_iterator<int>{};
    auto i2 = strange::forward_iterator<int>{};
    i1._static<strange::forward_iterator<int>>();
    std::swap(i1, i2);
    for (auto op : strange::reflection<std::vector<int>>::operations())
    {
        std::cout << op << std::endl;
    }
    std::cout << strange::reflection<std::vector<int>>::name() << std::endl;
    std::cout << strange::reflection<strange::vector_<int>>::name() << std::endl;
    std::cout << strange::vector_<int>::_name_ << std::endl;
    std::cout << strange::vector_<int>::_cat_ << std::endl;

    auto v1 = strange::vector_<int>::_make_();
    auto v2 = strange::vector<int>::_make(1,2,3);
    auto v3 = strange::vector_<double>::_make_(1.0,2.0,3.0);
    v1._thing().push_back(123);
    v2.push_back(123);
    v3._thing().push_back(123.0);
    std::cout << v1._name_ << std::endl;
    std::cout << v1._cat_ << std::endl;
    std::cout << v2._name() << std::endl;
    std::cout << v2._cat() << std::endl;
    std::cout << v3._name() << std::endl;
    std::cout << v3._cat() << std::endl;
    v3._cats();

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

    auto ni1 = example::numeric<>::_make<implementation>();
    ni1.inc();
    auto ni2 = ni1;
    ni2.x() = 2;
    std::cout << ni1.get() << ni1.x() << ni2.x() << std::endl;

    auto wt = example::widget::_make<implementation_template<int>>();
    auto bt = example::button::_make<implementation_template<int>>()--;
    auto nt = example::number::_make<implementation_template<int>>();
    auto wnt = example::widget_number::_make<implementation_template<int>>();
    auto nit = example::numeric<>::_make<implementation_template<int>>();

    return 0;
}