#!/bin/sh

root="$(pwd)"

cd "$root"

for each in $(find -name '*.git') # assume no whitespace :D
do
	cd "$each"
	agefile="$(git rev-parse --git-dir)"/info/web/last-modified
	mkdir -p "$(dirname "$agefile")" &&
	git for-each-ref \
		--sort=-authordate --count=1 \
		--format='%(authordate:iso8601)' \
		>"$agefile"
	cd "$root"
done
