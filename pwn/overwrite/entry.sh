#!/bin/bash

while :
do
	su -c "exec socat TCP-LISTEN:30011,reuseaddr,fork EXEC:'/pwn/overwrite,stderr'" - pwnuser;
done
