// strange space prototype
namespace strange
{
    struct any
    {
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

        [[strange::result("*this")]]
        auto operator++() -> forward_const_iterator &;

        [[strange::result("*that")]]
        auto operator++(int i) -> forward_const_iterator;

        [[strange::customisation("return _thing == other.template _static<forward_const_iterator_<T, _Thing, _Copy> const>()._thing()")]]
        auto operator==(forward_const_iterator<T> const & other) const -> bool;

        [[strange::customisation("return !operator==(other)")]]
        auto operator!=(forward_const_iterator<T> const & other) const -> bool;
    };

    template<typename T>
    struct forward_iterator : forward_const_iterator<T>
    {
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using reference = value_type &;
        using pointer = value_type *;
        using iterator_category = std::forward_iterator_tag;

        auto operator*() -> T &;

        auto operator->() -> T *;

        [[strange::customisation("return _thing == other.template _static<forward_iterator_<T, _Thing, _Copy> const>()._thing()")]]
        auto operator==(forward_iterator<T> const & other) const -> bool;

        [[strange::customisation("return !operator==(other)")]]
        auto operator!=(forward_iterator<T> const & other) const -> bool;
    };

    template<typename T>
    struct bidirectional_const_iterator : forward_const_iterator<T>
    {
        using iterator_category = std::bidirectional_iterator_tag;

        [[strange::customisation("return _thing == other.template _static<bidirectional_const_iterator_<T, _Thing, _Copy> const>()._thing()")]]
        auto operator==(bidirectional_const_iterator<T> const & other) const -> bool;

        [[strange::customisation("return !operator==(other)")]]
        auto operator!=(bidirectional_const_iterator<T> const & other) const -> bool;

        [[strange::result("*this")]]
        auto operator--() -> bidirectional_const_iterator &;

        [[strange::result("*that")]]
        auto operator--(int i) -> bidirectional_const_iterator;
    };

    template<typename T>
    struct bidirectional_iterator : forward_iterator<T>, bidirectional_const_iterator<T>
    {
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using reference = value_type &;
        using pointer = value_type *;
        using iterator_category = std::bidirectional_iterator_tag;

        [[strange::customisation("return _thing == other.template _static<bidirectional_iterator_<T, _Thing, _Copy> const>()._thing()")]]
        auto operator==(bidirectional_iterator<T> const & other) const -> bool;

        [[strange::customisation("return !operator==(other)")]]
        auto operator!=(bidirectional_iterator<T> const & other) const -> bool;
    };

    template<typename T>
    struct random_access_const_iterator : bidirectional_const_iterator<T>
    {
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using reference = value_type &;
        using pointer = value_type *;
        using iterator_category = std::random_access_iterator_tag;

        [[strange::customisation("return _thing == other.template _static<random_access_const_iterator_<T, _Thing, _Copy> const>()._thing()")]]
        auto operator==(random_access_const_iterator<T> const & other) const -> bool;

        [[strange::customisation("return !operator==(other)")]]
        auto operator!=(random_access_const_iterator<T> const & other) const -> bool;

        [[strange::customisation("return _thing < other.template _static<random_access_const_iterator_<T, _Thing, _Copy> const>()._thing()")]]
        auto operator<(random_access_const_iterator<T> const & other) const -> bool;

        [[strange::customisation("return _thing > other.template _static<random_access_const_iterator_<T, _Thing, _Copy> const>()._thing()")]]
        auto operator>(random_access_const_iterator<T> const & other) const -> bool;

        [[strange::customisation("return _thing <= other.template _static<random_access_const_iterator_<T, _Thing, _Copy> const>()._thing()")]]
        auto operator<=(random_access_const_iterator<T> const & other) const -> bool;

        [[strange::customisation("return _thing >= other.template _static<random_access_const_iterator_<T, _Thing, _Copy> const>()._thing()")]]
        auto operator>=(random_access_const_iterator<T> const & other) const -> bool;

        [[strange::result("*this")]]
        auto operator+=(std::ptrdiff_t n) -> random_access_const_iterator &;

        [[strange::result("*this")]]
        auto operator-=(std::ptrdiff_t n) -> random_access_const_iterator &;

        [[strange::customisation("return random_access_const_iterator<T>::template _make<_Thing, _Copy>(_thing + n)")]]
        auto operator+(std::ptrdiff_t n) const -> random_access_const_iterator<T>;

        [[strange::customisation("return random_access_const_iterator<T>::template _make<_Thing, _Copy>(_thing - n)")]]
        auto operator-(std::ptrdiff_t n) const -> random_access_const_iterator<T>;

        [[strange::customisation("return _thing - other.template _static<random_access_const_iterator_<T, _Thing, _Copy> const>()._thing()")]]
        auto operator-(random_access_const_iterator<T> const & other) const -> std::ptrdiff_t;

        auto operator[](std::ptrdiff_t n) const -> T const &;
    };

    template<typename T>
    struct random_access_iterator : bidirectional_iterator<T>, random_access_const_iterator<T>
    {
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using reference = value_type &;
        using pointer = value_type *;
        using iterator_category = std::random_access_iterator_tag;

        [[strange::customisation("return _thing == other.template _static<random_access_iterator_<T, _Thing, _Copy> const>()._thing()")]]
        auto operator==(random_access_iterator<T> const & other) const -> bool;

        [[strange::customisation("return !operator==(other)")]]
        auto operator!=(random_access_iterator<T> const & other) const -> bool;

        [[strange::customisation("return _thing < other.template _static<random_access_iterator_<T, _Thing, _Copy> const>()._thing()")]]
        auto operator<(random_access_iterator<T> const & other) const -> bool;

        [[strange::customisation("return _thing > other.template _static<random_access_iterator_<T, _Thing, _Copy> const>()._thing()")]]
        auto operator>(random_access_iterator<T> const & other) const -> bool;

        [[strange::customisation("return _thing <= other.template _static<random_access_iterator_<T, _Thing, _Copy> const>()._thing()")]]
        auto operator<=(random_access_iterator<T> const & other) const -> bool;

        [[strange::customisation("return _thing >= other.template _static<random_access_iterator_<T, _Thing, _Copy> const>()._thing()")]]
        auto operator>=(random_access_iterator<T> const & other) const -> bool;

        [[strange::customisation("return random_access_iterator<T>::template _make<_Thing, _Copy>(_thing + n)")]]
        auto operator+(std::ptrdiff_t n) -> random_access_iterator<T>;

        [[strange::customisation("return random_access_iterator<T>::template _make<_Thing, _Copy>(_thing - n)")]]
        auto operator-(std::ptrdiff_t n) -> random_access_iterator<T>;

        [[strange::customisation("return _thing - other.template _static<random_access_iterator_<T, _Thing, _Copy> const>()._thing()")]]
        auto operator-(random_access_iterator<T> const & other) const -> std::ptrdiff_t;

        auto operator[](std::ptrdiff_t n) -> T &;
    };

    template<typename T>
    struct [[strange::thing("std::vector<T>")]]
    vector : any
    {
        using value_type = T;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;
        using reference = value_type &;
        using const_reference = value_type const &;
        using pointer = value_type *;
        using const_pointer = value_type const *;
        using iterator = typename strange::random_access_iterator<T>;
        using const_iterator = typename strange::random_access_const_iterator<T>;
        using reverse_iterator = typename std::reverse_iterator<iterator>;
        using const_reverse_iterator = typename std::reverse_iterator<const_iterator>;

        [[strange::result("*this")]]
        auto operator=(std::initializer_list<T> ilist) -> void;

        auto assign(size_t count, T const & value) -> void;

        auto assign(forward_const_iterator<T> first, forward_const_iterator<T> last) -> void;

        auto assign(std::initializer_list<T> ilist) -> void;

        auto at(size_t pos) -> T &;

        auto at(size_t pos) const -> T const &;

        auto operator[](size_t pos) -> T &;

        auto operator[](size_t pos) const -> T const &;

        auto front() -> T &;

        auto front() const -> T const &;

        auto back() -> T &;

        auto back() const -> T const &;

        auto data() -> T *;

        auto data() const -> T const *;

        [[strange::customisation("return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.begin())")]]
        auto begin() -> typename strange::random_access_iterator<T>;

        [[strange::customisation("return random_access_const_iterator<T>::template _make<decltype(_thing.begin())>(_thing.begin())")]]
        auto begin() const -> typename strange::random_access_const_iterator<T>;

        [[strange::customisation("return random_access_const_iterator<T>::template _make<decltype(_thing.cbegin())>(_thing.cbegin())")]]
        auto cbegin() const -> typename strange::random_access_const_iterator<T>;

        [[strange::customisation("return random_access_iterator<T>::template _make<decltype(_thing.end())>(_thing.end())")]]
        auto end() -> typename strange::random_access_iterator<T>;

        [[strange::customisation("return random_access_const_iterator<T>::template _make<decltype(_thing.end())>(_thing.end())")]]
        auto end() const -> typename strange::random_access_const_iterator<T>;

        [[strange::customisation("return random_access_const_iterator<T>::template _make<decltype(_thing.cend())>(_thing.cend())")]]
        auto cend() const -> typename strange::random_access_const_iterator<T>;

        [[strange::customisation("return typename std::reverse_iterator<strange::random_access_iterator<T>>{random_access_iterator<T>::template _make<decltype(_thing.end())>(_thing.end())}")]]
        auto rbegin() -> typename std::reverse_iterator<strange::random_access_iterator<T>>;

        [[strange::customisation("return typename std::reverse_iterator<strange::random_access_const_iterator<T>>{random_access_const_iterator<T>::template _make<decltype(_thing.end())>(_thing.end())}")]]
        auto rbegin() const -> typename std::reverse_iterator<strange::random_access_const_iterator<T>>;

        [[strange::customisation("return typename std::reverse_iterator<strange::random_access_const_iterator<T>>{random_access_const_iterator<T>::template _make<decltype(_thing.cend())>(_thing.cend())}")]]
        auto crbegin() const -> typename std::reverse_iterator<strange::random_access_const_iterator<T>>;

        [[strange::customisation("return typename std::reverse_iterator<strange::random_access_iterator<T>>{random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.begin())}")]]
        auto rend() -> typename std::reverse_iterator<strange::random_access_iterator<T>>;

        [[strange::customisation("return typename std::reverse_iterator<strange::random_access_const_iterator<T>>{random_access_const_iterator<T>::template _make<decltype(_thing.begin())>(_thing.begin())}")]]
        auto rend() const -> typename std::reverse_iterator<strange::random_access_const_iterator<T>>;

        [[strange::customisation("return typename std::reverse_iterator<strange::random_access_const_iterator<T>>{random_access_const_iterator<T>::template _make<decltype(_thing.cbegin())>(_thing.cbegin())}")]]
        auto crend() const -> typename std::reverse_iterator<strange::random_access_const_iterator<T>>;

        auto empty() const -> bool;

        auto size() const -> size_t;

        auto max_size() const -> size_t;

        auto reserve(size_t new_cap) -> void;

        auto capacity() const -> size_t;

        auto shrink_to_fit() -> void;

        auto clear() -> void;

        [[strange::modification("auto const index = pos - cbegin();"
        "    strange::_common::_mutate();"
        "    pos = cbegin() + index;"
        "    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->insert(pos, value);")]]
        [[strange::customisation("return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.insert(pos.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), value))")]]
        auto insert(typename strange::random_access_const_iterator<T> pos, T const & value) -> typename strange::random_access_iterator<T>;

        [[strange::modification("auto const index = pos - cbegin();"
        "    strange::_common::_mutate();"
        "    pos = cbegin() + index;"
        "    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->insert(pos, std::move(value));")]]
        [[strange::customisation("return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.insert(pos.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), std::move(value)))")]]
        auto insert(typename strange::random_access_const_iterator<T> pos, T && value) -> typename strange::random_access_iterator<T>;

        [[strange::modification("auto const index = pos - cbegin();"
        "    strange::_common::_mutate();"
        "    pos = cbegin() + index;"
        "    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->insert(pos, count, value);")]]
        [[strange::customisation("return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.insert(pos.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), count, value))")]]
        auto insert(typename strange::random_access_const_iterator<T> pos, size_t count, T const & value) -> typename strange::random_access_iterator<T>;

        [[strange::modification("auto const index = pos - cbegin();"
        "    strange::_common::_mutate();"
        "    pos = cbegin() + index;"
        "    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->insert(pos, first, last);")]]
        [[strange::customisation("return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.insert(pos.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), first, last))")]]
        auto insert(typename strange::random_access_const_iterator<T> pos, forward_const_iterator<T> first, forward_const_iterator<T> last) -> typename strange::random_access_iterator<T>;

        [[strange::modification("auto const index = pos - cbegin();"
        "    strange::_common::_mutate();"
        "    pos = cbegin() + index;"
        "    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->insert(pos, ilist);")]]
        [[strange::customisation("return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.insert(pos.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), ilist))")]]
        auto insert(typename strange::random_access_const_iterator<T> pos, std::initializer_list<T> ilist) -> typename strange::random_access_iterator<T>;

        [[strange::modification("auto const index = pos - cbegin();"
        "    strange::_common::_mutate();"
        "    pos = cbegin() + index;"
        "    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->erase(pos);")]]
        [[strange::customisation("return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.erase(pos.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing()))")]]
        auto erase(typename strange::random_access_const_iterator<T> pos) -> typename strange::random_access_iterator<T>;

        [[strange::modification("auto const first_index = first - cbegin();"
        "    auto const last_index = last - cbegin();"
        "    strange::_common::_mutate();"
        "    first = cbegin() + first_index;"
        "    last = cbegin() + last_index;"
        "    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->erase(first, last);")]]
        [[strange::customisation("return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.erase(first.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), last.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing()))")]]
        auto erase(typename strange::random_access_const_iterator<T> first, typename strange::random_access_const_iterator<T> last) -> typename strange::random_access_iterator<T>;

        auto push_back(T const & value) -> void;

        auto push_back(T && value) -> void;

        auto pop_back() -> void;

        auto resize(size_t count) -> void;

        auto resize(size_t count, T const & value) -> void;

        [[strange::customisation("_thing.swap(other.template _static<vector_<T, _Thing, _Copy>>()._thing())")]]
        auto swap(vector<T> & other) -> void;

        [[strange::customisation("return _thing == other.template _static<vector_<T, _Thing, _Copy> const>()._thing()")]]
        auto operator==(vector<T> const & other) const -> bool;

        [[strange::customisation("return _thing != other.template _static<vector_<T, _Thing, _Copy> const>()._thing()")]]
        auto operator!=(vector<T> const & other) const -> bool;

        [[strange::customisation("return _thing < other.template _static<vector_<T, _Thing, _Copy> const>()._thing()")]]
        auto operator<(vector<T> const & other) const -> bool;

        [[strange::customisation("return _thing > other.template _static<vector_<T, _Thing, _Copy> const>()._thing()")]]
        auto operator>(vector<T> const & other) const -> bool;

        [[strange::customisation("return _thing <= other.template _static<vector_<T, _Thing, _Copy> const>()._thing()")]]
        auto operator<=(vector<T> const & other) const -> bool;

        [[strange::customisation("return _thing >= other.template _static<vector_<T, _Thing, _Copy> const>()._thing()")]]
        auto operator>=(vector<T> const & other) const -> bool;
    };

    struct [[strange::thing("strange::definition::parameter")]]
    parameter : any
    {
        std::string type;
        std::string name;
        std::string argument;

        [[strange::customisation("return type() == other.type()"
        "    && name() == other.name()"
        "    && argument() == other.argument()")]]
        auto operator==(parameter const & other) const -> bool;

        [[strange::customisation("return !operator==(other)")]]
        auto operator!=(parameter const & other) const -> bool;

        [[strange::customisation("return type() < other.type() || (type() == other.type()"
        "    && (name() < other.name() || (name() == other.name()"
        "    && argument() < other.argument())))")]]
        auto operator<(parameter const & other) const -> bool;

        [[strange::customisation("return operator<(other) || operator==(other)")]]
        auto operator<=(parameter const & other) const -> bool;

        [[strange::customisation("return !operator<=(other)")]]
        auto operator>(parameter const & other) const -> bool;

        [[strange::customisation("return !operator<(other)")]]
        auto operator>=(parameter const & other) const -> bool;
    };

    struct [[strange::thing("strange::definition::operation")]]
    operation : any
    {
        std::string name;
        strange::vector<strange::parameter> parameters;
        bool constness;
        std::string result;
        bool data;
        std::string modification;
        std::string customisation;
        std::string implementation;

        [[strange::customisation("return name() == other.name()"
        "    && parameters() == other.parameters()"
        "    && constness() == other.constness()"
        "    && result() == other.result()"
        "    && data() == other.data()"
        "    && modification() == other.modification()"
        "    && customisation() == other.customisation()"
        "    && implementation() == other.implementation()")]]
        auto operator==(operation const & other) const -> bool;

        [[strange::customisation("return !operator==(other)")]]
        auto operator!=(operation const & other) const -> bool;

        [[strange::customisation("return name() < other.name() || (name() == other.name()"
        "    && (parameters() < other.parameters() || (parameters() == other.parameters()"
        "    && (constness() < other.constness() || (constness() == other.constness()"
        "    && (result() < other.result() || (result() == other.result()"
        "    && (data() < other.data() || (data() == other.data()"
        "    && (modification() < other.modification() || (modification() == other.modification()"
        "    && (customisation() < other.customisation() || (customisation() == other.customisation()"
        "    && implementation() < other.implementation())))))))))))))")]]
        auto operator<(operation const & other) const -> bool;

        [[strange::customisation("return operator<(other) || operator==(other)")]]
        auto operator<=(operation const & other) const -> bool;

        [[strange::customisation("return !operator<=(other)")]]
        auto operator>(operation const & other) const -> bool;

        [[strange::customisation("return !operator<(other)")]]
        auto operator>=(operation const & other) const -> bool;
    };

    struct [[strange::thing("strange::definition::abstraction")]]
    abstraction : any
    {
        strange::vector<strange::parameter> parameters;
        std::string name;
        strange::vector<std::string> parents;
        strange::vector<strange::parameter> types;
        strange::vector<strange::operation> operations;
        std::string thing;
        std::string implementation;

        [[strange::customisation("return parameters() == other.parameters()"
        "    && name() == other.name()"
        "    && parents() == other.parents()"
        "    && types() == other.types()"
        "    && operations() == other.operations()"
        "    && thing() == other.thing()"
        "    && implementation() == other.implementation()")]]
        auto operator==(abstraction const & other) const -> bool;

        [[strange::customisation("return !operator==(other)")]]
        auto operator!=(abstraction const & other) const -> bool;

        [[strange::customisation("return parameters() < other.parameters() || (parameters() == other.parameters()"
        "    && (name() < other.name() || (name() == other.name()"
        "    && (parents() < other.parents() || (parents() == other.parents()"
        "    && (types() < other.types() || (types() == other.types()"
        "    && (operations() < other.operations() || (operations() == other.operations()"
        "    && (thing() < other.thing() || (thing() == other.thing()"
        "    && implementation() < other.implementation())))))))))))")]]
        auto operator<(abstraction const & other) const -> bool;

        [[strange::customisation("return operator<(other) || operator==(other)")]]
        auto operator<=(abstraction const & other) const -> bool;

        [[strange::customisation("return !operator<=(other)")]]
        auto operator>(abstraction const & other) const -> bool;

        [[strange::customisation("return !operator<(other)")]]
        auto operator>=(abstraction const & other) const -> bool;
    };

    struct [[strange::thing("strange::definition::space")]]
    space : any
    {
        std::string name;
        strange::vector<strange::abstraction> abstractions;

        [[strange::customisation("return name() == other.name()"
        "    && abstractions() == other.abstractions()")]]
        auto operator==(space const & other) const -> bool;

        [[strange::customisation("return !operator==(other)")]]
        auto operator!=(space const & other) const -> bool;

        [[strange::customisation("return name() < other.name() || (name() == other.name()"
        "    && abstractions() < other.abstractions())")]]
        auto operator<(space const & other) const -> bool;

        [[strange::customisation("return operator<(other) || operator==(other)")]]
        auto operator<=(space const & other) const -> bool;

        [[strange::customisation("return !operator<=(other)")]]
        auto operator>(space const & other) const -> bool;

        [[strange::customisation("return !operator<(other)")]]
        auto operator>=(space const & other) const -> bool;
    };

    struct [[strange::thing("strange::implementation::token")]]
    token : any
    {
        std::string filename {};
        int64_t line {};
        int64_t position {};
        strange::comprehension::cls classification {};
        std::string text {};

        [[strange::customisation("return filename() == other.filename()"
        "    && line() == other.line()"
        "    && position() == other.position()"
        "    && classification() == other.classification()"
        "    && text() == other.text()")]]
        auto operator==(token const & other) const -> bool;

        [[strange::customisation("return !operator==(other)")]]
        auto operator!=(token const & other) const -> bool;

        [[strange::customisation("return filename() < other.filename() || (filename() == other.filename()"
        "    && (line() < other.line() || (line() == other.line()"
        "    && (position() < other.position() || (position() == other.position()"
        "    && (classification() < other.classification() || (classification() == other.classification()"
        "    && text() < other.text())))))))")]]
        auto operator<(token const & other) const -> bool;

        [[strange::customisation("return operator<(other) || operator==(other)")]]
        auto operator<=(token const & other) const -> bool;

        [[strange::customisation("return !operator<=(other)")]]
        auto operator>(token const & other) const -> bool;

        [[strange::customisation("return !operator<(other)")]]
        auto operator>=(token const & other) const -> bool;
    };
}
