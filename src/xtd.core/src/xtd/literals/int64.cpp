#include "../../../include/xtd/literals/int64.hpp"
#include "../../../include/xtd/as.hpp"

using namespace xtd;

int64 xtd::literals::operator""_i64(long double n) {
  return as<int64>(n);
}

int64 xtd::literals::operator""_i64(unsigned long long n) {
  return as<int64>(n);
}

int64 xtd::literals::operator""_i64(const char* s, xtd::size n) {
  return as<int64>(string(s, s + n));
}

#if defined(__xtd__cpp_lib_char8_t)
int64 xtd::literals::operator""_i64(const char8* s, xtd::size n) {
  return as<int64>(string(s, s + n));
}
#endif

int64 xtd::literals::operator""_i64(const char16* s, xtd::size n) {
  return as<int64>(std::u16string(s, s + n));
}

int64 xtd::literals::operator""_i64(const char32* s, xtd::size n) {
  return as<int64>(std::u32string(s, s + n));
}

int64 xtd::literals::operator""_i64(const wchar* s, xtd::size n) {
  return as<int64>(std::wstring(s, s + n));
}

int64 xtd::literals::operator""_s64(long double n) {
  return as<int64>(n);
}

int64 xtd::literals::operator""_s64(unsigned long long n) {
  return as<int64>(n);
}

int64 xtd::literals::operator""_s64(const char* s, xtd::size n) {
  return as<int64>(string(s, s + n));
}

#if defined(__xtd__cpp_lib_char8_t)
int64 xtd::literals::operator""_s64(const char8* s, xtd::size n) {
  return as<int64>(string(s, s + n));
}
#endif

int64 xtd::literals::operator""_s64(const char16* s, xtd::size n) {
  return as<int64>(std::u16string(s, s + n));
}

int64 xtd::literals::operator""_s64(const char32* s, xtd::size n) {
  return as<int64>(std::u32string(s, s + n));
}

int64 xtd::literals::operator""_s64(const wchar* s, xtd::size n) {
  return as<int64>(std::wstring(s, s + n));
}
