#!/bin/bash
set -e

cd "$(dirname "$0")"

echo "=== Building graph tests with clang++-15 ==="
clang++-15 -std=c++17 -Wall \
    -I../../../../../doctest/doctest \
    -I../../../../../libdart/include \
    -I../../../../../GSL/include \
    -I../../../../../rapidjson/include \
    -I../../../../../sajson/include \
    -I../../../../../stlab-libraries/include \
    -I../../../../../BUILD/include \
    -o test_graph_clang \
    taste__graph_main.cpp \
    -L../../../../../BUILD \
    -lstlab

echo "=== Running graph tests ==="
./test_graph_clang --duration=true

echo ""
echo "=== All graph tests passed ==="
