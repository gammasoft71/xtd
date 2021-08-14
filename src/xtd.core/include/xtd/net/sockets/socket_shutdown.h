/// @file
/// @brief Contains xtd::net::sockets::socket_shutdown enum.
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
      /// @brief Defines constants that are used by the xtd::net::sockets::socket::shutdown method.
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
      inline std::ostream& operator<<(std::ostream& os, socket_shutdown value) {return os << to_string(value, {{socket_shutdown::receive, "receive"}, {socket_shutdown::send, "send"}, {socket_shutdown::both, "both"}});}
      inline std::wostream& operator<<(std::wostream& os, socket_shutdown value) {return os << to_string(value, {{socket_shutdown::receive, L"receive"}, {socket_shutdown::send, L"send"}, {socket_shutdown::both, L"both"}});}
      /// @endcond
    }
  }
}
