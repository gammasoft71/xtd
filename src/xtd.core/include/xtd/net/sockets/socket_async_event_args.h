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
      /// @brief Represents an asynchronous socket operation.
      /// @remarks The xtd::net::sockets::socket_async_event_args class is part of a set of enhancements to the xtd::net::sockets::socket class that provide an alternative asynchronous pattern that can be used by specialized high-performance socket applications. This class was specifically designed for network server applications that require high performance. An application can use the enhanced asynchronous pattern exclusively or only in targeted hot areas (for example, when receiving large amounts of data).
      /// @remarks The main feature of these enhancements is the avoidance of the repeated allocation and synchronization of objects during high-volume asynchronous socket I/O. The Begin/End design pattern currently implemented by the xtd::net::sockets::socket class requires a xtd::iasync_result object be allocated for each asynchronous socket operation.
      /// @remarks In the new xtd::net::sockets::socket class enhancements, asynchronous socket operations are described by reusable xtd::net::sockets::socket_async_event_args objects allocated and maintained by the application. High-performance socket applications know best the amount of overlapped socket operations that must be sustained. The application can create as many of the xtd::net::sockets::socket_async_event_args objects that it needs. For example, if a server application needs to have 15 socket accept operations outstanding at all times to support incoming client connection rates, it can allocate 15 reusable xtd::net::sockets::socket_async_event_args objects for that purpose.
      /// @remarks The pattern for performing an asynchronous socket operation with this class consists of the following steps:
      /// 1. Allocate a new xtd::net::sockets::socket_async_event_args context object, or get a free one from an application pool.
      /// 2. Set properties on the context object to the operation about to be performed (the completion callback method, the data buffer, the offset into the buffer, and the maximum amount of data to transfer, for example).
      /// 3. Call the appropriate socket method (xxx_async) to initiate the asynchronous operation.
      /// 4. If the asynchronous socket method (xxx_async) returns true, in the callback, query the context properties for completion status.
      /// 5. If the asynchronous socket method (xxx_async) returns false, the operation completed synchronously. The context properties may be queried for the operation result.
      /// 6. Reuse the context for another operation, put it back in the pool, or discard it.
      /// @remarks The lifetime of the new asynchronous socket operation context object is determined by references by the application code and asynchronous I/O references. It is not necessary for the application to retain a reference to an asynchronous socket operation context object after it is submitted as a parameter to one of the asynchronous socket operation methods. It will remain referenced until the completion callback returns. However it is advantageous for the application to retain the reference to the context so that it can be reused for a future asynchronous socket operation.
      class socket_aync_event_args {
      public:
        /// @brief Creates an empty xtd::net::sockets::socket_async_event_args instance.
        /// @remarks After calling this constructor all properties will have their default values:
        /// * Object references will be null.
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
