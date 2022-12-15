#include "../../../include/xtd/tunit/assert.h"

using namespace xtd;
using namespace xtd::tunit;

void assert::are_equal(const char* expected, const char* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (strcmp(actual, expected) == 0)
    succeed(message, stack_frame);
  else
    base_assert::fail(base_assert::to_string(expected), base_assert::to_string(actual), message, stack_frame);
}

void assert::are_equal(const char8* expected, const char8* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (ustring(actual) == ustring(expected))
    succeed(message, stack_frame);
  else
    base_assert::base_assert::fail(base_assert::to_string(expected), base_assert::to_string(actual), message, stack_frame);
}

void assert::are_equal(const char16* expected, const char16* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (std::u16string(actual) == std::u16string(expected))
    succeed(message, stack_frame);
  else
    base_assert::base_assert::fail(base_assert::to_string(expected), base_assert::to_string(actual), message, stack_frame);
}

void assert::are_equal(const char32* expected, const char32* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (std::u32string(actual) == std::u32string(expected))
    succeed(message, stack_frame);
  else
    base_assert::fail(base_assert::to_string(expected), base_assert::to_string(actual), message, stack_frame);
}

void assert::are_equal(const wchar_t* expected, const wchar_t* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (wcscmp(actual, expected) == 0)
    succeed(message, stack_frame);
  else
    base_assert::fail(base_assert::to_string(expected), base_assert::to_string(actual), message, stack_frame);
}

void assert::are_equal(float expected, float actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (std::isnan(actual) && std::isnan(expected))
    succeed(message, stack_frame);
  else if (actual == expected)
    succeed(message, stack_frame);
  else
    base_assert::fail(base_assert::to_string(expected), base_assert::to_string(actual), message, stack_frame);
}

void assert::are_equal(double expected, double actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (std::isnan(actual) && std::isnan(expected))
    succeed(message, stack_frame);
  else if (actual == expected)
    succeed(message, stack_frame);
  else
    base_assert::fail(base_assert::to_string(expected), base_assert::to_string(actual), message, stack_frame);
}

void assert::are_equal(long double expected, long double actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (std::isnan(actual) && std::isnan(expected))
    succeed(message, stack_frame);
  else if (actual == expected)
    succeed(message, stack_frame);
  else
    base_assert::fail(base_assert::to_string(expected), base_assert::to_string(actual), message, stack_frame);
}

void assert::are_equal(float expected, float actual, float tolerance) {
  are_equal(expected, actual, tolerance, "", csf_);
}

void assert::are_equal(float expected, float actual, float tolerance, const xtd::diagnostics::stack_frame& stack_frame) {
  are_equal(expected, actual, tolerance, "", stack_frame);
}

void assert::are_equal(float expected, float& actual, float tolerance, const xtd::ustring& message) {
  are_equal(expected, actual, tolerance, message, xtd::diagnostics::stack_frame::empty());
}

void assert::are_equal(float expected, float actual, float tolerance, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (fabsf(expected - actual) <= fabsf(tolerance))
    succeed(message, stack_frame);
  else
    base_assert::fail(base_assert::to_string(expected), base_assert::to_string(actual), message, stack_frame);
}

void assert::are_equal(double expected, double actual, double tolerance) {
  are_equal(expected, actual, tolerance, "", csf_);
}

void assert::are_equal(double expected, double actual, double tolerance, const xtd::diagnostics::stack_frame& stack_frame) {
  are_equal(expected, actual, tolerance, "", stack_frame);
}

void assert::are_equal(double expected, double actual, double tolerance, const xtd::ustring& message) {
  are_equal(expected, actual, tolerance, message, xtd::diagnostics::stack_frame::empty());
}

void assert::are_equal(double expected, double actual, double tolerance, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (fabs(expected - actual) <= fabs(tolerance))
    succeed(message, stack_frame);
  else
    base_assert::fail(base_assert::to_string(expected), base_assert::to_string(actual), message, stack_frame);
}

void assert::are_equal(long double expected, long double actual, long double tolerance) {
  are_equal(expected, actual, tolerance, "", csf_);
}

void assert::are_equal(long double expected, long double actual, long double tolerance, const xtd::diagnostics::stack_frame& stack_frame) {
  are_equal(expected, actual, tolerance, "", stack_frame);
}

void assert::are_equal(long double expected, long double actual, long double tolerance, const xtd::ustring& message) {
  are_equal(expected, actual, tolerance, message, xtd::diagnostics::stack_frame::empty());
}

void assert::are_equal(long double expected, long double actual, long double tolerance, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (fabsl(expected - actual) <= fabsl(tolerance))
    succeed(message, stack_frame);
  else
    base_assert::fail(base_assert::to_string(expected), base_assert::to_string(actual), message, stack_frame);
}

void assert::are_not_equal(const char* expected, const char* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (strcmp(actual, expected) != 0)
    succeed(message, stack_frame);
  else
    base_assert::fail("not " + base_assert::to_string(expected), base_assert::to_string(actual), message, stack_frame);
}

void assert::are_not_equal(const char8* expected, const char8* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (ustring(actual) != ustring(expected))
    succeed(message, stack_frame);
  else
    base_assert::fail("not " + base_assert::to_string(expected), base_assert::to_string(actual), message, stack_frame);
}

void assert::are_not_equal(const char16* expected, const char16* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (std::u16string(actual) != std::u16string(expected))
    succeed(message, stack_frame);
  else
    base_assert::fail("not " + base_assert::to_string(expected), base_assert::to_string(actual), message, stack_frame);
}

void assert::are_not_equal(const char32* expected, const char32* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (std::u32string(actual) != std::u32string(expected))
    succeed(message, stack_frame);
  else
    base_assert::fail("not " + base_assert::to_string(expected), base_assert::to_string(actual), message, stack_frame);
}

void assert::are_not_equal(const wchar_t* expected, const wchar_t* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (wcscmp(actual, expected) != 0)
    succeed(message, stack_frame);
  else
    base_assert::fail("not " + base_assert::to_string(expected), base_assert::to_string(actual), message, stack_frame);
}

void assert::contains(char item, const char* values, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  ustring s(values);
  auto result = std::find(s.begin(), s.end(), item);
  if (result != s.end())
    succeed(message, stack_frame);
  else
    base_assert::fail("collection containing " + base_assert::to_string(item), base_assert::join_items(s), message, stack_frame);
}

void assert::contains(char8 item, const char8* values, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  std::u8string s(values);
  auto result = std::find(s.begin(), s.end(), item);
  if (result != s.end())
    succeed(message, stack_frame);
  else
    base_assert::fail("collection containing " + base_assert::to_string(item), base_assert::join_items(s), message, stack_frame);
}

void assert::contains(char16 item, const char16* values, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  std::u16string s(values);
  auto result = std::find(s.begin(), s.end(), item);
  if (result != s.end())
    succeed(message, stack_frame);
  else
    base_assert::fail("collection containing " + base_assert::to_string(item), base_assert::join_items(s), message, stack_frame);
}

void assert::contains(char32 item, const char32* values, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  std::u32string s(values);
  auto result = std::find(s.begin(), s.end(), item);
  if (result != s.end())
    succeed(message, stack_frame);
  else
    base_assert::fail("collection containing " + base_assert::to_string(item), base_assert::join_items(s), message, stack_frame);
}

void assert::contains(wchar_t item, const wchar_t* values, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  std::wstring s(values);
  auto result = std::find(s.begin(), s.end(), item);
  if (result != s.end())
    succeed(message, stack_frame);
  else
    base_assert::fail("collection containing " + base_assert::to_string(item), base_assert::join_items(s), message, stack_frame);
}

void assert::does_not_throw(const std::function<void()>& statement) {
  does_not_throw(statement, "", xtd::diagnostics::stack_frame::empty());
}

void assert::does_not_throw(const std::function<void()>& statement, const xtd::diagnostics::stack_frame& stack_frame) {
  does_not_throw(statement, "", stack_frame);
}

void assert::does_not_throw(const std::function<void()>& statement, const xtd::ustring& message) {
  does_not_throw(statement, message, xtd::diagnostics::stack_frame::empty());
}

void assert::does_not_throw(const std::function<void()>& statement, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    statement();
    succeed(message, stack_frame);
  } catch (const std::exception& e) {
    base_assert::fail("No Exception to be thrown", "<" + __tunit_demangle(typeid(e).name()) + ">", message, stack_frame);
  } catch (...) {
    base_assert::fail("No Exception to be thrown", "<exception>", message, stack_frame);
  }
}

void assert::is_empty(const char* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  ustring s(value);
  if (ustring::is_empty(s))
    succeed(message, stack_frame);
  else
    base_assert::fail("collection <empty>", base_assert::join_items(s), message, stack_frame);
}

void assert::is_empty(const char8* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  ustring s(value);
  if (ustring::is_empty(s))
    succeed(message, stack_frame);
  else
    base_assert::fail("collection <empty>", base_assert::join_items(s), message, stack_frame);
}

void assert::is_empty(const char16* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  ustring s(value);
  if (ustring::is_empty(s))
    succeed(message, stack_frame);
  else
    base_assert::fail("collection <empty>", base_assert::join_items(s), message, stack_frame);
}

void assert::is_empty(const char32* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  ustring s(value);
  if (ustring::is_empty(s))
    succeed(message, stack_frame);
  else
    base_assert::fail("collection <empty>", base_assert::join_items(s), message, stack_frame);
}

void assert::is_empty(const wchar_t* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  ustring s(value);
  if (ustring::is_empty(s))
    succeed(message, stack_frame);
  else
    base_assert::fail("collection <empty>", base_assert::join_items(s), message, stack_frame);
}

void assert::is_false(bool condition) {
  is_false(condition, "", xtd::diagnostics::stack_frame::empty());
}

void assert::is_false(bool condition, const xtd::diagnostics::stack_frame& stack_frame) {
  is_false(condition, "", stack_frame);
}

void assert::is_false(bool condition, const xtd::ustring& message) {
  is_false(condition, message, xtd::diagnostics::stack_frame::empty());
}

void assert::is_false(bool condition, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (condition == false)
    succeed(message, stack_frame);
  else
    base_assert::fail("false", "true", message, stack_frame);
}

void assert::is_greater(const char* val1, const char* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (strcmp(val1, val2) > 0)
    succeed(message, stack_frame);
  else
    base_assert::fail("greather than " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
}

void assert::is_greater(const char8* val1, const char8* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (ustring(val1) > ustring(val2))
    succeed(message, stack_frame);
  else
    base_assert::fail("greather than " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
}

void assert::is_greater(const char16* val1, const char16* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (std::u16string(val1) > std::u16string(val2))
    succeed(message, stack_frame);
  else
    base_assert::fail("greather than " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
}

void assert::is_greater(const char32* val1, const char32* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (std::u32string(val1) > std::u32string(val2))
    succeed(message, stack_frame);
  else
    base_assert::fail("greather than " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
}

void assert::is_greater(const wchar_t* val1, const wchar_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (wcscmp(val1, val2) > 0)
    succeed(message, stack_frame);
  else
    base_assert::fail("greather than " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
}

void assert::is_greater_or_equal(const char* val1, const char* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (strcmp(val1, val2) >= 0)
    succeed(message, stack_frame);
  else
    base_assert::fail("greather than or equal to " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
}

void assert::is_greater_or_equal(const char8* val1, const char8* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (ustring(val1) >= ustring(val2))
    succeed(message, stack_frame);
  else
    base_assert::fail("greather than " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
}

void assert::is_greater_or_equal(const char16* val1, const char16* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (std::u16string(val1) >= std::u16string(val2))
    succeed(message, stack_frame);
  else
    base_assert::fail("greather than " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
}

void assert::is_greater_or_equal(const char32* val1, const char32* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (std::u32string(val1) >= std::u32string(val2))
    succeed(message, stack_frame);
  else
    base_assert::fail("greather than " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
}

void assert::is_greater_or_equal(const wchar_t* val1, const wchar_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (wcscmp(val1, val2) >= 0)
    succeed(message, stack_frame);
  else
    base_assert::fail("greather than or equal to " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
}

void assert::is_less(const char* val1, const char* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (strcmp(val1, val2) < 0)
    succeed(message, stack_frame);
  else
    base_assert::fail("less than " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
}

void assert::is_less(const char8* val1, const char8* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (ustring(val1) < ustring(val2))
    succeed(message, stack_frame);
  else
    base_assert::fail("greather than " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
}

void assert::is_less(const char16* val1, const char16* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (std::u16string(val1) < std::u16string(val2))
    succeed(message, stack_frame);
  else
    base_assert::fail("greather than " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
}

void assert::is_less(const char32* val1, const char32* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (std::u32string(val1) < std::u32string(val2))
    succeed(message, stack_frame);
  else
    base_assert::fail("greather than " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
}

void assert::is_less(const wchar_t* val1, const wchar_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (wcscmp(val1, val2) < 0)
    succeed(message, stack_frame);
  else
    base_assert::fail("less than " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
}

void assert::is_less_or_equal(const char* val1, const char* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (strcmp(val1, val2) <= 0)
    succeed(message, stack_frame);
  else
    base_assert::fail("less than or equal to " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
}

void assert::is_less_or_equal(const char8* val1, const char8* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (ustring(val1) <= ustring(val2))
    succeed(message, stack_frame);
  else
    base_assert::fail("greather than " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
}

void assert::is_less_or_equal(const char16* val1, const char16* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (std::u16string(val1) <= std::u16string(val2))
    succeed(message, stack_frame);
  else
    base_assert::fail("greather than " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
}

void assert::is_less_or_equal(const char32* val1, const char32* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (std::u32string(val1) <= std::u32string(val2))
    succeed(message, stack_frame);
  else
    base_assert::fail("greather than " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
}

void assert::is_less_or_equal(const wchar_t* val1, const wchar_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (wcscmp(val1, val2) <= 0)
    succeed(message, stack_frame);
  else
    base_assert::fail("less than or equal to " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
}

void assert::is_NaN(double value) {
  is_NaN(value, "", xtd::diagnostics::stack_frame::empty());
}

void assert::is_NaN(double value, const xtd::diagnostics::stack_frame& stack_frame) {
  is_NaN(value, "", stack_frame);
}

void assert::is_NaN(double value, const xtd::ustring& message) {
  is_NaN(value, message, xtd::diagnostics::stack_frame::empty());
}

void assert::is_NaN(double value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (std::isnan(value))
    succeed(message, stack_frame);
  else
    base_assert::fail("NaN", base_assert::to_string(value), message, stack_frame);
}

void assert::is_NaN(long double value) {
  is_NaN(value, "", xtd::diagnostics::stack_frame::empty());
}

void assert::is_NaN(long double value, const xtd::diagnostics::stack_frame& stack_frame) {
  is_NaN(value, "", stack_frame);
}

void assert::is_NaN(long double value, const xtd::ustring& message) {
  is_NaN(value, message, xtd::diagnostics::stack_frame::empty());
}

void assert::is_NaN(long double value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (std::isnan(value))
    succeed(message, stack_frame);
  else
    base_assert::fail("NaN", base_assert::to_string(value), message, stack_frame);
}

void assert::is_NaN(float value) {
  is_NaN(value, "", xtd::diagnostics::stack_frame::empty());
}

void assert::is_NaN(float value, const xtd::diagnostics::stack_frame& stack_frame) {
  is_NaN(value, "", stack_frame);
}

void assert::is_NaN(float value, const xtd::ustring& message) {
  is_NaN(value, message, xtd::diagnostics::stack_frame::empty());
}

void assert::is_NaN(float value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (std::isnan(value))
    succeed(message, stack_frame);
  else
    base_assert::fail("NaN", base_assert::to_string(value), message, stack_frame);
}

void assert::is_not_empty(const char* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (!ustring::is_empty(ustring(value)))
    succeed(message, stack_frame);
  else
    base_assert::fail("collection not <empty>", "<empty>", message, stack_frame);
}

void assert::is_not_empty(const char8* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (!ustring::is_empty(ustring(value)))
    succeed(message, stack_frame);
  else
    base_assert::fail("collection not <empty>", "<empty>", message, stack_frame);
}

void assert::is_not_empty(const char16* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (!ustring::is_empty(ustring(value)))
    succeed(message, stack_frame);
  else
    base_assert::fail("collection not <empty>", "<empty>", message, stack_frame);
}

void assert::is_not_empty(const char32* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (!ustring::is_empty(ustring(value)))
    succeed(message, stack_frame);
  else
    base_assert::fail("collection not <empty>", "<empty>", message, stack_frame);
}

void assert::is_not_empty(const wchar_t* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (!ustring::is_empty(ustring(value)))
    succeed(message, stack_frame);
  else
    base_assert::fail("collection not <empty>", "<empty>", message, stack_frame);
}

void assert::is_not_null(std::nullptr_t pointer) {
  is_not_null(pointer, "", xtd::diagnostics::stack_frame::empty());
}

void assert::is_not_null(std::nullptr_t pointer, const xtd::diagnostics::stack_frame& stack_frame) {
  is_not_null(pointer, "", stack_frame);
}

void assert::is_not_null(std::nullptr_t pointer, const xtd::ustring& message) {
  is_not_null(pointer, message, xtd::diagnostics::stack_frame::empty());
}

void assert::is_not_null(std::nullptr_t pointer, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  base_assert::fail("not null", "null", message, stack_frame);
}

void assert::is_null(std::nullptr_t pointer) {
  is_null(pointer, "", xtd::diagnostics::stack_frame::empty());
}

void assert::is_null(std::nullptr_t pointer, const xtd::diagnostics::stack_frame& stack_frame) {
  is_null(pointer, "", stack_frame);
}

void assert::is_null(std::nullptr_t pointer, const xtd::ustring& message) {
  is_null(pointer, message, xtd::diagnostics::stack_frame::empty());
}

void assert::is_null(std::nullptr_t pointer, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  succeed(message, stack_frame);
}

void assert::is_true(bool condition) {
  is_true(condition, "", xtd::diagnostics::stack_frame::empty());
}

void assert::is_true(bool condition, const xtd::diagnostics::stack_frame& stack_frame) {
  is_true(condition, "", stack_frame);
}

void assert::is_true(bool condition, const xtd::ustring& message) {
  is_true(condition, message, xtd::diagnostics::stack_frame::empty());
}

void assert::is_true(bool condition, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (condition == true)
    succeed(message, stack_frame);
  else
    base_assert::fail("true", "false", message, stack_frame);
}

void assert::throws_any(const std::function<void()>& statement) {
  throws_any(statement, "", xtd::diagnostics::stack_frame::empty());
}

void assert::throws_any(const std::function<void()>& statement, const xtd::diagnostics::stack_frame& stack_frame) {
  throws_any(statement, "", stack_frame);
}

void assert::throws_any(const std::function<void()>& statement, const xtd::ustring& message) {
  throws_any(statement, message, xtd::diagnostics::stack_frame::empty());
}

void assert::throws_any(const std::function<void()>& statement, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    statement();
    base_assert::fail("<exception>", "<nothing>", message, stack_frame);
  } catch (const xtd::tunit::assert_error&) {
    throw;
  } catch (...) {
    succeed(message, stack_frame);
  }
}
