#!/bin/sh
# 1. in ra màn hình đoạn thông báo theo định dạng.
echo "Bai thi giua ky mon: Lap trinh tren linux"
echo "Ho va ten: Ly Thanh Hai"
echo "Nhom: 19N10"
echo "MSSV: 102190061"
echo "De so: 02"
# 2. Kiểm tra tham số dòng lệnh.
if [ $# -lt 1 ];
then 
	echo "khong co tham so dong lenh"
elif [ $# -eq 1 ];
then
	if test -d "$1"
	then
		echo "$1 la mot thu muc"
	elif test -f "$1"
	then
		echo "$1 la mot file thong thuong"
	else
		echo "$1 khong duoc tim thay"
	fi
else
	echo "tham so dong lenh lon hon 1"
fi

# 3. Tạo menu công việc.
# echo "Moi chon cong viec: "
echo "s or S: De sap xep file actor_movies.txt"
echo "t or T: De tim kiem phim"
echo "q or Q: De thoat khoi chuong trinh"
while true
do
echo "Moi chon cong viec \c"
read option
   case "$option" in 
	s|S) 
		sort -r -o actor.txt -t',' actor_movies.txt
		cat actor.txt
	 ;;
	t|T) 
		read -p "moi nhap ten phim: " tenFilm
		if [ -z `grep "$tenFilm" actor_movies.txt` ];
		then 
			echo "Khong co ten phim phu hop voi tim kiem"
		else
			grep $tenphim actor_movies.txt
			cat cast.txt
		fi 
	 ;;
	q|Q) exit 0 ;;
	*) echo "Ban nhap sai. vui long nhap lai."
	   ;;
   esac
done

t|T) 
echo " nhap ten phim :\c"
read tenphim
grep $tenphim actor_movies.txt > cast1.txt
awk '{print $1}' cast1.txt > cast.txt
;;
s|S) 
sort -k1,2 -r actor_movies.txt > actor.txt

;;

q|Q) exit 0
;;


