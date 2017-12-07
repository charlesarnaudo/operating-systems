#!/bin/sh

cd code/
gcc sortMerge.c -pthread -o sortMerge
./sortMerge 4 data_128