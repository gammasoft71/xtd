/// @file
/// @brief Contains xtd literals.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "time_span.h"
#include "types.h"
#include "ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 1.6_b << std::endl;
  /// @endcode
  xtd::byte operator""_b(long double n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 54_b << std::endl;
  /// @endcode
  xtd::byte operator""_b(unsigned long long n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << "125"_b << std::endl;
  /// @endcode
  xtd::byte operator""_b(const char* s, size_t n);
  
#if defined(__cpp_lib_char8_t)
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << u8"125"_b << std::endl;
  /// @endcode
  xtd::byte operator""_b(const char8* s, size_t n);
#endif
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << u"125"_b << std::endl;
  /// @endcode
  xtd::byte operator""_b(const char16* s, size_t n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << U"125"_b << std::endl;
  /// @endcode
  xtd::byte operator""_b(const char32* s, size_t n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << L"125"_b << std::endl;
  /// @endcode
  xtd::byte operator""_b(const wchar* s, size_t n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 1.6_d << std::endl;
  /// @endcode
  double operator""_d(long double n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 54_d << std::endl;
  /// @endcode
  double operator""_d(unsigned long long n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << "125"_d << std::endl;
  /// @endcode
  double operator""_d(const char* s, size_t n);
  
#if defined(__cpp_lib_char8_t)
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << u8"125"_d << std::endl;
  /// @endcode
  double operator""_d(const char8* s, size_t n);
#endif
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << u"125"_d << std::endl;
  /// @endcode
  double operator""_d(const char16* s, size_t n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << U"125"_d << std::endl;
  /// @endcode
  double operator""_d(const char32* s, size_t n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << L"125"_d << std::endl;
  /// @endcode
  double operator""_d(const wchar* s, size_t n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 1.6_f << std::endl;
  /// @endcode
  float operator""_f(long double n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 54_f << std::endl;
  /// @endcode
  float operator""_f(unsigned long long n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << "125"_f << std::endl;
  /// @endcode
  float operator""_f(const char* s, size_t n);
  
#if defined(__cpp_lib_char8_t)
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << u8"125"_f << std::endl;
  /// @endcode
  float operator""_f(const char8* s, size_t n);
#endif
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << u"125"_f << std::endl;
  /// @endcode
  float operator""_f(const char16* s, size_t n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << U"125"_f << std::endl;
  /// @endcode
  float operator""_f(const char32* s, size_t n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << L"125"_f << std::endl;
  /// @endcode
  float operator""_f(const wchar* s, size_t n);
  
  /// @brief Used to convert specified value into char32._t
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 'a'_c << std::endl;
  /// @endcode
  char32 operator""_c(char c);
  
  /// @brief Used to convert specified value into char32._t
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << u'a'_c << std::endl;
  /// @endcode
  char32 operator""_c(char16 c);
  
  /// @brief Used to convert specified value into char32._t
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << U'a'_c << std::endl;
  /// @endcode
  char32 operator""_c(char32 c);
  
  /// @brief Used to convert specified value into char32._t
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << L'a'_c << std::endl;
  /// @endcode
  char32 operator""_c(wchar c);
  
  /// @brief Used to convert specified value into char32._t
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 49_c << std::endl;
  /// @endcode
  char32 operator""_c(unsigned long long c);
  
  /// @brief Used to convert the specified value as hours to xtd::time_span.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// xtd::time_span ts = 10_h;
  /// std::cout << ts << std::endl;
  /// @endcode
  xtd::time_span operator""_h(unsigned long long s);
  
  /// @brief Used to convert the specified value as minutes to xtd::time_span.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// xtd::time_span ts = 25_m;
  /// std::cout << ts << std::endl;
  /// @endcode
  xtd::time_span operator""_m(unsigned long long s);
  
  /// @brief Used to convert the specified value as minutes to xtd::time_span.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// xtd::time_span ts = 25_m;
  /// std::cout << ts << std::endl;
  /// @endcode
  xtd::time_span operator""_min(unsigned long long s);
  
  /// @brief Used to convert the specified value as millisconds to xtd::time_span.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// xtd::time_span ts = 25_m;
  /// std::cout << ts << std::endl;
  /// @endcode
  xtd::time_span operator""_ms(unsigned long long s);
  
  /// @brief Used to convert the specified value as nanoseconds to xtd::time_span.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// xtd::time_span ts = 25_m;
  /// std::cout << ts << std::endl;
  /// @endcode
  xtd::time_span operator""_ns(unsigned long long s);
  
  /// @brief Used to convert specified value into xtd::ustring.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// xtd::ustring s = "This is a "_s + "simple test"_s;
  /// std::cout << s << std::endl;
  /// @endcode
  xtd::ustring operator""_s(const char* s, size_t n);
  
#if defined(__cpp_lib_char8_t)
  /// @brief Used to convert specified value into xtd::ustring.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// xtd::ustring s = u8"This is a "_s + u8"simple test"_s;
  /// std::cout << s << std::endl;
  /// @endcode
  xtd::ustring operator""_s(const char8* s, size_t n);
#endif
  
  /// @brief Used to convert specified value into xtd::ustring.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// xtd::ustring s = U"This is a "_s + U"simple test"_s;
  /// std::cout << s << std::endl;
  /// @endcode
  xtd::ustring operator""_s(const char16* s, size_t n);
  
  /// @brief Used to convert specified value into xtd::ustring.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// xtd::ustring s = u"This is a "_s + u"simple test"_s;
  /// std::cout << s << std::endl;
  /// @endcode
  xtd::ustring operator""_s(const char32* s, size_t n);
  
  /// @brief Used to convert specified value into xtd::ustring.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// xtd::ustring s = L"This is a "_s + L"simple test"_s;
  /// std::cout << s << std::endl;
  /// @endcode
  xtd::ustring operator""_s(const wchar* s, size_t n);
  
  /// @brief Used to convert the specified value as seconds to xtd::time_span.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// xtd::time_span ts = 49_s;
  /// std::cout << ts << std::endl;
  /// @endcode
  xtd::time_span operator""_s(unsigned long long s);
  
  /// @brief Used to convert the specified value to xtd::ustring with a binary format.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// xtd::ustring s = 49_sb;
  /// std::cout << s << std::endl;
  /// @endcode
  xtd::ustring operator""_sb(unsigned long long s);
  
  /// @brief Used to convert the specified value to xtd::ustring with a binary format with two digits.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// xtd::ustring s = 49_sb2;
  /// std::cout << s << std::endl;
  /// @endcode
  xtd::ustring operator""_sb2(unsigned long long s);
  
  /// @brief Used to convert the specified value to xtd::ustring with a binary format with four digits.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// xtd::ustring s = 49_sb4;
  /// std::cout << s << std::endl;
  /// @endcode
  xtd::ustring operator""_sb4(unsigned long long s);
  
  /// @brief Used to convert the specified value to xtd::ustring with a binary format with eight digits.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// xtd::ustring s = 49_sb8;
  /// std::cout << s << std::endl;
  /// @endcode
  xtd::ustring operator""_sb8(unsigned long long s);
  
  /// @brief Used to convert the specified value to xtd::ustring with a binary format with sixteen digits.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// xtd::ustring s = 49_sb16;
  /// std::cout << s << std::endl;
  /// @endcode
  xtd::ustring operator""_sb16(unsigned long long s);
  
  /// @brief Used to convert the specified value to xtd::ustring with a binary format with thirty two digits.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// xtd::ustring s = 49_sb32;
  /// std::cout << s << std::endl;
  /// @endcode
  xtd::ustring operator""_sb32(unsigned long long s);
  
  /// @brief Used to convert the specified value to xtd::ustring with a binary format with sixty four digits.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// xtd::ustring s = 49_sb64;
  /// std::cout << s << std::endl;
  /// @endcode
  xtd::ustring operator""_sb64(unsigned long long s);
  
  /// @brief Used to convert the specified value to xtd::ustring with a decimal format.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// xtd::ustring s = 4.9_sd;
  /// std::cout << s << std::endl;
  /// @endcode
  xtd::ustring operator""_sd(long double s);
  
  /// @brief Used to convert the specified value to xtd::ustring with a decimal format.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// xtd::ustring s = 49_sd;
  /// std::cout << s << std::endl;
  /// @endcode
  xtd::ustring operator""_sd(unsigned long long s);
  
  /// @brief Used to convert specified value into xtd::ustring.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// xtd::ustring s = 49_sx;
  /// std::cout << s << std::endl;
  /// @endcode
  xtd::ustring operator""_sx(unsigned long long s);
  
  /// @brief Used to convert specified value into xtd::ustring.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// xtd::ustring s = 49_sx2;
  /// std::cout << s << std::endl;
  /// @endcode
  xtd::ustring operator""_sx2(unsigned long long s);
  
  /// @brief Used to convert specified value into xtd::ustring.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// xtd::ustring s = 49_sx4;
  /// std::cout << s << std::endl;
  /// @endcode
  xtd::ustring operator""_sx4(unsigned long long s);
  
  /// @brief Used to convert specified value into xtd::ustring.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// xtd::ustring s = 49_s;
  /// std::cout << s << std::endl;
  /// @endcode
  xtd::ustring operator""_sx8(unsigned long long s);
  
  /// @brief Used to convert specified value into xtd::ustring.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// xtd::ustring s = 49_sx;
  /// std::cout << s << std::endl;
  /// @endcode
  xtd::ustring operator""_sX(unsigned long long s);
  
  /// @brief Used to convert specified value into xtd::ustring.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// xtd::ustring s = 49_sx2;
  /// std::cout << s << std::endl;
  /// @endcode
  xtd::ustring operator""_sX2(unsigned long long s);
  
  /// @brief Used to convert specified value into xtd::ustring.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// xtd::ustring s = 49_sx4;
  /// std::cout << s << std::endl;
  /// @endcode
  xtd::ustring operator""_sX4(unsigned long long s);
  
  /// @brief Used to convert specified value into xtd::ustring.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// xtd::ustring s = 49_s;
  /// std::cout << s << std::endl;
  /// @endcode
  xtd::ustring operator""_sX8(unsigned long long s);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 1.6_s8 << std::endl;
  /// @endcode
  sbyte operator""_s8(long double n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 54_s8 << std::endl;
  /// @endcode
  sbyte operator""_s8(unsigned long long n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << "125"_s8 << std::endl;
  /// @endcode
  sbyte operator""_s8(const char* s, size_t n);
  
#if defined(__cpp_lib_char8_t)
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << u8"125"_s8 << std::endl;
  /// @endcode
  sbyte operator""_s8(const char8* s, size_t n);
#endif
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << u"125"_s8 << std::endl;
  /// @endcode
  sbyte operator""_s8(const char16* s, size_t n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << U"125"_s8 << std::endl;
  /// @endcode
  sbyte operator""_s8(const char32* s, size_t n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << L"125"_s8 << std::endl;
  /// @endcode
  sbyte operator""_s8(const wchar* s, size_t n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 1.6_s16 << std::endl;
  /// @endcode
  int16 operator""_s16(long double n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 54_s16 << std::endl;
  /// @endcode
  int16 operator""_s16(unsigned long long n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << "125"_s16 << std::endl;
  /// @endcode
  int16 operator""_s16(const char* s, size_t n);
  
#if defined(__cpp_lib_char8_t)
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << u8"125"_s16 << std::endl;
  /// @endcode
  int16 operator""_s16(const char8* s, size_t n);
#endif
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << u"125"_s16 << std::endl;
  /// @endcode
  int16 operator""_s16(const char16* s, size_t n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << U"125"_s16 << std::endl;
  /// @endcode
  int16 operator""_s16(const char32* s, size_t n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << L"125"_s16 << std::endl;
  /// @endcode
  int16 operator""_s16(const wchar* s, size_t n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 1.6_s32 << std::endl;
  /// @endcode
  int32 operator""_s32(long double n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 54_s32 << std::endl;
  /// @endcode
  int32 operator""_s32(unsigned long long n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << "125"_s32 << std::endl;
  /// @endcode
  int32 operator""_s32(const char* s, size_t n);
  
#if defined(__cpp_lib_char8_t)
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << u8"125"_s32 << std::endl;
  /// @endcode
  int32 operator""_s32(const char8* s, size_t n);
#endif
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << u"125"_s32 << std::endl;
  /// @endcode
  int32 operator""_s32(const char16* s, size_t n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << U"125"_s32 << std::endl;
  /// @endcode
  int32 operator""_s32(const char32* s, size_t n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << L"125"_s32 << std::endl;
  /// @endcode
  int32 operator""_s32(const wchar* s, size_t n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 1.6_s64 << std::endl;
  /// @endcode
  int64 operator""_s64(long double n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 54_s64 << std::endl;
  /// @endcode
  int64 operator""_s64(unsigned long long n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << "125"_s64 << std::endl;
  /// @endcode
  int64 operator""_s64(const char* s, size_t n);
  
#if defined(__cpp_lib_char8_t)
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << u8"125"_s64 << std::endl;
  /// @endcode
  int64 operator""_s64(const char8* s, size_t n);
#endif
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << u"125"_s64 << std::endl;
  /// @endcode
  int64 operator""_s64(const char16* s, size_t n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << U"125"_s64 << std::endl;
  /// @endcode
  int64 operator""_s64(const char32* s, size_t n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << L"125"_s64 << std::endl;
  /// @endcode
  int64 operator""_s64(const wchar* s, size_t n);
  
  /// @brief Used to translate specified string into locale.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals translate
  const char* operator""_t(const char* s, size_t n) noexcept;
  
  /// @brief Used to convert specified value into size_t.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 1.6_sz << std::endl;
  /// @endcode
  size_t operator""_sz(long double n);
  
  /// @brief Used to convert specified value into size_t.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 54_sz << std::endl;
  /// @endcode
  size_t operator""_sz(unsigned long long n);
  
  /// @brief Used to convert specified value into size_t.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << "125"_sz << std::endl;
  /// @endcode
  size_t operator""_sz(const char* s, size_t n);
  
#if defined(__cpp_lib_char8_t)
  /// @brief Used to convert specified value into size_t.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << u8"125"_sz << std::endl;
  /// @endcode
  size_t operator""_sz(const char8* s, size_t n);
#endif
  
  /// @brief Used to convert specified value into size_t.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << u"125"_sz << std::endl;
  /// @endcode
  size_t operator""_sz(const char16* s, size_t n);
  
  /// @brief Used to convert specified value into size_t.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << U"125"_sz << std::endl;
  /// @endcode
  size_t operator""_sz(const char32* s, size_t n);
  
  /// @brief Used to convert specified value into size_t.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << L"125"_sz << std::endl;
  /// @endcode
  size_t operator""_sz(const wchar* s, size_t n);

#if defined(__cpp_lib_char8_t)
  /// @brief Used to translate specified string into locale.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals translate
  xtd::ustring operator""_t(const char8* s, size_t n) noexcept;
#endif
  
  /// @brief Used to translate specified string into locale.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals translate
  xtd::ustring operator""_t(const char16* s, size_t n) noexcept;
  
  /// @brief Used to translate specified string into locale.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals translate
  xtd::ustring operator""_t(const char32* s, size_t n) noexcept;
  
  /// @brief Used to translate specified string into locale.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals translate
  xtd::ustring operator""_t(const wchar* s, size_t n) noexcept;
  
  /// @brief Used to convert the specified value as tiks to xtd::time_span.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// xtd::time_span ts = 49_s;
  /// std::cout << ts << std::endl;
  /// @endcode
  xtd::time_span operator""_t(unsigned long long s);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 1.6_u8 << std::endl;
  /// @endcode
  xtd::byte operator""_u8(long double n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 54_u8 << std::endl;
  /// @endcode
  xtd::byte operator""_u8(unsigned long long n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << "125"_u8 << std::endl;
  /// @endcode
  xtd::byte operator""_u8(const char* s, size_t n);
  
#if defined(__cpp_lib_char8_t)
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << u8"125"_u8 << std::endl;
  /// @endcode
  xtd::byte operator""_u8(const char8* s, size_t n);
#endif
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << u"125"_u8 << std::endl;
  /// @endcode
  xtd::byte operator""_u8(const char16* s, size_t n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << U"125"_u8 << std::endl;
  /// @endcode
  xtd::byte operator""_u8(const char32* s, size_t n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << L"125"_u8 << std::endl;
  /// @endcode
  xtd::byte operator""_u8(const wchar* s, size_t n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 1.6_u16 << std::endl;
  /// @endcode
  uint16 operator""_u16(long double n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 54_u16 << std::endl;
  /// @endcode
  uint16 operator""_u16(unsigned long long n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << "125"_u16 << std::endl;
  /// @endcode
  uint16 operator""_u16(const char* s, size_t n);
  
#if defined(__cpp_lib_char8_t)
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << u8"125"_u16 << std::endl;
  /// @endcode
  uint16 operator""_u16(const char8* s, size_t n);
#endif
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << u"125"_u16 << std::endl;
  /// @endcode
  uint16 operator""_u16(const char16* s, size_t n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << U"125"_u16 << std::endl;
  /// @endcode
  uint16 operator""_u16(const char32* s, size_t n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << L"125"_u16 << std::endl;
  /// @endcode
  uint16 operator""_u16(const wchar* s, size_t n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 1.6_u32 << std::endl;
  /// @endcode
  uint32 operator""_u32(long double n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 54_u32 << std::endl;
  /// @endcode
  uint32 operator""_u32(unsigned long long n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << "125"_u32 << std::endl;
  /// @endcode
  uint32 operator""_u32(const char* s, size_t n);
  
#if defined(__cpp_lib_char8_t)
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << u8"125"_u32 << std::endl;
  /// @endcode
  uint32 operator""_u32(const char8* s, size_t n);
#endif
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << u"125"_u32 << std::endl;
  /// @endcode
  uint32 operator""_u32(const char16* s, size_t n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << U"125"_u32 << std::endl;
  /// @endcode
  uint32 operator""_u32(const char32* s, size_t n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << L"125"_u32 << std::endl;
  /// @endcode
  uint32 operator""_u32(const wchar* s, size_t n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 1.6_u64 << std::endl;
  /// @endcode
  uint64 operator""_u64(long double n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 54_u64 << std::endl;
  /// @endcode
  uint64 operator""_u64(unsigned long long n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << "125"_u64 << std::endl;
  /// @endcode
  uint64 operator""_u64(const char* s, size_t n);
  
#if defined(__cpp_lib_char8_t)
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << u8"125"_u64 << std::endl;
  /// @endcode
  uint64 operator""_u64(const char8* s, size_t n);
#endif
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << u"125"_u64 << std::endl;
  /// @endcode
  uint64 operator""_u64(const char16* s, size_t n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << U"125"_u64 << std::endl;
  /// @endcode
  uint64 operator""_u64(const char32* s, size_t n);
  
  /// @brief Used to convert specified value into byte.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << L"125"_u64 << std::endl;
  /// @endcode
  uint64 operator""_u64(const wchar* s, size_t n);
  
  /// @brief Used to convert the specified value as microseconds to xtd::time_span.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// xtd::time_span ts = 49_s;
  /// std::cout << ts << std::endl;
  /// @endcode
  xtd::time_span operator""_us(unsigned long long s);
}
