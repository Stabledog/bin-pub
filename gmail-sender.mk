#!/usr/bin/make -f

SHELL=/bin/bash
.ONESHELL:

Sender=stabledog@gmail.com
KeyExists=$(shell test -e ~/.ssh/gmail-app-pwd && echo true || echo false)
GitAvail=$(shell which git &>/dev/null && echo true || echo false)

Config:
	@set -ue
	cat <<EOF
	Sender=$(Sender)
	KeyExists=$(KeyExists)
	GitAvail=$(GitAvail)
	EOF

~/.ssh/gmail-app-pwd:
	@set -ue
	cat <<EOF >&2
	1. Go to  https://myaccount.google.com/apppasswords and log into the $(Sender) account.
	2. Do the 2FA authentication,
	   . Select app: Mail
	   . Select device: Other (custom name)
	   . Provide label, e.g. 'Linux scripts'
	   . Click "Generate" and copy the code to clipboard
	3. Paste into this terminal:
	EOF
	read pwcode
	echo "$$pwcode" > $@
	echo "OK: created $@: $$(cat $@)" >&2



