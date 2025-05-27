#include "../../include/xtd/numeric_literals.hpp"
#include "../../include/xtd/as.hpp"

using namespace xtd;

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
