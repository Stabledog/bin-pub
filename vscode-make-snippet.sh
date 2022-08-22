#!/bin/bash
# vscode-make-snippet.sh
# Read from stdin, write to stdout.


scriptName="$(command readlink -f $0)"
scriptDir=$(command dirname -- "${scriptName}")

die() {
    builtin echo "ERROR: $*" >&2
    builtin exit 1
}

stub() {
   builtin echo "  <<< STUB[$*] >>> " >&2
}

xform_body_line() {
    command sed -e 's/["]/\\"/g' -e 's/[$]/\\\\\$/g' -e 's/^/        "/' -e 's/$/",/'
}
emitHeader() {
    command cat <<-EOF
"todoNameMe": {
    "description": "TODO give this snippet a description",
    "prefix": ["todoPrefixList"],
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
