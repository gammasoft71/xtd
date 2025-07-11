cmake_minimum_required(VERSION 3.20)

# Project
project(xtd.tunit)
include("../../scripts/cmake/xtd_commands.cmake")
include("../../scripts/cmake/xtd_version.cmake")
add_include_directories("include")
add_references(xtd.core)
add_sources(
  "include/xtd/tunit/__default_insert_basic_ostream_operator.hpp"
  "include/xtd/tunit/__google_test_markers.hpp"
  "include/xtd/tunit/__tunit_join__items.hpp"
  "include/xtd/tunit/abort_error.hpp"
  "include/xtd/tunit/abort_error"
  "include/xtd/tunit/assert.hpp"
  "include/xtd/tunit/assert"
  "include/xtd/tunit/assert_error.hpp"
  "include/xtd/tunit/assert_error"
  "include/xtd/tunit/assume.hpp"
  "include/xtd/tunit/assume"
  "include/xtd/tunit/base_assert.hpp"
  "include/xtd/tunit/base_assert"
  "include/xtd/tunit/class_cleanup_attribute.hpp"
  "include/xtd/tunit/class_cleanup_attribute"
  "include/xtd/tunit/class_event_args.hpp"
  "include/xtd/tunit/class_event_args"
  "include/xtd/tunit/class_initialize_attribute.hpp"
  "include/xtd/tunit/class_initialize_attribute"
  "include/xtd/tunit/collection_assert.hpp"
  "include/xtd/tunit/collection_assert"
  "include/xtd/tunit/collection_assume.hpp"
  "include/xtd/tunit/collection_assume"
  "include/xtd/tunit/collection_valid.hpp"
  "include/xtd/tunit/collection_valid"
  "include/xtd/tunit/console_unit_test.hpp"
  "include/xtd/tunit/console_unit_test"
  "include/xtd/tunit/default_main.hpp"
  "include/xtd/tunit/default_main"
  "include/xtd/tunit/directory_assert.hpp"
  "include/xtd/tunit/directory_assert"
  "include/xtd/tunit/directory_assume.hpp"
  "include/xtd/tunit/directory_assume"
  "include/xtd/tunit/directory_valid.hpp"
  "include/xtd/tunit/directory_valid"
  "include/xtd/tunit/event_listener.hpp"
  "include/xtd/tunit/event_listener"
  "include/xtd/tunit/file_assert.hpp"
  "include/xtd/tunit/file_assert"
  "include/xtd/tunit/file_assume.hpp"
  "include/xtd/tunit/file_assume"
  "include/xtd/tunit/file_valid.hpp"
  "include/xtd/tunit/file_valid"
  "include/xtd/tunit/ignore_error.hpp"
  "include/xtd/tunit/ignore_error"
  "include/xtd/tunit/ostream_event_listener.hpp"
  "include/xtd/tunit/ostream_event_listener"
  "include/xtd/tunit/ostream_unit_test.hpp"
  "include/xtd/tunit/ostream_unit_test"
  "include/xtd/tunit/settings.hpp"
  "include/xtd/tunit/settings"
  "include/xtd/tunit/string_assert.hpp"
  "include/xtd/tunit/string_assert"
  "include/xtd/tunit/string_assume.hpp"
  "include/xtd/tunit/string_assume"
  "include/xtd/tunit/string_valid.hpp"
  "include/xtd/tunit/string_valid"
  "include/xtd/tunit/test.hpp"
  "include/xtd/tunit/test"
  "include/xtd/tunit/registered_test_class.hpp"
  "include/xtd/tunit/registered_test_class"
  "include/xtd/tunit/test_cleanup_attribute.hpp"
  "include/xtd/tunit/test_cleanup_attribute"
  "include/xtd/tunit/test_event_args.hpp"
  "include/xtd/tunit/test_event_args"
  "include/xtd/tunit/test_initialize_attribute.hpp"
  "include/xtd/tunit/test_initialize_attribute"
  "include/xtd/tunit/test_method_attribute.hpp"
  "include/xtd/tunit/test_method_attribute"
  "include/xtd/tunit/test_class.hpp"
  "include/xtd/tunit/test_class"
  "include/xtd/tunit/test_class_attribute.hpp"
  "include/xtd/tunit/test_class_attribute"
  "include/xtd/tunit/test_state.hpp"
  "include/xtd/tunit/test_state"
  "include/xtd/tunit/tunit_event_args.hpp"
  "include/xtd/tunit/tunit_event_args"
  "include/xtd/tunit/tunit_main.hpp"
  "include/xtd/tunit/tunit_main"
  "include/xtd/tunit/unit_test.hpp"
  "include/xtd/tunit/unit_test"
  "include/xtd/tunit/valid.hpp"
  "include/xtd/tunit/valid"
  "include/xtd/gtest.hpp"
  "include/xtd/gtest"
  "include/xtd/xtd.tunit"
  "include/xtd/xtd.tunit.hpp"
)
add_sources(
  "src/xtd/tunit/assert.cpp"
  "src/xtd/tunit/assume.cpp"
  "src/xtd/tunit/console_unit_test.cpp"
  "src/xtd/tunit/base_assert.cpp"
  "src/xtd/tunit/directory_assert.cpp"
  "src/xtd/tunit/directory_assume.cpp"
  "src/xtd/tunit/directory_valid.cpp"
  "src/xtd/tunit/ostream_event_listener.cpp"
  "src/xtd/tunit/ostream_unit_test.cpp"
  "src/xtd/tunit/registered_test_class.cpp"
  "src/xtd/tunit/settings.cpp"
  "src/xtd/tunit/string_assert.cpp"
  "src/xtd/tunit/string_assume.cpp"
  "src/xtd/tunit/string_valid.cpp"
  "src/xtd/tunit/tunit_main.cpp"
  "src/xtd/tunit/test.cpp"
  "src/xtd/tunit/test_class.cpp"
  "src/xtd/tunit/unit_test.cpp"
  "src/xtd/tunit/valid.cpp"
)
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories("include/xtd")
install_component()
