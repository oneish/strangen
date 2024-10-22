// demo space prototype
namespace demo
{
    // abstraction
    struct any
    {
    };

    // inheritance
    struct food : any
    {
        auto eat() -> void;
    };

    struct fruit : food
    {
        auto ripen() -> void;
        auto ripe() const -> bool;
        auto peel() -> void;
        auto peeled() const -> bool;
        std::string xxx {};
    };

    // template
    template<typename Item>
    struct bunch : any
    {
        auto push_back(Item const & item) -> void;
        auto push_back(Item && item) -> void;
        auto size() const -> std::size_t;
        auto operator[](std::size_t pos) const -> Item const &;
        auto operator[](std::size_t pos) -> Item &;
    };

    // multiple inheritance
    struct bunch_of_fruit : food, bunch<fruit>
    {
        using Item = fruit;
        auto pick() -> void;
        auto picked() const -> bool;
    };
}
