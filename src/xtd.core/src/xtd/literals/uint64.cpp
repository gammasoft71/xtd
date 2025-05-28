#include "../../../include/xtd/literals/uint64.hpp"
#include "../../../include/xtd/as.hpp"

using namespace xtd;


uint64 xtd::literals::operator""_u64(long double n) {
  return as<uint64>(n);
}

uint64 xtd::literals::operator""_u64(unsigned long long n) {
  return as<uint64>(n);
}

uint64 xtd::literals::operator""_u64(const char* s, xtd::size n) {
  return as<uint64>(string(s, s + n));
}

#if defined(__xtd__cpp_lib_char8_t)
uint64 xtd::literals::operator""_u64(const char8* s, xtd::size n) {
  return as<uint64>(string(s, s + n));
}
#endif

uint64 xtd::literals::operator""_u64(const char16* s, xtd::size n) {
  return as<uint64>(std::u16string(s, s + n));
}

uint64 xtd::literals::operator""_u64(const char32* s, xtd::size n) {
  return as<uint64>(std::u32string(s, s + n));
}

uint64 xtd::literals::operator""_u64(const wchar* s, xtd::size n) {
  return as<uint64>(std::wstring(s, s + n));
}
