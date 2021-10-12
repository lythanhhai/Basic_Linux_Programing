#!/bin/sh
echo "the comman name is: $0."
echo "the number of command line argument passed as parameters are $#."
echo "the value of the command line argumants are: $1 $2 $3 $4 $5 $6 $7 $8 $9."
echo "another way to display values of all of the arguments: $@."
echo "Yet another way is: $*."
exit 0;
