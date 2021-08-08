# _completion_debug_monitor.bash
# Debug monitor for bash completion debugging:

#  1. Add "_cstb_term [context-tag]" calls in your completion function
#  2. Set "_cstb_term /path/to/tty" in the testing window, pointing to a monitor tty
#  3. Each time _cstb_term() is called, diagnostics show in the monitor tty

_cstb() {
    [[ -z $_cstb_term ]] && return;
    local _yellow="\033[;33m"; _green="\033[;32m"; _norm="\033[;0m"
    echo > $_cstb_term
    echo -e "${_yellow}--- _cstb: $@ ---${_norm}" > $_cstb_term
    echo "  COMP_CWORD:${COMP_CWORD}" > $_cstb_term
    local cw=0
    until [[ $cw -ge  ${#COMP_WORDS[@]} ]]; do
        (( cw == COMP_CWORD )) && echo -ne "${_green}" > $_cstb_term
        echo -e "    COMP_WORDS[$cw]: ${COMP_WORDS[$cw]}${_norm}" > $_cstb_term
        (( cw++ ))
    done
    echo "  COMP_LINE: [${COMP_LINE}]" > $_cstb_term
    echo "  COMPREPLY: [${COMPREPLY[@]}]" > $_cstb_term
}

