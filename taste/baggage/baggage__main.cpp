#include "../../sauce/strange/strange.h"
#include "../../sauce/strange/implementation/baggage/strange__implementation__baggage.h"
#include <iostream>
#include <string>
#include <fstream>
#include "../../sauce/strange/comprehension/strange__comprehension__parser.h"

int main()
{
    std::cout << "baggage\n";
{
auto json = dart::parse(R"({"msg":"hello from dart!"})");
std::cout << json["msg"].to_json() << std::endl;
dart::array arr {1, "two", 3.14159, true, nullptr};
std::cout << arr << std::endl;
dart::packet pkt = dart::packet::from_json(R"({"header":{"User-Agent":"ag","Content-Type":"co"}})");
dart::packet header = pkt["header"];
std::cout << header["User-Agent"] << std::endl;
std::cout << header["Content-Type"] << std::endl;
dart::packet obj = dart::packet::make_object("hello", "goodbye", "answer", 42);
obj.add_field("c", 2.99792);
obj.add_field("none", nullptr);
obj.add_field("truth", true);
obj.add_field("lies", false);
obj.add_field("fib", dart::packet::make_array(1, 1, 2, 3, 5, 8, 13));
std::cout << obj.to_json() << std::endl;
auto buffer = obj.finalize().get_bytes();
dart::object typed_obj {"rick", "sanchez", "morty", "smith"};
dart::packet untyped_obj = typed_obj;
dart::object retyped_obj {untyped_obj};
dart::packet untyped_name = typed_obj["rick"];
dart::string typed_name {typed_obj["rick"]};
dart::string retyped_name = typed_obj["rick"].as<dart::string>();
std::string name = typed_obj["rick"].as<std::string>();
auto data = dart::packet::make_object("status", 200, "err", nullptr);
assert(!data.is_finalized());
data.add_field("message", "OK");
assert(!data.is_finalized());
data.finalize(); // <-- could also use data.lower();
assert(data.is_finalized());
// data.add_field("can't", "do it"); // <-- BOOM
gsl::span<gsl::byte const> bytes = data.get_bytes();
// file.write(bytes.data(), bytes.size());
assert(data.is_finalized());
data.definalize(); // <-- could also use data.lift();
assert(!data.is_finalized());
data.add_field("can", "do it"); // <-- no explosion
}
{
// Get a packet using the mutable api.
auto pkt = dart::heap::make_object("hello", "world");
// Do stuff with it.
pkt.add_field("missing", nullptr);
dart::buffer finalized = pkt.finalize();
//assert(finalized.size() == 1U);
assert(finalized["hello"] == "world");
dart::packet copy = pkt;
copy = finalized;
dart::heap unfinalized {finalized};
dart::buffer refinalized {unfinalized};
}
{
// Definitely an object, might be mutable (starts out mutable).
dart::packet::object dynamic {"pi", 3.14159, "c", 2.99792};

// Definitely a mutable object.
dart::heap::object mut {"pi", 3.14159, "c", 2.99792};

// Definitely an immutable object.
dart::buffer::object immut {"pi", 3.14159, "c", 2.99792};

// Definitely an array, might be mutable (starts out mutable).
dart::packet::array dynarr {1, "fish", 2, "fish"};

// You get the point.
dart::heap::array mutarr {"red", "fish", "blue", "fish"};

// This also interplays with conversions as expected
dart::buffer buff = immut;
dart::packet::object dynimmut = immut;
dart::packet pkt = dynimmut;
}

    auto b = strange::baggage::_make();
    std::cout << "sealed:" << b.sealed() << "\n";
    std::cout << "is_null:" << b.is_null() << "\n";
    std::cout << b.to_json() << "\n";
    b.from_bool(true);
    std::cout << b.to_json() << "\n";
    b.from_int64(-123);
    std::cout << b.to_json() << "\n";
    b.from_uint64(456);
    std::cout << b.to_json() << "\n";
    b.from_double(789.1);
    std::cout << b.to_json() << "\n";
    b.from_string("hello");
    std::cout << b.to_json() << "\n";
    b.from_array();
    std::cout << b.to_json() << "\n";
    b.from_object();
    std::cout << b.to_json() << "\n";
    b.seal();
    b.seal();
    auto bin = b.to_binary();
    b.from_null();
    std::cout << "sealed:" << b.sealed() << "\n";
    b.from_binary(bin);
    std::cout << "sealed:" << b.sealed() << "\n";

    // b.insert_object("member", b.make_bool(true));
    std::cout << "sealed:" << b.sealed() << "\n";
    std::cout << b.to_json() << "\n";
    b.unseal();
    b.unseal();
    std::cout << "sealed:" << b.sealed() << "\n";
    std::cout << b.to_json() << "\n";

    char const * const prototype = "../../sauce/strange/meta/strange__space_prototype.h";
    std::ifstream ifs{prototype, std::ios::binary};
    std::istreambuf_iterator<char> it{ifs};
    strange::comprehension::toker toker{it, prototype};
    strange::comprehension::parser parser{toker};
    auto space = parser.parse();
    if (space._valid())
    {
        std::cout << "valid\n";
    }
    else
    {
        return 0;
    }
    b.from_any(space);
    auto json = b.to_json();
    std::cout << "original:\n" << std::hash<std::string>{}(json) << "\n";

    auto c = strange::baggage::_make();
    c.from_json(json);
    std::cout << "clone:\n" << std::hash<std::string>{}(c.to_json()) << "\n";
    auto clone = c.to_any();

    auto d = strange::baggage::_make();
    d.from_any(clone);
    std::cout << "duplicate:\n" << std::hash<std::string>{}(d.to_json()) << "\n";

    auto binary = b.to_binary();
    auto e = strange::baggage::_make();
    e.from_binary(binary);
    auto any = e.to_any();
    std::cout << any._name() << "\n";

    auto f = strange::baggage::_make();
    f.from_any(any);
    std::cout << "from binary:\n" << std::hash<std::string>{}(f.to_json()) << "\n";

    auto spc = strange::space::_make();
    spc.name() = "spc";
    auto abs1 = strange::abstraction::_make();
    abs1.name() = "abs1";
    auto abs2 = strange::abstraction::_make();
    abs2.name() = "abs2";
    auto abs3 = strange::abstraction::_make();
    abs3.name() = "other::abs3";
    spc.abstractions().push_back(abs1);
    spc.abstractions().push_back(abs2);
    spc.inclusions().push_back(abs3);
    spc.inclusions().push_back(abs3);
    auto bag = b.make_any(spc);
    auto jag = bag._dynamic<strange::package>().to_json();
    std::cout << "jag:" << jag << "\n";
    auto pag = b.make_json(jag);
    auto tag = pag._dynamic<strange::bag>().to_any();
    std::cout << tag._dynamic<strange::space>().abstractions()[0]._address() << "\n";
    std::cout << tag._dynamic<strange::space>().abstractions()[1]._address() << "\n";
    std::cout << tag._dynamic<strange::space>().inclusions()[0]._address() << "\n";
    std::cout << tag._dynamic<strange::space>().inclusions()[1]._address() << "\n";

    return 0;
}
