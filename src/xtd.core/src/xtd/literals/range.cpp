#include "../../../include/xtd/literals/range.hpp"
#include "../../../include/xtd/string.hpp"

using namespace xtd;

auto xtd::literals::operator""_r(const char* s, usize n) -> xtd::range {
  return xtd::range::parse(string(s, s + n));
}

auto xtd::literals::operator""_r(const char8* s, usize n) -> xtd::range {
  return xtd::range::parse(u8string(s, s + n));
}

auto xtd::literals::operator""_r(const char16* s, usize n) -> xtd::range {
  return xtd::range::parse(u16string(s, s + n));
}

auto xtd::literals::operator""_r(const char32* s, usize n) -> xtd::range {
  return xtd::range::parse(u32string(s, s + n));
}

auto xtd::literals::operator""_r(const wchar* s, usize n) -> xtd::range {
  return xtd::range::parse(wstring(s, s + n));
}
