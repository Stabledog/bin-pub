#!/bin/bash

# Test your password entry skills.

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
				echo " correct"
			else
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

