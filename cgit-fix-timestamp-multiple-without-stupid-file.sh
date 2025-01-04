#!/bin/sh
cat << EOF > /tmp/shutup.sh
#!/bin/sh
set -e
cd "$1"
rrr="$(git for-each-ref --sort=-authordate --count=1 --format='%(authordate:iso8601)')"
find . -print0 | xargs -0 touch -d "$rrr" --
EOF
chmod a+x /tmp/shutup.sh
find . -name '*.git' -type d -exec /tmp/shutup.sh '{}' \;  
