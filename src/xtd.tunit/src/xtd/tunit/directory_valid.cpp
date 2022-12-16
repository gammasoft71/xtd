#include "../../../include/xtd/tunit/directory_valid.h"

using namespace xtd;
using namespace xtd::tunit;

#if defined(__cpp_lib_filesystem)
using namespace std::filesystem;

void directory_valid::are_equal(const directory_entry& expected, const directory_entry& actual) {
  are_equal(expected, actual, "", xtd::diagnostics::stack_frame::empty());
}

void directory_valid::are_equal(const directory_entry& expected, const directory_entry& actual, const xtd::diagnostics::stack_frame& stack_frame) {
  are_equal(expected, actual, "", stack_frame);
}

void directory_valid::are_equal(const directory_entry& expected, const directory_entry& actual, const std::string& message) {
  are_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());
}

void directory_valid::are_equal(const directory_entry& expected, const directory_entry& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    directory_assert::are_equal(expected, actual, message, stack_frame);
  } catch (...) {
    base_assert::error();
  }
}

void directory_valid::are_not_equal(const directory_entry& expected, const directory_entry& actual) {
  are_not_equal(expected, actual, "", xtd::diagnostics::stack_frame::empty());
}

void directory_valid::are_not_equal(const directory_entry& expected, const directory_entry& actual, const xtd::diagnostics::stack_frame& stack_frame) {
  are_not_equal(expected, actual, "", stack_frame);
}

void directory_valid::are_not_equal(const directory_entry& expected, const directory_entry& actual, const std::string& message) {are_not_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}

void directory_valid::are_not_equal(const directory_entry& expected, const directory_entry& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    directory_assert::are_not_equal(expected, actual, message, stack_frame);
  } catch (...) {
    base_assert::error();
  }
}
#endif
