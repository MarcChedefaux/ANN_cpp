cmake_minimum_required(VERSION 3.10)

project(ANN_test)

#add_subdirectory(../src)

add_executable(ANN_test
    test.cpp
    )

target_include_directories(ANN_test PUBLIC ../src)    