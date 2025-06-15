#include "../../../include/xtd/literals/single.hpp"
#include "../../../include/xtd/as.hpp"

using namespace xtd;

float xtd::literals::operator""_f(long double n) {
  return as<float>(n);
}

float xtd::literals::operator""_f(unsigned long long n) {
  return as<float>(n);
}

float xtd::literals::operator""_f(const char* s, xtd::size n) {
  return as<float>(string(s, s + n));
}

float xtd::literals::operator""_f(const char8* s, xtd::size n) {
  return as<float>(string(s, s + n));
}

float xtd::literals::operator""_f(const char16* s, xtd::size n) {
  return as<float>(std::u16string(s, s + n));
}

float xtd::literals::operator""_f(const char32* s, xtd::size n) {
  return as<float>(std::u32string(s, s + n));
}

float xtd::literals::operator""_f(const wchar* s, xtd::size n) {
  return as<float>(std::wstring(s, s + n));
}
