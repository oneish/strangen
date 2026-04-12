#!/bin/bash
set -e

cd "$(dirname "$0")"

ACTION="${1:-build}"

if [[ "$ACTION" == "clean" || "$ACTION" == "rebuild" ]]; then
    echo "=== Cleaning stlab build ==="
    rm -rf ../BUILD
fi

if [[ "$ACTION" == "build" || "$ACTION" == "rebuild" ]]; then
    echo "=== Building stlab ==="
    cmake -S ../stlab-libraries -B ../BUILD \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_CXX_COMPILER=/usr/bin/g++-12 \
        -DCMAKE_CXX_STANDARD=17 \
        -DBUILD_TESTING=OFF
    cmake --build ../BUILD
    echo ""
    echo "=== stlab built ==="
elif [[ "$ACTION" != "clean" ]]; then
    echo "Usage: $0 [build|clean|rebuild]" >&2
    exit 1
fi
