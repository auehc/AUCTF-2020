#!/bin/bash

if [ ! -z "$@" ]
then
	cat $@ # 2>/dev/null
	# if [ ! $? -eq 0 ]
	# then
	# 	echo "Printing error. Check file permissions"
	# fi
else
	echo "Please enter a file."
	echo "./print_file FILENAME"
fi
