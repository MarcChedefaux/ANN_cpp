cmake_minimum_required(VERSION 3.14)

project(ANN_test)

#add_subdirectory(../src)

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
enable_testing()

add_executable(
  ANN_test
  test.cc
  node_t.cc
  activationFunction_t.cc
  layer_t.cc
  network_t.cc
  ../src/node.cpp
  ../src/activationFunction.cpp
  ../src/layer.cpp
  ../src/network.cpp
)
target_link_libraries(
  ANN_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(ANN_test)

target_include_directories(ANN_test PUBLIC ../src)    