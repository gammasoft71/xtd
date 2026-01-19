/// @file
/// @brief Contains dns API.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/core_native_export>
#include <cstddef>
#include <string>
#include <vector>
#include <cstdint>

/// @cond
class __using_dns__;
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace net {
    class dns;
  }
  /// @endcond
  
  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @brief Contains dns native API.
    /// @par Namespace
    /// xtd::native
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @warning Internal use only
    class core_native_export_ dns final {
      dns() = delete;
      friend xtd::net::dns;
      friend __using_dns__;
    protected:
      /// @name Protected Static Methods
      
      /// @{
      /// @brief Closes the file /etc/hosts.
      /// @warning Internal use only
      static auto cleanup() -> void;
      /// @brief Destroys host handle.
      /// @param host The host handle to destroy.
      /// @warning Internal use only
      static auto destroy(std::intmax_t host) -> void;
      /// @brief Gets host by host IP address.
      /// @param host_address The host IP address to resolve.
      /// @param host_address_type The  address family (see address_family_constants.h) to resolve.
      /// @return The host handle.
      /// @warning Internal use only
      [[nodiscard]] static auto get_host_by_address(const std::string& host_address, std::int32_t host_address_type) -> std::intmax_t;
      /// @brief Gets host by host name.
      /// @param host_name The name to resolve.
      /// @return The host handle.
      /// @warning Internal use only
      [[nodiscard]] static auto get_host_by_name(const std::string& host_name) -> std::intmax_t;
      /// @brief Gets aliases for a host.
      /// @param host The host handle to retrieve aliases.
      /// @return An alias array for yhe host.
      /// @warning Internal use only
      [[nodiscard]] static auto get_aliases(std::intmax_t host) -> std::vector<std::string>;
      /// @brief Gets IP addresses for a host.
      /// @param host The host handle to retrieve IP addresses.
      /// @return An IP address array for yhe host.
      /// @warning Internal use only
      [[nodiscard]] static auto get_addresses(std::intmax_t host) -> std::vector<std::vector<std::uint8_t>>;
      /// @brief Gets name for a host.
      /// @param host The host handle to retrieve name.
      /// @return A string that represent the host.
      /// @warning Internal use only
      [[nodiscard]] static auto get_host_name(std::intmax_t host) -> std::string;
      /// @brief Gets host name for the current computer.
      /// @param host_name The string that will contain the host name.
      /// @return 0 if succeed; otherwise error.
      /// @warning Internal use only
      [[nodiscard]] static auto get_host_name(std::string& host_name) -> std::int32_t;
      /// @brief Opens the file /etc/hosts.
      /// @warning Internal use only
      static auto startup() -> void;
      /// @}
    };
  }
}
