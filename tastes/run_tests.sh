#!/bin/bash
set -e

cd "$(dirname "$0")"

echo "=== Building tests with g++-12 ==="
g++-12 -std=c++17 -Wall \
    -I../../doctest/doctest \
    -o test_gcc \
    tastes__main.cpp

echo "=== Running tests (g++-12 build) ==="
./test_gcc --duration=true

echo ""
echo "=== All tests passed ==="
