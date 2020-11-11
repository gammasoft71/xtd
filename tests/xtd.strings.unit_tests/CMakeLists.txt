cmake_minimum_required(VERSION 3.3)

if (MSVC)
  # warning level 4 and all warnings as errors
  add_compile_options(/W4 /wd4100 /wd4458 /wd4127 /WX)
endif()

# Project
project(xtd.strings.unit_tests)
set(SOURCES
  src/main.cpp 
  src/numeric_parse_currency.cpp
  src/numeric_parse_default.cpp
  src/numeric_parse_fixed_point.cpp
  src/numeric_parse_integer.cpp
  src/numeric_parse_none.cpp
  src/numeric_parse_number.cpp
  src/parse.cpp
  src/string_boolean_format.cpp
  src/string_date_time_format.cpp
  src/string_duration_format.cpp
  src/string_enum_format.cpp
  src/string_enum_class_format.cpp
  src/string_fixed_point_format.cpp
  src/string_numeric_format.cpp
  src/string_object_format.cpp
  src/string_object_format_without_xtd_to_string.cpp
  src/string_string_format.cpp
  src/strings.cpp
  src/wstring_boolean_format.cpp
  src/wstring_date_time_format.cpp
  src/wstring_enum_format.cpp
  src/wstring_enum_class_format.cpp
  src/wstring_fixed_point_format.cpp
  src/wstring_numeric_format.cpp
  src/wstring_object_format.cpp
  src/wstring_object_format_without_xtd_to_string.cpp
  src/wstring_string_format.cpp
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
