/// @file
/// @brief Contains xtd::net::ip_host_entry class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once

#include "ip_address"
#include "../core_export"
#include "../object"
#include "../types"
#include "../ustring"
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief Provides a container class for Internet host address information.
    /// @par Header
    /// @code #include <xtd/net/ip_host_entry> @endcode
    /// @par Namespace
    /// xtd::net
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    class core_export_ ip_host_entry : public xtd::object {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::net::ip_host_entry.
      ip_host_entry() = default;
      /// @}
      
      /// @cond
      ip_host_entry(ip_host_entry&& ip_host_entry) = default;
      ip_host_entry(const ip_host_entry& ip_host_entry) = default;
      ip_host_entry& operator =(const ip_host_entry&) = default;
      /// @endcond
      
      /// @name Properties
      
      /// @{
      /// @brief Gets List of IP addresses that are associated with a host.
      /// @return An xtd::net::ip_address array of IP addresses that are associated with a host.
      const std::vector<xtd::net::ip_address>& address_list() const noexcept;
      /// @brief Gets List of IP addresses that are associated with a host.
      /// @return An xtd::net::ip_address array of IP addresses that are associated with a host.
      std::vector<xtd::net::ip_address>& address_list() noexcept;
      /// @brief Sets List of IP addresses that are associated with a host.
      /// @param address_list An xtd::net::ip_address array of IP addresses that are associated with a host.
      /// @return The current instance.
      ip_host_entry& address_list(const std::vector<xtd::net::ip_address>& address_list) noexcept;
      
      /// @brief Gets List of aliases that are associated with a host.
      /// @return A string array of aliases that are associated with a host.
      const std::vector<xtd::ustring>& aliases() const noexcept;
      /// @brief Gets List of aliases that are associated with a host.
      /// @return A string array of aliases that are associated with a host.
      std::vector<xtd::ustring>& aliases() noexcept;
      /// @brief Sets List of aliases that are associated with a host.
      /// @param aliases A string array of aliases that are associated with a host.
      /// @return The current instance.
      ip_host_entry& aliases(const std::vector<xtd::ustring>& aliases) noexcept;
      
      /// @brief Gets the DNS name of the host.
      /// @return A string represent the DNS name of the host.
      const xtd::ustring& host_name() const noexcept;
      /// @brief Sets the DNS name of the host.
      /// @param hist_name A string represent the DNS name of the host.
      /// @return The current instance.
      ip_host_entry& host_name(const xtd::ustring& host_name) noexcept;
      /// @}
      
    private:
      std::vector<xtd::net::ip_address> address_list_;
      std::vector<xtd::ustring> aliases_;
      xtd::ustring host_name_;
    };
  }
}
