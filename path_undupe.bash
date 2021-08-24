# vim: filetype=sh
# source this to de-duplicate dirs in PATH

path_undupe() {
    # Replace the value of PATH with ordered/unduplicated equivalent
    command which path_undupe.py &>/dev/null || return;
    local mypy=$(command which python3.9 python3.8 python3.7 | command head -n 1)
    [[ -z $mypy ]] && return;
    PATH=$( ${mypy} $(command which path_undupe.py) --unique )
}
