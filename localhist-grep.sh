#!/bin/bash
# localhist-grep.sh

set -x

die() {
    echo "ERROR: $@" >&2
    exit 1
}

[[ -d ~/.localhist ]] || die No ~/.localhist dir exists

cd ~/.localhist
grep -E "$@" *
