#!/usr/bin/bash

REGEX=$1
FILE=$2

cat cache.txt | grep $REGEX | tee -a $FILE

# ./append.sh Hell | grep -E "[0-9][0-9]\."
