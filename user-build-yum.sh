#!/bin/bash
# user-build.sh
#
# When the image is built, we want to brand it with the user's name and
# profile stuff, so we can run git and not mess up host-shared file permissions.
#
#

die() {
    echo "ERROR: $*" >&2
    exit 1
}

vscode_uid=$(sed -n "s/^.*--uid \([0-9]*\).*$/\1/p" <<< "$*")
[[ -n $vscode_uid ]] || vscode_uid=1000


[[ -f /.dockerenv ]] || die "Not running in a Docker container"
[[ $UID -eq 0 ]] || die "We're expecting to run as root in a container during image build"


grep -Eq vscode /etc/passwd || {
    adduser --home /home/vscode --uid $vscode_uid vscode 2>/dev/null || die "Failed adding vscode user"
    usermod -aG wheel vscode
    echo '%vscode ALL=(ALL) NOPASSWD: ALL' >> /etc/sudoers
}

