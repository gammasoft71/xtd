#include "../../../include/xtd/literals/country.hpp"

using namespace xtd;
using namespace xtd::forms;

country xtd::literals::operator""_country(const char* s, xtd::size n) {
  return country::from_name(string {s});
}

#if defined(__xtd__cpp_lib_char8_t)
country xtd::literals::operator""_country(const char8* s, xtd::size n) {
  return country::from_name(string {s});
}
#endif

country xtd::literals::operator""_country(const char16* s, xtd::size n) {
  return country::from_name(string {s});
}

country xtd::literals::operator""_country(const char32* s, xtd::size n) {
  return country::from_name(string {s});
}

country xtd::literals::operator""_country(const wchar* s, xtd::size n) {
  return country::from_name(string {s});
}
