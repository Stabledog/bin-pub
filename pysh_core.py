#pysh_core.py
import sys
import os
from os.path import isfile, isdir
from os import getcwd,  mkfifo,listdir, environ as env
from glob import glob
from sys import argv
from subprocess import check_output


class PyshCommands(object):
    '''Pysh provides unix-like shell helpers for the python interpreter, to be used in interactive mode.'''

    cin = sys.stdin
    cout = sys.stdout.write

    @property
    def xpudb(self, xtty=None):
        '''Launch pudb.remote on given tty'''
        from pudb.remote import set_trace
        set_trace()

    @property
    def cat(self,args):
        ''' Print file(s) to screen '''

    @property
    def ls(self, args="."):
        ''' List files in dir '''
        res=check_output(["ls"]+args.split())
        print( res)

    @property
    def cd(aprgs=env['HOME']):
        ''' Change current dir '''
        os.chdir(args)
        print(getcwd())

    @property
    def help(self):
        '''Print pysh help.'''
        eval('help(pysh)')
        # v='\n'.join(['pysh Help -'] + [ ':'.join( [d.__name__,d.__doc__ ]) for d in [cat,ls,cd] ])
        print(v)

pysh = PyshCommands()


if __name__ == "__main__":

    
    print('''You're in pysh (~/bin/pysh_core.py)
    phelp() can help.''')



