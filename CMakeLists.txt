cmake_minimum_required(VERSION 3.6)
project(apportionment)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Apportionment.cpp Apportionment.h State.cpp State.h Nation.cpp Nation.h Population.h Name.h)

find_package(Boost)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

add_executable(apportionment ${SOURCE_FILES})