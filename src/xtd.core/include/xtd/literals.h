/// @file
/// @brief Contains xtd literals.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#define __XTD_CORE_INTERNAL__
#include "internal/__literals_exception.h"
#undef __XTD_CORE_INTERNAL__
/// @endcond
#include <limits>
#include <stdexcept>
#include "parse.h"
#include "strings.h"
#include "translator.h"
#include "types.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Used to convert specified value into byte.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 1.6_d << std::endl;
  /// @endcode
  inline double operator""_d(long double n) {
    if (n < static_cast<long double>(-std::numeric_limits<double>::max()) || n > static_cast<long double>(std::numeric_limits<double>::max())) __litterals_argument_out_of_range_exception();
    return static_cast<double>(n);
  }

  /// @brief Used to convert specified value into byte.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 54_d << std::endl;
  /// @endcode
  inline double operator""_d(unsigned long long n) {
    if (n < static_cast<unsigned long long>(-std::numeric_limits<double>::max()) || n > static_cast<unsigned long long>(std::numeric_limits<double>::max())) __litterals_argument_out_of_range_exception();
    return static_cast<double>(n);
  }

  /// @brief Used to convert specified value into byte.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << "125"_d << std::endl;
  /// @endcode
  inline double operator""_d(const char* s, size_t n) {
    return xtd::parse<double>(std::string(s, s + n));
  }

  /// @brief Used to convert specified value into byte.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 1.6_f << std::endl;
  /// @endcode
  inline float operator""_f(long double n) {
    if (n < static_cast<long double>(-std::numeric_limits<float>::max()) || n > static_cast<long double>(std::numeric_limits<float>::max())) __litterals_argument_out_of_range_exception();
    return static_cast<float>(n);
  }

  /// @brief Used to convert specified value into byte.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 54_f << std::endl;
  /// @endcode
  inline float operator""_f(unsigned long long n) {
    if (n < static_cast<unsigned long long>(-std::numeric_limits<float>::max()) || n > static_cast<unsigned long long>(std::numeric_limits<float>::max())) __litterals_argument_out_of_range_exception();
    return static_cast<float>(n);
  }

  /// @brief Used to convert specified value into byte.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << "125"_f << std::endl;
  /// @endcode
  inline float operator""_f(const char* s, size_t n) {
    return xtd::parse<float>(std::string(s, s + n));
  }

  /// @brief Used to convert specified value into char32._t
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 'a'_c << std::endl;
  /// @endcode
  inline char32_t operator""_c(char c) {
    return static_cast<char32_t>(c);
  }

  /// @brief Used to convert specified value into char32._t
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << u'a'_c << std::endl;
  /// @endcode
  inline char32_t operator""_c(char16_t c) {
    return static_cast<char32_t>(c);
  }

  /// @brief Used to convert specified value into char32._t
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << U'a'_c << std::endl;
  /// @endcode
  inline char32_t operator""_c(char32_t c) {
    return c;
  }

  /// @brief Used to convert specified value into char32._t
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << L'a'_c << std::endl;
  /// @endcode
  inline char32_t operator""_c(wchar_t c) {
    return static_cast<char32_t>(c);
  }

  /// @brief Used to convert specified value into char32._t
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 49_c << std::endl;
  /// @endcode
  inline char32_t operator""_c(unsigned long long c) {
    return static_cast<char32_t>(c);
  }

  /// @brief Used to convert specified value into System::String.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::string s = "This is a "_s + "simple test"_s;
  /// std::cout << s << std::endl;
  /// @endcode
  inline std::string operator""_s(const char* s, size_t n) {
    return std::string(s, s + n);
  }

#if defined(__cpp_lib_char8_t)
  /// @brief Used to convert specified value into System::String.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::string s = u8"This is a "_s + u8"simple test"_s;
  /// std::cout << s << std::endl;
  /// @endcode
  inline std::string operator""_s(const char8_t* s, size_t n) {
    return std::string(s, s + n);
  }
#endif
  /// @brief Used to convert specified value into System::String.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::string s = U"This is a "_s + U"simple test"_s;
  /// std::cout << s << std::endl;
  /// @endcode
  inline std::string operator""_s(const char16_t* s, size_t n) {
    return xtd::strings::format("{}", s);
  }
  /// @brief Used to convert specified value into System::String.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::string s = u"This is a "_s + u"simple test"_s;
  /// std::cout << s << std::endl;
  /// @endcode
  inline std::string operator""_s(const char32_t* s, size_t n) {
    return xtd::strings::format("{}", s);
  }
  /// @brief Used to convert specified value into System::String.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::string s = L"This is a "_s + L"simple test"_s;
  /// std::cout << s << std::endl;
  /// @endcode
  inline std::string operator""_s(const wchar_t* s, size_t n) {
    return xtd::strings::format("{}", s);
  }

  /// @brief Used to convert specified value into std::string.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::string s = "This is a "_s + "simple test"_s;
  /// std::cout << s << std::endl;
  /// @endcode
  inline std::string operator""_s(long double s) {
    return xtd::strings::format("{}", s);
  }

  /// @brief Used to convert specified value into std::string.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::string s = 49_s;
  /// std::cout << s << std::endl;
  /// @endcode
  inline std::string operator""_s(unsigned long long s) {
    return xtd::strings::format("{}", s);
  }

  /// @brief Used to convert specified value into std::string.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::string s = 49_sb;
  /// std::cout << s << std::endl;
  /// @endcode
  inline std::string operator""_sb(unsigned long long s) {
    return xtd::strings::format("{:b}", s);
  }

  /// @brief Used to convert specified value into std::string.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::string s = 49_sb2;
  /// std::cout << s << std::endl;
  /// @endcode
  inline std::string operator""_sb2(unsigned long long s) {
    return xtd::strings::format("{:b2}", s);
  }

  /// @brief Used to convert specified value into std::string.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::string s = 49_sb4;
  /// std::cout << s << std::endl;
  /// @endcode
  inline std::string operator""_sb4(unsigned long long s) {
    return xtd::strings::format("{:b4}", s);
  }

  /// @brief Used to convert specified value into std::string.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::string s = 49_sb8;
  /// std::cout << s << std::endl;
  /// @endcode
  inline std::string operator""_sb8(unsigned long long s) {
    return xtd::strings::format("{:b8}", s);
  }

  /// @brief Used to convert specified value into std::string.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::string s = 49_sb16;
  /// std::cout << s << std::endl;
  /// @endcode
  inline std::string operator""_sb16(unsigned long long s) {
    return xtd::strings::format("{:b16}", s);
  }

  /// @brief Used to convert specified value into std::string.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::string s = 49_sb32;
  /// std::cout << s << std::endl;
  /// @endcode
  inline std::string operator""_sb32(unsigned long long s) {
    return xtd::strings::format("{:b32}", s);
  }

  /// @brief Used to convert specified value into std::string.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::string s = 49_sb64;
  /// std::cout << s << std::endl;
  /// @endcode
  inline std::string operator""_sb64(unsigned long long s) {
    return xtd::strings::format("{:b64}", s);
  }

  /// @brief Used to convert specified value into std::string.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::string s = 49_sx;
  /// std::cout << s << std::endl;
  /// @endcode
  inline std::string operator""_sx(unsigned long long s) {
    return xtd::strings::format("{:x}", s);
  }

  /// @brief Used to convert specified value into std::string.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::string s = 49_sx2;
  /// std::cout << s << std::endl;
  /// @endcode
  inline std::string operator""_sx2(unsigned long long s) {
    return xtd::strings::format("{:x2}", s);
  }

  /// @brief Used to convert specified value into std::string.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::string s = 49_sx4;
  /// std::cout << s << std::endl;
  /// @endcode
  inline std::string operator""_sx4(unsigned long long s) {
    return xtd::strings::format("{:x4}", s);
  }

  /// @brief Used to convert specified value into std::string.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::string s = 49_s;
  /// std::cout << s << std::endl;
  /// @endcode
  inline std::string operator""_sx8(unsigned long long s) {
    return xtd::strings::format("{:x8}", s);
  }

  /// @brief Used to convert specified value into std::string.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::string s = 49_sx;
  /// std::cout << s << std::endl;
  /// @endcode
  inline std::string operator""_sX(unsigned long long s) {
    return xtd::strings::format("{:X}", s);
  }

  /// @brief Used to convert specified value into std::string.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::string s = 49_sx2;
  /// std::cout << s << std::endl;
  /// @endcode
  inline std::string operator""_sX2(unsigned long long s) {
    return xtd::strings::format("{:X2}", s);
  }

  /// @brief Used to convert specified value into std::string.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::string s = 49_sx4;
  /// std::cout << s << std::endl;
  /// @endcode
  inline std::string operator""_sX4(unsigned long long s) {
    return xtd::strings::format("{:X4}", s);
  }

  /// @brief Used to convert specified value into std::string.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::string s = 49_s;
  /// std::cout << s << std::endl;
  /// @endcode
  inline std::string operator""_sX8(unsigned long long s) {
    return xtd::strings::format("{:X8}", s);
  }

  /// @brief Used to convert specified value into byte.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 1.6_s8 << std::endl;
  /// @endcode
  inline int8_t operator""_s8(long double n) {
    if (n < static_cast<long double>(std::numeric_limits<int8_t>::min()) || n > static_cast<long double>(std::numeric_limits<int8_t>::max())) __litterals_argument_out_of_range_exception();
    return static_cast<int8_t>(n);
  }

  /// @brief Used to convert specified value into byte.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 54_s8 << std::endl;
  /// @endcode
  inline int8_t operator""_s8(unsigned long long n) {
    if (static_cast<long long>(n) < std::numeric_limits<int8_t>::min() || static_cast<long long>(n) > std::numeric_limits<int8_t>::max()) __litterals_argument_out_of_range_exception();
    return static_cast<int8_t>(n);
  }

  /// @brief Used to convert specified value into byte.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << "125"_s8 << std::endl;
  /// @endcode
  inline int8_t operator""_s8(const char* s, size_t n) {
    return xtd::parse<int8_t>(std::string(s, s + n));
  }

  /// @brief Used to convert specified value into byte.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 1.6_s16 << std::endl;
  /// @endcode
  inline int16_t operator""_s16(long double n) {
    if (n < static_cast<long double>(std::numeric_limits<int16_t>::min()) || n > static_cast<long double>(std::numeric_limits<int16_t>::max())) __litterals_argument_out_of_range_exception();
    return static_cast<int16_t>(n);
  }

  /// @brief Used to convert specified value into byte.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 54_s16 << std::endl;
  /// @endcode
  inline int16_t operator""_s16(unsigned long long n) {
    if (static_cast<long long>(n) < std::numeric_limits<int16_t>::min() || static_cast<long long>(n) > std::numeric_limits<int16_t>::max()) __litterals_argument_out_of_range_exception();
    return static_cast<int16_t>(n);
  }

  /// @brief Used to convert specified value into byte.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << "125"_s16 << std::endl;
  /// @endcode
  inline int16_t operator""_s16(const char* s, size_t n) {
    return xtd::parse<int16_t>(std::string(s, s + n));
  }

  /// @brief Used to convert specified value into byte.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 1.6_s32 << std::endl;
  /// @endcode
  inline int32_t operator""_s32(long double n) {
    if (n < static_cast<long double>(std::numeric_limits<int32_t>::min()) || n > static_cast<long double>(std::numeric_limits<int32_t>::max())) __litterals_argument_out_of_range_exception();
    return static_cast<int32_t>(n);
  }

  /// @brief Used to convert specified value into byte.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 54_s32 << std::endl;
  /// @endcode
  inline int32_t operator""_s32(unsigned long long n) {
    if (static_cast<long long>(n) < std::numeric_limits<int32_t>::min() || static_cast<long long>(n) > std::numeric_limits<int32_t>::max()) __litterals_argument_out_of_range_exception();
    return static_cast<int32_t>(n);
  }

  /// @brief Used to convert specified value into byte.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << "125"_s32 << std::endl;
  /// @endcode
  inline int32_t operator""_s32(const char* s, size_t n) {
    return xtd::parse<int32_t>(std::string(s, s + n));
  }

  /// @brief Used to convert specified value into byte.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 1.6_s64 << std::endl;
  /// @endcode
  inline int64_t operator""_s64(long double n) {
    if (n < static_cast<long double>(std::numeric_limits<int64_t>::min()) || n > static_cast<long double>(std::numeric_limits<int64_t>::max())) __litterals_argument_out_of_range_exception();
    return static_cast<int64_t>(n);
  }

  /// @brief Used to convert specified value into byte.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 54_s64 << std::endl;
  /// @endcode
  inline int64_t operator""_s64(unsigned long long n) {
    if (static_cast<long long>(n) < std::numeric_limits<int64_t>::min() || static_cast<long long>(n) > std::numeric_limits<int64_t>::max()) __litterals_argument_out_of_range_exception();
    return static_cast<int64_t>(n);
  }

  /// @brief Used to convert specified value into byte.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << "125"_s64 << std::endl;
  /// @endcode
  inline int64_t operator""_s64(const char* s, size_t n) {
    return xtd::parse<int64_t>(std::string(s, s + n));
  }

  /// @brief Used to convert specified value into byte.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 1.6_u8 << std::endl;
  /// @endcode
  inline uint8_t operator""_u8(long double n) {
    if (n < static_cast<long double>(std::numeric_limits<uint8_t>::min()) || n > static_cast<long double>(std::numeric_limits<uint8_t>::max())) __litterals_argument_out_of_range_exception();
    return static_cast<uint8_t>(n);
  }

  /// @brief Used to convert specified value into byte.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 54_u8 << std::endl;
  /// @endcode
  inline uint8_t operator""_u8(unsigned long long n) {
    if (n < static_cast<unsigned long long>(std::numeric_limits<uint8_t>::min()) || n > static_cast<unsigned long long>(std::numeric_limits<uint8_t>::max())) __litterals_argument_out_of_range_exception();
    return static_cast<uint8_t>(n);
  }

  /// @brief Used to convert specified value into byte.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << "125"_u8 << std::endl;
  /// @endcode
  inline uint8_t operator""_u8(const char* s, size_t n) {
    return xtd::parse<uint8_t>(std::string(s, s + n));
  }

  /// @brief Used to convert specified value into byte.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 1.6_u16 << std::endl;
  /// @endcode
  inline uint16_t operator""_u16(long double n) {
    if (n < static_cast<long double>(std::numeric_limits<uint16_t>::min()) || n > static_cast<long double>(std::numeric_limits<uint16_t>::max())) __litterals_argument_out_of_range_exception();
    return static_cast<uint16_t>(n);
  }

  /// @brief Used to convert specified value into byte.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 54_u16 << std::endl;
  /// @endcode
  inline uint16_t operator""_u16(unsigned long long n) {
    if (n < static_cast<unsigned long long>(std::numeric_limits<uint16_t>::min()) || n > static_cast<unsigned long long>(std::numeric_limits<uint16_t>::max())) __litterals_argument_out_of_range_exception();
    return static_cast<uint16_t>(n);
  }

  /// @brief Used to convert specified value into byte.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << "125"_u16 << std::endl;
  /// @endcode
  inline uint16_t operator""_u16(const char* s, size_t n) {
    return xtd::parse<uint16_t>(std::string(s, s + n));
  }

  /// @brief Used to convert specified value into byte.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 1.6_u32 << std::endl;
  /// @endcode
  inline uint32_t operator""_u32(long double n) {
    if (n < static_cast<long double>(std::numeric_limits<uint32_t>::min()) || n > static_cast<long double>(std::numeric_limits<uint32_t>::max())) __litterals_argument_out_of_range_exception();
    return static_cast<uint32_t>(n);
  }

  /// @brief Used to convert specified value into byte.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 54_u32 << std::endl;
  /// @endcode
  inline uint32_t operator""_u32(unsigned long long n) {
    if (n < static_cast<unsigned long long>(std::numeric_limits<uint32_t>::min()) || n > static_cast<unsigned long long>(std::numeric_limits<uint32_t>::max())) __litterals_argument_out_of_range_exception();
    return static_cast<uint32_t>(n);
  }

  /// @brief Used to convert specified value into byte.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << "125"_u32 << std::endl;
  /// @endcode
  inline uint32_t operator""_u32(const char* s, size_t n) {
    return xtd::parse<uint32_t>(std::string(s, s + n));
  }

  /// @brief Used to convert specified value into byte.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 1.6_u64 << std::endl;
  /// @endcode
  inline uint64_t operator""_u64(long double n) {
    if (n < static_cast<long double>(std::numeric_limits<uint64_t>::min()) || n > static_cast<long double>(std::numeric_limits<uint64_t>::max())) __litterals_argument_out_of_range_exception();
    return static_cast<uint64_t>(n);
  }

  /// @brief Used to convert specified value into byte.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << 54_u64 << std::endl;
  /// @endcode
  inline uint64_t operator""_u64(unsigned long long n) {
    if (n < static_cast<unsigned long long>(std::numeric_limits<uint64_t>::min()) || n > static_cast<unsigned long long>(std::numeric_limits<uint64_t>::max())) __litterals_argument_out_of_range_exception();
    return static_cast<uint64_t>(n);
  }

  /// @brief Used to convert specified value into byte.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::cout << "125"_u64 << std::endl;
  /// @endcode
  inline uint64_t operator""_u64(const char* s, size_t n) {
    return xtd::parse<uint64_t>(std::string(s, s + n));
  }

  /// @brief Used to convert specified value into System::String.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::string s = "This is a "_s + "simple test"_s;
  /// std::cout << s << std::endl;
  /// @endcode
  inline std::wstring operator""_ws(const wchar_t* s, size_t n) {
    return std::wstring(s, s + n);
  }
  
#if defined(__cpp_lib_char8_t)
  /// @brief Used to convert specified value into System::String.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::string s = u8"This is a "_s + u8"simple test"_s;
  /// std::cout << s << std::endl;
  /// @endcode
  inline std::wstring operator""_ws(const char8_t* s, size_t n) {
    return std::wstring(s, s + n);
  }
#endif
  
  /// @brief Used to convert specified value into std::string.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::string s = "This is a "_s + "simple test"_s;
  /// std::cout << s << std::endl;
  /// @endcode
  inline std::wstring operator""_ws(long double s) {
    return L""; //strings::to_wstring(xtd::strings::format("{}", s));
  }
  
  /// @brief Used to convert specified value into std::string.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core literals
  /// @par Examples
  /// @code
  /// std::string s = 49_s;
  /// std::cout << s << std::endl;
  /// @endcode
  inline std::wstring operator""_ws(unsigned long long s) {
    return L""; //strings::to_wstring(xtd::strings::format("{}", s));
  }

  inline const char* operator""_t(const char* s, size_t n) {
    return xtd::translator::translate(s);
  }
  
#if defined(__cpp_lib_char8_t)
  inline std::string operator""_t(const char8_t* s, size_t n) {
    return xtd::translator::translate({s, s + n});
  }
#endif
  
  inline std::string operator""_t(const char16_t* s, size_t n) {
    return xtd::translator::translate(xtd::strings::format("{}", s));
  }
  
  inline std::string operator""_t(const char32_t* s, size_t n) {
    return xtd::translator::translate(xtd::strings::format("{}", s));
  }
  
  inline std::string operator""_t(const wchar_t* s, size_t n) {
    return xtd::translator::translate(xtd::strings::format("{}", s));
  }
}
