#include "../../../include/xtd/literals/string.hpp"
#include "../../../include/xtd/string.hpp"

using namespace xtd;

string xtd::literals::operator""_s(const char* s, xtd::size n) {
  return string(s, s + n);
}

string xtd::literals::operator""_s(const char8* s, xtd::size n) {
  return string(s, s + n);
}

string xtd::literals::operator""_s(const char16* s, xtd::size n) {
  return string(std::u16string(s, s + n));
}

string xtd::literals::operator""_s(const char32* s, xtd::size n) {
  return string(std::u32string(s, s + n));
}

string xtd::literals::operator""_s(const wchar* s, xtd::size n) {
  return string(std::wstring(s, s + n));
}

string xtd::literals::operator""_sb(long double s) {
  return string::format("{:b}", s);
}

string xtd::literals::operator""_sb(unsigned long long s) {
  return string::format("{:b}", s);
}

string xtd::literals::operator""_sb2(long double s) {
  return string::format("{:b2}", s);
}

string xtd::literals::operator""_sb2(unsigned long long s) {
  return string::format("{:b2}", s);
}

string xtd::literals::operator""_sb4(long double s) {
  return string::format("{:b4}", s);
}

string xtd::literals::operator""_sb4(unsigned long long s) {
  return string::format("{:b4}", s);
}

string xtd::literals::operator""_sb8(long double s) {
  return string::format("{:b8}", s);
}

string xtd::literals::operator""_sb8(unsigned long long s) {
  return string::format("{:b8}", s);
}

string xtd::literals::operator""_sb16(long double s) {
  return string::format("{:b16}", s);
}

string xtd::literals::operator""_sb16(unsigned long long s) {
  return string::format("{:b16}", s);
}

string xtd::literals::operator""_sb32(long double s) {
  return string::format("{:b32}", s);
}

string xtd::literals::operator""_sb32(unsigned long long s) {
  return string::format("{:b32}", s);
}

string xtd::literals::operator""_sb64(long double s) {
  return string::format("{:b64}", s);
}

string xtd::literals::operator""_sb64(unsigned long long s) {
  return string::format("{:b64}", s);
}

string xtd::literals::operator""_sd(long double s) {
  return string::format("{}", s);
}

string xtd::literals::operator""_sd(unsigned long long s) {
  return string::format("{}", s);
}

string xtd::literals::operator""_sx(long double s) {
  return string::format("{:x}", s);
}

string xtd::literals::operator""_sx(unsigned long long s) {
  return string::format("{:x}", s);
}

string xtd::literals::operator""_sx2(unsigned long long s) {
  return string::format("{:x2}", s);
}

string xtd::literals::operator""_sx4(unsigned long long s) {
  return string::format("{:x4}", s);
}

string xtd::literals::operator""_sx8(unsigned long long s) {
  return string::format("{:x8}", s);
}

string xtd::literals::operator""_sx16(unsigned long long s) {
  return string::format("{:x16}", s);
}

string xtd::literals::operator""_sX(long double s) {
  return string::format("{:X}", s);
}

string xtd::literals::operator""_sX(unsigned long long s) {
  return string::format("{:X}", s);
}

string xtd::literals::operator""_sX2(unsigned long long s) {
  return string::format("{:X2}", s);
}

string xtd::literals::operator""_sX4(unsigned long long s) {
  return string::format("{:X4}", s);
}

string xtd::literals::operator""_sX8(unsigned long long s) {
  return string::format("{:X8}", s);
}

string xtd::literals::operator""_sX16(unsigned long long s) {
  return string::format("{:X16}", s);
}
