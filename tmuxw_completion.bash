# tmuxw_completion.bash

#source ~/bin/_completion_debug_monitor.bash  # stub

_tmuxw_lev0() {
    if [[ -n $TMUX ]]; then
        # If a session is live, don't list sessions
        echo "ls cwd"
        return
    fi
    local sessions="$(tmux ls 2>/dev/null | cut -d: -f1)"
    echo "${sessions}"
}

_tmuxw_completion() {
    local sessions=$(_tmuxw_lev0)
    #_cstb "sessions:${sessions}"
    COMPREPLY=( $(compgen -W "$(_tmuxw_lev0)" "${COMP_WORDS[${COMP_CWORD}]}" ) )
}

complete -F _tmuxw_completion tmuxw
complete -F _tmuxw_completion tw

