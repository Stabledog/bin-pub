#!/bin/bash
# Gets a command (possibly multiline) from stdin and
# executes it once for each command line arg.
# Sets ITER_NDX to 1..n for each iteration
#

iter_cmd() {
    [[ $# -eq 0 ]] && { false; return; }
    echo "Args: [$@]" >&2
    echo "Enter command(s) and then ^D:" >&2
    local cmd="$(cat)"
    export ITER_NDX=1
    local ITER_ARGS=( $@ )
    for arg in "${ITER_ARGS[@]}"; do
        read -p "$ITER_NDX[${arg}] iter>"
        set ${arg}
        eval "$cmd"
        (( ITER_NDX++ ))
    done
}

[[ -z $sourceMe ]] && {
     iter_cmd "$@"
}
