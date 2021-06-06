#!/bin/bash
# :vim filetype=sh :
#

set -ue

canonpath() {
    ( cd -L -- "$(dirname -- $0)"; echo "$(pwd -P)/$(basename -- $0)" )
}

Script=$(canonpath "$0")
Scriptdir=$(dirname -- "$Script")

red() {
    echo -en "\033[;31m$@\033[;0m"
}
green() {
    echo -en "\033[;32m$@\033[;0m"
}
yellow() {
    echo -en "\033[;33m$@\033[;0m"
}

inner_py() {
    cat <<EOF
import subprocess
import hashlib
import sys
import os
def get_tree_checksum(xdir:str):
    try:
        cmd=f"find . -type f -ls "
        proc = subprocess.run(['sh','-c',cmd],capture_output=True,cwd=xdir)
        if proc.returncode != 0:
            msg=f"get_tree_checksum failed: {proc.stderr}"
            raise RuntimeError(msg)
        result = hashlib.md5(proc.stdout).hexdigest()
    except Exception as e:
        return "bad-hash"
    return result
print(get_tree_checksum(os.getcwd()))
EOF
}

get_tree_checksum() {
    python3.8 - < <(inner_py)
}

die() {
    red "$@\n" >&2
    exit 1
}

get_cur_branch() {
    git branch | egrep '^\*' | cut -d' ' -f2
}

set +u
if [ -z "$sourceMe" ]; then
    prev_cksum='---'
    set +e
    while true; do
        if [[ $(get_cur_branch) != $1 ]]; then
            die "Current branch is not \"$1\""
        fi
        cur_cksum=$(get_tree_checksum)
        if [[ $cur_cksum != $prev_cksum ]]; then
            git commit -am "sync"; git push
            prev_cksum=$cur_cksum
        else
            echo "No changes at $(date -Iseconds | cut -dT -f2 | cut -d'-' -f1)"
        fi
        sleep 5
    done
fi
