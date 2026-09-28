#!/usr/bin/env bash

writefile=$1
writestr=$2

if [ -z "$writefile" ] || [ -z "$writestr" ]; then
    echo "One of more of the arguments not supplied"
    exit 1
fi

pathname=$(dirname "$writefile")

if ! mkdir -p "$pathname"; then
    echo "Failed to create directory $pathname"
    exit 1
fi

if ! echo "$writestr" > "$writefile"; then
    echo "Failed to write to file $writefile"
    exit 1
fi

exit 0
