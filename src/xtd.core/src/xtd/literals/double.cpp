#include "../../../include/xtd/literals/double.hpp"
#include "../../../include/xtd/as.hpp"

using namespace xtd;

double xtd::literals::operator""_d(long double n) {
  return as<double>(n);
}

double xtd::literals::operator""_d(unsigned long long n) {
  return as<double>(n);
}

double xtd::literals::operator""_d(const char* s, xtd::size n) {
  return as<double>(string(s, s + n));
}

#if defined(__xtd__cpp_lib_char8_t)
double xtd::literals::operator""_d(const char8* s, xtd::size n) {
  return as<double>(string(s, s + n));
}
#endif

double xtd::literals::operator""_d(const char16* s, xtd::size n) {
  return as<double>(std::u16string(s, s + n));
}

double xtd::literals::operator""_d(const char32* s, xtd::size n) {
  return as<double>(std::u32string(s, s + n));
}

double xtd::literals::operator""_d(const wchar* s, xtd::size n) {
  return as<double>(std::wstring(s, s + n));
}
