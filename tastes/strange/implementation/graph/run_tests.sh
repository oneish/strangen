#!/bin/bash
set -e

cd "$(dirname "$0")"

echo "=== Building graph tests with g++-12 ==="
g++-12 -std=c++17 -Wall \
    -I../../../../../doctest/doctest \
    -I../../../../../libdart/include \
    -I../../../../../GSL/include \
    -I../../../../../rapidjson/include \
    -I../../../../../sajson/include \
    -I../../../../../stlab-libraries/include \
    -I../../../../../BUILD/include \
    -o test_graph \
    taste__graph_main.cpp \
    -L../../../../../BUILD \
    -lstlab

echo "=== Running graph tests ==="
./test_graph --duration=true

echo ""
echo "=== All graph tests passed ==="
