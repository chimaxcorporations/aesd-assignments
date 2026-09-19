#!/usr/bin/env bash

filesdir=$1
searchstr=$2

if [ -z "$filesdir" ] || [ -z "$searchstr" ]; then
    echo "filesdir is not a directory or searchstr is not supplied"
    exit 1
fi


if [ ! -d "$filesdir" ]; then
    echo "The parent directory of filesdir does not exist"
    exit 1
fi

X=$(find "$filesdir" -type f  | wc -l)
Y=$(grep -r "$searchstr" "$filesdir" | wc -l)
echo "The number of files are ${X} and the number of matching lines are ${Y}"

exit 0