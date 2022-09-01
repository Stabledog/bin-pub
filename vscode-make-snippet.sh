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

origInputs=

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
    local snipName="$1"
    [[ -n $snipName ]] || die "no snipName passed to emitHeader()"
    command cat <<-EOF
"${snipName}": {
    "description": "TODO ${snipName} needs a description?",
    "prefix": ["${snipName}"], // Multiple prefixes may be defined
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
    emitHeader $(basename "$input")
    local bodyIntermediateOutput=$(mktemp)
    xform_body "$input" > $bodyIntermediateOutput
    cat "$bodyIntermediateOutput"
    emitTail
    [[ -z $PRESERVE_BODY ]] && {
        [[ -f $bodyIntermediateOutput ]] && command rm $bodyIntermediateOutput
    }
    [[ 1 -eq 1 ]]
}

parseArgs() {
    local filename
    while [[ -n $1 ]]; do
        case $1 in
            -h|--help)
                do_help $*
                exit 1
                ;;
            *)
                origInputs="$origInputs $1"
                ;;
        esac
        shift
    done
    # Validate that minimal args have been parsed:
    # ??
}

main() {
    parseArgs "$@"
    [[ -z $origInputs ]] && {
        echo "Paste input and hit Ctrl-D:" >&2
        origInputs=/tmp/_nameless_snippet
        echo -n > $origInputs
        cat > $origInputs || die
    }
    local outfile=/tmp/_new_snippet.json
    echo "{" > $outfile
    for origInput in ${origInputs}; do
        make_snippet "$origInput" | sed 's/^/    /' | command tee -a $outfile
    done
    echo "}" >> $outfile

    (
        echo "  In vscode, hit: "
        echo "    Ctrl+Shift+P > \"Snippets: Configure User Snippets\""
        echo "    and paste content of ${outfile} into the appropriate snippet file."
    ) >&2
}

[[ -z ${sourceMe} ]] && {
    main "$@"
    exit
}
true
