#!/bin/bash
# vscode-make-snippet.sh
# Read from stdin, write to stdout. CC: output to /tmp/_newSnippet.json


canonpath() {
    builtin type -t realpath.sh &>/dev/null && {
        realpath.sh -f "$@"
        return
    }
    builtin type -t readlink &>/dev/null && {
        command readlink -f "$@"
        return
    }
    # Fallback: Ok for rough work only, does not handle some corner cases:
    ( builtin cd -L -- "$(command dirname -- $0)"; builtin echo "$(command pwd -P)/$(command basename -- $0)" )
}

scriptName="$(canonpath $0)"
scriptDir=$(command dirname -- "${scriptName}")

die() {
    builtin echo "ERROR: $*" >&2
    builtin exit 1
}

stub() {
    # Print debug output to stderr.  Call like this:
    #   stub ${FUNCNAME[0]}.$LINENO item item item
    #
    builtin echo -n "  <<< STUB" >&2
    for arg in "$@"; do
        echo -n "[${arg}] " >&2
    done
    echo " >>> " >&2
}

xform_body_line() {
    command sed -e 's/["]/\\"/g' -e 's/[$]/\\\\\$/g' -e 's/^/        "/' -e 's/$/",/'
}
emitHeader() {
    command cat <<-EOF
"todoNameMe": {
    "description": "TODO give this snippet a description",
    "prefix": ["todoPrefixList"], // Multiple prefixes may be defined
    // "scope": "shellscript",  // TODO: Set this to the relevant language(s) to make  snippet non-global
    "body": [
EOF
}

emitTail() {
    command cat <<-EOF
    ]
},
EOF
}

make_snippet() {
    emitHeader
    [[ -t 0 ]] && echo "Enter raw body text and then hit Ctrl+D:" >&2
    (
        [[ -t 0 ]] && command stty -echo
        while IFS= builtin read line; do
            xform_body_line <<< "$line"
        done
        [[ -t 0 ]] && command stty echo
    )
    emitTail
}

main() {
    local outfile=/tmp/_new_snippet.json
    make_snippet | sed 's/^/    /' | command tee $outfile
    echo "Snippet output copied to $outfile" >&2
}

[[ -z ${sourceMe} ]] && {
    main "$@"
    exit
}
true
