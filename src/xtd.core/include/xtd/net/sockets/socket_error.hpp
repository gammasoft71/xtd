/// @file
/// @brief Contains xtd::net::sockets::socket_error enum.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
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
      /// @brief Defines error codes for the xtd::net::sockets::socket class.
      /// ```cpp
      /// enum class socket_error
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/net/sockets/socket_error>
      /// ```
      /// @par Namespace
      /// xtd::net::sockets
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core
      enum class socket_error {
        /// @brief An unspecified error occurred
        sock_error = -1,
        /// @brief Operation successful
        success = 0,
        /// @brief The overlapped operation was aborted due to the closure of the socket
        operation_aborted = 995,
        /// @brief The application has initiated an overlapped operation that cannot be completed immediately
        io_pending = 997,
        /// @brief A blocking call was canceled
        interrupted = 10004,
        /// @brief Access denied
        access_denied = 10013,
        /// @brief Invalid pointer address
        fault = 10014,
        /// @brief Invalid argument
        invalid_argument = 10022,
        /// @brief Too many sockets opened
        too_many_open_sockets = 10024,
        /// @brief An operation on a nonblocking socket cannot be completed immediately
        would_block = 10035,
        /// @brief A blocking operation is in progress
        in_progress = 10036,
        /// @brief The nonblocking socket has an operation in progress
        already_in_progress = 10037,
        /// @brief Operation attempted on a non-socket object
        not_socket = 10038,
        /// @brief Required destination missing
        destination_address_required = 10039,
        /// @brief Datagram message is too long
        message_size = 10040,
        /// @brief The protocol type is incorrect
        protocol_type = 10041,
        /// @brief An unknown, invalid, or unsupported option or level was used
        protocol_option = 10042,
        /// @brief The protocol is not implemented or has not been configured
        protocol_not_supported = 10043,
        /// @brief  The support for the specified socket type does not exist in this address family
        socket_not_supported = 10044,
        /// @brief The address family is not supported by the protocol family
        operation_not_supported = 10045,
        /// @brief The protocol family is not implemented or has not been configured
        protocol_family_not_supported = 10046,
        /// @brief The address family specified is not supported. This error is returned if the IPv6 address family was specified and the IPv6 stack is not installed on the local machine. This error is returned if the IPv4 address family was specified and the IPv4 stack is not installed on the local machine.
        address_family_not_supported = 10047,
        /// @brief Only one use of an address is normally permitted
        address_already_in_use = 10048,
        /// @brief The selected IP address is not valid in this context
        address_not_available = 10049,
        /// @brief The network is not available
        network_down = 10050,
        /// @brief No route to the remote host exists
        network_unreachable = 10051,
        /// @brief The application tried to set "keep alive" on a connection that timed out
        network_reset = 10052,
        /// @brief Connection aborted
        connection_aborted = 10053,
        /// @brief Connection reset by the remote peer
        connection_reset = 10054,
        /// @brief No free buffer space available
        no_buffer_space_available = 10055,
        /// @brief Already connected
        is_connected = 10056,
        /// @brief The socket is not connected
        not_connected = 10057,
        /// @brief A request to send or receive data was disallowed because the socket is closed
        shutdown = 10058,
        /// @brief The connection attempt timed out, or the connected host has failed to respond
        timed_out = 10060,
        /// @brief The remote host is actively refusing a connection
        connection_refused = 10061,
        /// @brief The operation failed because the remote host is down
        host_down = 10064,
        /// @brief There is no network route to the specified host
        host_unreachable = 10065,
        /// @brief Too many processes are using the underlying socket provider
        process_limit = 10067,
        /// @brief The network subsystem is unavailable
        system_not_ready = 10091,
        /// @brief The version of the underlying socket provider is out of range
        version_not_supported = 10092,
        /// @brief The underlying socket provider has not been initialized
        not_initialized = 10093,
        /// @brief A graceful shutdown is in progress
        disconnecting = 10101,
        /// @brief The specified class was not found
        type_not_found = 10109,
        /// @brief No such host is known. The name is not an official host name or alias.
        host_not_found = 11001,
        /// @brief The name of the host could not be resolved. Try again later.
        try_again = 11002,
        /// @brief The error is unrecoverable or the requested database cannot be located.
        no_recovery = 11003,
        /// @brief The requested name or IP address was not found on the name server.
        no_data = 11004,
      };
    }
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::net::sockets::socket_error> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::net::sockets::socket_error> {{xtd::net::sockets::socket_error::sock_error, "sock_error"}, {xtd::net::sockets::socket_error::success, "success"}, {xtd::net::sockets::socket_error::operation_aborted, "operation_aborted"}, {xtd::net::sockets::socket_error::io_pending, "io_pending"}, {xtd::net::sockets::socket_error::interrupted, "interrupted"}, {xtd::net::sockets::socket_error::access_denied, "access_denied"}, {xtd::net::sockets::socket_error::fault, "fault"}, {xtd::net::sockets::socket_error::invalid_argument, "invalid_argument"}, {xtd::net::sockets::socket_error::too_many_open_sockets, "too_many_open_sockets"}, {xtd::net::sockets::socket_error::would_block, "would_block"}, {xtd::net::sockets::socket_error::in_progress, "in_progress"}, {xtd::net::sockets::socket_error::already_in_progress, "already_in_progress"}, {xtd::net::sockets::socket_error::not_socket, "not_socket"}, {xtd::net::sockets::socket_error::destination_address_required, "destination_address_required"}, {xtd::net::sockets::socket_error::message_size, "message_size"}, {xtd::net::sockets::socket_error::protocol_type, "protocol_type"}, {xtd::net::sockets::socket_error::protocol_option, "protocol_option"}, {xtd::net::sockets::socket_error::protocol_not_supported, "protocol_not_supported"}, {xtd::net::sockets::socket_error::socket_not_supported, "socket_not_supported"}, {xtd::net::sockets::socket_error::operation_not_supported, "operation_not_supported"}, {xtd::net::sockets::socket_error::protocol_family_not_supported, "protocol_family_not_supported"}, {xtd::net::sockets::socket_error::address_family_not_supported, "address_family_not_supported"}, {xtd::net::sockets::socket_error::address_already_in_use, "address_already_in_use"}, {xtd::net::sockets::socket_error::address_not_available, "address_not_available"}, {xtd::net::sockets::socket_error::network_down, "network_down"}, {xtd::net::sockets::socket_error::network_unreachable, "network_unreachable"}, {xtd::net::sockets::socket_error::network_reset, "network_reset"}, {xtd::net::sockets::socket_error::connection_aborted, "connection_aborted"}, {xtd::net::sockets::socket_error::connection_reset, "connection_reset"}, {xtd::net::sockets::socket_error::no_buffer_space_available, "no_buffer_space_available"}, {xtd::net::sockets::socket_error::is_connected, "is_connected"}, {xtd::net::sockets::socket_error::not_connected, "not_connected"}, {xtd::net::sockets::socket_error::shutdown, "shutdown"}, {xtd::net::sockets::socket_error::timed_out, "timed_out"}, {xtd::net::sockets::socket_error::connection_refused, "connection_refused"}, {xtd::net::sockets::socket_error::host_down, "host_down"}, {xtd::net::sockets::socket_error::host_unreachable, "host_unreachable"}, {xtd::net::sockets::socket_error::process_limit, "process_limit"}, {xtd::net::sockets::socket_error::system_not_ready, "system_not_ready"}, {xtd::net::sockets::socket_error::version_not_supported, "version_not_supported"}, {xtd::net::sockets::socket_error::not_initialized, "not_initialized"}, {xtd::net::sockets::socket_error::disconnecting, "disconnecting"}, {xtd::net::sockets::socket_error::type_not_found, "type_not_found"}, {xtd::net::sockets::socket_error::host_not_found, "host_not_found"}, {xtd::net::sockets::socket_error::try_again, "try_again"}, {xtd::net::sockets::socket_error::no_recovery, "no_recovery"}, {xtd::net::sockets::socket_error::no_data, "no_data"}};}
};
/// @endcond
