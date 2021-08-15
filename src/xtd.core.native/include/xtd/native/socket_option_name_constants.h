
/// @file
/// @brief Contains socket option name constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>

/// @brief Record debugging information.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_DEBUG = 1;

/// @brief The socket is listening.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_ACCEPT_CONNECTION = 2;

/// @brief Allows the socket to be bound to an address that is already in use.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_REUSE_ADDRESS = 4;

//// @brief Use keep-alives.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_KEEP_ALIVE = 8;

/// @brief Do not route; send the packet directly to the interface addresses.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_DONT_ROUTE = 16;

/// @brief Permit sending broadcast messages on the socket.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_BROADCAST = 32;

/// @brief Bypass hardware when possible.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_USE_LOOPBACK = 64;

/// @brief Linger on close if unsent data is present.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_LINGER = 128;

/// @brief Receives out-of-band data in the normal data stream.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_OUT_OF_BAND_INLINE = 256;

/// @brief Close the socket gracefully without lingering.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_DONT_LINGER = -129;

/// @brief Enables a socket to be bound for exclusive access.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_EXCLUSIVE_ADDRESS_USE = -5;

/// @brief Specifies the total per-socket buffer space reserved for sends. This is unrelated to the maximum message size or the size of a TCP window.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_SEND_BUFFER = 4097;

/// @brief Specifies the total per-socket buffer space reserved for receives. This is unrelated to the maximum message size or the size of a TCP window.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_RECEIVE_BUFFER = 4098;

/// @brief Specifies the low water mark for xtd::net::sockets::socket::send operations.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_SEND_LOW_WATER = 4099;

/// @brief Specifies the low water mark for xtd::net::sockets::socket::receive operations.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_RECEIVE_LOW_WATER = 4100;

/// @brief Send a time-out. This option applies only to synchronous methods; it has no effect on asynchronous methods such as the xtd::net::sockets::socket::begin_send method.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_SEND_TIMEOUT = 4101;

/// @brief Receive a time-out. This option applies only to synchronous methods; it has no effect on asynchronous methods such as the xtd::net::sockets::socket::begin_send method.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_RECEIVE_TIMEOUT = 4102;

/// @brief Get the error status and clear.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_ERROR = 4103;

/// @brief Get the socket type.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_TYPE = 4104;

/// @brief Not supported; will throw a xtd::net::sockets::socket_exception exception if used.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_MAX_CONNECTION = 2147483647;

/// @brief Specifies the IP options to be inserted into outgoing datagrams.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_IP_OPTIONS = 1;

/// @brief Indicates that the application provides the IP header for outgoing datagrams.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_HEADER_INCLUDED = 2;

/// @brief Change the IP header type of the service field.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_TYPE_OF_SERVICE = 3;

/// @brief Set the IP header Time-to-Live field.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_IP_TIME_TO_LIVE = 4;

/// @brief Set the interface for outgoing multicast packets.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_MULTICAST_INTERFACE = 9;

/// @brief An IP multicast Time to Live.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_MULTICAST_TIME_TO_LIVE = 10;

/// @brief An IP multicast loopback.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_MULTICAST_LOOPBACK = 11;

/// @brief Add an IP group membership.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_ADD_MEMBERSHIP = 12;

/// @brief Drop an IP group membership.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_DROP_MEMBERSHIP = 13;

/// @brief Do not fragment IP datagrams.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_DONT_FRAGMENT = 14;

/// @brief Join a source group.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_ADD_SOURCE_MEMBERSHIP = 15;

/// @brief Drop a source group.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_DROP_SOURCE_MEMBERSHIP = 16;

/// @brief Block data from a source.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_BLOCK_SOURCE = 17;

/// @brief Unblock a previously blocked source.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_UNBLOCK_SOURCE = 18;

/// @brief Return information about received packets.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_PACKET_INFORMATION = 19;

/// @brief Specifies the maximum number of router hops for an Internet Protocol version 6 (IPv6) packet. This is similar to Time to Live (TTL) for Internet Protocol version 4.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_HOP_LIMIT = 21;

/// @brief Enables restriction of a IPv6 socket to a specified scope, such as addresses with the same link local or site local prefix.This socket option enables applications to place access restrictions on IPv6 sockets. Such restrictions enable an application running on a private LAN to simply and robustly harden itself against external attacks. This socket option widens or narrows the scope of a listening socket, enabling unrestricted access from public and private users when appropriate, or restricting access only to the same site, as required. This socket option has defined protection levels specified in the xtd::net::sockets::ip_protection_level enumeration.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_IP_PROTECT_LEVEL = 22;

/// @brief Indicates if a socket created for the AF_INET6 address family is restricted to IPv6 communications only. Sockets created for the AF_INET6 address family may be used for both IPv6 and IPv4 communications. Some applications may want to restrict their use of a socket created for the AF_INET6 address family to IPv6 communications only. When this value is non-zero (the default on Windows), a socket created for the AF_INET6 address family can be used to send and receive IPv6 packets only. When this value is zero, a socket created for the AF_INET6 address family can be used to send and receive packets to and from an IPv6 address or an IPv4 address. Note that the ability to interact with an IPv4 address requires the use of IPv4 mapped addresses. This socket option is supported on Windows Vista or later.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_IP_V6_ONLY = 23;

/// @brief Disables the Nagle algorithm for send coalescing.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_NO_DILAY = 1;

/// @brief Use urgent data as defined in RFC-1222. This option can be set only once; after it is set, it cannot be turned off.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_BSD_URGENT = 2;

/// @brief Use expedited data as defined in RFC-1222. This option can be set only once; after it is set, it cannot be turned off.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_EXPEDITED = 2;

/// @brief Send UDP datagrams with checksum set to zero.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_NO_CHECKSUM = 1;

/// @brief Set or get the UDP checksum coverage.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_CHECKSUM_COVERAGE = 20;

/// @brief Updates an accepted socket's properties by using those of an existing socket. This is equivalent to using the Winsock2 SO_UPDATE_ACCEPT_CONTEXT socket option and is supported only on connection-oriented sockets.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_UPDATE_ACCEPT_CONTEXT = 28683;

/// @brief Updates a connected socket's properties by using those of an existing socket. This is equivalent to using the Winsock2 SO_UPDATE_CONNECT_CONTEXT socket option and is supported only on connection-oriented sockets.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_option_name
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_OPTION_NAME_UPDATE_CONNECT_CONTEXT = 28688;
