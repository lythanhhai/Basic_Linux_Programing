#!/bin/sh
echo “Is it morning ? yes or no”
read timeofday
case “$timeofday” in
“yes”) echo “good morning”;;
“no” ) echo “good afternoon”;;
“y” ) echo “good morning”;;
“n” ) echo “good afternoon”;;
* ) echo “answer not recognized”;;
esac
exit 0
