#!/bin/sh

agefile="$(git rev-parse --git-dir)"/info/web/last-modified

mkdir -p "$(dirname "$agefile")" &&
git for-each-ref \
	--sort=-authordate --count=1 \
	--format='%(authordate:iso8601)' \
	>"$agefile"
