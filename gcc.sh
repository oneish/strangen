#!/bin/bash
set -e

cd "$(dirname "$0")"

echo "=== Configuring with g++-12 ==="
cmake -B build-gcc -DCMAKE_CXX_COMPILER=g++-12

echo "=== Building ==="
cmake --build build-gcc

echo "=== Running tests ==="
cd build-gcc && ctest --output-on-failure

echo ""
echo "=== All tests passed (g++-12) ==="
