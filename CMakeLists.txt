cmake_minimum_required(VERSION 3.31)
project(stream-flix-heroes LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 20)
set(sCMAKE_CXX_STANDARD_REQUIRED ON)


find_package(PostgreSQL REQUIRED)


add_executable(stream-flix-heroes
    src/main.cpp
)


target_include_directories(stream-flix-heroes PRIVATE
    ${PostgreSQL_INCLUDE_DIRS}
)


target_link_libraries(stream-flix-heroes PRIVATE
    PostgreSQL::PostgreSQL
)