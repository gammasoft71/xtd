/// @file
/// @brief Contains xtd::net::ip_address suffixes.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../net/ip_address.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::literals namespace contains all xtd's litterals operators.
  inline namespace literals {
    /// @name IP address suffixes
    
    /// @{
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::net::ip_address ip_v4 = "192.168.0.1"_ip;
    /// xtd::console::out << ip_v4 << xtd::environment::new_line;
    /// xtd::net::ip_address ip_v6 = "2001:db8::1"_ip;
    /// xtd::console::out << ip_v6 << xtd::environment::new_line;
    /// ```
    xtd::net::ip_address operator""_ip(const char* s, xtd::size n);
    
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::net::ip_address ip_v4 = "192.168.0.1"_ip;
    /// xtd::console::out << ip_v4 << xtd::environment::new_line;
    /// xtd::net::ip_address ip_v6 = "2001:db8::1"_ip;
    /// xtd::console::out << ip_v6 << xtd::environment::new_line;
    /// ```
    xtd::net::ip_address operator""_ip(const char8* s, xtd::size n);
#endif
    
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::net::ip_address ip_v4 = "192.168.0.1"_ip;
    /// xtd::console::out << ip_v4 << xtd::environment::new_line;
    /// xtd::net::ip_address ip_v6 = "2001:db8::1"_ip;
    /// xtd::console::out << ip_v6 << xtd::environment::new_line;
    /// ```
    xtd::net::ip_address operator""_ip(const char16* s, xtd::size n);
    
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::net::ip_address ip_v4 = "192.168.0.1"_ip;
    /// xtd::console::out << ip_v4 << xtd::environment::new_line;
    /// xtd::net::ip_address ip_v6 = "2001:db8::1"_ip;
    /// xtd::console::out << ip_v6 << xtd::environment::new_line;
    /// ```
    xtd::net::ip_address operator""_ip(const char32* s, xtd::size n);
    
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::net::ip_address ip_v4 = "192.168.0.1"_ip;
    /// xtd::console::out << ip_v4 << xtd::environment::new_line;
    /// xtd::net::ip_address ip_v6 = "2001:db8::1"_ip;
    /// xtd::console::out << ip_v6 << xtd::environment::new_line;
    /// ```
    xtd::net::ip_address operator""_ip(const wchar* s, xtd::size n);
    /// @}
  }
}
