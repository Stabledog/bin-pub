#!/bin/bash
# The name says it all
#

die() {
    echo "ERROR: $@" >&2
    exit 1
}

command -v python3 &>/dev/null || die "\python3 not set"

infile=settings.json

if [[ -n $1 ]]; then
    if [[ ! -f $1 ]]; then
        die Can\'t find $1 in $PWD
    fi
    infile="$1"
fi


mkdir -p tmp
bakfile=tmp/${infile}.$RANDOM
cp ${infile} $bakfile || die Failed making backup $bakfile
echo "Backup of ${infile} is $bakfile"

rm tmp/${infile}.{10,20} &>/dev/null

< ${infile} /usr/bin/tr -d '\r' > tmp/${infile}.10


sort_json_py() {
   cat <<- EOF
from json import dumps,loads
with open("$1","r") as f_1:
    obj=loads(f_1.read())
print(dumps(obj,indent=4,sort_keys=True))
EOF
}


sort_json_py ./tmp/${infile}.10 | python3 > ./tmp/${infile}.20
[[ $? == 0 ]] || die Python filter failed

[[ -f ./tmp/${infile}.20 ]] || fail step 20

mv tmp/${infile}.20 ${infile} || die fail step 20b

echo "${infile} reformat OK"


