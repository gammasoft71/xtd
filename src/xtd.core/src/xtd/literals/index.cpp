#include "../../../include/xtd/literals/index.hpp"
#include "../../../include/xtd/string.hpp"

using namespace xtd;

auto xtd::literals::operator""_i(const char* s, usize n) -> xtd::index {
  return xtd::index::parse(string(s, s + n));
}

auto xtd::literals::operator""_i(const char8* s, usize n) -> xtd::index {
  return xtd::index::parse(u8string(s, s + n));
}

auto xtd::literals::operator""_i(const char16* s, usize n) -> xtd::index {
  return xtd::index::parse(u16string(s, s + n));
}

auto xtd::literals::operator""_i(const char32* s, usize n) -> xtd::index {
  return xtd::index::parse(u32string(s, s + n));
}

auto xtd::literals::operator""_i(const wchar* s, usize n) -> xtd::index {
  return xtd::index::parse(wstring(s, s + n));
}
