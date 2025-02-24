#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: ./build.sh <filename>"
    exit 1
fi

FILENAME="${1%.*}"

if [ ! -f "$1" ]; then
    echo "Error: File '$1' not found!"
    exit 1
fi

g++ -std=c++17 -Wall -Wextra -o "$FILENAME" "$1"

if [ $? -eq 0 ]; then
    echo "Compilation successful! Running..."
    ./"$FILENAME"

    rm "$FILENAME"

else
    echo "Compilation failed!"
    exit 1
fi
