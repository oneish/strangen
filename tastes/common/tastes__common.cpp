TEST_CASE("_common: default construction produces nothing")
{
    strange::any a;
    CHECK_FALSE(a._something());
    CHECK(a._cat() == "");
    CHECK(a._name() == "");
    CHECK(a._error() == "");
    CHECK(a._address() == nullptr);
    CHECK(a._sizeof() == 0);
    CHECK_FALSE(a._copy());
    CHECK_FALSE(a._is_weak());
}

TEST_CASE("_common: _error sets error message and replaces shared state")
{
    auto p = strange::parameter::_make();
    CHECK(p._something());
    CHECK(p._error() == "");

    auto msg = p._error("something went wrong");
    CHECK(msg == "something went wrong");
    CHECK(p._error() == "something went wrong");
    CHECK_FALSE(p._valid());
}

TEST_CASE("_common: _mutate triggers copy-on-write when shared")
{
    auto p1 = strange::parameter::_make();
    p1.name() = "original";
    auto p2 = p1;

    bool did_mutate = p2._mutate();
    CHECK(did_mutate);

    p2.name() = "mutated";
    CHECK(p1.name() == "original");
    CHECK(p2.name() == "mutated");
}

TEST_CASE("_common: _mutate does not clone when sole owner")
{
    auto p = strange::parameter::_make();
    bool did_mutate = p._mutate();
    CHECK_FALSE(did_mutate);
}

TEST_CASE("_common: _static cast preserves shared state")
{
    auto param = strange::parameter::_make();
    param.name() = "test";

    auto a = param._static<strange::any>();
    auto param2 = a._static<strange::parameter>();
    CHECK(param2._valid());
    CHECK(param2.name() == "test");
}

TEST_CASE("_common: _dynamic cast succeeds for compatible type")
{
    auto param = strange::parameter::_make();
    auto a = param._static<strange::any>();
    auto result = a._dynamic<strange::parameter>();
    CHECK(result._something());
    CHECK(result._valid());
}

TEST_CASE("_common: _dynamic cast fails for incompatible type")
{
    auto param = strange::parameter::_make();
    auto a = param._static<strange::any>();
    auto result = a._dynamic<strange::operation>();
    CHECK_FALSE(result._something());
}

TEST_CASE("_common: _weak and _is_weak")
{
    auto p = strange::parameter::_make();
    CHECK_FALSE(p._is_weak());

    auto w = p._weak();
    CHECK(w._is_weak());
}

TEST_CASE("_common: _weak reference expires when original is destroyed")
{
    strange::any w;
    {
        auto p = strange::parameter::_make();
        w = p._weak();
        CHECK(w._is_weak());
    }
    auto s = w._strong();
    CHECK_FALSE(s._something());
}

TEST_CASE("_common: _address and _sizeof for valid objects")
{
    auto p1 = strange::parameter::_make();
    auto p2 = strange::parameter::_make();

    CHECK(p1._address() != nullptr);
    CHECK(p2._address() != nullptr);
    CHECK(p1._address() != p2._address());
    CHECK(p1._sizeof() > 0);
}

TEST_CASE("_common: _name returns reflection name for concrete type")
{
    auto p = strange::parameter::_make();
    CHECK(p._name().find("parameter") != std::string::npos);
}

TEST_CASE("_common: _copy returns true for copyable types")
{
    auto p = strange::parameter::_make();
    CHECK(p._copy() == true);
}

struct non_copyable_thing
{
    non_copyable_thing() = default;
    non_copyable_thing(non_copyable_thing const &) = delete;
    non_copyable_thing(non_copyable_thing &&) = default;
};

TEST_CASE("_common: _make with non-copyable type")
{
    auto a = strange::any::_make<non_copyable_thing, false>();
    CHECK(a._something());
    CHECK(a._valid());
    CHECK(a._copy() == false);

    auto cloned = a._clone();
    CHECK_FALSE(cloned._something());
}

TEST_CASE("_common: _manufacture for registered types")
{
    auto p = strange::parameter::_manufacture(
        "strange::parameter_<strange::implementation::parameter, true>");
    CHECK(p._something());
    CHECK(p._valid());
}

TEST_CASE("_common: _manufacture for unknown type returns empty")
{
    auto p = strange::parameter::_manufacture("nonexistent::type");
    CHECK_FALSE(p._something());
}
