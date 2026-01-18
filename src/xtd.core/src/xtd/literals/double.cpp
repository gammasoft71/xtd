#include "../../../include/xtd/literals/double.hpp"
#include "../../../include/xtd/as.hpp"

using namespace xtd;

auto xtd::literals::operator""_d(long double n) -> double {
  return as<double>(n);
}

auto xtd::literals::operator""_d(unsigned long long n) -> double {
  return as<double>(n);
}

auto xtd::literals::operator""_d(const char* s, size n) -> double {
  return as<double>(string(s, s + n));
}

auto xtd::literals::operator""_d(const char8* s, size n) -> double {
  return as<double>(string(s, s + n));
}

auto xtd::literals::operator""_d(const char16* s, size n) -> double {
  return as<double>(std::u16string(s, s + n));
}

auto xtd::literals::operator""_d(const char32* s, size n) -> double {
  return as<double>(std::u32string(s, s + n));
}

auto xtd::literals::operator""_d(const wchar* s, size n) -> double {
  return as<double>(std::wstring(s, s + n));
}
