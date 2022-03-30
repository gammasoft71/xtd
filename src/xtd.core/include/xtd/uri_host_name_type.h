/// @file
/// @brief Contains xtd::uri_host_name_type enum.
#pragma once

#include "ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Defines host name types for the xtd::uri::check_host_name method.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks The xtd::uri_host_name_type enumeration defines the values that the xtd::uri::check_host_name method can return.
  enum class uri_host_name_type {
    /// @brief The type of the host name is not supplied.
    unknown = 0,
    /// @brief The host is set, but the type cannot be determined.
    basic = 1,
    /// @brief The host name is a domain name system (DNS) style host name.
    dns = 2,
    /// @brief The Uri is a relative xtd::uri.
    ip_v4 = 3,
    /// @brief The Uri is a relative xtd::uri.
    ip_v6 = 4,
  };
  
  /// @cond
  inline std::ostream& operator<<(std::ostream& os, const uri_host_name_type value) {return os << to_string(value, {{uri_host_name_type::unknown, "unknown"}, {uri_host_name_type::basic, "basic"}, {uri_host_name_type::dns, "dns"}, {uri_host_name_type::ip_v4, "ip_v4"}, {uri_host_name_type::ip_v6, "ip_v6"}});}
  inline std::wostream& operator<<(std::wostream& os, const uri_host_name_type value) {return os << to_string(value, {{uri_host_name_type::unknown, L"unknown"}, {uri_host_name_type::basic, L"basic"}, {uri_host_name_type::dns, L"dns"}, {uri_host_name_type::ip_v4, L"ip_v4"}, {uri_host_name_type::ip_v6, L"ip_v6"}});}
  /// @endcond
}
