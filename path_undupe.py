#!/usr/bin/env python
# path_undupe.py

# Given a colon-delimited input path as $1, print
# the de-duplicated version, such that if path X appears
# in the sequence, any subsequent appearance of X is eliminated

import sys

already_appeared={}

if sys.argv[1:]:
    for path in sys.argv[1].split(':'):
        if path in already_appeared:
            continue
        print(path)
        already_appeared[path]=True




