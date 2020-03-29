#!/bin/bash

while :
do
	su -c "exec socat TCP-LISTEN:30010,reuseaddr,fork EXEC:'python3 /pwn/shell.py,stderr'" - pwnuser;
done
