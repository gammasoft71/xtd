/// @file
/// @brief Contains xtd::net::sockets::socket_information_options enum.
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
      /// @brief Describes states for a xtd::net::sockets::socket. This enumeration has a flags attribute that allows a bitwise combination of its member values.
      /// @code
      /// enum class socket_information_options
      /// @endcode
      /// @par Header
      /// @code #include <xtd/net/sockets/socket_information_options> @endcode
      /// @par Namespace
      /// xtd::net::sockets
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core
      /// @ingroup xtd_core
      enum class socket_information_options {
        /// @brief Use no flags for this call.
        none = 0x00,
        /// @brief The Socket is nonblocking.
        non_blocking = 0x01,
        /// @brief The Socket is connected.
        connected = 0x02,
        /// @brief The Socket is listening for new connections.
        listening = 0x04,
        /// @brief The Socket uses overlapped I/O.
        use_only_overlapped_io = 0x08,
      };
    }
  }
}

/// @cond
flags_attribute_(xtd::net::sockets, socket_information_options);

template<> struct xtd::enum_register<xtd::net::sockets::socket_information_options> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::net::sockets::socket_information_options> {{xtd::net::sockets::socket_information_options::none, "none"}, {xtd::net::sockets::socket_information_options::non_blocking, "non_blocking"}, {xtd::net::sockets::socket_information_options::connected, "connected"}, {xtd::net::sockets::socket_information_options::listening, "listening"}, {xtd::net::sockets::socket_information_options::use_only_overlapped_io, "use_only_overlapped_io"}};}
};
/// @endcond
