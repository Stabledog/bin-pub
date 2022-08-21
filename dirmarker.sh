#!/bin/bash
# dirmarker.sh
#  Takes the basename of current dir and emits a string which expands it with
# spaces for use as a marker.  With -w, creates a subdir with that name and
# a .dirmarker file containing the original name.
#
help() {
    cat <<-EOF
dirmarker.sh
   - Print name of dirmarker based on PWD basename

dirmarker.sh -w
   - Create dirmarker here ./

dirmarker.sh -r
    - Remove all dirmarker dirs here ./
EOF
}
die() {
    echo "ERROR: $*" >&2
    exit 1
}

make_dirmarker_name() {
    echo "_$(basename ${PWD})" | command sed 's/./&_/g' | tr '\n' '_'
}


if [[ -z $sourceMe ]]; then
    [[ "$*" == "-h" || "$*" == "--help" ]] && {
        help
        exit
    }
    [[ "$*" == "-r" ]] && {
        set --
        # Remove any dirmarkers found in ./*
        while read dm; do
            dd=$(dirname "${dm}")
            [[ -d "${dd}" && -f "${dd}/.dirmarker" ]] && {
                rm -rf "${dd}" && {
                    echo "rm -rf ${dd}: OK" ;
                } || { die "Failed to remove ${dd}"; }
            }
        done < <(command ls -a */.dirmarker 2>/dev/null)
        exit
    }
    name="$(make_dirmarker_name)"
    echo "${name}"
    [[ "$*" == "-w" ]] && {
        mkdir -p "${name}" || die "Failed creating dirmarker for $PWD"
        echo "$(pwd -P)" > "${name}/.dirmarker"
    }

fi
