g++-12 -std=c++17 -Wall \
-I../../../libdart/include \
-I../../../GSL/include \
-I../../../rapidjson/include \
-I../../../sajson/include \
-I../../../stlab-libraries/include \
-I../../../BUILD/include \
currant__main.cpp \
-L../../../BUILD \
-lstlab
./a.out
