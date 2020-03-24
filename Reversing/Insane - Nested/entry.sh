#!/bin/bash

while :
do
	su -c "exec socat TCP-LISTEN:30002,reuseaddr,fork EXEC:/rev/server,stderr" - revuser;
done
