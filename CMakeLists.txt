cmake_minimum_required(VERSION 3.10)

project(abstract_positions)

option(COMPILE_TESTS "is it necessary to compile tests?" ON)

set (CMAKE_CXX_STANDARD 17)
set(INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/src)
set(TEST_DIR ${CMAKE_CURRENT_LIST_DIR}/test)
set(INSTALL_PATH ${CMAKE_CURRENT_LIST_DIR}/bin)


add_subdirectory(${SOURCE_DIR})

if(${COMPILE_TESTS})
    add_subdirectory(${TEST_DIR})
endif()