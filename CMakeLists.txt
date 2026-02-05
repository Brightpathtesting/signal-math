cmake_minimum_required(VERSION 3.21)
project(signal_math LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(signal_math
  src/signal_math.cpp
)
target_include_directories(signal_math PUBLIC include)

add_executable(signal_cli app/main.cpp)
target_link_libraries(signal_cli PRIVATE signal_math)

enable_testing()

find_package(Catch2 3 REQUIRED)
add_executable(signal_tests tests/test_signal_math.cpp)
target_link_libraries(signal_tests PRIVATE signal_math Catch2::Catch2WithMain)

add_test(NAME signal_tests COMMAND $<TARGET_FILE:signal_tests>)
