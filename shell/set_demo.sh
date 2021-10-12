#!/bin/sh
filename="$1"
set `ls -il $filename`
inode="$1"
size="$6"
echo "Name\t\tInode\t\tSize"
echo
echo "$filename\t$inode\t\t$size"
exit 0

