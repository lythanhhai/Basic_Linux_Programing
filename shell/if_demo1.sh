#!/bin/sh
# if
if test $# -eq 0
   then 
      echo "usgae: $0 ordinary_file"
      exit 1
fi
if test $# -gt 1
   then 
      echo "usgae: $0 ordinary_file1"
      exit 1
fi
if test -f "$1"
   then 
      filename="$1"
      set `ls -il $filename`
      echo "usgae: $0 ordinary_file"
      inode="$1"
      size="$6"
      echo "Name\t\tInode\t\tSize"
      echo
      echo "$filename\t$inode\t\t$size"
      exit 0
fi
echo "$0: argument must be an ordinary file"
exit 1


