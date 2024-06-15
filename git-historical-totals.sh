git log --numstat --pretty= | awk '{added += $1; removed += $2} END { print "total added: " added; print "total removed: " removed; }'
