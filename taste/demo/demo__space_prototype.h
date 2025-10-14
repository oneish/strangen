// demo space prototype
#include "../../sauce/strange/meta/strange__space_prototype.h"
namespace demo
{
    // abstraction
    struct food : strange::any
    {
        [[strange::closure("eat_closure_")]]
        auto eat(int xxx = 0) -> void;
    };

    // inheritance
    struct fruit : food, strange::stuff
    {
        auto ripen() -> void;
        [[strange::closure("ripe_closure_")]]
        auto ripe() const -> bool;
        auto peel() -> void;
        auto peeled() const -> bool;
    };

    // template
    template<typename Item = int, typename... Args>
    struct bunch : strange::any
    {
        [[strange::closure("push_back_closure_")]]
        auto push_back(Item const & item) -> void;
        auto push_back(Item && item) -> void;
        auto size() const -> std::size_t;
        [[strange::closure("operator_array_closure_")]]
        auto operator[](std::size_t pos) const -> Item const &;
        auto operator[](std::size_t pos) -> Item &;
    };

    template<typename... Args>
    struct variadic : strange::any
    {
        auto size() const -> std::size_t;
        auto emplace_back(Args && ...args) -> void;
    };

    // multiple inheritance
    struct bunch_of_fruit : food, bunch<fruit>, strange::stuff
    {
        using Item = fruit;
        auto pick() -> void;
        auto picked() const -> bool;
    };

    struct function
    {
        auto operator()() const -> void;
    };
}
