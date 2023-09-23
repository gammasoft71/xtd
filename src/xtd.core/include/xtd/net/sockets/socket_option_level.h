/// @file
/// @brief Contains xtd::net::sockets::socket_option_level enum.
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
      /// @brief Defines socket option levels for the xtd::net::sockets::socket::set_socket_option and xtd::net::sockets::socket::get_socket_option methods.
      /// @code
      /// enum class socket_option_level
      /// @endcode
      /// @par Header
      /// @code #include <xtd/net/sockets/socket_option_level> @endcode
      /// @par Namespace
      /// xtd::net::sockets
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core
      /// @remarks The xtd::net::sockets::socket_option_level enumeration defines the socket option levels that can be passed to the xtd::net::sockets::socket::set_socket_option and xtd::net::sockets::socket::get_socket_option methods. xtd::net::sockets::socket_option_name enumerated values are grouped by xtd::net::sockets::socket_option_level.
      enum class socket_option_level {
        /// @brief Socket options apply to all sockets.
        socket = 65535,
        /// @brief Socket options apply only to IP sockets.
        ip = 0,
        /// @brief Socket options apply only to IPv6 sockets.
        ip_v6 = 41,
        /// @brief Socket options apply only to TCP sockets.
        tcp = 6,
        /// @brief Socket options apply only to UDP sockets.
        udp = 17,
      };
    }
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::net::sockets::socket_option_level> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::net::sockets::socket_option_level> {{xtd::net::sockets::socket_option_level::socket, "socket"}, {xtd::net::sockets::socket_option_level::ip, "ip"}, {xtd::net::sockets::socket_option_level::ip_v6, "ip_v6"}, {xtd::net::sockets::socket_option_level::tcp, "tcp"}, {xtd::net::sockets::socket_option_level::udp, "udp"}};}
};
/// @endcond
