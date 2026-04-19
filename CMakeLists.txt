# Configuration.

cmake_minimum_required(VERSION 4.1)
project(global-command LANGUAGES CXX VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 26)

include(cmake/CPM.cmake)

# Executable.

add_executable(global-command main.cpp)

# Libraries

CPMAddPackage(
        NAME           saucer
        VERSION        8.0.4
        GIT_REPOSITORY "https://github.com/saucer/saucer"
)

target_link_libraries(${PROJECT_NAME} PRIVATE saucer::saucer)