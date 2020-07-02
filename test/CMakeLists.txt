file(GLOB SRC_TESTS ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp)

set(TEST_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/include)
message(STATUS ${SRC_TESTS})

add_executable(test ${SRC_TESTS})
target_include_directories(test PRIVATE ${TEST_INCLUDE_DIR})
target_link_libraries(test AP::LIB)