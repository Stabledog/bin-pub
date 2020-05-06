#!/bin/bash
# colortable-tput.sh

# Print terminal fg colors in a matrix:
for yy in $(seq 0 15); do   
    for xx in $(seq 0 15); do
        fgc=$(( xx + yy * 16  ))
        fgt=$(tail -c 4 <<< "  $fgc" )
        tput setaf $fgc
        echo -n "[$fgt]"; 
    done
    echo
done
