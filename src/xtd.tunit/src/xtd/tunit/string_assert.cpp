#include "../../../include/xtd/tunit/string_assert"

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

void string_assert::are_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual) {
  are_equal_ignoring_case(expected, actual, "", xtd::diagnostics::stack_frame::empty());
}

void string_assert::are_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual, const xtd::diagnostics::stack_frame& stack_frame) {
  are_equal_ignoring_case(expected, actual, "", stack_frame);
}

void string_assert::are_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual, const xtd::ustring& message) {
  are_equal_ignoring_case(expected, actual, message, xtd::diagnostics::stack_frame::empty());
}

void string_assert::are_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (actual.to_lower() == expected.to_lower())
    assert::succeed(message, stack_frame);
  else
    base_assert::fail(base_assert::to_string(expected) + ", ignoring case", base_assert::to_string(actual), message, stack_frame);
}

void string_assert::are_not_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual) {
  are_not_equal_ignoring_case(expected, actual, "", xtd::diagnostics::stack_frame::empty());
}

void string_assert::are_not_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual, const xtd::diagnostics::stack_frame& stack_frame) {
  are_not_equal_ignoring_case(expected, actual, "", stack_frame);
}

void string_assert::are_not_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual, const xtd::ustring& message) {
  are_not_equal_ignoring_case(expected, actual, message, xtd::diagnostics::stack_frame::empty());
}

void string_assert::are_not_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (actual.to_lower() != expected.to_lower())
    assert::succeed(message, stack_frame);
  else
    base_assert::fail("not " + base_assert::to_string(expected) + ", ignoring case", base_assert::to_string(actual), message, stack_frame);
}

void string_assert::contains(const xtd::ustring& item, const xtd::ustring& string) {
  contains(item, string, "", xtd::diagnostics::stack_frame::empty());
}

void string_assert::contains(const xtd::ustring& item, const xtd::ustring& string, const xtd::diagnostics::stack_frame& stack_frame) {
  contains(item, string, "", stack_frame);
}

void string_assert::contains(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message) {
  contains(item, string, message, xtd::diagnostics::stack_frame::empty());
}

void string_assert::contains(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (string.find(item) != xtd::ustring::npos)
    assert::succeed(message, stack_frame);
  else
    base_assert::fail("string containing " + base_assert::to_string(item), base_assert::to_string(string), message, stack_frame);
}

void string_assert::does_not_contain(const xtd::ustring& item, const xtd::ustring& string) {
  does_not_contain(item, string, "", xtd::diagnostics::stack_frame::empty());
}

void string_assert::does_not_contain(const xtd::ustring& item, const xtd::ustring& string, const xtd::diagnostics::stack_frame& stack_frame) {
  does_not_contain(item, string, "", stack_frame);
}

void string_assert::does_not_contain(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message) {
  does_not_contain(item, string, message, xtd::diagnostics::stack_frame::empty());
}

void string_assert::does_not_contain(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (string.find(item) == xtd::ustring::npos)
    assert::succeed(message, stack_frame);
  else
    base_assert::fail("not string containing " + base_assert::to_string(item), base_assert::to_string(string), message, stack_frame);
}

void string_assert::does_not_end_with(const xtd::ustring& item, const xtd::ustring& string) {
  does_not_end_with(item, string, "", xtd::diagnostics::stack_frame::empty());
}

void string_assert::does_not_end_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::diagnostics::stack_frame& stack_frame) {
  does_not_end_with(item, string, "", stack_frame);
}

void string_assert::does_not_end_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message) {
  does_not_end_with(item, string, message, xtd::diagnostics::stack_frame::empty());
}

void string_assert::does_not_end_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (string.rfind(item) + item.size() != string.size())
    assert::succeed(message, stack_frame);
  else
    base_assert::fail("not string ending with " + base_assert::to_string(item), base_assert::to_string(string), message, stack_frame);
}

void string_assert::does_not_match(const xtd::ustring& regex_pattern, const xtd::ustring& actual) {
  does_not_match(regex_pattern, actual, "", xtd::diagnostics::stack_frame::empty());
}

void string_assert::does_not_match(const xtd::ustring& regex_pattern, const xtd::ustring& actual, const xtd::diagnostics::stack_frame& stack_frame) {
  does_not_match(regex_pattern, actual, "", stack_frame);
}

void string_assert::does_not_match(const xtd::ustring& regex_pattern, const xtd::ustring& actual, const xtd::ustring& message) {
  does_not_match(regex_pattern, actual, message, xtd::diagnostics::stack_frame::empty());
}

void string_assert::does_not_match(const xtd::ustring& regex_pattern, const xtd::ustring& actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  std::string pattern(regex_pattern);
  std::regex r(pattern);
  std::smatch m;
  std::string act(actual);
  if (std::regex_search(act, m, r) == false)
    assert::succeed(message, stack_frame);
  else
    base_assert::fail("not string matching " + base_assert::to_string(regex_pattern), base_assert::to_string(actual), message, stack_frame);
}

void string_assert::does_not_start_with(const xtd::ustring& item, const xtd::ustring& string) {
  does_not_start_with(item, string, "", xtd::diagnostics::stack_frame::empty());
}

void string_assert::does_not_start_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::diagnostics::stack_frame& stack_frame) {
  does_not_start_with(item, string, "", stack_frame);
}

void string_assert::does_not_start_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message) {
  does_not_start_with(item, string, message, xtd::diagnostics::stack_frame::empty());
}

void string_assert::does_not_start_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (string.find(item) != 0)
    assert::succeed(message, stack_frame);
  else
    base_assert::fail("not string starting with " + base_assert::to_string(item), base_assert::to_string(string), message, stack_frame);
}

void string_assert::ends_with(const xtd::ustring& item, const xtd::ustring& string) {
  ends_with(item, string, "", xtd::diagnostics::stack_frame::empty());
}

void string_assert::ends_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::diagnostics::stack_frame& stack_frame) {
  ends_with(item, string, "", stack_frame);
}

void string_assert::ends_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message) {
  ends_with(item, string, message, xtd::diagnostics::stack_frame::empty());
}

void string_assert::ends_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (string.rfind(item) + item.size() == string.size())
    assert::succeed(message, stack_frame);
  else
    base_assert::fail("string ending with " + base_assert::to_string(item), base_assert::to_string(string), message, stack_frame);
}

void string_assert::matches(const xtd::ustring& regex_pattern, const xtd::ustring& actual) {
  matches(regex_pattern, actual, "", xtd::diagnostics::stack_frame::empty());
}

void string_assert::matches(const xtd::ustring& regex_pattern, const xtd::ustring& actual, const xtd::diagnostics::stack_frame& stack_frame) {
  matches(regex_pattern, actual, "", stack_frame);
}

void string_assert::matches(const xtd::ustring& regex_pattern, const xtd::ustring& actual, const xtd::ustring& message) {
  matches(regex_pattern, actual, message, xtd::diagnostics::stack_frame::empty());
}

void string_assert::matches(const xtd::ustring& regex_pattern, const xtd::ustring& actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  std::string pattern(regex_pattern);
  std::regex r(pattern);
  std::smatch m;
  std::string act(actual);
  if (std::regex_search(act, m, r) == true)
    assert::succeed(message, stack_frame);
  else
    base_assert::fail("string matching " + base_assert::to_string(regex_pattern), base_assert::to_string(actual), message, stack_frame);
}

void string_assert::starts_with(const xtd::ustring& item, const xtd::ustring& string) {
  starts_with(item, string, "", xtd::diagnostics::stack_frame::empty());
}

void string_assert::starts_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::diagnostics::stack_frame& stack_frame) {
  starts_with(item, string, "", stack_frame);
}

void string_assert::starts_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message) {
  starts_with(item, string, message, xtd::diagnostics::stack_frame::empty());
}

void string_assert::starts_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (string.find(item) == 0)
    assert::succeed(message, stack_frame);
  else
    base_assert::fail("string starting with " + base_assert::to_string(item), base_assert::to_string(string), message, stack_frame);
}
