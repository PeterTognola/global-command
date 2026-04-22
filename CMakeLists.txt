# Configuration.

cmake_minimum_required(VERSION 4.1)
project(global-command LANGUAGES CXX VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 26)

include(cmake/CPM.cmake)

# Executable.

add_executable(global-command src/main.cpp
        src/webview/webview.cpp
        src/webview/webview.h
        src/utils/utils.cpp
        src/utils/utils.h)

# UI

add_custom_command(
        OUTPUT "${CMAKE_CURRENT_SOURCE_DIR}/src/ui/dist/index.html"
        COMMAND npm install
        COMMAND npm run build
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src/ui"
        DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/ui/src" "${CMAKE_CURRENT_SOURCE_DIR}/src/ui/package.json"
        COMMENT "Building UI..."
        VERBATIM
)

add_custom_target(ui DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/ui/dist/index.html")
add_dependencies(${PROJECT_NAME} ui)

# Libraries

CPMAddPackage(
        NAME           saucer
        VERSION        8.0.4
        GIT_REPOSITORY "https://github.com/saucer/saucer"
)

saucer_embed("${CMAKE_CURRENT_SOURCE_DIR}/src/ui/dist" TARGET ${PROJECT_NAME} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/embedded")

target_link_libraries(${PROJECT_NAME} PRIVATE saucer::saucer saucer::embedded)
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/embedded")