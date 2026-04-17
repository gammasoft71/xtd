#include "../../../include/xtd/literals/ssize.hpp"
#include "../../../include/xtd/usize.hpp"
#include "../../../include/xtd/as.hpp"

using namespace xtd;

auto xtd::literals::operator""_sz(const char* s, usize n) -> ssize {
  return as<ssize>(string(s, s + n));
}

auto xtd::literals::operator""_sz(const char8* s, usize n) -> ssize {
  return as<ssize>(string(s, s + n));
}

auto xtd::literals::operator""_sz(const char16* s, usize n) -> ssize {
  return as<ssize>(std::u16string(s, s + n));
}

auto xtd::literals::operator""_sz(const char32* s, usize n) -> ssize {
  return as<ssize>(std::u32string(s, s + n));
}

auto xtd::literals::operator""_sz(const wchar* s, usize n) -> ssize {
  return as<ssize>(std::wstring(s, s + n));
}
