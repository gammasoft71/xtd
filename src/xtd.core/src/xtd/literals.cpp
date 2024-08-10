#include "../../include/xtd/as.h"
#include "../../include/xtd/translator.h"

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

#if defined(__xtd__cpp_lib_char8_t)
xtd::byte xtd::operator""_b(const char8* s, size_t n) {
  return as<xtd::byte>(ustring(s, s + n));
}
#endif

xtd::byte xtd::operator""_b(const char16* s, size_t n) {
  return as<xtd::byte>(std::u16string(s, s + n));
}

xtd::byte xtd::operator""_b(const char32* s, size_t n) {
  return as<xtd::byte>(std::u32string(s, s + n));
}

xtd::byte xtd::operator""_b(const wchar* s, size_t n) {
  return as<xtd::byte>(std::wstring(s, s + n));
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

#if defined(__xtd__cpp_lib_char8_t)
double xtd::operator""_d(const char8* s, size_t n) {
  return as<double>(ustring(s, s + n));
}
#endif

double xtd::operator""_d(const char16* s, size_t n) {
  return as<double>(std::u16string(s, s + n));
}

double xtd::operator""_d(const char32* s, size_t n) {
  return as<double>(std::u32string(s, s + n));
}

double xtd::operator""_d(const wchar* s, size_t n) {
  return as<double>(std::wstring(s, s + n));
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

#if defined(__xtd__cpp_lib_char8_t)
float xtd::operator""_f(const char8* s, size_t n) {
  return as<float>(ustring(s, s + n));
}
#endif

float xtd::operator""_f(const char16* s, size_t n) {
  return as<float>(std::u16string(s, s + n));
}

float xtd::operator""_f(const char32* s, size_t n) {
  return as<float>(std::u32string(s, s + n));
}

float xtd::operator""_f(const wchar* s, size_t n) {
  return as<float>(std::wstring(s, s + n));
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

#if defined(__xtd__cpp_lib_char8_t)
ustring xtd::operator""_s(const char8* s, size_t n) {
  return ustring(s, s + n);
}
#endif

ustring xtd::operator""_s(const char16* s, size_t n) {
  return ustring(std::u16string(s, s + n));
}

ustring xtd::operator""_s(const char32* s, size_t n) {
  return ustring(std::u32string(s, s + n));
}

ustring xtd::operator""_s(const wchar* s, size_t n) {
  return ustring(std::wstring(s, s + n));
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

#if defined(__xtd__cpp_lib_char8_t)
sbyte xtd::operator""_s8(const char8* s, size_t n) {
  return as<sbyte>(ustring(s, s + n));
}
#endif

sbyte xtd::operator""_s8(const char16* s, size_t n) {
  return as<sbyte>(std::u16string(s, s + n));
}

sbyte xtd::operator""_s8(const char32* s, size_t n) {
  return as<sbyte>(std::u32string(s, s + n));
}

sbyte xtd::operator""_s8(const wchar* s, size_t n) {
  return as<sbyte>(std::wstring(s, s + n));
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

#if defined(__xtd__cpp_lib_char8_t)
int16 xtd::operator""_s16(const char8* s, size_t n) {
  return as<int16>(ustring(s, s + n));
}
#endif

int16 xtd::operator""_s16(const char16* s, size_t n) {
  return as<int16>(std::u16string(s, s + n));
}

int16 xtd::operator""_s16(const char32* s, size_t n) {
  return as<int16>(std::u32string(s, s + n));
}

int16 xtd::operator""_s16(const wchar* s, size_t n) {
  return as<int16>(std::wstring(s, s + n));
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

#if defined(__xtd__cpp_lib_char8_t)
int32 xtd::operator""_s32(const char8* s, size_t n) {
  return as<int32>(ustring(s, s + n));
}
#endif

int32 xtd::operator""_s32(const char16* s, size_t n) {
  return as<int32>(std::u16string(s, s + n));
}

int32 xtd::operator""_s32(const char32* s, size_t n) {
  return as<int32>(std::u32string(s, s + n));
}

int32 xtd::operator""_s32(const wchar* s, size_t n) {
  return as<int32>(std::wstring(s, s + n));
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

#if defined(__xtd__cpp_lib_char8_t)
int64 xtd::operator""_s64(const char8* s, size_t n) {
  return as<int64>(ustring(s, s + n));
}
#endif

int64 xtd::operator""_s64(const char16* s, size_t n) {
  return as<int64>(std::u16string(s, s + n));
}

int64 xtd::operator""_s64(const char32* s, size_t n) {
  return as<int64>(std::u32string(s, s + n));
}

int64 xtd::operator""_s64(const wchar* s, size_t n) {
  return as<int64>(std::wstring(s, s + n));
}

const char* xtd::operator""_t(const char* s, size_t n) noexcept {
  return translator::translate(s);
}

#if defined(__xtd__cpp_lib_char8_t)
ustring xtd::operator""_t(const char8* s, size_t n) noexcept {
  return translator::translate(std::u8string(s, s + n));
}
#endif

ustring xtd::operator""_t(const char16* s, size_t n) noexcept {
  return translator::translate(std::u16string(s, s + n));
}

ustring xtd::operator""_t(const char32* s, size_t n) noexcept {
  return translator::translate(std::u32string(s, s + n));
}

ustring xtd::operator""_t(const wchar* s, size_t n) noexcept {
  return translator::translate(std::wstring(s, s + n));
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

#if defined(__xtd__cpp_lib_char8_t)
xtd::byte xtd::operator""_u8(const char8* s, size_t n) {
  return as<xtd::byte>(ustring(s, s + n));
}
#endif

xtd::byte xtd::operator""_u8(const char16* s, size_t n) {
  return as<xtd::byte>(std::u16string(s, s + n));
}

xtd::byte xtd::operator""_u8(const char32* s, size_t n) {
  return as<xtd::byte>(std::u32string(s, s + n));
}

xtd::byte xtd::operator""_u8(const wchar* s, size_t n) {
  return as<xtd::byte>(std::wstring(s, s + n));
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

#if defined(__xtd__cpp_lib_char8_t)
uint16 xtd::operator""_u16(const char8* s, size_t n) {
  return as<uint16>(ustring(s, s + n));
}
#endif

uint16 xtd::operator""_u16(const char16* s, size_t n) {
  return as<uint16>(std::u16string(s, s + n));
}

uint16 xtd::operator""_u16(const char32* s, size_t n) {
  return as<uint16>(std::u32string(s, s + n));
}

uint16 xtd::operator""_u16(const wchar* s, size_t n) {
  return as<uint16>(std::wstring(s, s + n));
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

#if defined(__xtd__cpp_lib_char8_t)
uint32 xtd::operator""_u32(const char8* s, size_t n) {
  return as<uint32>(ustring(s, s + n));
}
#endif

uint32 xtd::operator""_u32(const char16* s, size_t n) {
  return as<uint32>(std::u16string(s, s + n));
}

uint32 xtd::operator""_u32(const char32* s, size_t n) {
  return as<uint32>(std::u32string(s, s + n));
}

uint32 xtd::operator""_u32(const wchar* s, size_t n) {
  return as<uint32>(std::wstring(s, s + n));
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

#if defined(__xtd__cpp_lib_char8_t)
uint64 xtd::operator""_u64(const char8* s, size_t n) {
  return as<uint64>(ustring(s, s + n));
}
#endif

uint64 xtd::operator""_u64(const char16* s, size_t n) {
  return as<uint64>(std::u16string(s, s + n));
}

uint64 xtd::operator""_u64(const char32* s, size_t n) {
  return as<uint64>(std::u32string(s, s + n));
}

uint64 xtd::operator""_u64(const wchar* s, size_t n) {
  return as<uint64>(std::wstring(s, s + n));
}

xtd::time_span xtd::operator""_us(unsigned long long s) {
  return xtd::time_span {std::chrono::duration_cast<xtd::ticks>(std::chrono::microseconds(s))};
}

size_t xtd::operator""_uz(long double n) {
  return as<size_t>(n);
}

size_t xtd::operator""_uz(unsigned long long n) {
  return as<size_t>(n);
}

size_t xtd::operator""_uz(const char* s, size_t n) {
  return as<size_t>(ustring(s, s + n));
}

#if defined(__xtd__cpp_lib_char8_t)
size_t xtd::operator""_uz(const char8* s, size_t n) {
  return as<size_t>(ustring(s, s + n));
}
#endif

size_t xtd::operator""_uz(const char16* s, size_t n) {
  return as<size_t>(std::u16string(s, s + n));
}

size_t xtd::operator""_uz(const char32* s, size_t n) {
  return as<size_t>(std::u32string(s, s + n));
}

size_t xtd::operator""_uz(const wchar* s, size_t n) {
  return as<size_t>(std::wstring(s, s + n));
}

size_t xtd::operator""_z(long double n) {
  return as<size_t>(n);
}

size_t xtd::operator""_z(unsigned long long n) {
  return as<size_t>(n);
}

size_t xtd::operator""_z(const char* s, size_t n) {
  return as<size_t>(ustring(s, s + n));
}

#if defined(__xtd__cpp_lib_char8_t)
size_t xtd::operator""_z(const char8* s, size_t n) {
  return as<size_t>(ustring(s, s + n));
}
#endif

size_t xtd::operator""_z(const char16* s, size_t n) {
  return as<size_t>(std::u16string(s, s + n));
}

size_t xtd::operator""_z(const char32* s, size_t n) {
  return as<size_t>(std::u32string(s, s + n));
}

size_t xtd::operator""_z(const wchar* s, size_t n) {
  return as<size_t>(std::wstring(s, s + n));
}
