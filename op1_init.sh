# op1_init.sh
#
#  Reduce repetitive typing in op1 windows.  Load clipboard with 'op1-copy'
#

# implicit directory for some commands:
Xpwd=$PWD   

# implicit service name:
#
Xsvc=
Xlogdir=/bb/logs/mars
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
eqstst /bb/logs/mars eqstst
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
    eval "$(cat)"
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

# Show one or more logs for service: same params as list_logs
function less_logs {
    less $(list_logs $@)
}

function actlog_grep {
    cat /bb/data/act.log | grep "$*"
}

function help {
    echo "
actlog_grep {pattern}                         # Grep act.log for given pattern
less_logs {service-name|.} {filename-tail}    # Show logs for service-name, ascending-date
list_logs {service-name|.} {filename-tail}    # Show filenames of logs for service-name, ascending-date 
Xeval                                         # Input script text
set_svc {service-name}                        # Set Xsvc, implicit argument for commands that need a service name
# Notes:
#    1.  the '.', when supplied in place of a service-name, refers to the 'current service', which
#        can be set with 'set_svc'
"
}



