cmake_minimum_required(VERSION 3.10)
project(elastic-collisions VERSION 1.0 LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include header directory
include_directories(${PROJECT_SOURCE_DIR}/include)

# Collect all source files from src directory
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

# Find and require SFML
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link SFML libraries
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)