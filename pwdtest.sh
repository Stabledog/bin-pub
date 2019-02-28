#!/bin/bash

# Test your password entry skills.
print_after=false # -p: should we print the pwd after testing?

function parseArgs {
    while [[ ! -z $1 ]]; do
        case $1 in
            -p)
                print_after=true
                ;;
            *)
                pwd=$1
                ;;
        esac
        shift
    done
}

parseArgs "$@"

pwd=$1 
[[ -z $pwd ]] && { echo "Password should be \$1"; exit 1; }
clear

for i in {1..999999}
do # Outer loop:
	echo -n "$i:" 
	while true; do
		read -n1 -s  nextCh
		if [[ -z $nextCh ]]; then
			# End of entry: test it.
			if [ "$entry" == "$pwd" ]; then
			    if $print_after; then
			        echo -n "Yes, [$entry] is"
			    fi
				echo " correct"
			else
			    if $print_after; then
			        echo -n "No, [$entry] should be [$pwd]"
			    fi
				echo "  ERROR"
			fi
			entry=""
			break
		else
			echo -n "*"
			entry="${entry}${nextCh}"
		fi
	done
done

