/// @file
/// @brief Contains xtd::net::sockets::socket_async_event_args class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <any>
#include <memory>
#include <vector>
#include "../../delegate.h"
#include "../../event.h"
#include "../../event_args.h"
#include "ip_packet_information.h"
#include "socket.h"
#include "socket_flags.h"
#include "socket_async_operation.h"
#include "send_packets_element.h"
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
      class socket_async_event_args : public xtd::event_args {
      public:
        /// @brief Creates an empty xtd::net::sockets::socket_async_event_args instance.
        /// @remarks After calling this constructor all properties will have their default values:
        /// * Object references will be null.
        /// * Properties that return an integer will return zero.
        /// * The xtd::net::sockets::socket_async_event_args::last_operation property will be equal to xtd::net::sockets::async_operation::none.
        /// * The xtd::net::sockets::socket_async_event_args::send_packets_flags property will be equal to xtd::net::sockets::transmit_file_options::use_default_worker_thread, which specifies no flags will be used.
        /// * The xtd::net::sockets::socket_async_event_args::socket_flags property will be equal to xtd::net::sockets::async_operation::none.
        /// @remarks The caller must set the appropriate properties prior to passing the object to the appropriate asynchronous socket (xxx_async) method.
        socket_async_event_args() = default;
        /// @brief Initializes the SocketAsyncEventArgs.
        /// @param suppress_executioon_context_flow Whether to disable the capturing and flow of execution context. Execution context flow should only be disabled if it's handled by higher layers.
        socket_async_event_args(bool suppress_execution_context_flow);

        /// @brief Gets the socket to use or the socket created for accepting a connection with an asynchronous socket method.
        /// @return The xtd::net::sockets::socket to use or the socket created for accepting a connection with an asynchronous socket method.
        /// @remarks This property can be used to provide an already created Socket that will be used for an asynchronous socket accept operation. Upon completion of the accept operation, it is the socket representing the accepted connection. If not supplied (set to empty) before calling the xtd::net::sockets::socket::acceptA_async method, a new socket will be created automatically and be accessible in the completion callback with this property.
        xtd::net::sockets::socket accept_socket() const noexcept;
        /// @brief Sets the socket to use or the socket created for accepting a connection with an asynchronous socket method.
        /// @param value The xtd::net::sockets::socket to use or the socket created for accepting a connection with an asynchronous socket method.
        /// @return This current instance.
        /// @remarks This property can be used to provide an already created Socket that will be used for an asynchronous socket accept operation. Upon completion of the accept operation, it is the socket representing the accepted connection. If not supplied (set to empty) before calling the xtd::net::sockets::socket::acceptA_async method, a new socket will be created automatically and be accessible in the completion callback with this property.
        socket_async_event_args& accept_socket(const xtd::net::sockets::socket& value) noexcept;

        /// @brief Gets the data buffer to use with an asynchronous socket method.
        /// @return A Byte array that represents the data buffer to use with an asynchronous socket method.
        /// @remarks This property gets the data buffer currently associated with the xtd::net::sockets::socket_async_event_args instance. To set the buffer, the xtd::net::sockets::socket_async_event_args::set_buffer method must be used.
        /// @remarks This property is used with the xtd::net::sockets::socket::accept_async, xtd::net::sockets::socket::connect_async, xtd::net::sockets::socket::receive_async, xtd::net::sockets::socket::receive_from_async, xtd::net::sockets::socket::receive_message_from_async, xtd::net::sockets::socket::send_async, and xtd::net::sockets::socket::send_to_async methods.
        const std::vector<byte_t>& buffer() const noexcept;
        /// @brief Gets the data buffer to use with an asynchronous socket method.
        /// @return A Byte array that represents the data buffer to use with an asynchronous socket method.
        /// @remarks This property gets the data buffer currently associated with the xtd::net::sockets::socket_async_event_args instance. To set the buffer, the xtd::net::sockets::socket_async_event_args::set_buffer method must be used.
        /// @remarks This property is used with the xtd::net::sockets::socket::accept_async, xtd::net::sockets::socket::connect_async, xtd::net::sockets::socket::receive_async, xtd::net::sockets::socket::receive_from_async, xtd::net::sockets::socket::receive_message_from_async, xtd::net::sockets::socket::send_async, and xtd::net::sockets::socket::send_to_async methods.
        std::vector<byte_t>& buffer() noexcept;
        
        /// @brief Sets the region of memory to use as a buffer with an asynchronous socket method.
        /// @param memory_buffer The region of memory to use as a buffer with an asynchronous socket method.
        void set_buffer(const std::vector<byte_t>& memory_buffer);
        
        /// @brief Sets the data buffer to use with an asynchronous socket method.
        /// @param offset The offset, in bytes, in the data buffer where the operation starts.
        /// @param count The maximum amount of data, in bytes, to send or receive in the buffer.
        /// @exception xtd::argument_out_of_range_exception An argument was out of range. This exception occurs if the offset parameter is greater than the length of the array in the xtd::net::sockets::socket_async_event_args::buffer property. This exception also occurs if the count parameter is greater than the length of the array in the xtd::net::sockets::socket_async_event_args::buffer property minus the offset parameter.
        /// @remarks The offset and count parameters can't be negative numbers. The combination of the offset and count parameters must be in bounds of the buffer array in the xtd::net::sockets::socket_async_event_args::buffer property.
        /// @remarks This method sets the xtd::net::sockets::socket_async_event_args::count property to the count parameter and the xtd::net::sockets::socket_async_event_args::offset property to the offset parameter. If the xtd::net::sockets::socket_async_event_args::buffer property is emptty, this method ignores the offset and count parameters and sets the xtd::net::sockets::socket_async_event_args::offset and xtd::net::sockets::socket_async_event_args::count properties to 0.
        /// @remarks This method does not change the xtd::net::sockets::socket_async_event_args::buffer property.
        void set_buffer(size_t offset, size_t count);
        /// @brief Sets the data buffer to use with an asynchronous socket method.
        /// @param buffer The data buffer to use with an asynchronous socket method.
        /// @param offset The offset, in bytes, in the data buffer where the operation starts.
        /// @param count The maximum amount of data, in bytes, to send or receive in the buffer.
        /// @exception xtd::argument_out_of_range_exception An argument was out of range. This exception occurs if the offset parameter is greater than the length of the array in the xtd::net::sockets::socket_async_event_args::buffer property. This exception also occurs if the count parameter is greater than the length of the array in the xtd::net::sockets::socket_async_event_args::buffer property minus the offset parameter.
        /// @remarks The offset and count parameters can't be negative numbers. The combination of the offset and count parameters must be in bounds of the data array in the buffer parameter.
        /// @remarks This method sets the xtd::net::sockets::socket_async_event_args::buffer property to the buffer parameter, the xtd::net::sockets::socket_async_event_args::count property to the count parameter, and the xtd::net::sockets::socket_async_event_args::offset property to the offset parameter.
        void set_buffer(const std::vector<byte_t>& buffer, size_t count, size_t offset);

        /// @brief The event used to complete an asynchronous operation.
        /// @remarks The xtd::net::sockets::socket_async_event_args::completed event provides a way for client applications to complete an asynchronous socket operation. An event handler should be attached to the event within a xtd::net::sockets::socket_async_event_args instance when an asynchronous socket operation is initiated, otherwise the application will not be able to determine when the operation completes.
        /// @remarks The completion callback delegates referenced by the xtd::net::sockets::socket_async_event_args::completed event contains program logic to finish processing the asynchronous socket operation for the client.
        /// @remarks When the event is signaled, the application uses the xtd::net::sockets::socket_async_event_args object parameter to obtain the status of the completed asynchronous socket operation.
        xtd::event<socket_async_event_args, xtd::delegate<void(const socket_async_event_args&)>> completed;
        
      protected:
        /// @brief Represents a method that is called when an asynchronous operation completes.
        /// @param e The event that is signaled.
        /// @remarks This method is not callable by user code. This method gets called by the internals of the xtd::net::sockets::socket_async_event_args object when the current operation is complete. This method is used with all asynchronous socket (xxx_async) methods.
        /// @remarks An application that creates a class inheriting from xtd::net::sockets::socket_async_event_args can override this method to hook into this completion notification and clean up any resources that it allocated for the operation. The default implementation just raises the xtd::net::sockets::socket_async_event_args::completed event.
        /// @remarks This method is used to hook up an event handler to be used as the completion callback for a subsequent asynchronous socket operation. The caller must implement at least one callback delegate inherited from this method prior to starting an asynchronous socket operation using one of the asynchronous (xxx_async) methods on the xtd::net::sockets::socket class.
        /// @remarks The caller's xtd::net::sockets::socket_async_event_args::on_completed method provides a way for client applications to complete an asynchronous socket operation. A callback delegate must be implemented when an asynchronous socket operation is initiated. The completion callback delegate(s) inherited from the xtd::net::sockets::socket_async_event_args::on_completed method must contain program logic to finish processing the asynchronous socket operation for the client.
        /// @remarks When an asynchronous operation is signaled, the application uses the xtd::net::sockets::socket_async_event_args object parameter to obtain status of the completed asynchronous socket operation.
        virtual void on_complet(const socket_async_event_args& e);
        
      private:
        friend socket;
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
        xtd::net::sockets::ip_packet_information receive_message_from_packet_info_;
        std::unique_ptr<xtd::net::end_point> remote_end_point_;
        std::vector<xtd::net::sockets::send_packets_element> send_packets_elements_;
        xtd::net::sockets::transmit_file_options send_packets_flags_ = xtd::net::sockets::transmit_file_options::use_default_worker_thread;
        size_t send_packets_send_size_ = 0;
        xtd::net::sockets::socket_error socket_error_ = xtd::net::sockets::socket_error::success;
        xtd::net::sockets::socket_flags socket_flags_ = xtd::net::sockets::socket_flags::none;
        std::any user_token_;
      };
    }
  }
}
