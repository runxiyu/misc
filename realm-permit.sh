#!/bin/sh
realm permit "$1"
pkexec mkdir /home/"$1"
