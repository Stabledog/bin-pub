#!/bin/bash
# github-gh-install-debian.sh
#  See also: https://github.com/cli/cli/blob/trunk/docs/install_linux.md#debian-ubuntu-linux-raspberry-pi-os-apt

scriptName="$(readlink -f "$0")"
scriptDir=$(command dirname -- "${scriptName}")

die() {
    builtin echo "ERROR($(basename ${scriptName}): $*" >&2
    builtin exit 1
}

stub() {
   builtin echo "  <<< STUB[$*] >>> " >&2
}
main() {
    builtin echo "args:[$*]"

    curl -fsSL https://cli.github.com/packages/githubcli-archive-keyring.gpg \
        | sudo dd of=/usr/share/keyrings/githubcli-archive-keyring.gpg \
     && sudo chmod go+r /usr/share/keyrings/githubcli-archive-keyring.gpg \
     && echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/githubcli-archive-keyring.gpg] https://cli.github.com/packages stable main" \
        | sudo tee /etc/apt/sources.list.d/github-cli.list > /dev/null \
     && sudo apt update \
     && sudo apt install gh -y
     [[ $? -eq 0 ]] || die

     echo "Installed: OK" >&2
     echo "Run \"gh auth login\" to continue with authentication setup " >&2

}

[[ -z ${sourceMe} ]] && {
    main "$@"
    builtin exit
}
command true
