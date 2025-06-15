#include "../../../include/xtd/literals/byte.hpp"
#include "../../../include/xtd/as.hpp"

using namespace xtd;

xtd::byte xtd::literals::operator""_b(long double n) {
  return as<xtd::byte>(n);
}

xtd::byte xtd::literals::operator""_b(unsigned long long n) {
  return as<xtd::byte>(n);
}

xtd::byte xtd::literals::operator""_b(const char* s, xtd::size n) {
  return as<xtd::byte>(string(s, s + n));
}

xtd::byte xtd::literals::operator""_b(const char8* s, xtd::size n) {
  return as<xtd::byte>(string(s, s + n));
}

xtd::byte xtd::literals::operator""_b(const char16* s, xtd::size n) {
  return as<xtd::byte>(std::u16string(s, s + n));
}

xtd::byte xtd::literals::operator""_b(const char32* s, xtd::size n) {
  return as<xtd::byte>(std::u32string(s, s + n));
}

xtd::byte xtd::literals::operator""_b(const wchar* s, xtd::size n) {
  return as<xtd::byte>(std::wstring(s, s + n));
}

xtd::byte xtd::literals::operator""_u8(long double n) {
  return as<xtd::byte>(n);
}

xtd::byte xtd::literals::operator""_u8(unsigned long long n) {
  return as<xtd::byte>(n);
}

xtd::byte xtd::literals::operator""_u8(const char* s, xtd::size n) {
  return as<xtd::byte>(string(s, s + n));
}

xtd::byte xtd::literals::operator""_u8(const char8* s, xtd::size n) {
  return as<xtd::byte>(string(s, s + n));
}

xtd::byte xtd::literals::operator""_u8(const char16* s, xtd::size n) {
  return as<xtd::byte>(std::u16string(s, s + n));
}

xtd::byte xtd::literals::operator""_u8(const char32* s, xtd::size n) {
  return as<xtd::byte>(std::u32string(s, s + n));
}

xtd::byte xtd::literals::operator""_u8(const wchar* s, xtd::size n) {
  return as<xtd::byte>(std::wstring(s, s + n));
}
