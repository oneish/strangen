#include "example__type_erasure.h"
#include <iostream>

struct implementation
{
    int x = 0;
 
    inline void display() const
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
};

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
    b1.push();

    w1 = b1;

    auto n1 = example::number::_make<implementation>();
    n1.inc();
    n1.dec();

    return 0;
}