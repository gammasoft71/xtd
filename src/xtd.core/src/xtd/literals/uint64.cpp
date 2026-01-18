#include "../../../include/xtd/literals/uint64.hpp"
#include "../../../include/xtd/as.hpp"

using namespace xtd;

auto xtd::literals::operator""_u64(long double n) -> uint64 {
  return as<uint64>(n);
}

auto xtd::literals::operator""_u64(unsigned long long n) -> uint64 {
  return as<uint64>(n);
}

auto xtd::literals::operator""_u64(const char* s, size n) -> uint64 {
  return as<uint64>(string(s, s + n));
}

auto xtd::literals::operator""_u64(const char8* s, size n) -> uint64 {
  return as<uint64>(string(s, s + n));
}

auto xtd::literals::operator""_u64(const char16* s, size n) -> uint64 {
  return as<uint64>(std::u16string(s, s + n));
}

auto xtd::literals::operator""_u64(const char32* s, size n) -> uint64 {
  return as<uint64>(std::u32string(s, s + n));
}

auto xtd::literals::operator""_u64(const wchar* s, size n) -> uint64 {
  return as<uint64>(std::wstring(s, s + n));
}
