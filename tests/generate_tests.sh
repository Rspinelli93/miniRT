#!/bin/bash

DIR="$(cd "$(dirname "$0")" && pwd)"

# If -g flag is passed, delete tests and exit
if [ "$1" == "-g" ]; then
    echo "Deleting test folders..."
    rm -rf "$DIR/valid" "$DIR/invalid"
    exit 0
fi

echo "Generating test directories..."
rm -rf "$DIR/valid" "$DIR/invalid"
mkdir -p "$DIR/valid" "$DIR/invalid"

# ==========================================
# VALID TESTS (5)
# ==========================================
cat << 'EOF' > "$DIR/valid/01_minimal.rt"
A 0.2 255,255,255
C -50,0,20 0,0,1 70
L -40,0,30 0.7 255,255,255
pl 0,0,0 0,1.0,0 255,0,225
sp 0,0,20 20 255,0,0
cy 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255
EOF

cat << 'EOF' > "$DIR/valid/02_extreme_spacing.rt"

A  	 0.2		 255,255,255	 

C	 -50,0,20	  0,0,1 	70

L  -40,0,30   0.7  255,255,255

sp		0,0,20 	 20 	 255,0,0

EOF

cat << 'EOF' > "$DIR/valid/03_shuffled.rt"
sp 0,0,20 20 255,0,0
L -40,0,30 0.7 255,255,255
cy 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255
C -50,0,20 0,0,1 70
pl 0,0,0 0,1.0,0 255,0,225
A 0.2 255,255,255
EOF

cat << 'EOF' > "$DIR/valid/04_multiple_shapes.rt"
A 0.2 255,255,255
C -50,0,20 0,0,1 70
L -40,0,30 0.7 255,255,255
sp 0,0,20 20 255,0,0
sp 10,10,10 5.5 0,255,0
pl 0,0,0 0,1,0 255,255,255
cy 0,0,0 0,1,0 10 20 255,255,255
EOF

cat << 'EOF' > "$DIR/valid/05_edge_values.rt"
A 0.0 0,0,0
C 0,0,0 0,1,0 180
L 0,0,0 1.0 255,255,255
sp 0,0,0 0.0 255,255,255
EOF

# ==========================================
# INVALID TESTS (40)
# ==========================================
# Setup a valid base to copy for single-line errors
BASE="A 0.2 255,255,255\nC -50,0,20 0,0,1 70\nL -40,0,30 0.7 255,255,255"

# 1-5: Duplicates & Missing Mandatory
echo -e "A 0.2 255,255,255\n$BASE" > "$DIR/invalid/01_dup_A.rt"
echo -e "C 0,0,0 0,1,0 90\n$BASE" > "$DIR/invalid/02_dup_C.rt"
echo -e "L 0,0,0 0.5 255,255,255\n$BASE" > "$DIR/invalid/03_dup_L.rt"
echo -e "C -50,0,20 0,0,1 70\nL -40,0,30 0.7 255,255,255" > "$DIR/invalid/04_missing_A.rt"
echo -e "A 0.2 255,255,255\nC -50,0,20 0,0,1 70" > "$DIR/invalid/05_missing_L.rt"

# 6-12: Bounds & Limits (Colors, FOV, Ratio)
echo -e "$BASE\nsp 0,0,0 20 256,0,0" > "$DIR/invalid/06_rgb_high.rt"
echo -e "$BASE\nsp 0,0,0 20 0,-1,0" > "$DIR/invalid/07_rgb_neg.rt"
echo -e "A 1.1 255,255,255\nC -50,0,20 0,0,1 70\nL -40,0,30 0.7 255,255,255" > "$DIR/invalid/08_ratio_high.rt"
echo -e "A -0.1 255,255,255\nC -50,0,20 0,0,1 70\nL -40,0,30 0.7 255,255,255" > "$DIR/invalid/09_ratio_neg.rt"
echo -e "A 0.2 255,255,255\nC -50,0,20 0,0,1 181\nL -40,0,30 0.7 255,255,255" > "$DIR/invalid/10_fov_high.rt"
echo -e "A 0.2 255,255,255\nC -50,0,20 0,0,1 -1\nL -40,0,30 0.7 255,255,255" > "$DIR/invalid/11_fov_neg.rt"
echo -e "$BASE\npl 0,0,0 0,2.0,0 255,255,255" > "$DIR/invalid/12_vector_bounds.rt"

# 13-20: Missing or Extra Parameters
echo -e "$BASE\nsp 0,0,0 255,0,0" > "$DIR/invalid/13_sp_missing_param.rt"
echo -e "$BASE\npl 0,0,0 255,255,255" > "$DIR/invalid/14_pl_missing_param.rt"
echo -e "$BASE\ncy 0,0,0 0,1,0 10 255,255,255" > "$DIR/invalid/15_cy_missing_param.rt"
echo -e "$BASE\nsp 0,0,0 20 255,0,0 100" > "$DIR/invalid/16_sp_extra_param.rt"
echo -e "$BASE\npl 0,0,0 0,1,0 255,255,255 10" > "$DIR/invalid/17_pl_extra_param.rt"
echo -e "A 0.2 255,255,255 100\nC -50,0,20 0,0,1 70\nL -40,0,30 0.7 255,255,255" > "$DIR/invalid/18_A_extra_param.rt"
echo -e "A 0.2\nC -50,0,20 0,0,1 70\nL -40,0,30 0.7 255,255,255" > "$DIR/invalid/19_A_missing_param.rt"
echo -e "$BASE\ncy 0,0,0 0,1,0 10 20 255,255,255 extra" > "$DIR/invalid/20_cy_extra_param.rt"

# 21-30: Comma and Vector Formatting limits
echo -e "$BASE\nsp 0,,0 20 255,0,0" > "$DIR/invalid/21_double_comma.rt"
echo -e "$BASE\nsp ,0,0 20 255,0,0" > "$DIR/invalid/22_leading_comma.rt"
echo -e "$BASE\nsp 0,0, 20 255,0,0" > "$DIR/invalid/23_trailing_comma.rt"
echo -e "$BASE\nsp 0,0,0,0 20 255,0,0" > "$DIR/invalid/24_four_commas.rt"
echo -e "A 0.2 255.0,255,255\nC -50,0,20 0,0,1 70\nL -40,0,30 0.7 255,255,255" > "$DIR/invalid/25_float_in_rgb.rt"
echo -e "$BASE\nsp 0,0,0 20.5.5 255,0,0" > "$DIR/invalid/26_double_dot.rt"
echo -e "$BASE\nsp 0,0,0 20 255, 0,0" > "$DIR/invalid/27_space_after_comma.rt"
echo -e "$BASE\nsp 0, 0, 0 20 255,0,0" > "$DIR/invalid/28_spaces_in_vector.rt"
echo -e "A 0.2 255,255,255\nC-50,0,20 0,0,1 70\nL -40,0,30 0.7 255,255,255" > "$DIR/invalid/29_no_space_after_id.rt"
echo -e "A 0.2 255,255,255\nC -50,0,20 0,0,1 70\nL-40,0,30 0.7 255,255,255" > "$DIR/invalid/30_no_space_after_id_L.rt"

# 31-36: Identifier casing and typos
echo -e "a 0.2 255,255,255\nC -50,0,20 0,0,1 70\nL -40,0,30 0.7 255,255,255" > "$DIR/invalid/31_lowercase_a.rt"
echo -e "A 0.2 255,255,255\nc -50,0,20 0,0,1 70\nL -40,0,30 0.7 255,255,255" > "$DIR/invalid/32_lowercase_c.rt"
echo -e "A 0.2 255,255,255\nC -50,0,20 0,0,1 70\nl -40,0,30 0.7 255,255,255" > "$DIR/invalid/33_lowercase_l.rt"
echo -e "$BASE\nSP 0,0,0 20 255,0,0" > "$DIR/invalid/34_uppercase_sp.rt"
echo -e "$BASE\nCY 0,0,0 0,1,0 10 20 255,255,255" > "$DIR/invalid/35_uppercase_cy.rt"
echo -e "$BASE\nspp 0,0,0 20 255,0,0" > "$DIR/invalid/36_typo_id.rt"

# 37-40: Garbage input & Empty files
echo "" > "$DIR/invalid/37_empty_file.rt"
echo "    " > "$DIR/invalid/38_spaces_only.rt"
echo -e "$BASE\n\n\n   \n\n@sp 0,0,0 20 255,0,0" > "$DIR/invalid/39_garbage_char.rt"
echo -e "$BASE\nsp 0,0,0 20 255,0,0\nhello world" > "$DIR/invalid/40_random_text.rt"

echo "Generated 5 valid and 40 invalid tests."