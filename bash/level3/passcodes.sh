#!/bin/bash

x=$RANDOM

read input

if [[ "$input" -eq "$x" ]]
then
	echo "AWESOME sauce"
	cat flag.txt
else
	echo "$input"
	echo "$x try again"
fi
