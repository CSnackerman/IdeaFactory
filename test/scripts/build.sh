#!/bin/bash

src_dir=../../src
inc_dir=../../include
obj_dir=../obj
build_dir=../build
suite_dir=../suites

debug=-g

# Generate object file for each source file in source directory
for f in ${src_dir}/*.cc ; do
    noext=${f%.cc}
    fname=${noext##*/}

    # Skip main.cc
    if [[ $fname = "main" ]]; then
        continue;
    fi

    echo g++ ${debug} -o ${obj_dir}/${fname}.o -c $f -I${inc_dir}

    g++ ${debug} -o ${obj_dir}/${fname}.o -c $f -I${inc_dir}
done

# Generate an object file for each test suite and create executable
for f in ${suite_dir}/*.cc ; do
    noext=${f%.cc}
    fname=${noext##*/}

    echo

    # Compile .o file
    echo g++ ${debug} -o ${obj_dir}/${fname}.o -c $f -I${inc_dir}
    g++ ${debug} -o ${obj_dir}/${fname}.o -c $f -I${inc_dir}

    echo

    # Create executable
    echo g++ ${debug} -o ${build_dir}/${fname} ${obj_dir}/*.o \
        -I${inc_dir} `sdl2-config --cflags --libs`
    g++ ${debug} -o ${build_dir}/${fname} ${obj_dir}/*.o \
        -I${inc_dir} `sdl2-config --cflags --libs`

    # Remove <test-suite> object file
    rm -f ${obj_dir}/${fname}.o

done