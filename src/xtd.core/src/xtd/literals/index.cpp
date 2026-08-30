#include "../../../include/xtd/literals/index.hpp"
#include "../../../include/xtd/as.hpp"

using namespace xtd;

auto xtd::literals::operator""_i(const char* s, usize n) -> xtd::index {
  if (n >= 1 && s[0] == '~') return xtd::index {~as<usize>(string(s + 1, s + n))};
  return xtd::index {as<usize>(string(s, s + n))};
}

auto xtd::literals::operator""_i(const char8* s, usize n) -> xtd::index {
  if (n >= 1 && s[0] == u8'~') return xtd::index {~as<usize>(string(s + 1, s + n))};
  return xtd::index {as<usize>(string(s, s + n))};
}

auto xtd::literals::operator""_i(const char16* s, usize n) -> xtd::index {
  if (n >= 1 && s[0] == u'~') return xtd::index {~as<usize>(std::u16string(s + 1, s + n))};
  return xtd::index {as<usize>(std::u16string(s, s + n))};
}

auto xtd::literals::operator""_i(const char32* s, usize n) -> xtd::index {
  if (n >= 1 && s[0] == U'~') return xtd::index {~as<usize>(std::u32string(s + 1, s + n))};
  return xtd::index {as<usize>(std::u32string(s, s + n))};
}

auto xtd::literals::operator""_i(const wchar* s, usize n) -> xtd::index {
  if (n >= 1 && s[0] == L'~') return xtd::index {~as<usize>(std::wstring(s + 1, s + n))};
  return xtd::index {as<usize>(std::wstring(s, s + n))};
}
