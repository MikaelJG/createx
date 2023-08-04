#!/bin/bash

# current_dir=$(pwd)
tmp=${BASH_SOURCE[0]}
script_dir=$(dirname "$tmp")
build_dir="${script_dir}/cmake_createx/build"

option="$1"

echo "Option: $option"

case $option in
    app)
        cmake_command="cmake .. -DCOMPILE_EXE=ON";;
    lib)
        cmake_command="cmake .. -DCOMPILE_EXE=OFF";;
    test)
        cmake_command="cmake .. -DCOMPILE_TEST=ON";;
    default)
        cmake_command="cmake .. -DCOMPILE_TEST=ON -DCOMPILE_EX=ON"

        run_command="./test/Createx_test"
        echo "Test and executable defaulted to ON";;

    *)
        echo "Chose Option: app or lib"
        exit;;
esac

cd "$build_dir" || echo "can't find the build directory"
$cmake_command && cmake --build .

echo "Build Worked."
echo "Running Executable"
sleep 2 

./test/Createx_test test/test_dir txt


