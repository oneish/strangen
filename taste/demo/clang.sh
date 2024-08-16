../../bake/strangen demo__space_meta.h demo__space_meta.cpp
clang++-14 -std=c++17 -Wall demo__space_meta.cpp
./a.out > demo__space.h
clang++-14 -std=c++17 -Wall demo__main.cpp
./a.out
