#include "../../../include/xtd/tunit/directory_assume.hpp"

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::io;
using namespace xtd::tunit;

void directory_assume::are_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual, const stack_frame& stack_frame) {
  are_equal(expected, actual, string::empty_string, stack_frame);
}

void directory_assume::are_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual, const std::string& message, const stack_frame& stack_frame) {
  try {
    directory_assert::are_equal(expected, actual, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void directory_assume::are_equal(const directory_info& expected, const directory_info& actual, const stack_frame& stack_frame) {
  are_equal(expected, actual, string::empty_string, stack_frame);
}

void directory_assume::are_equal(const directory_info& expected, const directory_info& actual, const std::string& message, const stack_frame& stack_frame) {
  try {
    directory_assert::are_equal(expected, actual, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void directory_assume::are_not_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual, const stack_frame& stack_frame) {
  are_not_equal(expected, actual, string::empty_string, stack_frame);
}

void directory_assume::are_not_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual, const std::string& message, const stack_frame& stack_frame) {
  try {
    directory_assert::are_not_equal(expected, actual, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void directory_assume::are_not_equal(const directory_info& expected, const directory_info& actual, const stack_frame& stack_frame) {
  are_not_equal(expected, actual, string::empty_string, stack_frame);
}

void directory_assume::are_not_equal(const directory_info& expected, const directory_info& actual, const std::string& message, const stack_frame& stack_frame) {
  try {
    directory_assert::are_not_equal(expected, actual, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void directory_assume::does_not_exist(const std::filesystem::directory_entry& directory, const stack_frame& stack_frame) {
  does_not_exist(directory, string::empty_string, stack_frame);
}

void directory_assume::does_not_exist(const std::filesystem::directory_entry& directory, const std::string& message, const stack_frame& stack_frame) {
  does_not_exist(directory_info(directory.path().string()), message, stack_frame);
}

void directory_assume::does_not_exist(const directory_info& directory, const stack_frame& stack_frame) {
  does_not_exist(directory, string::empty_string, stack_frame);
}

void directory_assume::does_not_exist(const directory_info& directory, const std::string& message, const stack_frame& stack_frame) {
  try {
    directory_assert::does_not_exist(directory, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void directory_assume::exists(const std::filesystem::directory_entry& directory, const stack_frame& stack_frame) {
  exists(directory, string::empty_string, stack_frame);
}

void directory_assume::exists(const std::filesystem::directory_entry& directory, const std::string& message, const stack_frame& stack_frame) {
  exists(directory_info(directory.path().string()), message, stack_frame);
}

void directory_assume::exists(const directory_info& directory, const stack_frame& stack_frame) {
  exists(directory, string::empty_string, stack_frame);
}

void directory_assume::exists(const directory_info& directory, const std::string& message, const stack_frame& stack_frame) {
  try {
    directory_assert::exists(directory, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

