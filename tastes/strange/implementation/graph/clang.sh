#!/bin/bash
set -e

cd "$(dirname "$0")"

echo "=== Building currants tests with clang++-15 ==="
clang++-15 -std=c++17 -Wall \
    -I../../../../../doctest/doctest \
    -I../../../../../libdart/include \
    -I../../../../../GSL/include \
    -I../../../../../rapidjson/include \
    -I../../../../../sajson/include \
    -I../../../../../stlab-libraries/include \
    -I../../../../../BUILD/include \
    -o test_currants_clang \
    tastes__currants_main.cpp \
    -L../../../../../BUILD \
    -lstlab

echo "=== Running currants tests ==="
./test_currants_clang --duration=true

echo ""
echo "=== All currants tests passed ==="
