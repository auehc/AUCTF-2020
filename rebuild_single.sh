#!/bin/bash

docker container rm -f $1
docker run -dit -p $2:$3 --name $1 $1

