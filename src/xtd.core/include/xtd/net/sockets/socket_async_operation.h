/// @file
/// @brief Contains xtd::net::sockets::socket_async_operation enum.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once

#include "../../enum"

/// @cond
#undef accept
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief The xtd::net::sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
    namespace sockets {
      /// @brief The type of asynchronous socket operation most recently performed with this context object.
      /// @code
      /// enum class socket_async_operation
      /// @endcode
      /// @par Header
      /// @code #include <xtd/net/sockets/socket_async_operation> @endcode
      /// @par Namespace
      /// xtd::net::sockets
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core
      /// @remarks This type describes the asynchronous socket operation that was most recently completed using a xtd::net::sockets::socket_async_event_args object. The value of the xtd::net::sockets::socket_async_event_args::last_operation property is set to xtd::net::sockets::socket_async_operation::none until the xtd::net::sockets::socket_async_event_args instance is used to begin an asynchronous socket operation. The property will then be set to the type of asynchronous operation being performed. This type more easily facilitates using a single completion callback delegate for multiple kinds of asynchronous socket operations. This type is intended for use in the socket_async_callback completion routine.
      /// @remarks The xtd::net::sockets::socket_async_operation type is used by the xtd::net::sockets::socket_async_event_args::last_operation property.
      enum class socket_async_operation {
        /// @brief none of the socket operations.
        none = 0,
        /// @brief A socket accept operation.
        accept = 1,
        /// @brief A socket connect operation.
        connect = 2,
        /// @brief A socket disconnect operation.
        disconnect = 3,
        /// @brief A socket receive operation.
        receive = 4,
        /// @brief A socket receive_from operation.
        receive_from = 5,
        /// @brief A socket receive_message_from operation.
        receive_message_from = 6,
        /// @brief A socket send operation.
        send = 7,
        /// @brief A socket send_packets operation.
        send_packets = 8,
        /// @brief A socket send_to operation.
        send_to = 9,
      };
    }
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::net::sockets::socket_async_operation> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::net::sockets::socket_async_operation> {{xtd::net::sockets::socket_async_operation::none, "none"}, {xtd::net::sockets::socket_async_operation::accept, "accept"}, {xtd::net::sockets::socket_async_operation::connect, "connect"}, {xtd::net::sockets::socket_async_operation::disconnect, "disconnect"}, {xtd::net::sockets::socket_async_operation::receive, "receive"}, {xtd::net::sockets::socket_async_operation::receive_from, "receive_from"}, {xtd::net::sockets::socket_async_operation::receive_message_from, "receive_message_from"}, {xtd::net::sockets::socket_async_operation::send, "send"}, {xtd::net::sockets::socket_async_operation::send_packets, "send_packets"}, {xtd::net::sockets::socket_async_operation::send_to, "send_to"}};}
};
/// @endcond
