#!/bin/bash
while : 
do
    su -c "exec socat TCP-LISTEN:7777,reuseaddr,fork EXEC:'python extraordinary.py'";
done