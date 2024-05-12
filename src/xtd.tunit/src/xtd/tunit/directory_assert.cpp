#include "../../../include/xtd/tunit/directory_assert.h"

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::io;
using namespace xtd::tunit;

#if defined(__cpp_lib_filesystem)
using namespace std::filesystem;

void directory_assert::are_equal(const directory_entry& expected, const directory_entry& actual) {
  are_equal(expected, actual, ustring::empty_string, stack_frame::empty());
}

void directory_assert::are_equal(const directory_entry& expected, const directory_entry& actual, const stack_frame& stack_frame) {
  are_equal(expected, actual, ustring::empty_string, stack_frame);
}

void directory_assert::are_equal(const directory_entry& expected, const directory_entry& actual, const std::string& message) {
  are_equal(expected, actual, message, stack_frame::empty());
}

void directory_assert::are_equal(const directory_entry& expected, const directory_entry& actual, const std::string& message, const stack_frame& stack_frame) {
  are_equal(directory_info(expected.path().string()), directory_info(actual.path().string()), message, stack_frame);
}
#endif

void directory_assert::are_equal(const directory_info& expected, const directory_info& actual) {
  are_equal(expected, actual, ustring::empty_string, stack_frame::empty());
}

void directory_assert::are_equal(const directory_info& expected, const directory_info& actual, const stack_frame& stack_frame) {
  are_equal(expected, actual, ustring::empty_string, stack_frame);
}

void directory_assert::are_equal(const directory_info& expected, const directory_info& actual, const std::string& message) {
  are_equal(expected, actual, message, stack_frame::empty());
}

void directory_assert::are_equal(const directory_info& expected, const directory_info& actual, const std::string& message, const stack_frame& stack_frame) {
  if (expected.full_name() != actual.full_name())
    fail(to_string(expected.full_name()), to_string(actual.full_name()), message, stack_frame);
  else
    assert::succeed(message, stack_frame);
}

#if defined(__cpp_lib_filesystem)
void directory_assert::are_not_equal(const directory_entry& expected, const directory_entry& actual) {
  are_not_equal(expected, actual, ustring::empty_string, stack_frame::empty());
}

void directory_assert::are_not_equal(const directory_entry& expected, const directory_entry& actual, const stack_frame& stack_frame) {
  are_not_equal(expected, actual, ustring::empty_string, stack_frame);
}

void directory_assert::are_not_equal(const directory_entry& expected, const directory_entry& actual, const std::string& message) {
  are_not_equal(expected, actual, message, stack_frame::empty());
}

void directory_assert::are_not_equal(const directory_entry& expected, const directory_entry& actual, const std::string& message, const stack_frame& stack_frame) {
  are_not_equal(directory_info(expected.path().string()), directory_info(actual.path().string()), message, stack_frame);
}
#endif

void directory_assert::are_not_equal(const directory_info& expected, const directory_info& actual) {
  are_not_equal(expected, actual, ustring::empty_string, stack_frame::empty());
}

void directory_assert::are_not_equal(const directory_info& expected, const directory_info& actual, const stack_frame& stack_frame) {
  are_not_equal(expected, actual, ustring::empty_string, stack_frame);
}

void directory_assert::are_not_equal(const directory_info& expected, const directory_info& actual, const std::string& message) {
  are_not_equal(expected, actual, message, stack_frame::empty());
}

void directory_assert::are_not_equal(const directory_info& expected, const directory_info& actual, const std::string& message, const stack_frame& stack_frame) {
  if (expected.full_name() == actual.full_name())
    fail("not " + to_string(expected.full_name()), to_string(actual.full_name()), message, stack_frame);
  else
    assert::succeed(message, stack_frame);
}

#if defined(__cpp_lib_filesystem)
void directory_assert::does_not_exist(const std::filesystem::directory_entry& directory) {
  does_not_exist(directory, ustring::empty_string, stack_frame::empty());
}

void directory_assert::does_not_exist(const std::filesystem::directory_entry& directory, const stack_frame& stack_frame) {
  does_not_exist(directory, ustring::empty_string, stack_frame);
}

void directory_assert::does_not_exist(const std::filesystem::directory_entry& directory, const std::string& message) {
  does_not_exist(directory, message, stack_frame::empty());
}

void directory_assert::does_not_exist(const std::filesystem::directory_entry& directory, const std::string& message, const stack_frame& stack_frame) {
  does_not_exist(directory_info(directory.path().string()), message, stack_frame);
}
#endif

void directory_assert::does_not_exist(const directory_info& directory) {
  does_not_exist(directory, ustring::empty_string, stack_frame::empty());
}

void directory_assert::does_not_exist(const directory_info& directory, const stack_frame& stack_frame) {
  does_not_exist(directory, ustring::empty_string, stack_frame);
}

void directory_assert::does_not_exist(const directory_info& directory, const std::string& message) {
  does_not_exist(directory, message, stack_frame::empty());
}

void directory_assert::does_not_exist(const directory_info& directory, const std::string& message, const stack_frame& stack_frame) {
  if (directory::exists(directory.full_name()))
    fail("not directory exists", "\"" + to_string(directory) + "\"", message, stack_frame);
  else
    assert::succeed(message, stack_frame);
}

#if defined(__cpp_lib_filesystem)
void directory_assert::exists(const std::filesystem::directory_entry& directory) {
  exists(directory, ustring::empty_string, stack_frame::empty());
}

void directory_assert::exists(const std::filesystem::directory_entry& directory, const stack_frame& stack_frame) {
  exists(directory, ustring::empty_string, stack_frame);
}

void directory_assert::exists(const std::filesystem::directory_entry& directory, const std::string& message) {
  exists(directory, message, stack_frame::empty());
}

void directory_assert::exists(const std::filesystem::directory_entry& directory, const std::string& message, const stack_frame& stack_frame) {
  exists(directory_info(directory.path().string()), message, stack_frame);
}
#endif

void directory_assert::exists(const directory_info& directory) {
  exists(directory, ustring::empty_string, stack_frame::empty());
}

void directory_assert::exists(const directory_info& directory, const stack_frame& stack_frame) {
  exists(directory, ustring::empty_string, stack_frame);
}

void directory_assert::exists(const directory_info& directory, const std::string& message) {
  exists(directory, message, stack_frame::empty());
}

void directory_assert::exists(const directory_info& directory, const std::string& message, const stack_frame& stack_frame) {
  if (!directory.exists())
    fail("directory exists", "\"" + to_string(directory) + "\"", message, stack_frame);
  else
    assert::succeed(message, stack_frame);
}
