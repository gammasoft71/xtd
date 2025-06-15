#include "../../../include/xtd/literals/uint32.hpp"
#include "../../../include/xtd/as.hpp"

using namespace xtd;

uint32 xtd::literals::operator""_u32(long double n) {
  return as<uint32>(n);
}

uint32 xtd::literals::operator""_u32(unsigned long long n) {
  return as<uint32>(n);
}

uint32 xtd::literals::operator""_u32(const char* s, xtd::size n) {
  return as<uint32>(string(s, s + n));
}

uint32 xtd::literals::operator""_u32(const char8* s, xtd::size n) {
  return as<uint32>(string(s, s + n));
}

uint32 xtd::literals::operator""_u32(const char16* s, xtd::size n) {
  return as<uint32>(std::u16string(s, s + n));
}

uint32 xtd::literals::operator""_u32(const char32* s, xtd::size n) {
  return as<uint32>(std::u32string(s, s + n));
}

uint32 xtd::literals::operator""_u32(const wchar* s, xtd::size n) {
  return as<uint32>(std::wstring(s, s + n));
}
