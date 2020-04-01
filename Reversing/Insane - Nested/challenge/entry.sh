#!/bin/bash

while :
do
	su -c "exec socat TCP-LISTEN:30006,reuseaddr,fork EXEC:/rev/resource,stderr" - revuser;
done
