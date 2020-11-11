cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.diagnostics.unit_tests)
set(SOURCES
  src/main.cpp 
  src/trace_listener.cpp
)
source_group(src FILES ${SOURCES})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Target
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} xtd.diagnostics xtd.tunit)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd/tests")

# Tests
add_test(NAME ${PROJECT_NAME} COMMAND $<TARGET_FILE_NAME:${PROJECT_NAME}> WORKING_DIRECTORY $<TARGET_FILE_DIR:${PROJECT_NAME}>)
