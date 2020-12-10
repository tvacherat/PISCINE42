#!/bin/sh

grep -v '^#' /etc/passwd | cut -d : -f1 | sed -n 'n;p' | rev | sort -r | sed -n "${FT_LINE1},${FT_LINE2}p" | tr '\n' ',' | sed 's/,/, /g' | sed 's/$/,/' | sed 's/, ,/./' | tr -d "\n"
