#include "example__type_erasure.h"
#include "example__space_definition.h"
#include <iostream>

struct implementation
{
    int x = 0;
 
    inline void display(example::button b) const
    {
        std::cout << "display: " << x << std::endl;
    }

    inline void modify()
    {
        std::cout << "modify: " << x << " -> " << (x + 1) << std::endl;
        ++x;
    }

    inline void push()
    {
        std::cout << "push: " << x << " -> " << (x - 1) << std::endl;
        --x;
    }

    inline void inc()
    {
        ++x;
    }

    inline void dec()
    {
        --x;
    }

    inline int get() const
    {
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
    w1.modify();
    auto w2 = w1;
    w1.display();
    w2.display();
    w2.modify();
    w1.display();
    w2.display();

    auto b1 = example::button::_make<implementation>();
    if (b1._something())
    {
        std::cout << "yes" << std::endl;
    }
    else
    {
        std::cout << "no" << std::endl;
    }
    if (b1._dynamic())
    {
        std::cout << "yes" << std::endl;
    }
    else
    {
        std::cout << "no" << std::endl;
    }
    if (static_cast<example::number>(b1)._something())
    {
        std::cout << "yes" << std::endl;
    }
    else
    {
        std::cout << "no" << std::endl;
    }
    if (static_cast<example::number>(b1)._dynamic())
    {
        std::cout << "yes" << std::endl;
    }
    else
    {
        std::cout << "no" << std::endl;
    }
    b1.push();

    w1 = b1;

    auto n1 = example::number::_make<implementation>();
    n1.inc();
    n1.dec();

    auto wn1 = example::widget_number::_make<implementation>();
    wn1.inc();
    wn1.display();

    example::number wn2 = wn1;
    wn2.inc();

    example::widget wn3 = wn2;
    wn3.modify();
    wn3.display();

    wn1.display();
    increment(wn1);
    wn1.display();

    increment(wn2);
    
    wn3 = wn2;
    wn3.display();
    increment(wn2);
    wn3 = wn2;
    wn3.display();

    auto ni1 = example::numeric<int>::_make<implementation>();
    ni1.inc();
    std::cout << ni1.get() << std::endl;

    example::definition();

    return 0;
}