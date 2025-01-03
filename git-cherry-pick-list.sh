#!/bin/bash

main() {
    PS4='+$?( $(realpath ${BASH_SOURCE[0]}):${LINENO} ): ${FUNCNAME[0]:+${FUNCNAME[0]}(): }'
    set -ue

    # Function to display usage
    usage() {
        echo "Usage: $0 [-r|--restart] <branch>"
        exit 1
    }

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
    if [ -z "${BRANCH:-}" ]; then
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
        git log --reverse --pretty=format:"%H %s" "main..${BRANCH}" > /tmp/cherry-pick-list.txt
    fi
    # Open the list in the editor
    $EDITOR /tmp/cherry-pick-list.txt

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
                q) return 1 ;;
                *) echo "Invalid option" >&2 ; echo ;;
            esac
        done
    }

    # Read the edited list and cherry-pick commits
    exec 3</tmp/cherry-pick-list.txt
    while read -r commit message <&3; do
        git cherry-pick --no-commit "$commit" || {
            echo "WARNING: git cherry-pick failed. "
        }
        # Now you can edit the changes before committing
        echo "Picking:"
        echo "    Commit=$commit"
        echo "    Message=\"$message\""
        echo
        echo "Entering review shell. Do 'exit 0' to see post-shell options, or 'exit 1' to abort."
        Commit=$commit Message="$message" Ps1Tail="cherry-pick" bash
        post_review_options "$commit" "$message" || break
    done

    # Clean up
    rm /tmp/cherry-pick-list.txt

    echo "Cherry-picking completed."
}

main "$@"
