#!/bin/bash
#Help Launch vscode in custom env.
# Each workspace file may have a corresponding [workspace].env file in the
# same dir.  We source it and then run vscode from the dir containing the
# workspace file, to ensure that ${WorkspaceFolder} matches the CWD for
# vscode itself.

Code="$(type -a code | grep Microsoft | sed 's/code is //')"

die() {
    echo "ERROR: $@" >&2
    exit 1
}

choose_wsfile() {
    exec 9< <(echo "0 <none>"; ls *.code-workspace vscode/*.code-workspace 2>/dev/null | sed 's/\.code-workspace//' | cat -n )
    while read -u 9 line; do
        echo $line >&2
    done
    exec 9<&-
    read -n 1 -p "Select workspace #: "
    ls *.code-workspace vscode/*.code-workspace  2>/dev/null | sed "${REPLY}q;d"
}

function main {
    local wsfile=${1}
    if [[ -z $wsfile ]]; then
        wsfile=$(choose_wsfile)
        [[ -z $wsfile ]] && return $(die Please supply a workspace file as \$1)
    fi
    local ws_name=${wsfile//\.code-workspace}
    local ws_filename=${ws_name}.code-workspace
    [[ -f $ws_filename ]] || return $(die "Can't find $ws_filename")
    local env_filename="${ws_name}.env"
    (

        ws_dir=$(dirname $ws_filename)
        xenv=$(cat $env_filename)
        cd $ws_dir || die "Can't cd to $ws_dir"
        echo "xenv=[$xenv]"
        cmd="$xenv \"$Code\" $(basename $ws_filename)"
        echo -e "\033[;33m${cmd}\[033;0m"
        eval "$cmd $@"
    )
}

if [[ -z $sourceMe ]]; then
    #code_ws "$@"
    main  "$@"
    #choose_wsfile "$@"
fi
