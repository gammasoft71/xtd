#include "../../../include/xtd/literals/char32.hpp"
#include "../../../include/xtd/as.hpp"

using namespace xtd;

auto xtd::literals::operator""_c(unsigned long long c) -> char32 {
  return as<char32>(c);
}

auto xtd::literals::operator""_c(char c) -> char32 {
  return as<char32>(c);
}

auto xtd::literals::operator""_c(char8 c) -> char32 {
  return as<char32>(c);
}

auto xtd::literals::operator""_c(char16 c) -> char32 {
  return as<char32>(c);
}

auto xtd::literals::operator""_c(char32 c) -> char32 {
  return c;
}

auto xtd::literals::operator""_c(wchar c) -> char32 {
  return as<char32>(c);
}
