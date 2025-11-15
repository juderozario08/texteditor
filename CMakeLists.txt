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

# -----------------------------
# SDL3
# -----------------------------
find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL3 REQUIRED IMPORTED_TARGET sdl3)

# -----------------------------
# Lua (prefer Lua 5.4, fallback to generic lua)
# -----------------------------
find_package(PkgConfig REQUIRED)

pkg_check_modules(LUA lua5.4)
if (NOT LUA_FOUND)
    pkg_check_modules(LUA lua)
endif()

if (LUA_FOUND)
    include_directories(${LUA_INCLUDE_DIRS})
    link_directories(${LUA_LIBRARY_DIRS})
else()
    message(FATAL_ERROR "Lua not found. Please install lua5.4 or lua via pkg-config.")
endif()

# -----------------------------
# fmtlib
# -----------------------------
find_package(fmt REQUIRED)

# -----------------------------
# Executable
# -----------------------------
add_executable(texteditor ${SRC_FILES})

# -----------------------------
# Linking
# -----------------------------
target_link_libraries(texteditor
    PRIVATE
        PkgConfig::SDL3
        ${LUA_LIBRARIES}
        fmt::fmt
)

# -----------------------------
# RPATH fix (macOS/Homebrew)
# -----------------------------
# if(APPLE)
#     set_target_properties(texteditor PROPERTIES
#         INSTALL_RPATH "/opt/homebrew/lib"
#     )
# endif()
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
