#!/bin/bash

# cron-git-daily-maint.sh
#
#   Runs daily as a cron job to do git maintenance my git repositories.
#
#
HOME=/home/lmatheson4
export PATH=$PATH:/opt/swt/bin:$HOME/bin

myCronLogfile=$HOME/tmp/cron-git-daily-maint.log

export writeStderr
[[ -z $writeStderr ]] && writeStderr=false  # Used for debuggging only.

function errExit {
    if $writeStderr; then
        echo "ERROR: $* " >&2
    fi
    echo "ERROR: $* " >> $myCronLogfile
}

function dailyAutocommits {
    # List of dirs to get auto-commits
    echo "$HOME/journal"
    echo "$HOME/bin"
    echo "$HOME/mars-overlay"
    echo "$HOME/.vim"
    echo "$HOME/.taskrc"
    echo "$HOME/ksymkit"
}

function autoCommit {
    # Auto-commit a directory to its own repo
    local xdir="$1"
    (
        cd $xdir || errExit "Bad directory in autoCommit: $xdir"
        echo "
        [[ $(date): Starting autoCommit for $PWD : ]] " >> $myCronLogfile
        git add . >> $myCronLogfile || errExit "git add failed in autoCommit for $xdir"

        git commit . -m "Sync by ~/bin/cron-git-daily-maint.sh"  >> $myCronLogfile || errExit "git commit failed in autoCommit for $xdir"

    ) || { false; return; }
    
}


function doAllCommits {
    for xdir in $(dailyAutocommits); do
        autoCommit "$xdir"; 
    done
}


doAllCommits
