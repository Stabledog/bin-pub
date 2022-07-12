#!/bin/bash
# make-isolated-merge-environment.sh
#
# When you want to merge or maintain settings stuff without messing up VScode with intermediate changes, run this script first.
#
# It will create ./tmp/isolated-merge as a host workspace for vscode, with git enabled etc.
#
# PUSH YOUR CHANGES BEFORE destroying the workspace!
#
die() {
    builtin echo "ERROR: $*" >&2
    exit 1
}


tgtDir=tmp/isolated-merge
orgDir="$PWD"

script=$(basename -- $0)

command -v git || die "No git available"

readymsg() {
    builtin echo "$tgtDir is open for business"
}
statusmsg() {
    echo "====   Status of $tgtDir: ====" 
    git remote -v | sed 's/^/   /'
    git status | sed 's/^/   /' 
    echo
    echo "OK: You may now safely do maintenance with 'code .':"
    echo "  cd $tgtDir"
    echo "  code ." 
    echo 
    echo "  Be sure to commit + push when done."
}

[[ -f  $script ]] || die 101

command mkdir -p $tgtDir
[[ -d $tgtDir ]] || die 102

[[ -d $tgtDir/.git ]] && { 
    builtin cd $tgtDir && git pull parent || die "Failed to pull remote 'parent' in $PWD"
    readymsg; 
    exit 0; 
}

builtin cd $tgtDir || die 103
command rm -rf .git &>/dev/null

git clone  ../.. . || die "Failed cloning $PWD/../.."

cp ../../.git/config .git/ || die 104
git remote remove parent &>/dev/null

git remote add parent ../.. || die 105
git fetch parent

branch=$(git symbolic-ref HEAD --short)
[[ -n $branch ]] && {
    git checkout ${branch}
    git branch -u parent/${branch}
}

statusmsg
touch .ready



