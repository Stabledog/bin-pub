#!/bin/bash
#shellcheck disable=2154
PS4='$( _0=$?; exec 2>/dev/null; realpath -- "${BASH_SOURCE[0]:-?}:${LINENO} ^$_0 ${FUNCNAME[0]:-?}()=>" ) '


export BEST_PY3

python3_select() {
    local cand;
    for cand in python3.{14..9} python3 python; do
        local py_cand="$( command which ${cand} 2>/dev/null)"
        [[ -n $py_cand ]] || continue
	    [[ -n $MSYS ]] && {
            "$py_cand" -c 'import sys; sys.exit(0)' &>/dev/null || continue
        } 
        [[ $py_cand == *python ]] && {
            # We can't use v2:
            local xver=$( python --version 2>/dev/null)
            [[ "$xver" == Python\ 3* ]] || continue
        }
        BEST_PY3="${py_cand}"
        break
    done
    [[ -n "$BEST_PY3" ]] || {
        echo "ERROR: no usable python3 on path" >&2; false; return;
    }
    echo "$BEST_PY3"
}

python3() {
    [[ -n ${BEST_PY3} ]] || {
        python3_select >/dev/null || { false; return; }
    }
    [[ $1 == "--detect" ]] && {
        echo "$BEST_PY3"
        [[ -n $BEST_PY3 ]]
        return
    }
    "$BEST_PY3" "$@"
}

[[ -z $sourceMe ]] && {
    python3 "$@"
}

