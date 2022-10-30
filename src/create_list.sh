#1/usr/bin/bash

MUSIC=$1
REGEX=$2

#get dirs
ls -alR | grep "^\(\\..*\):"
ls -alR $MUSIC | grep $REGEX

find ~/Music -iname "*.mp3" > cache.txt
cat cache.txt | grep Black >> update_cache.txt

