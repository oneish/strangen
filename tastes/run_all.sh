#!/bin/bash
set -e

cd "$(dirname "$0")"

bash run_all_gcc.sh
echo ""
bash run_all_clang.sh
