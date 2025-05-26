#include "../../include/xtd/literals.hpp"
#include "../../include/xtd/as.hpp"
#include "../../include/xtd/translator.hpp"
#include "../../include/xtd/net/ip_address.hpp"

using namespace xtd;
using namespace xtd::net;

char32 xtd::literals::operator""_c(unsigned long long c) {
  return as<char32>(c);
}

char32 xtd::literals::operator""_c(char c) {
  return as<char32>(c);
}

#if defined(__xtd__cpp_lib_char8_t)
char32 xtd::literals::operator""_c(char8 c) {
  return as<char32>(c);
}
#endif

char32 xtd::literals::operator""_c(char16 c) {
  return as<char32>(c);
}

char32 xtd::literals::operator""_c(char32 c) {
  return c;
}

char32 xtd::literals::operator""_c(wchar c) {
  return as<char32>(c);
}

guid xtd::literals::operator""_guid(const char* s, xtd::size n) {
  return guid(string {s});
}

#if defined(__xtd__cpp_lib_char8_t)
guid xtd::literals::operator""_guid(const char8* s, xtd::size n) {
  return guid(string {s});
}
#endif

guid xtd::literals::operator""_guid(const char16* s, xtd::size n) {
  return guid(string {s});
}

guid xtd::literals::operator""_guid(const char32* s, xtd::size n) {
  return guid(string {s});
}

guid xtd::literals::operator""_guid(const wchar* s, xtd::size n) {
  return guid(string {s});
}

ip_address xtd::literals::operator""_ip(const char* s, xtd::size n) {
  return ip_address::parse(string {s});
}

#if defined(__xtd__cpp_lib_char8_t)
ip_address xtd::literals::operator""_ip(const char8* s, xtd::size n) {
  return ip_address::parse(string {s});
}
#endif

ip_address xtd::literals::operator""_ip(const char16* s, xtd::size n) {
  return ip_address::parse(string {s});
}

ip_address xtd::literals::operator""_ip(const char32* s, xtd::size n) {
  return ip_address::parse(string {s});
}

ip_address xtd::literals::operator""_ip(const wchar* s, xtd::size n) {
  return ip_address::parse(string {s});
}

xtd::byte xtd::literals::operator""_b(long double n) {
  return as<xtd::byte>(n);
}

xtd::byte xtd::literals::operator""_b(unsigned long long n) {
  return as<xtd::byte>(n);
}

xtd::byte xtd::literals::operator""_b(const char* s, xtd::size n) {
  return as<xtd::byte>(string(s, s + n));
}

#if defined(__xtd__cpp_lib_char8_t)
xtd::byte xtd::literals::operator""_b(const char8* s, xtd::size n) {
  return as<xtd::byte>(string(s, s + n));
}
#endif

xtd::byte xtd::literals::operator""_b(const char16* s, xtd::size n) {
  return as<xtd::byte>(std::u16string(s, s + n));
}

xtd::byte xtd::literals::operator""_b(const char32* s, xtd::size n) {
  return as<xtd::byte>(std::u32string(s, s + n));
}

xtd::byte xtd::literals::operator""_b(const wchar* s, xtd::size n) {
  return as<xtd::byte>(std::wstring(s, s + n));
}

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

float xtd::literals::operator""_f(long double n) {
  return as<float>(n);
}

float xtd::literals::operator""_f(unsigned long long n) {
  return as<float>(n);
}

float xtd::literals::operator""_f(const char* s, xtd::size n) {
  return as<float>(string(s, s + n));
}

#if defined(__xtd__cpp_lib_char8_t)
float xtd::literals::operator""_f(const char8* s, xtd::size n) {
  return as<float>(string(s, s + n));
}
#endif

float xtd::literals::operator""_f(const char16* s, xtd::size n) {
  return as<float>(std::u16string(s, s + n));
}

float xtd::literals::operator""_f(const char32* s, xtd::size n) {
  return as<float>(std::u32string(s, s + n));
}

float xtd::literals::operator""_f(const wchar* s, xtd::size n) {
  return as<float>(std::wstring(s, s + n));
}

sbyte xtd::literals::operator""_i8(long double n) {
  return as<sbyte>(n);
}

sbyte xtd::literals::operator""_i8(unsigned long long n) {
  return as<sbyte>(n);
}

sbyte xtd::literals::operator""_i8(const char* s, xtd::size n) {
  return as<sbyte>(string(s, s + n));
}

#if defined(__xtd__cpp_lib_char8_t)
sbyte xtd::literals::operator""_i8(const char8* s, xtd::size n) {
  return as<sbyte>(string(s, s + n));
}
#endif

sbyte xtd::literals::operator""_i8(const char16* s, xtd::size n) {
  return as<sbyte>(std::u16string(s, s + n));
}

sbyte xtd::literals::operator""_i8(const char32* s, xtd::size n) {
  return as<sbyte>(std::u32string(s, s + n));
}

sbyte xtd::literals::operator""_i8(const wchar* s, xtd::size n) {
  return as<sbyte>(std::wstring(s, s + n));
}

int16 xtd::literals::operator""_i16(long double n) {
  return as<int16>(n);
}

int16 xtd::literals::operator""_i16(unsigned long long n) {
  return as<int16>(n);
}

int16 xtd::literals::operator""_i16(const char* s, xtd::size n) {
  return as<int16>(string(s, s + n));
}

#if defined(__xtd__cpp_lib_char8_t)
int16 xtd::literals::operator""_i16(const char8* s, xtd::size n) {
  return as<int16>(string(s, s + n));
}
#endif

int16 xtd::literals::operator""_i16(const char16* s, xtd::size n) {
  return as<int16>(std::u16string(s, s + n));
}

int16 xtd::literals::operator""_i16(const char32* s, xtd::size n) {
  return as<int16>(std::u32string(s, s + n));
}

int16 xtd::literals::operator""_i16(const wchar* s, xtd::size n) {
  return as<int16>(std::wstring(s, s + n));
}

int32 xtd::literals::operator""_i32(long double n) {
  return as<int32>(n);
}

int32 xtd::literals::operator""_i32(unsigned long long n) {
  return as<int32>(n);
}

int32 xtd::literals::operator""_i32(const char* s, xtd::size n) {
  return as<int32>(string(s, s + n));
}

#if defined(__xtd__cpp_lib_char8_t)
int32 xtd::literals::operator""_i32(const char8* s, xtd::size n) {
  return as<int32>(string(s, s + n));
}
#endif

int32 xtd::literals::operator""_i32(const char16* s, xtd::size n) {
  return as<int32>(std::u16string(s, s + n));
}

int32 xtd::literals::operator""_i32(const char32* s, xtd::size n) {
  return as<int32>(std::u32string(s, s + n));
}

int32 xtd::literals::operator""_i32(const wchar* s, xtd::size n) {
  return as<int32>(std::wstring(s, s + n));
}

int64 xtd::literals::operator""_i64(long double n) {
  return as<int64>(n);
}

int64 xtd::literals::operator""_i64(unsigned long long n) {
  return as<int64>(n);
}

int64 xtd::literals::operator""_i64(const char* s, xtd::size n) {
  return as<int64>(string(s, s + n));
}

#if defined(__xtd__cpp_lib_char8_t)
int64 xtd::literals::operator""_i64(const char8* s, xtd::size n) {
  return as<int64>(string(s, s + n));
}
#endif

int64 xtd::literals::operator""_i64(const char16* s, xtd::size n) {
  return as<int64>(std::u16string(s, s + n));
}

int64 xtd::literals::operator""_i64(const char32* s, xtd::size n) {
  return as<int64>(std::u32string(s, s + n));
}

int64 xtd::literals::operator""_i64(const wchar* s, xtd::size n) {
  return as<int64>(std::wstring(s, s + n));
}

sbyte xtd::literals::operator""_s8(long double n) {
  return as<sbyte>(n);
}

sbyte xtd::literals::operator""_s8(unsigned long long n) {
  return as<sbyte>(n);
}

sbyte xtd::literals::operator""_s8(const char* s, xtd::size n) {
  return as<sbyte>(string(s, s + n));
}

#if defined(__xtd__cpp_lib_char8_t)
sbyte xtd::literals::operator""_s8(const char8* s, xtd::size n) {
  return as<sbyte>(string(s, s + n));
}
#endif

sbyte xtd::literals::operator""_s8(const char16* s, xtd::size n) {
  return as<sbyte>(std::u16string(s, s + n));
}

sbyte xtd::literals::operator""_s8(const char32* s, xtd::size n) {
  return as<sbyte>(std::u32string(s, s + n));
}

sbyte xtd::literals::operator""_s8(const wchar* s, xtd::size n) {
  return as<sbyte>(std::wstring(s, s + n));
}

int16 xtd::literals::operator""_s16(long double n) {
  return as<int16>(n);
}

int16 xtd::literals::operator""_s16(unsigned long long n) {
  return as<int16>(n);
}

int16 xtd::literals::operator""_s16(const char* s, xtd::size n) {
  return as<int16>(string(s, s + n));
}

#if defined(__xtd__cpp_lib_char8_t)
int16 xtd::literals::operator""_s16(const char8* s, xtd::size n) {
  return as<int16>(string(s, s + n));
}
#endif

int16 xtd::literals::operator""_s16(const char16* s, xtd::size n) {
  return as<int16>(std::u16string(s, s + n));
}

int16 xtd::literals::operator""_s16(const char32* s, xtd::size n) {
  return as<int16>(std::u32string(s, s + n));
}

int16 xtd::literals::operator""_s16(const wchar* s, xtd::size n) {
  return as<int16>(std::wstring(s, s + n));
}

int32 xtd::literals::operator""_s32(long double n) {
  return as<int32>(n);
}

int32 xtd::literals::operator""_s32(unsigned long long n) {
  return as<int32>(n);
}

int32 xtd::literals::operator""_s32(const char* s, xtd::size n) {
  return as<int32>(string(s, s + n));
}

#if defined(__xtd__cpp_lib_char8_t)
int32 xtd::literals::operator""_s32(const char8* s, xtd::size n) {
  return as<int32>(string(s, s + n));
}
#endif

int32 xtd::literals::operator""_s32(const char16* s, xtd::size n) {
  return as<int32>(std::u16string(s, s + n));
}

int32 xtd::literals::operator""_s32(const char32* s, xtd::size n) {
  return as<int32>(std::u32string(s, s + n));
}

int32 xtd::literals::operator""_s32(const wchar* s, xtd::size n) {
  return as<int32>(std::wstring(s, s + n));
}

int64 xtd::literals::operator""_s64(long double n) {
  return as<int64>(n);
}

int64 xtd::literals::operator""_s64(unsigned long long n) {
  return as<int64>(n);
}

int64 xtd::literals::operator""_s64(const char* s, xtd::size n) {
  return as<int64>(string(s, s + n));
}

#if defined(__xtd__cpp_lib_char8_t)
int64 xtd::literals::operator""_s64(const char8* s, xtd::size n) {
  return as<int64>(string(s, s + n));
}
#endif

int64 xtd::literals::operator""_s64(const char16* s, xtd::size n) {
  return as<int64>(std::u16string(s, s + n));
}

int64 xtd::literals::operator""_s64(const char32* s, xtd::size n) {
  return as<int64>(std::u32string(s, s + n));
}

int64 xtd::literals::operator""_s64(const wchar* s, xtd::size n) {
  return as<int64>(std::wstring(s, s + n));
}

xtd::byte xtd::literals::operator""_u8(long double n) {
  return as<xtd::byte>(n);
}

xtd::byte xtd::literals::operator""_u8(unsigned long long n) {
  return as<xtd::byte>(n);
}

xtd::byte xtd::literals::operator""_u8(const char* s, xtd::size n) {
  return as<xtd::byte>(string(s, s + n));
}

#if defined(__xtd__cpp_lib_char8_t)
xtd::byte xtd::literals::operator""_u8(const char8* s, xtd::size n) {
  return as<xtd::byte>(string(s, s + n));
}
#endif

xtd::byte xtd::literals::operator""_u8(const char16* s, xtd::size n) {
  return as<xtd::byte>(std::u16string(s, s + n));
}

xtd::byte xtd::literals::operator""_u8(const char32* s, xtd::size n) {
  return as<xtd::byte>(std::u32string(s, s + n));
}

xtd::byte xtd::literals::operator""_u8(const wchar* s, xtd::size n) {
  return as<xtd::byte>(std::wstring(s, s + n));
}

uint16 xtd::literals::operator""_u16(long double n) {
  return as<uint16>(n);
}

uint16 xtd::literals::operator""_u16(unsigned long long n) {
  return as<uint16>(n);
}

uint16 xtd::literals::operator""_u16(const char* s, xtd::size n) {
  return as<uint16>(string(s, s + n));
}

#if defined(__xtd__cpp_lib_char8_t)
uint16 xtd::literals::operator""_u16(const char8* s, xtd::size n) {
  return as<uint16>(string(s, s + n));
}
#endif

uint16 xtd::literals::operator""_u16(const char16* s, xtd::size n) {
  return as<uint16>(std::u16string(s, s + n));
}

uint16 xtd::literals::operator""_u16(const char32* s, xtd::size n) {
  return as<uint16>(std::u32string(s, s + n));
}

uint16 xtd::literals::operator""_u16(const wchar* s, xtd::size n) {
  return as<uint16>(std::wstring(s, s + n));
}

uint32 xtd::literals::operator""_u32(long double n) {
  return as<uint32>(n);
}

uint32 xtd::literals::operator""_u32(unsigned long long n) {
  return as<uint32>(n);
}

uint32 xtd::literals::operator""_u32(const char* s, xtd::size n) {
  return as<uint32>(string(s, s + n));
}

#if defined(__xtd__cpp_lib_char8_t)
uint32 xtd::literals::operator""_u32(const char8* s, xtd::size n) {
  return as<uint32>(string(s, s + n));
}
#endif

uint32 xtd::literals::operator""_u32(const char16* s, xtd::size n) {
  return as<uint32>(std::u16string(s, s + n));
}

uint32 xtd::literals::operator""_u32(const char32* s, xtd::size n) {
  return as<uint32>(std::u32string(s, s + n));
}

uint32 xtd::literals::operator""_u32(const wchar* s, xtd::size n) {
  return as<uint32>(std::wstring(s, s + n));
}

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

xtd::size xtd::literals::operator""_uz(long double n) {
  return as<xtd::size>(n);
}

xtd::size xtd::literals::operator""_uz(unsigned long long n) {
  return as<xtd::size>(n);
}

xtd::size xtd::literals::operator""_uz(const char* s, xtd::size n) {
  return as<xtd::size>(string(s, s + n));
}

#if defined(__xtd__cpp_lib_char8_t)
xtd::size xtd::literals::operator""_uz(const char8* s, xtd::size n) {
  return as<xtd::size>(string(s, s + n));
}
#endif

xtd::size xtd::literals::operator""_uz(const char16* s, xtd::size n) {
  return as<xtd::size>(std::u16string(s, s + n));
}

xtd::size xtd::literals::operator""_uz(const char32* s, xtd::size n) {
  return as<xtd::size>(std::u32string(s, s + n));
}

xtd::size xtd::literals::operator""_uz(const wchar* s, xtd::size n) {
  return as<xtd::size>(std::wstring(s, s + n));
}

xtd::size xtd::literals::operator""_z(long double n) {
  return as<xtd::size>(n);
}

xtd::size xtd::literals::operator""_z(unsigned long long n) {
  return as<xtd::size>(n);
}

xtd::size xtd::literals::operator""_z(const char* s, xtd::size n) {
  return as<xtd::size>(string(s, s + n));
}

#if defined(__xtd__cpp_lib_char8_t)
xtd::size xtd::literals::operator""_z(const char8* s, xtd::size n) {
  return as<xtd::size>(string(s, s + n));
}
#endif

xtd::size xtd::literals::operator""_z(const char16* s, xtd::size n) {
  return as<xtd::size>(std::u16string(s, s + n));
}

xtd::size xtd::literals::operator""_z(const char32* s, xtd::size n) {
  return as<xtd::size>(std::u32string(s, s + n));
}

xtd::size xtd::literals::operator""_z(const wchar* s, xtd::size n) {
  return as<xtd::size>(std::wstring(s, s + n));
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

const char* xtd::literals::operator""_t(const char* s, xtd::size n) noexcept {
  return translator::translate(s);
}

#if defined(__xtd__cpp_lib_char8_t)
string xtd::literals::operator""_t(const char8* s, xtd::size n) noexcept {
  return translator::translate(std::u8string(s, s + n));
}
#endif

string xtd::literals::operator""_t(const char16* s, xtd::size n) noexcept {
  return translator::translate(std::u16string(s, s + n));
}

string xtd::literals::operator""_t(const char32* s, xtd::size n) noexcept {
  return translator::translate(std::u32string(s, s + n));
}

string xtd::literals::operator""_t(const wchar* s, xtd::size n) noexcept {
  return translator::translate(std::wstring(s, s + n));
}

time_span xtd::literals::operator""_h(unsigned long long s) {
  return xtd::time_span {std::chrono::duration_cast<xtd::ticks>(std::chrono::hours(s))};
}

time_span xtd::literals::operator""_m(unsigned long long s) {
  return xtd::time_span {std::chrono::duration_cast<xtd::ticks>(std::chrono::minutes(s))};
}

time_span xtd::literals::operator""_min(unsigned long long s) {
  return xtd::time_span {std::chrono::duration_cast<xtd::ticks>(std::chrono::minutes(s))};
}

time_span xtd::literals::operator""_ms(unsigned long long s) {
  return xtd::time_span {std::chrono::duration_cast<xtd::ticks>(std::chrono::milliseconds(s))};
}

time_span xtd::literals::operator""_ns(unsigned long long s) {
  return xtd::time_span {std::chrono::duration_cast<xtd::ticks>(std::chrono::nanoseconds(s))};
}

time_span xtd::literals::operator""_s(unsigned long long s) {
  return xtd::time_span {std::chrono::duration_cast<xtd::ticks>(std::chrono::seconds(s))};
}

time_span xtd::literals::operator""_t(unsigned long long s) {
  return xtd::time_span {xtd::ticks(s)};
}

time_span xtd::literals::operator""_us(unsigned long long s) {
  return xtd::time_span {std::chrono::duration_cast<xtd::ticks>(std::chrono::microseconds(s))};
}
