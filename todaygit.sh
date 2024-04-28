#!/bin/sh
exec faketime -m -f "@$(date --date='today UTC' +'%Y-%m-%d %H:%M:%S')" git "$@"
