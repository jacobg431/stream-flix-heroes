cmake_minimum_required(VERSION 3.31)
project(stream-flix-heroes LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(PostgreSQL REQUIRED)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(stream-flix-heroes
    ${SOURCES}
)


target_include_directories(stream-flix-heroes PRIVATE
    ${PostgreSQL_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(stream-flix-heroes PRIVATE
    PostgreSQL::PostgreSQL
)
