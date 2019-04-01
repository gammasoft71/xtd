cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.strings.unit_tests)
set(SOURCES
  src/main.cpp 
  src/boolean_format.cpp
  src/string_boolean_format.cpp
  src/string_enum_format.cpp
  src/string_enum_class_format.cpp
  src/string_fixed_point_format.cpp
  src/string_format.cpp
  src/string_numeric_format.cpp
  src/strings.cpp
  src/wstring_fixed_point_format.cpp
  src/wstring_numeric_format.cpp
)
source_group(src FILES ${SOURCES})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8 /wd4309")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /bigobj")
endif ()


# Target
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} xtd.strings xtd.tunit)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd/tests")

# Tests
add_test(NAME ${PROJECT_NAME} COMMAND $<TARGET_FILE_NAME:${PROJECT_NAME}> WORKING_DIRECTORY $<TARGET_FILE_DIR:${PROJECT_NAME}>)
