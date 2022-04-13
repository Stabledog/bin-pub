#!/bin/bash
# dockershell.sh -- open a shell or run shell command on a docker container.
# suggest alias 'docksh'

die() {
    echo "ERROR: $@" >&1
    exit 1
}

show_containers() {
    docker ps --format "{{.Names}}"
}

pick_container() {
    select result in $(show_containers); do
        echo "$result"
        return
    done
}

main() {
    if (( $# > 0 )); then
        docker exec $container $@
    else
        docker exec -it $container bash
    fi
}

if [[ -z $sourceMe ]]; then

    container=$1
    shift
    [[ -z $container ]] && { 
        container=$(pick_container)
        [[ -z $container ]] && { command docker ps; exit 1; }
    }

    main "$@"
fi
