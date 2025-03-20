#include "../../../include/xtd/tunit/assert.hpp"
#include <xtd/string>
#include <xtd/u16string>
#include <xtd/u32string>
#include <xtd/u8string>
#include <xtd/wstring>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::tunit;

void assert::are_equal(const char* expected, const char* actual, const string& message, const stack_frame& stack_frame) {
  if (equals(string {expected}, string {actual})) succeed(message, stack_frame);
  else fail(to_string(expected), to_string(actual), message, stack_frame);
}

#if defined(__xtd__cpp_lib_char8_t)
void assert::are_equal(const char8* expected, const char8* actual, const string& message, const stack_frame& stack_frame) {
  if (equals(string {expected}, string {actual})) succeed(message, stack_frame);
  else fail(to_string(expected), to_string(actual), message, stack_frame);
}
#endif

void assert::are_equal(const char16* expected, const char16* actual, const string& message, const stack_frame& stack_frame) {
  if (equals(string {expected}, string {actual})) succeed(message, stack_frame);
  else fail(to_string(expected), to_string(actual), message, stack_frame);
}

void assert::are_equal(const char32* expected, const char32* actual, const string& message, const stack_frame& stack_frame) {
  if (equals(string {expected}, string {actual})) succeed(message, stack_frame);
  else fail(to_string(expected), to_string(actual), message, stack_frame);
}

void assert::are_equal(const wchar_t* expected, const wchar_t* actual, const string& message, const stack_frame& stack_frame) {
  if (equals(string {expected}, string {actual})) succeed(message, stack_frame);
  else fail(to_string(expected), to_string(actual), message, stack_frame);
}

void assert::are_equal(float expected, float actual, const string& message, const stack_frame& stack_frame) {
  if (equals(expected, actual) || (std::isnan(actual) && std::isnan(expected))) succeed(message, stack_frame);
  else fail(to_string(expected), to_string(actual), message, stack_frame);
}

void assert::are_equal(double expected, double actual, const string& message, const stack_frame& stack_frame) {
  if (equals(expected, actual) || (std::isnan(actual) && std::isnan(expected))) succeed(message, stack_frame);
  else fail(to_string(expected), to_string(actual), message, stack_frame);
}

void assert::are_equal(long double expected, long double actual, const string& message, const stack_frame& stack_frame) {
  if (equals(expected, actual) || (std::isnan(actual) && std::isnan(expected))) succeed(message, stack_frame);
  else fail(to_string(expected), to_string(actual), message, stack_frame);
}

void assert::are_equal(float expected, float actual, float tolerance, const stack_frame& stack_frame) {
  are_equal(expected, actual, tolerance, string::empty_string, stack_frame);
}

void assert::are_equal(float expected, float actual, float tolerance, const string& message, const stack_frame& stack_frame) {
  if (equals(expected, actual, tolerance)) succeed(message, stack_frame);
  else fail(to_string(expected), to_string(actual), message, stack_frame);
}

void assert::are_equal(double expected, double actual, double tolerance, const stack_frame& stack_frame) {
  are_equal(expected, actual, tolerance, string::empty_string, stack_frame);
}

void assert::are_equal(double expected, double actual, double tolerance, const string& message, const stack_frame& stack_frame) {
  if (equals(expected, actual, tolerance)) succeed(message, stack_frame);
  else fail(to_string(expected), to_string(actual), message, stack_frame);
}

void assert::are_equal(long double expected, long double actual, long double tolerance, const stack_frame& stack_frame) {
  are_equal(expected, actual, tolerance, string::empty_string, stack_frame);
}

void assert::are_equal(long double expected, long double actual, long double tolerance, const string& message, const stack_frame& stack_frame) {
  if (equals(expected, actual, tolerance)) succeed(message, stack_frame);
  else fail(to_string(expected), to_string(actual), message, stack_frame);
}

void assert::are_not_equal(const char* expected, const char* actual, const string& message, const stack_frame& stack_frame) {
  if (!equals(string {expected}, string {actual})) succeed(message, stack_frame);
  else fail("not " + to_string(expected), to_string(actual), message, stack_frame);
}

#if defined(__xtd__cpp_lib_char8_t)
void assert::are_not_equal(const char8* expected, const char8* actual, const string& message, const stack_frame& stack_frame) {
  if (!equals(string {expected}, string {actual})) succeed(message, stack_frame);
  else fail("not " + to_string(expected), to_string(actual), message, stack_frame);
}
#endif

void assert::are_not_equal(const char16* expected, const char16* actual, const string& message, const stack_frame& stack_frame) {
  if (!equals(string {expected}, string {actual})) succeed(message, stack_frame);
  else fail("not " + to_string(expected), to_string(actual), message, stack_frame);
}

void assert::are_not_equal(const char32* expected, const char32* actual, const string& message, const stack_frame& stack_frame) {
  if (!equals(string {expected}, string {actual})) succeed(message, stack_frame);
  else fail("not " + to_string(expected), to_string(actual), message, stack_frame);
}

void assert::are_not_equal(const wchar_t* expected, const wchar_t* actual, const string& message, const stack_frame& stack_frame) {
  if (!equals(string {expected}, string {actual})) succeed(message, stack_frame);
  else fail("not " + to_string(expected), to_string(actual), message, stack_frame);
}

void assert::contains(char item, const char* values, const string& message, const stack_frame& stack_frame) {
  auto s = string {values};
  if (s.contains(item)) succeed(message, stack_frame);
  else fail("collection containing " + to_string(item), join_items(s), message, stack_frame);
}

#if defined(__xtd__cpp_lib_char8_t)
void assert::contains(char8 item, const char8* values, const string& message, const stack_frame& stack_frame) {
  auto s = u8string {values};
  if (s.contains(item)) succeed(message, stack_frame);
  else fail("collection containing " + to_string(item), join_items(s), message, stack_frame);
}
#endif

void assert::contains(char16 item, const char16* values, const string& message, const stack_frame& stack_frame) {
  auto s = u16string {values};
  if (s.contains(item)) succeed(message, stack_frame);
  else fail("collection containing " + to_string(item), join_items(s), message, stack_frame);
}

void assert::contains(char32 item, const char32* values, const string& message, const stack_frame& stack_frame) {
  auto s = u32string {values};
  if (s.contains(item)) succeed(message, stack_frame);
  else fail("collection containing " + to_string(item), join_items(s), message, stack_frame);
}

void assert::contains(wchar_t item, const wchar_t* values, const string& message, const stack_frame& stack_frame) {
  auto s = wstring {values};
  if (s.contains(item)) succeed(message, stack_frame);
  else fail("collection containing " + to_string(item), join_items(s), message, stack_frame);
}

void assert::does_not_throw(const std::function<void()>& statement, const stack_frame& stack_frame) {
  does_not_throw(statement, string::empty_string, stack_frame);
}

void assert::does_not_throw(const std::function<void()>& statement, const string& message, const stack_frame& stack_frame) {
  try {
    statement();
    succeed(message, stack_frame);
  } catch (const std::exception& e) {
    fail("No Exception to be thrown", "<" + typeof_(e).full_name() + ">", message, stack_frame);
  } catch (...) {
    fail("No Exception to be thrown", "<exception>", message, stack_frame);
  }
}

void assert::is_empty(const char* value, const string& message, const stack_frame& stack_frame) {
  auto s = string {value};
  if (string::is_empty(s)) succeed(message, stack_frame);
  else fail("collection <empty>", join_items(s), message, stack_frame);
}

#if defined(__xtd__cpp_lib_char8_t)
void assert::is_empty(const char8* value, const string& message, const stack_frame& stack_frame) {
  auto s = string {value};
  if (string::is_empty(s)) succeed(message, stack_frame);
  else fail("collection <empty>", join_items(s), message, stack_frame);
}
#endif

void assert::is_empty(const char16* value, const string& message, const stack_frame& stack_frame) {
  auto s = string {value};
  if (string::is_empty(s)) succeed(message, stack_frame);
  else fail("collection <empty>", join_items(s), message, stack_frame);
}

void assert::is_empty(const char32* value, const string& message, const stack_frame& stack_frame) {
  auto s = string {value};
  if (string::is_empty(s)) succeed(message, stack_frame);
  else fail("collection <empty>", join_items(s), message, stack_frame);
}

void assert::is_empty(const wchar_t* value, const string& message, const stack_frame& stack_frame) {
  auto s = string {value};
  if (string::is_empty(s)) succeed(message, stack_frame);
  else fail("collection <empty>", join_items(s), message, stack_frame);
}

void assert::is_false(bool condition, const stack_frame& stack_frame) {
  is_false(condition, string::empty_string, stack_frame);
}

void assert::is_false(bool condition, const string& message, const stack_frame& stack_frame) {
  if (condition == false) succeed(message, stack_frame);
  else fail("false", "true", message, stack_frame);
}

void assert::is_greater(const char* val1, const char* val2, const string& message, const stack_frame& stack_frame) {
  if (strcmp(val1, val2) > 0) succeed(message, stack_frame);
  else fail("greater than " + to_string(val2), to_string(val1), message, stack_frame);
}

#if defined(__xtd__cpp_lib_char8_t)
void assert::is_greater(const char8* val1, const char8* val2, const string& message, const stack_frame& stack_frame) {
  if (string {val1} > string {val2}) succeed(message, stack_frame);
  else fail("greater than " + to_string(val2), to_string(val1), message, stack_frame);
}
#endif

void assert::is_greater(const char16* val1, const char16* val2, const string& message, const stack_frame& stack_frame) {
  if (std::u16string {val1} > std::u16string {val2}) succeed(message, stack_frame);
  else fail("greater than " + to_string(val2), to_string(val1), message, stack_frame);
}

void assert::is_greater(const char32* val1, const char32* val2, const string& message, const stack_frame& stack_frame) {
  if (std::u32string {val1} > std::u32string {val2}) succeed(message, stack_frame);
  else fail("greater than " + to_string(val2), to_string(val1), message, stack_frame);
}

void assert::is_greater(const wchar_t* val1, const wchar_t* val2, const string& message, const stack_frame& stack_frame) {
  if (wcscmp(val1, val2) > 0) succeed(message, stack_frame);
  else fail("greater than " + to_string(val2), to_string(val1), message, stack_frame);
}

void assert::is_greater_or_equal(const char* val1, const char* val2, const string& message, const stack_frame& stack_frame) {
  if (strcmp(val1, val2) >= 0) succeed(message, stack_frame);
  else fail("greater than or equal to " + to_string(val2), to_string(val1), message, stack_frame);
}

#if defined(__xtd__cpp_lib_char8_t)
void assert::is_greater_or_equal(const char8* val1, const char8* val2, const string& message, const stack_frame& stack_frame) {
  if (string {val1} >= string {val2}) succeed(message, stack_frame);
  else fail("greater than " + to_string(val2), to_string(val1), message, stack_frame);
}
#endif

void assert::is_greater_or_equal(const char16* val1, const char16* val2, const string& message, const stack_frame& stack_frame) {
  if (std::u16string {val1} >= std::u16string {val2}) succeed(message, stack_frame);
  else fail("greater than " + to_string(val2), to_string(val1), message, stack_frame);
}

void assert::is_greater_or_equal(const char32* val1, const char32* val2, const string& message, const stack_frame& stack_frame) {
  if (std::u32string {val1} >= std::u32string {val2}) succeed(message, stack_frame);
  else fail("greater than " + to_string(val2), to_string(val1), message, stack_frame);
}

void assert::is_greater_or_equal(const wchar_t* val1, const wchar_t* val2, const string& message, const stack_frame& stack_frame) {
  if (wcscmp(val1, val2) >= 0) succeed(message, stack_frame);
  else fail("greater than or equal to " + to_string(val2), to_string(val1), message, stack_frame);
}

void assert::is_less(const char* val1, const char* val2, const string& message, const stack_frame& stack_frame) {
  if (strcmp(val1, val2) < 0) succeed(message, stack_frame);
  else fail("less than " + to_string(val2), to_string(val1), message, stack_frame);
}

#if defined(__xtd__cpp_lib_char8_t)
void assert::is_less(const char8* val1, const char8* val2, const string& message, const stack_frame& stack_frame) {
  if (string {val1} < string {val2}) succeed(message, stack_frame);
  else fail("greater than " + to_string(val2), to_string(val1), message, stack_frame);
}
#endif

void assert::is_less(const char16* val1, const char16* val2, const string& message, const stack_frame& stack_frame) {
  if (std::u16string {val1} < std::u16string {val2}) succeed(message, stack_frame);
  else fail("greater than " + to_string(val2), to_string(val1), message, stack_frame);
}

void assert::is_less(const char32* val1, const char32* val2, const string& message, const stack_frame& stack_frame) {
  if (std::u32string {val1} < std::u32string {val2}) succeed(message, stack_frame);
  else fail("greater than " + to_string(val2), to_string(val1), message, stack_frame);
}

void assert::is_less(const wchar_t* val1, const wchar_t* val2, const string& message, const stack_frame& stack_frame) {
  if (wcscmp(val1, val2) < 0) succeed(message, stack_frame);
  else fail("less than " + to_string(val2), to_string(val1), message, stack_frame);
}

void assert::is_less_or_equal(const char* val1, const char* val2, const string& message, const stack_frame& stack_frame) {
  if (strcmp(val1, val2) <= 0) succeed(message, stack_frame);
  else fail("less than or equal to " + to_string(val2), to_string(val1), message, stack_frame);
}

#if defined(__xtd__cpp_lib_char8_t)
void assert::is_less_or_equal(const char8* val1, const char8* val2, const string& message, const stack_frame& stack_frame) {
  if (string {val1} <= string {val2}) succeed(message, stack_frame);
  else fail("greater than " + to_string(val2), to_string(val1), message, stack_frame);
}
#endif

void assert::is_less_or_equal(const char16* val1, const char16* val2, const string& message, const stack_frame& stack_frame) {
  if (std::u16string {val1} <= std::u16string {val2}) succeed(message, stack_frame);
  else fail("greater than " + to_string(val2), to_string(val1), message, stack_frame);
}

void assert::is_less_or_equal(const char32* val1, const char32* val2, const string& message, const stack_frame& stack_frame) {
  if (std::u32string {val1} <= std::u32string {val2}) succeed(message, stack_frame);
  else fail("greater than " + to_string(val2), to_string(val1), message, stack_frame);
}

void assert::is_less_or_equal(const wchar_t* val1, const wchar_t* val2, const string& message, const stack_frame& stack_frame) {
  if (wcscmp(val1, val2) <= 0) succeed(message, stack_frame);
  else fail("less than or equal to " + to_string(val2), to_string(val1), message, stack_frame);
}

void assert::is_NaN(double value, const stack_frame& stack_frame) {
  is_NaN(value, string::empty_string, stack_frame);
}

void assert::is_NaN(double value, const string& message, const stack_frame& stack_frame) {
  if (std::isnan(value)) succeed(message, stack_frame);
  else fail("NaN", to_string(value), message, stack_frame);
}

void assert::is_NaN(long double value, const stack_frame& stack_frame) {
  is_NaN(value, string::empty_string, stack_frame);
}

void assert::is_NaN(long double value, const string& message, const stack_frame& stack_frame) {
  if (std::isnan(value)) succeed(message, stack_frame);
  else fail("NaN", to_string(value), message, stack_frame);
}

void assert::is_NaN(float value, const stack_frame& stack_frame) {
  is_NaN(value, string::empty_string, stack_frame);
}

void assert::is_NaN(float value, const string& message, const stack_frame& stack_frame) {
  if (std::isnan(value)) succeed(message, stack_frame);
  else fail("NaN", to_string(value), message, stack_frame);
}

void assert::is_not_empty(const char* value, const string& message, const stack_frame& stack_frame) {
  if (!string::is_empty(string(value))) succeed(message, stack_frame);
  else fail("collection not <empty>", "<empty>", message, stack_frame);
}

#if defined(__xtd__cpp_lib_char8_t)
void assert::is_not_empty(const char8* value, const string& message, const stack_frame& stack_frame) {
  if (!string::is_empty(string(value))) succeed(message, stack_frame);
  else fail("collection not <empty>", "<empty>", message, stack_frame);
}
#endif

void assert::is_not_empty(const char16* value, const string& message, const stack_frame& stack_frame) {
  if (!string::is_empty(string(value))) succeed(message, stack_frame);
  else fail("collection not <empty>", "<empty>", message, stack_frame);
}

void assert::is_not_empty(const char32* value, const string& message, const stack_frame& stack_frame) {
  if (!string::is_empty(string(value))) succeed(message, stack_frame);
  else fail("collection not <empty>", "<empty>", message, stack_frame);
}

void assert::is_not_empty(const wchar_t* value, const string& message, const stack_frame& stack_frame) {
  if (!string::is_empty(string(value))) succeed(message, stack_frame);
  else fail("collection not <empty>", "<empty>", message, stack_frame);
}

void assert::is_not_null(std::nullptr_t pointer, const stack_frame& stack_frame) {
  is_not_null(pointer, string::empty_string, stack_frame);
}

void assert::is_not_null(std::nullptr_t pointer, const string& message, const stack_frame& stack_frame) {
  fail("not null", "null", message, stack_frame);
}

void assert::is_null(std::nullptr_t pointer, const stack_frame& stack_frame) {
  is_null(pointer, string::empty_string, stack_frame);
}

void assert::is_null(std::nullptr_t pointer, const string& message, const stack_frame& stack_frame) {
  succeed(message, stack_frame);
}

void assert::is_true(bool condition, const stack_frame& stack_frame) {
  is_true(condition, string::empty_string, stack_frame);
}

void assert::is_true(bool condition, const string& message, const stack_frame& stack_frame) {
  if (condition == true) succeed(message, stack_frame);
  else fail("true", "false", message, stack_frame);
}

void assert::throws_any(const std::function<void()>& statement, const stack_frame& stack_frame) {
  throws_any(statement, string::empty_string, stack_frame);
}

void assert::throws_any(const std::function<void()>& statement, const string& message, const stack_frame& stack_frame) {
  try {
    statement();
    fail("<exception>", "<nothing>", message, stack_frame);
  } catch (const assert_error&) {
    throw;
  } catch (...) {
    succeed(message, stack_frame);
  }
}
