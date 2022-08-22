#!/bin/bash
# python-from-scratch
#

PyVer=3.10.5

die() {
    echo "ERROR: $*" >&2
    exit 1
}

mkdir -p /tmp/py-from-scratch 

cd /tmp/py-from-scratch || die 100
rm -rf ./


apt install -y wget build-essential libreadline-dev libncursesw5-dev libssl-dev libsqlite3-dev tk-dev libgdbm-dev libc6-dev libbz2-dev libffi-dev zlib1g-dev || die 101

wget -c https://www.python.org/ftp/python/${PyVer}/Python-${PyVer}.tar.xz || die 102


tar -Jxf Python-${PyVer}.tar.xz  || die 103


cd Python-${PyVer} || die 104

./configure --enable-optimizations || die 105

make altinstall -j4 || die 106

python3.10 --version || die 107


