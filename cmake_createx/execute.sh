#!/bin/bash

current_dir=$(pwd)
build_dir="${current_dir}/build"

cd $build_dir
cmake .. && cmake --build .
