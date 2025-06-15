#include "../../../include/xtd/literals/uri.hpp"
#include "../../../include/xtd/uri.hpp"

using namespace xtd;

uri xtd::literals::operator""_uri(const char* s, xtd::size n) {
  return uri(string {s});
}

uri xtd::literals::operator""_uri(const char8* s, xtd::size n) {
  return uri(string {s});
}

uri xtd::literals::operator""_uri(const char16* s, xtd::size n) {
  return uri(string {s});
}

uri xtd::literals::operator""_uri(const char32* s, xtd::size n) {
  return uri(string {s});
}

uri xtd::literals::operator""_uri(const wchar* s, xtd::size n) {
  return uri(string {s});
}
