#!/bin/bash

DIR="$(cd "$(dirname "$0")" && pwd)"
MINIRT="$DIR/../miniRT"
VALID_DIR="$DIR/valid"
INVALID_DIR="$DIR/invalid"
VALGRIND_LOG="$DIR/valgrind.log"

GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
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
    
    # Run with Valgrind quietly. Normal output is captured, memory errors go to log file.
    output=$(valgrind --leak-check=full --quiet --log-file="$VALGRIND_LOG" "$MINIRT" -t "$file" 2>&1)
    status=$?
    
    # If the log file has a size greater than 0, Valgrind found a leak
    if [ -s "$VALGRIND_LOG" ]; then
        has_leak=1
    else
        has_leak=0
    fi
    rm -f "$VALGRIND_LOG"

    if [ $status -eq 0 ]; then
        if [ $has_leak -eq 1 ]; then
            echo -e "${YELLOW}[OK (LEAK)]${NC} $(basename "$file")"
        else
            echo -e "${GREEN}[OK]${NC}        $(basename "$file")"
        fi
    else
        echo -e "${RED}[FAIL]${NC}      $(basename "$file") (Exited with $status)"
    fi
done

echo -e "\nTesting INVALID files (Expected 'Error' output & exit code != 0):"
for file in "$INVALID_DIR"/*.rt; do
    [ -e "$file" ] || break
    
    output=$(valgrind --leak-check=full --quiet --log-file="$VALGRIND_LOG" "$MINIRT" -t "$file" 2>&1)
    status=$?
    
    if [ -s "$VALGRIND_LOG" ]; then
        has_leak=1
    else
        has_leak=0
    fi
    rm -f "$VALGRIND_LOG"

    if [ $status -ne 0 ] && [[ "$output" == Error* ]]; then
        if [ $has_leak -eq 1 ]; then
            echo -e "${YELLOW}[OK (LEAK)]${NC} $(basename "$file")"
        else
            echo -e "${GREEN}[OK]${NC}        $(basename "$file")"
        fi
    else
        echo -e "${RED}[FAIL]${NC}      $(basename "$file")"
        echo "       Exit status: $status (Expected != 0)"
    fi
done

echo -e "\n======================================"