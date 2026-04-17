#include "../../../include/xtd/literals/uint32.hpp"
#include "../../../include/xtd/as.hpp"

using namespace xtd;

auto xtd::literals::operator""_u32(long double n) -> uint32 {
  return as<uint32>(n);
}

auto xtd::literals::operator""_u32(unsigned long long n) -> uint32 {
  return as<uint32>(n);
}

auto xtd::literals::operator""_u32(const char* s, usize n) -> uint32 {
  return as<uint32>(string(s, s + n));
}

auto xtd::literals::operator""_u32(const char8* s, usize n) -> uint32 {
  return as<uint32>(string(s, s + n));
}

auto xtd::literals::operator""_u32(const char16* s, usize n) -> uint32 {
  return as<uint32>(std::u16string(s, s + n));
}

auto xtd::literals::operator""_u32(const char32* s, usize n) -> uint32 {
  return as<uint32>(std::u32string(s, s + n));
}

auto xtd::literals::operator""_u32(const wchar* s, usize n) -> uint32 {
  return as<uint32>(std::wstring(s, s + n));
}
