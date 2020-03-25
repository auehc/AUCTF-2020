#!/bin/bash
while : 
do
    su -c "exec socat TCP-LISTEN:30030,reuseaddr,fork EXEC:'python3 extraordinary.py'";
done
