#include "../../../include/xtd/tunit/string_assert.h"

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::tunit;

void string_assert::are_equal_ignoring_case(const ustring& expected, const ustring& actual) {
  are_equal_ignoring_case(expected, actual, ustring::empty_string, stack_frame::empty());
}

void string_assert::are_equal_ignoring_case(const ustring& expected, const ustring& actual, const stack_frame& stack_frame) {
  are_equal_ignoring_case(expected, actual, ustring::empty_string, stack_frame);
}

void string_assert::are_equal_ignoring_case(const ustring& expected, const ustring& actual, const ustring& message) {
  are_equal_ignoring_case(expected, actual, message, stack_frame::empty());
}

void string_assert::are_equal_ignoring_case(const ustring& expected, const ustring& actual, const ustring& message, const stack_frame& stack_frame) {
  if (actual.to_lower() == expected.to_lower())
    assert::succeed(message, stack_frame);
  else
    fail(to_string(expected) + ", ignoring case", to_string(actual), message, stack_frame);
}

void string_assert::are_not_equal_ignoring_case(const ustring& expected, const ustring& actual) {
  are_not_equal_ignoring_case(expected, actual, ustring::empty_string, stack_frame::empty());
}

void string_assert::are_not_equal_ignoring_case(const ustring& expected, const ustring& actual, const stack_frame& stack_frame) {
  are_not_equal_ignoring_case(expected, actual, ustring::empty_string, stack_frame);
}

void string_assert::are_not_equal_ignoring_case(const ustring& expected, const ustring& actual, const ustring& message) {
  are_not_equal_ignoring_case(expected, actual, message, stack_frame::empty());
}

void string_assert::are_not_equal_ignoring_case(const ustring& expected, const ustring& actual, const ustring& message, const stack_frame& stack_frame) {
  if (actual.to_lower() != expected.to_lower())
    assert::succeed(message, stack_frame);
  else
    fail("not " + to_string(expected) + ", ignoring case", to_string(actual), message, stack_frame);
}

void string_assert::contains(const ustring& item, const ustring& string) {
  contains(item, string, ustring::empty_string, stack_frame::empty());
}

void string_assert::contains(const ustring& item, const ustring& string, const stack_frame& stack_frame) {
  contains(item, string, ustring::empty_string, stack_frame);
}

void string_assert::contains(const ustring& item, const ustring& string, const ustring& message) {
  contains(item, string, message, stack_frame::empty());
}

void string_assert::contains(const ustring& item, const ustring& string, const ustring& message, const stack_frame& stack_frame) {
  if (string.find(item) != ustring::npos)
    assert::succeed(message, stack_frame);
  else
    fail("string containing " + to_string(item), to_string(string), message, stack_frame);
}

void string_assert::does_not_contain(const ustring& item, const ustring& string) {
  does_not_contain(item, string, ustring::empty_string, stack_frame::empty());
}

void string_assert::does_not_contain(const ustring& item, const ustring& string, const stack_frame& stack_frame) {
  does_not_contain(item, string, ustring::empty_string, stack_frame);
}

void string_assert::does_not_contain(const ustring& item, const ustring& string, const ustring& message) {
  does_not_contain(item, string, message, stack_frame::empty());
}

void string_assert::does_not_contain(const ustring& item, const ustring& string, const ustring& message, const stack_frame& stack_frame) {
  if (string.find(item) == ustring::npos)
    assert::succeed(message, stack_frame);
  else
    fail("not string containing " + to_string(item), to_string(string), message, stack_frame);
}

void string_assert::does_not_end_with(const ustring& item, const ustring& string) {
  does_not_end_with(item, string, ustring::empty_string, stack_frame::empty());
}

void string_assert::does_not_end_with(const ustring& item, const ustring& string, const stack_frame& stack_frame) {
  does_not_end_with(item, string, ustring::empty_string, stack_frame);
}

void string_assert::does_not_end_with(const ustring& item, const ustring& string, const ustring& message) {
  does_not_end_with(item, string, message, stack_frame::empty());
}

void string_assert::does_not_end_with(const ustring& item, const ustring& string, const ustring& message, const stack_frame& stack_frame) {
  if (string.rfind(item) + item.size() != string.size())
    assert::succeed(message, stack_frame);
  else
    fail("not string ending with " + to_string(item), to_string(string), message, stack_frame);
}

void string_assert::does_not_match(const ustring& regex_pattern, const ustring& actual) {
  does_not_match(regex_pattern, actual, ustring::empty_string, stack_frame::empty());
}

void string_assert::does_not_match(const ustring& regex_pattern, const ustring& actual, const stack_frame& stack_frame) {
  does_not_match(regex_pattern, actual, ustring::empty_string, stack_frame);
}

void string_assert::does_not_match(const ustring& regex_pattern, const ustring& actual, const ustring& message) {
  does_not_match(regex_pattern, actual, message, stack_frame::empty());
}

void string_assert::does_not_match(const ustring& regex_pattern, const ustring& actual, const ustring& message, const stack_frame& stack_frame) {
  std::string pattern(regex_pattern);
  std::regex r(pattern);
  std::smatch m;
  std::string act(actual);
  if (std::regex_search(act, m, r) == false)
    assert::succeed(message, stack_frame);
  else
    fail("not string matching " + to_string(regex_pattern), to_string(actual), message, stack_frame);
}

void string_assert::does_not_start_with(const ustring& item, const ustring& string) {
  does_not_start_with(item, string, ustring::empty_string, stack_frame::empty());
}

void string_assert::does_not_start_with(const ustring& item, const ustring& string, const stack_frame& stack_frame) {
  does_not_start_with(item, string, ustring::empty_string, stack_frame);
}

void string_assert::does_not_start_with(const ustring& item, const ustring& string, const ustring& message) {
  does_not_start_with(item, string, message, stack_frame::empty());
}

void string_assert::does_not_start_with(const ustring& item, const ustring& string, const ustring& message, const stack_frame& stack_frame) {
  if (string.find(item) != 0)
    assert::succeed(message, stack_frame);
  else
    fail("not string starting with " + to_string(item), to_string(string), message, stack_frame);
}

void string_assert::ends_with(const ustring& item, const ustring& string) {
  ends_with(item, string, ustring::empty_string, stack_frame::empty());
}

void string_assert::ends_with(const ustring& item, const ustring& string, const stack_frame& stack_frame) {
  ends_with(item, string, ustring::empty_string, stack_frame);
}

void string_assert::ends_with(const ustring& item, const ustring& string, const ustring& message) {
  ends_with(item, string, message, stack_frame::empty());
}

void string_assert::ends_with(const ustring& item, const ustring& string, const ustring& message, const stack_frame& stack_frame) {
  if (string.rfind(item) + item.size() == string.size())
    assert::succeed(message, stack_frame);
  else
    fail("string ending with " + to_string(item), to_string(string), message, stack_frame);
}

void string_assert::matches(const ustring& regex_pattern, const ustring& actual) {
  matches(regex_pattern, actual, ustring::empty_string, stack_frame::empty());
}

void string_assert::matches(const ustring& regex_pattern, const ustring& actual, const stack_frame& stack_frame) {
  matches(regex_pattern, actual, ustring::empty_string, stack_frame);
}

void string_assert::matches(const ustring& regex_pattern, const ustring& actual, const ustring& message) {
  matches(regex_pattern, actual, message, stack_frame::empty());
}

void string_assert::matches(const ustring& regex_pattern, const ustring& actual, const ustring& message, const stack_frame& stack_frame) {
  std::string pattern(regex_pattern);
  std::regex r(pattern);
  std::smatch m;
  std::string act(actual);
  if (std::regex_search(act, m, r) == true)
    assert::succeed(message, stack_frame);
  else
    fail("string matching " + to_string(regex_pattern), to_string(actual), message, stack_frame);
}

void string_assert::starts_with(const ustring& item, const ustring& string) {
  starts_with(item, string, ustring::empty_string, stack_frame::empty());
}

void string_assert::starts_with(const ustring& item, const ustring& string, const stack_frame& stack_frame) {
  starts_with(item, string, ustring::empty_string, stack_frame);
}

void string_assert::starts_with(const ustring& item, const ustring& string, const ustring& message) {
  starts_with(item, string, message, stack_frame::empty());
}

void string_assert::starts_with(const ustring& item, const ustring& string, const ustring& message, const stack_frame& stack_frame) {
  if (string.find(item) == 0)
    assert::succeed(message, stack_frame);
  else
    fail("string starting with " + to_string(item), to_string(string), message, stack_frame);
}
