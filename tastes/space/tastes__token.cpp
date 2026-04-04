TEST_CASE("token: default _make construction")
{
    auto tok = strange::token::_make();
    CHECK(tok._something());
    CHECK(tok._valid());
    CHECK(tok.filename() == "");
    CHECK(tok.line() == 0);
    CHECK(tok.position() == 0);
    CHECK(tok.text() == "");
}

TEST_CASE("token: setters via mutable accessors")
{
    auto tok = strange::token::_make();
    tok.filename() = "input.cpp";
    tok.line() = 42;
    tok.position() = 7;
    tok.classification() = strange::comprehension::cls::punctuation;
    tok.text() = "{";

    CHECK(tok.filename() == "input.cpp");
    CHECK(tok.line() == 42);
    CHECK(tok.position() == 7);
    CHECK(tok.classification() == strange::comprehension::cls::punctuation);
    CHECK(tok.text() == "{");
}

TEST_CASE("token: _cat and _cats")
{
    auto tok = strange::token::_make();
    CHECK(tok._cat() == "strange::token");
    auto cats = tok._cats();
    CHECK(cats.count("strange::token") == 1);
    CHECK(cats.count("strange::any") == 1);
}

TEST_CASE("token: classification enum round-trip")
{
    auto check_cls = [](strange::comprehension::cls c)
    {
        auto tok = strange::token::_make();
        tok.classification() = c;
        return tok.classification() == c;
    };
    CHECK(check_cls(strange::comprehension::cls::name));
    CHECK(check_cls(strange::comprehension::cls::number));
    CHECK(check_cls(strange::comprehension::cls::character));
    CHECK(check_cls(strange::comprehension::cls::string));
    CHECK(check_cls(strange::comprehension::cls::comment));
    CHECK(check_cls(strange::comprehension::cls::punctuation));
    CHECK(check_cls(strange::comprehension::cls::whitespace));
    CHECK(check_cls(strange::comprehension::cls::mistake));
}
