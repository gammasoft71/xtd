#include "../../../include/xtd/literals/sbyte.hpp"
#include "../../../include/xtd/as.hpp"

using namespace xtd;

auto xtd::literals::operator""_i8(long double n) -> sbyte {
  return as<sbyte>(n);
}

auto xtd::literals::operator""_i8(unsigned long long n) -> sbyte {
  return as<sbyte>(n);
}

auto xtd::literals::operator""_i8(const char* s, size n) -> sbyte {
  return as<sbyte>(string(s, s + n));
}

auto xtd::literals::operator""_i8(const char8* s, size n) -> sbyte {
  return as<sbyte>(string(s, s + n));
}

auto xtd::literals::operator""_i8(const char16* s, size n) -> sbyte {
  return as<sbyte>(std::u16string(s, s + n));
}

auto xtd::literals::operator""_i8(const char32* s, size n) -> sbyte {
  return as<sbyte>(std::u32string(s, s + n));
}

auto xtd::literals::operator""_i8(const wchar* s, size n) -> sbyte {
  return as<sbyte>(std::wstring(s, s + n));
}

auto xtd::literals::operator""_s8(long double n) -> sbyte {
  return as<sbyte>(n);
}

auto xtd::literals::operator""_s8(unsigned long long n) -> sbyte {
  return as<sbyte>(n);
}

auto xtd::literals::operator""_s8(const char* s, size n) -> sbyte {
  return as<sbyte>(string(s, s + n));
}

auto xtd::literals::operator""_s8(const char8* s, size n) -> sbyte {
  return as<sbyte>(string(s, s + n));
}

auto xtd::literals::operator""_s8(const char16* s, size n) -> sbyte {
  return as<sbyte>(std::u16string(s, s + n));
}

auto xtd::literals::operator""_s8(const char32* s, size n) -> sbyte {
  return as<sbyte>(std::u32string(s, s + n));
}

auto xtd::literals::operator""_s8(const wchar* s, size n) -> sbyte {
  return as<sbyte>(std::wstring(s, s + n));
}
