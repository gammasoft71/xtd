/// @file
/// @brief Contains xtd::net::sockets::select_mode enum.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../../enum.hpp"

/// @cond
#undef unix
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief The xtd::net::sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
    namespace sockets {
      /// @brief Defines the polling modes for the xtd::net::sockets::socket::poll method.
      /// ```cpp
      /// enum class select_mode
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/net/sockets/select_mode>
      /// ```
      /// @par Namespace
      /// xtd::net::sockets
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core
      /// @remarks The xtd::net::sockets::select_mode enumeration defines the polling modes that can be passed to the xtd::net::sockets::socket::poll method. Use the xtd::net::sockets::select_mode::select_read value to determine if a listening xtd::net::sockets::socket has incoming connection requests. Use the xtd::net::sockets::select_mode::select_write value to determine if a xtd::net::sockets::socket is writeable. Use the xtd::net::sockets::select_mode::select_error value to determine if there is an error condition present on the xtd::net::sockets::socket. For explanations of writeability, readability, and the presence of error conditions, see the xtd::net::sockets::socket::poll method.
      enum class select_mode {
        /// @brief Read status mode.
        select_read = 0,
        /// @brief Write status mode.
        select_write = 1,
        /// @brief Error status mode.
        select_error = 2
      };
    }
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::net::sockets::select_mode> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::net::sockets::select_mode> {{xtd::net::sockets::select_mode::select_read, "select_read"}, {xtd::net::sockets::select_mode::select_write, "select_write"}, {xtd::net::sockets::select_mode::select_error, "select_error"}};}
};
/// @endcond
