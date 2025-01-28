#!/bin/sh

if [ -z "$2" ] || [ ! -z "$3" ]
then
	printf 'usage: %s repo-name repo-description\n' "$0" >&2
	exit 1
fi

name="$(basename "$1" .git)"

hut git create "$name" -v public -d "$2"
gh repo create "$name" --disable-issues --disable-wiki -d "$2" --public -h "https://git.sr.ht/~runxiyu/$1"
berg --non-interactive repo create -n "$name" -d "$2" -p public --default-branch master
