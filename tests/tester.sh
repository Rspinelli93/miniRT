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

get_expected_error() {
	local file=$(basename "$1")
	case "$file" in
		01_dup_A*|02_dup_C*|03_dup_L*|38_*|29_*|30_*|31_*|32_*|33_*)
			echo "Error\nWrong A, C, or L count" ;;
		04_missing_A*|05_missing_L*)
			echo "Error\nWrong A, C, or L count" ;;
		06_rgb_high*|07_rgb_neg*)
			echo "Error\nWrong Sphere line." ;;
		08_ratio_high*|09_ratio_neg*)
			echo "Error\nWrong Ambient Light line." ;;
		10_fov_high*|11_fov_neg*)
			echo "Error\nWrong Camera line." ;;
		12_vector_bounds*)
			echo "Error\nWrong Plane line." ;;
		13_sp_missing*|16_sp_extra*|21_double*|22_leading*|23_trailing*|24_four*|26_double*|27_space_after*|28_spaces_in*)
			echo "Error\nWrong Sphere line." ;;
		14_pl_missing*|17_pl_extra*)
			echo "Error\nWrong Plane line." ;;
		15_cy_missing*|20_cy_extra*)
			echo "Error\nWrong Cylinder line." ;;
		18_A_extra*|19_A_missing*|25_float*)
			echo "Error\nWrong Ambient Light line." ;;
		34_*|35_*|36_*|39_*|40_*)
			echo "Error\nLine should start with A, C, L, sp, pl or cy." ;;
		37_*)
			echo "Error\nEmpty or wrong format doc" ;;
		*)
			echo "Error" ;;
	esac
}

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
	output=$(valgrind --leak-check=full --quiet --log-file="$VALGRIND_LOG" "$MINIRT" -t "$file" 2>&1)
	status=$?
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
		echo "       Got: $output"
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
	expected=$(get_expected_error "$file")
	expected_expanded=$(echo -e "$expected")
	if [ $status -ne 0 ] && [ "$output" = "$expected_expanded" ]; then
		if [ $has_leak -eq 1 ]; then
			echo -e "${YELLOW}[OK (LEAK)]${NC} $(basename "$file")"
		else
			echo -e "${GREEN}[OK]${NC}        $(basename "$file")"
		fi
	else
		echo -e "${RED}[FAIL]${NC}      $(basename "$file")"
		echo "       Exit: $status | Expected: $(echo -e "$expected")"
		echo "       Got:  $output"
	fi
done

echo -e "\n======================================"