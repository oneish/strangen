#!/bin/bash
set -e

cd "$(dirname "$0")"

ACTION="${1:-build}"

bash gcc.sh "$ACTION"
echo ""
bash clang.sh "$ACTION"
