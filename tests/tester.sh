#!/bin/bash

DIR="$(cd "$(dirname "$0")" && pwd)"
MINIRT="$DIR/../minirt"
VALID_DIR="$DIR/valid"
INVALID_DIR="$DIR/invalid"

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

if [ ! -f "$MINIRT" ]; then
    echo -e "${RED}Error: miniRT executable not found at $MINIRT.${NC}"
    exit 1
fi

if [ ! -d "$VALID_DIR" ] || [ ! -d "$INVALID_DIR" ]; then
    echo -e "${RED}Test folders not found. Run ./generate_tests.sh first.${NC}"
    exit 1
fi

echo "======================================"
echo "        MINIRT PARSER TESTER          "
echo "======================================"

echo -e "\nTesting VALID files (Expected exit code 0):"
for file in "$VALID_DIR"/*.rt; do
    [ -e "$file" ] || break
    $MINIRT -t "$file" > /dev/null 2>&1
    status=$?
    if [ $status -eq 0 ]; then
        echo -e "${GREEN}[OK]${NC}   $(basename "$file")"
    else
        echo -e "${RED}[FAIL]${NC} $(basename "$file") (Exited with $status)"
    fi
done

echo -e "\nTesting INVALID files (Expected 'Error' output & exit code != 0):"
for file in "$INVALID_DIR"/*.rt; do
    [ -e "$file" ] || break
    output=$($MINIRT -t "$file" 2>&1)
    status=$?
    if [ $status -ne 0 ] && [[ "$output" == Error* ]]; then
        echo -e "${GREEN}[OK]${NC}   $(basename "$file")"
    else
        echo -e "${RED}[FAIL]${NC} $(basename "$file")"
        echo "       Exit status: $status (Expected != 0)"
    fi
done

echo -e "\n======================================"