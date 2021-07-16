#!/bin/bash
# Remove unwanted junk from given histfile

die() {
    echo "ERROR: $@" >&2
    exit 1
}

cleanup_histfile() {
    local file=$1
    local tmpf=$(mktemp)
    grep -v '^#' ${file} | grep \# > ${tmpf}
    [[ -f ${tmpf} ]] || die "Can't find ${tmpf}"
    mv ${tmpf} $1
    echo "Done cleaning $file"
}

parseArgs() {
    [[ -z $1 ]] && die Filename expected as \$1
    [[ -f $1 ]] || die Can\'t find $1
    target_file=$1
}

if [[ -z $sourceMe ]]; then
    parseArgs "$@"
    cleanup_histfile $target_file
fi
