cmake_minimum_required(VERSION 3.3)

# Project
project(console_beep VERSION 1.0.0)
find_package(console REQUIRED)
set(SOURCES
  src/console_beep.cpp
)
source_group(src FILES ${SOURCES})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Application properties
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} console)
