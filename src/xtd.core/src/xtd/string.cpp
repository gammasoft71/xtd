#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/types>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include "../../include/xtd/string.hpp"
#include "../../include/xtd/typeof.hpp"
#include "../../include/xtd/argument_exception.hpp"
#include "../../include/xtd/convert_string.hpp"
#include "../../include/xtd/format_exception.hpp"
#include "../../include/xtd/hash_code.hpp"
#include "../../include/xtd/is.hpp"
#include "../../include/xtd/null_pointer_exception.hpp"
//#include "../../include/xtd/collections/generic/hasher.hpp"
#include "../../include/xtd/diagnostics/stack_frame.hpp"
#include <iomanip>

using namespace xtd;
using namespace xtd::collections::generic;

string xtd::to_string(int val) {
  return string::format("{}", val);
}

string xtd::to_string(unsigned val) {
  return string::format("{}", val);
}

string xtd::to_string(long val) {
  return string::format("{}", val);
}

string xtd::to_string(unsigned long val) {
  return string::format("{}", val);
}

string xtd::to_string(long long val) {
  return string::format("{}", val);
}

string xtd::to_string(unsigned long long val) {
  return string::format("{}", val);
}

string xtd::to_string(float val) {
  return string::format("{}", val);
}

string xtd::to_string(double val) {
  return string::format("{}", val);
}

string xtd::to_string(long double val) {
  return string::format("{}", val);
}

string xtd::literals::operator""_s(const char* s, xtd::size n) {
  return string(s, s + n);
}

#if defined(__xtd__cpp_lib_char8_t)
string xtd::literals::operator""_s(const char8* s, xtd::size n) {
  return string(s, s + n);
}
#endif

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
