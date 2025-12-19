cmake_minimum_required(VERSION 3.10)
project(Manilyzer)

set(CMAKE_SUPPRESS_REGENERATION TRUE)  # Hides ZERO_CHECK too
set_property(GLOBAL PROPERTY USE_FOLDERS ON)  # Enable folder organization

# Define executable name
set(EXECUTABLE "Manilyzer")

# Define the project name and language
project(Manilyzer LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wformat -Wdeprecated-declarations")

# Recursively find all source files
set(CODE_SRC_DIR "${CMAKE_SOURCE_DIR}/code")
file(GLOB_RECURSE CODE_FILES "${CODE_SRC_DIR}/*.cpp" "${CODE_SRC_DIR}/*.hpp")
message(STATUS "All files found: ${CODE_FILES}")

# Create executable
add_executable(${EXECUTABLE} ${CODE_FILES})

# Add include directory
target_include_directories(${EXECUTABLE} PRIVATE ${CODE_SRC_DIR})

# Preserve folder structure in XCode
source_group(TREE "${CODE_SRC_DIR}" FILES ${CODE_FILES})
