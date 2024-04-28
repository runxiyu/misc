#!/bin/sh
sudo realm permit --withdraw "$1"
sudo rm -rf /home/"$1"
