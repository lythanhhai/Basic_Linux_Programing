#!/bin/sh
password=$(zenity --entry --title "entry of a value " --text "Enter a value ")
until [ $password = "123abc" ]
do	 
password=$(zenity --entry --title "entry of a value " --text "Enter a value ")
done
	
exit 0

