#!/bin/bash
# dockershell.sh -- open a shell or run shell command on a docker container.
# suggest alias 'docksh'

die() {
    echo "ERROR: $@" >&1
    exit 1
}

show_containers() {
    echo "Running containers:"
    echo "-------------------"
    docker ps --format "{{.Names}}"
    echo
}

container=$1
shift
[[ -z $container ]] && { show_containers; die "Container name required"; }

if (( $# > 0 )); then
    docker exec $container $@
else
    docker exec -it $container bash
fi
