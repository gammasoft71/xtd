#include "../../../include/xtd/literals/version.hpp"
#include "../../../include/xtd/version.hpp"

using namespace xtd;

version xtd::literals::operator""_vers(const char* s, xtd::size n) {
  return version::parse(string {s});
}

version xtd::literals::operator""_vers(const char8* s, xtd::size n) {
  return version::parse(string {s});
}

version xtd::literals::operator""_vers(const char16* s, xtd::size n) {
  return version::parse(string {s});
}

version xtd::literals::operator""_vers(const char32* s, xtd::size n) {
  return version::parse(string {s});
}

version xtd::literals::operator""_vers(const wchar* s, xtd::size n) {
  return version::parse(string {s});
}
