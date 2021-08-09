#!/bin/bash
# task-find.sh
#  Track down aliases, functions, scripts...
#  Configuration:
#     Add ~/.taskrc/task-find-dirs to extend the list of directories searched beyond "find_dirs"

die() {
    echo "ERROR: $@"
    exit 1
}

yellow() {
    echo -e "\033[;33m$@\033[;0m"
}

find_dirs="$PWD $HOME/.taskrc $HOME/.taskrc/bin $HOME/bin $(cat ~/.taskrc/task-find-dirs 2>/dev/null | tr -d '#' )"

if [[ -z $sourceMe ]]; then
    expr="$1"
    for xdir in $find_dirs; do
        cd $xdir || { echo "ERROR: Can't cd to $xdir" >&2; continue; }
        yellow "Searching $PWD for \"${expr}\":" >&2
        grep -E "$expr" * 2>/dev/null | sed "s%^% $PWD/%"
    done
    (
        PS1="." source ~/.bashrc
        shopt -s extdebug
        echo "declare -Ff $@ :"
        declare -Ff $@
        shopt -u extdebug
    )
fi

