#!/bin/bash
Folder=$1

for file in ${Folder}/*;
do
    temp_file="$file"
    echo ${temp_file##*/}
done
