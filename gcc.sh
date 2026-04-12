#!/bin/bash
set -e

cd "$(dirname "$0")"

ACTION="${1:-build}"

if [[ "$ACTION" == "clean" || "$ACTION" == "rebuild" ]]; then
    echo "=== Cleaning bake-gcc ==="
    rm -rf bake-gcc
fi

if [[ "$ACTION" == "build" || "$ACTION" == "rebuild" ]]; then
    echo "=== Configuring with g++-12 ==="
    cmake -B bake-gcc -DCMAKE_CXX_COMPILER=g++-12

    echo "=== Baking ==="
    cmake --build bake-gcc

    echo "=== Running tests ==="
    cd bake-gcc && ctest --output-on-failure

    echo ""
    echo "=== All tests passed (g++-12) ==="
elif [[ "$ACTION" != "clean" ]]; then
    echo "Usage: $0 [build|clean|rebuild]" >&2
    exit 1
fi
