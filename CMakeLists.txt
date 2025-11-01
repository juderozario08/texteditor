cmake_minimum_required(VERSION 3.16)
project(TextEditorPro LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define source and header directories
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(UTILS_DIR "${CMAKE_SOURCE_DIR}/utils")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

# Collect source files
file(GLOB_RECURSE SRC_FILES
    "${SRC_DIR}/*.cpp"
    "${UTILS_DIR}/*.cpp"
)

# Include directories
include_directories(${INCLUDE_DIR})

# Find SDL2 using pkg-config
find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED IMPORTED_TARGET sdl2)

# Create executable
add_executable(texteditor ${SRC_FILES})

# Link SDL2
target_link_libraries(texteditor PRIVATE PkgConfig::SDL2)
