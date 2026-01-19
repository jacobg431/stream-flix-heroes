cmake_minimum_required(VERSION 3.31)
project(stream-flix-heroes LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(PostgreSQL REQUIRED)

file(GLOB_RECURSE APP_SOURCES "src/*.cpp")
list(FILTER APP_SOURCES EXCLUDE REGEX ".*/TestModels/.*")

add_executable(stream-flix-heroes
    ${APP_SOURCES}
)

target_include_directories(stream-flix-heroes PRIVATE
    ${PostgreSQL_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(stream-flix-heroes PRIVATE
    PostgreSQL::PostgreSQL
)
enable_testing()

file(GLOB MODEL_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Models/*.cpp
)

add_executable(stream-flix-tests
    src/TestModels/testModels.cpp
    src/TestModels/catch_amalgamated.cpp
    ${MODEL_SOURCES}
)

target_include_directories(stream-flix-tests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

add_test(NAME streamflix-tests COMMAND stream-flix-tests)
