#!/bin/bash                            
declare -a "s=($SSH_ORIGINAL_COMMAND)" 
p="${s[1]}"                            
[ "$p" = "${p#/}" ] && p=/srv/git/"$p" 
exec git-shell -c "${s[0]} ${p@Q}"     
