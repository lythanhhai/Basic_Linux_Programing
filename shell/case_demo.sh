#!/bin/sh
echo "use one of the following options: "
echo "d or D: to display today's date and present time"
echo "l or L: to see the listening files in your  present working directory"
echo "w or W: to see who;s logged in"
echo "q or Q: to quit this program "
while true
do
echo "enter you option and hit <Enter>: \c"
read option
   case "$option" in 
	d|D) date ;;
	l|L) ls ;;
	w|W) who ;;
	q|Q) exit 0 ;;
	*) echo "Invalid option; try running the program again."
	   exit 1
	   ;;
   esac
done

exit 0

