#!/bin/bash
# This script runs in an endless loop, periodically committing the files in the current
# directory and doing a push.
#

set -ue

canonpath() {
    ( cd -L -- "$(dirname -- $0)"; echo "$(pwd -P)/$(basename -- $0)" )
}

Script=$(canonpath "$0")
Scriptdir=$(dirname -- "$Script")

LOOP_PERIOD_SECS=60  # Set with the -p|--period option

red() {
    /bin/echo -en "\033[;31m$@\033[;0m"
}
green() {
    /bin/echo -en "\033[;32m$@\033[;0m"
}
yellow() {
    /bin/echo -en "\033[;33m$@\033[;0m"
}

die() {
    red "$@\n" >&2
    exit 1
}

parseArgs() {
    set +u
    while [[ -n $1  ]]; do
        case $1 in
            -p|--period)
                shift
                [[ -n  $1 ]] || die --period option requires argument in seconds
                LOOP_PERIOD_SECS=$1
                ;;
            *)
                die Unknown argument $1
                ;;
        esac
        shift
    done

    git-find-root &>/dev/null || die "Dir $PWD is not a git working tree"
    set -u
}

runLoop() {
    while true; do
        (
            git commit -am "Auto commit by autocommit_run.sh"
            git pull
            git push
            echo "   (...sleeping $LOOP_PERIOD_SECS at $(date -Iseconds) )"
            echo "    ...in:  $(pwd -P)"
            sleep $LOOP_PERIOD_SECS
        ) || :
    done
}

set +u
if [ -z "$sourceMe" ]; then
    set -u
    parseArgs "$@"
    runLoop $LOOP_PERIOD_SECS "$PWD"
fi
