#!/bin/bash
password=$(zenity --entry --hide-text --title "entry of a password" --text "enter your secret")
echo the secret password is $password
exit 0
