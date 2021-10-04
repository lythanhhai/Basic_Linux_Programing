#!/bin/sh
password=$(zenity --entry --hide-text --title "entry of a password" --text "enter your secret")
until [ $password = "123abc" ]
do
zenity --warning --text "dang nhap khong thanh cong"
password=$(zenity --entry --hide-text --title "entry of a password" --text "enter your secret")
done
zenity --notification  --text "dang nhap thanh cong"
exit 0 

