#!/bin/sh
echo “Nhap mat khau:”
#read pass
pass="";
until [ $pass = "123abc" ]
do
	read pass
	if [ $pass != "123abc" ];
	then
	echo "dang nhap khong thanh cong " 
	echo "moi ban nhap lai"
	fi
done
	echo "dang nhap thanh cong"
exit 0 
