/// @file
/// @brief Contains xtd::net::sockets::ip_packet_information class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once

#include "../ip_address"

/// @cond
#undef unix
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief The xtd::net::sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
    namespace sockets {
      /// @cond
      class socket;
      /// @endcond
      
      /// @brief Gets the network interface information that is associated with a call to xtd::net::sockets::socket::receive_message_from or xtd::net::sockets::socket::end_receive_message_from.
      /// @code
      /// class core_export_ ip_packet_information : public xtd::object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::net::sockets::ip_packet_information
      /// @par Header
      /// @code #include <xtd/net/sockets/ip_packet_information> @endcode
      /// @par Namespace
      /// xtd::net::sockets
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core
      class core_export_ ip_packet_information : public xtd::object {
      public:
        /// @name Constructors
        
        /// @{
        /// @brief Creates an empty xtd::net::sockets::ip_packet_information instance.
        ip_packet_information() = default;
        /// @}
        
        /// @cond
        ip_packet_information(ip_packet_information&&) = default;
        ip_packet_information(const ip_packet_information&) = default;
        ip_packet_information& operator =(const ip_packet_information&) = default;
        /// @endcond
        
        /// @name Properties
        
        /// @{
        /// @brief Gets the origin information of the packet that was received as a result of calling the xtd::net::sockets::socket::receive_message_from method or xtd::net::sockets::socket::end_receive_message_from method.
        /// @return An xtd::net::ip_address that indicates the origin information of the packet that was received as a result of calling the xtd::net::sockets::socket::receive_message_from method or xtd::net::sockets::socket::end_receive_message_from method. For packets that were sent from a unicast address, the xtd::net::sockets::ip_packet_information::address property will return the xtd::net::ip_address of the sender; for multicast or broadcast packets, the xtd::net::sockets::ip_packet_information::address property will return the multicast or broadcast xtd::net::ip_address.
        const xtd::net::ip_address& address() const noexcept;
        
        /// @brief Gets the network interface information that is associated with a call to xtd::net::sockets::socket::receive_message_from method or xtd::net::sockets::socket::end_receive_message_from.
        /// @return An int32 value, which represents the index of the network interface. You can use this index with xtd::net::network_information::network_interface::get_all_network_interfaces() to get more information about the relevant interface.
        int32 interface() const noexcept;
        /// @}
        
      private:
        friend class socket;
        xtd::net::ip_address address_;
        int32 address_interface_ = 0;
      };
    }
  }
}
