#!/bin/bash
# bashpy.template.sh
#
#  This is a starter template for creating scripts which combine bash and python code on one file.
#  Basically the bash calls the python code emitted from here-docs.

Script=$(readlink -f -- $0)
Scriptdir=$(dirname -- $Script)
Py=$(which python3.9 python3.8 python3.7 2>/dev/null | head -n 1)

die() {
    echo "ERROR: $@" >&2
    exit 1
}

emit_pyscript_1() {
    # Python code is wrapped in HERE-docs:
    cat << XEOF
# python:
import sys
print(sys.argv)
name=input("Enter your name:")
print(f"Hi! Your name is {name}")
XEOF
}

if [[ -z $sourceMe ]]; then
    [[ -z $Py ]] && die "\$Py not defined"

    # We redirect the output of a python emit function into the python interpreter and add args as needed:
    echo "Hello world" | $Py <(emit_pyscript_1) arg1 arg2
fi

