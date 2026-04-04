// ---- TOKENIZER TESTS ----

TEST_CASE("toker: tokenize a name")
{
    std::istringstream input("hello");
    std::istreambuf_iterator<char> it(input);
    strange::comprehension::toker t(it, "test");

    auto tok = t.increment();
    CHECK(tok.classification() == strange::comprehension::cls::name);
    CHECK(tok.text() == "hello");
    CHECK(tok.filename() == "test");
    CHECK(tok.line() == 1);
}

TEST_CASE("toker: tokenize a number")
{
    std::istringstream input("42");
    std::istreambuf_iterator<char> it(input);
    strange::comprehension::toker t(it);

    auto tok = t.increment();
    CHECK(tok.classification() == strange::comprehension::cls::number);
    CHECK(tok.text() == "42");
}

TEST_CASE("toker: tokenize floating point number")
{
    std::istringstream input("3.14");
    std::istreambuf_iterator<char> it(input);
    strange::comprehension::toker t(it);

    auto tok = t.increment();
    CHECK(tok.classification() == strange::comprehension::cls::number);
    CHECK(tok.text() == "3.14");
}

TEST_CASE("toker: tokenize a string literal")
{
    std::istringstream input("\"hello world\"");
    std::istreambuf_iterator<char> it(input);
    strange::comprehension::toker t(it);

    auto tok = t.increment();
    CHECK(tok.classification() == strange::comprehension::cls::string);
    CHECK(tok.text() == "hello world");
}

TEST_CASE("toker: tokenize punctuation")
{
    std::istringstream input("{");
    std::istreambuf_iterator<char> it(input);
    strange::comprehension::toker t(it);

    auto tok = t.increment();
    CHECK(tok.classification() == strange::comprehension::cls::punctuation);
    CHECK(tok.text() == "{");
}

TEST_CASE("toker: tokenize double colon")
{
    std::istringstream input("::");
    std::istreambuf_iterator<char> it(input);
    strange::comprehension::toker t(it);

    auto tok = t.increment();
    CHECK(tok.classification() == strange::comprehension::cls::punctuation);
    CHECK(tok.text() == "::");
}

TEST_CASE("toker: tokenize arrow")
{
    std::istringstream input("->");
    std::istreambuf_iterator<char> it(input);
    strange::comprehension::toker t(it);

    auto tok = t.increment();
    CHECK(tok.classification() == strange::comprehension::cls::punctuation);
    CHECK(tok.text() == "->");
}

TEST_CASE("toker: tokenize line comment")
{
    std::istringstream input("// comment\nname");
    std::istreambuf_iterator<char> it(input);
    strange::comprehension::toker t(it);

    auto tok = t.increment();
    CHECK(tok.classification() == strange::comprehension::cls::comment);

    tok = t.increment();
    CHECK(tok.classification() == strange::comprehension::cls::name);
    CHECK(tok.text() == "name");
}

TEST_CASE("toker: tokenize block comment")
{
    std::istringstream input("/* block */name");
    std::istreambuf_iterator<char> it(input);
    strange::comprehension::toker t(it);

    auto tok = t.increment();
    CHECK(tok.classification() == strange::comprehension::cls::comment);

    tok = t.increment();
    CHECK(tok.classification() == strange::comprehension::cls::name);
    CHECK(tok.text() == "name");
}

TEST_CASE("toker: character literal")
{
    std::istringstream input("'x'");
    std::istreambuf_iterator<char> it(input);
    strange::comprehension::toker t(it);

    auto tok = t.increment();
    CHECK(tok.classification() == strange::comprehension::cls::character);
    CHECK(tok.text() == "x");
}

TEST_CASE("toker: string escape sequences")
{
    std::istringstream input("\"hello\\nworld\"");
    std::istreambuf_iterator<char> it(input);
    strange::comprehension::toker t(it);

    auto tok = t.increment();
    CHECK(tok.classification() == strange::comprehension::cls::string);
    CHECK(tok.text() == "hello\nworld");
}

// ---- PARSER TESTS ----

TEST_CASE("parser: parse minimal space")
{
    std::string input = R"(
namespace test
{
}
)";
    std::istringstream iss(input);
    std::istreambuf_iterator<char> it(iss);
    strange::comprehension::toker toker(it, "test_input");
    strange::comprehension::parser parser(toker);

    auto spc = parser.parse();
    CHECK(spc._error() == "");
    CHECK(spc.name() == "test");
    CHECK(spc.abstractions().empty());
}

TEST_CASE("parser: parse space with simple struct")
{
    std::string input = R"(
namespace example
{
    struct widget : strange::any
    {
        auto display() const -> void;
    };
}
)";
    std::istringstream iss(input);
    std::istreambuf_iterator<char> it(iss);
    strange::comprehension::toker toker(it, "test_input");
    strange::comprehension::parser parser(toker);

    auto spc = parser.parse();
    CHECK(spc._error() == "");
    CHECK(spc.name() == "example");
    REQUIRE(spc.abstractions().size() == 1);

    auto const & abs = spc.abstractions()[0];
    CHECK(abs.name() == "widget");
    REQUIRE(abs.parents().size() == 1);
    CHECK(abs.parents()[0] == "strange::any");
}

TEST_CASE("parser: parse templated struct")
{
    std::string input = R"(
namespace test
{
    template<typename T>
    struct container : strange::any
    {
        auto size() const -> std::size_t;
    };
}
)";
    std::istringstream iss(input);
    std::istreambuf_iterator<char> it(iss);
    strange::comprehension::toker toker(it, "test_input");
    strange::comprehension::parser parser(toker);

    auto spc = parser.parse();
    CHECK(spc._error() == "");
    REQUIRE(spc.abstractions().size() == 1);

    auto const & abs = spc.abstractions()[0];
    CHECK(abs.name() == "container");
    REQUIRE(abs.parameters().size() == 1);
    CHECK(abs.parameters()[0].type() == "typename");
    CHECK(abs.parameters()[0].name() == "T");
}

TEST_CASE("parser: parse multiple abstractions")
{
    std::string input = R"(
namespace test
{
    struct alpha : strange::any
    {
        auto foo() -> void;
    };
    struct beta : alpha
    {
        auto bar() const -> int;
    };
}
)";
    std::istringstream iss(input);
    std::istreambuf_iterator<char> it(iss);
    strange::comprehension::toker toker(it, "test_input");
    strange::comprehension::parser parser(toker);

    auto spc = parser.parse();
    CHECK(spc._error() == "");
    CHECK(spc.name() == "test");
    REQUIRE(spc.abstractions().size() == 2);
    CHECK(spc.abstractions()[0].name() == "alpha");
    CHECK(spc.abstractions()[1].name() == "beta");
}

TEST_CASE("parser: parse operation with parameters")
{
    std::string input = R"(
namespace test
{
    struct widget : strange::any
    {
        auto process(int count, std::string const & label) -> bool;
    };
}
)";
    std::istringstream iss(input);
    std::istreambuf_iterator<char> it(iss);
    strange::comprehension::toker toker(it, "test_input");
    strange::comprehension::parser parser(toker);

    auto spc = parser.parse();
    CHECK(spc._error() == "");
    REQUIRE(spc.abstractions().size() == 1);
    REQUIRE(spc.abstractions()[0].operations().size() >= 1);

    auto const & op = spc.abstractions()[0].operations()[0];
    CHECK(op.name() == "process");
    CHECK(op.result() == "bool");
    CHECK(op.constness() == false);
    REQUIRE(op.parameters().size() == 2);
    CHECK(op.parameters()[0].type() == "int");
    CHECK(op.parameters()[0].name() == "count");
    CHECK(op.parameters()[1].name() == "label");
}

TEST_CASE("parser: invalid input produces error")
{
    std::string input = "not_a_valid_space";
    std::istringstream iss(input);
    std::istreambuf_iterator<char> it(iss);
    strange::comprehension::toker toker(it, "bad_input");
    strange::comprehension::parser parser(toker);

    auto spc = parser.parse();
    CHECK(spc._error() != "");
}
