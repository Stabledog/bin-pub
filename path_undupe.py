#!/usr/bin/env python
# path_undupe.py

# Given a colon-delimited input path as $1, print
# the de-duplicated version, such that if path X appears
# in the sequence, any subsequent appearance of X is eliminated

import sys

args=list(sys.argv[1:])
verbose=False
if args[0] == '-v':
    verbose=True
    args=args[1:]
raw = ' '.join(args)

already_appeared={}
result=[]

windirs=['/c/program files','/c/windows','/c/users','/c/program data']

if raw:
    for path in raw.split(':'):
        path=path.rstrip('/')
        if not path:
            continue
        key = path
        for p in windirs:
            # Dupe detection for windows dirs should be case-insensitive
            if path.lower().startswith(p):
                key=path.lower()
                break
        if key in already_appeared:
            if verbose:
                sys.stderr.write("skipping dupe: %s\n" % path)
            continue
        already_appeared[key]=True
        result.append(path.rstrip('/'))

    print(':'.join(result))





