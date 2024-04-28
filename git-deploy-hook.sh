#!/bin/sh
# Put this in repo/hooks/post-receive
DSTDIR="/tmp/changeme"
git --work-tree=${DSTDIR} clean -fd
git --work-tree=${DSTDIR} checkout --force
