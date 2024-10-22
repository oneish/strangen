#include <iostream>
#include <string>

struct banana
{
    auto eat() -> void
    {
        std::cout << "banana.eat()\n";
    }

    auto ripen() -> void
    {
        std::cout << "banana.ripen()\n";
        _ripe = true;
    }

    auto ripe() const -> bool
    {
        std::cout << "banana.ripe():" << (_ripe ? "yes" : "no") << "\n";
        return _ripe;
    }

    auto peel() -> void
    {
        std::cout << "banana.peel()\n";
        _peeled = true;
    }

    auto peeled() const -> bool
    {
        std::cout << "banana.peeled():" << (_peeled ? "yes" : "no") << "\n";
        return _peeled;
    }

    auto xxx() const -> std::string const & { return xxx_; }
    auto xxx() -> std::string & { return xxx_; }

private:
    bool _ripe = false;
    bool _peeled = false;
    std::string xxx_;
};

#include "demo__space.h"

struct bunch_of_bananas : std::vector<demo::fruit>
{
    auto eat() -> void
    {
        std::cout << "bunch_of_bananas.eat()\n";
    }

    auto pick() -> void
    {
        std::cout << "bunch_of_bananas.pick()\n";
        _picked = true;
    }

    auto picked() const -> bool
    {
        std::cout << "bunch_of_bananas.picked():" << (_picked ? "yes" : "no") << "\n";
        return _picked;
    }

private:
    bool _picked = false;
};

int main()
{
    std::cout << "demo\n";

    auto fruit_1 = demo::fruit::_make<banana>();
    auto fruit_2 = fruit_1;
    fruit_1.ripe();
    fruit_1.peeled();
    fruit_1.peel();
    fruit_1.peeled();
    fruit_1.eat();

    auto bunch_1 = demo::bunch<demo::fruit>::_make<std::vector<demo::fruit>>();
    bunch_1.push_back(fruit_1);
    std::cout << "bunch_1.size(): " << bunch_1.size() << "\n";

    auto bunch_2 = demo::bunch_of_fruit::_make<bunch_of_bananas>();
    bunch_2.push_back(fruit_1);
    bunch_2.push_back(fruit_2);
    std::cout << "bunch_2.size(): " << bunch_2.size() << "\n";

    return 0;
}
