#!/bin/bash

x=$RANDOM
echo "Input the random number."
read input

if [[ "$input" -eq "$x" ]]
then
	echo "AWESOME sauce"
	cat flag.txt
else
	echo "$input"
	echo "$x try again"
fi
