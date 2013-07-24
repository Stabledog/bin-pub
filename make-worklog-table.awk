# Awk script companion to make-worklog-table bash script.

# Date stamps like >> 2013-12-07:
/^>> *20[0-9][0-9]-[0-9][0-9]-[0-9][0-9]/ {print NR " new_date -- " $0}

# Punch-ins+punch-outs, like 12:20pm >>
# We have a 4-way matrix to avoid coding string manipulation logic:
#  Bit 0 is "<<" vs ">>", Bit 1 is "am" vs "pm".
/^[0-9][0-9]?:[0-9][0-9] *am *>>/ { print NR " sess_start am " $0 }
/^[0-9][0-9]?:[0-9][0-9] *am *<</ { print NR " sess_end am " $0 }
/^[0-9][0-9]?:[0-9][0-9] *pm *>>/ { print NR " sess_start pm " $0 }
/^[0-9][0-9]?:[0-9][0-9] *pm *<</ { print NR " sess_end pm " $0 }


