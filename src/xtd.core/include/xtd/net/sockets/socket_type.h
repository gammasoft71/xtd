/// @file
/// @brief Contains xtd::net::sockets::socket_type enum.
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
      /// @brief Specifies the type of socket that an instance of the xtd::net::sockets::socket class represents.
      /// @par Namespace
      /// xtd::net::sockets
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core
      /// @remarks Before a xtd::net::sockets::socket can send and receive data, it must first be created using an xtd::net::sockects::address_family, a xtd::net::sockets::socket_type, and a xtd::net::sockets::protocol_type. The xtd::net::sockets::socket_type enumeration provides several options for defining the type of xtd::net::sockets::socket that you intend to open.
      /// @note xtd::net::sockets::socket_type will sometimes implicitly indicate which xtd::net::sockets::protocol_type will be used within an xtd::net::sockets::address_family. For example when the xtd::net::sockets::socket_type is xtd::net::sockets::socket_typedgram, the xtd::net::sockets::protocol_type is always xtd::net::sockets::protocol_type::udp. When the xtd::net::sockets::socket_type is xtd::net::sockets::socket_type::stream, the xtd::net::sockets::protocol_type is always xtd::net::sockets::protocol_type::tcp. If you try to create a xtd::net::sockets::socket with an incompatible combination, xtd::net::sockets::socket will throw a xtd::net::sockets::socket_exception.
      enum class socket_type {
        /// @brief Specifies an unknown xtd::net::sockets::socket type.
        unknown = -1,
        /// @brief Supports reliable, two-way, connection-based byte streams without the duplication of data and without preservation of boundaries. A xtd::net::sockets::socket of this type communicates with a single peer and requires a remote host connection before communication can begin. xtd::net::sockets::socket_types::stream uses the Transmission Control Protocol (xtd::net::sockets::protocol_type::tcp) and the xtd::net::sockets::address_family::inter_network address family.
        stream = 1,
        /// @brief Supports datagrams, which are connectionless, unreliable messages of a fixed (typically small) maximum length. Messages might be lost or duplicated and might arrive out of order. A xtd::net::sockets::socket of type xtd::net::sockets::socket_type::dgram requires no connection prior to sending and receiving data, and can communicate with multiple peers. xtd::net::sockets::socket_type::dgram uses the Datagram Protocol (xtd::net::sockets::protocol_type::udp) and the xtd::net::sockets::address_family::inter_network address family.
        dgram = 2,
        /// @brief Supports access to the underlying transport protocol. Using the xtd::net::sockets::socket_type::raw, you can communicate using protocols like Internet Control Message Protocol (xtd::net::sockets::protocol_type::icmp) and Internet Group Management Protocol (xtd::net::sockets::protocol_type::Igmp). Your application must provide a complete IP header when sending. Received datagrams return with the IP header and options intact.
        raw = 3,
        /// @brief Supports connectionless, message-oriented, reliably delivered messages, and preserves message boundaries in data. xtd::net::sockets::socket_type::rdm (Reliably Delivered Messages) messages arrive unduplicated and in order. Furthermore, the sender is notified if messages are lost. If you initialize a xtd::net::sockets::socket using xtd::net::sockets::socket_type::rdm, you do not require a remote host connection before sending and receiving data. With xtd::net::sockets::socket_typerdm, you can communicate with multiple peers.
        rdm = 4,
        /// @brief Provides connection-oriented and reliable two-way transfer of ordered byte streams across a network. xtd::net::sockets::socket_type::seqpacket does not duplicate data, and it preserves boundaries within the data stream. A xtd::net::sockets::socket of type xtd::net::sockets::socket_type::seqpacket communicates with a single peer and requires a remote host connection before communication can begin.
        seqpacket = 5,
      };

      /// @cond
      inline std::ostream& operator<<(std::ostream& os, socket_type value) {return os << to_string(value, {{socket_type::unknown, "unknown"}, {socket_type::stream, "stream"}, {socket_type::dgram, "dgram"}, {socket_type::raw, "raw"}, {socket_type::rdm, "rdm"}, {socket_type::seqpacket, "seqpacket"}});}
      inline std::wostream& operator<<(std::wostream& os, socket_type value) {return os << to_string(value, {{socket_type::unknown, L"unknown"}, {socket_type::stream, L"stream"}, {socket_type::dgram, L"dgram"}, {socket_type::raw, L"raw"}, {socket_type::rdm, L"rdm"}, {socket_type::seqpacket, L"seqpacket"}});}
      /// @endcond
    }
  }
}
