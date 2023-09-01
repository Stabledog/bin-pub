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
Logname=git-map.log
Logfile=$(CacheDir)/$(Logname)
Treename=git-map.trees
Treesfile=$(CacheDir)/$(Treename)
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
	Logname=$(Logname)
	Treename=$(Treename)
	Logfile=$(Logfile)
	Treesfile=$(Treesfile)
	EOF

$(TmpTreeList):
	@set -ue
	set -x
	cd $(StartDir)
	find $(StartDir) -type d -name '.git' | sed -e 's,/\.git$,,,' | sort | tee $(TmpTreeList)

$(TmpLog): $(TmpTreeList)
	@set -u
	set -x
	cat $< | $(invoke_xargs_parallel) -- bash -c 'cd {}; $(print_git_remotes); $(print_git_branch)' | sort | tee $(TmpLog)

stub1: $(TmpLog)

$(CacheDir):
	@set -ue
	tmpDir=$@.$(Mypid)
	mkdir -p $$tmpDir
	cd $$tmpDir
	touch ./$(Treename)
	touch ./$(Logname)
	echo 'tmp-*' >> .gitignore
	git init
	git add .
	git commit -m "Initial cache created"
	cd ..
	mv $$tmpDir $@



.PHONY: .forever
.forever:


$(Logfile): $(CacheDir) .forever $(TmpTreeList) $(TmpLog)
	@set -ue
	set -x
	mv $(TmpTreeList) $(Treesfile)
	mv $(TmpLog) $(Logfile)
	echo "Done: $@ ok"



map: $(Logfile)
	@set -ue
	cd $(CacheDir)
	git add .
	git commit -m "Updated $$(date -Iseconds)"
	echo "Ok: $@ updated"

clean-tmp:
	@set -ue
	rm $(TmpLog) $(TmpTreeList) 2>/dev/null|| :
