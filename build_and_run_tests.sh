cd build
cmake ..
make

if [[ -z $1 ]]; then
    ./all_tests_binary
    # ctest
else
    ./all_tests_binary --gtest_filter=$1*
    # ctest -R $1
fi
