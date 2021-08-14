/// @file
/// @brief Contains xtd::net::sockets::protocol_type enum.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include "../../ustring.h"

/// @cond
#undef unix
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief The xtd::net::sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
    namespace sockets {
      /// @brief Specifies the protocols that the xtd::net::sockets::socket class supports.
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core
      enum class protocol_type {
        /// @brief Specifies an unknown Socket type.
        unknown = -1,
        /// @brief IPv6 Hop by Hop Options header.
        ip_v6_hop_by_hop_options = 0,
        /// @brief Undpecified Protocol.
        unspecified = 0,
        /// @brief Internet Protocol.
        ip = 0,
        /// @brief Internet Control Message Protocol.
        icmp = 1,
        /// @brief Internet Group Management Protocol.
        igmp = 2,
        /// @brief Gateway To Gateway Protocol.
        ggp = 3,
        /// @brief Internet Protocol version 4.
        ip_v4 = 4,
        /// @brief Transmission Control Protocol.
        tcp = 6,
        /// @brief PARC Universal Packet Protocol.
        pup = 12,
        /// @brief User Datagram Protocol.
        udp = 17,
        /// @brief Internet Datagram Protocol.
        idp = 22,
        /// @brief Internet Protocol version 6 (IPv6).
        ip_v6 = 41,
        /// @brief IPv6 Routing header.
        ip_v6_routing_header = 43,
        /// @brief IPv6 Fragment header.
        ip_v6_fragment_header = 44,
        /// @brief IPv6 Encapsulating Security Payload header.
        ip_sec_encapsulating_security_payload = 50,
        /// @brief IPv6 Authentication header. For details, see RFC 2292 section 2.2.1, available at http://www.ietf.org.
        ip_sec_authentication_header = 51,
        /// @brief Internet Control Message Protocol for IPv6.
        icmp_v6 = 58,
        /// @brief IPv6 No next header.
        ip_v6_no_next_header = 59,
        /// @brief IPv6 Destination Options header.
        ip_v6_destination_options = 60,
        /// @brief Net Disk Protocol (unofficial).
        nd = 77,
        /// @brief Raw IP packet protocol.
        raw = 255,
        /// @brief Internet Packet Exchange Protocol.
        ipx = 1000,
        /// @brief Sequenced Packet Exchange protocol.
        spx = 1256,
        /// @brief Sequenced Packet Exchange version 2 protocol.
        spx_2 = 1257,
      };

      /// @cond
      inline std::ostream& operator<<(std::ostream& os, protocol_type value) {return os << to_string(value, {{protocol_type::unknown, "unknown"}, {protocol_type::ip_v6_hop_by_hop_options, "ip_v6_hop_by_hop_options"}, {protocol_type::unspecified, "unspecified"}, {protocol_type::ip, "ip"}, {protocol_type::icmp, "icmp"}, {protocol_type::igmp, "igmp"}, {protocol_type::ggp, "ggp"}, {protocol_type::ip_v4, "ip_v4"}, {protocol_type::tcp, "tcp"}, {protocol_type::pup, "pup"}, {protocol_type::udp, "udp"}, {protocol_type::idp, "idp"}, {protocol_type::ip_v6, "ip_v6"}, {protocol_type::ip_v6_routing_header, "ip_v6_routing_header"}, {protocol_type::ip_v6_fragment_header, "ip_v6_fragment_header"}, {protocol_type::ip_sec_encapsulating_security_payload, "ip_sec_encapsulating_security_payload"}, {protocol_type::ip_sec_authentication_header, "ip_sec_authentication_header"}, {protocol_type::icmp_v6, "icmp_v6"}, {protocol_type::ip_v6_no_next_header, "ip_v6_no_next_header"}, {protocol_type::ip_v6_destination_options, "ip_v6_destination_options"}, {protocol_type::nd, "nd"}, {protocol_type::raw, "raw"}, {protocol_type::ipx, "ipx"}, {protocol_type::spx, "spx"}, {protocol_type::spx_2, "spx_2"}});}
      inline std::wostream& operator<<(std::wostream& os, protocol_type value) {return os << to_string(value, {{protocol_type::unknown, L"unknown"}, {protocol_type::ip_v6_hop_by_hop_options, L"ip_v6_hop_by_hop_options"}, {protocol_type::unspecified, L"unspecified"}, {protocol_type::ip, L"ip"}, {protocol_type::icmp, L"icmp"}, {protocol_type::igmp, L"igmp"}, {protocol_type::ggp, L"ggp"}, {protocol_type::ip_v4, L"ip_v4"}, {protocol_type::tcp, L"tcp"}, {protocol_type::pup, L"pup"}, {protocol_type::udp, L"udp"}, {protocol_type::idp, L"idp"}, {protocol_type::ip_v6, L"ip_v6"}, {protocol_type::ip_v6_routing_header, L"ip_v6_routing_header"}, {protocol_type::ip_v6_fragment_header, L"ip_v6_fragment_header"}, {protocol_type::ip_sec_encapsulating_security_payload, L"ip_sec_encapsulating_security_payload"}, {protocol_type::ip_sec_authentication_header, L"ip_sec_authentication_header"}, {protocol_type::icmp_v6, L"icmp_v6"}, {protocol_type::ip_v6_no_next_header, L"ip_v6_no_next_header"}, {protocol_type::ip_v6_destination_options, L"ip_v6_destination_options"}, {protocol_type::nd, L"nd"}, {protocol_type::raw, L"raw"}, {protocol_type::ipx, L"ipx"}, {protocol_type::spx, L"spx"}, {protocol_type::spx_2, L"spx_2"}});}
      /// @endcond
    }
  }
}
