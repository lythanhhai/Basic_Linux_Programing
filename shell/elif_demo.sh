#!/bin/sh
# elseif
if test $# -eq 0
   then 
      echo "usgae: $0 ordinary_file"
elif test $# -gt 1
   then 
      echo "usgae: $0 ordinary_file1"
elif test -f "$1"
   then 
      filename="$1"
      set `ls -il $filename`
      echo "usgae: $0 ordinary_file"
      inode="$1"
      size="$6"
      echo "Name\t\tInode\t\tSize"
      echo
      echo "$filename\t$inode\t\t$size"
else  
      echo "$0: argument must be an ordinary file"
fi
exit 1
	
	
