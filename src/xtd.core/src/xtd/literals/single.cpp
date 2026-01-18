#include "../../../include/xtd/literals/single.hpp"
#include "../../../include/xtd/as.hpp"

using namespace xtd;

auto xtd::literals::operator""_f(long double n) -> float {
  return as<float>(n);
}

auto xtd::literals::operator""_f(unsigned long long n) -> float {
  return as<float>(n);
}

auto xtd::literals::operator""_f(const char* s, size n) -> float {
  return as<float>(string(s, s + n));
}

auto xtd::literals::operator""_f(const char8* s, size n) -> float {
  return as<float>(string(s, s + n));
}

auto xtd::literals::operator""_f(const char16* s, size n) -> float {
  return as<float>(std::u16string(s, s + n));
}

auto xtd::literals::operator""_f(const char32* s, size n) -> float {
  return as<float>(std::u32string(s, s + n));
}

auto xtd::literals::operator""_f(const wchar* s, size n) -> float {
  return as<float>(std::wstring(s, s + n));
}
