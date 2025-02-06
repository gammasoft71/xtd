/// @file
/// @brief Contains xtd::net::sockets::ip_v6_multicast_option class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../ip_address.hpp"
#include "../../core_export.hpp"
#include "../../object.hpp"
#include "../../types.hpp"
#include "../../string.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief The xtd::net::sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
    namespace sockets {
      /// @brief Contains option values for joining an IPv6 multicast group.
      /// ```cpp
      /// class core_export_ ip_v6_multicast_option : public xtd::object
      /// ```
      /// @par Inheritance
      /// xtd::object → xtd::net::sockets::ip_v6_multicast_option
      /// @par Header
      /// ```cpp
      /// #include <xtd/net/sockets/ip_v6_multicast_option>
      /// ```
      /// @par Namespace
      /// xtd::net::sockets
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core
      struct core_export_ ip_v6_multicast_option : xtd::object {
        /// @name Public Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::net::sockets::ip_v6_multicast_option class.
        ip_v6_multicast_option() = default;
        /// @brief Initializes a new version of the xtd::net::sockets::ip_v6_multicast_option class for the specified IP multicast group.
        /// @param group The xtd::net::ip_address of the multicast group.
        explicit ip_v6_multicast_option(const xtd::net::ip_address& group);
        /// @brief Initializes a new instance of the xtd::net::sockets::ip_v6_multicast_option class with the specified IP multicast group and the local interface address.
        /// @param group The xtd::net::ip_address of the multicast group.
        /// @param interface_index The address of the interface.
        ip_v6_multicast_option(const xtd::net::ip_address& group, uint32 interface_index);
        /// @}
        
        /// @cond
        ip_v6_multicast_option(ip_v6_multicast_option&& ip_v6_multicast_option) = default;
        ip_v6_multicast_option& operator =(ip_v6_multicast_option&&) = default;
        ip_v6_multicast_option(const ip_v6_multicast_option& ip_v6_multicast_option) = default;
        ip_v6_multicast_option& operator =(const ip_v6_multicast_option&) = default;
        /// @endcond
        
        /// @name Public Properties
        
        /// @{
        /// @brief Gets or sets the IP address of a multicast group.
        /// @param group An xtd::net::ip_address that contains the Internet address of a multicast group.
        xtd::net::ip_address group = xtd::net::ip_address::ip_v6_none;
        
        /// @brief Gets or sets the interface index that is associated with a multicast group.
        /// @param value A uint32 value that specifies the address of the interface.
        /// @remarks This property specifies the interface on which data is received or sent.
        xtd::uint32 interface_index = 0;
        /// @}
      };
    }
  }
}
