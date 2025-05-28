#include "../../../include/xtd/literals/int32.hpp"
#include "../../../include/xtd/as.hpp"

using namespace xtd;

int32 xtd::literals::operator""_i32(long double n) {
  return as<int32>(n);
}

int32 xtd::literals::operator""_i32(unsigned long long n) {
  return as<int32>(n);
}

int32 xtd::literals::operator""_i32(const char* s, xtd::size n) {
  return as<int32>(string(s, s + n));
}

#if defined(__xtd__cpp_lib_char8_t)
int32 xtd::literals::operator""_i32(const char8* s, xtd::size n) {
  return as<int32>(string(s, s + n));
}
#endif

int32 xtd::literals::operator""_i32(const char16* s, xtd::size n) {
  return as<int32>(std::u16string(s, s + n));
}

int32 xtd::literals::operator""_i32(const char32* s, xtd::size n) {
  return as<int32>(std::u32string(s, s + n));
}

int32 xtd::literals::operator""_i32(const wchar* s, xtd::size n) {
  return as<int32>(std::wstring(s, s + n));
}

int32 xtd::literals::operator""_s32(long double n) {
  return as<int32>(n);
}

int32 xtd::literals::operator""_s32(unsigned long long n) {
  return as<int32>(n);
}

int32 xtd::literals::operator""_s32(const char* s, xtd::size n) {
  return as<int32>(string(s, s + n));
}

#if defined(__xtd__cpp_lib_char8_t)
int32 xtd::literals::operator""_s32(const char8* s, xtd::size n) {
  return as<int32>(string(s, s + n));
}
#endif

int32 xtd::literals::operator""_s32(const char16* s, xtd::size n) {
  return as<int32>(std::u16string(s, s + n));
}

int32 xtd::literals::operator""_s32(const char32* s, xtd::size n) {
  return as<int32>(std::u32string(s, s + n));
}

int32 xtd::literals::operator""_s32(const wchar* s, xtd::size n) {
  return as<int32>(std::wstring(s, s + n));
}
