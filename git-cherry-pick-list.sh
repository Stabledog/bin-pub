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

# Read the edited list and cherry-pick commits
exec 3</tmp/cherry-pick-list.txt
while read -r commit message <&3; do
  git cherry-pick --no-commit "$commit"
  # Now you can edit the changes before committing
  echo "Picking:"
  echo "    Commit=$commit"
  echo "    Message=\"$message\""
  echo
  echo "It is up to you to commit the change, edit it,  or skip it.  Do \"exit 0\" to continue with next commit."
  if ! Commit=$commit Message="$message" Ps1Tail="cherry-pick" bash; then
    echo "abort"
    exit 1
  fi
done 

# Clean up
rm /tmp/cherry-pick-list.txt

echo "Cherry-picking completed."
