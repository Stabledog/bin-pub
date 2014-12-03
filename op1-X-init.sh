#!/bin/bash

# op1-X-init.sh
#
# Copies op1_init.sh to the X clipboard.  Does not assume any particular shell
# configuration.   If xclip isn't found on the path, we remote-invoke on sdv9

remoteHost=sundev9
[ -z $XCLIP ] && XCLIP=$MYLIBS/bin/xclip
XXCLIP=$HOME/mylibs/sun/bin/xclip


if [ -x $XCLIP ]; then
    cat $HOME/bin/op1_init.sh | $XCLIP
    echo "op1_init.sh has been copied to the X clipboard.  Use Xeval in the target window,"
    echo "or this:"
    echo "   eval \"\$(cat)\" "
    if [ ! -z $bySsh ]; then
        echo "Press Ctrl+C after pasting to quit this ssh shell."
    fi
    exit 0
fi

echo "Running op1-X-init.sh on ${remoteHost}:"
ssh  -Y ${remoteHost} "XCLIP=$XXCLIP bySsh=true $HOME/bin/op1-X-init.sh"

