#!/bin/bash

while :
do
	su -c "exec socat TCP-LISTEN:30001,reuseaddr,fork EXEC:/rev/java interpret,stderr" - revuser;
done
