#!/bin/bash

x=$(shuf -i 1024-65500 -n 1)
echo "Guess the listening port"
input=$(nc -lp $x)
echo "That was easy right? :)"
cat flag.txt
