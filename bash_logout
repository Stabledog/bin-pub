# ~/.bash_logout: executed by bash(1) when login shell exits.

# when leaving the console clear the screen to increase privacy

if [[ -n $HISTFILE ]]; then
    history -w
    histfile-cleanup.sh $HISTFILE &>/dev/null && echo "HISTFILE cleaned and updated" >&2
fi
