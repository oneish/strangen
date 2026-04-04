// ---- SCALAR TYPE TESTS ----

TEST_CASE("baggage: null")
{
    auto b = strange::baggage::_make();
    b.from_null();
    CHECK(b.is_null());
    CHECK_FALSE(b.is_bool());
    CHECK_FALSE(b.is_int64());
    CHECK_FALSE(b.is_string());

    auto n = b.make_null();
    CHECK(n.is_null());
}

TEST_CASE("baggage: bool")
{
    auto b = strange::baggage::_make();
    b.from_bool(true);
    CHECK(b.is_bool());
    CHECK(b.to_bool() == true);
    CHECK_FALSE(b.is_null());
    CHECK_FALSE(b.is_int64());

    bool dest = false;
    b.as_bool(dest);
    CHECK(dest == true);

    b.from_bool(false);
    CHECK(b.to_bool() == false);

    auto m = b.make_bool(true);
    CHECK(m.is_bool());
    CHECK(m.to_bool() == true);

    auto d = b.make_bool();
    CHECK(d.is_bool());
    CHECK(d.to_bool() == false);
}

TEST_CASE("baggage: int64")
{
    auto b = strange::baggage::_make();
    b.from_int64(-42);
    CHECK(b.is_int64());
    CHECK(b.to_int64() == -42);
    CHECK_FALSE(b.is_bool());
    CHECK_FALSE(b.is_double());

    int64_t dest = 0;
    b.as_int64(dest);
    CHECK(dest == -42);

    b.from_int64();
    CHECK(b.to_int64() == 0);

    auto m = b.make_int64(999);
    CHECK(m.to_int64() == 999);
}

TEST_CASE("baggage: uint64")
{
    auto b = strange::baggage::_make();
    b.from_uint64(123456);
    CHECK(b.is_uint64());
    CHECK(b.to_uint64() == 123456);

    uint64_t dest = 0;
    b.as_uint64(dest);
    CHECK(dest == 123456);

    auto m = b.make_uint64(789);
    CHECK(m.to_uint64() == 789);
}

TEST_CASE("baggage: double")
{
    auto b = strange::baggage::_make();
    b.from_double(3.14);
    CHECK(b.is_double());
    CHECK(b.to_double() == doctest::Approx(3.14));
    CHECK_FALSE(b.is_int64());

    double dest = 0.0;
    b.as_double(dest);
    CHECK(dest == doctest::Approx(3.14));

    auto m = b.make_double(2.718);
    CHECK(m.to_double() == doctest::Approx(2.718));

    b.from_double();
    CHECK(b.to_double() == doctest::Approx(0.0));
}

TEST_CASE("baggage: string")
{
    auto b = strange::baggage::_make();
    b.from_string("hello");
    CHECK(b.is_string());
    CHECK(b.to_string() == "hello");
    CHECK_FALSE(b.is_bool());

    std::string dest;
    b.as_string(dest);
    CHECK(dest == "hello");

    auto m = b.make_string("world");
    CHECK(m.to_string() == "world");

    b.from_string();
    CHECK(b.to_string() == "");
}

TEST_CASE("baggage: type transitions")
{
    auto b = strange::baggage::_make();

    b.from_bool(true);
    CHECK(b.is_bool());

    b.from_int64(42);
    CHECK(b.is_int64());
    CHECK_FALSE(b.is_bool());

    b.from_string("test");
    CHECK(b.is_string());
    CHECK_FALSE(b.is_int64());

    b.from_null();
    CHECK(b.is_null());
    CHECK_FALSE(b.is_string());
}

// ---- ARRAY TESTS ----

TEST_CASE("baggage: empty array")
{
    auto b = strange::baggage::_make();
    b.from_array();
    CHECK(b.is_array());
    CHECK(b.empty_array());
    CHECK(b.size_array() == 0);
}

TEST_CASE("baggage: array push and access")
{
    auto b = strange::baggage::_make();
    b.from_array();

    b.push_back_array(b.make_int64(10));
    b.push_back_array(b.make_int64(20));
    b.push_back_array(b.make_int64(30));

    CHECK(b.size_array() == 3);
    CHECK_FALSE(b.empty_array());

    CHECK(b.get_array(0).to_int64() == 10);
    CHECK(b.get_array(1).to_int64() == 20);
    CHECK(b.get_array(2).to_int64() == 30);

    CHECK(b.front_array().to_int64() == 10);
    CHECK(b.back_array().to_int64() == 30);
}

TEST_CASE("baggage: array modification")
{
    auto b = strange::baggage::_make();
    b.from_array();

    b.push_back_array(b.make_string("a"));
    b.push_back_array(b.make_string("b"));
    b.push_back_array(b.make_string("c"));

    b.set_array(1, b.make_string("B"));
    CHECK(b.get_array(1).to_string() == "B");

    b.insert_array(0, b.make_string("Z"));
    CHECK(b.size_array() == 4);
    CHECK(b.get_array(0).to_string() == "Z");

    b.erase_array(0);
    CHECK(b.size_array() == 3);
    CHECK(b.get_array(0).to_string() == "a");

    b.clear_array();
    CHECK(b.empty_array());
}

TEST_CASE("baggage: array push_front")
{
    auto b = strange::baggage::_make();
    b.from_array();

    b.push_back_array(b.make_int64(1));
    b.push_back_array(b.make_int64(2));
    b.push_front_array(b.make_int64(0));

    CHECK(b.size_array() == 3);
    CHECK(b.get_array(0).to_int64() == 0);
    CHECK(b.get_array(1).to_int64() == 1);
    CHECK(b.get_array(2).to_int64() == 2);
}

TEST_CASE("baggage: array pop_back")
{
    auto b = strange::baggage::_make();
    b.from_array();

    b.push_back_array(b.make_int64(10));
    b.push_back_array(b.make_int64(20));
    CHECK(b.size_array() == 2);

    auto result = b.pop_back_array();
    CHECK(result.is_array());
    CHECK(result.size_array() == 1);
    CHECK(result.get_array(0).to_int64() == 10);
}

TEST_CASE("baggage: array pop_front")
{
    auto b = strange::baggage::_make();
    b.from_array();

    b.push_back_array(b.make_int64(10));
    b.push_back_array(b.make_int64(20));
    CHECK(b.size_array() == 2);

    auto result = b.pop_front_array();
    CHECK(result.is_array());
    CHECK(result.size_array() == 1);
    CHECK(result.get_array(0).to_int64() == 20);
}

TEST_CASE("baggage: typed arrays")
{
    auto b = strange::baggage::_make();

    std::vector<int64_t> ints = {1, 2, 3, 4, 5};
    b.from_array_int64(ints);
    CHECK(b.is_array());
    auto restored = b.to_array_int64();
    CHECK(restored == ints);

    std::vector<std::string> strs = {"hello", "world"};
    b.from_array_string(strs);
    auto restored_strs = b.to_array_string();
    CHECK(restored_strs == strs);

    std::vector<double> dbls = {1.1, 2.2, 3.3};
    b.from_array_double(dbls);
    auto restored_dbls = b.to_array_double();
    REQUIRE(restored_dbls.size() == 3);
    CHECK(restored_dbls[0] == doctest::Approx(1.1));
    CHECK(restored_dbls[1] == doctest::Approx(2.2));
    CHECK(restored_dbls[2] == doctest::Approx(3.3));

    std::vector<bool> bools = {true, false, true};
    b.from_array_bool(bools);
    auto restored_bools = b.to_array_bool();
    CHECK(restored_bools == bools);
}

TEST_CASE("baggage: make typed arrays")
{
    auto b = strange::baggage::_make();

    std::vector<int64_t> ints = {10, 20};
    auto arr = b.make_array_int64(ints);
    CHECK(arr.is_array());
    CHECK(arr.to_array_int64() == ints);

    std::vector<std::string> strs = {"x", "y"};
    auto sarr = b.make_array_string(strs);
    CHECK(sarr.to_array_string() == strs);
}

// ---- OBJECT TESTS ----

TEST_CASE("baggage: empty object")
{
    auto b = strange::baggage::_make();
    b.from_object();
    CHECK(b.is_object());
    CHECK(b.empty_object());
    CHECK(b.size_object() == 0);
}

TEST_CASE("baggage: object insert and access")
{
    auto b = strange::baggage::_make();
    b.from_object();

    b.insert_object("name", b.make_string("alice"));
    b.insert_object("age", b.make_int64(30));
    b.insert_object("active", b.make_bool(true));

    CHECK(b.size_object() == 3);
    CHECK_FALSE(b.empty_object());

    CHECK(b.contains_object("name"));
    CHECK(b.contains_object("age"));
    CHECK_FALSE(b.contains_object("missing"));

    CHECK(b.get_object("name").to_string() == "alice");
    CHECK(b.get_object("age").to_int64() == 30);
    CHECK(b.get_object("active").to_bool() == true);
}

TEST_CASE("baggage: object set and erase")
{
    auto b = strange::baggage::_make();
    b.from_object();

    b.insert_object("key", b.make_string("original"));
    CHECK(b.get_object("key").to_string() == "original");

    b.set_object("key", b.make_string("updated"));
    CHECK(b.get_object("key").to_string() == "updated");

    b.erase_object("key");
    CHECK_FALSE(b.contains_object("key"));
    CHECK(b.empty_object());
}

TEST_CASE("baggage: nested objects")
{
    auto b = strange::baggage::_make();
    b.from_object();

    auto inner = b.make_object();
    inner.insert_object("x", b.make_int64(1));
    inner.insert_object("y", b.make_int64(2));

    b.insert_object("point", inner);
    CHECK(b.get_object("point").is_object());
    CHECK(b.get_object("point").get_object("x").to_int64() == 1);
    CHECK(b.get_object("point").get_object("y").to_int64() == 2);
}

// ---- SERIALIZATION ROUND-TRIP TESTS ----

TEST_CASE("baggage: seal and unseal")
{
    auto b = strange::baggage::_make();
    b.from_object();
    b.insert_object("key", b.make_string("value"));

    CHECK_FALSE(b.sealed());

    b.seal();
    CHECK(b.sealed());

    b.unseal();
    CHECK_FALSE(b.sealed());
}

TEST_CASE("baggage: JSON round-trip")
{
    auto b = strange::baggage::_make();
    b.from_object();
    b.insert_object("name", b.make_string("test"));
    b.insert_object("count", b.make_int64(42));
    b.insert_object("flag", b.make_bool(true));

    auto json1 = b.to_json();
    CHECK_FALSE(json1.empty());

    auto b2 = strange::baggage::_make();
    b2.from_json(json1);

    auto json2 = b2.to_json();
    CHECK(json1 == json2);
}

TEST_CASE("baggage: binary round-trip")
{
    auto b = strange::baggage::_make();
    b.from_object();
    b.insert_object("x", b.make_double(1.5));
    b.insert_object("items", b.make_array_int64({10, 20, 30}));

    b.seal();
    CHECK(b.sealed());

    auto binary = b.to_binary();
    CHECK_FALSE(binary.empty());

    auto b2 = strange::baggage::_make();
    b2.from_binary(binary);

    auto json1 = b.to_json();
    auto json2 = b2.to_json();
    CHECK(json1 == json2);
}

TEST_CASE("baggage: complex nested round-trip")
{
    auto b = strange::baggage::_make();
    b.from_object();

    auto arr = b.make_array();
    arr.push_back_array(b.make_string("one"));
    arr.push_back_array(b.make_string("two"));

    auto inner = b.make_object();
    inner.insert_object("nested", b.make_bool(true));
    arr.push_back_array(inner);

    b.insert_object("list", arr);
    b.insert_object("count", b.make_int64(3));

    auto json1 = b.to_json();

    auto b2 = strange::baggage::_make();
    b2.from_json(json1);

    CHECK(b2.get_object("count").to_int64() == 3);
    CHECK(b2.get_object("list").is_array());
    CHECK(b2.get_object("list").size_array() == 3);
    CHECK(b2.get_object("list").get_array(0).to_string() == "one");
    CHECK(b2.get_object("list").get_array(2).get_object("nested").to_bool() == true);
}

// ---- ANY-TYPE SERIALIZATION TESTS ----

TEST_CASE("baggage: from_any / to_any with parameter")
{
    auto param = strange::parameter::_make();
    param.type() = "int";
    param.name() = "count";
    param.argument() = "0";

    auto b = strange::baggage::_make();
    b.from_any(param._static<strange::any>());

    auto restored = b.to_any()._static<strange::parameter>();
    CHECK(restored._valid());
    CHECK(restored.type() == "int");
    CHECK(restored.name() == "count");
    CHECK(restored.argument() == "0");
}

TEST_CASE("baggage: from_any / to_any with space")
{
    auto spc = strange::space::_make();
    spc.name() = "example";

    auto abs = strange::abstraction::_make();
    abs.name() = "widget";
    abs.parents().push_back("strange::any");
    spc.abstractions().push_back(abs);

    auto b = strange::baggage::_make();
    b.from_any(spc._static<strange::any>());

    auto json = b.to_json();
    CHECK_FALSE(json.empty());

    auto b2 = strange::baggage::_make();
    b2.from_json(json);

    auto restored = b2.to_any()._static<strange::space>();
    CHECK(restored._valid());
    CHECK(restored.name() == "example");
    REQUIRE(restored.abstractions().size() == 1);
    CHECK(restored.abstractions()[0].name() == "widget");
}

TEST_CASE("baggage: any round-trip through JSON")
{
    auto op = strange::operation::_make();
    op.name() = "process";
    op.constness() = true;
    op.result() = "bool";

    auto p = strange::parameter::_make();
    p.type() = "int";
    p.name() = "x";
    op.parameters().push_back(p);

    auto b = strange::baggage::_make();
    b.from_any(op._static<strange::any>());
    auto json = b.to_json();

    auto b2 = strange::baggage::_make();
    b2.from_json(json);
    auto restored = b2.to_any()._static<strange::operation>();

    CHECK(restored._valid());
    CHECK(restored.name() == "process");
    CHECK(restored.constness() == true);
    CHECK(restored.result() == "bool");
    REQUIRE(restored.parameters().size() == 1);
    CHECK(restored.parameters()[0].type() == "int");
    CHECK(restored.parameters()[0].name() == "x");
}

// ---- STUFF PACK/UNPACK TESTS ----

TEST_CASE("baggage: pack parameter into bag")
{
    auto param = strange::parameter::_make();
    param.type() = "std::string";
    param.name() = "label";
    param.argument() = "\"default\"";
    param.variadic() = true;

    auto b = strange::baggage::_make();
    auto bag = b._static<strange::bag>();
    param.pack(bag);

    CHECK(bag.is_object());
    CHECK(bag.get_object("type").to_string() == "std::string");
    CHECK(bag.get_object("name").to_string() == "label");
    CHECK(bag.get_object("argument").to_string() == "\"default\"");
    CHECK(bag.get_object("variadic").to_bool() == true);
}

TEST_CASE("baggage: unpack parameter from bag")
{
    auto b = strange::baggage::_make();
    b.from_object();
    b.insert_object("type", b.make_string("double"));
    b.insert_object("name", b.make_string("value"));
    b.insert_object("argument", b.make_string("0.0"));
    b.insert_object("variadic", b.make_bool(false));

    auto param = strange::parameter::_make();
    auto bag = b._static<strange::bag>();
    param.unpack(bag);

    CHECK(param.type() == "double");
    CHECK(param.name() == "value");
    CHECK(param.argument() == "0.0");
    CHECK(param.variadic() == false);
}
