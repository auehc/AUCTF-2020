#!/bin/bash

while :
do
	su -c "exec socat TCP-LISTEN:30000,reuseaddr,fork EXEC:/rev/crackme,stderr" - revuser;
done
