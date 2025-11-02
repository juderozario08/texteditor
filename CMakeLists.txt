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

# Find SDL3 using pkg-config
find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL3 REQUIRED IMPORTED_TARGET sdl3)

# Find Lua using pkg-config (try lua5.4 first, fallback to lua)
pkg_check_modules(LUA REQUIRED lua5.4)
if (NOT LUA_FOUND)
    pkg_check_modules(LUA REQUIRED lua)
endif()

# Include Lua headers
include_directories(${LUA_INCLUDE_DIRS})

# Create executable
add_executable(texteditor ${SRC_FILES})

# Link SDL3 and Lua
target_link_libraries(texteditor PRIVATE PkgConfig::SDL3 ${LUA_LIBRARIES})
