#!/bin/bash

suite_dir=../suites

#!/bin/bash

suite_name=$1

suite_file=${suite_dir}/${suite_name}Suite.cc

suite_string=""
suite_string+="#include <iostream>\n\n"
suite_string+="int main() {\n"
suite_string+="\tstd::cout << \"=== '${suite_name}' Test Suite ===\" << std::endl;\n"
suite_string+="\treturn 0;\n"
suite_string+="}"

if [ -e "${suite_file}" ] ;
then
    printf "suite \'${suite_name}\' already exists\n"
    exit
fi

if [ -z "${suite_file}" ]
then
    echo "test suite not created -- no name given"
else
    # Create empty files
    touch ${suite_file}

    # Write class template string to class header file
    printf "${suite_string}" > ${suite_file}

    echo "Test suite '${suite_name}' created"
fi