TEST_CASE("any: default construction")
{
    strange::any a;
    CHECK_FALSE(a._something());
    CHECK_FALSE(a._valid());
}

TEST_CASE("any: _make with concrete type")
{
    auto a = strange::any::_make<int>(42);
    CHECK(a._something());
    CHECK(a._valid());
    CHECK(a._cat() == "strange::any");
}

TEST_CASE("any: _cats includes strange::any")
{
    auto a = strange::any::_make<int>(42);
    auto cats = a._cats();
    CHECK(cats.count("strange::any") == 1);
}

TEST_CASE("any: _clone produces independent copy")
{
    auto a = strange::any::_make<int>(42);
    auto b = a._clone();
    CHECK(b._something());
    CHECK(b._valid());
}

TEST_CASE("any: _reproduce produces default-constructed instance")
{
    auto a = strange::any::_make<int>(42);
    auto b = a._reproduce();
    CHECK(b._something());
    CHECK(b._valid());
}

TEST_CASE("any: copy semantics")
{
    auto a = strange::any::_make<int>(42);
    auto b = a;
    CHECK(b._something());

    auto c = std::move(a);
    CHECK(c._something());
}
