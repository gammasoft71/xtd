#include "../../../include/xtd/literals/guid.hpp"
#include "../../../include/xtd/guid.hpp"

using namespace xtd;

guid xtd::literals::operator""_guid(const char* s, xtd::size n) {
  return guid(string {s});
}

guid xtd::literals::operator""_guid(const char8* s, xtd::size n) {
  return guid(string {s});
}

guid xtd::literals::operator""_guid(const char16* s, xtd::size n) {
  return guid(string {s});
}

guid xtd::literals::operator""_guid(const char32* s, xtd::size n) {
  return guid(string {s});
}

guid xtd::literals::operator""_guid(const wchar* s, xtd::size n) {
  return guid(string {s});
}
