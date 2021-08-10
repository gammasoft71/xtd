/// @file
/// @brief Contains xtd::net::dns class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <vector>
#include "../core_export.h"
#include "../static.h"
#include "ip_host_entry.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief Provides simple domain name resolution functionality.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core net
    class core_export_ dns static_ {
    public:
      /// @brief Returns the Internet Protocol (IP) addresses for the specified host.
      /// @param host_name_or_address The host name or IP address to resolve.
      /// @return An array of type xtd::net::ip_address that holds the IP addresses for the host that is specified by the host_name_or_address parameter..
      static std::vector<xtd::net::ip_address> get_host_addresses(const xtd::ustring& host_name_or_address);
      
      /// @brief Resolves an IP address to an xtd::net::ip_host_entry instance.
      /// @param address An IP address.
      /// @return An xtd::net::ip_host_entry instance that contains address information about the host specified in address.
      static xtd::net::ip_host_entry get_host_entry(const ip_address& address);
      
      /// @brief Resolves a host name or IP address to an xtd::net::ip_host_entry instance.
      /// @param host_name_or_address The host name or IP address to resolve.
      /// @return An xtd::net::ip_host_entry instance that contains address information about the host specified in host_name_or_address.
      static xtd::net::ip_host_entry get_host_entry(const xtd::ustring& host_name_or_address);
      
      /// @brief Gets the host name of the local computer.
      /// @return string A string that contains the DNS host name of the local computer.
      static xtd::ustring get_host_name();
    };
  }
}
