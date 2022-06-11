#!/bin/bash
# dirmarker.sh
#  Takes the basename of current dir and emits a string which expands it with
# spaces for use as a marker.  With -w, creates a subdir with that name and
# a .dirmarker file containing the original name.
#
die() {
    echo "ERROR: $*" >&2
    exit 1
}

make_dirmarker_name() {
    echo "_$(basename ${PWD})_" | command sed 's/./& /g'
}

if [[ -z $sourceMe ]]; then
    name="$(make_dirmarker_name)"
    echo "${name}"
    [[ "$*" == "-w" ]] && {
        mkdir -p "${name}" || die "Failed creating dirmarker for $PWD"
        echo "$(pwd -P)" > "${name}/.dirmarker"
    }
fi
