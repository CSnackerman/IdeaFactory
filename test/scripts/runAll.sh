#!/bin/bash

build_dir=../build

for f in ${build_dir}/* ; do
    
    # Output error message if no files found
    if [[ ${f} == "../build/*" ]]; then
        echo "couldn't find any test runs"
        break
    fi

    # Execute test run
    ${f}
    
done