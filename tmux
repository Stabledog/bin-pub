#!/bin/bash

# Whack things around so tmux will run
#

cd $MYLIBS/bin
LD_LIBRARY_PATH=$PWD:$MYLIBS/lib exec ./_tmux 

