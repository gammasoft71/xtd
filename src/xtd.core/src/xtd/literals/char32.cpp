#include "../../../include/xtd/literals/char32.hpp"
#include "../../../include/xtd/as.hpp"

using namespace xtd;

char32 xtd::literals::operator""_c(unsigned long long c) {
  return as<char32>(c);
}

char32 xtd::literals::operator""_c(char c) {
  return as<char32>(c);
}

char32 xtd::literals::operator""_c(char8 c) {
  return as<char32>(c);
}

char32 xtd::literals::operator""_c(char16 c) {
  return as<char32>(c);
}

char32 xtd::literals::operator""_c(char32 c) {
  return c;
}

char32 xtd::literals::operator""_c(wchar c) {
  return as<char32>(c);
}
