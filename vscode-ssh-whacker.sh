#!/bin/bash
# vscode-ssh-whacker.sh
#  Run this on a remote ssh host when you're using VSCode for remote development.
#  If you have trouble with starting new VSCode sessions or reloading existing windows,
# this script will rename your ~/.vscode-server dir -- permitting existing instances to
# keep running, while allowing the new one to start or reload.

scriptName="$(readlink -f "$0")"
scriptDir=$(command dirname -- "${scriptName}")

die() {
    builtin echo "ERROR($(basename ${scriptName})): $*" >&2
    builtin exit 1
}

do_whack() {
    [[ -d ${HOME}/.vscode-server ]] || {
        echo "Sorry, no ~/.vscode-server/ dir exists.  Nothing I can do to help." >&2
        false; return;
    }
    for dn in {1..1000}; do
        [[ -d ${HOME}/.vscode-server-bak${dn} ]] \
            && continue
        mv ${HOME}/.vscode-server ${HOME}/.vscode-server-bak${dn} || {
            echo "ERROR: failed moving ~/.vscode-server to ~/.vscode-server-bak${dn}" >&2
            false; return
        }
        echo "Renamed ~/.vscode-server to ~/.vscode-server-bak${dn}.  Reload your vscode window now."
        return
    done
    echo "You have too many freakin' ~/.vscode-server-bak directories.  Please clean up and try again." >&2
    false; return
}

main() {

    do_whack

}

[[ -z ${sourceMe} ]] && {
    stub "${FUNCNAME[0]}.${LINENO}" "calling main()" "$@"
    main "$@"
    builtin exit
}
command true
