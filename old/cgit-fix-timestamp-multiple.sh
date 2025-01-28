#!/bin/sh

root="$(pwd)"

cd "$root"

for each in $(find -name '*.git') # assume no whitespace :D
do
	cd "$each"
	git for-each-ref \
		--sort=-authordate --count=1 \
		--format='%(authordate:iso8601)'
	cd "$root"
done
