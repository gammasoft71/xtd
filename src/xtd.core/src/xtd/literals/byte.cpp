#include "../../../include/xtd/literals/byte.hpp"
#include "../../../include/xtd/as.hpp"

using namespace xtd;

auto xtd::literals::operator""_b(long double n) -> xtd::byte {
  return as<xtd::byte>(n);
}

auto xtd::literals::operator""_b(unsigned long long n) -> xtd::byte {
  return as<xtd::byte>(n);
}

auto xtd::literals::operator""_b(const char* s, size n) -> xtd::byte {
  return as<xtd::byte>(string(s, s + n));
}

auto xtd::literals::operator""_b(const char8* s, size n) -> xtd::byte {
  return as<xtd::byte>(string(s, s + n));
}

auto xtd::literals::operator""_b(const char16* s, size n) -> xtd::byte {
  return as<xtd::byte>(std::u16string(s, s + n));
}

auto xtd::literals::operator""_b(const char32* s, size n) -> xtd::byte {
  return as<xtd::byte>(std::u32string(s, s + n));
}

auto xtd::literals::operator""_b(const wchar* s, size n) -> xtd::byte {
  return as<xtd::byte>(std::wstring(s, s + n));
}

auto xtd::literals::operator""_u8(long double n) -> xtd::byte {
  return as<xtd::byte>(n);
}

auto xtd::literals::operator""_u8(unsigned long long n) -> xtd::byte {
  return as<xtd::byte>(n);
}

auto xtd::literals::operator""_u8(const char* s, size n) -> xtd::byte {
  return as<xtd::byte>(string(s, s + n));
}

auto xtd::literals::operator""_u8(const char8* s, size n) -> xtd::byte {
  return as<xtd::byte>(string(s, s + n));
}

auto xtd::literals::operator""_u8(const char16* s, size n) -> xtd::byte {
  return as<xtd::byte>(std::u16string(s, s + n));
}

auto xtd::literals::operator""_u8(const char32* s, size n) -> xtd::byte {
  return as<xtd::byte>(std::u32string(s, s + n));
}

auto xtd::literals::operator""_u8(const wchar* s, size n) -> xtd::byte {
  return as<xtd::byte>(std::wstring(s, s + n));
}
