#!/bin/bash
# git-remote-show-urls.sh

die() {
    echo "ERROR: $*" >&2
    exit 1
}

match_subst_urls() {
    # match entries are [pattern] [result]
    command sed -e 's%git@bbgithub\.dev\.bloomberg\.com:%https://bbgithub.dev.bloomberg.com/%' -e 's%git@github\.com:%https://github.com/%'
}

translate_entry_url() {
    echo "xlat[$1]"
}

main() {
    command -V git &>/dev/null || die "No git installed"
    local branch=$(git symbolic-ref --short HEAD)
    while read remote_name entry mode; do
        echo "$remote_name $entry" | match_subst_urls
    done < <( command git remote -v | command grep -E '\(fetch\)' )
}

[[ -z ${sourceMe} ]] && main "$@"
