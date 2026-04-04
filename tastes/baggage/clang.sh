#!/bin/bash
set -e

cd "$(dirname "$0")"

echo "=== Building baggage tests with clang++-15 ==="
clang++-15 -std=c++17 -Wall \
    -I../../../doctest/doctest \
    -I../../../libdart/include \
    -I../../../GSL/include \
    -I../../../rapidjson/include \
    -I../../../sajson/include \
    -o test_baggage_clang \
    tastes__baggage_main.cpp

echo "=== Running baggage tests ==="
./test_baggage_clang --duration=true

echo ""
echo "=== All baggage tests passed ==="
