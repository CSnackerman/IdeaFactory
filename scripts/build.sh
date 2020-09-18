#!/usr/bin/env bash

# Directories
src_dir="../src"
obj_dir="../obj"
build_dir="../build"
template_dir="../src/templates"
game_scene_dir="../src/game_scenes"
game_object_dir="../src/game_objects"

# Name of the target to be built
target="set"
fullTargetPath=${build_dir}/${target}

# Set compiler flags
debug="-g"
cxxflags="${debug} -std=c++14 -Wall -Wextra"

# Output text color escape sequences
GREEN="\u001b[32m"
BLUE="\u001b[34m"
CYAN="\033[1;36m"
RED="\u001b[31m"
NO_COLOR="\033[0m"

# Set to false if any source file is not up-to-date and compiles
upToDate="true"

# Compile src/ directory
printf "${CYAN}generating object files from ${GREEN}src/${NO_COLOR}\n"
for f in ${src_dir}/*.cc ; do

    noext=${f%.cc}
    fname=${noext##*/}
    header="${noext}.h"

    # Check if source file and header is up-to-date
    if [[ ! $f -nt ${obj_dir}/${fname}.o ]]; then
        if [[ ! ${header} -nt ${obj_dir}/${fname}.o ]]; then
            printf "'${fname}' up-to-date\n";
            continue;
        fi
    fi

    upToDate="false"

    echo g++ ${cxxflags} -o ${obj_dir}/${fname}.o -c $f

    g++ ${cxxflags} -o ${obj_dir}/${fname}.o -c $f

done

# Compile template/ directory
printf "\n${CYAN}generating object files from ${GREEN}src/templates/ ${NO_COLOR}\n"
for f in ${template_dir}/*.cc ; do

    noext=${f%.cc}
    fname=${noext##*/}
    header="${noext}.h"

    # Check if source file and header is up-to-date
    if [[ ! $f -nt ${obj_dir}/${fname}.o ]]; then
        if [[ ! ${header} -nt ${obj_dir}/${fname}.o ]]; then
            printf "'${fname}' up-to-date\n";
            continue;
        fi
    fi

    echo g++ ${cxxflags} -o ${obj_dir}/${fname}.o -c $f

    g++ ${cxxflags} -o ${obj_dir}/${fname}.o -c $f

done

# Compiile game_object/ directory
printf "\n${CYAN}generating object files from ${GREEN}src/game_objects/ ${NO_COLOR}\n"
for f in ${game_object_dir}/*.cc ; do

    noext=${f%.cc}
    fname=${noext##*/}
    header="${noext}.h"

    # Check if source file and header is up-to-date
    if [[ ! $f -nt ${obj_dir}/${fname}.o ]]; then
        if [[ ! ${header} -nt ${obj_dir}/${fname}.o ]]; then
            printf "'${fname}' up-to-date\n";
            continue;
        fi
    fi

    upToDate="false"

    echo g++ ${cxxflags} -o ${obj_dir}/${fname}.o -c $f

    g++ ${cxxflags} -o ${obj_dir}/${fname}.o -c $f

done

# Compile game_scene/ directory
printf "\n${CYAN}generating object files from ${GREEN}src/game_scenes/ ${NO_COLOR}\n"
for f in ${game_scene_dir}/*.cc ; do

    noext=${f%.cc}
    fname=${noext##*/}
    header="${noext}.h"

    # Check if source file and header is up-to-date
    if [[ ! $f -nt ${obj_dir}/${fname}.o ]]; then
        if [[ ! ${header} -nt ${obj_dir}/${fname}.o ]]; then
            printf "'${fname}' up-to-date\n";
            continue;
        fi
    fi

    upToDate="false"

    echo g++ ${cxxflags} -o ${obj_dir}/${fname}.o -c $f

    g++ ${cxxflags} -o ${obj_dir}/${fname}.o -c $f

done

# Build target
printf "\n${CYAN}building target ${RED}'${target}' ${NO_COLOR}\n"
if [[ ${upToDate} == "true" ]]; then
    printf "'${target}' up-to-date\n"
    exit;
fi

echo g++ ${cxxflags} -o ${build_dir}/${target} ${obj_dir}/*.o `sdl2-config --cflags --libs`
g++ ${cxxflags} -o ${build_dir}/${target} ${obj_dir}/*.o `sdl2-config --cflags --libs`

echo