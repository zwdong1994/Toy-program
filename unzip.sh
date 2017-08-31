#!/bin/bash

Folder=$1
UNZIP_FOLDER=$2
testing=$(echo ${Folder} | grep "Mobile_sys")
##echo ${testig}
if [ "$testing" == "" ]; then
    echo "You must input a valid folder!"
    exit 0
fi
testing=$(echo ${UNZIP_FOLDER} | grep "Mobile_sys_unzip")
if [ "$testing" == "" ]; then
    echo "You must input a valid unzip folder!"
    exit 0
fi

echo $Folder
for file in ${Folder}/*.zip;
do
    tempfile=${file}
    filename=${file##*/}
    file_nosuffix=${filename%%.zip}
    unzip ${tempfile} -d ${UNZIP_FOLDER}/${file_nosuffix}
    echo ${file_nosuffix}
    echo ${tempfile}
done
