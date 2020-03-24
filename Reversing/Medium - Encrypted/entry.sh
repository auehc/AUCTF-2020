#!/bin/bash

while :
do
	su -c "exec socat TCP-LISTEN:30049,reuseaddr,fork EXEC:/rev/enc,stderr" - revuser;
done
