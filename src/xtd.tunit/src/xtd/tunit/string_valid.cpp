#include "../../../include/xtd/tunit/string_valid.h"

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::tunit;

void string_valid::are_equal_ignoring_case(const xtd::string& expected, const xtd::string& actual, const stack_frame& stack_frame) {
  are_equal_ignoring_case(expected, actual, string::empty_string, stack_frame);
}

void string_valid::are_equal_ignoring_case(const xtd::string& expected, const xtd::string& actual, const xtd::string& message, const stack_frame& stack_frame) {
  try {
    string_assert::are_equal_ignoring_case(expected, actual, message, stack_frame);
  } catch (...) {
    error();
  }
}

void string_valid::are_not_equal_ignoring_case(const xtd::string& expected, const xtd::string& actual, const stack_frame& stack_frame) {
  are_not_equal_ignoring_case(expected, actual, string::empty_string, stack_frame);
}

void string_valid::are_not_equal_ignoring_case(const xtd::string& expected, const xtd::string& actual, const xtd::string& message, const stack_frame& stack_frame) {
  try {
    string_assert::are_not_equal_ignoring_case(expected, actual, message, stack_frame);
  } catch (...) {
    error();
  }
}

void string_valid::contains(const xtd::string& item, const xtd::string& string, const stack_frame& stack_frame) {
  contains(item, string, string::empty_string, stack_frame);
}

void string_valid::contains(const xtd::string& item, const xtd::string& string, const xtd::string& message, const stack_frame& stack_frame) {
  try {
    string_assert::contains(item, string, message, stack_frame);
  } catch (...) {
    error();
  }
}

void string_valid::does_not_contain(const xtd::string& item, const xtd::string& string, const stack_frame& stack_frame) {
  does_not_contain(item, string, string::empty_string, stack_frame);
}

void string_valid::does_not_contain(const xtd::string& item, const xtd::string& string, const xtd::string& message, const stack_frame& stack_frame) {
  try {
    string_assert::does_not_contain(item, string, message, stack_frame);
  } catch (...) {
    error();
  }
}

void string_valid::does_not_end_with(const xtd::string& item, const xtd::string& string, const stack_frame& stack_frame) {
  does_not_end_with(item, string, string::empty_string, stack_frame);
}

void string_valid::does_not_end_with(const xtd::string& item, const xtd::string& string, const xtd::string& message, const stack_frame& stack_frame) {
  try {
    string_assert::does_not_end_with(item, string, message, stack_frame);
  } catch (...) {
    error();
  }
}

void string_valid::does_not_match(const xtd::string& regex_pattern, const xtd::string& actual, const stack_frame& stack_frame) {
  does_not_match(regex_pattern, actual, string::empty_string, stack_frame);
}

void string_valid::does_not_match(const xtd::string& regex_pattern, const xtd::string& actual, const xtd::string& message, const stack_frame& stack_frame) {
  try {
    string_assert::does_not_match(regex_pattern, actual, message, stack_frame);
  } catch (...) {
    error();
  }
}

void string_valid::does_not_start_with(const xtd::string& item, const xtd::string& string, const stack_frame& stack_frame) {
  does_not_start_with(item, string, string::empty_string, stack_frame);
}

void string_valid::does_not_start_with(const xtd::string& item, const xtd::string& string, const xtd::string& message, const stack_frame& stack_frame) {
  try {
    string_assert::does_not_start_with(item, string, message, stack_frame);
  } catch (...) {
    error();
  }
}

void string_valid::ends_with(const xtd::string& item, const xtd::string& string, const stack_frame& stack_frame) {
  ends_with(item, string, string::empty_string, stack_frame);
}

void string_valid::ends_with(const xtd::string& item, const xtd::string& string, const xtd::string& message, const stack_frame& stack_frame) {
  try {
    string_assert::ends_with(item, string, message, stack_frame);
  } catch (...) {
    error();
  }
}

void string_valid::matches(const xtd::string& regex_pattern, const xtd::string& actual, const stack_frame& stack_frame) {
  matches(regex_pattern, actual, string::empty_string, stack_frame);
}

void string_valid::matches(const xtd::string& regex_pattern, const xtd::string& actual, const xtd::string& message, const stack_frame& stack_frame) {
  try {
    string_assert::matches(regex_pattern, actual, message, stack_frame);
  } catch (...) {
    error();
  }
}

void string_valid::starts_with(const xtd::string& item, const xtd::string& string, const stack_frame& stack_frame) {
  starts_with(item, string, string::empty_string, stack_frame);
}

void string_valid::starts_with(const xtd::string& item, const xtd::string& string, const xtd::string& message, const stack_frame& stack_frame) {
  try {
    string_assert::starts_with(item, string, message, stack_frame);
  } catch (...) {
    error();
  }
}
