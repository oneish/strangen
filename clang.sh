#!/bin/bash
set -e

cd "$(dirname "$0")"

echo "=== Configuring with clang++-15 ==="
cmake -B bake-clang -DCMAKE_CXX_COMPILER=clang++-15 -DSTRANGEN_ENABLE_STLAB=OFF

echo "=== Baking ==="
cmake --build bake-clang

echo "=== Running tests ==="
cd bake-clang && ctest --output-on-failure

echo ""
echo "=== All tests passed (clang++-15) ==="
