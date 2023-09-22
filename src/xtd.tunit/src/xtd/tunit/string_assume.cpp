#include "../../../include/xtd/tunit/string_assume"

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::tunit;

void string_assume::are_equal_ignoring_case(const ustring& expected, const ustring& actual) {
  are_equal_ignoring_case(expected, actual, "", stack_frame::empty());
}

void string_assume::are_equal_ignoring_case(const ustring& expected, const ustring& actual, const stack_frame& stack_frame) {
  are_equal_ignoring_case(expected, actual, "", stack_frame);
}

void string_assume::are_equal_ignoring_case(const ustring& expected, const ustring& actual, const ustring& message) {
  are_equal_ignoring_case(expected, actual, message, stack_frame::empty());
}

void string_assume::are_equal_ignoring_case(const ustring& expected, const ustring& actual, const ustring& message, const stack_frame& stack_frame) {
  try {
    string_assert::are_equal_ignoring_case(expected, actual, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void string_assume::are_not_equal_ignoring_case(const ustring& expected, const ustring& actual) {
  are_not_equal_ignoring_case(expected, actual, "", stack_frame::empty());
}

void string_assume::are_not_equal_ignoring_case(const ustring& expected, const ustring& actual, const stack_frame& stack_frame) {
  are_not_equal_ignoring_case(expected, actual, "", stack_frame);
}

void string_assume::are_not_equal_ignoring_case(const ustring& expected, const ustring& actual, const ustring& message) {
  are_not_equal_ignoring_case(expected, actual, message, stack_frame::empty());
}

void string_assume::are_not_equal_ignoring_case(const ustring& expected, const ustring& actual, const ustring& message, const stack_frame& stack_frame) {
  try {
    string_assert::are_not_equal_ignoring_case(expected, actual, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void string_assume::contains(const ustring& item, const ustring& string) {
  contains(item, string, "", stack_frame::empty());
}

void string_assume::contains(const ustring& item, const ustring& string, const stack_frame& stack_frame) {
  contains(item, string, "", stack_frame);
}

void string_assume::contains(const ustring& item, const ustring& string, const ustring& message) {
  contains(item, string, message, stack_frame::empty());
}

void string_assume::contains(const ustring& item, const ustring& string, const ustring& message, const stack_frame& stack_frame) {
  try {
    string_assert::contains(item, string, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void string_assume::does_not_contain(const ustring& item, const ustring& string) {
  does_not_contain(item, string, "", stack_frame::empty());
}

void string_assume::does_not_contain(const ustring& item, const ustring& string, const stack_frame& stack_frame) {
  does_not_contain(item, string, "", stack_frame);
}

void string_assume::does_not_contain(const ustring& item, const ustring& string, const ustring& message) {
  does_not_contain(item, string, message, stack_frame::empty());
}

void string_assume::does_not_contain(const ustring& item, const ustring& string, const ustring& message, const stack_frame& stack_frame) {
  try {
    string_assert::does_not_contain(item, string, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void string_assume::does_not_end_with(const ustring& item, const ustring& string) {
  does_not_end_with(item, string, "", stack_frame::empty());
}

void string_assume::does_not_end_with(const ustring& item, const ustring& string, const stack_frame& stack_frame) {
  does_not_end_with(item, string, "", stack_frame);
}

void string_assume::does_not_end_with(const ustring& item, const ustring& string, const ustring& message) {
  does_not_end_with(item, string, message, stack_frame::empty());
}

void string_assume::does_not_end_with(const ustring& item, const ustring& string, const ustring& message, const stack_frame& stack_frame) {
  try {
    string_assert::does_not_end_with(item, string, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void string_assume::does_not_match(const ustring& regex_pattern, const ustring& actual) {
  does_not_match(regex_pattern, actual, "", stack_frame::empty());
}

void string_assume::does_not_match(const ustring& regex_pattern, const ustring& actual, const stack_frame& stack_frame) {
  does_not_match(regex_pattern, actual, "", stack_frame);
}

void string_assume::does_not_match(const ustring& regex_pattern, const ustring& actual, const ustring& message) {
  does_not_match(regex_pattern, actual, message, stack_frame::empty());
}

void string_assume::does_not_match(const ustring& regex_pattern, const ustring& actual, const ustring& message, const stack_frame& stack_frame) {
  try {
    string_assert::does_not_match(regex_pattern, actual, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void string_assume::does_not_start_with(const ustring& item, const ustring& string) {
  does_not_start_with(item, string, "", stack_frame::empty());
}

void string_assume::does_not_start_with(const ustring& item, const ustring& string, const stack_frame& stack_frame) {
  does_not_start_with(item, string, "", stack_frame);
}

void string_assume::does_not_start_with(const ustring& item, const ustring& string, const ustring& message) {
  does_not_start_with(item, string, message, stack_frame::empty());
}

void string_assume::does_not_start_with(const ustring& item, const ustring& string, const ustring& message, const stack_frame& stack_frame) {
  try {
    string_assert::does_not_start_with(item, string, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void string_assume::ends_with(const ustring& item, const ustring& string) {
  ends_with(item, string, "", stack_frame::empty());
}

void string_assume::ends_with(const ustring& item, const ustring& string, const stack_frame& stack_frame) {
  ends_with(item, string, "", stack_frame);
}

void string_assume::ends_with(const ustring& item, const ustring& string, const ustring& message) {
  ends_with(item, string, message, stack_frame::empty());
}

void string_assume::ends_with(const ustring& item, const ustring& string, const ustring& message, const stack_frame& stack_frame) {
  try {
    string_assert::ends_with(item, string, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void string_assume::matches(const ustring& regex_pattern, const ustring& actual) {
  matches(regex_pattern, actual, "", stack_frame::empty());
}

void string_assume::matches(const ustring& regex_pattern, const ustring& actual, const stack_frame& stack_frame) {
  matches(regex_pattern, actual, "", stack_frame);
}

void string_assume::matches(const ustring& regex_pattern, const ustring& actual, const ustring& message) {
  matches(regex_pattern, actual, message, stack_frame::empty());
}

void string_assume::matches(const ustring& regex_pattern, const ustring& actual, const ustring& message, const stack_frame& stack_frame) {
  try {
    string_assert::matches(regex_pattern, actual, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void string_assume::starts_with(const ustring& item, const ustring& string) {
  starts_with(item, string, "", stack_frame::empty());
}

void string_assume::starts_with(const ustring& item, const ustring& string, const stack_frame& stack_frame) {
  starts_with(item, string, "", stack_frame);
}

void string_assume::starts_with(const ustring& item, const ustring& string, const ustring& message) {
  starts_with(item, string, message, stack_frame::empty());
}

void string_assume::starts_with(const ustring& item, const ustring& string, const ustring& message, const stack_frame& stack_frame) {
  try {
    string_assert::starts_with(item, string, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}
