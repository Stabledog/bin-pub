#!/bin/bash
# taskrc.sh

xbin=$(cd ~/projects; realpath .)
${xbin}/taskrc-kit/bin/taskrc.sh "$@"
