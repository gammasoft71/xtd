#include "../../../include/xtd/literals/color.hpp"

using namespace xtd;
using namespace xtd::drawing;

color xtd::literals::operator""_color(const char* s, xtd::size n) {
  return color::parse(string {s});
}

color xtd::literals::operator""_color(const char8* s, xtd::size n) {
  return color::parse(string {s});
}

color xtd::literals::operator""_color(const char16* s, xtd::size n) {
  return color::parse(string {s});
}

color xtd::literals::operator""_color(const char32* s, xtd::size n) {
  return color::parse(string {s});
}

color xtd::literals::operator""_color(const wchar* s, xtd::size n) {
  return color::parse(string {s});
}
