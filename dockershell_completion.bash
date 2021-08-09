# dockershell_completion.bash

_dockershell_targets() {
    docker ps --format "{{.Names}}"
}

_dockershell_completion() {
    COMPREPLY=( $(compgen -W "$(_dockershell_targets)" "${COMP_WORDS[${COMP_CWORD}]}" ) )
}

complete -F _dockershell_completion dockershell.sh
complete -F _dockershell_completion docksh

