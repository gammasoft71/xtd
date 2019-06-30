cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.forms.unit_tests)
set(SOURCES
  src/control.cpp 
  src/form.cpp
  src/main.cpp 
)
source_group(src FILES ${SOURCES})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (MSVC)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif ()

# Target
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} xtd.forms xtd.tunit)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd/tests")

# Tests
add_test(NAME ${PROJECT_NAME} COMMAND $<TARGET_FILE_NAME:${PROJECT_NAME}> WORKING_DIRECTORY $<TARGET_FILE_DIR:${PROJECT_NAME}>)
