namespace strange
{
    struct any
    {
    };

    struct [[strange::thing("strange::definition::parameter")]]
    parameter
    {
        std::string type{};
        std::string name{};
        std::string argument{};
    };

    template<typename T>
    struct forward_const_iterator : any
    {
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using reference = value_type &;
        using pointer = value_type *;
        using iterator_category = std::forward_iterator_tag;
        auto operator*() const -> T const &;
        auto operator->() const -> T const *;
        auto operator++() -> forward_const_iterator & [[strange::result("*this")]];
        auto operator++(int i) -> forward_const_iterator [[strange::result("*that")]];
        auto operator==(forward_const_iterator<T> const & other) const -> bool [[strange::customisation("return _thing == other.template _static<forward_const_iterator_<T, _Thing, _Copy>>()._thing()")]];
        auto operator!=(forward_const_iterator<T> const & other) const -> bool [[strange::customisation("return !operator==(other)")]];
    };
}
