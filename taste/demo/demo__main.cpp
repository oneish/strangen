#include "../../sauce/strange/strange.h"
#include "../../sauce/strange/implementation/baggage/strange__implementation__baggage.h"
#include "demo__space.h"

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

    auto pack(strange::bag & dest) const -> void
    {
        dest.from_object();
        dest.insert_object("ripe", dest.make_bool(_ripe));
        dest.insert_object("peeled", dest.make_bool(_peeled));
    }

    auto unpack(strange::bag const & src) -> void
    {
        src.get_object("ripe").as_bool(_ripe);
        src.get_object("peeled").as_bool(_peeled);
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

    auto pack(strange::bag & dest) const -> void
    {
        dest.from_object();
        dest.insert_object("ripe", dest.make_bool(_ripe));
        dest.insert_object("peeled", dest.make_bool(_peeled));
    }

    auto unpack(strange::bag const & src) -> void
    {
        src.get_object("ripe").as_bool(_ripe);
        src.get_object("peeled").as_bool(_peeled);
    }

private:
    bool _ripe = false;
    bool _peeled = false;
};

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

    auto pack(strange::bag & dest) const -> void
    {
        dest.from_object();
        {
            auto _array = dest.make_array();
            for (auto const & _item : *this)
            {
                _array.push_back_array(dest.make_any(_item._static<strange::any>()));
            }
            dest.insert_object("fruit", _array);
        }
        dest.insert_object("picked", dest.make_bool(_picked));
    }

    auto unpack(strange::bag const & src) -> void
    {
        {
            auto _array = src.get_object("fruit").to_array();
            auto _size = _array.size();
            clear();
            resize(_size);
            for (std::size_t _index = 0; _index < _size; ++_index)
            {
                (*this)[_index] = _array[_index].to_any()._static<demo::fruit>();
            }
        }
        src.get_object("picked").as_bool(_picked);
    }

private:
    bool _picked = false;
};

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

template<>
struct reflection<bunch_of_bananas>
{
    static inline auto name() -> std::string
    {
        return "bunch_of_bananas";
    }
};

}

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

    auto bag_1 = strange::baggage::_make();
    bag_1.from_any(bunch_2._static<strange::any>());
    std::cout << "bag_1.to_json(): " << bag_1.to_json() << "\n";
    auto bunch_3 = bag_1.to_any()._static<demo::bunch_of_fruit>();
    std::cout << "bunch_3.size(): " << bunch_3.size() << "\n";

    std::cout << "fruit_1._name(): " << fruit_1._name() << "\n";
    auto fruit_3 = demo::fruit::_manufacture("demo::fruit_<banana, true>");
    std::cout << "fruit_3._valid(): " << fruit_3._valid() << "\n";
    std::cout << "fruit_3._name(): " << fruit_3._name() << "\n";

    auto no_banana_1 = demo::fruit::_make<no_banana>(std::string{});
    std::cout << "no_banana_1._name(): " << no_banana_1._name() << "\n";

    return 0;
}
