cmake_minimum_required(VERSION 3.20)
project(cpp_postgres_app LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 20)
set(sCMAKE_CXX_STANDARD_REQUIRED ON)


find_package(PostgreSQL REQUIRED)


add_executable(cpp_postgres_app
    src/main.cpp
)


target_include_directories(cpp_postgres_app PRIVATE
    ${PostgreSQL_INCLUDE_DIRS}
)


target_link_libraries(cpp_postgres_app PRIVATE
    PostgreSQL::PostgreSQL
)