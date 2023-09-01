#!/bin/make -f
#  For mapping all git repos in a tree and their remotes.
#
#  Basic usage:
#     - cd & bin/git-map.mk map
#         Map entire HOME tree.  Output goes to stdout and ~/.git-map.mk.d/git-map.log

SHELL=/bin/bash
.ONESHELL:

StartDir=$(shell pwd)
CacheDir=$(HOME)/.git-map.mk.d
Logfile=$(CacheDir)/git-map.log
Mypid:=$(shell ps -o ppid $$$$ | tail -n 1 | tr -d [:space:] )
TmpLog=$(CacheDir)/tmp-$(Mypid).log
TmpTreeList=$(CacheDir)/tmp-$(Mypid).trees

print_git_remotes=git remote -v  | grep fetch | sed -e "s,^,{}/," -e "s,[(]fetch[)],,"
# ^^ Offered to xargs, we cd into the target dir, print its remotes and branch, and prefix with the dirname for correlation

print_git_branch=git branch 2>/dev/null | awk "/[*]/ {print \"$$PWD\\tbranch=\" \$$2}" | sed "s,[()],,"

invoke_xargs_parallel=xargs -I {} -P $$(nproc) -n 1
# ^^cmdline for xargs which runs 1 arg at a time against number of available processors.


Config:
	@set -ue
	cat <<-EOF
	StartDir=$(StartDir)
	CacheDir=$(CacheDir)
	Logfile=$(Logfile)
	Mypid=$(Mypid)
	TmpTreeList=$(TmpTreeList)
	EOF

$(TmpTreeList):
	@set -ue
	cd $(StartDir)
	find $(StartDir) -type d -name '.git' | sed -e 's,/\.git$,,,' | tee $(TmpTreeList)

$(TmpLog): $(TmpTreeList)
	@set -ue
	cat $< | $(invoke_xargs_parallel) -- bash -c 'cd {}; $(print_git_remotes); $(print_git_branch)' | sort | tee $@

$(CacheDir):
	@set -ue
	mkdir -p $@

.PHONY: .forever
.forever:


$(Logfile): $(CacheDir) .forever $(TmpLog)
	@set -ue
	echo "Done: $@ ok"

map: clean-tmp $(Logfile)
	@set -ue
	echo "Ok: $@"

clean-tmp:
	@set -ue
	rm $(TmpLog) $(TmpTreeList) 2>/dev/null|| :
