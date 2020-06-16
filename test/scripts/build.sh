#!/bin/bash

# Project source/include directories
proj_src_dir=../../src
proj_inc_dir=../../include

# Test facility directories
test_src_dir=../src
test_inc_dir=../include
test_obj_dir=../obj
test_build_dir=../build
test_suite_dir=../suites

# Set debug flag
debug=-g

# Generate TestFacility object file
echo g++ ${debug} -o ${test_obj_dir}/TestFacility.o -c ${test_src_dir}/TestFacility.cc -I${test_inc_dir}
g++ ${debug} -o ${test_obj_dir}/TestFacility.o -c ${test_src_dir}/TestFacility.cc -I${test_inc_dir}

# Generate object file for each source file in source directory
for f in ${proj_src_dir}/*.cc ; do

    # Store name of file into fname cleaning off file path and extension info
    noext=${f%.cc}
    fname=${noext##*/}

    # Skip main.cc
    if [[ $fname = "main" ]]; then
        continue;
    fi

    echo g++ ${debug} -o ${test_obj_dir}/${fname}.o -c $f -I${proj_inc_dir}

    g++ ${debug} -o ${test_obj_dir}/${fname}.o -c $f -I${proj_inc_dir}
done

# Generate an object file for each test suite and create executable test run
for f in ${test_suite_dir}/*.cc ; do
    
    if [[ ${f} == "../suites/*.cc" ]]; then
        echo "0 test suites found"
        echo "exited"
        exit
    fi
    
    noext=${f%.cc}
    fname=${noext##*/}

    echo

    # Compile .o file
    echo g++ ${debug} -o ${test_obj_dir}/${fname}.o -c $f -I${proj_inc_dir} -I${test_inc_dir}
    
    g++ ${debug} -o ${test_obj_dir}/${fname}.o -c $f -I${proj_inc_dir} -I${test_inc_dir}

    echo

    # Create executable test-set
    echo g++ ${debug} -o ${test_build_dir}/${fname} ${test_obj_dir}/*.o \
        -I${proj_inc_dir} -I${test_inc_dir} `sdl2-config --cflags --libs`

    g++ ${debug} -o ${test_build_dir}/${fname} ${test_obj_dir}/*.o \
        -I${proj_inc_dir} -I${test_inc_dir} `sdl2-config --cflags --libs`

    # Remove <test-suite> object file
    rm -f ${test_obj_dir}/${fname}.o

done