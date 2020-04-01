#!/bin/bash
while :
do
    su -c "exec socat TCP-LISTEN:30001,reuseaddr,fork EXEC:'java mr_game_and_watch',stderr" - revuser;
done
