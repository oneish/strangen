#!/bin/bash
set -e

cd "$(dirname "$0")"

ACTION="${1:-}"
SNACKS=(baggage currants demo example)
COMPILERS=(gcc clang)
FAILED=0

for snack in "${SNACKS[@]}"; do
    for compiler in "${COMPILERS[@]}"; do
        if [[ "$snack" == "currants" && "$compiler" == "clang" ]]; then
            continue
        fi

        exe="bake-${compiler}/snacks/${snack}/${snack}"

        if [[ ! -x "$exe" ]]; then
            echo "SKIP  ${snack} (${compiler}) - not built"
            continue
        fi

        if [[ "$ACTION" == "purge" ]]; then
            echo "=== ${snack} (${compiler}) ==="
            if (cd "snacks/${snack}" && "../../${exe}"); then
                echo ""
            else
                echo "FAILED"
                FAILED=1
            fi
        else
            echo -n "RUN   ${snack} (${compiler}) ... "
            if (cd "snacks/${snack}" && "../../${exe}") > /dev/null 2>&1; then
                echo "ok"
            else
                echo "FAILED"
                FAILED=1
            fi
        fi
    done
done

if [[ "$FAILED" -ne 0 ]]; then
    echo ""
    echo "=== Some snacks failed ==="
    exit 1
else
    echo ""
    echo "=== All snacks passed ==="
fi
