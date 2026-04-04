TEST_CASE("operation: default _make construction")
{
    auto op = strange::operation::_make();
    CHECK(op._something());
    CHECK(op._valid());
    CHECK(op.name() == "");
    CHECK(op.parameters().empty());
    CHECK(op.constness() == false);
    CHECK(op.result() == "");
    CHECK(op.data() == false);
    CHECK(op.closure() == "");
    CHECK(op.modification() == "");
    CHECK(op.customisation() == "");
    CHECK(op.implementation() == "");
}

TEST_CASE("operation: setters and getters")
{
    auto op = strange::operation::_make();
    op.name() = "process";
    op.constness() = true;
    op.result() = "bool";
    op.data() = false;
    op.closure() = "process_closure_";
    op.modification() = "mod";
    op.customisation() = "custom";
    op.implementation() = "impl";

    CHECK(op.name() == "process");
    CHECK(op.constness() == true);
    CHECK(op.result() == "bool");
    CHECK(op.data() == false);
    CHECK(op.closure() == "process_closure_");
    CHECK(op.modification() == "mod");
    CHECK(op.customisation() == "custom");
    CHECK(op.implementation() == "impl");
}

TEST_CASE("operation: parameters vector")
{
    auto op = strange::operation::_make();
    auto p1 = strange::parameter::_make();
    p1.type() = "int";
    p1.name() = "x";
    auto p2 = strange::parameter::_make();
    p2.type() = "double";
    p2.name() = "y";

    op.parameters().push_back(p1);
    op.parameters().push_back(p2);

    CHECK(op.parameters().size() == 2);
    CHECK(op.parameters()[0].name() == "x");
    CHECK(op.parameters()[1].name() == "y");
}

TEST_CASE("operation: _cat and _cats")
{
    auto op = strange::operation::_make();
    CHECK(op._cat() == "strange::operation");
    auto cats = op._cats();
    CHECK(cats.count("strange::operation") == 1);
    CHECK(cats.count("strange::stuff") == 1);
    CHECK(cats.count("strange::any") == 1);
}

TEST_CASE("operation: equality")
{
    auto op1 = strange::operation::_make();
    op1.name() = "foo";
    op1.result() = "void";

    auto op2 = strange::operation::_make();
    op2.name() = "foo";
    op2.result() = "void";

    CHECK(op1 == op2);

    op2.name() = "bar";
    CHECK(op1 != op2);
}
