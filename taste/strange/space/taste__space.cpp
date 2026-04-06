TEST_CASE("space: default _make construction")
{
    auto spc = strange::space::_make();
    CHECK(spc._something());
    CHECK(spc._valid());
    CHECK(spc.name() == "");
    CHECK(spc.abstractions().empty());
    CHECK(spc.inclusions().empty());
}

TEST_CASE("space: name, abstractions, inclusions")
{
    auto spc = strange::space::_make();
    spc.name() = "example";

    auto abs1 = strange::abstraction::_make();
    abs1.name() = "widget";
    spc.abstractions().push_back(abs1);

    auto abs2 = strange::abstraction::_make();
    abs2.name() = "button";
    spc.abstractions().push_back(abs2);

    auto inc = strange::abstraction::_make();
    inc.name() = "included_type";
    spc.inclusions().push_back(inc);

    CHECK(spc.name() == "example");
    CHECK(spc.abstractions().size() == 2);
    CHECK(spc.abstractions()[0].name() == "widget");
    CHECK(spc.abstractions()[1].name() == "button");
    CHECK(spc.inclusions().size() == 1);
    CHECK(spc.inclusions()[0].name() == "included_type");
}

TEST_CASE("space: _cat and _cats")
{
    auto spc = strange::space::_make();
    CHECK(spc._cat() == "strange::space");
    auto cats = spc._cats();
    CHECK(cats.count("strange::space") == 1);
    CHECK(cats.count("strange::stuff") == 1);
    CHECK(cats.count("strange::any") == 1);
}

TEST_CASE("space: equality")
{
    auto s1 = strange::space::_make();
    s1.name() = "ns";

    auto s2 = strange::space::_make();
    s2.name() = "ns";

    CHECK(s1 == s2);

    s2.name() = "other";
    CHECK(s1 != s2);
}
