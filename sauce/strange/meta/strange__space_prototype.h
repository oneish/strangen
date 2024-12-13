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

        auto assign(typename strange::forward_const_iterator<T> first, typename strange::forward_const_iterator<T> last) -> void;

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

        [[strange::customisation("return strange::random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.begin())")]]
        auto begin() -> typename strange::random_access_iterator<T>;

        [[strange::customisation("return strange::random_access_const_iterator<T>::template _make<decltype(_thing.begin())>(_thing.begin())")]]
        auto begin() const -> typename strange::random_access_const_iterator<T>;

        [[strange::customisation("return strange::random_access_const_iterator<T>::template _make<decltype(_thing.cbegin())>(_thing.cbegin())")]]
        auto cbegin() const -> typename strange::random_access_const_iterator<T>;

        [[strange::customisation("return strange::random_access_iterator<T>::template _make<decltype(_thing.end())>(_thing.end())")]]
        auto end() -> typename strange::random_access_iterator<T>;

        [[strange::customisation("return strange::random_access_const_iterator<T>::template _make<decltype(_thing.end())>(_thing.end())")]]
        auto end() const -> typename strange::random_access_const_iterator<T>;

        [[strange::customisation("return strange::random_access_const_iterator<T>::template _make<decltype(_thing.cend())>(_thing.cend())")]]
        auto cend() const -> typename strange::random_access_const_iterator<T>;

        [[strange::customisation("return typename std::reverse_iterator<strange::random_access_iterator<T>>{strange::random_access_iterator<T>::template _make<decltype(_thing.end())>(_thing.end())}")]]
        auto rbegin() -> typename std::reverse_iterator<strange::random_access_iterator<T>>;

        [[strange::customisation("return typename std::reverse_iterator<strange::random_access_const_iterator<T>>{strange::random_access_const_iterator<T>::template _make<decltype(_thing.end())>(_thing.end())}")]]
        auto rbegin() const -> typename std::reverse_iterator<strange::random_access_const_iterator<T>>;

        [[strange::customisation("return typename std::reverse_iterator<strange::random_access_const_iterator<T>>{strange::random_access_const_iterator<T>::template _make<decltype(_thing.cend())>(_thing.cend())}")]]
        auto crbegin() const -> typename std::reverse_iterator<strange::random_access_const_iterator<T>>;

        [[strange::customisation("return typename std::reverse_iterator<strange::random_access_iterator<T>>{strange::random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.begin())}")]]
        auto rend() -> typename std::reverse_iterator<strange::random_access_iterator<T>>;

        [[strange::customisation("return typename std::reverse_iterator<strange::random_access_const_iterator<T>>{strange::random_access_const_iterator<T>::template _make<decltype(_thing.begin())>(_thing.begin())}")]]
        auto rend() const -> typename std::reverse_iterator<strange::random_access_const_iterator<T>>;

        [[strange::customisation("return typename std::reverse_iterator<strange::random_access_const_iterator<T>>{strange::random_access_const_iterator<T>::template _make<decltype(_thing.cbegin())>(_thing.cbegin())}")]]
        auto crend() const -> typename std::reverse_iterator<strange::random_access_const_iterator<T>>;

        auto empty() const -> bool;

        auto size() const -> std::size_t;

        auto max_size() const -> std::size_t;

        auto reserve(std::size_t new_cap) -> void;

        auto capacity() const -> std::size_t;

        auto shrink_to_fit() -> void;

        auto clear() -> void;

        [[strange::modification("auto const index = pos - cbegin();"
        "    if (strange::_common::_mutate())"
        "    {"
        "        pos = cbegin() + index;"
        "    }"
        "    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->insert(pos, value);")]]
        [[strange::customisation("return strange::random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.insert(pos.template _static<strange::random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), value))")]]
        auto insert(typename strange::random_access_const_iterator<T> pos, T const & value) -> typename strange::random_access_iterator<T>;

        [[strange::modification("auto const index = pos - cbegin();"
        "    if (strange::_common::_mutate())"
        "    {"
        "        pos = cbegin() + index;"
        "    }"
        "    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->insert(pos, std::move(value));")]]
        [[strange::customisation("return strange::random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.insert(pos.template _static<strange::random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), std::move(value)))")]]
        auto insert(typename strange::random_access_const_iterator<T> pos, T && value) -> typename strange::random_access_iterator<T>;

        [[strange::modification("auto const index = pos - cbegin();"
        "    if (strange::_common::_mutate())"
        "    {"
        "        pos = cbegin() + index;"
        "    }"
        "    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->insert(pos, count, value);")]]
        [[strange::customisation("return strange::random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.insert(pos.template _static<strange::random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), count, value))")]]
        auto insert(typename strange::random_access_const_iterator<T> pos, std::size_t count, T const & value) -> typename strange::random_access_iterator<T>;

        [[strange::modification("auto const index = pos - cbegin();"
        "    if (strange::_common::_mutate())"
        "    {"
        "        pos = cbegin() + index;"
        "    }"
        "    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->insert(pos, first, last);")]]
        [[strange::customisation("return strange::random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.insert(pos.template _static<strange::random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), first, last))")]]
        auto insert(typename strange::random_access_const_iterator<T> pos, forward_const_iterator<T> first, forward_const_iterator<T> last) -> typename strange::random_access_iterator<T>;

        [[strange::modification("auto const index = pos - cbegin();"
        "    if (strange::_common::_mutate())"
        "    {"
        "        pos = cbegin() + index;"
        "    }"
        "    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->insert(pos, ilist);")]]
        [[strange::customisation("return strange::random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.insert(pos.template _static<strange::random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), ilist))")]]
        auto insert(typename strange::random_access_const_iterator<T> pos, std::initializer_list<T> ilist) -> typename strange::random_access_iterator<T>;

        [[strange::modification("auto const index = pos - cbegin();"
        "    if (strange::_common::_mutate())"
        "    {"
        "        pos = cbegin() + index;"
        "    }"
        "    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->erase(pos);")]]
        [[strange::customisation("return strange::random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.erase(pos.template _static<strange::random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing()))")]]
        auto erase(typename strange::random_access_const_iterator<T> pos) -> typename strange::random_access_iterator<T>;

        [[strange::modification("auto const first_index = first - cbegin();"
        "    auto const last_index = last - cbegin();"
        "    if (strange::_common::_mutate())"
        "    {"
        "        first = cbegin() + first_index;"
        "        last = cbegin() + last_index;"
        "    }"
        "    return std::dynamic_pointer_cast<typename vector<T>::_derived>(strange::_common::_shared)->erase(first, last);")]]
        [[strange::customisation("return strange::random_access_iterator<T>::template _make<decltype(_thing.begin())>(_thing.erase(first.template _static<strange::random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing(), last.template _static<strange::random_access_const_iterator_<T, decltype(_thing.cbegin())>>()._thing()))")]]
        auto erase(typename strange::random_access_const_iterator<T> first, typename strange::random_access_const_iterator<T> last) -> typename strange::random_access_iterator<T>;

        auto push_back(T const & value) -> void;

        auto push_back(T && value) -> void;

        auto pop_back() -> void;

        auto resize(std::size_t count) -> void;

        auto resize(std::size_t count, T const & value) -> void;

        [[strange::customisation("_thing.swap(other.template _static<strange::vector_<T, _Thing, _Copy>>()._thing())")]]
        auto swap(vector<T> & other) -> void;

        [[strange::customisation("return _thing == other.template _static<strange::vector_<T, _Thing, _Copy> const>()._thing()")]]
        auto operator==(vector<T> const & other) const -> bool;

        [[strange::customisation("return _thing != other.template _static<strange::vector_<T, _Thing, _Copy> const>()._thing()")]]
        auto operator!=(vector<T> const & other) const -> bool;

        [[strange::customisation("return _thing < other.template _static<strange::vector_<T, _Thing, _Copy> const>()._thing()")]]
        auto operator<(vector<T> const & other) const -> bool;

        [[strange::customisation("return _thing > other.template _static<strange::vector_<T, _Thing, _Copy> const>()._thing()")]]
        auto operator>(vector<T> const & other) const -> bool;

        [[strange::customisation("return _thing <= other.template _static<strange::vector_<T, _Thing, _Copy> const>()._thing()")]]
        auto operator<=(vector<T> const & other) const -> bool;

        [[strange::customisation("return _thing >= other.template _static<strange::vector_<T, _Thing, _Copy> const>()._thing()")]]
        auto operator>=(vector<T> const & other) const -> bool;
    };

    struct stuff : any
    {
        auto pack(strange::bag & dest) const -> void;
        auto unpack(strange::bag const & src) -> void;
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

        auto is_uint64() const -> bool;
        auto as_uint64(uint64_t & dest) const -> void;
        auto to_uint64() const -> uint64_t;
        auto from_uint64() -> void;
        auto from_uint64(uint64_t src) -> void;
        auto make_uint64() const -> bag;
        auto make_uint64(uint64_t src) const -> bag;

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
        auto get_array(std::size_t index) const -> bag;
        auto set_array(std::size_t index, bag const & value) -> void;
        auto front_array() const -> bag;
        auto back_array() const -> bag;
        auto empty_array() const -> bool;
        auto size_array() const -> std::size_t;
        auto reserve_array(std::size_t new_cap) -> void;
        auto capacity_array() const -> std::size_t;
        auto clear_array() -> void;
        auto insert_array(std::size_t pos, bag const & value) -> void;
        auto erase_array(std::size_t pos) -> void;
        auto push_front_array(bag const & value) -> void;
        auto push_back_array(bag const & value) -> void;
        auto pop_front_array() -> bag;
        auto pop_back_array() -> bag;
        auto resize_array(std::size_t count) -> void;
        auto as_array_bool(std::vector<bool> & dest) const -> void;
        auto as_array_int64(std::vector<int64_t> & dest) const -> void;
        auto as_array_uint64(std::vector<uint64_t> & dest) const -> void;
        auto as_array_double(std::vector<double> & dest) const -> void;
        auto as_array_string(std::vector<std::string> & dest) const -> void;
        auto as_array_any(std::vector<strange::any> & dest) const -> void;
        auto to_array_bool() const -> std::vector<bool>;
        auto to_array_int64() const -> std::vector<int64_t>;
        auto to_array_uint64() const -> std::vector<uint64_t>;
        auto to_array_double() const -> std::vector<double>;
        auto to_array_string() const -> std::vector<std::string>;
        auto to_array_any() const -> std::vector<strange::any>;
        auto from_array_bool(std::vector<bool> const & src) -> void;
        auto from_array_int64(std::vector<int64_t> const & src) -> void;
        auto from_array_uint64(std::vector<uint64_t> const & src) -> void;
        auto from_array_double(std::vector<double> const & src) -> void;
        auto from_array_string(std::vector<std::string> const & src) -> void;
        auto from_array_any(std::vector<strange::any> const & src) -> void;
        auto make_array_bool(std::vector<bool> const & src) const -> bag;
        auto make_array_int64(std::vector<int64_t> const & src) const -> bag;
        auto make_array_uint64(std::vector<uint64_t> const & src) const -> bag;
        auto make_array_double(std::vector<double> const & src) const -> bag;
        auto make_array_string(std::vector<std::string> const & src) const -> bag;
        auto make_array_any(std::vector<strange::any> const & src) const -> bag;

        auto is_object() const -> bool;
        auto as_object(std::unordered_map<std::string, bag> & dest) const -> void;
        auto to_object() const -> std::unordered_map<std::string, bag>;
        auto from_object() -> void;
        auto from_object(std::unordered_map<std::string, bag> const & src) -> void;
        auto make_object() const -> bag;
        auto make_object(std::unordered_map<std::string, bag> const & src) const -> bag;
        auto empty_object() const -> bool;
        auto size_object() const -> std::size_t;
        auto clear_object() -> void;
        auto insert_object(std::string const & key, bag const & value) -> void;
        auto erase_object(std::string const & key) -> void;
        auto get_object(std::string const & key) const -> bag;
        auto set_object(std::string const & key, bag const & value) -> void;
        auto contains_object(std::string const & key) const -> bool;

        auto is_any() const -> bool;
        auto as_any(strange::any & dest) const -> void;
        auto to_any() const -> strange::any;
        auto from_any() -> void;
        auto from_any(strange::any const & src) -> void;
        auto make_any() const -> bag;
        auto make_any(strange::any const & src) const -> bag;
    };

    struct package : stuff
    {
        auto seal() -> void;
        auto unseal() -> void;
        auto sealed() const -> bool;

        auto is_binary() const -> bool;
        auto as_binary(std::string & binary) const -> void;
        auto to_binary() const -> std::string;
        auto from_binary(std::string const & binary) -> void;
        auto make_binary(std::string const & binary) const -> package;

        auto is_json() const -> bool;
        auto as_json(std::string & json) const -> void;
        auto to_json() const -> std::string;
        auto from_json(std::string const & json) -> void;
        auto make_json(std::string const & json) const -> package;
    };

    struct [[strange::thing("strange::implementation::baggage")]]
    baggage : bag, package
    {
    };

    struct [[strange::thing("strange::implementation::parameter")]]
    parameter : stuff
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
    operation : stuff
    {
        std::string name {};
        std::vector<strange::parameter> parameters {};
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
    abstraction : stuff
    {
        std::vector<strange::parameter> parameters {};
        std::string name {};
        std::vector<std::string> parents {};
        std::vector<strange::parameter> types {};
        std::vector<strange::operation> operations {};
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
    space : stuff
    {
        std::vector<strange::abstraction> inclusions {};
        std::string name {};
        std::vector<strange::abstraction> abstractions {};

        [[strange::customisation("return inclusions() == other.inclusions()"
        "    && name() == other.name()"
        "    && abstractions() == other.abstractions()")]]
        auto operator==(space const & other) const -> bool;

        [[strange::customisation("return !operator==(other)")]]
        auto operator!=(space const & other) const -> bool;

        [[strange::customisation("return inclusions() < other.inclusions() || (inclusions() == other.inclusions()"
        "    && (name() < other.name() || (name() == other.name()"
        "    && abstractions() < other.abstractions())))")]]
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
