#!/bin/bash
# colortable-tput.sh

# Print terminal fg colors in a matrix:
for yy in $(seq 0 15); do   
    for xx in $(seq 0 15); do
        fgc=$(( xx + yy * 16  ))
        fgt=$(tail --bytes=4 <<< "  $fgc" )
        tput setaf $fgc
        echo -n "[$fgt]"; 
    done
    echo
done

echo "To generate color attributes in shell script, select the color value"
echo "and add this:"
echo "  tput setaf nnn"
echo "  ... to change foreground color, or "
echo "  tput setab nnn"
echo "  ... to change background color."
echo 
echo "Reset with:"
echo "  tput sgr0"
echo
