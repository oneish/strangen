#!/bin/bash
set -e

cd "$(dirname "$0")"

ACTION="${1:-build}"

if [[ "$ACTION" == "clean" || "$ACTION" == "rebuild" ]]; then
    echo "=== Cleaning bake-clang ==="
    rm -rf bake-clang
fi

if [[ "$ACTION" == "build" || "$ACTION" == "rebuild" ]]; then
    echo "=== Configuring with clang++-15 ==="
    cmake -B bake-clang -DCMAKE_CXX_COMPILER=clang++-15 -DSTRANGEN_ENABLE_STLAB=OFF

    echo "=== Baking ==="
    cmake --build bake-clang

    echo "=== Running tests ==="
    cd bake-clang && ctest --output-on-failure

    echo ""
    echo "=== All tests passed (clang++-15) ==="
elif [[ "$ACTION" != "clean" ]]; then
    echo "Usage: $0 [build|clean|rebuild]" >&2
    exit 1
fi
