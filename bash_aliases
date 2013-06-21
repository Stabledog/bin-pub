#!/bin/bash
#  ~/bin/bash_aliases for lmatheson

# Whenever displaying the prompt, write the previous line to disk
export PROMPT_COMMAND="history -a"

# Directory listing
alias ll='ls -alF' --color=none
alias la='ls -A'
alias l='ls -CF'

# Editing
alias gopen='gnome-open'

# Bash history
alias his=history
alias hisg='history | grep '

# Navigation
alias pd='pushd '

function dpList {
    dirs -p
    echo "(cancel)"
}

function dp {
    select wxdir in $(dirs -p); do
        if [[ "$wxdir" == "(cancel)" ]]; then
            return
        fi
        eval "pushd $wxdir"
        return
    done
}

function chrome {
    if ! which chromium-browser &>/dev/null; then
		echo "We need to install Chrome for this command:"
		sudo apt-get install chromium-browser || return
	fi
	chromium-browser &>/dev/null &
}





# set a fancy prompt (non-color, unless we know we "want" color)
case "$TERM" in
    xterm-color) color_prompt=yes;;
esac

# uncomment for a colored prompt, if the terminal has the capability; turned
# off by default to not distract the user: the focus in a terminal window
# should be on the output of commands, not on the prompt
force_color_prompt=yes

if [ -n "$force_color_prompt" ]; then
    if [ -x /usr/bin/tput ] && tput setaf 1 >&/dev/null; then
	# We have color support; assume it's compliant with Ecma-48
	# (ISO/IEC-6429). (Lack of such support is extremely rare, and such
	# a case would tend to support setf rather than setaf.)
	color_prompt=yes
    else
	color_prompt=
    fi
fi

if [ "$color_prompt" = yes ]; then
    PS1='${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\$ '
else
    PS1='${debian_chroot:+($debian_chroot)}\u@\h:\w\$ '
fi
unset color_prompt force_color_prompt

# If this is an xterm set the title to user@host:dir
case "$TERM" in
xterm*|rxvt*)
    PS1="\[\e]0;${debian_chroot:+($debian_chroot)}\u@\h: \w\a\]$PS1"
    ;;
*)
    ;;
esac

# enable color support of ls and also add handy aliases
if [ -x /usr/bin/dircolors ]; then
    test -r ~/.dircolors && eval "$(dircolors -b ~/.dircolors)" || eval "$(dircolors -b)"
    alias ls='ls --color=auto'
    #alias dir='dir --color=auto'
    #alias vdir='vdir --color=auto'

    alias grep='grep --color=auto'
    alias fgrep='fgrep --color=auto'
    alias egrep='egrep --color=auto'
fi


# When doing an ssh -Y into another box, this makes many gnome apps behave:
alias dbus-up='export $(dbus-launch)'

# Usage: popup {msg}
alias popup='zenity --info --text '

# A new bash script is handy:
function newBashScript {
	local orgArgs="$@"
	while [[ "$1" != "" ]]; do
		if [[ ! -f $1 ]]; then
			echo "#!/bin/bash
# $1

function errExit {
    echo \"ERROR: \$1\" >&2
    exit 1
}
" > $1
		else
			echo "$1 already exists"
		fi
		chmod +x $1
		shift
	done

	$EDITOR $orgArgs
}


function pathadd () {
    if ! echo $PATH | /bin/egrep -q "(^|:)$1($|:)" ; then
       if [ "$2" = "after" ] ; then
          PATH=$PATH:$1
       else
          PATH=$1:$PATH
       fi
    fi
}

# Adds the current directory to the PATH:
alias addpath='pathadd $PWD'

# Pipe aids
alias cutc='cut -c '

# Environment
alias envg='set | grep '

# Remove tabs from a file
function removeTabs {
	if [[ -z $1 ]]; then
		echo "Usage: removeTabs [file]"
		return
	fi
	cat "$1" | expand -t 4 > /tmp/killtabs && mv /tmp/killtabs "$1"
}

alias tabsRemove='removeTabs '

# process management
alias psg='ps aux | grep '
alias kill9='kill -9 '
alias kill1='kill -9 %1 '
alias kill2='kill -9 %2 '


alias dddmake='ddd --make ./GNUmakefile '

repeat() {
    n=$1
    shift
    while [ $(( n -= 1 )) -ge 0 ]
    do
        "$@"
    done
}

export SVN_EDITOR=vim

function gitdiff {
	if ! which diffuse >/dev/null; then
		echo "Sorry, diffuse not installed.  Try {yum|apt-get} diffuse" >&2
		false
		return
	fi

	git difftool -t diffuse "$@"
}

function git-commit {
	# Whatever we get as params is the message, and we push afterward:
	git commit -am "$@"  && git push
}

function gitstatus {
	git status
}

alias et='myEdit -t '

alias e='myEdit '
alias ek='myEdit -k '

if ! [[ "$PATH" =~ "$HOME/bin" ]]; then
    export PATH="$PATH:$HOME/bin"
fi

# Show that we're currently in a vim shell, if so:
alias invim='pstree | grep -B1 pstree | grep vim'

