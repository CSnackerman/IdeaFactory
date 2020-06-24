#!/bin/bash

class_name=$1

printf "delete class '${class_name}'\n"
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
    # Attempt to remove class from all project source file directories
    rm -f ../src/$class_name.h
    rm -f ../src/$class_name.cc

    rm -f ../src/templates/$class_name.h
    rm -f ../src/templates/$class_name.cc

    rm -f ../src/game_objects/$class_name.h
    rm -f ../src/game_objects/$class_name.cc

    rm -f ../src/game_scenes/$class_name.h
    rm -f ../src/game_scenes/$class_name.cc

    echo "class '$class_name' deleted"
fi