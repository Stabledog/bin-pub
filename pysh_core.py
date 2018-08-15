#pysh_core.py
import sys
import os
from os.path import isfile, isdir
from os import getcwd,  mkfifo,listdir, environ as env
from glob import glob
from sys import argv
from subprocess import check_output

cin = sys.stdin
cout = sys.stdout.write

def xpudb(xtty):
    '''Launch pudb.remote on given tty'''
    from pudb.remote import set_trace
    set_trace()

def cat(args):
    """ Print file(s) to screen """

def ls(args="."):
    """ List files in dir """
    res=check_output(["ls"]+args.split())
    print res

def cd(args=env['HOME']):
    """ Change current dir """
    os.chdir(args)
    print(getcwd())

def phelp():
    v='\n'.join(['pysh Help -'] + [ ':'.join( [d.__name__,d.__doc__ ]) for d in [cat,ls,cd] ])
    print(v)

if __name__ == "__main__":

    
    print('''You're in pysh (~/bin/pysh_core.py)
    phelp() can help.''')



