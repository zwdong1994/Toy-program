#!/bin/bash

Folder=$1

for file in Folder/*
do
    name=${file##*/}
    sudo rm name
    echo ${name}
done
