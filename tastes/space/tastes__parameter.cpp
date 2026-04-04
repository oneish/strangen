TEST_CASE("parameter: default _make construction")
{
    auto p = strange::parameter::_make();
    CHECK(p._something());
    CHECK(p._valid());
    CHECK(p.type() == "");
    CHECK(p.name() == "");
    CHECK(p.argument() == "");
    CHECK(p.variadic() == false);
}

TEST_CASE("parameter: getters and setters")
{
    auto p = strange::parameter::_make();
    p.type() = "int";
    p.name() = "count";
    p.argument() = "0";
    p.variadic() = true;

    CHECK(p.type() == "int");
    CHECK(p.name() == "count");
    CHECK(p.argument() == "0");
    CHECK(p.variadic() == true);
}

TEST_CASE("parameter: const accessors")
{
    auto p = strange::parameter::_make();
    p.type() = "std::string";
    p.name() = "label";

    strange::parameter const & cp = p;
    CHECK(cp.type() == "std::string");
    CHECK(cp.name() == "label");
    CHECK(cp.argument() == "");
    CHECK(cp.variadic() == false);
}

TEST_CASE("parameter: equality operators")
{
    auto p1 = strange::parameter::_make();
    p1.type() = "int";
    p1.name() = "x";

    auto p2 = strange::parameter::_make();
    p2.type() = "int";
    p2.name() = "x";

    auto p3 = strange::parameter::_make();
    p3.type() = "double";
    p3.name() = "x";

    CHECK(p1 == p2);
    CHECK_FALSE(p1 != p2);
    CHECK(p1 != p3);
}

TEST_CASE("parameter: _cat and _cats")
{
    auto p = strange::parameter::_make();
    CHECK(p._cat() == "strange::parameter");
    auto cats = p._cats();
    CHECK(cats.count("strange::parameter") == 1);
    CHECK(cats.count("strange::stuff") == 1);
    CHECK(cats.count("strange::any") == 1);
}

TEST_CASE("parameter: _clone produces independent copy")
{
    auto p1 = strange::parameter::_make();
    p1.name() = "original";
    auto p2 = p1._clone();
    p2.name() = "cloned";
    CHECK(p1.name() == "original");
    CHECK(p2.name() == "cloned");
}
