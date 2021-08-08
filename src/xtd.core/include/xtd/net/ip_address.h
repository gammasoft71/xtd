/// @file
/// @brief Contains xtd::net::ip_address class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <vector>
#include "../core_export.h"
#include "../object.h"
#include "../types.h"
#include "../ustring.h"
#include "sockets/address_family.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief Provides an Internet Protocol (IP) address.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core net
    class core_export_ ip_address : public xtd::object {
    public:
      /// @brief Initializes a new instance of the xtd::net::ip_address.
      /// @remarks ip_address is initialized by default value (as none).
      ip_address() = default;
      
      /// @cond
       ip_address(const ip_address& ip_address);
       ip_address& operator=(const ip_address&) = default;
      /// @endcond
      
      /// @brief Gets the address family of the IP address.
      /// @return Returns sockets::address_family::inter_network for IPv4 or sockets::address_family::inter_network_v6 for IPv6.
      sockets::address_family address_family() const;
      
      /// @brief Gets the IPv6 address scope identifier.
      /// @return A int64_t that specifies the scope of the address.
      /// @exception xtd::net::sockets::socket_exception if address_family = sockets::address_family::inter_network
      /// @exception xtd::argument_out_of_range_exception scope_id < 0 or scope_id > 0x00000000FFFFFFFF.
      int64_t scope_id() const;
      /// @brief Sets the IPv6 address scope identifier.
      /// @param value A int64_t that specifies the scope of the address.
      /// @exception xtd::net::sockets::socket_exception if address_family = sockets::address_family::inter_network
      /// @exception xtd::argument_out_of_range_exception scope_id < 0 or scope_id > 0x00000000FFFFFFFF.
      ip_address& scope_id(int64_t value);

    protected:
      uint32_t ip_v4_address_ = 0x00000000FFFFFFFF;
      std::vector<uint16_t> ip_v6_numbers_ {8};
      uint32_t scope_id_ = 0;
      sockets::address_family family_ = sockets::address_family::inter_network;
    };
  }
}
