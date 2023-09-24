/// @file
/// @brief Contains xtd::net::sockets::socket_shutdown enum.
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
      /// @brief Defines constants that are used by the xtd::net::sockets::socket::shutdown method.
      /// @code
      /// enum class socket_shutdown
      /// @endcode
      /// @par Header
      /// @code #include <xtd/net/sockets/socket_shutdown> @endcode
      /// @par Namespace
      /// xtd::net::sockets
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core
      /// @remarks The xtd::net::sockets::socket_shutdown enumeration defines the values that can be passed to the xtd::net::sockets::socket::shutdown method.
      enum class socket_shutdown {
        /// @brief Disables a xtd::net::sockets::socket for receiving. This field is constant.
        receive = 0,
        /// @brief Disables a xtd::net::sockets::socket for sending. This field is constant.
        send = 1,
        /// @brief Disables a xtd::net::sockets::socket for both sending and receiving. This field is constant.
        both = 2
      };
      
      /// @cond
      /// @endcond
    }
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::net::sockets::socket_shutdown> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::net::sockets::socket_shutdown> {{xtd::net::sockets::socket_shutdown::receive, "receive"}, {xtd::net::sockets::socket_shutdown::send, "send"}, {xtd::net::sockets::socket_shutdown::both, "both"}};}
};
/// @endcond
