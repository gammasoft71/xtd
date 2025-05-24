/// @file
/// @brief Contains xtd literals.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "time_span.hpp"
#include "types.hpp"
#include "string.hpp"
#define __XTD_STD_INTERNAL__
#include "internal/__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::literals namespace contains all xtd's litterals operators.
  inline namespace literals {
    /// @name Character suffixes
    
    /// @{
    /// @brief Used to convert specified value into char32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 49_c << std::endl;
    /// ```
    char32 operator""_c(unsigned long long c);

    /// @brief Used to convert specified value into char32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 'a'_c << std::endl;
    /// ```
    char32 operator""_c(char c);
    
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Used to convert specified value into char32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 'a'_c << std::endl;
    /// ```
    char32 operator""_c(char8 c);
#endif
    
    /// @brief Used to convert specified value into char32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << u'a'_c << std::endl;
    /// ```
    char32 operator""_c(char16 c);
    
    /// @brief Used to convert specified value into char32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << U'a'_c << std::endl;
    /// ```
    char32 operator""_c(char32 c);
    
    /// @brief Used to convert specified value into char32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << L'a'_c << std::endl;
    /// ```
    char32 operator""_c(wchar c);
    /// @}
    
    /// @name Numeric suffixes
    
    /// @{
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 1.6_b << std::endl;
    /// ```
    xtd::byte operator""_b(long double n);
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 54_b << std::endl;
    /// ```
    xtd::byte operator""_b(unsigned long long n);
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << "125"_b << std::endl;
    /// ```
    xtd::byte operator""_b(const char* s, xtd::size n);
    
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << u8"125"_b << std::endl;
    /// ```
    xtd::byte operator""_b(const char8* s, xtd::size n);
#endif
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << u"125"_b << std::endl;
    /// ```
    xtd::byte operator""_b(const char16* s, xtd::size n);
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << U"125"_b << std::endl;
    /// ```
    xtd::byte operator""_b(const char32* s, xtd::size n);
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << L"125"_b << std::endl;
    /// ```
    xtd::byte operator""_b(const wchar* s, xtd::size n);

    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 1.6_d << std::endl;
    /// ```
    double operator""_d(long double n);
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 54_d << std::endl;
    /// ```
    double operator""_d(unsigned long long n);
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << "125"_d << std::endl;
    /// ```
    double operator""_d(const char* s, xtd::size n);
    
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << u8"125"_d << std::endl;
    /// ```
    double operator""_d(const char8* s, xtd::size n);
#endif
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << u"125"_d << std::endl;
    /// ```
    double operator""_d(const char16* s, xtd::size n);
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << U"125"_d << std::endl;
    /// ```
    double operator""_d(const char32* s, xtd::size n);
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << L"125"_d << std::endl;
    /// ```
    double operator""_d(const wchar* s, xtd::size n);
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 1.6_f << std::endl;
    /// ```
    float operator""_f(long double n);
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 54_f << std::endl;
    /// ```
    float operator""_f(unsigned long long n);
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << "125"_f << std::endl;
    /// ```
    float operator""_f(const char* s, xtd::size n);
    
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << u8"125"_f << std::endl;
    /// ```
    float operator""_f(const char8* s, xtd::size n);
#endif
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << u"125"_f << std::endl;
    /// ```
    float operator""_f(const char16* s, xtd::size n);
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << U"125"_f << std::endl;
    /// ```
    float operator""_f(const char32* s, xtd::size n);
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << L"125"_f << std::endl;
    /// ```
    float operator""_f(const wchar* s, xtd::size n);
    
    /// @brief Used to convert specified value into sbyte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 1.6_i8 << std::endl;
    /// ```
    sbyte operator""_i8(long double n);
    
    /// @brief Used to convert specified value into sbyte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 54_i8 << std::endl;
    /// ```
    sbyte operator""_i8(unsigned long long n);
    
    /// @brief Used to convert specified value into sbyte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << "125"_i8 << std::endl;
    /// ```
    sbyte operator""_i8(const char* s, xtd::size n);
    
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Used to convert specified value into sbyte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << u8"125"_i8 << std::endl;
    /// ```
    sbyte operator""_i8(const char8* s, xtd::size n);
#endif
    
    /// @brief Used to convert specified value into sbyte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << u"125"_i8 << std::endl;
    /// ```
    sbyte operator""_i8(const char16* s, xtd::size n);
    
    /// @brief Used to convert specified value into sbyte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << U"125"_i8 << std::endl;
    /// ```
    sbyte operator""_i8(const char32* s, xtd::size n);
    
    /// @brief Used to convert specified value into sbyte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << L"125"_i8 << std::endl;
    /// ```
    sbyte operator""_i8(const wchar* s, xtd::size n);
    
    /// @brief Used to convert specified value into int16.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 1.6_i16 << std::endl;
    /// ```
    int16 operator""_i16(long double n);
    
    /// @brief Used to convert specified value into int16.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 54_i16 << std::endl;
    /// ```
    int16 operator""_i16(unsigned long long n);
    
    /// @brief Used to convert specified value into int16.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << "125"_i16 << std::endl;
    /// ```
    int16 operator""_i16(const char* s, xtd::size n);
    
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Used to convert specified value into int16.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << u8"125"_i16 << std::endl;
    /// ```
    int16 operator""_i16(const char8* s, xtd::size n);
#endif
    
    /// @brief Used to convert specified value into int16.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << u"125"_i16 << std::endl;
    /// ```
    int16 operator""_i16(const char16* s, xtd::size n);
    
    /// @brief Used to convert specified value into int16.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << U"125"_i16 << std::endl;
    /// ```
    int16 operator""_i16(const char32* s, xtd::size n);
    
    /// @brief Used to convert specified value into int16.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << L"125"_i16 << std::endl;
    /// ```
    int16 operator""_i16(const wchar* s, xtd::size n);
    
    /// @brief Used to convert specified value into int32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 1.6_i32 << std::endl;
    /// ```
    int32 operator""_i32(long double n);
    
    /// @brief Used to convert specified value into int32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 54_i32 << std::endl;
    /// ```
    int32 operator""_i32(unsigned long long n);
    
    /// @brief Used to convert specified value into int32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << "125"_i32 << std::endl;
    /// ```
    int32 operator""_i32(const char* s, xtd::size n);
    
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Used to convert specified value into int32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << u8"125"_i32 << std::endl;
    /// ```
    int32 operator""_i32(const char8* s, xtd::size n);
#endif
    
    /// @brief Used to convert specified value into int32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << u"125"_i32 << std::endl;
    /// ```
    int32 operator""_i32(const char16* s, xtd::size n);
    
    /// @brief Used to convert specified value into int32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << U"125"_i32 << std::endl;
    /// ```
    int32 operator""_i32(const char32* s, xtd::size n);
    
    /// @brief Used to convert specified value into int32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << L"125"_i32 << std::endl;
    /// ```
    int32 operator""_i32(const wchar* s, xtd::size n);
    
    /// @brief Used to convert specified value into int64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 1.6_i64 << std::endl;
    /// ```
    int64 operator""_i64(long double n);
    
    /// @brief Used to convert specified value into int64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 54_i64 << std::endl;
    /// ```
    int64 operator""_i64(unsigned long long n);
    
    /// @brief Used to convert specified value into int64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << "125"_i64 << std::endl;
    /// ```
    int64 operator""_i64(const char* s, xtd::size n);
    
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Used to convert specified value into int64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << u8"125"_i64 << std::endl;
    /// ```
    int64 operator""_i64(const char8* s, xtd::size n);
#endif
    
    /// @brief Used to convert specified value into int64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << u"125"_i64 << std::endl;
    /// ```
    int64 operator""_i64(const char16* s, xtd::size n);
    
    /// @brief Used to convert specified value into int64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << U"125"_i64 << std::endl;
    /// ```
    int64 operator""_i64(const char32* s, xtd::size n);
    
    /// @brief Used to convert specified value into int64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << L"125"_i64 << std::endl;
    /// ```
    int64 operator""_i64(const wchar* s, xtd::size n);

    /// @brief Used to convert specified value into sbyte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 1.6_s8 << std::endl;
    /// ```
    sbyte operator""_s8(long double n);
    
    /// @brief Used to convert specified value into sbyte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 54_s8 << std::endl;
    /// ```
    sbyte operator""_s8(unsigned long long n);
    
    /// @brief Used to convert specified value into sbyte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << "125"_s8 << std::endl;
    /// ```
    sbyte operator""_s8(const char* s, xtd::size n);
    
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Used to convert specified value into sbyte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << u8"125"_s8 << std::endl;
    /// ```
    sbyte operator""_s8(const char8* s, xtd::size n);
#endif
    
    /// @brief Used to convert specified value into sbyte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << u"125"_s8 << std::endl;
    /// ```
    sbyte operator""_s8(const char16* s, xtd::size n);
    
    /// @brief Used to convert specified value into sbyte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << U"125"_s8 << std::endl;
    /// ```
    sbyte operator""_s8(const char32* s, xtd::size n);
    
    /// @brief Used to convert specified value into sbyte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << L"125"_s8 << std::endl;
    /// ```
    sbyte operator""_s8(const wchar* s, xtd::size n);
    
    /// @brief Used to convert specified value into int16.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 1.6_s16 << std::endl;
    /// ```
    int16 operator""_s16(long double n);
    
    /// @brief Used to convert specified value into int16.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 54_s16 << std::endl;
    /// ```
    int16 operator""_s16(unsigned long long n);
    
    /// @brief Used to convert specified value into int16.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << "125"_s16 << std::endl;
    /// ```
    int16 operator""_s16(const char* s, xtd::size n);
    
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Used to convert specified value into int16.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << u8"125"_s16 << std::endl;
    /// ```
    int16 operator""_s16(const char8* s, xtd::size n);
#endif
    
    /// @brief Used to convert specified value into int16.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << u"125"_s16 << std::endl;
    /// ```
    int16 operator""_s16(const char16* s, xtd::size n);
    
    /// @brief Used to convert specified value into int16.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << U"125"_s16 << std::endl;
    /// ```
    int16 operator""_s16(const char32* s, xtd::size n);
    
    /// @brief Used to convert specified value into int16.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << L"125"_s16 << std::endl;
    /// ```
    int16 operator""_s16(const wchar* s, xtd::size n);
    
    /// @brief Used to convert specified value into int32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 1.6_s32 << std::endl;
    /// ```
    int32 operator""_s32(long double n);
    
    /// @brief Used to convert specified value into int32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 54_s32 << std::endl;
    /// ```
    int32 operator""_s32(unsigned long long n);
    
    /// @brief Used to convert specified value into int32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << "125"_s32 << std::endl;
    /// ```
    int32 operator""_s32(const char* s, xtd::size n);
    
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Used to convert specified value into int32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << u8"125"_s32 << std::endl;
    /// ```
    int32 operator""_s32(const char8* s, xtd::size n);
#endif
    
    /// @brief Used to convert specified value into int32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << u"125"_s32 << std::endl;
    /// ```
    int32 operator""_s32(const char16* s, xtd::size n);
    
    /// @brief Used to convert specified value into int32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << U"125"_s32 << std::endl;
    /// ```
    int32 operator""_s32(const char32* s, xtd::size n);
    
    /// @brief Used to convert specified value into int32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << L"125"_s32 << std::endl;
    /// ```
    int32 operator""_s32(const wchar* s, xtd::size n);
    
    /// @brief Used to convert specified value into int64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 1.6_s64 << std::endl;
    /// ```
    int64 operator""_s64(long double n);
    
    /// @brief Used to convert specified value into int64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 54_s64 << std::endl;
    /// ```
    int64 operator""_s64(unsigned long long n);
    
    /// @brief Used to convert specified value into int64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << "125"_s64 << std::endl;
    /// ```
    int64 operator""_s64(const char* s, xtd::size n);
    
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Used to convert specified value into int64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << u8"125"_s64 << std::endl;
    /// ```
    int64 operator""_s64(const char8* s, xtd::size n);
#endif
    
    /// @brief Used to convert specified value into int64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << u"125"_s64 << std::endl;
    /// ```
    int64 operator""_s64(const char16* s, xtd::size n);
    
    /// @brief Used to convert specified value into int64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << U"125"_s64 << std::endl;
    /// ```
    int64 operator""_s64(const char32* s, xtd::size n);
    
    /// @brief Used to convert specified value into int64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << L"125"_s64 << std::endl;
    /// ```
    int64 operator""_s64(const wchar* s, xtd::size n);

    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 1.6_u8 << std::endl;
    /// ```
    xtd::byte operator""_u8(long double n);
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 54_u8 << std::endl;
    /// ```
    xtd::byte operator""_u8(unsigned long long n);
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << "125"_u8 << std::endl;
    /// ```
    xtd::byte operator""_u8(const char* s, xtd::size n);
    
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << u8"125"_u8 << std::endl;
    /// ```
    xtd::byte operator""_u8(const char8* s, xtd::size n);
#endif
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << u"125"_u8 << std::endl;
    /// ```
    xtd::byte operator""_u8(const char16* s, xtd::size n);
    
    /// @brief Used to convert specified value into byte.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << U"125"_u8 << std::endl;
    /// ```
    xtd::byte operator""_u8(const char32* s, xtd::size n);
    
    /// @brief Used to convert specified value into uint16.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << L"125"_u8 << std::endl;
    /// ```
    xtd::byte operator""_u8(const wchar* s, xtd::size n);
    
    /// @brief Used to convert specified value into uint16.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 1.6_u16 << std::endl;
    /// ```
    uint16 operator""_u16(long double n);
    
    /// @brief Used to convert specified value into uint16.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 54_u16 << std::endl;
    /// ```
    uint16 operator""_u16(unsigned long long n);
    
    /// @brief Used to convert specified value into uint16.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << "125"_u16 << std::endl;
    /// ```
    uint16 operator""_u16(const char* s, xtd::size n);
    
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Used to convert specified value into uint16.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << u8"125"_u16 << std::endl;
    /// ```
    uint16 operator""_u16(const char8* s, xtd::size n);
#endif
    
    /// @brief Used to convert specified value into uint16.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << u"125"_u16 << std::endl;
    /// ```
    uint16 operator""_u16(const char16* s, xtd::size n);
    
    /// @brief Used to convert specified value into uint16.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << U"125"_u16 << std::endl;
    /// ```
    uint16 operator""_u16(const char32* s, xtd::size n);
    
    /// @brief Used to convert specified value into uint16.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << L"125"_u16 << std::endl;
    /// ```
    uint16 operator""_u16(const wchar* s, xtd::size n);
    
    /// @brief Used to convert specified value into uint32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 1.6_u32 << std::endl;
    /// ```
    uint32 operator""_u32(long double n);
    
    /// @brief Used to convert specified value into uint32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 54_u32 << std::endl;
    /// ```
    uint32 operator""_u32(unsigned long long n);
    
    /// @brief Used to convert specified value into uint32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << "125"_u32 << std::endl;
    /// ```
    uint32 operator""_u32(const char* s, xtd::size n);
    
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Used to convert specified value into uint32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << u8"125"_u32 << std::endl;
    /// ```
    uint32 operator""_u32(const char8* s, xtd::size n);
#endif
    
    /// @brief Used to convert specified value into uint32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << u"125"_u32 << std::endl;
    /// ```
    uint32 operator""_u32(const char16* s, xtd::size n);
    
    /// @brief Used to convert specified value into uint32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << U"125"_u32 << std::endl;
    /// ```
    uint32 operator""_u32(const char32* s, xtd::size n);
    
    /// @brief Used to convert specified value into uint32.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << L"125"_u32 << std::endl;
    /// ```
    uint32 operator""_u32(const wchar* s, xtd::size n);
    
    /// @brief Used to convert specified value into uint64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 1.6_u64 << std::endl;
    /// ```
    uint64 operator""_u64(long double n);
    
    /// @brief Used to convert specified value into uint64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 54_u64 << std::endl;
    /// ```
    uint64 operator""_u64(unsigned long long n);
    
    /// @brief Used to convert specified value into uint64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << "125"_u64 << std::endl;
    /// ```
    uint64 operator""_u64(const char* s, xtd::size n);
    
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Used to convert specified value into uint64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << u8"125"_u64 << std::endl;
    /// ```
    uint64 operator""_u64(const char8* s, xtd::size n);
#endif
    
    /// @brief Used to convert specified value into uint64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << u"125"_u64 << std::endl;
    /// ```
    uint64 operator""_u64(const char16* s, xtd::size n);
    
    /// @brief Used to convert specified value into uint64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << U"125"_u64 << std::endl;
    /// ```
    uint64 operator""_u64(const char32* s, xtd::size n);
    
    /// @brief Used to convert specified value into uint64.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << L"125"_u64 << std::endl;
    /// ```
    uint64 operator""_u64(const wchar* s, xtd::size n);
   
    /// @brief Used to convert specified value into xtd::size.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 1.6_z << std::endl;
    /// ```
    xtd::size operator""_uz(long double n);
    
    /// @brief Used to convert specified value into xtd::size.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 54_z << std::endl;
    /// ```
    xtd::size operator""_uz(unsigned long long n);
    
    /// @brief Used to convert specified value into xtd::size.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << "125"_z << std::endl;
    /// ```
    xtd::size operator""_uz(const char* s, xtd::size n);
    
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Used to convert specified value into xtd::size.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << u8"125"_z << std::endl;
    /// ```
    xtd::size operator""_uz(const char8* s, xtd::size n);
#endif
    
    /// @brief Used to convert specified value into xtd::size.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << u"125"_z << std::endl;
    /// ```
    xtd::size operator""_uz(const char16* s, xtd::size n);
    
    /// @brief Used to convert specified value into xtd::size.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << U"125"_z << std::endl;
    /// ```
    xtd::size operator""_uz(const char32* s, xtd::size n);
    
    /// @brief Used to convert specified value into xtd::size.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << L"125"_z << std::endl;
    /// ```
    xtd::size operator""_uz(const wchar* s, xtd::size n);
    
    /// @brief Used to convert specified value into signed xtd::size.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 1.6_z << std::endl;
    /// ```
    xtd::size operator""_z(long double n);
    
    /// @brief Used to convert specified value into signed xtd::size.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << 54_z << std::endl;
    /// ```
    xtd::size operator""_z(unsigned long long n);
    
    /// @brief Used to convert specified value into signed xtd::size.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << "125"_z << std::endl;
    /// ```
    xtd::size operator""_z(const char* s, xtd::size n);
    
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Used to convert specified value into signed xtd::size.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << u8"125"_z << std::endl;
    /// ```
    xtd::size operator""_z(const char8* s, xtd::size n);
#endif
    
    /// @brief Used to convert specified value into signed xtd::size.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << u"125"_z << std::endl;
    /// ```
    xtd::size operator""_z(const char16* s, xtd::size n);
    
    /// @brief Used to convert specified value into signed xtd::size.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << U"125"_z << std::endl;
    /// ```
    xtd::size operator""_z(const char32* s, xtd::size n);
    
    /// @brief Used to convert specified value into signed xtd::size.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// std::cout << L"125"_z << std::endl;
    /// ```
    xtd::size operator""_z(const wchar* s, xtd::size n);
    /// @}
    
    /// @name String suffixes
    
    /// @{
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = "This is a "_s + "simple test"_s;
    /// std::cout << s << std::endl;
    /// ```
    xtd::string operator""_s(const char* s, xtd::size n);
    
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = u8"This is a "_s + u8"simple test"_s;
    /// std::cout << s << std::endl;
    /// ```
    xtd::string operator""_s(const char8* s, xtd::size n);
#endif
    
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = U"This is a "_s + U"simple test"_s;
    /// std::cout << s << std::endl;
    /// ```
    xtd::string operator""_s(const char16* s, xtd::size n);
    
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = u"This is a "_s + u"simple test"_s;
    /// std::cout << s << std::endl;
    /// ```
    xtd::string operator""_s(const char32* s, xtd::size n);
    
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = L"This is a "_s + L"simple test"_s;
    /// std::cout << s << std::endl;
    /// ```
    xtd::string operator""_s(const wchar* s, xtd::size n);

    /// @brief Used to convert the specified value to xtd::string with a binary format.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 49_sb;
    /// std::cout << s << std::endl;
    /// ```
    xtd::string operator""_sb(unsigned long long s);
    
    /// @brief Used to convert the specified value to xtd::string with a binary format with two digits.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 49_sb2;
    /// std::cout << s << std::endl;
    /// ```
    xtd::string operator""_sb2(unsigned long long s);
    
    /// @brief Used to convert the specified value to xtd::string with a binary format with four digits.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 49_sb4;
    /// std::cout << s << std::endl;
    /// ```
    xtd::string operator""_sb4(unsigned long long s);
    
    /// @brief Used to convert the specified value to xtd::string with a binary format with eight digits.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 49_sb8;
    /// std::cout << s << std::endl;
    /// ```
    xtd::string operator""_sb8(unsigned long long s);
    
    /// @brief Used to convert the specified value to xtd::string with a binary format with sixteen digits.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 49_sb16;
    /// std::cout << s << std::endl;
    /// ```
    xtd::string operator""_sb16(unsigned long long s);
    
    /// @brief Used to convert the specified value to xtd::string with a binary format with thirty two digits.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 49_sb32;
    /// std::cout << s << std::endl;
    /// ```
    xtd::string operator""_sb32(unsigned long long s);
    
    /// @brief Used to convert the specified value to xtd::string with a binary format with sixty four digits.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 49_sb64;
    /// std::cout << s << std::endl;
    /// ```
    xtd::string operator""_sb64(unsigned long long s);
    
    /// @brief Used to convert the specified value to xtd::string with a decimal format.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 4.9_sd;
    /// std::cout << s << std::endl;
    /// ```
    xtd::string operator""_sd(long double s);
    
    /// @brief Used to convert the specified value to xtd::string with a decimal format.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 49_sd;
    /// std::cout << s << std::endl;
    /// ```
    xtd::string operator""_sd(unsigned long long s);
    
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 49_sx;
    /// std::cout << s << std::endl;
    /// ```
    xtd::string operator""_sx(unsigned long long s);
    
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 49_sx2;
    /// std::cout << s << std::endl;
    /// ```
    xtd::string operator""_sx2(unsigned long long s);
    
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 49_sx4;
    /// std::cout << s << std::endl;
    /// ```
    xtd::string operator""_sx4(unsigned long long s);
    
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 49_s;
    /// std::cout << s << std::endl;
    /// ```
    xtd::string operator""_sx8(unsigned long long s);
    
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 49_sx;
    /// std::cout << s << std::endl;
    /// ```
    xtd::string operator""_sX(unsigned long long s);
    
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 49_sx2;
    /// std::cout << s << std::endl;
    /// ```
    xtd::string operator""_sX2(unsigned long long s);
    
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 49_sx4;
    /// std::cout << s << std::endl;
    /// ```
    xtd::string operator""_sX4(unsigned long long s);
    
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 49_s;
    /// std::cout << s << std::endl;
    /// ```
    xtd::string operator""_sX8(unsigned long long s);
    /// @}
    
    /// @name String with translation suffixes
    
    /// @{
    /// @brief Used to translate specified string into locale.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core translate literals
    const char* operator""_t(const char* s, xtd::size n) noexcept;
    
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Used to translate specified string into locale.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core translate literals
    xtd::string operator""_t(const char8* s, xtd::size n) noexcept;
#endif
    
    /// @brief Used to translate specified string into locale.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core translate literals
    xtd::string operator""_t(const char16* s, xtd::size n) noexcept;
    
    /// @brief Used to translate specified string into locale.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core translate literals
    xtd::string operator""_t(const char32* s, xtd::size n) noexcept;
    
    /// @brief Used to translate specified string into locale.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core translate literals
    xtd::string operator""_t(const wchar* s, xtd::size n) noexcept;
    /// @}

    /// @name Time span suffixes
    
    /// @{
    /// @brief Used to convert the specified value as hours to xtd::time_span.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::time_span ts = 10_h;
    /// std::cout << ts << std::endl;
    /// ```
    xtd::time_span operator""_h(unsigned long long s);
    
    /// @brief Used to convert the specified value as minutes to xtd::time_span.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::time_span ts = 25_m;
    /// std::cout << ts << std::endl;
    /// ```
    xtd::time_span operator""_m(unsigned long long s);
    
    /// @brief Used to convert the specified value as minutes to xtd::time_span.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::time_span ts = 25_m;
    /// std::cout << ts << std::endl;
    /// ```
    xtd::time_span operator""_min(unsigned long long s);
    
    /// @brief Used to convert the specified value as millisconds to xtd::time_span.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::time_span ts = 25_m;
    /// std::cout << ts << std::endl;
    /// ```
    xtd::time_span operator""_ms(unsigned long long s);
    
    /// @brief Used to convert the specified value as nanoseconds to xtd::time_span.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::time_span ts = 25_m;
    /// std::cout << ts << std::endl;
    /// ```
    xtd::time_span operator""_ns(unsigned long long s);
    
    /// @brief Used to convert the specified value as seconds to xtd::time_span.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::time_span ts = 49_s;
    /// std::cout << ts << std::endl;
    /// ```
    xtd::time_span operator""_s(unsigned long long s);

    /// @brief Used to convert the specified value as tiks to xtd::time_span.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::time_span ts = 49_s;
    /// std::cout << ts << std::endl;
    /// ```
    xtd::time_span operator""_t(unsigned long long s);

    /// @brief Used to convert the specified value as microseconds to xtd::time_span.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::time_span ts = 49_s;
    /// std::cout << ts << std::endl;
    /// ```
    xtd::time_span operator""_us(unsigned long long s);
  }
  /// @}
}
