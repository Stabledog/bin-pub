#!/bin/bash

# Check if branch name is provided
if [ -z "$1" ]; then
  echo "Usage: $0 <branch>"
  exit 1
fi

set -ue

BRANCH=$1
EDITOR=${EDITOR:-vim}  # Use nano as default editor if $EDITOR is not set

# Generate the list of commits
git log --reverse --pretty=format:"%H %s" "main..${BRANCH}" > /tmp/cherry-pick-list.txt

# Open the list in the editor
$EDITOR /tmp/cherry-pick-list.txt

post_review_options() {
    local commit=$1
    local message="$2"
    while true; do
        echo "(1) Commit with message \"$message\""
        echo "(2) Edit commit message and then commit"
        echo "(3) Discard staged changes and move on"
        echo "(q) Quit"
        read -rp "Select an option: " option
        case $option in
            1) git commit -m "$message"; return 0 ;;
            2) git commit ; return 0 ;;
            3) git reset --hard HEAD; return 0 ;;
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
    if ! Commit=$commit Message="$message" Ps1Tail="cherry-pick" bash; then
        echo "User abort"
        exit 1
    fi
    if ! post_review_options "$commit" "$message"; then
        exit 1
    fi
done 

# Clean up
rm /tmp/cherry-pick-list.txt

echo "Cherry-picking completed."
