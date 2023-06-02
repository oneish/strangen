#include "strange__type_erasure.h"
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
};

int main()
{
    strange::widget w1 = strange::widget::_make<implementation>();
    w1.modify();
    auto w2 = w1;
    w1.display();
    w2.display();
    w2.modify();
    w1.display();
    w2.display();
    return 0;
}