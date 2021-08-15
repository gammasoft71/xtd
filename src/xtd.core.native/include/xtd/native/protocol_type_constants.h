/// @file
/// @brief Contains protocol type constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>

/// @brief Specifies an unknown Socket type.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native protocol_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PROTOCOL_TYPE_UNKNWON = -1;

/// @brief IPv6 Hop by Hop Options header.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native protocol_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PROTOCOL_TYPE_IP_V6_HOP_BY_HOP_OPTIONS = 0;

/// @brief Undpecified Protocol.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native protocol_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PROTOCOL_TYPE_UNSPECIFIED = 0;

/// @brief Internet Protocol.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native protocol_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PROTOCOL_TYPE_IP = 0;

/// @brief Internet Control Message Protocol.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native protocol_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PROTOCOL_TYPE_ICMP = 1;

/// @brief Internet Group Management Protocol.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native protocol_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PROTOCOL_TYPE_IGMP = 2;

/// @brief Gateway To Gateway Protocol.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native protocol_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PROTOCOL_TYPE_GGP = 3;

/// @brief Internet Protocol version 4.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native protocol_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PROTOCOL_TYPE_IP_V4 = 4;

/// @brief Transmission Control Protocol.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native protocol_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PROTOCOL_TYPE_TCP = 6;

/// @brief PARC Universal Packet Protocol.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native protocol_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PROTOCOL_TYPE_PUP = 12;

/// @brief User Datagram Protocol.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native protocol_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PROTOCOL_TYPE_UDP = 17;

/// @brief Internet Datagram Protocol.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native protocol_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PROTOCOL_TYPE_IDP = 22;

/// @brief Internet Protocol version 6 (IPv6).
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native protocol_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PROTOCOL_TYPE_IP_V6 = 41;

/// @brief IPv6 Routing header.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native protocol_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PROTOCOL_TYPE_IP_V6_ROUTING_HEADER = 43;

/// @brief IPv6 Fragment header.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native protocol_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PROTOCOL_TYPE_IP_V6_FRAGMENT_HEADER = 44;

/// @brief IPv6 Encapsulating Security Payload header.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native protocol_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PROTOCOL_TYPE_IP_SEC_ENCAPSULATING_SECURITY_PAYLOAD = 50;

/// @brief IPv6 Authentication header. For details, see RFC 2292 section 2.2.1, available at http://www.ietf.org.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native protocol_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PROTOCOL_TYPE_IP_SEC_AUTHENTIFICATION_HEADER = 51;

/// @brief Internet Control Message Protocol for IPv6.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native protocol_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PROTOCOL_TYPE_ICMP_V6 = 58;

/// @brief IPv6 No next header.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native protocol_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PROTOCOL_TYPE_IP_V6_NO_NEXT_HEADER = 59;

/// @brief IPv6 Destination Options header.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native protocol_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PROTOCOL_TYPE_IP_V6_DESTINATION_OPTIONS = 60;

/// @brief Net Disk Protocol (unofficial).
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native protocol_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PROTOCOL_TYPE_ND = 77;

/// @brief Raw IP packet protocol.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native protocol_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PROTOCOL_TYPE_RAW = 255;

/// @brief Internet Packet Exchange Protocol.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native protocol_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PROTOCOL_TYPE_IPX = 1000;

/// @brief Sequenced Packet Exchange protocol.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native protocol_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PROTOCOL_TYPE_SPX = 1256;

/// @brief Sequenced Packet Exchange version 2 protocol.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native protocol_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PROTOCOL_TYPE_SPX_2 = 1257;
