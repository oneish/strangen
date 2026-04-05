#!/bin/bash
set -e

cd "$(dirname "$0")"

echo "========================================="
echo "  Running all tests with clang++-15"
echo "========================================="
echo ""

bash strange/clang.sh
echo ""

bash strange/implementation/baggage/clang.sh
echo ""

bash strange/implementation/graph/clang.sh
echo ""

echo "========================================="
echo "  All tests passed (clang++-15)"
echo "========================================="
