#!/bin/bash
set -e

cd "$(dirname "$0")"

echo "========================================="
echo "  Running all tests with g++-12"
echo "========================================="
echo ""

bash strange/run_tests.sh
echo ""

bash strange/implementation/baggage/run_tests.sh
echo ""

bash strange/implementation/graph/run_tests.sh
echo ""

echo "========================================="
echo "  All tests passed (g++-12)"
echo "========================================="
