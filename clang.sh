#!/bin/bash
set -e

cd "$(dirname "$0")"

echo "=== Configuring with clang++-15 ==="
cmake -B build-clang -DCMAKE_CXX_COMPILER=clang++-15

echo "=== Building ==="
cmake --build build-clang

echo "=== Running tests ==="
cd build-clang && ctest --output-on-failure

echo ""
echo "=== All tests passed (clang++-15) ==="
