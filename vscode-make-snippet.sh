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
    command sed -e 's/["]/\\"/g' -e 's/[$]/\\\$/g' -e 's/^/"/' -e 's/$/",/'
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
}
EOF
}

main() {
    emitHeader
    echo "Enter raw body text and then hit Ctrl+D:" >&2
    (
        command stty -echo
        while IFS= builtin read line; do
            xform_body_line <<< "$line"
        done
        command stty echo
    )
    emitTail
}

[[ -z ${sourceMe} ]] && {
    main "$@"
    exit
}
true
