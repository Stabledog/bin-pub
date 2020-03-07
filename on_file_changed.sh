#!/bin/bash
#  Run a command when file changes.  Prompts user for
# command (via cat) which can include piping, etc.
#  $1 is the name of the file to be watched

function errExit {
    echo "ERROR: $@" >&2
    exit 1
}

cmd=

function get_cmd_from_user {
    echo  "Enter command to run when $1 changes, use ^D to end." >&2
    echo  "  (command will be eval'ed in shell $BASHPID): " >&2
    cmd="$(cat)"
}

[[ -f $1 ]] || errExit "Can't find file $1"

old_meta="$(ls -l $1)"
new_meta="$old_meta"
get_cmd_from_user weasl.txt

while true; do
    while [[ "$new_meta" == "$old_meta" ]]; do
        sleep 1
        new_meta="$(ls -l $1)"
    done
    eval "$cmd"
    old_meta=new_meta
done

