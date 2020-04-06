#!/bin/bash

x=$RANDOM

base64 flag.txt > /tmp/$x
function finish {
	rm  /tmp/$x
}
trap finish EXIT

sleep 15
