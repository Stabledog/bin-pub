#!/bin/bash
#  Usage:  [-] file-to-watch
#  If '-' is the first argument, command will be read from stdin with
#  no prompting.  Otherwise we'll prompt the user for the command to
#  run when file-to-watch metadata changes (mode, size, timestamp, existence)
#
#  Because we treat existence like another bit of metadata, we'll trigger if
#  the file comes into or goes out of existence, just as if the timestamp or
#  size had changed.  This means if you misspell the filename, you'll have
#  a hidden problem.

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

function file_metadata {
    ls -l --full-time $1 2>&1
}

if [[ "$1" == - ]]; then
    # Get command from stdin with no user prompt:
    shift
    cmd="$(cat)"
else
    # Prompt user for command:
    get_cmd_from_user $1
fi


old_meta="$(file_metadata $1)"
new_meta="$old_meta"

while true; do
    while [[ "$new_meta" == "$old_meta" ]]; do
        sleep 1
        new_meta="$(file_metadata $1)"
    done
    eval "$cmd"
    old_meta="$new_meta"
done

