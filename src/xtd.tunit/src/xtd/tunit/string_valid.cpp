#include "../../../include/xtd/tunit/string_valid"

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

void string_valid::are_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual) {
  are_equal_ignoring_case(expected, actual, "", xtd::diagnostics::stack_frame::empty());
}

void string_valid::are_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual, const xtd::diagnostics::stack_frame& stack_frame) {
  are_equal_ignoring_case(expected, actual, "", stack_frame);
}

void string_valid::are_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual, const xtd::ustring& message) {
  are_equal_ignoring_case(expected, actual, message, xtd::diagnostics::stack_frame::empty());
}

void string_valid::are_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    string_assert::are_equal_ignoring_case(expected, actual, message, stack_frame);
  } catch (...) {
    base_assert::error();
  }
}

void string_valid::are_not_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual) {
  are_not_equal_ignoring_case(expected, actual, "", xtd::diagnostics::stack_frame::empty());
}

void string_valid::are_not_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual, const xtd::diagnostics::stack_frame& stack_frame) {
  are_not_equal_ignoring_case(expected, actual, "", stack_frame);
}

void string_valid::are_not_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual, const xtd::ustring& message) {
  are_not_equal_ignoring_case(expected, actual, message, xtd::diagnostics::stack_frame::empty());
}

void string_valid::are_not_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    string_assert::are_not_equal_ignoring_case(expected, actual, message, stack_frame);
  } catch (...) {
    base_assert::error();
  }
}

void string_valid::contains(const xtd::ustring& item, const xtd::ustring& string) {
  contains(item, string, "", xtd::diagnostics::stack_frame::empty());
}

void string_valid::contains(const xtd::ustring& item, const xtd::ustring& string, const xtd::diagnostics::stack_frame& stack_frame) {
  contains(item, string, "", stack_frame);
}

void string_valid::contains(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message) {
  contains(item, string, message, xtd::diagnostics::stack_frame::empty());
}

void string_valid::contains(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    string_assert::contains(item, string, message, stack_frame);
  } catch (...) {
    base_assert::error();
  }
}

void string_valid::does_not_contain(const xtd::ustring& item, const xtd::ustring& string) {
  does_not_contain(item, string, "", xtd::diagnostics::stack_frame::empty());
}

void string_valid::does_not_contain(const xtd::ustring& item, const xtd::ustring& string, const xtd::diagnostics::stack_frame& stack_frame) {
  does_not_contain(item, string, "", stack_frame);
}

void string_valid::does_not_contain(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message) {
  does_not_contain(item, string, message, xtd::diagnostics::stack_frame::empty());
}

void string_valid::does_not_contain(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    string_assert::does_not_contain(item, string, message, stack_frame);
  } catch (...) {
    base_assert::error();
  }
}

void string_valid::does_not_end_with(const xtd::ustring& item, const xtd::ustring& string) {
  does_not_end_with(item, string, "", xtd::diagnostics::stack_frame::empty());
}

void string_valid::does_not_end_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::diagnostics::stack_frame& stack_frame) {
  does_not_end_with(item, string, "", stack_frame);
}

void string_valid::does_not_end_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message) {
  does_not_end_with(item, string, message, xtd::diagnostics::stack_frame::empty());
}

void string_valid::does_not_end_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    string_assert::does_not_end_with(item, string, message, stack_frame);
  } catch (...) {
    base_assert::error();
  }
}

void string_valid::does_not_match(const xtd::ustring& regex_pattern, const xtd::ustring& actual) {
  does_not_match(regex_pattern, actual, "", xtd::diagnostics::stack_frame::empty());
}

void string_valid::does_not_match(const xtd::ustring& regex_pattern, const xtd::ustring& actual, const xtd::diagnostics::stack_frame& stack_frame) {
  does_not_match(regex_pattern, actual, "", stack_frame);
}

void string_valid::does_not_match(const xtd::ustring& regex_pattern, const xtd::ustring& actual, const xtd::ustring& message) {
  does_not_match(regex_pattern, actual, message, xtd::diagnostics::stack_frame::empty());
}

void string_valid::does_not_match(const xtd::ustring& regex_pattern, const xtd::ustring& actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    string_assert::does_not_match(regex_pattern, actual, message, stack_frame);
  } catch (...) {
    base_assert::error();
  }
}

void string_valid::does_not_start_with(const xtd::ustring& item, const xtd::ustring& string) {
  does_not_start_with(item, string, "", xtd::diagnostics::stack_frame::empty());
}

void string_valid::does_not_start_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::diagnostics::stack_frame& stack_frame) {
  does_not_start_with(item, string, "", stack_frame);
}

void string_valid::does_not_start_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message) {
  does_not_start_with(item, string, message, xtd::diagnostics::stack_frame::empty());
}

void string_valid::does_not_start_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    string_assert::does_not_start_with(item, string, message, stack_frame);
  } catch (...) {
    base_assert::error();
  }
}

void string_valid::ends_with(const xtd::ustring& item, const xtd::ustring& string) {
  ends_with(item, string, "", xtd::diagnostics::stack_frame::empty());
}

void string_valid::ends_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::diagnostics::stack_frame& stack_frame) {
  ends_with(item, string, "", stack_frame);
}

void string_valid::ends_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message) {
  ends_with(item, string, message, xtd::diagnostics::stack_frame::empty());
}

void string_valid::ends_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    string_assert::ends_with(item, string, message, stack_frame);
  } catch (...) {
    base_assert::error();
  }
}

void string_valid::matches(const xtd::ustring& regex_pattern, const xtd::ustring& actual) {matches(regex_pattern, actual, "", xtd::diagnostics::stack_frame::empty());}

void string_valid::matches(const xtd::ustring& regex_pattern, const xtd::ustring& actual, const xtd::diagnostics::stack_frame& stack_frame) {
  matches(regex_pattern, actual, "", stack_frame);
}

void string_valid::matches(const xtd::ustring& regex_pattern, const xtd::ustring& actual, const xtd::ustring& message) {
  matches(regex_pattern, actual, message, xtd::diagnostics::stack_frame::empty());
}

void string_valid::matches(const xtd::ustring& regex_pattern, const xtd::ustring& actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    string_assert::matches(regex_pattern, actual, message, stack_frame);
  } catch (...) {
    base_assert::error();
  }
}

void string_valid::starts_with(const xtd::ustring& item, const xtd::ustring& string) {
  starts_with(item, string, "", xtd::diagnostics::stack_frame::empty());
}

void string_valid::starts_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::diagnostics::stack_frame& stack_frame) {
  starts_with(item, string, "", stack_frame);
}

void string_valid::starts_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message) {
  starts_with(item, string, message, xtd::diagnostics::stack_frame::empty());
}

void string_valid::starts_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    string_assert::starts_with(item, string, message, stack_frame);
  } catch (...) {
    base_assert::error();
  }
}
