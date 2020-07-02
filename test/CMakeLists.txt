file(GLOB SRC_TESTS ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp)

message(STATUS ${SRC_TESTS})

add_executable(test ${SRC_TESTS})
target_link_libraries(test AP::LIB)