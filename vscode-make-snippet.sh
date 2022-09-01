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

xform_body() {
    [[ -f $1 ]] || die "no input for xform_body()"
    set -x
    local inputfile="$1"
    command sed -E \
         -e 's%[\]$%\\\\%' \
         -e 's/["]/\\"/g'  \
         -e 's/[$]/\\\\\$/g'  \
         -e 's/[\]/\\/g' \
         -e 's/\t/\\t/g' \
         -e 's/^/        "/'  \
         -e 's/$/",/'  \
         ${inputfile}

    set +x
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
    [[ -f $1 ]] || die "no intermediate input for make_snippet()"
    local input="$1"
    emitHeader
    local bodyIntermediateOutput=$(mktemp)
    xform_body "$input" > $bodyIntermediateOutput
    cat "$bodyIntermediateOutput"
    emitTail
    [[ -z $PRESERVE_BODY ]] && {
        [[ -f $bodyIntermediateOutput ]] && command rm $bodyIntermediateOutput
    }
    [[ 1 -eq 1 ]]
}

main() {
    local origInput="$1"
    [[ -f $origInput ]] || die "No original input file [$1]"
    local outfile=/tmp/_new_snippet.json
    echo "{" > $outfile
    make_snippet "$origInput" | sed 's/^/    /' | command tee -a $outfile
    echo "}" >> $outfile
    echo "Snippet output copied to $outfile -- Use Ctrl+Shift+P > \"Snippets: Configure User Snippets\" and paste content there." >&2
}

[[ -z ${sourceMe} ]] && {
    main "$@"
    exit
}
true
