#!/bin/bash
# histecho.sh:
#

scriptName="$(readlink -f "$0")"
scriptDir=$(command dirname -- "${scriptName}")

configFile=~/.histecho

die() {
    builtin echo "ERROR($(basename ${scriptName})): $*" >&2
    builtin exit 1
}

makeDefaultConfig() {
    cat <<- EOF
# .histecho -- config for histecho.sh
targetPath=www/histecho/bash_history.txt
destHost=my-web-server
sourcePath=~/.bash_history
reverseOrder=true  # Newest events on top?
stripTimestamps=true
EOF
}

stub() {
    # Print debug output to stderr.  Call like this:
    #   stub "${FUNCNAME[0]}.${LINENO}" "$@" "<Put your message here>"
    #
    builtin echo -n "  <<< STUB" >&2
    for arg in "$@"; do
        echo -n "[${arg}] " >&2
    done
    echo " >>> " >&2
}

parseArgs() {
    [[ $# -eq 0 ]] && die "Expected arguments"
    local filename  # Declare arguments to be parsed as local
    while [[ -n $1 ]]; do
        case $1 in
            -h|--help)
                #  do_help $*
                exit 1
                ;;
            --config)
                # Print default config file
                makeDefaultConfig
                exit 0
                ;;
            *)
                unknown_args="$unknown_args $1"
                ;;
        esac
        shift
    done
}

main() {
    parseArgs "$@"
}

[[ -z ${sourceMe} ]] && {
    main "$@"
    builtin exit
}
command true
