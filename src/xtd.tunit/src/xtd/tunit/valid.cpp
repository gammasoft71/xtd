#include "../../../include/xtd/tunit/valid"

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

void valid::are_equal(const char* expected, const char* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::are_equal(expected, actual, message, stack_frame);
  } catch (...) {
    error();
  }
}

#if defined(__cpp_lib_char8_t)
void valid::are_equal(const char8* expected, const char8* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::are_equal(expected, actual, message, stack_frame);
  } catch (...) {
    error();
  }
}
#endif

void valid::are_equal(const char16* expected, const char16* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::are_equal(expected, actual, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::are_equal(const char32* expected, const char32* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::are_equal(expected, actual, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::are_equal(const wchar_t* expected, const wchar_t* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::are_equal(expected, actual, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::are_equal(float expected, float actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::are_equal(expected, actual, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::are_equal(double expected, double actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::are_equal(expected, actual, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::are_equal(long double expected, long double actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::are_equal(expected, actual, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::are_equal(float expected, float actual, float tolerance) {
  are_equal(expected, actual, tolerance, "", xtd::diagnostics::stack_frame::empty());
}

void valid::are_equal(float expected, float actual, float tolerance, const xtd::diagnostics::stack_frame& stack_frame) {
  are_equal(expected, actual, tolerance, "", stack_frame);
}

void valid::are_equal(float expected, float& actual, float tolerance, const xtd::ustring& message) {
  are_equal(expected, actual, tolerance, message, xtd::diagnostics::stack_frame::empty());
}

void valid::are_equal(float expected, float actual, float tolerance, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::are_equal(expected, actual, tolerance, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::are_equal(double expected, double actual, double tolerance) {
  are_equal(expected, actual, tolerance, "", xtd::diagnostics::stack_frame::empty());
}

void valid::are_equal(double expected, double actual, double tolerance, const xtd::diagnostics::stack_frame& stack_frame) {
  are_equal(expected, actual, tolerance, "", stack_frame);
}

void valid::are_equal(double expected, double actual, double tolerance, const xtd::ustring& message) {
  are_equal(expected, actual, tolerance, message, xtd::diagnostics::stack_frame::empty());
}

void valid::are_equal(double expected, double actual, double tolerance, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::are_equal(expected, actual, tolerance, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::are_equal(long double expected, long double actual, long double tolerance) {
  are_equal(expected, actual, tolerance, "", xtd::diagnostics::stack_frame::empty());
}

void valid::are_equal(long double expected, long double actual, long double tolerance, const xtd::diagnostics::stack_frame& stack_frame) {
  are_equal(expected, actual, tolerance, "", stack_frame);
}

void valid::are_equal(long double expected, long double actual, long double tolerance, const xtd::ustring& message) {
  are_equal(expected, actual, tolerance, message, xtd::diagnostics::stack_frame::empty());
}

void valid::are_equal(long double expected, long double actual, long double tolerance, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::are_equal(expected, actual, tolerance, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::are_not_equal(const char* expected, const char* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::are_not_equal(expected, actual, message, stack_frame);
  } catch (...) {
    error();
  }
}

#if defined(__cpp_lib_char8_t)
void valid::are_not_equal(const char8* expected, const char8* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::are_not_equal(expected, actual, message, stack_frame);
  } catch (...) {
    error();
  }
}
#endif

void valid::are_not_equal(const char16* expected, const char16* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::are_not_equal(expected, actual, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::are_not_equal(const char32* expected, const char32* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::are_not_equal(expected, actual, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::are_not_equal(const wchar_t* expected, const wchar_t* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::are_not_equal(expected, actual, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::contains(char item, const char* values, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::contains(item, values, message, stack_frame);
  } catch (...) {
    error();
  }
}

#if defined(__cpp_lib_char8_t)
void valid::contains(char8 item, const char8* values, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::contains(item, values, message, stack_frame);
  } catch (...) {
    error();
  }
}
#endif

void valid::contains(char16 item, const char16* values, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::contains(item, values, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::contains(char32 item, const char32* values, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::contains(item, values, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::contains(wchar_t item, const wchar_t* values, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::contains(item, values, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::does_not_throw(const std::function<void()>& statement) {
  does_not_throw(statement, "", xtd::diagnostics::stack_frame::empty());
}

void valid::does_not_throw(const std::function<void()>& statement, const xtd::diagnostics::stack_frame& stack_frame) {
  does_not_throw(statement, "", stack_frame);
}

void valid::does_not_throw(const std::function<void()>& statement, const xtd::ustring& message) {
  does_not_throw(statement, message, xtd::diagnostics::stack_frame::empty());
}

void valid::does_not_throw(const std::function<void()>& statement, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::does_not_throw(statement, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::is_empty(const char* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::is_empty(value, message, stack_frame);
  } catch (...) {
    error();
  }
}

#if defined(__cpp_lib_char8_t)
void valid::is_empty(const char8* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::is_empty(value, message, stack_frame);
  } catch (...) {
    error();
  }
}
#endif

void valid::is_empty(const char16* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::is_empty(value, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::is_empty(const char32* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::is_empty(value, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::is_empty(const wchar_t* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::is_empty(value, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::is_false(bool condition) {
  is_false(condition, "", xtd::diagnostics::stack_frame::empty());
}

void valid::is_false(bool condition, const xtd::diagnostics::stack_frame& stack_frame) {
  is_false(condition, "", stack_frame);
}

void valid::is_false(bool condition, const xtd::ustring& message) {
  is_false(condition, message, xtd::diagnostics::stack_frame::empty());
}

void valid::is_false(bool condition, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::is_false(condition, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::is_greater(const char* val1, const char* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::is_greater(val1, val2, message, stack_frame);
  } catch (...) {
    error();
  }
}

#if defined(__cpp_lib_char8_t)
void valid::is_greater(const char8* val1, const char8* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::is_greater(val1, val2, message, stack_frame);
  } catch (...) {
    error();
  }
}
#endif

void valid::is_greater(const char16* val1, const char16* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::is_greater(val1, val2, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::is_greater(const char32* val1, const char32* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::is_greater(val1, val2, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::is_greater(const wchar_t* val1, const wchar_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::is_greater(val1, val2, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::is_greater_or_equal(const char* val1, const char* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::is_greater_or_equal(val1, val2, message, stack_frame);
  } catch (...) {
    error();
  }
}

#if defined(__cpp_lib_char8_t)
void valid::is_greater_or_equal(const char8* val1, const char8* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::is_greater_or_equal(val1, val2, message, stack_frame);
  } catch (...) {
    error();
  }
}
#endif

void valid::is_greater_or_equal(const char16* val1, const char16* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::is_greater_or_equal(val1, val2, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::is_greater_or_equal(const char32* val1, const char32* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::is_greater_or_equal(val1, val2, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::is_greater_or_equal(const wchar_t* val1, const wchar_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::is_greater_or_equal(val1, val2, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::is_less(const char* val1, const char* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::is_less(val1, val2, message, stack_frame);
  } catch (...) {
    error();
  }
}

#if defined(__cpp_lib_char8_t)
void valid::is_less(const char8* val1, const char8* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::is_less(val1, val2, message, stack_frame);
  } catch (...) {
    error();
  }
}
#endif

void valid::is_less(const char16* val1, const char16* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::is_less(val1, val2, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::is_less(const char32* val1, const char32* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::is_less(val1, val2, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::is_less(const wchar_t* val1, const wchar_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::is_less(val1, val2, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::is_less_or_equal(const char* val1, const char* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::is_less_or_equal(val1, val2, message, stack_frame);
  } catch (...) {
    error();
  }
}

#if defined(__cpp_lib_char8_t)
void valid::is_less_or_equal(const char8* val1, const char8* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::is_less_or_equal(val1, val2, message, stack_frame);
  } catch (...) {
    error();
  }
}
#endif

void valid::is_less_or_equal(const char16* val1, const char16* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::is_less_or_equal(val1, val2, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::is_less_or_equal(const char32* val1, const char32* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::is_less_or_equal(val1, val2, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::is_less_or_equal(const wchar_t* val1, const wchar_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::is_less_or_equal(val1, val2, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::is_NaN(double value) {
  is_NaN(value, "", xtd::diagnostics::stack_frame::empty());
}

void valid::is_NaN(double value, const xtd::diagnostics::stack_frame& stack_frame) {
  is_NaN(value, "", stack_frame);
}

void valid::is_NaN(double value, const xtd::ustring& message) {
  is_NaN(value, message, xtd::diagnostics::stack_frame::empty());
}

void valid::is_NaN(double value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::is_NaN(value, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::is_NaN(long double value) {
  is_NaN(value, "", xtd::diagnostics::stack_frame::empty());
}

void valid::is_NaN(long double value, const xtd::diagnostics::stack_frame& stack_frame) {
  is_NaN(value, "", stack_frame);
}

void valid::is_NaN(long double value, const xtd::ustring& message) {
  is_NaN(value, message, xtd::diagnostics::stack_frame::empty());
}

void valid::is_NaN(long double value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::is_NaN(value, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::is_NaN(float value) {
  is_NaN(value, "", xtd::diagnostics::stack_frame::empty());
}

void valid::is_NaN(float value, const xtd::diagnostics::stack_frame& stack_frame) {
  is_NaN(value, "", stack_frame);
}

void valid::is_NaN(float value, const xtd::ustring& message) {
  is_NaN(value, message, xtd::diagnostics::stack_frame::empty());
}

void valid::is_NaN(float value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::is_NaN(value, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::is_not_empty(const char* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::is_not_empty(value, message, stack_frame);
  } catch (...) {
    error();
  }
}

#if defined(__cpp_lib_char8_t)
void valid::is_not_empty(const char8* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::is_not_empty(value, message, stack_frame);
  } catch (...) {
    error();
  }
}
#endif

void valid::is_not_empty(const char16* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::is_not_empty(value, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::is_not_empty(const char32* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::is_not_empty(value, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::is_not_empty(const wchar_t* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::is_not_empty(value, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::is_not_null(std::nullptr_t pointer) {
  is_not_null(pointer, "", xtd::diagnostics::stack_frame::empty());
}

void valid::is_not_null(std::nullptr_t pointer, const xtd::diagnostics::stack_frame& stack_frame) {
  is_not_null(pointer, "", stack_frame);
}

void valid::is_not_null(std::nullptr_t pointer, const xtd::ustring& message) {
  is_not_null(pointer, message, xtd::diagnostics::stack_frame::empty());
}

void valid::is_not_null(std::nullptr_t pointer, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::is_not_null(pointer, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::is_null(std::nullptr_t pointer) {
  is_null(pointer, "", xtd::diagnostics::stack_frame::empty());
}

void valid::is_null(std::nullptr_t pointer, const xtd::diagnostics::stack_frame& stack_frame) {
  is_null(pointer, "", stack_frame);
}

void valid::is_null(std::nullptr_t pointer, const xtd::ustring& message) {
  is_null(pointer, message, xtd::diagnostics::stack_frame::empty());
}

void valid::is_null(std::nullptr_t pointer, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  assert::succeed(message, stack_frame);
}

void valid::is_true(bool condition) {
  is_true(condition, "", xtd::diagnostics::stack_frame::empty());
}

void valid::is_true(bool condition, const xtd::diagnostics::stack_frame& stack_frame) {
  is_true(condition, "", stack_frame);
}

void valid::is_true(bool condition, const xtd::ustring& message) {
  is_true(condition, message, xtd::diagnostics::stack_frame::empty());
}

void valid::is_true(bool condition, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::is_true(condition, message, stack_frame);
  } catch (...) {
    error();
  }
}

void valid::throws_any(const std::function<void()>& statement) {
  throws_any(statement, "", xtd::diagnostics::stack_frame::empty());
}

void valid::throws_any(const std::function<void()>& statement, const xtd::diagnostics::stack_frame& stack_frame) {
  throws_any(statement, "", stack_frame);
}

void valid::throws_any(const std::function<void()>& statement, const xtd::ustring& message) {
  throws_any(statement, message, xtd::diagnostics::stack_frame::empty());
}

void valid::throws_any(const std::function<void()>& statement, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
  try {
    assert::throws_any(statement, message, stack_frame);
  } catch (...) {
    error();
  }
}
