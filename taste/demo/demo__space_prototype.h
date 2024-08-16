// demo space prototype
namespace demo
{
    struct any
    {
    };

    struct food : any
    {
        auto eat() -> void;
    };

    struct fruit : food
    {
        auto ripe() const -> bool;
        auto peel() -> void;
        auto peeled() const -> bool;
    };

    template<typename Item>
    struct bunch : any
    {
        auto size() const -> std::size_t;
    };

    struct bunch_of_fruit : food, bunch<fruit>
    {
    };
}
