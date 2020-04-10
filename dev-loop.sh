#!/bin/bash
#vim: filetype=sh :
#
# dev-loop.sh:
# This runs in two modes: "tmux_outer" vs. "tmux_inner"
#
# The outer instance launches a unique tmux session, and starts a tmux_inner instance within a new window
# in that session.  The inner instance runs the UI loop, launches debug/run/shell as needed by the user.
#
# Usage:
#   dev-loop.sh [args]
#    - There must be an active ./taskrc{.md}.
#    - The taskrc can redefine debug_one(), run_one(), and/or shell_one() to customize behavior within
#         each of those loops.  The default versions of debug_one() and run_one() just print error messages,
#         while the default version of shell_one() runs a bash shell with a taskrc+.bashrc loader in current dir.
#    - Any [args] not eaten by dev-loop.sh are forwarded to the *_one() functions
#
org_args="$@"

function stub {
    return # Comment this out to enable stubs
    echo -e "\033[;31mdev-loop.sh:stub(\033[;33m$@\033[;31m)\033[;0m" >&2
}
stub "org_args=[$org_args]"

source ~/.bashrc

function run_one {
    stub "ERROR: run_one() should be defined in taskrc" >&2
}

function debug_one {
    stub "ERROR: debug_one() should be defined in taskrc" >&2
}

function shell_one {
    stub "shell_one() default:"
    /bin/bash --login --rcfile  <(cat << EOF
source ~/.bashrc
taskrc_v3
echo "Default shell_one() + taskrc + .bashrc loaded OK"
EOF
    )
    stub "shell_one default exit"
}



function run_loop {
    # runs a run_one() function repeatedly with restart prompt
    local again=true
    while $again; do
        again=false
        run_one "$@"
        read -n 1 -p "[A]gain or [Q]uit?"
        if [[ $REPLY =~ [aA] ]]; then
            again=true
        fi
    done
}


function debug_loop {
    # runs a debug_one() function repeatedly with restart prompt
    local again=true
    while $again; do
        again=false
        debug_one "$@"
        read -n 1 -p "[A]gain or [Q]uit?"
        if [[ $REPLY =~ [aA] ]]; then
            again=true
        fi
    done
}


function make_inner_shrc {
    # Creates a temp --rcfile named .devloop_inner_shrc for the inner shell to set up environment
    cat > ./.devloop_inner_shrc << EOF
# .devloop_inner_shrc, created by dev-loop.sh $(date)
#  You should add this to .gitignore
echo ".devloop_inner_shrc($@) loading:"
source ~/.bashrc
dev-loop.sh --inner $@
rm .devloop_inner_shrc
exit
EOF
}

function tmux_outer {
    local tmx_sess=devloop$(tty | tr '/' '_')
    stub tmx_sess=$tmx_sess
    make_inner_shrc "$@"
    stub tmux new-session -s $tmx_sess '/bin/bash --rcfile ./.devloop_inner_shrc'
    tmux new-session -s $tmx_sess '/bin/bash --rcfile ./.devloop_inner_shrc'
    stub $(tmux ls)
    stub tmux result=$?
}

function tmux_inner {
    # This function runs the main inner loop
    stub "tmux_inner($@): pwd=$PWD..."

    local again_main=true
    while $again_main; do
        again_main=false
        echo
        echo "-----------------"
        read -n 1 -p "[D]ebug, [R]un, [S]hell, or [Q]uit?"
        case $REPLY in
            [dD])
                debug_loop "$@"
                again_main=true
                ;;
            [rR])
                run_loop "$@"
                again_main=true
                ;;
            [qQ])
                #set -x
                echo "exit"
                exit
                ;;
            *)
                shell_one "$@"
                again_main=true
                ;;
        esac
    done
}


if [[ -z $sourceMe ]]; then
    if [[ $1 == "--inner" ]]; then
        shift

        # AFTER we have defined default run/debug/start_one() functions, we'll give the local
        # project a shot at redefining them:
        if ! (shopt -s extglob; ls taskrc?(.md) &>/dev/null ); then
            stub "No .taskrc{.md} present"
            exit
        fi
        taskrc_v3  # Load ./taskrc.md
        tmux_inner "$@"
    elif [[ -z $DEVLOOP_OUTER ]]; then
        export DEVLOOP_OUTER=$$
        stub calling tmux_outer
        tmux_outer "$@"
    else
        stub "Cant run nested dev-loop.sh instances, DEVLOOP_OUTER=$DEVLOOP_OUTER"
    fi
fi

