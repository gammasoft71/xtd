/// @file
/// @brief Contains xtd::uri_host_name_type enum.
#pragma once
#include "enum"

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
}

/// @cond
template<> struct xtd::enum_register<xtd::uri_host_name_type> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::uri_host_name_type> {{xtd::uri_host_name_type::unknown, "unknown"}, {xtd::uri_host_name_type::basic, "basic"}, {xtd::uri_host_name_type::dns, "dns"}, {xtd::uri_host_name_type::ip_v4, "ip_v4"}, {xtd::uri_host_name_type::ip_v6, "ip_v6"}};}
};
/// @endcond
