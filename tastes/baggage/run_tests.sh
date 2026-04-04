#!/bin/bash
set -e

cd "$(dirname "$0")"

echo "=== Building baggage tests with g++-12 ==="
g++-12 -std=c++17 -Wall \
    -I../../../doctest/doctest \
    -I../../../libdart/include \
    -I../../../GSL/include \
    -I../../../rapidjson/include \
    -I../../../sajson/include \
    -o test_baggage \
    tastes__baggage_main.cpp

echo "=== Running baggage tests ==="
./test_baggage --duration=true

echo ""
echo "=== All baggage tests passed ==="
