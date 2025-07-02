/// @file
/// @brief Contains xtd::string suffixes.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../string.hpp"
#define __XTD_CORE_INTERNAL__
#include "../internal/__string_definitions.hpp"
#undef __XTD_CORE_INTERNAL__

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::literals namespace contains all xtd's litterals operators.
  inline namespace literals {
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
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_s(const char* s, xtd::size n);
    
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = u8"This is a "_s + u8"simple test"_s;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_s(const char8* s, xtd::size n);
    
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = U"This is a "_s + U"simple test"_s;
    /// xtd::console::out << s << xtd::environment::new_line;
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
    /// xtd::console::out << s << xtd::environment::new_line;
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
    /// xtd::console::out << s << xtd::environment::new_line;
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
    /// xtd::string s = 42.0_sb;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sb(long double s);
    
    /// @brief Used to convert the specified value to xtd::string with a binary format.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42_sb;
    /// xtd::console::out << s << xtd::environment::new_line;
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
    /// xtd::string s = 42.0_sb2;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sb2(long double s);
    
    /// @brief Used to convert the specified value to xtd::string with a binary format with two digits.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42_sb2;
    /// xtd::console::out << s << xtd::environment::new_line;
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
    /// xtd::string s = 42.0_sb4;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sb4(long double s);
    
    /// @brief Used to convert the specified value to xtd::string with a binary format with four digits.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42_sb4;
    /// xtd::console::out << s << xtd::environment::new_line;
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
    /// xtd::string s = 42.0_sb8;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sb8(long double s);
    
    /// @brief Used to convert the specified value to xtd::string with a binary format with eight digits.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42_sb8;
    /// xtd::console::out << s << xtd::environment::new_line;
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
    /// xtd::string s = 42.0_sb16;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sb16(long double s);
    
    /// @brief Used to convert the specified value to xtd::string with a binary format with sixteen digits.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42_sb16;
    /// xtd::console::out << s << xtd::environment::new_line;
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
    /// xtd::string s = 42.0_sb32;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sb32(long double s);
    
    /// @brief Used to convert the specified value to xtd::string with a binary format with thirty two digits.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42_sb32;
    /// xtd::console::out << s << xtd::environment::new_line;
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
    /// xtd::string s = 42.0_sb64;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sb64(long double s);
    
    /// @brief Used to convert the specified value to xtd::string with a binary format with sixty four digits.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42_sb64;
    /// xtd::console::out << s << xtd::environment::new_line;
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
    /// xtd::console::out << s << xtd::environment::new_line;
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
    /// xtd::string s = 42_sd;
    /// xtd::console::out << s << xtd::environment::new_line;
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
    /// xtd::string s = 42_sx;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sx(long double s);
    
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42_sx;
    /// xtd::console::out << s << xtd::environment::new_line;
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
    /// xtd::string s = 42_sx2;
    /// xtd::console::out << s << xtd::environment::new_line;
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
    /// xtd::string s = 42_sx4;
    /// xtd::console::out << s << xtd::environment::new_line;
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
    /// xtd::string s = 42_sx8;
    /// xtd::console::out << s << xtd::environment::new_line;
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
    /// xtd::string s = 42_sx16;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sx16(unsigned long long s);
    
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42.0_sX;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sX(long double s);
    
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42_sX;
    /// xtd::console::out << s << xtd::environment::new_line;
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
    /// xtd::string s = 42_sX2;
    /// xtd::console::out << s << xtd::environment::new_line;
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
    /// xtd::string s = 42_sX4;
    /// xtd::console::out << s << xtd::environment::new_line;
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
    /// xtd::string s = 42_sX8;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sX8(unsigned long long s);
    
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42_sX16;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sX16(unsigned long long s);
    /// @}
  }
}
