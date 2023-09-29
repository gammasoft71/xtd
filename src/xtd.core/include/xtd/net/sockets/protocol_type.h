/// @file
/// @brief Contains xtd::net::sockets::protocol_type enum.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../../enum.h"

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
      /// @code
      /// enum class protocol_type
      /// @endcode
      /// @par Header
      /// @code #include <xtd/net/sockets/protocol_type> @endcode
      /// @par Namespace
      /// xtd::net::sockets
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core
      enum class protocol_type {
        /// @brief Specifies an unknown protocol.
        unknown = -1,
        /// @brief IPv6 Hop by Hop Options header.
        ip_v6_hop_by_hop_options = 0,
        /// @brief Unspecified Protocol.
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
    }
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::net::sockets::protocol_type> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::net::sockets::protocol_type> {{xtd::net::sockets::protocol_type::unknown, "unknown"}, {xtd::net::sockets::protocol_type::ip, "ip"}, {xtd::net::sockets::protocol_type::icmp, "icmp"}, {xtd::net::sockets::protocol_type::igmp, "igmp"}, {xtd::net::sockets::protocol_type::ggp, "ggp"}, {xtd::net::sockets::protocol_type::ip_v4, "ip_v4"}, {xtd::net::sockets::protocol_type::tcp, "tcp"}, {xtd::net::sockets::protocol_type::pup, "pup"}, {xtd::net::sockets::protocol_type::udp, "udp"}, {xtd::net::sockets::protocol_type::idp, "idp"}, {xtd::net::sockets::protocol_type::ip_v6, "ip_v6"}, {xtd::net::sockets::protocol_type::ip_v6_routing_header, "ip_v6_routing_header"}, {xtd::net::sockets::protocol_type::ip_v6_fragment_header, "ip_v6_fragment_header"}, {xtd::net::sockets::protocol_type::ip_sec_encapsulating_security_payload, "ip_sec_encapsulating_security_payload"}, {xtd::net::sockets::protocol_type::ip_sec_authentication_header, "ip_sec_authentication_header"}, {xtd::net::sockets::protocol_type::icmp_v6, "icmp_v6"}, {xtd::net::sockets::protocol_type::ip_v6_no_next_header, "ip_v6_no_next_header"}, {xtd::net::sockets::protocol_type::ip_v6_destination_options, "ip_v6_destination_options"}, {xtd::net::sockets::protocol_type::nd, "nd"}, {xtd::net::sockets::protocol_type::raw, "raw"}, {xtd::net::sockets::protocol_type::ipx, "ipx"}, {xtd::net::sockets::protocol_type::spx, "spx"}, {xtd::net::sockets::protocol_type::spx_2, "spx_2"}};}
};
/// @endcond
