#include "../../include/xtd/character_literals.hpp"
#include "../../include/xtd/as.hpp"

using namespace xtd;
using namespace xtd::net;

char32 xtd::literals::operator""_c(unsigned long long c) {
  return as<char32>(c);
}

char32 xtd::literals::operator""_c(char c) {
  return as<char32>(c);
}

#if defined(__xtd__cpp_lib_char8_t)
char32 xtd::literals::operator""_c(char8 c) {
  return as<char32>(c);
}
#endif

char32 xtd::literals::operator""_c(char16 c) {
  return as<char32>(c);
}

char32 xtd::literals::operator""_c(char32 c) {
  return c;
}

char32 xtd::literals::operator""_c(wchar c) {
  return as<char32>(c);
}
