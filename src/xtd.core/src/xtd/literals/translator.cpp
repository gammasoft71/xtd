#include "../../../include/xtd/literals/translator.hpp"
#include "../../../include/xtd/translator.hpp"

using namespace xtd;

const char* xtd::literals::operator""_t(const char* s, xtd::size n) noexcept {
  return translator::translate(s);
}

#if defined(__xtd__cpp_lib_char8_t)
string xtd::literals::operator""_t(const char8* s, xtd::size n) noexcept {
  return translator::translate(std::u8string(s, s + n));
}
#endif

string xtd::literals::operator""_t(const char16* s, xtd::size n) noexcept {
  return translator::translate(std::u16string(s, s + n));
}

string xtd::literals::operator""_t(const char32* s, xtd::size n) noexcept {
  return translator::translate(std::u32string(s, s + n));
}

string xtd::literals::operator""_t(const wchar* s, xtd::size n) noexcept {
  return translator::translate(std::wstring(s, s + n));
}
