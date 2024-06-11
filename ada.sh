#!/bin/sh
gcc -c "$1"
gnatbind "$(basename "$1" .adb)"
gnatlink "$(basename "$1" .adb)"
