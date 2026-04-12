TEST_CASE("hash_init: produces non-zero hash for non-empty string")
{
    auto h = strange::hash_init(std::string("hello"));
    CHECK(h != 0);
}

TEST_CASE("hash_init: same value produces same hash")
{
    auto h1 = strange::hash_init(42);
    auto h2 = strange::hash_init(42);
    CHECK(h1 == h2);
}

TEST_CASE("hash_init: different values produce different hashes")
{
    auto h1 = strange::hash_init(std::string("hello"));
    auto h2 = strange::hash_init(std::string("world"));
    CHECK(h1 != h2);
}

TEST_CASE("hash_combine: modifies seed")
{
    std::size_t seed = strange::hash_init(std::string("hello"));
    auto original = seed;
    strange::hash_combine(seed, std::string("world"));
    CHECK(seed != original);
}

TEST_CASE("hash_combine: order matters")
{
    std::size_t seed1 = strange::hash_init(std::string("a"));
    strange::hash_combine(seed1, std::string("b"));

    std::size_t seed2 = strange::hash_init(std::string("b"));
    strange::hash_combine(seed2, std::string("a"));

    CHECK(seed1 != seed2);
}

TEST_CASE("hash_range: same vectors produce same hash")
{
    std::vector<std::string> v1 = {"a", "b", "c"};
    std::vector<std::string> v2 = {"a", "b", "c"};
    CHECK(strange::hash_range(v1) == strange::hash_range(v2));
}

TEST_CASE("hash_range: different vectors produce different hashes")
{
    std::vector<std::string> v1 = {"a", "b", "c"};
    std::vector<std::string> v2 = {"a", "b", "d"};
    CHECK(strange::hash_range(v1) != strange::hash_range(v2));
}

TEST_CASE("hash_range: different lengths produce different hashes")
{
    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = {1, 2};
    CHECK(strange::hash_range(v1) != strange::hash_range(v2));
}

TEST_CASE("hash_range: empty vector produces consistent hash")
{
    std::vector<int> v1;
    std::vector<int> v2;
    CHECK(strange::hash_range(v1) == strange::hash_range(v2));
}
