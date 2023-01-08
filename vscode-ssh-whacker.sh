#!/bin/bash
# vscode-ssh-whacker.sh
#  Run this on a remote ssh host when you're using VSCode for remote development.
#  If you have trouble with starting new VSCode sessions or reloading existing windows,
# this script will rebuild your ~/.vscode-server tree without removing the
# persistent state data.  
#
# Then if you do a Reload Window in vscode, it can usually rebuild the ./bin folder and reconnect

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
        [[ -d ${HOME}/.vscold${dn} ]] \
            && continue
        mv ${HOME}/.vscode-server ${HOME}/.vscold${dn} || {
            echo "ERROR: failed moving ~/.vscode-server to ~/.vscold${dn}" >&2
            false; return
        }
        mkdir ${HOME}/.vscode-server || die 109
        cd ${HOME}/.vscode-server || die 110
        rsync -a ${HOME}/.vscold${dn}/data ${HOME}/.vscold${dn}/extensions ./ || die 112
        {
            echo "Rebuilt $(hostname):$USER:.vscode-server tree. "
            echo "Reload your vscode window now."
        } >&2
        return
    done
    echo "You have too many freakin' ~/.vscold* directories.  Please clean up and try again." >&2
    false; return
}

main() {
    which rsync || die "rsync must be installed on $(hostname)"
    do_whack

}

[[ -z ${sourceMe} ]] && {
    main "$@"
    builtin exit
}
command true
