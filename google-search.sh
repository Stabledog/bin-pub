#!/bin/bash
# :vim filetype=sh :
# Launch browser with args converted to google search string

set -ue

canonpath() {
    ( cd -L -- "$(dirname -- $0)"; echo "$(pwd -P)/$(basename -- $0)" )
}

Script=$(canonpath "$0")
Scriptdir=$(dirname -- "$Script")

get_browser() {
    wslpath -u "C:\Program Files (x86)\Google\Chrome\Application\chrome.exe"
}

red() {
    echo -en "\033[;31m$@\033[;0m"
}
green() {
    echo -en "\033[;32m$@\033[;0m"
}
yellow() {
    echo -en "\033[;33m$@\033[;0m"
}

die() {
    red "$@\n" >&2
    exit 1
}

set +u
if [ -z "$sourceMe" ]; then
    loc="$(get_browser)"
    [[ -x "${loc}" ]] || die "Can't find browser app \"${loc}\""
    url=$( echo "https://google.com/search?q=$@" | tr ' ' '+')
    echo "${url}"
    "$(get_browser)" "${url}"
fi
