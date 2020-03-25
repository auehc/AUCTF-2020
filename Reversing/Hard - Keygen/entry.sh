#!/bin/bash

while :
do
	su -c "exec socat TCP-LISTEN:30004,reuseaddr,fork EXEC:/rev/keygen,stderr" - revuser;
done
