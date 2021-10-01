#!/usr/bin/env python3
# path_undupe.py
import sys
import os
from typing import List

def make_counts(path:str, delim=':') -> List[str]:
    ''' Returns
    [a] ordered list of [path,count]
    [b] set of {dupes} '''
    known={}
    dupes={}
    ordered=[]
    for pp in path.split(delim):
        if not pp:
            continue
        if pp in known:
            known[pp] += 1
            if known[pp] == 2:
                dupes[pp] = True
        else:
            known[pp] = 1
            ordered.append(pp)
    return [ ( px, known[px] ) for px in ordered ], set(dupes.keys())



if __name__=="__main__":
    path=os.environ['PATH']
    if len(sys.argv)==1:
        ord,dup=make_counts(path)
        print('--- All: ---')
        [ print('%s %s' % (o[0],o[1])) for o in ord ]
        print('--- Dupes: ---')
        print(dup)

    elif sys.argv[1] in ['-l',"--list-duplicates"]:
        ord,_=make_counts(path,':')
        for vv in ord:
            if vv[1] > 1:
                print("%s %s" % (vv[0],vv[1]))

    elif sys.argv[1] in ['-u','--unique']:
        ord,_=make_counts(path,':')
        items=[vv[0] for vv in ord ]
        print(':'.join(items))

