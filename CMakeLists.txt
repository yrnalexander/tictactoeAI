cmake_minimum_required(VERSION 3.14)
project(tictactoe VERSION 1.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)


add_executable(tictactoe main.cpp board.cpp)
add_executable(test_tictactoe tests.cpp board.cpp)
target_include_directories(tictactoe PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

enable_testing()
target_link_libraries(test_tictactoe gtest_main)
include(GoogleTest)
gtest_discover_tests(test_tictactoe)
