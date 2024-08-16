../../bake/strangen demo__space_meta.h demo__space_meta.cpp
g++-11 -std=c++17 -Wall demo__space_meta.cpp
./a.out > demo__space.h
g++-11 -std=c++17 -Wall demo__main.cpp
./a.out
