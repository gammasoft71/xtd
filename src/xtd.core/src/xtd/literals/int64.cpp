#include "../../../include/xtd/literals/int64.hpp"
#include "../../../include/xtd/as.hpp"

using namespace xtd;

auto xtd::literals::operator""_i64(long double n) -> int64 {
  return as<int64>(n);
}

auto xtd::literals::operator""_i64(unsigned long long n) -> int64 {
  return as<int64>(n);
}

auto xtd::literals::operator""_i64(const char* s, size n) -> int64 {
  return as<int64>(string(s, s + n));
}

auto xtd::literals::operator""_i64(const char8* s, size n) -> int64 {
  return as<int64>(string(s, s + n));
}

auto xtd::literals::operator""_i64(const char16* s, size n) -> int64 {
  return as<int64>(std::u16string(s, s + n));
}

auto xtd::literals::operator""_i64(const char32* s, size n) -> int64 {
  return as<int64>(std::u32string(s, s + n));
}

auto xtd::literals::operator""_i64(const wchar* s, size n) -> int64 {
  return as<int64>(std::wstring(s, s + n));
}

auto xtd::literals::operator""_s64(long double n) -> int64 {
  return as<int64>(n);
}

auto xtd::literals::operator""_s64(unsigned long long n) -> int64 {
  return as<int64>(n);
}

auto xtd::literals::operator""_s64(const char* s, size n) -> int64 {
  return as<int64>(string(s, s + n));
}

auto xtd::literals::operator""_s64(const char8* s, size n) -> int64 {
  return as<int64>(string(s, s + n));
}

auto xtd::literals::operator""_s64(const char16* s, size n) -> int64 {
  return as<int64>(std::u16string(s, s + n));
}

auto xtd::literals::operator""_s64(const char32* s, size n) -> int64 {
  return as<int64>(std::u32string(s, s + n));
}

auto xtd::literals::operator""_s64(const wchar* s, size n) -> int64 {
  return as<int64>(std::wstring(s, s + n));
}
