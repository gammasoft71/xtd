#include "../../../include/xtd/tunit/assume"

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::tunit;

void assume::are_equal(const char* expected, const char* actual, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::are_equal(expected, actual, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

#if defined(__cpp_lib_char8_t)
void assume::are_equal(const char8* expected, const char8* actual, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::are_equal(expected, actual, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}
#endif

void assume::are_equal(const char16* expected, const char16* actual, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::are_equal(expected, actual, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::are_equal(const char32* expected, const char32* actual, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::are_equal(expected, actual, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::are_equal(const wchar_t* expected, const wchar_t* actual, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::are_equal(expected, actual, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::are_equal(float expected, float actual, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::are_equal(expected, actual, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::are_equal(double expected, double actual, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::are_equal(expected, actual, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::are_equal(long double expected, long double actual, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::are_equal(expected, actual, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::are_equal(float expected, float actual, float tolerance) {
  are_equal(expected, actual, tolerance, "", stack_frame::empty());
}

void assume::are_equal(float expected, float actual, float tolerance, const stack_frame& stack_frame) {
  are_equal(expected, actual, tolerance, "", stack_frame);
}

void assume::are_equal(float expected, float& actual, float tolerance, const ustring& message) {
  are_equal(expected, actual, tolerance, message, stack_frame::empty());
}

void assume::are_equal(float expected, float actual, float tolerance, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::are_equal(expected, actual, tolerance, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::are_equal(double expected, double actual, double tolerance) {
  are_equal(expected, actual, tolerance, "", stack_frame::empty());
}

void assume::are_equal(double expected, double actual, double tolerance, const stack_frame& stack_frame) {
  are_equal(expected, actual, tolerance, "", stack_frame);
}

void assume::are_equal(double expected, double actual, double tolerance, const ustring& message) {
  are_equal(expected, actual, tolerance, message, stack_frame::empty());
}

void assume::are_equal(double expected, double actual, double tolerance, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::are_equal(expected, actual, tolerance, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::are_equal(long double expected, long double actual, long double tolerance) {
  are_equal(expected, actual, tolerance, "", stack_frame::empty());
}

void assume::are_equal(long double expected, long double actual, long double tolerance, const stack_frame& stack_frame) {
  are_equal(expected, actual, tolerance, "", stack_frame);
}

void assume::are_equal(long double expected, long double actual, long double tolerance, const ustring& message) {
  are_equal(expected, actual, tolerance, message, stack_frame::empty());
}

void assume::are_equal(long double expected, long double actual, long double tolerance, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::are_equal(expected, actual, tolerance, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::are_not_equal(const char* expected, const char* actual, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::are_not_equal(expected, actual, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

#if defined(__cpp_lib_char8_t)
void assume::are_not_equal(const char8* expected, const char8* actual, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::are_not_equal(expected, actual, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}
#endif

void assume::are_not_equal(const char16* expected, const char16* actual, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::are_not_equal(expected, actual, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::are_not_equal(const char32* expected, const char32* actual, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::are_not_equal(expected, actual, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::are_not_equal(const wchar_t* expected, const wchar_t* actual, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::are_not_equal(expected, actual, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::contains(char item, const char* values, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::contains(item, values, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

#if defined(__cpp_lib_char8_t)
void assume::contains(char8 item, const char8* values, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::contains(item, values, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}
#endif

void assume::contains(char16 item, const char16* values, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::contains(item, values, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::contains(char32 item, const char32* values, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::contains(item, values, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::contains(wchar_t item, const wchar_t* values, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::contains(item, values, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::does_not_throw(const function<void()>& statement) {
  does_not_throw(statement, "", stack_frame::empty());
}

void assume::does_not_throw(const function<void()>& statement, const stack_frame& stack_frame) {
  does_not_throw(statement, "", stack_frame);
}

void assume::does_not_throw(const function<void()>& statement, const ustring& message) {
  does_not_throw(statement, message, stack_frame::empty());
}

void assume::does_not_throw(const function<void()>& statement, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::does_not_throw(statement, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_empty(const char* value, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::is_empty(value, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

#if defined(__cpp_lib_char8_t)
void assume::is_empty(const char8* value, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::is_empty(value, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}
#endif

void assume::is_empty(const char16* value, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::is_empty(value, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_empty(const char32* value, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::is_empty(value, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_empty(const wchar_t* value, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::is_empty(value, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_false(bool condition) {
  is_false(condition, "", stack_frame::empty());
}

void assume::is_false(bool condition, const stack_frame& stack_frame) {
  is_false(condition, "", stack_frame);
}

void assume::is_false(bool condition, const ustring& message) {
  is_false(condition, message, stack_frame::empty());
}

void assume::is_false(bool condition, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::is_false(condition, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_greater(const char* val1, const char* val2, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::is_greater(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

#if defined(__cpp_lib_char8_t)
void assume::is_greater(const char8* val1, const char8* val2, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::is_greater(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}
#endif

void assume::is_greater(const char16* val1, const char16* val2, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::is_greater(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_greater(const char32* val1, const char32* val2, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::is_greater(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_greater(const wchar_t* val1, const wchar_t* val2, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::is_greater(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_greater_or_equal(const char* val1, const char* val2, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::is_greater_or_equal(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

#if defined(__cpp_lib_char8_t)
void assume::is_greater_or_equal(const char8* val1, const char8* val2, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::is_greater_or_equal(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}
#endif

void assume::is_greater_or_equal(const char16* val1, const char16* val2, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::is_greater_or_equal(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_greater_or_equal(const char32* val1, const char32* val2, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::is_greater_or_equal(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_greater_or_equal(const wchar_t* val1, const wchar_t* val2, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::is_greater_or_equal(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_less(const char* val1, const char* val2, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::is_less(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

#if defined(__cpp_lib_char8_t)
void assume::is_less(const char8* val1, const char8* val2, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::is_less(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}
#endif

void assume::is_less(const char16* val1, const char16* val2, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::is_less(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_less(const char32* val1, const char32* val2, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::is_less(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_less(const wchar_t* val1, const wchar_t* val2, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::is_less(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_less_or_equal(const char* val1, const char* val2, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::is_less_or_equal(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

#if defined(__cpp_lib_char8_t)
void assume::is_less_or_equal(const char8* val1, const char8* val2, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::is_less_or_equal(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}
#endif

void assume::is_less_or_equal(const char16* val1, const char16* val2, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::is_less_or_equal(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_less_or_equal(const char32* val1, const char32* val2, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::is_less_or_equal(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_less_or_equal(const wchar_t* val1, const wchar_t* val2, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::is_less_or_equal(val1, val2, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_NaN(double value) {
  is_NaN(value, "", stack_frame::empty());
}

void assume::is_NaN(double value, const stack_frame& stack_frame) {
  is_NaN(value, "", stack_frame);
}

void assume::is_NaN(double value, const ustring& message) {
  is_NaN(value, message, stack_frame::empty());
}

void assume::is_NaN(double value, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::is_NaN(value, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_NaN(long double value) {is_NaN(value, "", stack_frame::empty());}

void assume::is_NaN(long double value, const stack_frame& stack_frame) {is_NaN(value, "", stack_frame);}

void assume::is_NaN(long double value, const ustring& message) {is_NaN(value, message, stack_frame::empty());}

void assume::is_NaN(long double value, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::is_NaN(value, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_NaN(float value) {
  is_NaN(value, "", stack_frame::empty());
}

void assume::is_NaN(float value, const stack_frame& stack_frame) {
  is_NaN(value, "", stack_frame);
}

void assume::is_NaN(float value, const ustring& message) {
  is_NaN(value, message, stack_frame::empty());
}

void assume::is_NaN(float value, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::is_NaN(value, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}


void assume::is_not_empty(const char* value, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::is_not_empty(value, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

#if defined(__cpp_lib_char8_t)
void assume::is_not_empty(const char8* value, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::is_not_empty(value, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}
#endif

void assume::is_not_empty(const char16* value, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::is_not_empty(value, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_not_empty(const char32* value, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::is_not_empty(value, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_not_empty(const wchar_t* value, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::is_not_empty(value, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_not_null(nullptr_t pointer) {
  is_not_null(pointer, "", stack_frame::empty());
}

void assume::is_not_null(nullptr_t pointer, const stack_frame& stack_frame) {
  is_not_null(pointer, "", stack_frame);
}

void assume::is_not_null(nullptr_t pointer, const ustring& message) {
  is_not_null(pointer, message, stack_frame::empty());
}

void assume::is_not_null(nullptr_t pointer, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::is_not_null(pointer, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::is_null(nullptr_t pointer) {
  is_null(pointer, "", stack_frame::empty());
}

void assume::is_null(nullptr_t pointer, const stack_frame& stack_frame) {
  is_null(pointer, "", stack_frame);
}

void assume::is_null(nullptr_t pointer, const ustring& message) {
  is_null(pointer, message, stack_frame::empty());
}

void assume::is_null(nullptr_t pointer, const ustring& message, const stack_frame& stack_frame) {
  assert::succeed(message, stack_frame);
}

void assume::is_true(bool condition) {
  is_true(condition, "", stack_frame::empty());
}

void assume::is_true(bool condition, const stack_frame& stack_frame) {
  is_true(condition, "", stack_frame);
}

void assume::is_true(bool condition, const ustring& message) {
  is_true(condition, message, stack_frame::empty());
}

void assume::is_true(bool condition, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::is_true(condition, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}

void assume::throws_any(const function<void()>& statement) {
  throws_any(statement, "", stack_frame::empty());
}

void assume::throws_any(const function<void()>& statement, const stack_frame& stack_frame) {
  throws_any(statement, "", stack_frame);
}

void assume::throws_any(const function<void()>& statement, const ustring& message) {
  throws_any(statement, message, stack_frame::empty());
}

void assume::throws_any(const function<void()>& statement, const ustring& message, const stack_frame& stack_frame) {
  try {
    assert::throws_any(statement, message, stack_frame);
  } catch (...) {
    assert::abort();
  }
}
