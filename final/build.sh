#!/bin/sh

# Kill containers
docker kill $(docker ps -q)

# Delete containers
docker rm $(docker ps -aq)

# Delete images
# docker rmi $(docker images -q)

# Build and attach
docker build -t "image_name:mergesort" .
docker run -td --name mergesort image_name:mergesort
docker exec mergesort /code/run.sh