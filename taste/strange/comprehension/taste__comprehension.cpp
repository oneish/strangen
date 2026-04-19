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

TEST_CASE("toker: negative number")
{
    std::istringstream input("-123");
    std::istreambuf_iterator<char> it(input);
    strange::comprehension::toker t(it);

    auto tok = t.increment();
    CHECK(tok.classification() == strange::comprehension::cls::number);
    CHECK(tok.text() == "-123");
}

TEST_CASE("toker: float with leading dot")
{
    std::istringstream input(".5");
    std::istreambuf_iterator<char> it(input);
    strange::comprehension::toker t(it);

    auto tok = t.increment();
    // .5 starts with punctuation dot, then number
    CHECK(tok.classification() == strange::comprehension::cls::punctuation);
}

TEST_CASE("toker: float with trailing dot")
{
    std::istringstream input("5.x");
    std::istreambuf_iterator<char> it(input);
    strange::comprehension::toker t(it);

    auto tok = t.increment();
    CHECK(tok.classification() == strange::comprehension::cls::number);
    CHECK(tok.text() == "5");
}

TEST_CASE("toker: scientific notation")
{
    std::istringstream input("1e10");
    std::istreambuf_iterator<char> it(input);
    strange::comprehension::toker t(it);

    auto tok = t.increment();
    CHECK(tok.classification() == strange::comprehension::cls::number);
    CHECK(tok.text() == "1e10");
}

TEST_CASE("toker: all escape sequences")
{
    std::istringstream input("\"\\a\\b\\f\\r\\t\\v\\\\\"");
    std::istreambuf_iterator<char> it(input);
    strange::comprehension::toker t(it);

    auto tok = t.increment();
    CHECK(tok.classification() == strange::comprehension::cls::string);
    CHECK(tok.text() == "\a\b\f\r\t\v\\");
}

TEST_CASE("toker: double-char operators")
{
    auto check_op = [](std::string const & op)
    {
        std::istringstream input(op);
        std::istreambuf_iterator<char> it(input);
        strange::comprehension::toker t(it);
        auto tok = t.increment();
        return tok.text();
    };
    CHECK(check_op("==") == "==");
    CHECK(check_op("!=") == "!=");
    CHECK(check_op("<=") == "<=");
    CHECK(check_op(">=") == ">=");
    CHECK(check_op("++") == "++");
    CHECK(check_op("--") == "--");
}

TEST_CASE("toker: ellipsis")
{
    std::istringstream input("...");
    std::istreambuf_iterator<char> it(input);
    strange::comprehension::toker t(it);

    auto tok = t.increment();
    CHECK(tok.classification() == strange::comprehension::cls::punctuation);
    CHECK(tok.text() == "...");
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

TEST_CASE("parser: closure annotation")
{
    std::string input = R"(
namespace test
{
    struct food : strange::any
    {
        [[strange::closure("eat_closure_")]]
        auto eat(int x) -> void;
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
    CHECK(op.name() == "eat");
    CHECK(op.closure() == "eat_closure_");
}

TEST_CASE("parser: default arguments")
{
    std::string input = R"(
namespace test
{
    struct widget : strange::any
    {
        auto process(int x = 0) -> void;
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
    REQUIRE(op.parameters().size() == 1);
    CHECK(op.parameters()[0].name() == "x");
    CHECK(op.parameters()[0].argument() == "0");
}

TEST_CASE("parser: multiple inheritance")
{
    std::string input = R"(
namespace test
{
    struct base1 : strange::any
    {
        auto foo() -> void;
    };
    struct base2 : strange::any
    {
        auto bar() -> void;
    };
    struct derived : base1, base2
    {
        auto baz() -> void;
    };
}
)";
    std::istringstream iss(input);
    std::istreambuf_iterator<char> it(iss);
    strange::comprehension::toker toker(it, "test_input");
    strange::comprehension::parser parser(toker);

    auto spc = parser.parse();
    CHECK(spc._error() == "");
    REQUIRE(spc.abstractions().size() == 3);

    auto const & derived = spc.abstractions()[2];
    CHECK(derived.name() == "derived");
    REQUIRE(derived.parents().size() == 2);
    CHECK(derived.parents()[0] == "base1");
    CHECK(derived.parents()[1] == "base2");
}

TEST_CASE("parser: data member")
{
    std::string input = R"(
namespace test
{
    struct item : strange::any
    {
        std::string name;
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

    auto const & ops = spc.abstractions()[0].operations();
    REQUIRE(ops.size() == 2);
    CHECK(ops[0].data() == true);
    CHECK(ops[0].name() == "name");
    CHECK(ops[0].constness() == true);
    CHECK(ops[1].data() == true);
    CHECK(ops[1].name() == "name");
    CHECK(ops[1].constness() == false);
}

TEST_CASE("parser: variadic template")
{
    std::string input = R"(
namespace test
{
    template<typename... Args>
    struct variadic : strange::any
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
    CHECK(abs.name() == "variadic");
    REQUIRE(abs.parameters().size() == 1);
    CHECK(abs.parameters()[0].type() == "typename");
    CHECK(abs.parameters()[0].name() == "Args");
    CHECK(abs.parameters()[0].variadic() == true);
}

TEST_CASE("parser: template with default argument")
{
    std::string input = R"(
namespace test
{
    template<typename T = int>
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
    REQUIRE(abs.parameters().size() == 1);
    CHECK(abs.parameters()[0].name() == "T");
    CHECK(abs.parameters()[0].argument() == "int");
}

TEST_CASE("parser: using declaration")
{
    std::string input = R"(
namespace test
{
    struct bunch : strange::any
    {
        using Item = int;
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
    REQUIRE(abs.types().size() == 1);
    CHECK(abs.types()[0].name() == "Item");
    CHECK(abs.types()[0].argument() == "int");
}

TEST_CASE("parser: angle bracket include")
{
    std::string input = R"(
#include <path/to/header.h>
namespace test
{
    struct widget : strange::any
    {
        auto display() -> void;
    };
}
)";
    std::istringstream iss(input);
    std::istreambuf_iterator<char> it(iss);
    strange::comprehension::toker toker(it, "test_input");
    strange::comprehension::parser parser(toker);

    auto spc = parser.parse();
    CHECK(spc._error() == "");
    REQUIRE(spc.includes().size() == 1);
    CHECK(spc.includes()[0] == "path/to/header.h");
}

TEST_CASE("parser: hash attribute")
{
    std::string input = R"(
namespace test
{
    struct [[strange::hash]]
    item : strange::any
    {
        std::string name {};
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
    CHECK(spc.abstractions()[0].hash() == true);
}

TEST_CASE("parser: equality attribute synthesizes operators")
{
    std::string input = R"(
namespace test
{
    struct [[strange::equality]]
    item : strange::any
    {
        std::string name {};
        int64_t value {};
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
    CHECK(spc.abstractions()[0].equality() == true);

    auto const & ops = spc.abstractions()[0].operations();
    bool found_eq = false;
    bool found_ne = false;
    for (auto const & op : ops)
    {
        if (op.name() == "operator==" && op.constness() && op.result() == "bool")
        {
            found_eq = true;
            CHECK(op.parameters().size() == 1);
            CHECK(op.parameters()[0].name() == "other");
            CHECK(op.customisation().find("name() == other.name()") != std::string::npos);
            CHECK(op.customisation().find("value() == other.value()") != std::string::npos);
        }
        if (op.name() == "operator!=" && op.constness() && op.result() == "bool")
        {
            found_ne = true;
            CHECK(op.customisation() == "return !operator==(other)");
        }
    }
    CHECK(found_eq);
    CHECK(found_ne);
}

TEST_CASE("parser: comparison attribute synthesizes operators")
{
    std::string input = R"(
namespace test
{
    struct [[strange::comparison]]
    item : strange::any
    {
        std::string name {};
        int64_t value {};
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
    CHECK(spc.abstractions()[0].comparison() == true);

    auto const & ops = spc.abstractions()[0].operations();
    bool found_lt = false;
    bool found_le = false;
    bool found_gt = false;
    bool found_ge = false;
    for (auto const & op : ops)
    {
        if (op.name() == "operator<" && op.constness() && op.result() == "bool")
        {
            found_lt = true;
            CHECK(op.customisation().find("name() < other.name()") != std::string::npos);
            CHECK(op.customisation().find("value() < other.value()") != std::string::npos);
        }
        if (op.name() == "operator<=" && op.constness())
        {
            found_le = true;
            CHECK(op.customisation() == "return operator<(other) || operator==(other)");
        }
        if (op.name() == "operator>" && op.constness())
        {
            found_gt = true;
            CHECK(op.customisation() == "return !operator<=(other)");
        }
        if (op.name() == "operator>=" && op.constness())
        {
            found_ge = true;
            CHECK(op.customisation() == "return !operator<(other)");
        }
    }
    CHECK(found_lt);
    CHECK(found_le);
    CHECK(found_gt);
    CHECK(found_ge);
}

TEST_CASE("parser: non-data operation with implementation")
{
    std::string input = R"(
namespace test
{
    struct [[strange::implementation("test::impl")]]
    widget : strange::any
    {
        std::string name {};
        auto compute() const -> int { return 42; };
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
    CHECK(abs.thing() == "test::impl");
    CHECK(abs.implementation() == "test::impl");

    bool found_compute = false;
    for (auto const & op : abs.operations())
    {
        if (op.name() == "compute" && op.constness())
        {
            found_compute = true;
            CHECK(op.data() == false);
            CHECK(op.result() == "int");
            CHECK(op.implementation() == "{ return 42; }");
        }
    }
    CHECK(found_compute);
}
