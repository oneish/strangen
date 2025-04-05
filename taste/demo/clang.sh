../../bake/strangen demo__space_meta.h demo__space_meta.cpp
clang++-15 -std=c++17 -Wall demo__space_meta.cpp
./a.out > demo__space.h
clang++-15 -std=c++17 -Wall -I../../../libdart/include -I../../../GSL/include -I../../../rapidjson/include -I../../../sajson/include demo__main.cpp
./a.out
