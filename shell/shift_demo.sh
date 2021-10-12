#!/bin/sh
echo "the program name is: $0."
echo "the argument are: $@."
echo "the first three arguments are: $1 $2 $3."
shift
echo "the program name is: $0."
echo "the argument are: $@"
echo "the first three arguments are: $1 $2 $3."
shift 3
echo "the program name is: $0."
echo "the argument are: $@"
echo "the first three arguments are: $1 $2 $3." 
exit 0
