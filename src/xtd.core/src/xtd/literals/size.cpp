#include "../../../include/xtd/literals/size.hpp"
#include "../../../include/xtd/as.hpp"

using namespace xtd;

auto xtd::literals::operator""_uz(const char* s, size n) -> size {
  return as<size>(string(s, s + n));
}

auto xtd::literals::operator""_uz(const char8* s, size n) -> size {
  return as<size>(string(s, s + n));
}

auto xtd::literals::operator""_uz(const char16* s, size n) -> size {
  return as<size>(std::u16string(s, s + n));
}

auto xtd::literals::operator""_uz(const char32* s, size n) -> size {
  return as<size>(std::u32string(s, s + n));
}

auto xtd::literals::operator""_uz(const wchar* s, size n) -> size {
  return as<size>(std::wstring(s, s + n));
}

auto xtd::literals::operator""_z(const char* s, size n) -> size {
  return as<size>(string(s, s + n));
}

auto xtd::literals::operator""_z(const char8* s, size n) -> size {
  return as<size>(string(s, s + n));
}

auto xtd::literals::operator""_z(const char16* s, size n) -> size {
  return as<size>(std::u16string(s, s + n));
}

auto xtd::literals::operator""_z(const char32* s, size n) -> size {
  return as<size>(std::u32string(s, s + n));
}

auto xtd::literals::operator""_z(const wchar* s, size n) -> size {
  return as<size>(std::wstring(s, s + n));
}
