#!/bin/bash

suite_dir=../suites

#!/bin/bash

suite_name=$1

suite_file=${suite_dir}/${suite_name}Suite.cc

# Test suite template string
suite_string=""
suite_string+="#include \"TestFacility.h\"\n\n"
suite_string+="/* Test Declarations */\n\n"
suite_string+="/*-------------------*/\n\n"
suite_string+="int main() {\n\n"
suite_string+="    TestFacility::printTestSuiteHeader(\"${suite_name}\");\n\n"
suite_string+="    /* Tests */\n\n"
suite_string+="    /*-------*/\n\n"
suite_string+="    return 0;\n"
suite_string+="}\n\n"
suite_string+="/* Test Definitions */\n\n"

# Exit if no argument
if [ -z "${suite_name}" ]
then
    echo "test suite not created -- no name given"
    exit
fi

# Exit if already exists
if [ -e "${suite_file}" ] ;
then
    printf "suite \'${suite_name}\' already exists\n"
    exit
fi

# Create empty files
touch ${suite_file}

# Write class template string to class header file
printf "${suite_string}" > ${suite_file}

echo "Test suite '${suite_name}' created"