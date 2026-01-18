#include "../../../include/xtd/literals/int16.hpp"
#include "../../../include/xtd/as.hpp"

using namespace xtd;

auto xtd::literals::operator""_i16(long double n) -> int16 {
  return as<int16>(n);
}

auto xtd::literals::operator""_i16(unsigned long long n) -> int16 {
  return as<int16>(n);
}

auto xtd::literals::operator""_i16(const char* s, size n) -> int16 {
  return as<int16>(string(s, s + n));
}

auto xtd::literals::operator""_i16(const char8* s, size n) -> int16 {
  return as<int16>(string(s, s + n));
}

auto xtd::literals::operator""_i16(const char16* s, size n) -> int16 {
  return as<int16>(std::u16string(s, s + n));
}

auto xtd::literals::operator""_i16(const char32* s, size n) -> int16 {
  return as<int16>(std::u32string(s, s + n));
}

auto xtd::literals::operator""_i16(const wchar* s, size n) -> int16 {
  return as<int16>(std::wstring(s, s + n));
}

auto xtd::literals::operator""_s16(long double n) -> int16 {
  return as<int16>(n);
}

auto xtd::literals::operator""_s16(unsigned long long n) -> int16 {
  return as<int16>(n);
}

auto xtd::literals::operator""_s16(const char* s, size n) -> int16 {
  return as<int16>(string(s, s + n));
}

auto xtd::literals::operator""_s16(const char8* s, size n) -> int16 {
  return as<int16>(string(s, s + n));
}

auto xtd::literals::operator""_s16(const char16* s, size n) -> int16 {
  return as<int16>(std::u16string(s, s + n));
}

auto xtd::literals::operator""_s16(const char32* s, size n) -> int16 {
  return as<int16>(std::u32string(s, s + n));
}

auto xtd::literals::operator""_s16(const wchar* s, size n) -> int16 {
  return as<int16>(std::wstring(s, s + n));
}
