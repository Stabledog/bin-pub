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
    cleanup_histstream <${file} >${tmpf}
    mv ${tmpf} ${file}
    echo "Done cleaning $file"
}

cleanup_histstream() {
    local timestamp="#$(date +%s)"
    while read line; do
        #stub "raw:$line"
        # Is this a timestamp?
        if [[ $line =~ ^#[[:digit:]]+$ ]]; then
            timestamp=$line
            #stub "<timestamp>"
            continue
        fi
        # We're not interested in lines less than this long:
        if (( ${#line} < 9  )); then
            #stub "<tooshort>"
            continue
        fi
        if [[ $line =~ .+#.+ ]]; then
            #stub "<output-ok>"
            echo "$timestamp"
            echo "$line"
        fi
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
