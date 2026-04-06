#!/bin/bash
set -e

cd "$(dirname "$0")"

echo "=== Configuring with g++-12 ==="
cmake -B bake-gcc -DCMAKE_CXX_COMPILER=g++-12

echo "=== Baking ==="
cmake --build bake-gcc

echo "=== Running tests ==="
cd bake-gcc && ctest --output-on-failure

echo ""
echo "=== All tests passed (g++-12) ==="
