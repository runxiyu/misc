#!/bin/sh
realm permit --withdraw "$1"
pkexec rm -rf /home/"$1"
