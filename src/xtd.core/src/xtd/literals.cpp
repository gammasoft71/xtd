#include "../../include/xtd/as.h"
#include "../../include/xtd/translator.h"

using namespace std;
using namespace xtd;

xtd::byte xtd::operator""_b(long double n) {
  return as<xtd::byte>(n);
}

xtd::byte xtd::operator""_b(unsigned long long n) {
  return as<xtd::byte>(n);
}

xtd::byte xtd::operator""_b(const char* s, size_t n) {
  return as<xtd::byte>(ustring(s, s + n));
}

#if defined(__cpp_lib_char8_t)
xtd::byte xtd::operator""_b(const char8* s, size_t n) {
  return as<xtd::byte>(ustring(s, s + n));
}
#endif

xtd::byte xtd::operator""_b(const char16* s, size_t n) {
  return as<xtd::byte>(u16string(s, s + n));
}

xtd::byte xtd::operator""_b(const char32* s, size_t n) {
  return as<xtd::byte>(u32string(s, s + n));
}

xtd::byte xtd::operator""_b(const wchar* s, size_t n) {
  return as<xtd::byte>(wstring(s, s + n));
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

#if defined(__cpp_lib_char8_t)
double xtd::operator""_d(const char8* s, size_t n) {
  return as<double>(ustring(s, s + n));
}
#endif

double xtd::operator""_d(const char16* s, size_t n) {
  return as<double>(u16string(s, s + n));
}

double xtd::operator""_d(const char32* s, size_t n) {
  return as<double>(u32string(s, s + n));
}

double xtd::operator""_d(const wchar* s, size_t n) {
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

#if defined(__cpp_lib_char8_t)
float xtd::operator""_f(const char8* s, size_t n) {
  return as<float>(ustring(s, s + n));
}
#endif

float xtd::operator""_f(const char16* s, size_t n) {
  return as<float>(u16string(s, s + n));
}

float xtd::operator""_f(const char32* s, size_t n) {
  return as<float>(u32string(s, s + n));
}

float xtd::operator""_f(const wchar* s, size_t n) {
  return as<float>(wstring(s, s + n));
}

char32 xtd::operator""_c(char c) {
  return as<char32>(c);
}

char32 xtd::operator""_c(char16 c) {
  return as<char32>(c);
}

char32 xtd::operator""_c(char32 c) {
  return c;
}

char32 xtd::operator""_c(wchar c) {
  return as<char32>(c);
}

char32 xtd::operator""_c(unsigned long long c) {
  return as<char32>(c);
}

xtd::time_span xtd::operator""_h(unsigned long long s) {
  return xtd::time_span {std::chrono::duration_cast<xtd::ticks>(std::chrono::hours(s))};
}

xtd::time_span xtd::operator""_m(unsigned long long s) {
  return xtd::time_span {std::chrono::duration_cast<xtd::ticks>(std::chrono::minutes(s))};
}

xtd::time_span xtd::operator""_min(unsigned long long s) {
  return xtd::time_span {std::chrono::duration_cast<xtd::ticks>(std::chrono::minutes(s))};
}

xtd::time_span xtd::operator""_ms(unsigned long long s) {
  return xtd::time_span {std::chrono::duration_cast<xtd::ticks>(std::chrono::milliseconds(s))};
}

xtd::time_span xtd::operator""_ns(unsigned long long s) {
  return xtd::time_span {std::chrono::duration_cast<xtd::ticks>(std::chrono::nanoseconds(s))};
}

ustring xtd::operator""_s(const char* s, size_t n) {
  return ustring(s, s + n);
}

#if defined(__cpp_lib_char8_t)
ustring xtd::operator""_s(const char8* s, size_t n) {
  return ustring(s, s + n);
}
#endif

ustring xtd::operator""_s(const char16* s, size_t n) {
  return ustring(u16string(s, s + n));
}

ustring xtd::operator""_s(const char32* s, size_t n) {
  return ustring(u32string(s, s + n));
}

ustring xtd::operator""_s(const wchar* s, size_t n) {
  return ustring(wstring(s, s + n));
}

xtd::time_span xtd::operator""_s(unsigned long long s) {
  return xtd::time_span {std::chrono::duration_cast<xtd::ticks>(std::chrono::seconds(s))};
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

ustring xtd::operator""_sd(long double s) {
  return ustring::format("{}", s);
}

ustring xtd::operator""_sd(unsigned long long s) {
  return ustring::format("{}", s);
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

sbyte xtd::operator""_s8(long double n) {
  return as<sbyte>(n);
}

sbyte xtd::operator""_s8(unsigned long long n) {
  return as<sbyte>(n);
}

sbyte xtd::operator""_s8(const char* s, size_t n) {
  return as<sbyte>(ustring(s, s + n));
}

#if defined(__cpp_lib_char8_t)
sbyte xtd::operator""_s8(const char8* s, size_t n) {
  return as<sbyte>(ustring(s, s + n));
}
#endif

sbyte xtd::operator""_s8(const char16* s, size_t n) {
  return as<sbyte>(u16string(s, s + n));
}

sbyte xtd::operator""_s8(const char32* s, size_t n) {
  return as<sbyte>(u32string(s, s + n));
}

sbyte xtd::operator""_s8(const wchar* s, size_t n) {
  return as<sbyte>(wstring(s, s + n));
}

int16 xtd::operator""_s16(long double n) {
  return as<int16>(n);
}

int16 xtd::operator""_s16(unsigned long long n) {
  return as<int16>(n);
}

int16 xtd::operator""_s16(const char* s, size_t n) {
  return as<int16>(ustring(s, s + n));
}

#if defined(__cpp_lib_char8_t)
int16 xtd::operator""_s16(const char8* s, size_t n) {
  return as<int16>(ustring(s, s + n));
}
#endif

int16 xtd::operator""_s16(const char16* s, size_t n) {
  return as<int16>(u16string(s, s + n));
}

int16 xtd::operator""_s16(const char32* s, size_t n) {
  return as<int16>(u32string(s, s + n));
}

int16 xtd::operator""_s16(const wchar* s, size_t n) {
  return as<int16>(wstring(s, s + n));
}

int32 xtd::operator""_s32(long double n) {
  return as<int32>(n);
}

int32 xtd::operator""_s32(unsigned long long n) {
  return as<int32>(n);
}

int32 xtd::operator""_s32(const char* s, size_t n) {
  return as<int32>(ustring(s, s + n));
}

#if defined(__cpp_lib_char8_t)
int32 xtd::operator""_s32(const char8* s, size_t n) {
  return as<int32>(ustring(s, s + n));
}
#endif

int32 xtd::operator""_s32(const char16* s, size_t n) {
  return as<int32>(u16string(s, s + n));
}

int32 xtd::operator""_s32(const char32* s, size_t n) {
  return as<int32>(u32string(s, s + n));
}

int32 xtd::operator""_s32(const wchar* s, size_t n) {
  return as<int32>(wstring(s, s + n));
}

int64 xtd::operator""_s64(long double n) {
  return as<int64>(n);
}

int64 xtd::operator""_s64(unsigned long long n) {
  return as<int64>(n);
}

int64 xtd::operator""_s64(const char* s, size_t n) {
  return as<int64>(ustring(s, s + n));
}

#if defined(__cpp_lib_char8_t)
int64 xtd::operator""_s64(const char8* s, size_t n) {
  return as<int64>(ustring(s, s + n));
}
#endif

int64 xtd::operator""_s64(const char16* s, size_t n) {
  return as<int64>(u16string(s, s + n));
}

int64 xtd::operator""_s64(const char32* s, size_t n) {
  return as<int64>(u32string(s, s + n));
}

int64 xtd::operator""_s64(const wchar* s, size_t n) {
  return as<int64>(wstring(s, s + n));
}

size_t xtd::operator""_sz(long double n) {
  return as<size_t>(n);
}

size_t xtd::operator""_sz(unsigned long long n) {
  return as<size_t>(n);
}

size_t xtd::operator""_sz(const char* s, size_t n) {
  return as<size_t>(ustring(s, s + n));
}

#if defined(__cpp_lib_char8_t)
size_t xtd::operator""_sz(const char8* s, size_t n) {
  return as<size_t>(ustring(s, s + n));
}
#endif

size_t xtd::operator""_sz(const char16* s, size_t n) {
  return as<size_t>(u16string(s, s + n));
}

size_t xtd::operator""_sz(const char32* s, size_t n) {
  return as<size_t>(u32string(s, s + n));
}

size_t xtd::operator""_sz(const wchar* s, size_t n) {
  return as<size_t>(wstring(s, s + n));
}

const char* xtd::operator""_t(const char* s, size_t n) noexcept {
  return translator::translate(s);
}

#if defined(__cpp_lib_char8_t)
ustring xtd::operator""_t(const char8* s, size_t n) noexcept {
  return translator::translate(u8string(s, s + n));
}
#endif

ustring xtd::operator""_t(const char16* s, size_t n) noexcept {
  return translator::translate(u16string(s, s + n));
}

ustring xtd::operator""_t(const char32* s, size_t n) noexcept {
  return translator::translate(u32string(s, s + n));
}

ustring xtd::operator""_t(const wchar* s, size_t n) noexcept {
  return translator::translate(wstring(s, s + n));
}

xtd::time_span xtd::operator""_t(unsigned long long s) {
  return xtd::time_span {xtd::ticks(s)};
}

xtd::byte xtd::operator""_u8(long double n) {
  return as<xtd::byte>(n);
}

xtd::byte xtd::operator""_u8(unsigned long long n) {
  return as<xtd::byte>(n);
}

xtd::byte xtd::operator""_u8(const char* s, size_t n) {
  return as<xtd::byte>(ustring(s, s + n));
}

#if defined(__cpp_lib_char8_t)
xtd::byte xtd::operator""_u8(const char8* s, size_t n) {
  return as<xtd::byte>(ustring(s, s + n));
}
#endif

xtd::byte xtd::operator""_u8(const char16* s, size_t n) {
  return as<xtd::byte>(u16string(s, s + n));
}

xtd::byte xtd::operator""_u8(const char32* s, size_t n) {
  return as<xtd::byte>(u32string(s, s + n));
}

xtd::byte xtd::operator""_u8(const wchar* s, size_t n) {
  return as<xtd::byte>(wstring(s, s + n));
}

uint16 xtd::operator""_u16(long double n) {
  return as<uint16>(n);
}

uint16 xtd::operator""_u16(unsigned long long n) {
  return as<uint16>(n);
}

uint16 xtd::operator""_u16(const char* s, size_t n) {
  return as<uint16>(ustring(s, s + n));
}

#if defined(__cpp_lib_char8_t)
uint16 xtd::operator""_u16(const char8* s, size_t n) {
  return as<uint16>(ustring(s, s + n));
}
#endif

uint16 xtd::operator""_u16(const char16* s, size_t n) {
  return as<uint16>(u16string(s, s + n));
}

uint16 xtd::operator""_u16(const char32* s, size_t n) {
  return as<uint16>(u32string(s, s + n));
}

uint16 xtd::operator""_u16(const wchar* s, size_t n) {
  return as<uint16>(wstring(s, s + n));
}

uint32 xtd::operator""_u32(long double n) {
  return as<uint32>(n);
}

uint32 xtd::operator""_u32(unsigned long long n) {
  return as<uint32>(n);
}

uint32 xtd::operator""_u32(const char* s, size_t n) {
  return as<uint32>(ustring(s, s + n));
}

#if defined(__cpp_lib_char8_t)
uint32 xtd::operator""_u32(const char8* s, size_t n) {
  return as<uint32>(ustring(s, s + n));
}
#endif

uint32 xtd::operator""_u32(const char16* s, size_t n) {
  return as<uint32>(u16string(s, s + n));
}

uint32 xtd::operator""_u32(const char32* s, size_t n) {
  return as<uint32>(u32string(s, s + n));
}

uint32 xtd::operator""_u32(const wchar* s, size_t n) {
  return as<uint32>(wstring(s, s + n));
}

uint64 xtd::operator""_u64(long double n) {
  return as<uint64>(n);
}

uint64 xtd::operator""_u64(unsigned long long n) {
  return as<uint64>(n);
}

uint64 xtd::operator""_u64(const char* s, size_t n) {
  return as<uint64>(ustring(s, s + n));
}

#if defined(__cpp_lib_char8_t)
uint64 xtd::operator""_u64(const char8* s, size_t n) {
  return as<uint64>(ustring(s, s + n));
}
#endif

uint64 xtd::operator""_u64(const char16* s, size_t n) {
  return as<uint64>(u16string(s, s + n));
}

uint64 xtd::operator""_u64(const char32* s, size_t n) {
  return as<uint64>(u32string(s, s + n));
}

uint64 xtd::operator""_u64(const wchar* s, size_t n) {
  return as<uint64>(wstring(s, s + n));
}

xtd::time_span xtd::operator""_us(unsigned long long s) {
  return xtd::time_span {std::chrono::duration_cast<xtd::ticks>(std::chrono::microseconds(s))};
}
