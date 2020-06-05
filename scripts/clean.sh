#!/bin/bash
src_dir=../src
inc_dir=../include
obj_dir=../obj
build_dir=../build

executable=set

echo rm -f ${obj_dir}/*.o ${build_dir}/${executable}
rm -f ${obj_dir}/*.o ${build_dir}/${executable}