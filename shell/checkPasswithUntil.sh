#!/bin/sh
echo “Nhap mat khau:”
read pass
while [ $pass != "123abc" ]
do
	echo "dang nhap khong thanh cong " 
	echo "moi ban nhap lai"
	read pass
done
echo "dang nhap thanh cong"
exit 0 
