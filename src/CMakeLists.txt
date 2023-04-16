cmake_minimum_required(VERSION 3.10)

project(ANN)

add_executable(ANN 
    mainDebug.cpp
    network.cpp
    layer.cpp
    node.cpp
    activationFunction.cpp
    dataset.cpp
    )