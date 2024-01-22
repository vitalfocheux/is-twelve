# How to use:
#   mkdir build
#   cd build
#   cmake ..
#   make
#
cmake_minimum_required(VERSION 3.10)

project(IS
  LANGUAGES CXX C
)

find_package(Threads)


add_executable(testtwelve
  Twelve.cc
  testtwelve.cc
  googletest/googletest/src/gtest-all.cc
)

target_include_directories(testtwelve
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest"
)

target_link_libraries(testtwelve
  PRIVATE
    Threads::Threads
)

target_compile_options(testtwelve
  PRIVATE
    "-Wall" "-Wextra" "-pedantic" "-g" "-O2"
)

set_target_properties(testtwelve
  PROPERTIES
    CXX_STANDARD 17
    CXX_EXTENSIONS OFF
)
