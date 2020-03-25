#!/bin/bash

while :
do
	su -c "exec socat TCP-LISTEN:30005,reuseaddr,fork EXEC:/rev/debug,stderr" - revuser;
done
