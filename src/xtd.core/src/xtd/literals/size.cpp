#include "../../../include/xtd/literals/size.hpp"
#include "../../../include/xtd/as.hpp"

using namespace xtd;

xtd::size xtd::literals::operator""_uz(const char* s, xtd::size n) {
  return as<xtd::size>(string(s, s + n));
}

xtd::size xtd::literals::operator""_uz(const char8* s, xtd::size n) {
  return as<xtd::size>(string(s, s + n));
}

xtd::size xtd::literals::operator""_uz(const char16* s, xtd::size n) {
  return as<xtd::size>(std::u16string(s, s + n));
}

xtd::size xtd::literals::operator""_uz(const char32* s, xtd::size n) {
  return as<xtd::size>(std::u32string(s, s + n));
}

xtd::size xtd::literals::operator""_uz(const wchar* s, xtd::size n) {
  return as<xtd::size>(std::wstring(s, s + n));
}

xtd::size xtd::literals::operator""_z(const char* s, xtd::size n) {
  return as<xtd::size>(string(s, s + n));
}

xtd::size xtd::literals::operator""_z(const char8* s, xtd::size n) {
  return as<xtd::size>(string(s, s + n));
}

xtd::size xtd::literals::operator""_z(const char16* s, xtd::size n) {
  return as<xtd::size>(std::u16string(s, s + n));
}

xtd::size xtd::literals::operator""_z(const char32* s, xtd::size n) {
  return as<xtd::size>(std::u32string(s, s + n));
}

xtd::size xtd::literals::operator""_z(const wchar* s, xtd::size n) {
  return as<xtd::size>(std::wstring(s, s + n));
}
