#include "../../include/xtd/as.h"
#include "../../include/xtd/parse.h"
#include "../../include/xtd/translator.h"

using namespace std;
using namespace xtd;

byte_t xtd::operator""_b(long double n) {
  return as<byte_t>(n);
}

byte_t xtd::operator""_b(unsigned long long n) {
  return as<byte_t>(n);
}

byte_t xtd::operator""_b(const char* s, size_t n) {
  return as<byte_t>(ustring(s, s + n));
}

byte_t xtd::operator""_b(const char8_t* s, size_t n) {
  return as<byte_t>(ustring(s, s + n));
}

byte_t xtd::operator""_b(const char16_t* s, size_t n) {
  return as<byte_t>(u16string(s, s + n));
}

byte_t xtd::operator""_b(const char32_t* s, size_t n) {
  return as<byte_t>(u32string(s, s + n));
}

byte_t xtd::operator""_b(const wchar_t* s, size_t n) {
  return as<byte_t>(wstring(s, s + n));
}

double xtd::operator""_d(long double n) {
  return as<double>(n);
}

double xtd::operator""_d(unsigned long long n) {
  return as<double>(n);
}

double xtd::operator""_d(const char* s, size_t n) {
  return as<double>(ustring(s, s + n));
}

double xtd::operator""_d(const char8_t* s, size_t n) {
  return as<double>(ustring(s, s + n));
}

double xtd::operator""_d(const char16_t* s, size_t n) {
  return as<double>(u16string(s, s + n));
}

double xtd::operator""_d(const char32_t* s, size_t n) {
  return as<double>(u32string(s, s + n));
}

double xtd::operator""_d(const wchar_t* s, size_t n) {
  return as<double>(wstring(s, s + n));
}

float xtd::operator""_f(long double n) {
  return as<float>(n);
}

float xtd::operator""_f(unsigned long long n) {
  return as<float>(n);
}

float xtd::operator""_f(const char* s, size_t n) {
  return as<float>(ustring(s, s + n));
}

float xtd::operator""_f(const char8_t* s, size_t n) {
  return as<float>(ustring(s, s + n));
}

float xtd::operator""_f(const char16_t* s, size_t n) {
  return as<float>(u16string(s, s + n));
}

float xtd::operator""_f(const char32_t* s, size_t n) {
  return as<float>(u32string(s, s + n));
}

float xtd::operator""_f(const wchar_t* s, size_t n) {
  return as<float>(wstring(s, s + n));
}

char32_t xtd::operator""_c(char c) {
  return as<char32_t>(c);
}

char32_t xtd::operator""_c(char16_t c) {
  return as<char32_t>(c);
}

char32_t xtd::operator""_c(char32_t c) {
  return c;
}

char32_t xtd::operator""_c(wchar_t c) {
  return as<char32_t>(c);
}

char32_t xtd::operator""_c(unsigned long long c) {
  return as<char32_t>(c);
}

ustring xtd::operator""_s(const char* s, size_t n) {
  return ustring(s, s + n);
}

ustring xtd::operator""_s(const char8_t* s, size_t n) {
  return ustring(s, s + n);
}

ustring xtd::operator""_s(const char16_t* s, size_t n) {
  return ustring(u16string(s, s + n));
}

ustring xtd::operator""_s(const char32_t* s, size_t n) {
  return ustring(u32string(s, s + n));
}

ustring xtd::operator""_s(const wchar_t* s, size_t n) {
  return ustring(wstring(s, s + n));
}

ustring xtd::operator""_s(long double s) {
  return ustring::format("{}", s);
}

ustring xtd::operator""_s(unsigned long long s) {
  return ustring::format("{}", s);
}

ustring xtd::operator""_sb(unsigned long long s) {
  return ustring::format("{:b}", s);
}

ustring xtd::operator""_sb2(unsigned long long s) {
  return ustring::format("{:b2}", s);
}

ustring xtd::operator""_sb4(unsigned long long s) {
  return ustring::format("{:b4}", s);
}

ustring xtd::operator""_sb8(unsigned long long s) {
  return ustring::format("{:b8}", s);
}

ustring xtd::operator""_sb16(unsigned long long s) {
  return ustring::format("{:b16}", s);
}

ustring xtd::operator""_sb32(unsigned long long s) {
  return ustring::format("{:b32}", s);
}

ustring xtd::operator""_sb64(unsigned long long s) {
  return ustring::format("{:b64}", s);
}

ustring xtd::operator""_sx(unsigned long long s) {
  return ustring::format("{:x}", s);
}

ustring xtd::operator""_sx2(unsigned long long s) {
  return ustring::format("{:x2}", s);
}

ustring xtd::operator""_sx4(unsigned long long s) {
  return ustring::format("{:x4}", s);
}

ustring xtd::operator""_sx8(unsigned long long s) {
  return ustring::format("{:x8}", s);
}

ustring xtd::operator""_sX(unsigned long long s) {
  return ustring::format("{:X}", s);
}

ustring xtd::operator""_sX2(unsigned long long s) {
  return ustring::format("{:X2}", s);
}

ustring xtd::operator""_sX4(unsigned long long s) {
  return ustring::format("{:X4}", s);
}

ustring xtd::operator""_sX8(unsigned long long s) {
  return ustring::format("{:X8}", s);
}

int8_t xtd::operator""_s8(long double n) {
  return as<int8_t>(n);
}

int8_t xtd::operator""_s8(unsigned long long n) {
  return as<int8_t>(n);
}

int8_t xtd::operator""_s8(const char* s, size_t n) {
  return as<int8_t>(ustring(s, s + n));
}

int8_t xtd::operator""_s8(const char8_t* s, size_t n) {
  return as<int8_t>(ustring(s, s + n));
}

int8_t xtd::operator""_s8(const char16_t* s, size_t n) {
  return as<int8_t>(u16string(s, s + n));
}

int8_t xtd::operator""_s8(const char32_t* s, size_t n) {
  return as<int8_t>(u32string(s, s + n));
}

int8_t xtd::operator""_s8(const wchar_t* s, size_t n) {
  return as<int8_t>(wstring(s, s + n));
}

int16_t xtd::operator""_s16(long double n) {
  return as<int16_t>(n);
}

int16_t xtd::operator""_s16(unsigned long long n) {
  return as<int16_t>(n);
}

int16_t xtd::operator""_s16(const char* s, size_t n) {
  return as<int16_t>(ustring(s, s + n));
}

int16_t xtd::operator""_s16(const char8_t* s, size_t n) {
  return as<int16_t>(ustring(s, s + n));
}

int16_t xtd::operator""_s16(const char16_t* s, size_t n) {
  return as<int16_t>(u16string(s, s + n));
}

int16_t xtd::operator""_s16(const char32_t* s, size_t n) {
  return as<int16_t>(u32string(s, s + n));
}

int16_t xtd::operator""_s16(const wchar_t* s, size_t n) {
  return as<int16_t>(wstring(s, s + n));
}

int32_t xtd::operator""_s32(long double n) {
  return as<int32_t>(n);
}

int32_t xtd::operator""_s32(unsigned long long n) {
  return as<int32_t>(n);
}

int32_t xtd::operator""_s32(const char* s, size_t n) {
  return as<int32_t>(ustring(s, s + n));
}

int32_t xtd::operator""_s32(const char8_t* s, size_t n) {
  return as<int32_t>(ustring(s, s + n));
}

int32_t xtd::operator""_s32(const char16_t* s, size_t n) {
  return as<int32_t>(u16string(s, s + n));
}

int32_t xtd::operator""_s32(const char32_t* s, size_t n) {
  return as<int32_t>(u32string(s, s + n));
}

int32_t xtd::operator""_s32(const wchar_t* s, size_t n) {
  return as<int32_t>(wstring(s, s + n));
}

int64_t xtd::operator""_s64(long double n) {
  return as<int64_t>(n);
}

int64_t xtd::operator""_s64(unsigned long long n) {
  return as<int64_t>(n);
}

int64_t xtd::operator""_s64(const char* s, size_t n) {
  return as<int64_t>(ustring(s, s + n));
}

int64_t xtd::operator""_s64(const char8_t* s, size_t n) {
  return as<int64_t>(ustring(s, s + n));
}

int64_t xtd::operator""_s64(const char16_t* s, size_t n) {
  return as<int64_t>(u16string(s, s + n));
}

int64_t xtd::operator""_s64(const char32_t* s, size_t n) {
  return as<int64_t>(u32string(s, s + n));
}

int64_t xtd::operator""_s64(const wchar_t* s, size_t n) {
  return as<int64_t>(wstring(s, s + n));
}

uint8_t xtd::operator""_u8(long double n) {
  return as<uint8_t>(n);
}

uint8_t xtd::operator""_u8(unsigned long long n) {
  return as<uint8_t>(n);
}

uint8_t xtd::operator""_u8(const char* s, size_t n) {
  return as<uint8_t>(ustring(s, s + n));
}

uint8_t xtd::operator""_u8(const char8_t* s, size_t n) {
  return as<uint8_t>(ustring(s, s + n));
}

uint8_t xtd::operator""_u8(const char16_t* s, size_t n) {
  return as<uint8_t>(u16string(s, s + n));
}

uint8_t xtd::operator""_u8(const char32_t* s, size_t n) {
  return as<uint8_t>(u32string(s, s + n));
}

uint8_t xtd::operator""_u8(const wchar_t* s, size_t n) {
  return as<uint8_t>(wstring(s, s + n));
}

uint16_t xtd::operator""_u16(long double n) {
  return as<uint16_t>(n);
}

uint16_t xtd::operator""_u16(unsigned long long n) {
  return as<uint16_t>(n);
}

uint16_t xtd::operator""_u16(const char* s, size_t n) {
  return as<uint16_t>(ustring(s, s + n));
}

uint16_t xtd::operator""_u16(const char8_t* s, size_t n) {
  return as<uint16_t>(ustring(s, s + n));
}

uint16_t xtd::operator""_u16(const char16_t* s, size_t n) {
  return as<uint16_t>(u16string(s, s + n));
}

uint16_t xtd::operator""_u16(const char32_t* s, size_t n) {
  return as<uint16_t>(u32string(s, s + n));
}

uint16_t xtd::operator""_u16(const wchar_t* s, size_t n) {
  return as<uint16_t>(wstring(s, s + n));
}

uint32_t xtd::operator""_u32(long double n) {
  return as<uint32_t>(n);
}

uint32_t xtd::operator""_u32(unsigned long long n) {
  return as<uint32_t>(n);
}

uint32_t xtd::operator""_u32(const char* s, size_t n) {
  return as<uint32_t>(ustring(s, s + n));
}

uint32_t xtd::operator""_u32(const char8_t* s, size_t n) {
  return as<uint32_t>(ustring(s, s + n));
}

uint32_t xtd::operator""_u32(const char16_t* s, size_t n) {
  return as<uint32_t>(u16string(s, s + n));
}

uint32_t xtd::operator""_u32(const char32_t* s, size_t n) {
  return as<uint32_t>(u32string(s, s + n));
}

uint32_t xtd::operator""_u32(const wchar_t* s, size_t n) {
  return as<uint32_t>(wstring(s, s + n));
}

uint64_t xtd::operator""_u64(long double n) {
  return as<uint64_t>(n);
}

uint64_t xtd::operator""_u64(unsigned long long n) {
  return as<uint64_t>(n);
}

uint64_t xtd::operator""_u64(const char* s, size_t n) {
  return parse<uint64_t>(ustring(s, s + n));
}

uint64_t xtd::operator""_u64(const char8_t* s, size_t n) {
  return parse<uint64_t>(ustring(s, s + n));
}

uint64_t xtd::operator""_u64(const char16_t* s, size_t n) {
  return parse<uint64_t>(u16string(s, s + n));
}

uint64_t xtd::operator""_u64(const char32_t* s, size_t n) {
  return parse<uint64_t>(u32string(s, s + n));
}

uint64_t xtd::operator""_u64(const wchar_t* s, size_t n) {
  return parse<uint64_t>(wstring(s, s + n));
}

const char* xtd::operator""_t(const char* s, size_t n) {
  return translator::translate(s);
}

ustring xtd::operator""_t(const char8_t* s, size_t n) {
  return translator::translate(u8string(s, s + n));
}

ustring xtd::operator""_t(const char16_t* s, size_t n) {
  return translator::translate(u16string(s, s + n));
}

ustring xtd::operator""_t(const char32_t* s, size_t n) {
  return translator::translate(u32string(s, s + n));
}

ustring xtd::operator""_t(const wchar_t* s, size_t n) {
  return translator::translate(wstring(s, s + n));
}
