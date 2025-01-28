#!/bin/bash                            
#
# Written by Runxi Yu <me@runxiyu.org>
# Public domain / CC0
# 
# Usage:
# 1. Prepend command="/path/to/this/script" to a key line in
#    authorized_keys on the server
# 2. Generate or otherwise have a git-specific SSH key on the client
# 3. Configure the client's .ssh/config such as:
#    host rxgit
#        user me
#        hostname runxiyu.org
#        port 22
#        identityfile ~/.ssh/id_ed25519_git
# 4. Now, git clone rxgit:relative_path will use /srv/git/relative_path
#    instead, while absolute paths are unaffected.
#

declare -a "s=($SSH_ORIGINAL_COMMAND)" 
p="${s[1]}"
[ "$p" = "${p#/}" ] && p=/srv/git/"$p"
[ -d "$p" ] || (mkdir "$p" && cd "$p" && git init --bare --shared >&2 && printf "Warning: Repository at %s did not exist and was just created\n" "$p" >&2)
exec git-shell -c "${s[0]} ${p@Q}"
