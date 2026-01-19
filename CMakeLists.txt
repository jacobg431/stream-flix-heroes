cmake_minimum_required(VERSION 3.31)
project(stream-flix-heroes LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(PostgreSQL REQUIRED)

file(GLOB_RECURSE SOURCES "src/*.cpp")


# --- Main executable ---

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

# --------------------
# Test target
# --------------------

find_package(Catch2 REQUIRED)

file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/test/*.cpp"
)

list(REMOVE_ITEM SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

add_executable(stream-flix-heroes-tests
    ${TEST_SOURCES}
    ${SOURCES}
)

target_include_directories(stream-flix-heroes-tests PRIVATE
    ${PostgreSQL_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(stream-flix-heroes-tests PRIVATE
    PostgreSQL::PostgreSQL
    Catch2::Catch2WithMain
)

enable_testing()
add_test(NAME stream-flix-heroes-tests COMMAND stream-flix-heroes-tests)