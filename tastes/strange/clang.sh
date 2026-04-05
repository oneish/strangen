#!/bin/bash
set -e

cd "$(dirname "$0")"

echo "=== Building tests with clang++-15 ==="
clang++-15 -std=c++17 -Wall \
    -I../../../doctest/doctest \
    -o test_clang \
    taste__main.cpp

echo "=== Running tests (clang++-15 build) ==="
./test_clang --duration=true

echo ""
echo "=== All tests passed ==="
