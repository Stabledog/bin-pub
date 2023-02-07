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

dirmarker.sh -w [marker text]
   - Create dirmarker here ./
   - Default marker text is base name of current dir

dirmarker.sh -n [marker text]
    - Print proposed marker text after expansion
    - Default marker text is base name of current dir

dirmarker.sh -r
    - Remove all dirmarker dirs here ./

EOF
}
die() {
    echo "ERROR: $*" >&2
    exit 1
}

make_dirmarker_name() {
    local name="$(basename ${PWD})"
    [[ -n "$*" ]] && {
        name="$*"
    }
    echo "_${name}" | command sed -e 's|[ /]|-|g' -e 's|.|&_|g' | tr '\n' '_'
}

write_dirmarker() {
    local text=$(make_dirmarker_name "$@")
    mkdir "./$text" || die "Failed creating dir ./$text"
    pwd > "./${text}/.dirmarker"
}

do_remove() {
    # Remove any dirmarkers found in ./*
    local result=true
    while read dm; do
        dd=$(dirname "${dm}")
        if [[ -d "${dd}" && -f "${dd}/.dirmarker" ]] ; then
            if rm -rf "${dd}"; then
                echo "rm -rf ${dd}: OK" ;
            else
                echo "ERROR: Failed to remove ${dd}" >&2;
                result=false
            fi
        fi
    done < <(command ls -a */.dirmarker 2>/dev/null)
    $result
}

if [[ -z $sourceMe ]]; then
    while [[ -n $1 ]]; do
        case $1 in
            -h|--help) help; exit ;;
            -r|--remove) shift; do_remove "$@"; exit ;;
            -w|--write) shift; write_dirmarker "$@"; exit ;;
            -n|--name) shift; make_dirmarker_name "$@"; exit ;;
            *)  die "Unknown arg(s): $*" ;;
        esac
        shift
    done
    help
    exit 1
fi
