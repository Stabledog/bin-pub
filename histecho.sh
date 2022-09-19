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
pub_url=http://my-web-server/bash_history.txt
sourcePath=~/.bash_history
reverseOrder=true  # Newest events on top?
stripTimestamps=true
EOF
}

loop_mode=false
loop_interval=30

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
do_help() {
    local fname=$(basename ${scriptName})
    cat <<-EOF
${fname} --makeconfig   # print default config content
${fname} --config       # print the current config
${fname} --loop         # Loop the transmission

EOF
}

printConfig() {
    echo "Contents of ${configFile}:" >&2
    cat ${configFile}
}

parseArgs() {
    local filename  # Declare arguments to be parsed as local
    while [[ -n $1 ]]; do
        case $1 in
            -h|--help)
                do_help $*
                exit 1
                ;;
            -l|--loop)
                loop_mode=true
                ;;
            --makeconfig)
                # Print default config file
                makeDefaultConfig
                exit 0
                ;;
            --config)
                printConfig "$@"
                exit
                ;;
            *)
                unknown_args="$unknown_args $1"
                ;;
        esac
        shift
    done
    source $configFile
}

do_send() {
    echo -n "Sending $sourcePath to ${destHost}:${targetPath} @$(date -Iseconds):" >&2
    do_filter() {
        if $stripTimestamps; then
            grep -Ev "^\#[0-9]+$"
        else
            while read line; do
                if [[ ${line} == \#[0-9]* ]]; then
                    echo -n "${line:1}" | awk '{print strftime("%b-%d %T ", $1)}' | tr -d '\n'
                else
                    echo "$line"
                fi
            done
        fi
    }
    tac $sourcePath | do_filter | ssh ${destHost} bash -c "cat > ${targetPath}" && {
        echo "  OK" >&2
        echo "   $pub_url" >&2
    } || {
        echo "ERROR occurred: $?" >&2
    }
}

do_loop_send() {
    while true; do
        do_send
        sleep $loop_interval
    done
}

main() {
    parseArgs "$@"
    if $loop_mode; then
        do_loop_send
    else
        do_send
    fi
}

[[ -z ${sourceMe} ]] && {
    main "$@"
    builtin exit
}
command true
