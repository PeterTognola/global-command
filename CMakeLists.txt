# Configuration.

cmake_minimum_required(VERSION 4.1)
project(global-command LANGUAGES CXX VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 26)

include(cmake/CPM.cmake)

# UI.

set(UI_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/ui")

if (NOT EXISTS "${UI_INDEX_HTML}")
    message(STATUS "UI dist not found; building UI before embedding...")

    execute_process(
            COMMAND npm install
            WORKING_DIRECTORY "${UI_SOURCE_DIR}"
            COMMAND_ERROR_IS_FATAL ANY
    )

    execute_process(
            COMMAND npm run build
            WORKING_DIRECTORY "${UI_SOURCE_DIR}"
            COMMAND_ERROR_IS_FATAL ANY
    )
endif ()

add_custom_command(
        OUTPUT "${UI_SOURCE_DIR}/dist/index.html"
        COMMAND "${CMAKE_COMMAND}" -E rm -rf "${UI_SOURCE_DIR}/dist"
        COMMAND npm install
        COMMAND npm run build
        WORKING_DIRECTORY "${UI_SOURCE_DIR}"
        DEPENDS "${UI_SOURCE_DIR}/src" "${UI_SOURCE_DIR}/package.json"
        COMMENT "Building UI..."
        VERBATIM
)

add_custom_target(ui DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/ui/dist/index.html")

# Executable.

add_executable(global-command
        src/main.cpp
        src/webview/webview.cpp
        src/webview/webview.h
        src/utils/utils.cpp
        src/utils/utils.h)

add_dependencies(${PROJECT_NAME} ui)

# Libraries.

CPMAddPackage(
        NAME           saucer
        VERSION        8.0.4
        GIT_REPOSITORY "https://github.com/saucer/saucer"
)

saucer_embed("${CMAKE_CURRENT_SOURCE_DIR}/src/ui/dist" TARGET ${PROJECT_NAME} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/embedded")

target_link_libraries(${PROJECT_NAME} PRIVATE saucer::saucer saucer::embedded)
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/embedded")