#!/bin/bash
# wsl-mount-usb-drive.sh

# See also:
#  https://learn.microsoft.com/en-us/windows/wsl/wsl-config
#    ( How to setup c:\Users\[me]\.wslconfig "automount" so that USB drivers are attached on WSL startup )

scriptName="$(readlink -f "$0")"
scriptDir=$(command dirname -- "${scriptName}")


drive_letter=   # Defaults to d, set this with --drive or -d

die() {
    builtin echo "ERROR($(basename ${scriptName})): $*" >&2
    builtin exit 1
}



parseArgs() {

    command uname -r | grep -qi microsoft || die "This command is intended only for WSL"

    [[ $# == 0 ]] && { drive_letter='d'; return; }
    while [[ -n $1 ]]; do
        case $1 in
            -d|--drive)
                if [[ "$2" =~ ^[d-zD-Z]:?$ ]]; then
                    drive_letter="${2:0:1}"
                    shift 2
                    continue
                fi
                die "Invalid argument for --drive: $2"
            ;;
        esac
        shift
    done
    [[ -n $drive_letter ]] || die No drive letter defined
    [[ $# == 0 ]] || { die "Unknown command line args: $*"; false; return; }
    true
}

main() {
    parseArgs "$@"
    [[ -f ~/win-profile/.wslconfig ]] || die "Can't find ~/win-profile/.wslconfig"

    grep -Eq "^[automount]" ~/win-profile/.wslconfig || {
        echo "WARNING: can't find [automount] element in ~/win-profile/.wslconfig"
        echo "Add this to it, and then do a \"wsl --shutdown\" :"
        echo "[automount]"
        echo "options = \"metadata\""
        echo "enabled = true"
    }
    mount | command grep -Eq "${drive_letter}: on /mnt/${drive_letter}" && {
        true;  # Already a device mounted
        return;
    }
    sudo mount -t drvfs "${drive_letter}:" /mnt/${drive_letter} -o metadata || {
        die "Failed mounting drive $drive_letter: on /mnt/${drive_letter}"
    }
}

[[ -z ${sourceMe} ]] && {
    main "$@"
    builtin exit
}
command true
