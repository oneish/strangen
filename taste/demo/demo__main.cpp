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

private:
    bool _ripe = false;
    bool _peeled = false;
};

struct no_banana
{
    no_banana(std::string x)
    {
    }

    no_banana(no_banana const &) = delete;

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

private:
    bool _ripe = false;
    bool _peeled = false;
};

#include "demo__space.h"

namespace strange
{

template<>
struct reflection<banana>
{
    static inline auto name() -> std::string
    {
        return "banana";
    }
};

template<>
struct reflection<no_banana>
{
    static inline auto name() -> std::string
    {
        return "no_banana";
    }
};

}

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

    std::cout << "fruit_1._name(): " << fruit_1._name() << "\n";
    auto fruit_3 = demo::any::_construct<demo::fruit>("demo::fruit_<banana, true>");
    std::cout << "fruit_3._valid(): " << fruit_3._valid() << "\n";
    std::cout << "fruit_3._name(): " << fruit_3._name() << "\n";

    auto no_banana_1 = demo::fruit::_make<no_banana>(std::string{});
    std::cout << "no_banana_1._name(): " << no_banana_1._name() << "\n";

    return 0;
}
