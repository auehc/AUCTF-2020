#!/bin/bash
while : 
do
    su -c "exec socat TCP-LISTEN:30031,reuseaddr,fork EXEC:'python3 pick_your_poison.py'";
done
