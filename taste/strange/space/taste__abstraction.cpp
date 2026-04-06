TEST_CASE("abstraction: default _make construction")
{
    auto abs = strange::abstraction::_make();
    CHECK(abs._something());
    CHECK(abs._valid());
    CHECK(abs.name() == "");
    CHECK(abs.parents().empty());
    CHECK(abs.parameters().empty());
    CHECK(abs.types().empty());
    CHECK(abs.operations().empty());
    CHECK(abs.thing() == "");
    CHECK(abs.implementation() == "");
}

TEST_CASE("abstraction: name, parents, thing, implementation")
{
    auto abs = strange::abstraction::_make();
    abs.name() = "widget";
    abs.parents().push_back("strange::any");
    abs.thing() = "implement";
    abs.implementation() = "implement";

    CHECK(abs.name() == "widget");
    CHECK(abs.parents().size() == 1);
    CHECK(abs.parents()[0] == "strange::any");
    CHECK(abs.thing() == "implement");
    CHECK(abs.implementation() == "implement");
}

TEST_CASE("abstraction: parameters and operations")
{
    auto abs = strange::abstraction::_make();
    abs.name() = "container";

    auto param = strange::parameter::_make();
    param.type() = "typename";
    param.name() = "T";
    abs.parameters().push_back(param);

    auto op = strange::operation::_make();
    op.name() = "size";
    op.constness() = true;
    op.result() = "std::size_t";
    abs.operations().push_back(op);

    CHECK(abs.parameters().size() == 1);
    CHECK(abs.parameters()[0].name() == "T");
    CHECK(abs.operations().size() == 1);
    CHECK(abs.operations()[0].name() == "size");
}

TEST_CASE("abstraction: _cat and _cats")
{
    auto abs = strange::abstraction::_make();
    CHECK(abs._cat() == "strange::abstraction");
    auto cats = abs._cats();
    CHECK(cats.count("strange::abstraction") == 1);
    CHECK(cats.count("strange::stuff") == 1);
    CHECK(cats.count("strange::any") == 1);
}
