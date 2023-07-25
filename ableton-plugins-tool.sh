#!/bin/bash
# waves-plugin-fix.sh

scriptName="$(readlink -f "$0")"
scriptDir=$(command dirname -- "${scriptName}")

die() {
    builtin echo "ERROR($(basename ${scriptName})): $*" >&2
    builtin exit 1
}

[[ -z ${sourceMe} ]] && {
    [[ -L ~/program-files ]] || exit 19
    {
        echo Ableton plugin maintenance:
        echo VST Plugins must sometimes be copied to the Ableton VST3 folder.
        echo The following folders may be involved
    } >&2

    cat <<-EOF
    waves-install-location "C:\Program Files\Native Instruments\VSTPlugins 64 bit"
    ableton-main "C:\Program Files\Common Files\VST3"
EOF

    builtin exit
}
command true

