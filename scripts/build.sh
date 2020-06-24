#!/bin/bash

# Directories
src_dir=../src
obj_dir=../obj
build_dir=../build
template_dir=../src/templates
game_scene_dir=../src/game_scenes
game_object_dir=../src/game_objects

# Name of the executable to be built
executable=set

# Set debug flag
debug=-g

# Output text color escape sequences
RED='\033[1;31m'
GREEN='\033[1;36m'
NO_COLOR='\033[0m'

# Generate object file for each source file in source directory
printf "${GREEN}generating object files from ${RED}src/${NO_COLOR} :\n"

for f in ${src_dir}/*.cc ; do

    noext=${f%.cc}
    fname=${noext##*/}

    echo g++ ${debug} -o ${obj_dir}/${fname}.o -c $f

    g++ ${debug} -o ${obj_dir}/${fname}.o -c $f

done

# Generate template object files
printf "\n${GREEN}generating object files from ${RED}src/templates ${NO_COLOR}:\n"

for f in ${template_dir}/*.cc ; do

    noext=${f%.cc}
    fname=${noext##*/}

    echo g++ ${debug} -o ${obj_dir}/${fname}.o -c $f

    g++ ${debug} -o ${obj_dir}/${fname}.o -c $f

done

# Generate GameObject object files
printf "\n${GREEN}generating object files from ${RED}src/game_objects ${NO_COLOR}:\n"

for f in ${game_object_dir}/*.cc ; do

    noext=${f%.cc}
    fname=${noext##*/}

    echo g++ ${debug} -o ${obj_dir}/${fname}.o -c $f

    g++ ${debug} -o ${obj_dir}/${fname}.o -c $f

done

# Build GameScene object files
printf "\n${GREEN}generating object files from ${RED}src/game_scenes ${NO_COLOR}:\n"

for f in ${game_scene_dir}/*.cc ; do

    noext=${f%.cc}
    fname=${noext##*/}

    echo g++ ${debug} -o ${obj_dir}/${fname}.o -c $f

    g++ ${debug} -o ${obj_dir}/${fname}.o -c $f

done


# Build executable
printf "\n${GREEN}building executable ${RED}'${executable}' ${NO_COLOR}:\n"
echo g++ ${debug} -o ${build_dir}/${executable} ${obj_dir}/*.o `sdl2-config --cflags --libs`

g++ ${debug} -o ${build_dir}/${executable} ${obj_dir}/*.o `sdl2-config --cflags --libs`

echo