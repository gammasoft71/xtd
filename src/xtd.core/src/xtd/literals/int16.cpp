#include "../../../include/xtd/literals/int16.hpp"
#include "../../../include/xtd/as.hpp"

using namespace xtd;

int16 xtd::literals::operator""_i16(long double n) {
  return as<int16>(n);
}

int16 xtd::literals::operator""_i16(unsigned long long n) {
  return as<int16>(n);
}

int16 xtd::literals::operator""_i16(const char* s, xtd::size n) {
  return as<int16>(string(s, s + n));
}

#if defined(__xtd__cpp_lib_char8_t)
int16 xtd::literals::operator""_i16(const char8* s, xtd::size n) {
  return as<int16>(string(s, s + n));
}
#endif

int16 xtd::literals::operator""_i16(const char16* s, xtd::size n) {
  return as<int16>(std::u16string(s, s + n));
}

int16 xtd::literals::operator""_i16(const char32* s, xtd::size n) {
  return as<int16>(std::u32string(s, s + n));
}

int16 xtd::literals::operator""_i16(const wchar* s, xtd::size n) {
  return as<int16>(std::wstring(s, s + n));
}

int16 xtd::literals::operator""_s16(long double n) {
  return as<int16>(n);
}

int16 xtd::literals::operator""_s16(unsigned long long n) {
  return as<int16>(n);
}

int16 xtd::literals::operator""_s16(const char* s, xtd::size n) {
  return as<int16>(string(s, s + n));
}

#if defined(__xtd__cpp_lib_char8_t)
int16 xtd::literals::operator""_s16(const char8* s, xtd::size n) {
  return as<int16>(string(s, s + n));
}
#endif

int16 xtd::literals::operator""_s16(const char16* s, xtd::size n) {
  return as<int16>(std::u16string(s, s + n));
}

int16 xtd::literals::operator""_s16(const char32* s, xtd::size n) {
  return as<int16>(std::u32string(s, s + n));
}

int16 xtd::literals::operator""_s16(const wchar* s, xtd::size n) {
  return as<int16>(std::wstring(s, s + n));
}
