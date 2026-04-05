#!/bin/bash
set -e

cd "$(dirname "$0")"

bash gcc.sh
echo ""
bash clang.sh
