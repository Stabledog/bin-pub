#!/bin/bash
#Help Launch vscode in custom env.
# Each workspace file should have a corresponding [workspace].env file in the
# same dir.  We source it and then run vscode from the dir containing the
# workspace file, to ensure that ${WorkspaceFolder} matches the CWD for
# vscode itself.

function code_ws {

    [[ -n $1 ]] || return $(die Please supply a workspace file as \$1)
    local ws_name=$(readlink -f $1 | sed 's/\.code-workspace//')
    shift
    local ws_filename=${ws_name}.code-workspace
    [[ -f $ws_filename ]] || return $(die "Can't find $ws_filename")
    local env_filename="${ws_name}.env"
    if [[ ! -f $env_filename ]]; then
        read -p "Can't find $env_filename, so I can't source it.  Hit Enter to continue anyway."
    fi
    (
        ws_dir=$(dirname $ws_filename)
        cd $ws_dir || die "Can't cd to $ws_dir"
        xenv=$(cat $env_filename)
        echo "xenv=[$xenv]"
        cmd="$xenv code $ws_filename"
        echo -e "\033[;33m${cmd}\[033;0m"
        eval "$cmd $@"
    )
}

if [[ -z $sourceMe ]]; then
    code_ws "$@"
fi
