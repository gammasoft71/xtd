
/// @file
/// @brief Contains socket type constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>

/// @brief Specifies an unknown xtd::net::sockets::socket type.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_TYPE_UNKNOWN = -1;

/// @brief Supports reliable, two-way, connection-based byte streams without the duplication of data and without preservation of boundaries. A xtd::net::sockets::socket of this type communicates with a single peer and requires a remote host connection before communication can begin. xtd::net::sockets::socket_types::stream uses the Transmission Control Protocol (xtd::net::sockets::protocol_type::tcp) and the xtd::net::sockets::address_family::inter_network address family.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_TYPE_STREAM = 1;

/// @brief Supports datagrams, which are connectionless, unreliable messages of a fixed (typically small) maximum length. Messages might be lost or duplicated and might arrive out of order. A xtd::net::sockets::socket of type xtd::net::sockets::socket_type::dgram requires no connection prior to sending and receiving data, and can communicate with multiple peers. xtd::net::sockets::socket_type::dgram uses the Datagram Protocol (xtd::net::sockets::protocol_type::udp) and the xtd::net::sockets::address_family::inter_network address family.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_TYPE_DGRAM = 2;

/// @brief Supports access to the underlying transport protocol. Using the xtd::net::sockets::socket_type::raw, you can communicate using protocols like Internet Control Message Protocol (xtd::net::sockets::protocol_type::icmp) and Internet Group Management Protocol (xtd::net::sockets::protocol_type::Igmp). Your application must provide a complete IP header when sending. Received datagrams return with the IP header and options intact.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_TYPE_RAW = 3;

/// @brief Supports connectionless, message-oriented, reliably delivered messages, and preserves message boundaries in data. xtd::net::sockets::socket_type::rdm (Reliably Delivered Messages) messages arrive unique and in order. Furthermore, the sender is notified if messages are lost. If you initialize a xtd::net::sockets::socket using xtd::net::sockets::socket_type::rdm, you do not require a remote host connection before sending and receiving data. With xtd::net::sockets::socket_typerdm, you can communicate with multiple peers.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_TYPE_RDM = 4;

/// @brief Provides connection-oriented and reliable two-way transfer of ordered byte streams across a network. xtd::net::sockets::socket_type::seqpacket does not duplicate data, and it preserves boundaries within the data stream. A xtd::net::sockets::socket of type xtd::net::sockets::socket_type::seqpacket communicates with a single peer and requires a remote host connection before communication can begin.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native socket_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t SOCKET_TYPE_SEQPACKET = 5;
