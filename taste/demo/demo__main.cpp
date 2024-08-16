#include <iostream>
#include <string>

struct banana
{
    auto eat() -> void
    {
        std::cout << "banana.eat()\n";
    }

    auto ripe() const -> bool
    {
        std::cout << "banana.ripe()\n";
        return _ripe;
    }

    auto peel() -> void
    {
        std::cout << "banana.peel()\n";
        _peeled = true;
    }

    auto peeled() const -> bool
    {
        std::cout << "banana.peeled()\n";
        return _peeled;
    }

private:
    bool _ripe = false;
    bool _peeled = false;
};

#include "demo__space.h"

int main()
{
    std::cout << "demo\n";

    auto fruit_1 = demo::fruit::_make<banana>();
    std::cout << "fruit_1.ripe(): " << fruit_1.ripe() << "\n";

    auto bunch_1 = demo::bunch<demo::fruit>::_make<std::vector<demo::fruit>>();
    std::cout << "bunch_1.size(): " << bunch_1.size() << "\n";

    return 0;
}
