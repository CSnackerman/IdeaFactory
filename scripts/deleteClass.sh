#!/bin/bash

class_name=$1



printf "delete class \'${class_name}\'\n"
printf "  are you sure [y/n] ? "

read response

if [[ $response != "y" ]];
then
    exit
fi

if [ -z "$class_name" ]
then
    echo "no class deleted -- empty argument"
else
    rm ../include/$class_name.h
    rm ../src/$class_name.cc
    echo "class '$class_name' deleted"
fi