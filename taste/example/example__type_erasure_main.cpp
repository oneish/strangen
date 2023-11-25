#include "../../sauce/strange/strange.h"
//#include "example__type_erasure.h"
#include "example__space_transformation_3.h"

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

int main()
{
    std::cout << strange::reflection<std::vector<int>>::name() << std::endl;
    std::cout << strange::reflection<strange::vector_a_<std::vector<int>, int>>::name() << std::endl;
    std::cout << strange::vector_a_<std::vector<int>, int>::_name_ << std::endl;

    auto v1 = strange::vector_a_<std::vector<int>, int>::_null_();
    auto v2 = strange::vector_a_<std::vector<int>, int>::_make_();
    auto v3 = strange::vector_a_<std::vector<int>, int>::_make(1,2,3);
    auto v4 = strange::vector_a_<std::vector<int>, int>::_incognito_();
    auto v5 = strange::vector_a_<std::vector<int>, int>::_incognito(1,2,3);
    auto v6 = strange::vector_a_<std::vector<int>, int>{};
    auto v7 = strange::vector_a_<std::vector<int>, int>{1,2,3};
    v2._thing().push_back(123);
    v4.push_back(123);
    v6._thing().push_back(123);
    std::cout << v1._name_ << std::endl;

    auto w1 = example::widget_<implementation>::_make();
    w1.inc();
    auto w2 = ++w1;
    w1.display();
    w2.display();
    w2.inc();
    w1.display();
    w2.display();

    auto b1 = example::button_<implementation>::_make()--;
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

    auto n1 = example::number_<implementation>::_make();
    n1.inc();
    n1.dec();

    auto wn1 = example::widget_number_<implementation>::_make();
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

    auto ni1 = example::numeric_<implementation, int>::_make();
    ni1.inc();
    auto ni2 = ni1;
    ni2.x() = 2;
    std::cout << ni1.get() << ni1.x() << ni2.x() << std::endl;

    auto wt = example::widget_<implementation_template<int>>::_make();
    auto bt = example::button_<implementation_template<int>>::_make()--;
    auto nt = example::number_<implementation_template<int>>::_make();
    auto wnt = example::widget_number_<implementation_template<int>>::_make();
    auto nit = example::numeric_<implementation_template<int>, int>::_make();

    return 0;
}