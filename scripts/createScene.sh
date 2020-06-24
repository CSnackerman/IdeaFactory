#!/bin/bash

class_name=$1

src_file=../src/game_scenes/$class_name.cc
header_file=../src/game_scenes/$class_name.h

class_string=""
class_string+="#ifndef ${class_name^^}_H\n"
class_string+="#define ${class_name^^}_H\n\n"
class_string+="#include \"../templates/GameScene.h\"\n\n"
class_string+="class ${class_name} {\n"
class_string+="private:\n"
class_string+="\n"
class_string+="public:\n"
class_string+="};\n\n"
class_string+="#endif"

if [ -e "$src_file" ] || [ -e "$header_file" ] ;
then
    printf "class \'${class_name}\' already exists\n"
    exit
fi

if [ -z "$class_name" ]
then
    echo "class not created -- no argument"
else
    # Create empty files
    touch $header_file
    touch $src_file

    # Write class template string to class header file
    printf "$class_string" > $header_file

    # Write class include to source file
    printf "#include \"${class_name}.h\"" > $src_file

    echo "class '$class_name' created"
fi