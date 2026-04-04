TEST_CASE("vector<int>: default construction")
{
    strange::vector<int> v;
    CHECK_FALSE(v._something());
}

TEST_CASE("vector<int>: _make creates valid empty vector")
{
    auto v = strange::vector<int>::_make();
    CHECK(v._something());
    CHECK(v._valid());
    CHECK(v.empty());
    CHECK(v.size() == 0);
}

TEST_CASE("vector: push_back and access")
{
    auto v = strange::vector<int>::_make();
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    CHECK(v.size() == 3);
    CHECK_FALSE(v.empty());
    CHECK(v[0] == 10);
    CHECK(v[1] == 20);
    CHECK(v[2] == 30);
    CHECK(v.front() == 10);
    CHECK(v.back() == 30);
    CHECK(v.at(1) == 20);
}

TEST_CASE("vector<parameter>: works with strange types")
{
    auto v = strange::vector<strange::parameter>::_make();
    auto p = strange::parameter::_make();
    p.name() = "x";
    v.push_back(p);
    CHECK(v.size() == 1);
    CHECK(v[0].name() == "x");
}

TEST_CASE("vector: range-based for loop")
{
    auto v = strange::vector<int>::_make();
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    int sum = 0;
    for (auto const & val : v)
    {
        sum += val;
    }
    CHECK(sum == 6);
}
