# rbuzz_rcd-completion.bash
# vim: filetype=sh :

# Recommended: source this from .bashrc 

# bash completion support for tox / rbuzz_rcd
[[ -z $LmHome ]] && export LmHome=$HOME

if [[ -f ${LmHome}/bin/rbuzz_rcd ]]; then
	function tox {
	    while [[ ! -z $1 ]]; do
            local arg1=$1
            shift
            if [[ $1 =~ ^[0-9]+$ ]]; then
                local offset=${1} # If we match a number, interpret it as an offset in a list of matching dirs
                shift
            fi
            #echo "stub0: [$arg1] [$offset]" >&2
            local newDir="$($LmHome/bin/rbuzz_rcd ${arg1} ${offset} )"
            if [[ "${newDir:0:1}" == "!" ]]; then
                # rbuzz_rcd returned a command and we should run it:
                eval "${newDir:1}"
            elif [[ ! -z "$newDir" ]]; then
                pushd $newDir >/dev/null
            fi
        done
	}
else
	function tox {
		echo "This function only works if ${LmHome}/bin/rbuzz_rcd is present."
	}
fi

_tox()  # Here's our readline completion handler
{
    COMPREPLY=()
    local cur="${COMP_WORDS[COMP_CWORD]}"
    #echo "cur=[$cur]" >&2  Stub
    local toxfile=$(tox -q 2>&1 | egrep '^Index' | awk '{print $2'})

    local opts="$(cat ${toxfile})"

    COMPREPLY=( $(compgen -W "${opts}" -- ${cur}) )        
    return 0
}

complete -F _tox tox

