cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.tunit.unit_tests)
set(SOURCES
  src/assert_unit_tests.hpp
  src/main.cpp
  src/one_test_one_test_case.cpp
  src/one_test_two_test_cases.cpp
  src/one_test_two_test_cases_and_one_ignore_test_case.cpp
  src/test_assert_are_equal_double_failed.cpp
  src/test_assert_are_equal_double_succeed.cpp
  src/test_assert_are_equal_double_NaN.cpp
  src/test_assert_are_equal_double_with_tolerence_failed.cpp
  src/test_assert_are_equal_double_with_tolerence_succeed.cpp
  src/test_assert_are_equal_failed.cpp
  src/test_assert_are_equal_float_failed.cpp
  src/test_assert_are_equal_float_succeed.cpp
  src/test_assert_are_equal_float_NaN.cpp
  src/test_assert_are_equal_float_with_tolerence_failed.cpp
  src/test_assert_are_equal_float_with_tolerence_succeed.cpp
  src/test_assert_are_equal_succeed.cpp
  src/test_assert_are_equal_long_double_with_tolerence_failed.cpp
  src/test_assert_are_equal_long_double_with_tolerence_succeed.cpp
  src/test_assert_are_not_equal_failed.cpp
  src/test_assert_are_not_equal_succeed.cpp
  src/test_assert_are_not_same_failed.cpp
  src/test_assert_are_not_same_succeed.cpp
  src/test_assert_are_same_failed.cpp
  src/test_assert_are_same_succeed.cpp
  src/test_assert_contains_collection_failed.cpp
  src/test_assert_contains_collection_succeed.cpp
  src/test_assert_contains_string_failed.cpp
  src/test_assert_contains_string_succeed.cpp
  src/test_assert_does_not_throw_failed.cpp
  src/test_assert_does_not_throw_succeed.cpp
  src/test_assert_fail_failed.cpp
  src/test_assert_is_empty_collection_failed.cpp
  src/test_assert_is_empty_collection_succeed.cpp
  src/test_assert_is_empty_string_failed.cpp
  src/test_assert_is_empty_string_succeed.cpp
  src/test_assert_is_false_succeed.cpp
  src/test_assert_is_false_failed.cpp
  src/test_insert_basic_output_stream_operator.cpp
  src/two_tests_five_test_cases.cpp
)
source_group(src FILES ${SOURCES})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Target
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} xtd.tunit)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd/tests")

# Tests
add_test(NAME ${PROJECT_NAME} COMMAND $<TARGET_FILE_NAME:${PROJECT_NAME}> WORKING_DIRECTORY $<TARGET_FILE_DIR:${PROJECT_NAME}>)
