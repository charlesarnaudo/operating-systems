#!/bin/sh
docker rm $(docker ps -aq)
docker rmi $(docker images -q)
docker build -t "image_name:mergesort" .
docker run -i -t image_name:mergesort /bin/bash