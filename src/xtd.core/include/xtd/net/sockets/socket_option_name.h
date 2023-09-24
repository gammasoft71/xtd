/// @file
/// @brief Contains xtd::net::sockets::socket_option_name enum.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../../enum"

/// @cond
#undef unix
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief The xtd::net::sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
    namespace sockets {
      /// @brief Defines configuration option names.
      /// @code
      /// enum class socket_option_name
      /// @endcode
      /// @par Header
      /// @code #include <xtd/net/sockets/socket_option_name> @endcode
      /// @par Namespace
      /// xtd::net::sockets
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core
      /// @remarks The xtd::net::sockets::socket_option_name enumeration defines the name of each xtd::net::sockets::socket configuration option. Sockets can be configured with the xtd::net::sockets::socket::set_socket_option method.
      enum class socket_option_name {
        /// @brief Record debugging information.
        debug = 1,
        /// @brief The socket is listening.
        accept_connection = 2,
        /// @brief Allows the socket to be bound to an address that is already in use.
        reuse_address = 4,
        /// @brief Use keep-alive.
        keep_alive = 8,
        /// @brief Do not route; send the packet directly to the interface addresses.
        dont_route = 16,
        /// @brief Permit sending broadcast messages on the socket.
        broadcast = 32,
        /// @brief Bypass hardware when possible.
        use_loopback = 64,
        /// @brief Linger on close if unsent data is present.
        linger = 128,
        /// @brief Receives out-of-band data in the normal data stream.
        out_of_band_inline = 256,
        /// @brief Close the socket gracefully without lingering.
        dont_linger = -129,
        /// @brief Enables a socket to be bound for exclusive access.
        exclusive_address_use = -5,
        /// @brief Specifies the total per-socket buffer space reserved for sends. This is unrelated to the maximum message size or the size of a TCP window.
        send_buffer = 4097,
        /// @brief Specifies the total per-socket buffer space reserved for receives. This is unrelated to the maximum message size or the size of a TCP window.
        receive_buffer = 4098,
        /// @brief Specifies the low water mark for xtd::net::sockets::socket::send operations.
        send_low_water = 4099,
        /// @brief Specifies the low water mark for xtd::net::sockets::socket::receive operations.
        receive_low_water = 4100,
        /// @brief Send a time-out. This option applies only to synchronous methods; it has no effect on asynchronous methods such as the xtd::net::sockets::socket::begin_send method.
        send_timeout = 4101,
        /// @brief Receive a time-out. This option applies only to synchronous methods; it has no effect on asynchronous methods such as the xtd::net::sockets::socket::begin_send method.
        receive_timeout = 4102,
        /// @brief Gets the error status and clear.
        error = 4103,
        /// @brief Gets the socket type.
        type = 4104,
        /// @brief Not supported; will throw a xtd::net::sockets::socket_exception exception if used.
        max_connections = 2147483647,
        /// @brief Specifies the IP options to be inserted into outgoing datagrams.
        ip_options = 1,
        /// @brief Indicates that the application provides the IP header for outgoing datagrams.
        header_included = 2,
        /// @brief Change the IP header type of the service field.
        type_of_service = 3,
        /// @brief Sets the IP header Time-to-Live field.
        ip_time_to_live = 4,
        /// @brief Sets the interface for outgoing multicast packets.
        multicast_interface = 9,
        /// @brief An IP multicast Time to Live.
        multicast_time_to_live = 10,
        /// @brief An IP multicast loopback.
        multicast_loopback = 11,
        /// @brief Add an IP group membership.
        add_membership = 12,
        /// @brief Drop an IP group membership.
        drop_membership = 13,
        /// @brief Do not fragment IP datagrams.
        dont_fragment = 14,
        /// @brief Join a source group.
        add_source_membership = 15,
        /// @brief Drop a source group.
        drop_source_membership = 16,
        /// @brief Block data from a source.
        block_source = 17,
        /// @brief Unblock a previously blocked source.
        unblock_source = 18,
        /// @brief Return information about received packets.
        packet_information = 19,
        /// @brief Specifies the maximum number of router hops for an Internet Protocol version 6 (IPv6) packet. This is similar to Time to Live (TTL) for Internet Protocol version 4.
        hop_limit = 21,
        /// @brief Enables restriction of a IPv6 socket to a specified scope, such as addresses with the same link local or site local prefix.This socket option enables applications to place access restrictions on IPv6 sockets. Such restrictions enable an application running on a private LAN to simply and robustly harden itself against external attacks. This socket option widens or narrows the scope of a listening socket, enabling unrestricted access from public and private users when appropriate, or restricting access only to the same site, as required. This socket option has defined protection levels specified in the xtd::net::sockets::ip_protection_level enumeration.
        ip_protection_level = 23,
        /// @brief Indicates if a socket created for the AF_INET6 address family is restricted to IPv6 communications only. Sockets created for the AF_INET6 address family may be used for both IPv6 and IPv4 communications. Some applications may want to restrict their use of a socket created for the AF_INET6 address family to IPv6 communications only. When this value is non-zero (the default on Windows), a socket created for the AF_INET6 address family can be used to send and receive IPv6 packets only. When this value is zero, a socket created for the AF_INET6 address family can be used to send and receive packets to and from an IPv6 address or an IPv4 address. Note that the ability to interact with an IPv4 address requires the use of IPv4 mapped addresses. This socket option is supported on Windows Vista or later.
        ip_v6_only = 27,
        /// @brief Disables the Nagle algorithm for send coalescing.
        no_delay = 1,
        /// @brief Use urgent data as defined in RFC-1222. This option can be set only once; after it is set, it cannot be turned off.
        bsd_urgent = 2,
        /// @brief Use expedited data as defined in RFC-1222. This option can be set only once; after it is set, it cannot be turned off.
        expedited = 2,
        /// @brief Send UDP datagrams with checksum set to zero.
        no_checksum = 1,
        /// @brief Sets or get the UDP checksum coverage.
        checksum_coverage = 20,
        /// @brief Updates an accepted socket's properties by using those of an existing socket. This is equivalent to using the Winsock2 SO_UPDATE_ACCEPT_CONTEXT socket option and is supported only on connection-oriented sockets.
        update_accept_context = 28683,
        /// @brief Updates a connected socket's properties by using those of an existing socket. This is equivalent to using the Winsock2 SO_UPDATE_CONNECT_CONTEXT socket option and is supported only on connection-oriented sockets.
        update_connect_context = 28688
      };
    }
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::net::sockets::socket_option_name> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::net::sockets::socket_option_name> {{xtd::net::sockets::socket_option_name::debug, "debug"}, {xtd::net::sockets::socket_option_name::accept_connection, "accept_connection"}, {xtd::net::sockets::socket_option_name::reuse_address, "reuse_address"}, {xtd::net::sockets::socket_option_name::keep_alive, "keep_alive"}, {xtd::net::sockets::socket_option_name::dont_route, "dont_route"}, {xtd::net::sockets::socket_option_name::broadcast, "broadcast"}, {xtd::net::sockets::socket_option_name::use_loopback, "use_loopback"}, {xtd::net::sockets::socket_option_name::linger, "linger"}, {xtd::net::sockets::socket_option_name::out_of_band_inline, "out_of_band_inline"}, {xtd::net::sockets::socket_option_name::dont_linger, "dont_linger"}, {xtd::net::sockets::socket_option_name::exclusive_address_use, "exclusive_address_use"}, {xtd::net::sockets::socket_option_name::send_buffer, "send_buffer"}, {xtd::net::sockets::socket_option_name::receive_buffer, "receive_buffer"}, {xtd::net::sockets::socket_option_name::send_low_water, "send_low_water"}, {xtd::net::sockets::socket_option_name::receive_low_water, "receive_low_water"}, {xtd::net::sockets::socket_option_name::send_timeout, "send_timeout"}, {xtd::net::sockets::socket_option_name::receive_timeout, "receive_timeout"}, {xtd::net::sockets::socket_option_name::error, "error"}, {xtd::net::sockets::socket_option_name::type, "type"}, {xtd::net::sockets::socket_option_name::max_connections, "max_connections"}, {xtd::net::sockets::socket_option_name::type_of_service, "type_of_service"}, {xtd::net::sockets::socket_option_name::multicast_interface, "multicast_interface"}, {xtd::net::sockets::socket_option_name::multicast_time_to_live, "multicast_time_to_live"}, {xtd::net::sockets::socket_option_name::multicast_loopback, "multicast_loopback"}, {xtd::net::sockets::socket_option_name::add_membership, "add_membership"}, {xtd::net::sockets::socket_option_name::drop_membership, "drop_membership"}, {xtd::net::sockets::socket_option_name::block_source, "block_source"}, {xtd::net::sockets::socket_option_name::unblock_source, "unblock_source"}, {xtd::net::sockets::socket_option_name::packet_information, "packet_information"}, {xtd::net::sockets::socket_option_name::hop_limit, "hop_limit"}, {xtd::net::sockets::socket_option_name::ip_protection_level, "ip_protection_level"}, {xtd::net::sockets::socket_option_name::ip_v6_only, "ip_v6_only"}, {xtd::net::sockets::socket_option_name::checksum_coverage, "checksum_coverage"}, {xtd::net::sockets::socket_option_name::update_accept_context, "update_accept_context"}, {xtd::net::sockets::socket_option_name::update_connect_context, "update_connect_context"}};}
};
/// @endcond
