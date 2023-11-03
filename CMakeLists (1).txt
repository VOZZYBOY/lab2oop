cmake_minimum_required(VERSION 3.10)
project(first_lab)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  DOWNLOAD_EXTRACT_TIMESTAMP true
)

FetchContent_MakeAvailable(googletest)
add_executable(main main.cpp hex_cdg.cpp hex_bool_op.cpp hex_math_op.cpp )
add_executable(tests tests.cpp hex_cdg.cpp hex_bool_op.cpp hex_math_op.cpp)
target_link_libraries(tests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)