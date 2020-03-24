#!/bin/bash

x=$RANDOM

base64 flag.txt > /tmp/$x
sleep 15
rm /tmp/$x
