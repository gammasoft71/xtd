#include "../../../include/xtd/literals/color.hpp"

using namespace xtd;
using namespace xtd::drawing;

color xtd::literals::operator""_color(const char* s, xtd::size n) {
  return color::parse(string {s});
}

#if defined(__xtd__cpp_lib_char8_t)
color xtd::literals::operator""_color(const char8* s, xtd::size n) {
  return color::parse(string {s});
}
#endif

color xtd::literals::operator""_color(const char16* s, xtd::size n) {
  return color::parse(string {s});
}

color xtd::literals::operator""_color(const char32* s, xtd::size n) {
  return color::parse(string {s});
}

color xtd::literals::operator""_color(const wchar* s, xtd::size n) {
  return color::parse(string {s});
}
