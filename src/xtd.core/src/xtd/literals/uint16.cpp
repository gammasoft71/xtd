#include "../../../include/xtd/literals/uint16.hpp"
#include "../../../include/xtd/as.hpp"

using namespace xtd;

uint16 xtd::literals::operator""_u16(long double n) {
  return as<uint16>(n);
}

uint16 xtd::literals::operator""_u16(unsigned long long n) {
  return as<uint16>(n);
}

uint16 xtd::literals::operator""_u16(const char* s, xtd::size n) {
  return as<uint16>(string(s, s + n));
}

uint16 xtd::literals::operator""_u16(const char8* s, xtd::size n) {
  return as<uint16>(string(s, s + n));
}

uint16 xtd::literals::operator""_u16(const char16* s, xtd::size n) {
  return as<uint16>(std::u16string(s, s + n));
}

uint16 xtd::literals::operator""_u16(const char32* s, xtd::size n) {
  return as<uint16>(std::u32string(s, s + n));
}

uint16 xtd::literals::operator""_u16(const wchar* s, xtd::size n) {
  return as<uint16>(std::u32string(s, s + n));
}
