# op1_init.sh
#
#  Reduce repetitive typing in op1 windows.  Load clipboard with 'op1-copy'
#

# implicit directory for some commands:
Xpwd=$PWD   

# implicit service name:
#
Xsvc=
Xlogdir=/bb/data
Xlogbase=


alias reset='clear '
alias ll='ls -al'
alias lr='ls -lirt'
alias l1='ls -1rt'
alias la='ls -a'


function view {
    less
}

function logMap {
    # Columns are [key] [log dir] [logfile basename]
    echo "
eqstst /bb/data/tmp eqstst
xapp1 /bb/logs/mars xapp1
xapp4 /bb/logs/mars xapp4
xapp3 /bb/logs/mars xapp3
"
}


function set_svc {
    # Set the current service name:
    Xsvc=$1
    # Load the attributes for this service:
    Xlogdir=$( logMap | grep "^${Xsvc} " | cut -d ' ' -f 2 )
    Xlogbase=$( logMap | grep "^${Xsvc} " | cut -d ' ' -f 3 )

}



set_svc eqstst

function Xeval {
    # Workaround the weaknesses of the X clipboard in Xceeed:
    tx1="$(cat)"
    eval "$tx1"
}

# List the latest logfiles for service:
function list_logs {
    loc_svc=$1
    # You can use '.' to represent the value of Xsvc 
    if [ -z $loc_svc ] || [ "$loc_svc" == "." ]; then
       loc_svc="${Xsvc}"
    fi
    set_svc $loc_svc

    ls -1rt ${Xlogdir}/${Xlogbase}*$2
}

function help {
    echo "
list_logs {service-name|.} {filename-tail}    # Show filenames of logs for service-name
Xeval                                         # Input script text
set_svc {service-name}                        # Set Xsvc, implicit argument for commands that need a service name
"
}



