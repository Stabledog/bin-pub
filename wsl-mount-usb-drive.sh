#!/bin/bash

drive_letter=   # Defaults to d, set this with --drive or -d

die() {
    echo "ERROR: $*" >&2
    exit 1
}

stub() {
    echo "   -->$*<--"
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
    [[ $# == 0 ]] || { die "Unknown command line args: $*"; false; return; }
    true
}

main() {
    parseArgs "$@"
    grep -Eq "^[automount]" /etc/wsl.conf || {
        echo "WARNING: can't find /etc/wsl.conf or no [automount] element."
        echo "Add this to it, and then do a \"wsl --shutdown\" :"
        echo "[automount]"
        echo "options = \"metadata\""
    }
    [[ -d /mnt/${drive_letter} ]] || { 
        sudo mkdir -p /mnt/${drive_letter} 2>/dev/null || die "Failed creating /mnt/${drive_letter}"; 
    }
    mount | grep -Eq "^drvfs on /mnt/${drive_letter} " && {
        true;  # Already a device mounted
        return;
    }
    sudo mount -t drvfs "${drive_letter}:" /mnt/${drive_letter} -o metadata || {
        die "Failed mounting drive $drive_letter: on /mnt/${drive_letter}"
    }
}

if [[ -z $sourceMe ]]; then

    main "$@"
fi
