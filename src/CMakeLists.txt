file(GLOB SRC_LIB ${CMAKE_CURRENT_LIST_DIR}/lib/*.cpp
                  ${CMAKE_CURRENT_LIST_DIR}/lib/entity/*.cpp
                  ${CMAKE_CURRENT_LIST_DIR}/lib/repository/*.cpp
                  ${CMAKE_CURRENT_LIST_DIR}/lib/serializer/*.cpp)

add_library(abstract_positions ${SRC_LIB})
target_include_directories(abstract_positions PUBLIC ${INCLUDE_DIR})
add_library(AP::LIB ALIAS abstract_positions)

add_executable(app main.cpp)
target_link_libraries(app abstract_positions)