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

if raw:
    for path in raw.split(':'):
        path=path.rstrip('/')
        if not path:
            continue
        if path in already_appeared:
            if verbose:
                sys.stderr.write("skipping dupe: %s\n" % path)
            continue
        already_appeared[path]=True
        result.append(path.rstrip('/'))

    print(':'.join(result))





