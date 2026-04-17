#include "../../../include/xtd/literals/usize.hpp"
#include "../../../include/xtd/as.hpp"

using namespace xtd;

auto xtd::literals::operator""_uz(const char* s, usize n) -> usize {
  return as<usize>(string(s, s + n));
}

auto xtd::literals::operator""_uz(const char8* s, usize n) -> usize {
  return as<usize>(string(s, s + n));
}

auto xtd::literals::operator""_uz(const char16* s, usize n) -> usize {
  return as<usize>(std::u16string(s, s + n));
}

auto xtd::literals::operator""_uz(const char32* s, usize n) -> usize {
  return as<usize>(std::u32string(s, s + n));
}

auto xtd::literals::operator""_uz(const wchar* s, usize n) -> usize {
  return as<usize>(std::wstring(s, s + n));
}

auto xtd::literals::operator""_z(const char* s, usize n) -> usize {
  return as<usize>(string(s, s + n));
}

auto xtd::literals::operator""_z(const char8* s, usize n) -> usize {
  return as<usize>(string(s, s + n));
}

auto xtd::literals::operator""_z(const char16* s, usize n) -> usize {
  return as<usize>(std::u16string(s, s + n));
}

auto xtd::literals::operator""_z(const char32* s, usize n) -> usize {
  return as<usize>(std::u32string(s, s + n));
}

auto xtd::literals::operator""_z(const wchar* s, usize n) -> usize {
  return as<usize>(std::wstring(s, s + n));
}
