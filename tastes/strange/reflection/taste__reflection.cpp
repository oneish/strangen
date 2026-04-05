TEST_CASE("reflection: built-in types")
{
    CHECK(strange::reflection<void>::name() == "void");
    CHECK(strange::reflection<bool>::name() == "bool");
    CHECK(strange::reflection<char>::name() == "char");
    CHECK(strange::reflection<int8_t>::name() == "int8_t");
    CHECK(strange::reflection<int16_t>::name() == "int16_t");
    CHECK(strange::reflection<int32_t>::name() == "int32_t");
    CHECK(strange::reflection<int64_t>::name() == "int64_t");
    CHECK(strange::reflection<uint8_t>::name() == "uint8_t");
    CHECK(strange::reflection<uint16_t>::name() == "uint16_t");
    CHECK(strange::reflection<uint32_t>::name() == "uint32_t");
    CHECK(strange::reflection<uint64_t>::name() == "uint64_t");
    CHECK(strange::reflection<float>::name() == "float");
    CHECK(strange::reflection<double>::name() == "double");
    CHECK(strange::reflection<std::string>::name() == "std::string");
}

TEST_CASE("reflection: unknown type returns ???")
{
    struct unknown_type {};
    CHECK(strange::reflection<unknown_type>::name() == "???");
}

TEST_CASE("reflection: std::vector<T>")
{
    CHECK(strange::reflection<std::vector<int32_t>>::name() == "std::vector<int32_t>");
    CHECK(strange::reflection<std::vector<bool>>::name() == "std::vector<bool>");
}

TEST_CASE("reflection: strange types")
{
    CHECK(strange::reflection<strange::any>::name() == "strange::any");
    CHECK(strange::reflection<strange::stuff>::name() == "strange::stuff");
    CHECK(strange::reflection<strange::parameter>::name() == "strange::parameter");
    CHECK(strange::reflection<strange::operation>::name() == "strange::operation");
    CHECK(strange::reflection<strange::abstraction>::name() == "strange::abstraction");
    CHECK(strange::reflection<strange::space>::name() == "strange::space");
    CHECK(strange::reflection<strange::token>::name() == "strange::token");
}

TEST_CASE("reflection: nested vector")
{
    auto name = strange::reflection<std::vector<std::vector<int32_t>>>::name();
    CHECK(name == "std::vector<std::vector<int32_t>>");
}
