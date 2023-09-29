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

void increment(example::number & num)
{
    num.inc();
}

int main()
{

    auto w1 = example::widget::_make<implementation>();
    w1.inc();
    ++w1;
    auto w2 = w1;
    w1.display();
    w2.display();
    w2.inc();
    w1.display();
    w2.display();

    auto b1 = example::button::_make<implementation>();
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

    return 0;
}