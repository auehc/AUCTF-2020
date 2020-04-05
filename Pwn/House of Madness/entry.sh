#!/bin/bash

while :
do
	su -c "exec socat TCP-LISTEN:30012,reuseaddr,fork EXEC:'/pwn/challenge,stderr'" - pwnuser;
done
