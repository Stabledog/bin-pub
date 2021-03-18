#!/bin/bash
# code-sync-edit
#  Vscode has the ability to work as 'EDITOR' if you use the --wait flag.
# When the user closes the edit window, the shell process continues on.

code --wait "$@"
