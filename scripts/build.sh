#!/bin/bash
src_dir=../src
inc_dir=../include
obj_dir=../obj
build_dir=../build

executable=set

# Generate object file for each source file in source directory
for f in ${src_dir}/*.cc ; do
    noext=${f%.cc}
    fname=${noext##*/}
    echo g++ -o ${obj_dir}/${fname}.o -c $f -I${inc_dir}
    g++ -o ${obj_dir}/${fname}.o -c $f -I${inc_dir}
done

# Build executable
echo g++ -o ${build_dir}/${executable} ${obj_dir}/*.o \
    -I${inc_dir} `sdl2-config --cflags --libs`

g++ -o ${build_dir}/${executable} ${obj_dir}/*.o \
    -I${inc_dir} `sdl2-config --cflags --libs`