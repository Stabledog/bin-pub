#!/bin/bash

# filelist_append.sh
#
#  Using the same logic as vimgit, but the output gets merged into to ./.filelist
#
EDITOR=echo
sourceMe=1 source ~/bin/vimgit 
do_vimgit $* | tr ' ' '\n' > ./.filelist-cur
if [[ -f ./.filelist ]]; then
    # Cat and sort/unique:
    cat ./.filelist ./.filelist-cur | sort -u > ./.filelist-tmp
    mv ./.filelist-tmp ./.filelist
else
    mv ./.filelist-cur ./.filelist
fi

# Kill temp files
rm ./.filelist-cur ./.filelist-tmp 2>/dev/null




