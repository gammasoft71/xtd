/// @file
/// @brief Contains xtd::net::sockets::socket_aync_event_args class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include "../../event_args.h"
#include "ip_packet_information.h"
#include "socket.h"
#include "socket_async_operation.h"
#include "transmit_file_options.h"

/// @cond
#undef unix
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief The xtd::net::sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
    namespace sockets {
      class socket_aync_event_args {
      public:
        /// @brief Creates an empty xtd::net::sockets::socket_async_event_args instance.
        /// @remarks After calling this constructor all properties will have their default values:
        /// * Object references will be null
        /// * Properties that return an integer will return zero.
        /// * The xtd::net::sockets::socket_async_event_args::last_operation property will be equal to xtd::net::sockets::async_operation::none.
        /// * The xtd::net::sockets::socket_async_event_args::send_packets_flags property will be equal to xtd::net::sockets::transmit_file_options::use_default_worker_thread, which specifies no flags will be used.
        /// * The xtd::net::sockets::socket_async_event_args::socket_flags property will be equal to xtd::net::sockets::async_operation::none.
        /// @remarks The caller must set the appropriate properties prior to passing the object to the appropriate asynchronous socket (xxx_async) method.
        socket_aync_event_args() = default;
        /// @brief Initializes the SocketAsyncEventArgs.
        /// @param suppress_executioon_context_flow Whether to disable the capturing and flow of execution context. Execution context flow should only be disabled if it's handled by higher layers.
        socket_aync_event_args(bool suppress_execution_context_flow);

      private:
        xtd::net::sockets::socket accept_socket_;
        std::vector<byte_t> buffer_;
        std::vector<std::vector<byte_t>> buffer_list_;
        size_t bytes_transfered_ = 0;
        std::unique_ptr<xtd::system_exception> connect_by_name_error_;
        xtd::net::sockets::socket connect_socket_;
        size_t count_ = 0;
        bool disconnect_reuse_socket_ = false;
        xtd::net::sockets::socket_async_operation last_operation = xtd::net::sockets::socket_async_operation::none;
        std::vector<byte_t> memory_buffer_;
        size_t offset_ = 0;
        ip_packet_information receive_message_from_packet_info_;
        std::unique_ptr<xtd::net::end_point> remote_end_point_;
      };
    }
  }
}
