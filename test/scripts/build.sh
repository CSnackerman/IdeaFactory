#!/bin/bash

# Project source/include directories
proj_src_dir='../../src'
template_dir='../../src/templates'
game_scene_dir='../../src/game_scenes'
game_object_dir='../../src/game_objects'

# Test facility directories
test_src_dir='../src'
test_obj_dir='../obj'
test_build_dir='../build'
test_suite_dir='../suites'

# Set debug flag
debug=-g

# Output text color escape sequences
GREEN="\u001b[32m"
BLUE='\u001b[34m'
CYAN='\033[1;36m'
NO_COLOR='\033[0m'

# Compile test source files
printf "${CYAN}compiling test source files${NO_COLOR}\n"
for f in ${test_src_dir}/*.cc ; do

    # Get the filename
    noext=${f%.cc}
    fname=${noext##*/}

    echo g++ ${debug} -o ${test_obj_dir}/${fname}.o -c $f -I${proj_src_dir}
    g++ ${debug} -o ${test_obj_dir}/${fname}.o -c $f -I${proj_src_dir}
done

# Compile project source files
printf "\n${CYAN}compiling project source files${NO_COLOR}\n"
for f in ${proj_src_dir}/*.cc ; do

    # Get the filename
    noext=${f%.cc}
    fname=${noext##*/}

    # Skip main.cc
    if [[ $fname = "main" ]]; then
        continue;
    fi

    echo g++ ${debug} -o ${test_obj_dir}/${fname}.o -c $f
    g++ ${debug} -o ${test_obj_dir}/${fname}.o -c $f
done

# Compile game_object directory
printf "\n${CYAN}compiling game objects${NO_COLOR}\n"
for f in ${game_object_dir}/*.cc ; do

    # Get the filename
    noext=${f%.cc}
    fname=${noext##*/}

    echo g++ ${debug} -o ${test_obj_dir}/${fname}.o -c $f

    g++ ${debug} -o ${test_obj_dir}/${fname}.o -c $f
done

# Compile template directory
printf "\n${CYAN}compiling templates${NO_COLOR}\n"
for f in ${template_dir}/*.cc ; do

    # Get the filename
    noext=${f%.cc}
    fname=${noext##*/}

    echo g++ ${debug} -o ${test_obj_dir}/${fname}.o -c $f
    g++ ${debug} -o ${test_obj_dir}/${fname}.o -c $f
done

# Compile game_scene direcotry
for f in ${game_scene_dir}/*.cc ; do

    # Get the filename
    noext=${f%.cc}
    fname=${noext##*/}

    printf "\n${CYAN}compiling GameScenes${NO_COLOR}\n"
    echo g++ ${debug} -o ${test_obj_dir}/${fname}.o -c $f

    g++ ${debug} -o ${test_obj_dir}/${fname}.o -c $f
done

# Compile each test suite and build executable
printf "\n${CYAN}building runnable test suites${NO_COLOR}\n"
for f in ${test_suite_dir}/*.cc ; do
    
    if [[ ${f} == "../suites/*.cc" ]]; then
        echo "0 test suites found"
        echo "exited"
        exit
    fi
    
    # Get filename
    noext=${f%.cc}
    fname=${noext##*/}

    # Compile .o file
    printf "\n${GREEN}${fname}:\n"
    printf "${CYAN}compiling...${NO_COLOR}\n"
    echo g++ ${debug} -o ${test_obj_dir}/${fname}.o -c $f -I${test_src_dir} -I${proj_src_dir}
    g++ ${debug} -o ${test_obj_dir}/${fname}.o -c $f -I${test_src_dir} -I${proj_src_dir}

    # Create executable
    printf "\n${CYAN}building...${NO_COLOR}\n"
    echo g++ ${debug} -o ${test_build_dir}/${fname} ${test_obj_dir}/*.o \
    `sdl2-config --cflags --libs`

    g++ ${debug} -o ${test_build_dir}/${fname} ${test_obj_dir}/*.o \
     `sdl2-config --cflags --libs`

    # Remove <test-suite> object file
    rm -f ${test_obj_dir}/${fname}.o

done