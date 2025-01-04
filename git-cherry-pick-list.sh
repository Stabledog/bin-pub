#!/bin/bash

post_review_options() {
    local commit=$1
    local message="$2"
    while true; do
        echo "(1) Commit with message \"$message\""
        echo "(2) Edit commit message and then commit"
        echo "(3) Discard staged changes and move on"
        echo "(4) Blindly forward (add more cherries to this bag)"
        echo "-----"
        echo "(q) Quit"
        echo
        read -rp "Select an option: " option
        case $option in
            1) git commit -m "$message"; return 0 ;;
            2) git commit ; return 0 ;;
            3) git reset --hard HEAD; return 0 ;;
            4) return 0 ;;
            q) echo "Quitting.  If you wish to restart with the same pick list, use -r|--restart"; exit 1;;
            *) echo "Invalid option" >&2 ; echo ;;
        esac
    done
}

mark_reconciled_branch() {
    local branch="$1"
    local cur_branch
    cur_branch="$(git rev-parse --abbrev-ref HEAD)"
    echo "All commits have been cherry-picked from ${branch}."
    echo "Should I mark \"${cur_branch}\" with an empty merge commit? (This will prevent "
    echo "re-merging of the same lineage, counting them as reconciled.)"
    echo 
    read -rp "Mark \"${cur_branch}\" now (Y/n)? " answer
    if [[ "$answer" =~ [yY] ]]; then
        git merge --strategy=ours "${branch}" -m "Reconciled with ${branch} by cherry-picking."
    fi
}

# Function to display usage
usage() {
    local scr
    scr=$(basename -- "$0")
    echo "Usage: " 
    echo "   $scr <branch>"
    echo "     Create a new picklist, edit it, then loop over them with review for each"
    echo "   $scr [-r|--restart]"
    echo "     Restart the picklist from the previous run"
    exit 1
}


main() {
    PS4='+$?( $(realpath ${BASH_SOURCE[0]}):${LINENO} ): ${FUNCNAME[0]:+${FUNCNAME[0]}(): }'
    set -ue

    # Initialize variables
    RESTART=false

    # Parse command line options
    while [[ $# -gt 0 ]]; do
        case $1 in
            -r|--restart)
                RESTART=true
                shift
                ;;
            -*)
                usage
                ;;
            *)
                BRANCH=$1
                shift
                ;;
        esac
    done

    # Check if branch name is provided
    BRANCH=${BRANCH:-$(cat /tmp/git-cherry-pick-branch 2>/dev/null)}
    if [[ -z "${BRANCH}" ]]; then
        usage
    fi

    EDITOR=${EDITOR:-vim}  # Use vim as default editor if $EDITOR is not set
    # Generate the list of commits if not restarting
    if [[ "$RESTART" == true ]]; then
        cp /tmp/cherry-pick-list.txt.previous /tmp/cherry-pick-list.txt || {
            echo "ERROR: Could not find previous cherry-pick list. Please run without --restart option." >&2
            exit 1
        }
    else
        cur_branch="$(git rev-parse --abbrev-ref HEAD)"
        git log --reverse --pretty=format:"%H %s" "$cur_branch..${BRANCH}" > /tmp/cherry-pick-list.txt
    fi
    # Open the list in the editor
    $EDITOR /tmp/cherry-pick-list.txt
    cp /tmp/cherry-pick-list.txt /tmp/cherry-pick-list.txt.previous
    [[ -n ${BRANCH} ]] && \
        echo "${BRANCH}" > /tmp/cherry-pick-list-branch


    # Read the edited list and cherry-pick commits
    exec 3</tmp/cherry-pick-list.txt
    while read -r commit message <&3; do
        if git cherry-pick --no-commit "$commit"; then 
            git reset  # Unstage the changes
        else 
            echo "WARNING: git cherry-pick failed. "
        fi
        # Now you can edit the changes before committing
        echo "Picking:"
        echo "    Commit=$commit"
        echo "    Message=\"$message\""
        echo
        echo "Entering review shell. Do 'exit 0' to see post-shell options, or 'exit 1' to abort."
        Commit=$commit Message="$message" Ps1Tail="cherry-pick" bash
        post_review_options "$commit" "$message" || break
    done

    [[ -f /tmp/cherry-pick-list-branch ]] && {
        mark_reconciled_branch "$(cat /tmp/cherry-pick-list-branch)"
        rm /tmp/cherry-pick-list-branch
    }
    
    rm /tmp/cherry-pick-list.txt

}

main "$@"
