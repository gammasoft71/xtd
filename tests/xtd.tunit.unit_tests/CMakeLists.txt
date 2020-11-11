cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.tunit.unit_tests)
set(SOURCES
  src/assert_unit_tests.h
  src/main.cpp
  src/one_test_one_test_case.cpp
  src/one_test_two_test_cases.cpp
  src/one_test_two_test_cases_and_one_ignore_test_case.cpp
  src/test_assert_abort_aborted.cpp
  src/test_assert_are_equal_const_char_pointer_failed.cpp
  src/test_assert_are_equal_const_char_pointer_succeed.cpp
  src/test_assert_are_equal_const_char16_t_pointer_failed.cpp
  src/test_assert_are_equal_const_char16_t_pointer_succeed.cpp
  src/test_assert_are_equal_const_char32_t_pointer_succeed.cpp
  src/test_assert_are_equal_const_wchar_t_pointer_failed.cpp
  src/test_assert_are_equal_const_wchar_t_pointer_succeed.cpp
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
  src/test_assert_are_not_equal_const_char_pointer_failed.cpp
  src/test_assert_are_not_equal_const_char_pointer_succeed.cpp
  src/test_assert_are_not_equal_const_char16_t_pointer_failed.cpp
  src/test_assert_are_not_equal_const_char16_t_pointer_succeed.cpp
  src/test_assert_are_not_equal_const_char32_t_pointer_failed.cpp
  src/test_assert_are_not_equal_const_char32_t_pointer_succeed.cpp
  src/test_assert_are_not_equal_const_wchar_t_pointer_failed.cpp
  src/test_assert_are_not_equal_const_wchar_t_pointer_succeed.cpp
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
  src/test_assert_is_false_failed.cpp
  src/test_assert_is_false_succeed.cpp
  src/test_assert_is_greater_failed.cpp
  src/test_assert_is_greater_succeed.cpp
  src/test_assert_is_greater_or_equal_failed.cpp
  src/test_assert_is_greater_or_equal_succeed.cpp
  src/test_assert_is_instance_of_failed.cpp
  src/test_assert_is_instance_of_succeed.cpp
  src/test_assert_is_less_failed.cpp
  src/test_assert_is_less_succeed.cpp
  src/test_assert_is_less_or_equal_failed.cpp
  src/test_assert_is_less_or_equal_succeed.cpp
  src/test_assert_is_NaN_double_failed.cpp
  src/test_assert_is_NaN_double_succeed.cpp
  src/test_assert_is_NaN_float_failed.cpp
  src/test_assert_is_NaN_float_succeed.cpp
  src/test_assert_is_NaN_long_double_failed.cpp
  src/test_assert_is_NaN_long_double_succeed.cpp
  src/test_assert_is_negative_failed.cpp
  src/test_assert_is_negative_succeed.cpp
  src/test_assert_is_not_empty_collection_failed.cpp
  src/test_assert_is_not_empty_collection_succeed.cpp
  src/test_assert_is_not_empty_string_failed.cpp
  src/test_assert_is_not_empty_string_succeed.cpp
  src/test_assert_is_not_instance_of_failed.cpp
  src/test_assert_is_not_instance_of_succeed.cpp
  src/test_assert_is_not_null_nullptr_failed.cpp
  src/test_assert_is_not_null_pointer_failed.cpp
  src/test_assert_is_not_null_pointer_succeed.cpp
  src/test_assert_is_not_null_unique_ptr_failed.cpp
  src/test_assert_is_not_null_unique_ptr_succeed.cpp
  src/test_assert_is_not_null_shared_ptr_failed.cpp
  src/test_assert_is_not_null_shared_ptr_succeed.cpp
  src/test_assert_is_not_null_weak_ptr_succeed.cpp
  src/test_assert_is_not_zero_failed.cpp
  src/test_assert_is_not_zero_succeed.cpp
  src/test_assert_is_null_nullptr_succeed.cpp
  src/test_assert_is_null_pointer_failed.cpp
  src/test_assert_is_null_pointer_succeed.cpp
  src/test_assert_is_null_unique_ptr_failed.cpp
  src/test_assert_is_null_unique_ptr_succeed.cpp
  src/test_assert_is_null_shared_ptr_failed.cpp
  src/test_assert_is_null_shared_ptr_succeed.cpp
  src/test_assert_is_null_weak_ptr_failed.cpp
  src/test_assert_is_positive_failed.cpp
  src/test_assert_is_positive_succeed.cpp
  src/test_assert_is_succeed_succeed.cpp
  src/test_assert_is_true_failed.cpp
  src/test_assert_is_true_succeed.cpp
  src/test_assert_is_zero_failed.cpp
  src/test_assert_is_zero_succeed.cpp
  src/test_assert_throws_failed.cpp
  src/test_assert_throws_succeed.cpp
  src/test_assert_throws_any_failed.cpp
  src/test_assert_throws_any_succeed.cpp
  src/test_insert_basic_output_stream_operator.cpp
  src/test_string_assert_are_equal_ignoring_case_const_char_pointer_failed.cpp
  src/test_string_assert_are_equal_ignoring_case_const_char_pointer_succeed.cpp
  src/test_string_assert_are_equal_ignoring_case_const_char16_t_pointer_failed.cpp
  src/test_string_assert_are_equal_ignoring_case_const_char16_t_pointer_succeed.cpp
  src/test_string_assert_are_equal_ignoring_case_const_char32_t_pointer_failed.cpp
  src/test_string_assert_are_equal_ignoring_case_const_char32_t_pointer_succeed.cpp
  src/test_string_assert_are_equal_ignoring_case_const_wchar_t_pointer_failed.cpp
  src/test_string_assert_are_equal_ignoring_case_const_wchar_t_pointer_succeed.cpp
  src/test_string_assert_are_equal_ignoring_case_string_failed.cpp
  src/test_string_assert_are_equal_ignoring_case_string_succeed.cpp
  src/test_string_assert_are_equal_ignoring_case_u16string_failed.cpp
  src/test_string_assert_are_equal_ignoring_case_u16string_succeed.cpp
  src/test_string_assert_are_equal_ignoring_case_u32string_failed.cpp
  src/test_string_assert_are_equal_ignoring_case_u32string_succeed.cpp
  src/test_string_assert_are_equal_ignoring_case_wstring_failed.cpp
  src/test_string_assert_are_equal_ignoring_case_wstring_succeed.cpp
  src/two_tests_five_test_cases.cpp
  src/unit_tests_event_listener.h
)
source_group(src FILES ${SOURCES})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4834")
endif ()


# Target
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} xtd.tunit)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd/tests")

# Tests
add_test(NAME ${PROJECT_NAME} COMMAND $<TARGET_FILE_NAME:${PROJECT_NAME}> WORKING_DIRECTORY $<TARGET_FILE_DIR:${PROJECT_NAME}>)
