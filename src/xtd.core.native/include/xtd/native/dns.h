/// @file
/// @brief Contains dns API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/core_native_export.h>
#include <cstddef>
#include <string>
#include <vector>

/// @cond
class __using_dns__;
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace net {
    class dns;
  }
  // @endcond

  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @brief Contains dns native API.
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @warning Internal use only
    class core_native_export_ dns final {
      friend xtd::net::dns;
      friend __using_dns__;
    protected:
      /// @brief Closes the file /etc/hosts.
      /// @warning Internal use only
      static void cleanup();
      /// @brief Destroy host handle.
      /// @param host The host handle to destroy.
      /// @warning Internal use only
      static void destroy(intptr_t host);
      /// @brief Gets host by host IP address.
      /// @param host_address The host IP address to resolve.
      /// @param host_address_type The  address family (see address_family_constants.h) to resolve.
      /// @return The host handle.
      /// @warning Internal use only
      static intptr_t get_host_by_address(const std::string& host_address, int32_t host_address_type);
      /// @brief Gets host by host name.
      /// @param host_name The name to resolve.
      /// @return The host handle.
      /// @warning Internal use only
      static intptr_t get_host_by_name(const std::string& host_name);
      /// @brief Gets aliases for a host.
      /// @param host The host handle to retreive aliases.
      /// @return An alias array for yhe host.
      /// @warning Internal use only
      static std::vector<std::string> get_aliases(intptr_t host);
      /// @brief Gets IP addresses for a host.
      /// @param host The host handle to retreive IP adresses.
      /// @return An IP address array for yhe host.
      /// @warning Internal use only
      static std::vector<std::vector<uint8_t>> get_addresses(intptr_t host);
      /// @brief Gets name for a host.
      /// @param host The host handle to retreive name.
      /// @return A string that represent the host.
      /// @warning Internal use only
      static std::string get_host_name(intptr_t host);
      /// @brief Gets host name for the current computer.
      /// @param host_name The string that will contain the host name.
      /// @return 0 if succeed; otherwise error.
      /// @warning Internal use only
      static int32_t get_host_name(std::string& host_name);
      /// @brief Opens the file /etc/hosts.
      /// @warning Internal use only
      static void startup();
    };
  }
}
