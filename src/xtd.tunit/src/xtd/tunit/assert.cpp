#include "../../../include/xtd/tunit/assert.h"
#include <cstring>

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::tunit;

void assert::are_equal(const char* expected, const char* actual, const ustring& message, const stack_frame& stack_frame) {
  if (strcmp(actual, expected) == 0)
    succeed(message, stack_frame);
  else
    fail(to_string(expected), to_string(actual), message, stack_frame);
}

#if defined(__cpp_lib_char8_t)
void assert::are_equal(const char8* expected, const char8* actual, const ustring& message, const stack_frame& stack_frame) {
  if (ustring {actual} == ustring {expected})
    succeed(message, stack_frame);
  else
    fail(to_string(expected), to_string(actual), message, stack_frame);
}
#endif

void assert::are_equal(const char16* expected, const char16* actual, const ustring& message, const stack_frame& stack_frame) {
  if (u16string {actual} == u16string {expected})
    succeed(message, stack_frame);
  else
    fail(to_string(expected), to_string(actual), message, stack_frame);
}

void assert::are_equal(const char32* expected, const char32* actual, const ustring& message, const stack_frame& stack_frame) {
  if (u32string {actual} == u32string {expected})
    succeed(message, stack_frame);
  else
    fail(to_string(expected), to_string(actual), message, stack_frame);
}

void assert::are_equal(const wchar_t* expected, const wchar_t* actual, const ustring& message, const stack_frame& stack_frame) {
  if (wcscmp(actual, expected) == 0)
    succeed(message, stack_frame);
  else
    fail(to_string(expected), to_string(actual), message, stack_frame);
}

void assert::are_equal(float expected, float actual, const ustring& message, const stack_frame& stack_frame) {
  if (isnan(actual) && isnan(expected))
    succeed(message, stack_frame);
  else if (actual == expected)
    succeed(message, stack_frame);
  else
    fail(to_string(expected), to_string(actual), message, stack_frame);
}

void assert::are_equal(double expected, double actual, const ustring& message, const stack_frame& stack_frame) {
  if (isnan(actual) && isnan(expected))
    succeed(message, stack_frame);
  else if (actual == expected)
    succeed(message, stack_frame);
  else
    fail(to_string(expected), to_string(actual), message, stack_frame);
}

void assert::are_equal(long double expected, long double actual, const ustring& message, const stack_frame& stack_frame) {
  if (isnan(actual) && isnan(expected))
    succeed(message, stack_frame);
  else if (actual == expected)
    succeed(message, stack_frame);
  else
    fail(to_string(expected), to_string(actual), message, stack_frame);
}

void assert::are_equal(float expected, float actual, float tolerance) {
  are_equal(expected, actual, tolerance, ustring::empty_string, stack_frame::empty());
}

void assert::are_equal(float expected, float actual, float tolerance, const stack_frame& stack_frame) {
  are_equal(expected, actual, tolerance, ustring::empty_string, stack_frame);
}

void assert::are_equal(float expected, float& actual, float tolerance, const ustring& message) {
  are_equal(expected, actual, tolerance, message, stack_frame::empty());
}

void assert::are_equal(float expected, float actual, float tolerance, const ustring& message, const stack_frame& stack_frame) {
  if (fabsf(expected - actual) <= fabsf(tolerance))
    succeed(message, stack_frame);
  else
    fail(to_string(expected), to_string(actual), message, stack_frame);
}

void assert::are_equal(double expected, double actual, double tolerance) {
  are_equal(expected, actual, tolerance, ustring::empty_string, stack_frame::empty());
}

void assert::are_equal(double expected, double actual, double tolerance, const stack_frame& stack_frame) {
  are_equal(expected, actual, tolerance, ustring::empty_string, stack_frame);
}

void assert::are_equal(double expected, double actual, double tolerance, const ustring& message) {
  are_equal(expected, actual, tolerance, message, stack_frame::empty());
}

void assert::are_equal(double expected, double actual, double tolerance, const ustring& message, const stack_frame& stack_frame) {
  if (fabs(expected - actual) <= fabs(tolerance))
    succeed(message, stack_frame);
  else
    fail(to_string(expected), to_string(actual), message, stack_frame);
}

void assert::are_equal(long double expected, long double actual, long double tolerance) {
  are_equal(expected, actual, tolerance, ustring::empty_string, stack_frame::empty());
}

void assert::are_equal(long double expected, long double actual, long double tolerance, const stack_frame& stack_frame) {
  are_equal(expected, actual, tolerance, ustring::empty_string, stack_frame);
}

void assert::are_equal(long double expected, long double actual, long double tolerance, const ustring& message) {
  are_equal(expected, actual, tolerance, message, stack_frame::empty());
}

void assert::are_equal(long double expected, long double actual, long double tolerance, const ustring& message, const stack_frame& stack_frame) {
  if (fabsl(expected - actual) <= fabsl(tolerance))
    succeed(message, stack_frame);
  else
    fail(to_string(expected), to_string(actual), message, stack_frame);
}

void assert::are_not_equal(const char* expected, const char* actual, const ustring& message, const stack_frame& stack_frame) {
  if (strcmp(actual, expected) != 0)
    succeed(message, stack_frame);
  else
    fail("not " + to_string(expected), to_string(actual), message, stack_frame);
}

#if defined(__cpp_lib_char8_t)
void assert::are_not_equal(const char8* expected, const char8* actual, const ustring& message, const stack_frame& stack_frame) {
  if (ustring {actual} != ustring {expected})
    succeed(message, stack_frame);
  else
    fail("not " + to_string(expected), to_string(actual), message, stack_frame);
}
#endif

void assert::are_not_equal(const char16* expected, const char16* actual, const ustring& message, const stack_frame& stack_frame) {
  if (u16string {actual} != u16string {expected})
    succeed(message, stack_frame);
  else
    fail("not " + to_string(expected), to_string(actual), message, stack_frame);
}

void assert::are_not_equal(const char32* expected, const char32* actual, const ustring& message, const stack_frame& stack_frame) {
  if (u32string {actual} != u32string {expected})
    succeed(message, stack_frame);
  else
    fail("not " + to_string(expected), to_string(actual), message, stack_frame);
}

void assert::are_not_equal(const wchar_t* expected, const wchar_t* actual, const ustring& message, const stack_frame& stack_frame) {
  if (wcscmp(actual, expected) != 0)
    succeed(message, stack_frame);
  else
    fail("not " + to_string(expected), to_string(actual), message, stack_frame);
}

void assert::contains(char item, const char* values, const ustring& message, const stack_frame& stack_frame) {
  auto s = ustring {values};
  auto result = find(s.begin(), s.end(), item);
  if (result != s.end())
    succeed(message, stack_frame);
  else
    fail("collection containing " + to_string(item), join_items(s), message, stack_frame);
}

#if defined(__cpp_lib_char8_t)
void assert::contains(char8 item, const char8* values, const ustring& message, const stack_frame& stack_frame) {
  auto s = u8string {values};
  auto result = find(s.begin(), s.end(), item);
  if (result != s.end())
    succeed(message, stack_frame);
  else
    fail("collection containing " + to_string(item), join_items(s), message, stack_frame);
}
#endif

void assert::contains(char16 item, const char16* values, const ustring& message, const stack_frame& stack_frame) {
  auto s = u16string {values};
  auto result = find(s.begin(), s.end(), item);
  if (result != s.end())
    succeed(message, stack_frame);
  else
    fail("collection containing " + to_string(item), join_items(s), message, stack_frame);
}

void assert::contains(char32 item, const char32* values, const ustring& message, const stack_frame& stack_frame) {
  auto s = u32string {values};
  auto result = find(s.begin(), s.end(), item);
  if (result != s.end())
    succeed(message, stack_frame);
  else
    fail("collection containing " + to_string(item), join_items(s), message, stack_frame);
}

void assert::contains(wchar_t item, const wchar_t* values, const ustring& message, const stack_frame& stack_frame) {
  auto s = wstring {values};
  auto result = find(s.begin(), s.end(), item);
  if (result != s.end())
    succeed(message, stack_frame);
  else
    fail("collection containing " + to_string(item), join_items(s), message, stack_frame);
}

void assert::does_not_throw(const function<void()>& statement) {
  does_not_throw(statement, ustring::empty_string, stack_frame::empty());
}

void assert::does_not_throw(const function<void()>& statement, const stack_frame& stack_frame) {
  does_not_throw(statement, ustring::empty_string, stack_frame);
}

void assert::does_not_throw(const function<void()>& statement, const ustring& message) {
  does_not_throw(statement, message, stack_frame::empty());
}

void assert::does_not_throw(const function<void()>& statement, const ustring& message, const stack_frame& stack_frame) {
  try {
    statement();
    succeed(message, stack_frame);
  } catch (const exception& e) {
    fail("No Exception to be thrown", "<" + typeof_(e).full_name() + ">", message, stack_frame);
  } catch (...) {
    fail("No Exception to be thrown", "<exception>", message, stack_frame);
  }
}

void assert::is_empty(const char* value, const ustring& message, const stack_frame& stack_frame) {
  auto s = ustring {value};
  if (ustring::is_empty(s))
    succeed(message, stack_frame);
  else
    fail("collection <empty>", join_items(s), message, stack_frame);
}

#if defined(__cpp_lib_char8_t)
void assert::is_empty(const char8* value, const ustring& message, const stack_frame& stack_frame) {
  auto s = ustring {value};
  if (ustring::is_empty(s))
    succeed(message, stack_frame);
  else
    fail("collection <empty>", join_items(s), message, stack_frame);
}
#endif

void assert::is_empty(const char16* value, const ustring& message, const stack_frame& stack_frame) {
  auto s = ustring {value};
  if (ustring::is_empty(s))
    succeed(message, stack_frame);
  else
    fail("collection <empty>", join_items(s), message, stack_frame);
}

void assert::is_empty(const char32* value, const ustring& message, const stack_frame& stack_frame) {
  auto s = ustring {value};
  if (ustring::is_empty(s))
    succeed(message, stack_frame);
  else
    fail("collection <empty>", join_items(s), message, stack_frame);
}

void assert::is_empty(const wchar_t* value, const ustring& message, const stack_frame& stack_frame) {
  auto s = ustring {value};
  if (ustring::is_empty(s))
    succeed(message, stack_frame);
  else
    fail("collection <empty>", join_items(s), message, stack_frame);
}

void assert::is_false(bool condition) {
  is_false(condition, ustring::empty_string, stack_frame::empty());
}

void assert::is_false(bool condition, const stack_frame& stack_frame) {
  is_false(condition, ustring::empty_string, stack_frame);
}

void assert::is_false(bool condition, const ustring& message) {
  is_false(condition, message, stack_frame::empty());
}

void assert::is_false(bool condition, const ustring& message, const stack_frame& stack_frame) {
  if (condition == false)
    succeed(message, stack_frame);
  else
    fail("false", "true", message, stack_frame);
}

void assert::is_greater(const char* val1, const char* val2, const ustring& message, const stack_frame& stack_frame) {
  if (strcmp(val1, val2) > 0)
    succeed(message, stack_frame);
  else
    fail("greater than " + to_string(val2), to_string(val1), message, stack_frame);
}

#if defined(__cpp_lib_char8_t)
void assert::is_greater(const char8* val1, const char8* val2, const ustring& message, const stack_frame& stack_frame) {
  if (ustring {val1} > ustring {val2})
    succeed(message, stack_frame);
  else
    fail("greater than " + to_string(val2), to_string(val1), message, stack_frame);
}
#endif

void assert::is_greater(const char16* val1, const char16* val2, const ustring& message, const stack_frame& stack_frame) {
  if (u16string {val1} > u16string {val2})
    succeed(message, stack_frame);
  else
    fail("greater than " + to_string(val2), to_string(val1), message, stack_frame);
}

void assert::is_greater(const char32* val1, const char32* val2, const ustring& message, const stack_frame& stack_frame) {
  if (u32string {val1} > u32string {val2})
    succeed(message, stack_frame);
  else
    fail("greater than " + to_string(val2), to_string(val1), message, stack_frame);
}

void assert::is_greater(const wchar_t* val1, const wchar_t* val2, const ustring& message, const stack_frame& stack_frame) {
  if (wcscmp(val1, val2) > 0)
    succeed(message, stack_frame);
  else
    fail("greater than " + to_string(val2), to_string(val1), message, stack_frame);
}

void assert::is_greater_or_equal(const char* val1, const char* val2, const ustring& message, const stack_frame& stack_frame) {
  if (strcmp(val1, val2) >= 0)
    succeed(message, stack_frame);
  else
    fail("greater than or equal to " + to_string(val2), to_string(val1), message, stack_frame);
}

#if defined(__cpp_lib_char8_t)
void assert::is_greater_or_equal(const char8* val1, const char8* val2, const ustring& message, const stack_frame& stack_frame) {
  if (ustring {val1} >= ustring {val2})
    succeed(message, stack_frame);
  else
    fail("greater than " + to_string(val2), to_string(val1), message, stack_frame);
}
#endif

void assert::is_greater_or_equal(const char16* val1, const char16* val2, const ustring& message, const stack_frame& stack_frame) {
  if (u16string {val1} >= u16string {val2})
    succeed(message, stack_frame);
  else
    fail("greater than " + to_string(val2), to_string(val1), message, stack_frame);
}

void assert::is_greater_or_equal(const char32* val1, const char32* val2, const ustring& message, const stack_frame& stack_frame) {
  if (u32string {val1} >= u32string {val2})
    succeed(message, stack_frame);
  else
    fail("greater than " + to_string(val2), to_string(val1), message, stack_frame);
}

void assert::is_greater_or_equal(const wchar_t* val1, const wchar_t* val2, const ustring& message, const stack_frame& stack_frame) {
  if (wcscmp(val1, val2) >= 0)
    succeed(message, stack_frame);
  else
    fail("greater than or equal to " + to_string(val2), to_string(val1), message, stack_frame);
}

void assert::is_less(const char* val1, const char* val2, const ustring& message, const stack_frame& stack_frame) {
  if (strcmp(val1, val2) < 0)
    succeed(message, stack_frame);
  else
    fail("less than " + to_string(val2), to_string(val1), message, stack_frame);
}

#if defined(__cpp_lib_char8_t)
void assert::is_less(const char8* val1, const char8* val2, const ustring& message, const stack_frame& stack_frame) {
  if (ustring {val1} < ustring {val2})
    succeed(message, stack_frame);
  else
    fail("greater than " + to_string(val2), to_string(val1), message, stack_frame);
}
#endif

void assert::is_less(const char16* val1, const char16* val2, const ustring& message, const stack_frame& stack_frame) {
  if (u16string {val1} < u16string {val2})
    succeed(message, stack_frame);
  else
    fail("greater than " + to_string(val2), to_string(val1), message, stack_frame);
}

void assert::is_less(const char32* val1, const char32* val2, const ustring& message, const stack_frame& stack_frame) {
  if (u32string {val1} < u32string {val2})
    succeed(message, stack_frame);
  else
    fail("greater than " + to_string(val2), to_string(val1), message, stack_frame);
}

void assert::is_less(const wchar_t* val1, const wchar_t* val2, const ustring& message, const stack_frame& stack_frame) {
  if (wcscmp(val1, val2) < 0)
    succeed(message, stack_frame);
  else
    fail("less than " + to_string(val2), to_string(val1), message, stack_frame);
}

void assert::is_less_or_equal(const char* val1, const char* val2, const ustring& message, const stack_frame& stack_frame) {
  if (strcmp(val1, val2) <= 0)
    succeed(message, stack_frame);
  else
    fail("less than or equal to " + to_string(val2), to_string(val1), message, stack_frame);
}

#if defined(__cpp_lib_char8_t)
void assert::is_less_or_equal(const char8* val1, const char8* val2, const ustring& message, const stack_frame& stack_frame) {
  if (ustring {val1} <= ustring {val2})
    succeed(message, stack_frame);
  else
    fail("greater than " + to_string(val2), to_string(val1), message, stack_frame);
}
#endif

void assert::is_less_or_equal(const char16* val1, const char16* val2, const ustring& message, const stack_frame& stack_frame) {
  if (u16string {val1} <= u16string {val2})
    succeed(message, stack_frame);
  else
    fail("greater than " + to_string(val2), to_string(val1), message, stack_frame);
}

void assert::is_less_or_equal(const char32* val1, const char32* val2, const ustring& message, const stack_frame& stack_frame) {
  if (u32string {val1} <= u32string {val2})
    succeed(message, stack_frame);
  else
    fail("greater than " + to_string(val2), to_string(val1), message, stack_frame);
}

void assert::is_less_or_equal(const wchar_t* val1, const wchar_t* val2, const ustring& message, const stack_frame& stack_frame) {
  if (wcscmp(val1, val2) <= 0)
    succeed(message, stack_frame);
  else
    fail("less than or equal to " + to_string(val2), to_string(val1), message, stack_frame);
}

void assert::is_NaN(double value) {
  is_NaN(value, ustring::empty_string, stack_frame::empty());
}

void assert::is_NaN(double value, const stack_frame& stack_frame) {
  is_NaN(value, ustring::empty_string, stack_frame);
}

void assert::is_NaN(double value, const ustring& message) {
  is_NaN(value, message, stack_frame::empty());
}

void assert::is_NaN(double value, const ustring& message, const stack_frame& stack_frame) {
  if (isnan(value))
    succeed(message, stack_frame);
  else
    fail("NaN", to_string(value), message, stack_frame);
}

void assert::is_NaN(long double value) {
  is_NaN(value, ustring::empty_string, stack_frame::empty());
}

void assert::is_NaN(long double value, const stack_frame& stack_frame) {
  is_NaN(value, ustring::empty_string, stack_frame);
}

void assert::is_NaN(long double value, const ustring& message) {
  is_NaN(value, message, stack_frame::empty());
}

void assert::is_NaN(long double value, const ustring& message, const stack_frame& stack_frame) {
  if (isnan(value))
    succeed(message, stack_frame);
  else
    fail("NaN", to_string(value), message, stack_frame);
}

void assert::is_NaN(float value) {
  is_NaN(value, ustring::empty_string, stack_frame::empty());
}

void assert::is_NaN(float value, const stack_frame& stack_frame) {
  is_NaN(value, ustring::empty_string, stack_frame);
}

void assert::is_NaN(float value, const ustring& message) {
  is_NaN(value, message, stack_frame::empty());
}

void assert::is_NaN(float value, const ustring& message, const stack_frame& stack_frame) {
  if (isnan(value))
    succeed(message, stack_frame);
  else
    fail("NaN", to_string(value), message, stack_frame);
}

void assert::is_not_empty(const char* value, const ustring& message, const stack_frame& stack_frame) {
  if (!ustring::is_empty(ustring(value)))
    succeed(message, stack_frame);
  else
    fail("collection not <empty>", "<empty>", message, stack_frame);
}

#if defined(__cpp_lib_char8_t)
void assert::is_not_empty(const char8* value, const ustring& message, const stack_frame& stack_frame) {
  if (!ustring::is_empty(ustring(value)))
    succeed(message, stack_frame);
  else
    fail("collection not <empty>", "<empty>", message, stack_frame);
}
#endif

void assert::is_not_empty(const char16* value, const ustring& message, const stack_frame& stack_frame) {
  if (!ustring::is_empty(ustring(value)))
    succeed(message, stack_frame);
  else
    fail("collection not <empty>", "<empty>", message, stack_frame);
}

void assert::is_not_empty(const char32* value, const ustring& message, const stack_frame& stack_frame) {
  if (!ustring::is_empty(ustring(value)))
    succeed(message, stack_frame);
  else
    fail("collection not <empty>", "<empty>", message, stack_frame);
}

void assert::is_not_empty(const wchar_t* value, const ustring& message, const stack_frame& stack_frame) {
  if (!ustring::is_empty(ustring(value)))
    succeed(message, stack_frame);
  else
    fail("collection not <empty>", "<empty>", message, stack_frame);
}

void assert::is_not_null(nullptr_t pointer) {
  is_not_null(pointer, ustring::empty_string, stack_frame::empty());
}

void assert::is_not_null(nullptr_t pointer, const stack_frame& stack_frame) {
  is_not_null(pointer, ustring::empty_string, stack_frame);
}

void assert::is_not_null(nullptr_t pointer, const ustring& message) {
  is_not_null(pointer, message, stack_frame::empty());
}

void assert::is_not_null(nullptr_t pointer, const ustring& message, const stack_frame& stack_frame) {
  fail("not null", "null", message, stack_frame);
}

void assert::is_null(nullptr_t pointer) {
  is_null(pointer, ustring::empty_string, stack_frame::empty());
}

void assert::is_null(nullptr_t pointer, const stack_frame& stack_frame) {
  is_null(pointer, ustring::empty_string, stack_frame);
}

void assert::is_null(nullptr_t pointer, const ustring& message) {
  is_null(pointer, message, stack_frame::empty());
}

void assert::is_null(nullptr_t pointer, const ustring& message, const stack_frame& stack_frame) {
  succeed(message, stack_frame);
}

void assert::is_true(bool condition) {
  is_true(condition, ustring::empty_string, stack_frame::empty());
}

void assert::is_true(bool condition, const stack_frame& stack_frame) {
  is_true(condition, ustring::empty_string, stack_frame);
}

void assert::is_true(bool condition, const ustring& message) {
  is_true(condition, message, stack_frame::empty());
}

void assert::is_true(bool condition, const ustring& message, const stack_frame& stack_frame) {
  if (condition == true)
    succeed(message, stack_frame);
  else
    fail("true", "false", message, stack_frame);
}

void assert::throws_any(const function<void()>& statement) {
  throws_any(statement, ustring::empty_string, stack_frame::empty());
}

void assert::throws_any(const function<void()>& statement, const stack_frame& stack_frame) {
  throws_any(statement, ustring::empty_string, stack_frame);
}

void assert::throws_any(const function<void()>& statement, const ustring& message) {
  throws_any(statement, message, stack_frame::empty());
}

void assert::throws_any(const function<void()>& statement, const ustring& message, const stack_frame& stack_frame) {
  try {
    statement();
    fail("<exception>", "<nothing>", message, stack_frame);
  } catch (const assert_error&) {
    throw;
  } catch (...) {
    succeed(message, stack_frame);
  }
}
