#!/bin/bash
# Remove unwanted junk from given histfile

die() {
    echo "ERROR: $@" >&2
    exit 1
}

stub() {
    echo "stub[$@]" >&2
}

cleanup_histfile() {
    local file=$1
    local tmpf=$(mktemp)
    trap "rm ${tmpf} &>/dev/null" exit
    cleanup_histstream <${file} >${tmpf}
    cp ${tmpf} ${file}
    echo "Done cleaning $file"
}

cleanup_histstream() {
    local timestamp="#$(date +%s)"
    local prev_line
    while read line; do
        #stub "raw:$line"
        # Is this a timestamp?
        if [[ $line =~ ^#[[:digit:]]+$ ]]; then
            timestamp=$line
            #stub "<timestamp>"
            continue
        fi
        if [[ ${line} == ${prev_line} ]]; then
            continue  # Simplistic dupe removal
        # We're not interested in lines less than this long:
        elif ! [[ $line =~ .+\# ]]; then
            continue
        fi
        prev_line=${line}
        echo "$timestamp"
        echo -E $line
    done
}

parseArgs() {
    [[ -z $1 ]] && die Filename expected as \$1
    [[ -f $1 ]] || die Can\'t find $1
    target_file=$1
}

if [[ -z $sourceMe ]]; then
    parseArgs "$@"
    cleanup_histfile $target_file
fi
