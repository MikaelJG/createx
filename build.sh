#!/bin/bash

# current_dir=$(pwd)
tmp=${BASH_SOURCE[0]}
script_dir=$(dirname "$tmp")
build_dir="${script_dir}/cmake_createx/build"
test_dir="${build_dir}/test/test_dir/new_tex"


# Previous test still exist
if rm "${test_dir}/output.tex" >/dev/null 2>&1; then
    echo "Output.tex has been deleted"
    echo "Executing.."
else
    echo "Output.tex could not be found"
    echo "Executing.."
fi

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

if cat "${test_dir}/output.tex" >/dev/null 2>&1; then
    echo ""
    echo "Test complete."
    echo "Output file:"
    echo ""
    cat "${test_dir}/output.tex"
else
    echo "Output could not be read"
fi
