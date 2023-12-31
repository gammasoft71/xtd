/// @file
/// @brief Contains xtd::net::sockets::socket_flags enum.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
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
      /// @brief Specifies socket send and receive behaviors. This enumeration has a flags attribute that allows a bitwise combination of its member values.
      /// @code
      /// enum class socket_flags
      /// @endcode
      /// @par Header
      /// @code #include <xtd/net/sockets/socket_flags> @endcode
      /// @par Namespace
      /// xtd::net::sockets
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core
      enum class socket_flags {
        /// @brief Use no flags for this call.
        none = 0x0000,
        /// @brief Process out-of-band data.
        out_of_band = 0x0001,
        /// @brief Peek at the incoming message.
        peek = 0x0002,
        /// @brief Send without using routing tables.
        dont_route = 0x0004,
        /// @brief Provides a standard value for the number of WSABUF structures that are used to send and receive data.
        max_io_vector_length = 0x0010,
        /// @brief The message was too large to fit into the specified buffer and was truncated.
        truncated = 0x0100,
        /// @brief Indicates that the control data did not fit into an internal 64-KB buffer and was truncated.
        control_data_truncated = 0x0200,
        /// @brief Indicates a broadcast packet.
        broadcast = 0x0400,
        /// @brief Indicates a multicast packet.
        multicast = 0x0800,
        /// @brief Partial send or receive for message.
        partial = 0x8000,
      };
    }
  }
}

/// @cond
flags_attribute_(xtd::net::sockets, socket_flags);

template<> struct xtd::enum_register<xtd::net::sockets::socket_flags> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::net::sockets::socket_flags> {{xtd::net::sockets::socket_flags::none, "none"}, {xtd::net::sockets::socket_flags::out_of_band, "out_of_band"}, {xtd::net::sockets::socket_flags::peek, "peek"}, {xtd::net::sockets::socket_flags::dont_route, "dont_route"}, {xtd::net::sockets::socket_flags::max_io_vector_length, "max_io_vector_length"}, {xtd::net::sockets::socket_flags::truncated, "truncated"}, {xtd::net::sockets::socket_flags::control_data_truncated, "control_data_truncated"}, {xtd::net::sockets::socket_flags::broadcast, "broadcast"}, {xtd::net::sockets::socket_flags::multicast, "multicast"}, {xtd::net::sockets::socket_flags::partial, "partial"}};}
};
/// @endcond
