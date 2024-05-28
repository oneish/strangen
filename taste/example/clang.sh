../../bake/strangen example__space_transformation_1.h example__space_transformation_2.cpp
clang++-14 -std=c++17 -Wall example__space_transformation_2.cpp
./a.out > example__space_transformation_3.h
clang++-14 -std=c++17 -Wall example__type_erasure_main.cpp
./a.out
