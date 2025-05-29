#include "../../../include/xtd/literals/country.hpp"

using namespace xtd;
using namespace xtd::forms;

namespace {
  country get_country(const string& s) {
    auto result = country::empty();
    if (s.size() == 2) result = country::from_alpha_2_code(s);
    if (s.size() == 3) result = country::from_alpha_3_code(s);
    if (result == country::empty()) result = country::from_name(s);
    return result;
  }
}

country xtd::literals::operator""_country(const char* s, xtd::size n) {
  return get_country(string {s});
}

#if defined(__xtd__cpp_lib_char8_t)
country xtd::literals::operator""_country(const char8* s, xtd::size n) {
  return get_country(string {s});
}
#endif

country xtd::literals::operator""_country(const char16* s, xtd::size n) {
  return get_country(string {s});
}

country xtd::literals::operator""_country(const char32* s, xtd::size n) {
  return get_country(string {s});
}

country xtd::literals::operator""_country(const wchar* s, xtd::size n) {
  return get_country(string {s});
}
