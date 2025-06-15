#include "../../../include/xtd/literals/sbyte.hpp"
#include "../../../include/xtd/as.hpp"

using namespace xtd;

sbyte xtd::literals::operator""_i8(long double n) {
  return as<sbyte>(n);
}

sbyte xtd::literals::operator""_i8(unsigned long long n) {
  return as<sbyte>(n);
}

sbyte xtd::literals::operator""_i8(const char* s, xtd::size n) {
  return as<sbyte>(string(s, s + n));
}

sbyte xtd::literals::operator""_i8(const char8* s, xtd::size n) {
  return as<sbyte>(string(s, s + n));
}

sbyte xtd::literals::operator""_i8(const char16* s, xtd::size n) {
  return as<sbyte>(std::u16string(s, s + n));
}

sbyte xtd::literals::operator""_i8(const char32* s, xtd::size n) {
  return as<sbyte>(std::u32string(s, s + n));
}

sbyte xtd::literals::operator""_i8(const wchar* s, xtd::size n) {
  return as<sbyte>(std::wstring(s, s + n));
}

sbyte xtd::literals::operator""_s8(long double n) {
  return as<sbyte>(n);
}

sbyte xtd::literals::operator""_s8(unsigned long long n) {
  return as<sbyte>(n);
}

sbyte xtd::literals::operator""_s8(const char* s, xtd::size n) {
  return as<sbyte>(string(s, s + n));
}

sbyte xtd::literals::operator""_s8(const char8* s, xtd::size n) {
  return as<sbyte>(string(s, s + n));
}

sbyte xtd::literals::operator""_s8(const char16* s, xtd::size n) {
  return as<sbyte>(std::u16string(s, s + n));
}

sbyte xtd::literals::operator""_s8(const char32* s, xtd::size n) {
  return as<sbyte>(std::u32string(s, s + n));
}

sbyte xtd::literals::operator""_s8(const wchar* s, xtd::size n) {
  return as<sbyte>(std::wstring(s, s + n));
}
