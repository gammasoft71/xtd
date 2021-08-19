/// @file
/// @brief Contains xtd::net::sockets::transmit_file_options enum.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include "../../ustring.h"

/// @cond
#undef disconnect
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief The xtd::net::sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
    namespace sockets {
      /// @brief The TransmitFileOptions enumeration defines values used in file transfer requests.
      /// @remarks This enumeration has a flags attribute that allows a bitwise combination of its member values.
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core
      /// @note The flags xtd::net::sockets::transmit_file_options::disconnect and xtd::net::sockets::transmit_file_options::reuse_socket return the socket to a disconnected, reusable state after the file has been transmitted. These flags should not be used on a socket where quality of service (QOS) has been requested, because the service provider might immediately delete any quality of service associated with the socket before the file transfer has completed. The best approach for a QOS-enabled socket is to call xtd::net::sockets::socket::close when the file transfer has completed, rather than relying on these flags.
      enum class transmit_file_options {
        /// @brief Use the default thread to process long file transfer requests.
        use_default_worker_thread = 0,
        /// @brief Start a transport-level disconnect after all the file data has been queued for transmission. When used with xtd::net::sockets::transmit_file_options::reuse_socket, these flags return the socket to a disconnected, reusable state after the file has been transmitted.
        disconnect = 0b1,
        /// @brief The socket handle may be reused when the request completes. This flag is valid only if xtd::net::sockets::transmit_file_options::disconnect is also specified. When used with xtd::net::sockets::transmit_file_options::disconnect, these flags return the socket to a disconnected, reusable state after the file has been transmitted.
        reuse_socket = 0b10,
        /// @brief Complete the file transfer request immediately, without pending. If this flag is specified and the file transfer succeeds, the data has been accepted by the system but not necessarily acknowledged by the remote end. Do not use this flag with the xtd::net::sockets::transmit_file_options::disconnect and xtd::net::sockets::transmit_file_options::reuse_socket flags.
        write_behind = 0b100,
        /// @brief Use system threads to process long file transfer requests.
        use_system_thread = 0b1000,
        /// @brief Use kernel asynchronous procedure calls (APCs) instead of worker threads to process long file transfer requests. Long requests are defined as requests that require more than a single read from the file or a cache; the request therefore depends on the size of the file and the specified length of the send packet.
        use_kernel_apc = 0b100000,
      };

      /// @cond
      inline transmit_file_options& operator^=(transmit_file_options& lhs, transmit_file_options rhs) {lhs = static_cast<transmit_file_options>(static_cast<int>(lhs) ^ static_cast<int>(rhs)); return lhs;}
      inline transmit_file_options& operator&=(transmit_file_options& lhs, transmit_file_options rhs) {lhs = static_cast<transmit_file_options>(static_cast<int>(lhs) & static_cast<int>(rhs)); return lhs;}
      inline transmit_file_options& operator|=(transmit_file_options& lhs, transmit_file_options rhs) {lhs = static_cast<transmit_file_options>(static_cast<int>(lhs) | static_cast<int>(rhs)); return lhs;}
      inline transmit_file_options& operator+=(transmit_file_options& lhs, transmit_file_options rhs) {lhs = static_cast<transmit_file_options>(static_cast<int>(lhs) + static_cast<int>(rhs)); return lhs;}
      inline transmit_file_options& operator-=(transmit_file_options& lhs, transmit_file_options rhs) {lhs = static_cast<transmit_file_options>(static_cast<int>(lhs) - static_cast<int>(rhs)); return lhs;}
      inline transmit_file_options operator^(transmit_file_options lhs, transmit_file_options rhs) {return static_cast<transmit_file_options>(static_cast<int>(lhs) ^ static_cast<int>(rhs));}
      inline transmit_file_options operator&(transmit_file_options lhs, transmit_file_options rhs) {return static_cast<transmit_file_options>(static_cast<int>(lhs) & static_cast<int>(rhs));}
      inline transmit_file_options operator|(transmit_file_options lhs, transmit_file_options rhs) {return static_cast<transmit_file_options>(static_cast<int>(lhs) | static_cast<int>(rhs));}
      inline transmit_file_options operator+(transmit_file_options lhs, transmit_file_options rhs) {return static_cast<transmit_file_options>(static_cast<int>(lhs) + static_cast<int>(rhs));}
      inline transmit_file_options operator-(transmit_file_options lhs, transmit_file_options rhs) {return static_cast<transmit_file_options>(static_cast<int>(lhs) - static_cast<int>(rhs));}
      inline transmit_file_options operator~(transmit_file_options lhs) {return static_cast<transmit_file_options>(~static_cast<int>(lhs));}
      inline std::ostream& operator<<(std::ostream& os, transmit_file_options value) {return os << to_string(value, {{transmit_file_options::use_default_worker_thread, "use_default_worker_thread"}, {transmit_file_options::disconnect, "disconnect"}, {transmit_file_options::reuse_socket, "reuse_socket"}, {transmit_file_options::write_behind, "write_behind"}, {transmit_file_options::use_system_thread, "use_system_thread"}, {transmit_file_options::use_kernel_apc, "use_kernel_apc"}});}
      inline std::wostream& operator<<(std::wostream& os, transmit_file_options value) {return os << to_string(value, {{transmit_file_options::use_default_worker_thread, L"use_default_worker_thread"}, {transmit_file_options::disconnect, L"disconnect"}, {transmit_file_options::reuse_socket, L"reuse_socket"}, {transmit_file_options::write_behind, L"write_behind"}, {transmit_file_options::use_system_thread, L"use_system_thread"}, {transmit_file_options::use_kernel_apc, L"use_kernel_apc"}});}
      /// @endcond
    }
  }
}
