#!/bin/sh
URL="http://10.250.3.66/include/auth_action.php"
read -p "Username: " username
read -p "Password: " -s password
echo
ip="$(ip -f inet addr show eno0 | sed -En -e 's/.*inet ([0-9.]+).*/\1/p')"
mac="$(ip -f link addr show eno0 | sed -En -e 's/.*link\/ether ([0-9a-f:]+).*/\1/p')"
curl $URL --insecure --data "action=login&username=$username&password=$password&ac_id=1&user_ip=$ip&nas_ip=127.0.0.1&user_mac=$mac&save_me=1&ajax=1"
