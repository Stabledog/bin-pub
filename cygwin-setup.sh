#!/bin/bash

# Run Cygwin's setup to add packages, with a bit less pain.
#
# Note: Cygwin's setup-???.exe takes a --help option that explains some of this.

cygwinPortsEnabled=false  # -p to enable the Cygwin ports repo
packageList=""            # List of packages to install
adminMode=false           # Enable with -a

sites="--site http://mirrors.kernel.org/sourceware/cygwin"


gpgKeys=""         # gpg keys to append to command line



function parseArgs {
    while  [[ ! -z $1 ]]; do
        case $1 in
            -p) 
                cygwinPortsEnabled=true
                gpgKeys="$gpgKeys http://cygwinports.org/ports.gpg"
                sites="$sites --site http://sourceware.mirrors.tds.net/pub/sourceware.org/cygwinports"
                ;;
             -a)
                adminMode=true
                ;;

             --help)
                echo "cygwin-setup.sh [-p][-a] [package-name ...]"
                echo "    -p:  Include Cygwin Ports repo"
                echo "    -a:  Install as admin (normally not needed, causes Windows prompt)"
                exit 1
                ;;
             *)
                packageList="$packageList $1"
                ;;
        esac
        shift
    done
}


function runSetup {
	cd /cygdrive/c/cygwin
	local cmdline="cygstart -- ./setup-x86.exe"

	# Append any gpg keys if such have been requested:
	if [[ ! -z $gpgKeys ]]; then
	    cmdline="$cmdline  -K $gpgKeys"
	fi

	# Do we need admin mode?
	if ! $adminMode; then
	    cmdline="$cmdline --no-admin"
	fi

	# If the caller didn't identify any packages, pick the 'chooser' mode:
	if [[ -z $packageList ]]; then
        cmdline="$cmdline -M"  # -M is chooser mode (semi-attended)
	else
	    cmdline="$cmdline -q"  # Unattended mode is -q
	fi

	if [[ ! -z $sites ]]; then
	    cmdline="$cmdline $sites"
	fi

	if [[ ! -z $packageList ]]; then
	    cmdline="$cmdline --packages $packageList"
	fi
	
	echo "Command line: $cmdline" >&2
	# Testing: put the command line on the clipboard:
	#echo "$cmdline" > /dev/clipboard
	$cmdline

}

if [[ -z $sourceMe ]]; then
	parseArgs $@
	runSetup
fi


