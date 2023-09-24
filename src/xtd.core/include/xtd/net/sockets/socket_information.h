/// @file
/// @brief Contains xtd::net::sockets::socket_information class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "socket_information_options"
#include "../../core_export"
#include "../../object"
#include "../../types"
#include "../../ustring"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief The xtd::net::sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
    namespace sockets {
      /// @brief Encapsulates the information that is necessary to duplicate a xtd::net::sockets::socket.
      /// @code
      /// class core_export_ socket_information : public xtd::object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::net::sockets::socket_information
      /// @par Header
      /// @code #include <xtd/net/sockets/socket_information> @endcode
      /// @par Namespace
      /// xtd::net::sockets
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core
      /// @remarks xtd::net::sockets::socket::duplicate_and_close creates a xtd::net::sockets::socket_information instance for use with the xtd::net::sockets::socket::socket constructor.
      class core_export_ socket_information : public xtd::object {
      public:
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::net::sockets::socket_information class.
        socket_information() = default;
        /// @}
        
        /// @cond
        socket_information(socket_information&& socket_information) = default;
        socket_information(const socket_information& socket_information) = default;
        socket_information& operator =(const socket_information&) = default;
        /// @endcond
        
        /// @name Properties
        
        /// @{
        /// @brief Gets the options for a xtd::net::sockets::socket.
        /// @return A xtd::net::sockets::socket_information_options instance.
        /// @remarks Options include xtd::net::sockets::socket_information_options::connected, xtd::net::sockets::socket_information_options::listening, xtd::net::sockets::socket_information_options::non_blocking, and xtd::net::sockets::socket_information_options::use_only_overlapped_io.
        xtd::net::sockets::socket_information_options options() const noexcept;
        /// @brief Sets the options for a xtd::net::sockets::socket.
        /// @param value A xtd::net::sockets::socket_information_options instance.
        /// @return This current instance.
        /// @remarks Options include xtd::net::sockets::socket_information_options::connected, xtd::net::sockets::socket_information_options::listening, xtd::net::sockets::socket_information_options::non_blocking, and xtd::net::sockets::socket_information_options::use_only_overlapped_io.
        socket_information& options(xtd::net::sockets::socket_information_options value) noexcept;
        
        /// @brief Gets the protocol information for a xtd::net::sockets::socket.
        /// @return An array of byte.
        const std::vector<xtd::byte>& protocol_information() const noexcept;
        /// @brief Sets the protocol information for a xtd::net::sockets::socket.
        /// @param value An array of byte.
        /// @return This current instance.
        socket_information& protocol_information(const std::vector<xtd::byte>& value) noexcept;
        /// @}
        
      private:
        xtd::net::sockets::socket_information_options options_ = xtd::net::sockets::socket_information_options::none;
        std::vector<xtd::byte> protocol_information_;
      };
    }
  }
}
