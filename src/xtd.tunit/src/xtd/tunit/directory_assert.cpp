#include "../../../include/xtd/tunit/directory_assert.h"

using namespace xtd;
using namespace xtd::io;
using namespace xtd::tunit;

#if defined(__cpp_lib_filesystem)
using namespace std::filesystem;

void directory_assert::are_equal(const directory_entry& expected, const directory_entry& actual) {
  are_equal(expected, actual, "", xtd::diagnostics::stack_frame::empty());
}

void directory_assert::are_equal(const directory_entry& expected, const directory_entry& actual, const xtd::diagnostics::stack_frame& stack_frame) {
  are_equal(expected, actual, "", stack_frame);
}

void directory_assert::are_equal(const directory_entry& expected, const directory_entry& actual, const std::string& message) {
  are_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());
}

void directory_assert::are_equal(const directory_entry& expected, const directory_entry& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (expected != actual)
    base_assert::fail(base_assert::to_string(expected.path().string()), base_assert::to_string(actual.path().string()), message, stack_frame);
  else
    assert::succeed(message, stack_frame);
}
#endif

void directory_assert::are_equal(const directory_info& expected, const directory_info& actual) {
  are_equal(expected, actual, "", xtd::diagnostics::stack_frame::empty());
}

void directory_assert::are_equal(const directory_info& expected, const directory_info& actual, const xtd::diagnostics::stack_frame& stack_frame) {
  are_equal(expected, actual, "", stack_frame);
}

void directory_assert::are_equal(const directory_info& expected, const directory_info& actual, const std::string& message) {
  are_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());
}

void directory_assert::are_equal(const directory_info& expected, const directory_info& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (expected != actual)
    base_assert::fail(base_assert::to_string(expected.full_name()), base_assert::to_string(actual.full_name()), message, stack_frame);
  else
    assert::succeed(message, stack_frame);
}

#if defined(__cpp_lib_filesystem)
void directory_assert::are_not_equal(const directory_entry& expected, const directory_entry& actual) {
  are_not_equal(expected, actual, "", xtd::diagnostics::stack_frame::empty());
}

void directory_assert::are_not_equal(const directory_entry& expected, const directory_entry& actual, const xtd::diagnostics::stack_frame& stack_frame) {
  are_not_equal(expected, actual, "", stack_frame);
}

void directory_assert::are_not_equal(const directory_entry& expected, const directory_entry& actual, const std::string& message) {
  are_not_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());
}

void directory_assert::are_not_equal(const directory_entry& expected, const directory_entry& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (expected == actual)
    base_assert::fail("not " + base_assert::to_string(expected.path().string()), base_assert::to_string(actual.path().string()), message, stack_frame);
  else
    assert::succeed(message, stack_frame);
}
#endif

void directory_assert::are_not_equal(const directory_info& expected, const directory_info& actual) {
  are_not_equal(expected, actual, "", xtd::diagnostics::stack_frame::empty());
}

void directory_assert::are_not_equal(const directory_info& expected, const directory_info& actual, const xtd::diagnostics::stack_frame& stack_frame) {
  are_not_equal(expected, actual, "", stack_frame);
}

void directory_assert::are_not_equal(const directory_info& expected, const directory_info& actual, const std::string& message) {
  are_not_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());
}

void directory_assert::are_not_equal(const directory_info& expected, const directory_info& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (expected == actual)
    base_assert::fail("not " + base_assert::to_string(expected.full_name()), base_assert::to_string(actual.full_name()), message, stack_frame);
  else
    assert::succeed(message, stack_frame);
}
