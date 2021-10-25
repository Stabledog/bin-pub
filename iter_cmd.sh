#!/bin/bash
# Gets a command (possibly multiline) from stdin and
# executes it once for each command line arg.
# Sets ITER_NDX to 1..n for each iteration

iter_cmd() {
    [[ $# -eq 0 ]] && { false; return; }
    echo -e "\033[;33mArgs: [\033[;0m$@\033[33m]\0330m" >&2
    [[ -t 0 ]] && {
        echo -e "\033[;32mEnter command(s) and then ^D:\033[;0m" >&2
    }
    local cmd="$(cat)"
    export ITER_NDX=1
    local ITER_ARGS=( $@ )
    for arg in "${ITER_ARGS[@]}"; do
        #read -p "$ITER_NDX[${arg}] iter>"
        set -- ${arg}
        eval "$cmd"
        (( ITER_NDX++ ))
    done
}

[[ -z $sourceMe ]] && {
     iter_cmd "$@"
}
