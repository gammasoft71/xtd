#include "../../../include/xtd/literals/int32.hpp"
#include "../../../include/xtd/as.hpp"

using namespace xtd;

auto xtd::literals::operator""_i32(long double n) -> int32 {
  return as<int32>(n);
}

auto xtd::literals::operator""_i32(unsigned long long n) -> int32 {
  return as<int32>(n);
}

auto xtd::literals::operator""_i32(const char* s, size n) -> int32 {
  return as<int32>(string(s, s + n));
}

auto xtd::literals::operator""_i32(const char8* s, size n) -> int32 {
  return as<int32>(string(s, s + n));
}

auto xtd::literals::operator""_i32(const char16* s, size n) -> int32 {
  return as<int32>(std::u16string(s, s + n));
}

auto xtd::literals::operator""_i32(const char32* s, size n) -> int32 {
  return as<int32>(std::u32string(s, s + n));
}

auto xtd::literals::operator""_i32(const wchar* s, size n) -> int32 {
  return as<int32>(std::wstring(s, s + n));
}

auto xtd::literals::operator""_s32(long double n) -> int32 {
  return as<int32>(n);
}

auto xtd::literals::operator""_s32(unsigned long long n) -> int32 {
  return as<int32>(n);
}

auto xtd::literals::operator""_s32(const char* s, size n) -> int32 {
  return as<int32>(string(s, s + n));
}

auto xtd::literals::operator""_s32(const char8* s, size n) -> int32 {
  return as<int32>(string(s, s + n));
}

auto xtd::literals::operator""_s32(const char16* s, size n) -> int32 {
  return as<int32>(std::u16string(s, s + n));
}

auto xtd::literals::operator""_s32(const char32* s, size n) -> int32 {
  return as<int32>(std::u32string(s, s + n));
}

auto xtd::literals::operator""_s32(const wchar* s, size n) -> int32 {
  return as<int32>(std::wstring(s, s + n));
}
