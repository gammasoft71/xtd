#include "../../../include/xtd/tunit/assume.h"

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::tunit;

void assume::are_equal(const char* expected, const char* actual, const string& message, const stack_frame& stack_frame) {
  try {
    assert::are_equal(expected, actual, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

#if defined(__xtd__cpp_lib_char8_t)
void assume::are_equal(const char8* expected, const char8* actual, const string& message, const stack_frame& stack_frame) {
  try {
    assert::are_equal(expected, actual, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}
#endif

void assume::are_equal(const char16* expected, const char16* actual, const string& message, const stack_frame& stack_frame) {
  try {
    assert::are_equal(expected, actual, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::are_equal(const char32* expected, const char32* actual, const string& message, const stack_frame& stack_frame) {
  try {
    assert::are_equal(expected, actual, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::are_equal(const wchar_t* expected, const wchar_t* actual, const string& message, const stack_frame& stack_frame) {
  try {
    assert::are_equal(expected, actual, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::are_equal(float expected, float actual, const string& message, const stack_frame& stack_frame) {
  try {
    assert::are_equal(expected, actual, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::are_equal(double expected, double actual, const string& message, const stack_frame& stack_frame) {
  try {
    assert::are_equal(expected, actual, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::are_equal(long double expected, long double actual, const string& message, const stack_frame& stack_frame) {
  try {
    assert::are_equal(expected, actual, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::are_equal(float expected, float actual, float tolerance, const stack_frame& stack_frame) {
  are_equal(expected, actual, tolerance, string::empty_string, stack_frame);
}

void assume::are_equal(float expected, float actual, float tolerance, const string& message, const stack_frame& stack_frame) {
  try {
    assert::are_equal(expected, actual, tolerance, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::are_equal(double expected, double actual, double tolerance, const stack_frame& stack_frame) {
  are_equal(expected, actual, tolerance, string::empty_string, stack_frame);
}

void assume::are_equal(double expected, double actual, double tolerance, const string& message, const stack_frame& stack_frame) {
  try {
    assert::are_equal(expected, actual, tolerance, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::are_equal(long double expected, long double actual, long double tolerance, const stack_frame& stack_frame) {
  are_equal(expected, actual, tolerance, string::empty_string, stack_frame);
}

void assume::are_equal(long double expected, long double actual, long double tolerance, const string& message, const stack_frame& stack_frame) {
  try {
    assert::are_equal(expected, actual, tolerance, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::are_not_equal(const char* expected, const char* actual, const string& message, const stack_frame& stack_frame) {
  try {
    assert::are_not_equal(expected, actual, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

#if defined(__xtd__cpp_lib_char8_t)
void assume::are_not_equal(const char8* expected, const char8* actual, const string& message, const stack_frame& stack_frame) {
  try {
    assert::are_not_equal(expected, actual, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}
#endif

void assume::are_not_equal(const char16* expected, const char16* actual, const string& message, const stack_frame& stack_frame) {
  try {
    assert::are_not_equal(expected, actual, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::are_not_equal(const char32* expected, const char32* actual, const string& message, const stack_frame& stack_frame) {
  try {
    assert::are_not_equal(expected, actual, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::are_not_equal(const wchar_t* expected, const wchar_t* actual, const string& message, const stack_frame& stack_frame) {
  try {
    assert::are_not_equal(expected, actual, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::contains(char item, const char* values, const string& message, const stack_frame& stack_frame) {
  try {
    assert::contains(item, values, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

#if defined(__xtd__cpp_lib_char8_t)
void assume::contains(char8 item, const char8* values, const string& message, const stack_frame& stack_frame) {
  try {
    assert::contains(item, values, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}
#endif

void assume::contains(char16 item, const char16* values, const string& message, const stack_frame& stack_frame) {
  try {
    assert::contains(item, values, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::contains(char32 item, const char32* values, const string& message, const stack_frame& stack_frame) {
  try {
    assert::contains(item, values, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::contains(wchar_t item, const wchar_t* values, const string& message, const stack_frame& stack_frame) {
  try {
    assert::contains(item, values, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::does_not_throw(const std::function<void()>& statement, const stack_frame& stack_frame) {
  does_not_throw(statement, string::empty_string, stack_frame);
}

void assume::does_not_throw(const std::function<void()>& statement, const string& message, const stack_frame& stack_frame) {
  try {
    assert::does_not_throw(statement, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_empty(const char* value, const string& message, const stack_frame& stack_frame) {
  try {
    assert::is_empty(value, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

#if defined(__xtd__cpp_lib_char8_t)
void assume::is_empty(const char8* value, const string& message, const stack_frame& stack_frame) {
  try {
    assert::is_empty(value, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}
#endif

void assume::is_empty(const char16* value, const string& message, const stack_frame& stack_frame) {
  try {
    assert::is_empty(value, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_empty(const char32* value, const string& message, const stack_frame& stack_frame) {
  try {
    assert::is_empty(value, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_empty(const wchar_t* value, const string& message, const stack_frame& stack_frame) {
  try {
    assert::is_empty(value, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_false(bool condition, const stack_frame& stack_frame) {
  is_false(condition, string::empty_string, stack_frame);
}

void assume::is_false(bool condition, const string& message, const stack_frame& stack_frame) {
  try {
    assert::is_false(condition, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_greater(const char* val1, const char* val2, const string& message, const stack_frame& stack_frame) {
  try {
    assert::is_greater(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

#if defined(__xtd__cpp_lib_char8_t)
void assume::is_greater(const char8* val1, const char8* val2, const string& message, const stack_frame& stack_frame) {
  try {
    assert::is_greater(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}
#endif

void assume::is_greater(const char16* val1, const char16* val2, const string& message, const stack_frame& stack_frame) {
  try {
    assert::is_greater(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_greater(const char32* val1, const char32* val2, const string& message, const stack_frame& stack_frame) {
  try {
    assert::is_greater(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_greater(const wchar_t* val1, const wchar_t* val2, const string& message, const stack_frame& stack_frame) {
  try {
    assert::is_greater(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_greater_or_equal(const char* val1, const char* val2, const string& message, const stack_frame& stack_frame) {
  try {
    assert::is_greater_or_equal(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

#if defined(__xtd__cpp_lib_char8_t)
void assume::is_greater_or_equal(const char8* val1, const char8* val2, const string& message, const stack_frame& stack_frame) {
  try {
    assert::is_greater_or_equal(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}
#endif

void assume::is_greater_or_equal(const char16* val1, const char16* val2, const string& message, const stack_frame& stack_frame) {
  try {
    assert::is_greater_or_equal(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_greater_or_equal(const char32* val1, const char32* val2, const string& message, const stack_frame& stack_frame) {
  try {
    assert::is_greater_or_equal(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_greater_or_equal(const wchar_t* val1, const wchar_t* val2, const string& message, const stack_frame& stack_frame) {
  try {
    assert::is_greater_or_equal(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_less(const char* val1, const char* val2, const string& message, const stack_frame& stack_frame) {
  try {
    assert::is_less(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

#if defined(__xtd__cpp_lib_char8_t)
void assume::is_less(const char8* val1, const char8* val2, const string& message, const stack_frame& stack_frame) {
  try {
    assert::is_less(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}
#endif

void assume::is_less(const char16* val1, const char16* val2, const string& message, const stack_frame& stack_frame) {
  try {
    assert::is_less(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_less(const char32* val1, const char32* val2, const string& message, const stack_frame& stack_frame) {
  try {
    assert::is_less(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_less(const wchar_t* val1, const wchar_t* val2, const string& message, const stack_frame& stack_frame) {
  try {
    assert::is_less(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_less_or_equal(const char* val1, const char* val2, const string& message, const stack_frame& stack_frame) {
  try {
    assert::is_less_or_equal(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

#if defined(__xtd__cpp_lib_char8_t)
void assume::is_less_or_equal(const char8* val1, const char8* val2, const string& message, const stack_frame& stack_frame) {
  try {
    assert::is_less_or_equal(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}
#endif

void assume::is_less_or_equal(const char16* val1, const char16* val2, const string& message, const stack_frame& stack_frame) {
  try {
    assert::is_less_or_equal(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_less_or_equal(const char32* val1, const char32* val2, const string& message, const stack_frame& stack_frame) {
  try {
    assert::is_less_or_equal(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_less_or_equal(const wchar_t* val1, const wchar_t* val2, const string& message, const stack_frame& stack_frame) {
  try {
    assert::is_less_or_equal(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_NaN(double value, const stack_frame& stack_frame) {
  is_NaN(value, string::empty_string, stack_frame);
}

void assume::is_NaN(double value, const string& message, const stack_frame& stack_frame) {
  try {
    assert::is_NaN(value, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_NaN(long double value, const stack_frame& stack_frame) {
  is_NaN(value, string::empty_string, stack_frame);
}

void assume::is_NaN(long double value, const string& message, const stack_frame& stack_frame) {
  try {
    assert::is_NaN(value, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_NaN(float value, const stack_frame& stack_frame) {
  is_NaN(value, string::empty_string, stack_frame);
}

void assume::is_NaN(float value, const string& message, const stack_frame& stack_frame) {
  try {
    assert::is_NaN(value, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_not_empty(const char* value, const string& message, const stack_frame& stack_frame) {
  try {
    assert::is_not_empty(value, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

#if defined(__xtd__cpp_lib_char8_t)
void assume::is_not_empty(const char8* value, const string& message, const stack_frame& stack_frame) {
  try {
    assert::is_not_empty(value, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}
#endif

void assume::is_not_empty(const char16* value, const string& message, const stack_frame& stack_frame) {
  try {
    assert::is_not_empty(value, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_not_empty(const char32* value, const string& message, const stack_frame& stack_frame) {
  try {
    assert::is_not_empty(value, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_not_empty(const wchar_t* value, const string& message, const stack_frame& stack_frame) {
  try {
    assert::is_not_empty(value, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_not_null(nullptr_t pointer, const stack_frame& stack_frame) {
  is_not_null(pointer, string::empty_string, stack_frame);
}

void assume::is_not_null(nullptr_t pointer, const string& message, const stack_frame& stack_frame) {
  try {
    assert::is_not_null(pointer, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_null(nullptr_t pointer, const stack_frame& stack_frame) {
  is_null(pointer, string::empty_string, stack_frame);
}

void assume::is_null(nullptr_t pointer, const string& message, const stack_frame& stack_frame) {
  assert::succeed(message, stack_frame);
}

void assume::is_true(bool condition, const stack_frame& stack_frame) {
  is_true(condition, string::empty_string, stack_frame);
}

void assume::is_true(bool condition, const string& message, const stack_frame& stack_frame) {
  try {
    assert::is_true(condition, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::throws_any(const std::function<void()>& statement, const stack_frame& stack_frame) {
  throws_any(statement, string::empty_string, stack_frame);
}

void assume::throws_any(const std::function<void()>& statement, const string& message, const stack_frame& stack_frame) {
  try {
    assert::throws_any(statement, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}
