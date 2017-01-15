# mars-shtool-genl.sh
#
#   General (user-independent) shell tools for MARS
#

function errExit {
    echo "ERROR: $@" >&2
    exit 1
}

function errPrint {
    echo "ERROR: $@" >&2
}

function cd_root {
    # cd to the git repo root
    cd $(git rev-parse --show-toplevel )
}

function environ_sanity_check {
    # There should be xbd5 on the path...
    local ok=true

    type -a xbd5 &>/dev/null || { ok=false ; errPrint "xbd5 is not on the PATH" ; }

    if [[ -z $MARSTOP ]]; then 
        ok=false; errPrint "MARSTOP is not defined"
    else
        [[ -d $MARSTOP ]] || { ok=false; errPrint "Dir $MARSTOP doesn't exist" ; }
    fi

    if ! $ok; then
        echo "One or more environment errors found." >&2
        false
        return
    fi
    true
}


function xbd_build {
    environ_sanity_check || return

    (
        export MARS_CHECK_EX_TIMESTAMPS=false
        cd_root 
        mkdir -p build
        cd build

        xbd5 init --branch=ccache  ../ || errExit "0x1525"

        #xbd5 make --ccache  -tS --check=gcc-wall  xapapp3.tsk
        xbd5 make --ccache  -tS   xapapp3.tsk || errExit "0x1526"
    ) || exit 1

    echo "xbd_build completed normally"    
}


