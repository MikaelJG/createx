#!/bin/bash

current_dir=$(pwd)
build_dir="${current_dir}/build"

option="$1"

echo "Option: $option"

case $option in
    app)
        cmake_command="cmake .. -DCOMPILE_EXE=ON";;
    lib)
        cmake_command="cmake .. -DCOMPILE_EXE=OFF";;
    *)
        echo "Invalid option"
        echo "Exiting program"
        exit;;
esac

cd $build_dir
$cmake_command && cmake --build .
