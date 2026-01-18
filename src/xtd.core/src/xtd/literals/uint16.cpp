#include "../../../include/xtd/literals/uint16.hpp"
#include "../../../include/xtd/as.hpp"

using namespace xtd;

auto xtd::literals::operator""_u16(long double n) -> uint16 {
  return as<uint16>(n);
}

auto xtd::literals::operator""_u16(unsigned long long n) -> uint16 {
  return as<uint16>(n);
}

auto xtd::literals::operator""_u16(const char* s, size n) -> uint16 {
  return as<uint16>(string(s, s + n));
}

auto xtd::literals::operator""_u16(const char8* s, size n) -> uint16 {
  return as<uint16>(string(s, s + n));
}

auto xtd::literals::operator""_u16(const char16* s, size n) -> uint16 {
  return as<uint16>(std::u16string(s, s + n));
}

auto xtd::literals::operator""_u16(const char32* s, size n) -> uint16 {
  return as<uint16>(std::u32string(s, s + n));
}

auto xtd::literals::operator""_u16(const wchar* s, size n) -> uint16 {
  return as<uint16>(std::u32string(s, s + n));
}
