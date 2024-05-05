#!/bin/sh
curl -D /dev/stdout -X POST https://changeme.org/_matrix/client/v3/register --json '{"password": "changeme", "username": "changeme", "auth": {"type": "m.login.registration_token", "token": "changeme"}, "device_id": "curl", "initial_device_display_name": "curl"}'
