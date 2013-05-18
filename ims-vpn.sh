#!/bin/bash

# ims-vpn.sh - connect to IMS VPN (expects /etc/vpnc/ims.conf)
#
function connect {
	export TESTSERVER=192.168.1.23
	ping -c 1 -t 3 $TESTSERVER
	if [ $? -eq 0 ]; then
		echo "IMS Network is already connected"
		exit 0
	fi
	sudo vpnc ims
	ping -c 2 -t 3 $TESTSERVER
	if [ $? -ne 0 ]; then
		echo "PING to $TESTSERVER failed!"
		exit 1
	fi
	echo "VPN connected successfully."
}


if [[ "$1" == "-d" ]]; then
	sudo vpnc-disconnect
else
	connect
fi
