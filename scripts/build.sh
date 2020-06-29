#!/bin/bash

# Directories
src_dir='../src'
obj_dir='../obj'
build_dir='../build'
template_dir='../src/templates'
game_scene_dir='../src/game_scenes'
game_object_dir='../src/game_objects'

# Name of the executable to be built
executable='set'

# Set debug flag
debug='-g'
cxxflags='-std=c++14 -Wall -Wextra'


# Output text color escape sequences
GREEN="\u001b[32m"
BLUE='\u001b[34m'
CYAN='\033[1;36m'
NO_COLOR='\033[0m'

# Generate object file for each source file in source directory
printf "${CYAN}generating object files from ${GREEN}src/${NO_COLOR} :\n"

for f in ${src_dir}/*.cc ; do

    noext=${f%.cc}
    fname=${noext##*/}

    echo g++ ${debug} ${cxxflags} -o ${obj_dir}/${fname}.o -c $f

    g++ ${debug} ${cxxflags} -o ${obj_dir}/${fname}.o -c $f

done

# Generate template object files
printf "\n${CYAN}generating object files from ${GREEN}src/templates/ ${NO_COLOR}:\n"

for f in ${template_dir}/*.cc ; do

    noext=${f%.cc}
    fname=${noext##*/}

    echo g++ ${debug} ${cxxflags} -o ${obj_dir}/${fname}.o -c $f

    g++ ${debug} ${cxxflags} -o ${obj_dir}/${fname}.o -c $f

done

# Generate GameObject object files
printf "\n${CYAN}generating object files from ${GREEN}src/game_objects/ ${NO_COLOR}:\n"

for f in ${game_object_dir}/*.cc ; do

    noext=${f%.cc}
    fname=${noext##*/}

    echo g++ ${debug} ${cxxflags} -o ${obj_dir}/${fname}.o -c $f

    g++ ${debug} ${cxxflags} -o ${obj_dir}/${fname}.o -c $f

done

# Build GameScene object files
printf "\n${CYAN}generating object files from ${GREEN}src/game_scenes/ ${NO_COLOR}:\n"

for f in ${game_scene_dir}/*.cc ; do

    noext=${f%.cc}
    fname=${noext##*/}

    echo g++ ${debug} ${cxxflags} -o ${obj_dir}/${fname}.o -c $f

    g++ ${debug} ${cxxflags} -o ${obj_dir}/${fname}.o -c $f

done


# Build executable
printf "\n${CYAN}building executable ${GREEN}'${executable}' ${NO_COLOR}:\n"
echo g++ ${debug} ${cxxflags} -o ${build_dir}/${executable} ${obj_dir}/*.o `sdl2-config --cflags --libs`

g++ ${debug} ${cxxflags} -o ${build_dir}/${executable} ${obj_dir}/*.o `sdl2-config --cflags --libs`

echo