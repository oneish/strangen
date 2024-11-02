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

        auto assign(std::size_t count, T const & value) -> void;

        auto assign(forward_const_iterator<T> first, forward_const_iterator<T> last) -> void;

        auto assign(std::initializer_list<T> ilist) -> void;

        auto at(std::size_t pos) -> T &;

        auto at(std::size_t pos) const -> T const &;

        auto operator[](std::size_t pos) -> T &;

        auto operator[](std::size_t pos) const -> T const &;

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

        auto size() const -> std::size_t;

        auto max_size() const -> std::size_t;

        auto reserve(std::size_t new_cap) -> void;

        auto capacity() const -> std::size_t;

        auto shrink_to_fit() -> void;

        auto clear() -> void;

        [[strange::modification("auto const index = pos - cbegin();"
        "    strange::_common::_mutate(); // could invalidate iterators"
        "    pos = cbegin() + index;"
        "    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->insert(pos, value);")]]
        [[strange::customisation("return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.insert(pos.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), value))")]]
        auto insert(typename strange::random_access_const_iterator<T> pos, T const & value) -> typename strange::random_access_iterator<T>;

        [[strange::modification("auto const index = pos - cbegin();"
        "    strange::_common::_mutate(); // could invalidate iterators"
        "    pos = cbegin() + index;"
        "    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->insert(pos, std::move(value));")]]
        [[strange::customisation("return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.insert(pos.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), std::move(value)))")]]
        auto insert(typename strange::random_access_const_iterator<T> pos, T && value) -> typename strange::random_access_iterator<T>;

        [[strange::modification("auto const index = pos - cbegin();"
        "    strange::_common::_mutate(); // could invalidate iterators"
        "    pos = cbegin() + index;"
        "    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->insert(pos, count, value);")]]
        [[strange::customisation("return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.insert(pos.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), count, value))")]]
        auto insert(typename strange::random_access_const_iterator<T> pos, std::size_t count, T const & value) -> typename strange::random_access_iterator<T>;

        [[strange::modification("auto const index = pos - cbegin();"
        "    strange::_common::_mutate(); // could invalidate iterators"
        "    pos = cbegin() + index;"
        "    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->insert(pos, first, last);")]]
        [[strange::customisation("return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.insert(pos.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), first, last))")]]
        auto insert(typename strange::random_access_const_iterator<T> pos, forward_const_iterator<T> first, forward_const_iterator<T> last) -> typename strange::random_access_iterator<T>;

        [[strange::modification("auto const index = pos - cbegin();"
        "    strange::_common::_mutate(); // could invalidate iterators"
        "    pos = cbegin() + index;"
        "    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->insert(pos, ilist);")]]
        [[strange::customisation("return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.insert(pos.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), ilist))")]]
        auto insert(typename strange::random_access_const_iterator<T> pos, std::initializer_list<T> ilist) -> typename strange::random_access_iterator<T>;

        [[strange::modification("auto const index = pos - cbegin();"
        "    strange::_common::_mutate(); // could invalidate iterators"
        "    pos = cbegin() + index;"
        "    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->erase(pos);")]]
        [[strange::customisation("return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.erase(pos.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing()))")]]
        auto erase(typename strange::random_access_const_iterator<T> pos) -> typename strange::random_access_iterator<T>;

        [[strange::modification("auto const first_index = first - cbegin();"
        "    auto const last_index = last - cbegin();"
        "    strange::_common::_mutate(); // could invalidate iterators"
        "    first = cbegin() + first_index;"
        "    last = cbegin() + last_index;"
        "    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->erase(first, last);")]]
        [[strange::customisation("return random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.erase(first.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), last.template _static<random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing()))")]]
        auto erase(typename strange::random_access_const_iterator<T> first, typename strange::random_access_const_iterator<T> last) -> typename strange::random_access_iterator<T>;

        auto push_back(T const & value) -> void;

        auto push_back(T && value) -> void;

        auto pop_back() -> void;

        auto resize(std::size_t count) -> void;

        auto resize(std::size_t count, T const & value) -> void;

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

    struct [[strange::thing("strange::implementation::parameter")]]
    parameter : any
    {
        std::string type {};
        std::string name {};
        std::string argument {};

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

    struct [[strange::thing("strange::implementation::operation")]]
    operation : any
    {
        std::string name {};
        strange::vector<strange::parameter> parameters {strange::vector<strange::parameter>::_make()};
        bool constness {false};
        std::string result {};
        bool data {false};
        std::string modification {};
        std::string customisation {};
        std::string implementation {};

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

    struct [[strange::thing("strange::implementation::abstraction")]]
    abstraction : any
    {
        strange::vector<strange::parameter> parameters {strange::vector<strange::parameter>::_make()};
        std::string name {};
        strange::vector<std::string> parents {strange::vector<std::string>::_make()};
        strange::vector<strange::parameter> types {strange::vector<strange::parameter>::_make()};
        strange::vector<strange::operation> operations {strange::vector<strange::operation>::_make()};
        std::string thing {};
        std::string implementation {};

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

    struct [[strange::thing("strange::implementation::space")]]
    space : any
    {
        std::string name {};
        strange::vector<strange::abstraction> abstractions {strange::vector<strange::abstraction>::_make()};

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
/*
    struct stuff : any
    {
        auto pack(bag & dest) const -> void;
        auto pack(bag & dest, std::unordered_map<void const *, std::size_t> & unique) const -> void;
        auto unpack(bag const & src) -> void;
        auto unpack(bag const & src, std::vector<any> & unique) -> void;
    };

    struct bag : stuff
    {
        auto is_null() const -> bool;
        auto from_null() -> void;
        auto make_null() const -> bag;

        auto is_bool() const -> bool;
        auto as_bool(bool & dest) const -> void;
        auto to_bool() const -> bool;
        auto from_bool() -> void;
        auto from_bool(bool src) -> void;
        auto make_bool() const -> bag;
        auto make_bool(bool src) const -> bag;

        auto is_int64() const -> bool;
        auto as_int64(int64_t & dest) const -> void;
        auto to_int64() const -> int64_t;
        auto from_int64() -> void;
        auto from_int64(int64_t src) -> void;
        auto make_int64() const -> bag;
        auto make_int64(int64_t src) const -> bag;

        auto is_double() const -> bool;
        auto as_double(double & dest) const -> void;
        auto to_double() const -> double;
        auto from_double() -> void;
        auto from_double(double src) -> void;
        auto make_double() const -> bag;
        auto make_double(double src) const -> bag;

        auto is_string() const -> bool;
        auto as_string(std::string & dest) const -> void;
        auto to_string() const -> std::string;
        auto from_string() -> void;
        auto from_string(std::string const & src) -> void;
        auto make_string() const -> bag;
        auto make_string(std::string const & src) const -> bag;

        auto is_array() const -> bool;
        auto as_array(std::vector<bag> & dest) const -> void;
        auto to_array() const -> std::vector<bag>;
        auto from_array() -> void;
        auto from_array(std::vector<bag> const & src) -> void;
        auto make_array() const -> bag;
        auto make_array(std::vector<bag> const & src) const -> bag;
        auto at_array(std::size_t index) const -> bag const &;
        auto at_array(std::size_t index) -> bag &;
        auto front_array() const -> bag const &;
        auto front_array() -> bag &;
        auto back_array() const -> bag const &;
        auto back_array() -> bag &;
        auto begin_array() -> bidirectional_iterator<bag>;
        auto begin_array() const -> bidirectional_const_iterator<bag>;
        auto cbegin_array() const -> bidirectional_const_iterator<bag>;
        auto end_array() -> bidirectional_iterator<bag>;
        auto end_array() const -> bidirectional_const_iterator<bag>;
        auto cend_array() const -> bidirectional_const_iterator<bag>;
        auto rbegin_array() -> bidirectional_iterator<bag>;
        auto rbegin_array() const -> bidirectional_const_iterator<bag>;
        auto crbegin_array() const -> bidirectional_const_iterator<bag>;
        auto rend_array() -> bidirectional_iterator<bag>;
        auto rend_array() const -> bidirectional_const_iterator<bag>;
        auto crend_array() const -> bidirectional_const_iterator<bag>;
        auto empty_array() const -> bool;
        auto size_array() const -> std::size_t;
        auto reserve_array(std::size_t new_cap) -> void;
        auto capacity_array() const -> std::size_t;
        auto clear_array() -> void;

        [[strange::modification("auto const index = pos - cbegin_array();"
        "    strange::_common::_mutate(); // could invalidate iterators"
        "    pos = cbegin_array() + index;"
        "    return std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->insert_array(pos, value);")]]
        [[strange::customisation("return bidirectional_iterator<bag>::template _make<decltype(_thing.begin_array())>(_thing.insert_array(pos.template _static<bidirectional_const_iterator_<bag, decltype(_thing.cbegin_array())>>()._thing(), value))")]]
        auto insert_array(typename strange::bidirectional_const_iterator<bag> pos, bag const & value) -> typename strange::bidirectional_iterator<bag>;

        [[strange::modification("auto const index = pos - cbegin_array();"
        "    strange::_common::_mutate(); // could invalidate iterators"
        "    pos = cbegin_array() + index;"
        "    return std::dynamic_pointer_cast<typename bag::_derived>(strange::_common::_shared)->erase_array(pos);")]]
        [[strange::customisation("return bidirectional_iterator<bag>::template _make<decltype(_thing.begin_array())>(_thing.erase_array(pos.template _static<bidirectional_const_iterator_<bag, decltype(_thing.cbegin_array())>>()._thing()))")]]
        auto erase_array(typename strange::bidirectional_const_iterator<bag> pos) -> typename strange::bidirectional_iterator<bag>;

        auto push_front_array(bag const & value) -> void;
        auto push_back_array(bag const & value) -> void;
        auto pop_front_array() -> void;
        auto pop_back_array() -> void;
        auto resize_array(std::size_t count) -> void;

        [[strange::customisation("_thing.swap_array(other.template _static<bag_<_Thing, _Copy>>()._thing())")]]
        auto swap_array(bag & other) -> void;

        auto is_object() const -> bool;
        auto as_object(std::unordered_map<std::string, bag> & dest) const -> void;
        auto to_object() const -> std::unordered_map<std::string, bag>;
        auto from_object() -> void;
        auto from_object(std::unordered_map<std::string, bag> const & src) -> void;
        auto make_object() const -> bag;
        auto make_object(std::unordered_map<std::string, bag> const & src) const -> bag;
        auto at_object(std::string const & key) const -> bag;

        // add_field, remove_field, insert, set, erase, clear,
        // inject, project, operator[], get, find, find_key,
        // keys, has_key, size, begin, end, key_begin, key_end,
        // empty, cbegin, cend, rbegin, rend, kvbegin, kvend

        auto is_any() const -> bool;
        auto as_any(any & dest) const -> void;
        auto as_any(any & dest, std::vector<any> & unique) const -> void;
        auto to_any() const -> any;
        auto to_any(std::vector<any> & unique) const -> any;
        auto from_any() -> void;
        auto from_any(any const & src) -> void;
        auto from_any(any const & src, std::unordered_map<void const *, std::size_t> & unique) -> void;
        auto make_any() const -> bag;
        auto make_any(any const & src) const -> bag;
        auto make_any(any const & src, std::unordered_map<void const *, std::size_t> & unique) const -> bag;
    };

    struct package : stuff
    {
        // seal, sealed, unseal, from_json, to_json,
        // from_binary, to_binary, from_yaml, to_yaml
    };

    struct baggage : bag, package
    {
    };

    template<typename R, typename ... Args>
    struct [[strange::thing("std::function<R(Args ...)>")]]
    const_function<R(Args ...)> : any
    {
        auto operator()(Args && ... args) const -> R;
    };

    template<typename R, typename ... Args>
    struct function<R(Args ...)> : any
    {
        auto operator()(Args && ... args) -> R;
    };
*/
}
