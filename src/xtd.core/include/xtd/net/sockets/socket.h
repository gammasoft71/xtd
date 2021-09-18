/// @file
/// @brief Contains xtd::net::sockets::socket class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <memory>
#include "../../core_export.h"
#include "../../argument_exception.h"
#include "../../async_callback.h"
#include "../../iasync_result.h"
#include "../../not_implemented_exception.h"
#include "../../not_supported_exception.h"
#include "../../object.h"
#include "../../types.h"
#include "../../ustring.h"
#include "../end_point.h"
#include "../ip_address.h"
#include "address_family.h"
#include "io_control_code.h"
#include "ip_packet_information.h"
#include "ip_protection_level.h"
#include "linger_option.h"
#include "multicast_option.h"
#include "ip_v6_multicast_option.h"
#include "protocol_type.h"
#include "select_mode.h"
#include "socket_error.h"
#include "socket_flags.h"
#include "socket_information.h"
#include "socket_option_level.h"
#include "socket_option_name.h"
#include "socket_shutdown.h"
#include "socket_type.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief The xtd::net::sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
    namespace sockets {
      /// @cond
      class socket_async_event_args;
      /// @endcond
      
      /// @brief Implements the Berkeley sockets interface.
      /// @par Namespace
      /// xtd::net::sockets
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core net
      /// @remarks The xtd::net::sockets::socket class provides a rich set of methods and properties for network communications. The xtd::net::sockets::socket class allows you to perform both synchronous and asynchronous data transfer using any of the communication protocols listed in the xtd::net::sockets::protocol_type enumeration.
      /// @remarks The xtd::net::sockets::socket class follows the xtd naming pattern for asynchronous methods. For example, the synchronous xtd::net::sockets::receive method corresponds to the asynchronous xtd::net::sockets::begin_receive and xtd::net::sockets::end_receive methods.
      /// @remarks If your application only requires one thread during execution, use the following methods, which are designed for synchronous operation mode.
      /// * If you are using a connection-oriented protocol such as TCP, your server can listen for connections using the xtd::net::sockets::socket::listen method. The xtd::net::sockets::socket::xtd::net::sockets::socket::accept method processes any incoming connection requests and returns a xtd::net::sockets::socket that you can use to communicate data with the remote host. Use this returned xtd::net::sockets::socket to call the xtd::net::sockets::socket::send or xtd::net::sockets::socket::receive method. Call the xtd::net::sockets::socket::bind method prior to calling the xtd::net::sockets::socket::listen method if you want to specify the local IP address and port number. Use a port number of zero if you want the underlying service provider to assign a free port for you. If you want to connect to a listening host, call the xtd::net::sockets::socket::connect method. To communicate data, call the xtd::net::sockets::socket::send or xtd::net::sockets::socket::receive method.
      /// * If you are using a connectionless protocol such as UDP, you do not need to listen for connections at all. Call the xtd::net::sockets::socket::receive_from method to accept any incoming datagrams. Use the xtd::net::sockets::socket::send_to method to send datagrams to a remote host.
      /// @remarks To process communications using separate threads during execution, use the following methods, which are designed for asynchronous operation mode.
      /// * If you are using a connection-oriented protocol such as TCP, use the xtd::net::sockets::socket, xtd::net::sockets::socket::begin_connect, and xtd::net::sockets::socket::end_connect methods to connect with a listening host. Use the xtd::net::sockets::socket::begin_send and xtd::net::sockets::socket::end_send or xtd::net::sockets::socket::begin_receive and xtd::net::sockets::socket::end_receive methods to communicate data asynchronously. Incoming connection requests can be processed using xtd::net::sockets::socket::begin_accept and xtd::net::sockets::socket::end_accept.
      /// * If you are using a connectionless protocol such as UDP, you can use xtd::net::sockets::socket::begin_send_to and xtd::net::sockets::socket::end_send_tto to send datagrams, and xtd::net::sockets::socket::begin_receive_from and xtd::net::sockets::socket::end_receive_from to receive datagrams.
      /// @remarks If you perform multiple asynchronous operations on a socket, they do not necessarily complete in the order in which they are started.
      /// @remarks When you are finished sending and receiving data, use the xtd::net::sockets::socket::shutdown method to disable the xtd::net::sockets::socket. After calling xtd::net::sockets::socket::shutdown, call the xtd::net::sockets::socket::close method to release all resources associated with the xtd::net::sockets::socket.
      /// @remarks The xtd::net::sockets::socket class allows you to configure your xtd::net::sockets::socket using the xtd::net::sockets::socket::set_socket_option method. Retrieve these settings using the xtd::net::sockets::socket::get_socket_option method.
      /// @note If you are writing a relatively simple application and do not require maximum performance, consider using xtd::net::sockets::tcp_client, xtd::net::sockets::tcp_listener, and xtd::net::sockets::udp_client. These classes provide a simpler and more user-friendly interface to xtd::net::sockets::socket communications.
      class core_export_ socket : public xtd::object {
        class async_result_socket : public xtd::object, public xtd::iasync_result {
        public:
          async_result_socket(std::any async_state) : async_state_(async_state) {}
          std::any async_state() const noexcept override {return async_state_;}
          std::shared_mutex& async_mutex() override {return async_mutex_;}
          bool completed_synchronously() const noexcept override {return false;}
          bool is_completed() const noexcept override {return is_completed_;};
          
          std::any async_state_;
          bool is_completed_ = false;
          std::shared_mutex async_mutex_;
          xtd::net::sockets::socket_error error_code_ = xtd::net::sockets::socket_error::success;
          std::exception_ptr exception_;
        };
        
        class async_result_accept : public async_result_socket {
        public:
          async_result_accept(std::any async_state) : async_result_socket(async_state) {}
          std::any socket_;
        };
        
        class async_result_connect : public async_result_socket {
        public:
          async_result_connect(std::any async_state) : async_result_socket(async_state) {}
        };
        
        class async_result_disconnect : public async_result_socket {
        public:
          async_result_disconnect(std::any async_state) : async_result_socket(async_state) {}
        };
        
        class async_result_receive : public async_result_socket {
        public:
          async_result_receive(std::any async_state) : async_result_socket(async_state) {}
          size_t number_of_bytes_received_ = 0;
        };
        
        class async_result_receive_from : public async_result_socket {
        public:
          async_result_receive_from(std::any async_state) : async_result_socket(async_state) {}
          std::shared_ptr<xtd::net::end_point> end_point_;
          size_t number_of_bytes_received_ = 0;
        };
        
        class async_result_receive_message_from : public async_result_socket {
        public:
          async_result_receive_message_from(std::any async_state) : async_result_socket(async_state) {}
          std::shared_ptr<xtd::net::end_point> end_point_;
          xtd::net::sockets::socket_flags socket_flags_;
          size_t number_of_bytes_received_ = 0;
          xtd::net::sockets::ip_packet_information ip_packet_information_;
        };
        
        class async_result_send : public async_result_socket {
        public:
          async_result_send(std::any async_state) : async_result_socket(async_state) {}
          size_t number_of_bytes_sent_ = 0;
        };
        
        class async_result_send_to : public async_result_socket {
        public:
          async_result_send_to(std::any async_state) : async_result_socket(async_state) {}
          size_t number_of_bytes_sent_ = 0;
        };

      public:
        /// @brief Initializes a new instance of the xtd::net::sockets::socket class.
        socket();
        
        /// @brief Initializes a new instance of the xtd::net::sockets::socket class for the specified socket handle.
        /// @param handle The socket handle for the socket that the xtd::net::sockets::socket object will encapsulate.
        /// @exception xtd::argument_exception The handle is invalid.
        /// @remarks This method populates the xtd::net::sockets::socket instance with data gathered from the supplied intptr_t. Different operating systems provide varying levels of support for querying a socket handle or file descriptor for its properties and configuration. Some of the public APIs on the resulting xtd::net::sockets::socket instance may differ based on operating system, such as xtd::net::sockets::socket::protocol_type and xtd::net::sockets::socket::blocking.
        socket(intptr_t handle);
        /// @brief Initializes a new instance of the xtd::net::sockets::socket class using the specified value returned from xtd::net::sockets::socket::duplicate_and_close.
        /// @param socket_information The socket information returned by xtd::net::sockets::socket::duplicate_and_close.
        /// @remarks If you call the xtd::net::sockets::socket constructor multiple times with the same byte array as the argument for each call, you will create multiple xtd::net::sockets::socket with the same underlying socket. This practice is strongly discouraged.
        socket(const xtd::net::sockets::socket_information& socket_information);
        /// @brief Initializes a new instance of the xtd::net::sockets::socket class using the specified socket type and protocol. If the operating system supports IPv6, this constructor creates a dual-mode socket; otherwise, it creates an IPv4 socket.
        /// @param socket_type One of the xtd::net::sockets::socket_type values.
        /// @param protocol_type One of the xtd::net::sockets::protocol_type values.
        /// @exception xtd::net:sockets::socket_exception The combination of socket_type and protocol_type results in an invalid socket.
        /// @remarks The socket_type parameter specifies the type of the xtd::net::sockets::socket class and the protocol_type parameter specifies the protocol used by xtd::net::sockets::socket. The two parameters are not independent. Often the xtd::net::sockets::socket type is implicit in the protocol. If the combination of xtd::net::sockets::socket type and protocol type results in an invalid xtd::net::sockets::socket, this constructor throws a xtd::net::sockets::socket_exception.
        /// @note If this constructor throws a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        socket(xtd::net::sockets::socket_type socket_type, xtd::net::sockets::protocol_type protocol_type);
        /// @brief Initializes a new instance of the xtd::net::sockets::socket class using the specified address family, socket type and protocol.
        /// @param address_family One of the xtd::net::sockets::address_family values.
        /// @param socket_type One of the xtd::net::sockets::socket_type values.
        /// @param protocol_type One of the xtd::net::sockets::protocol_type values.
        /// @exception xtd::net:sockets::socket_exception The combination of address_family, socket_type and protocol_type results in an invalid socket.
        /// @remarks The address_family parameter specifies the addressing scheme that the xtd::net::sockets::socket class uses, the socket_type parameter specifies the type of the xtd::net::sockets::socket class, and the protocol_type parameter specifies the protocol used by xtd::net::sockets::socket. The three parameters are not independent. Some address families restrict which protocols can be used with them, and often the xtd::net::sockets::socket type is implicit in the protocol. If the combination of address family, xtd::net::sockets::socket type, and protocol type results in an invalid xtd::net::sockets::socket, this constructor throws a xtd::net::sockets::socket_exception.
        /// @note If this constructor throws a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        socket(xtd::net::sockets::address_family address_family, xtd::net::sockets::socket_type socket_type, xtd::net::sockets::protocol_type protocol_type);
        
        /// @cond
        socket(socket&&) = default;
        socket(const socket&) = default;
        ~socket();
        socket& operator=(const socket&) = default;
        friend std::ostream& operator <<(std::ostream& os, const socket& mo) noexcept {return os << mo.to_string();}
        bool operator==(const socket& s) const {return data_ == s.data_;};
        bool operator!=(const socket& s) const {return !operator==(s);};
        /// @endcond
        
        /// @brief Gets the address family of the xtd::net::sockets::socket.
        /// @return One of the xtd::net::sockets::address_family values.
        /// @remarks The xtd::net::sockets::address_family specifies the addressing scheme that an instance of the xtd::net::sockets::socket class can use. This property is read-only and is set when the xtd::net::sockets::socket is created.
        xtd::net::sockets::address_family address_family() const noexcept;
        
        /// @brief Gets the amount of data that has been received from the network and is available to be read.
        /// @return The number of bytes of data received from the network and available to be read.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        size_t available() const;
        
        /// @brief Gets a value that indicates whether the xtd::net::sockets::socket is in blocking mode.
        /// @return true if the xtd::net::sockets::socket will block; otherwise, false. The default is true.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks The xtd::net::sockets::socket::blocking property indicates whether a xtd::net::sockets::socket is in blocking mode.
        /// @remarks If you are in blocking mode, and you make a method call which does not complete immediately, your application will block execution until the requested operation completes. If you want execution to continue even though the requested operation is not complete, change the xtd::net::sockets::socket::blocking property to false. The xtd::net::sockets::socket::blocking property has no effect on asynchronous methods. If you are sending and receiving data asynchronously and want to block execution, use the xtd::threading::manual_reset_event class.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        bool blocking() const;
        /// @brief Sets a value that indicates whether the xtd::net::sockets::socket is in blocking mode.
        /// @param value true if the xtd::net::sockets::socket will block; otherwise, false. The default is true.
        /// @return This current instance.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks The xtd::net::sockets::socket::blocking property indicates whether a xtd::net::sockets::socket is in blocking mode.
        /// @remarks If you are in blocking mode, and you make a method call which does not complete immediately, your application will block execution until the requested operation completes. If you want execution to continue even though the requested operation is not complete, change the xtd::net::sockets::socket::blocking property to false. The xtd::net::sockets::socket::blocking property has no effect on asynchronous methods. If you are sending and receiving data asynchronously and want to block execution, use the xtd::threading::manual_reset_event class.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        socket& blocking(bool value);

        /// @brief Gets a value that indicates whether a xtd::net::sockets::socket is connected to a remote host as of the last xtd::net::sockets::socket::send or xtd::net::sockets::socket::receive operation.
        /// @return true if the xtd::net::sockets::socket was connected to a remote resource as of the most recent operation; otherwise, false.
        /// @remarks The xtd::net::sockets::socket::connected property gets the connection state of the xtd::net::sockets::socket as of the last I/O operation. When it returns false, the xtd::net::sockets::socket was either never connected, or is no longer connected. xtd::net::sockets::socket::connected is not thread-safe; it may return true after an operation is aborted when the xtd::net::sockets::socket is disconnected from another thread.
        /// @remarks The value of the xtd::net::sockets::socket::connected property reflects the state of the connection as of the most recent operation. If you need to determine the current state of the connection, make a nonblocking, zero-byte xtd::net::sockets::socket::send call. If the call returns successfully or throws a WAEWOULDBLOCK error code (10035), then the socket is still connected; otherwise, the socket is no longer connected.
        /// @remarks If you call xtd::net::sockets::socket::connect on a User Datagram Protocol (UDP) socket, the xtd::net::sockets::socket::connected property always returns true; however, this action does not change the inherent connectionless nature of UDP.
        bool connected() const noexcept;

        /// @brief Gets a value that specifies whether the xtd::net::sockets::socket allows Internet Protocol (IP) datagrams to be fragmented.
        /// @return true if the xtd::net::sockets::socket doesn't allow datagram fragmentation; otherwise, false. The default is true.
        /// @exception xtd::not_supported_exception The socket is not in the xtd::net::sockets::address_family::inter_network family.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        bool dont_fragment() const;
        /// @brief Sets a value that specifies whether the xtd::net::sockets::socket allows Internet Protocol (IP) datagrams to be fragmented.
        /// @param value true if the xtd::net::sockets::socket doesn't allow datagram fragmentation; otherwise, false. The default is true.
        /// @return This current instance.
        /// @exception xtd::not_supported_exception The socket is not in the xtd::net::sockets::address_family::inter_network family.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        socket& dont_fragment(bool value);

        /// @brief Gets a value that specifies whether the xtd::net::sockets::socket is a dual-mode socket used for both IPv4 and IPv6.
        /// @return true if the xtd::net::sockets::socket is a dual-mode socket; otherwise, false. The default is true if the socket was created by calling the xtd::net::sockets::socket(xtd::net::sockets::socket_type, xtd::net::sockets::protocol_type) constructor and the operating system supports IPv6; otherwise, the default is false.
        /// @exception xtd::not_supported_exception The socket is not in the xtd::net::sockets::address_family::inter_network_v6 family.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        bool dual_mode() const;
        /// @brief Sets a value that specifies whether the xtd::net::sockets::socket is a dual-mode socket used for both IPv4 and IPv6.
        /// @param value true if the xtd::net::sockets::socket is a dual-mode socket; otherwise, false. The default is true if the socket was created by calling the xtd::net::sockets::socket(xtd::net::sockets::socket_type, xtd::net::sockets::protocol_type) constructor and the operating system supports IPv6; otherwise, the default is false.
        /// @return This current instance.
        /// @exception xtd::not_supported_exception The socket is not in the xtd::net::sockets::address_family::inter_network_v6 family.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        socket& dual_mode(bool value);
        
        /// @brief Gets a boolean value that specifies whether the xtd::net::sockets::socket can send or receive broadcast packets.
        /// @return true if the xtd::net::sockets::socket allows broadcast packets; otherwise, false. The default is false.
        /// @exception xtd::net::sockets::socket_exception This option is valid for a datagram socket only.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks Broadcasting is limited to a specific subnet, and must use User Datagram Protocol (UDP.) For Internet Protocol version 4, you can broadcast to your local subnet by sending a packet to 255.255.255.255; or you can use the directed broadcast address, which is the network portion of an Internet Protocol (IP) address with all bits set in the host portion. For example, if your IP address is 192.168.1.40 (a Class C address, with a netmask of 255.255.255.0 -- the network portion is the first three octets, and the host portion is the last octet), your directed broadcast address is 192.168.1.255.
        /// @remarks Setting this property on a Transmission Control Protocol (TCP) socket will have no effect.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        bool enable_broadcast() const;
        /// @brief Sets a bool value that specifies whether the xtd::net::sockets::socket can send or receive broadcast packets.
        /// @param value true if the xtd::net::sockets::socket allows broadcast packets; otherwise, false. The default is false.
        /// @return This current instance.
        /// @exception xtd::net::sockets::socket_exception This option is valid for a datagram socket only.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks Broadcasting is limited to a specific subnet, and must use User Datagram Protocol (UDP.) For Internet Protocol version 4, you can broadcast to your local subnet by sending a packet to 255.255.255.255; or you can use the directed broadcast address, which is the network portion of an Internet Protocol (IP) address with all bits set in the host portion. For example, if your IP address is 192.168.1.40 (a Class C address, with a netmask of 255.255.255.0 -- the network portion is the first three octets, and the host portion is the last octet), your directed broadcast address is 192.168.1.255.
        /// @remarks Setting this property on a Transmission Control Protocol (TCP) socket will have no effect.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        socket& enable_broadcast(bool value);

        /// @brief Gets a boolean value that specifies whether the xtd::net::sockets::socket allows only one process to bind to a port.
        /// @return true if the xtd::net::sockets::socket allows only one socket to bind to a specific port; otherwise, false. The default is true for Windows Server 2003 and Windows XP Service Pack 2, and false for all other versions.
        /// @exception xtd::net::sockets::socket_exception This option is valid for a datagram socket only.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks If xtd::net::sockets::socket::exclusive_address_use is false, multiple sockets can use the xtd::net::sockets::socket::bind method to bind to a specific port; however only one of the sockets can perform operations on the network traffic sent to the port. If more than one socket attempts to use the xtd::net::sockets::socket::bind method to bind to a particular port, then the one with the more specific IP address will handle the network traffic sent to that port.
        /// @remarks If xtd::net::sockets::socket::exclusive_address_use is true, the first use of the xtd::net::sockets::socket::bind method to attempt to bind to a particular port, regardless of Internet Protocol (IP) address, will succeed; all subsequent uses of the xtd::net::sockets::socket::bind method to attempt to bind to that port will fail until the original bound socket is destroyed.
        /// @remarks This property must be set before xtd::net::sockets::socket::bind is called; otherwise an xtd::invalid_operation_exception will be thrown.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        bool exclusive_address_use() const;
        /// @brief Gets a boolean value that specifies whether the xtd::net::sockets::socket allows only one process to bind to a port.
        /// @param value true if the xtd::net::sockets::socket allows only one socket to bind to a specific port; otherwise, false. The default is true for Windows Server 2003 and Windows XP Service Pack 2, and false for all other versions.
        /// @return This current instance.
        /// @exception xtd::net::sockets::socket_exception This option is valid for a datagram socket only.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @exception xtd::invalid_operation_exception xtd::net::sockets::socket::bind has been called for this xtd::net::sockets::socket.
        /// @remarks If xtd::net::sockets::socket::exclusive_address_use is false, multiple sockets can use the xtd::net::sockets::socket::bind method to bind to a specific port; however only one of the sockets can perform operations on the network traffic sent to the port. If more than one socket attempts to use the xtd::net::sockets::socket::bind method to bind to a particular port, then the one with the more specific IP address will handle the network traffic sent to that port.
        /// @remarks If xtd::net::sockets::socket::exclusive_address_use is true, the first use of the xtd::net::sockets::socket::bind method to attempt to bind to a particular port, regardless of Internet Protocol (IP) address, will succeed; all subsequent uses of the xtd::net::sockets::socket::bind method to attempt to bind to that port will fail until the original bound socket is destroyed.
        /// @remarks This property must be set before xtd::net::sockets::socket::bind is called; otherwise an xtd::invalid_operation_exception will be thrown.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        socket& exclusive_address_use(bool value);

        /// @brief Gets the operating system handle for the xtd::net::sockets::socket.
        /// @return An intptr_t that represents the operating system handle for the xtd::net::sockets::socket.
        intptr_t handle() const noexcept;

        /// @brief Gets a value that indicates whether the xtd::net::sockets::socket is bound to a specific local port.
        /// @return true if the xtd::net::sockets::socket is bound to a local port; otherwise, false.
        /// @remarks A socket is considered bound to a local port if it is explicitly bound by calling the xtd::net::sockets::socket::bind method, or implicitly bound by calling members like xtd::net::sockets::socket::connect, xtd::net::sockets::socket::send_to, or xtd::net::sockets::socket::receive_from, which use an ephemeral local port (a free port greater than 1024, selected by the operating system.) Servers use the xtd::net::sockets::socket::bind method to bind to a well-known port so that clients may connect to them.
        bool is_bound() const noexcept;
        
        /// @brief Gets a value that specifies whether the xtd::net::sockets::socket will delay closing a socket in an attempt to send all pending data.
        /// @return A xtd::net::sockets::sockets::linger_option that specifies how to linger while closing a socket.
        /// @exception xtd::net::sockets::socket_exception This option is valid for a datagram socket only.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks The xtd::net::sockets::socket::linger_state property changes the way xtd::net::sockets::socket::close method behaves. This property when set modifies the conditions under which the connection can be reset by Winsock. Connection resets can still occur based on the IP protocol behavior.
        /// @remarks This property controls the length of time that a connection-oriented connection will remain open after a call to xtd::net::sockets::socket::close when data remains to be sent.
        /// @remarks When you call methods to send data to a peer, this data is placed in the outgoing network buffer. This property can be used to ensure that this data is sent to the remote host before the xtd::net::sockets::socket::close method drops the connection.
        /// @remarks To enable lingering, create a xtd::net::sockets::linger_option instance containing the desired values, and set the xtd::net::sockets::socket::linger_state property to this instance.
        /// @remarks The following table describes the behavior of the xtd::net::sockets::socket::close method for the possible values of the xtd::net::sockets::inger_option::enabled property and the xtd::net::sockets::linger_option::linger_time property stored in the xtd::net::sockets::socket::linger_state property.
        /// | xtd::net::sockets::linger_state::enabled | xtd::net::sockets::linger_state::linger_time | Behavior                                                                                                                          |
        /// |------------------------------------------|----------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------|
        /// | false (disabled), the default value      | The time-out is not applicable, (default).   | Attempts to send pending data until the default IP protocol time-out expires.                                                     |
        /// | true (enabled)                           | A nonzero time-out.                          | Attempts to send pending data until the specified time-out expires, and if the attempt fails, then Winsock resets the connection. |
        /// | true (enabled)                           | A zero time-out.                             | Discards any pending data. For connection-oriented socket (TCP, for example), Winsock resets the connection.                      |
        /// @remarks The IP stack computes the default IP protocol time-out period to use based on the round trip time of the connection. In most cases, the time-out computed by the stack is more relevant than one defined by an application. This is the default behavior for a socket when the xtd::net::sockets::socket::linger_state property is not set.
        /// @remarks When the xtd::net::sockets::linger_option::linger_time property stored in the xtd::net::sockets::socket::linger_state property is set greater than the default IP protocol time-out, the default IP protocol time-out will still apply and override.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        xtd::net::sockets::linger_option linger_state() const;
        /// @brief Sets a value that specifies whether the xtd::net::sockets::socket will delay closing a socket in an attempt to send all pending data.
        /// @param value A xtd::net::sockets::sockets::linger_option that specifies how to linger while closing a socket.
        /// @return This current instance.
        /// @exception xtd::net::sockets::socket_exception This option is valid for a datagram socket only.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks The xtd::net::sockets::socket::linger_state property changes the way xtd::net::sockets::socket::close method behaves. This property when set modifies the conditions under which the connection can be reset by Winsock. Connection resets can still occur based on the IP protocol behavior.
        /// @remarks This property controls the length of time that a connection-oriented connection will remain open after a call to xtd::net::sockets::socket::close when data remains to be sent.
        /// @remarks When you call methods to send data to a peer, this data is placed in the outgoing network buffer. This property can be used to ensure that this data is sent to the remote host before the xtd::net::sockets::socket::close method drops the connection.
        /// @remarks To enable lingering, create a xtd::net::sockets::linger_option instance containing the desired values, and set the xtd::net::sockets::socket::linger_state property to this instance.
        /// @remarks The following table describes the behavior of the xtd::net::sockets::socket::close method for the possible values of the xtd::net::sockets::inger_option::enabled property and the xtd::net::sockets::linger_option::linger_time property stored in the xtd::net::sockets::socket::linger_state property.
        /// | xtd::net::sockets::linger_state::enabled | xtd::net::sockets::linger_state::linger_time | Behavior                                                                                                                          |
        /// |------------------------------------------|----------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------|
        /// | false (disabled), the default value      | The time-out is not applicable, (default).   | Attempts to send pending data until the default IP protocol time-out expires.                                                     |
        /// | true (enabled)                           | A nonzero time-out.                          | Attempts to send pending data until the specified time-out expires, and if the attempt fails, then Winsock resets the connection. |
        /// | true (enabled)                           | A zero time-out.                             | Discards any pending data. For connection-oriented socket (TCP, for example), Winsock resets the connection.                      |
        /// @remarks The IP stack computes the default IP protocol time-out period to use based on the round trip time of the connection. In most cases, the time-out computed by the stack is more relevant than one defined by an application. This is the default behavior for a socket when the xtd::net::sockets::socket::linger_state property is not set.
        /// @remarks When the xtd::net::sockets::linger_option::linger_time property stored in the xtd::net::sockets::socket::linger_state property is set greater than the default IP protocol time-out, the default IP protocol time-out will still apply and override.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        socket& linger_state(const xtd::net::sockets::linger_option& value);

        /// @brief Gets the local endpoint.
        /// @return The xtd::net::end_point that the xtd::net::sockets::socket is using for communications.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks The xtd::net::sockets::socket::local_end_point property gets an xtd::net::end_point that contains the local IP address and port number to which your xtd::net::sockets::socket is bound. You must cast this xtd::net::end_point to an xtd::net::ip_end_point before retrieving any information. You can then call the xtd::net::ip_end_point::address method to retrieve the local xtd::net::ip_address, and the xtd::net::ip_end_point::port method to retrieve the local port number.
        /// @remarks The xtd::net::sockets::socket::local_end_point property is usually set after you make a call to the xtd::net::sockets::socket::bind method. If you allow the system to assign your socket's local IP address and port number, the xtd::net::sockets::socket::local_end_point property will be set after the first I/O operation. For connection-oriented protocols, the first I/O operation would be a call to the xtd::net::sockets::socket::connect or xtd::net::sockets::socket::accept method. For connectionless protocols, the first I/O operation would be any of the send or receive calls.
        std::shared_ptr<xtd::net::end_point> local_end_point() const;
        
        /// @brief Gets a value that specifies whether outgoing multicast packets are delivered to the sending application.
        /// @return true if the xtd::net::sockets::socket receives outgoing multicast packets; otherwise, false.
        /// @exception xtd::net::sockets::socket_exception This option is valid for a datagram socket only.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @exception xtd::not_supported_exception The xtd::net::sockets::socket is not in the xtd::net::sockets::address_family::inter_network or xtd::net::sockets::address_family::inter_network_v6 families.
        /// @remarks Multicast is a scalable method for many-to-many communication on the Internet. A process subscribes to a multicast address; then, any packets sent by a subscribed process are received by every other process subscribed to the multicast address.
        /// @remarks Setting this property on a Transmission Control Protocol (TCP) socket has no effect.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        bool multicast_loopback() const;
        /// @brief Sets a value that specifies whether outgoing multicast packets are delivered to the sending application.
        /// @param value true if the xtd::net::sockets::socket receives outgoing multicast packets; otherwise, false.
        /// @return This current instance.
        /// @exception xtd::net::sockets::socket_exception This option is valid for a datagram socket only.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @exception xtd::not_supported_exception The xtd::net::sockets::socket is not in the xtd::net::sockets::address_family::inter_network or xtd::net::sockets::address_family::inter_network_v6 families.
        /// @remarks Multicast is a scalable method for many-to-many communication on the Internet. A process subscribes to a multicast address; then, any packets sent by a subscribed process are received by every other process subscribed to the multicast address.
        /// @remarks Setting this property on a Transmission Control Protocol (TCP) socket has no effect.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        socket& multicast_loopback(bool value);
        
        /// @brief Gets a boolean value that specifies whether the stream xtd::net::sockets::socket is using the Nagle algorithm.
        /// @return false if the xtd::net::sockets::socket uses the Nagle algorithm; otherwise, true. The default is false.
        /// @exception xtd::net::sockets::socket_exception This option is valid for a datagram socket only.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks The Nagle algorithm is designed to reduce network traffic by causing the socket to buffer small packets and then combine and send them in one packet under certain circumstances. A TCP packet consists of 40 bytes of header plus the data being sent. When small packets of data are sent with TCP, the overhead resulting from the TCP header can become a significant part of the network traffic. On heavily loaded networks, the congestion resulting from this overhead can result in lost datagrams and retransmissions, as well as excessive propagation time caused by congestion. The Nagle algorithm inhibits the sending of new TCP segments when new outgoing data arrives from the user if any previously transmitted data on the connection remains unacknowledged.
        /// @remarks The majority of network applications should use the Nagle algorithm.
        /// @remarks Setting this property on a User Datagram Protocol (UDP) socket will have no effect.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        bool no_delay() const;
        /// @brief Gets a boolean value that specifies whether the stream xtd::net::sockets::socket is using the Nagle algorithm.
        /// @param value false if the xtd::net::sockets::socket uses the Nagle algorithm; otherwise, true. The default is false.
        /// @return This current instance.
        /// @exception xtd::net::sockets::socket_exception This option is valid for a datagram socket only.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks The Nagle algorithm is designed to reduce network traffic by causing the socket to buffer small packets and then combine and send them in one packet under certain circumstances. A TCP packet consists of 40 bytes of header plus the data being sent. When small packets of data are sent with TCP, the overhead resulting from the TCP header can become a significant part of the network traffic. On heavily loaded networks, the congestion resulting from this overhead can result in lost datagrams and retransmissions, as well as excessive propagation time caused by congestion. The Nagle algorithm inhibits the sending of new TCP segments when new outgoing data arrives from the user if any previously transmitted data on the connection remains unacknowledged.
        /// @remarks The majority of network applications should use the Nagle algorithm.
        /// @remarks Setting this property on a User Datagram Protocol (UDP) socket will have no effect.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        socket& no_delay(bool value);
        
        /// @brief Indicates whether the underlying operating system and network adaptors support Internet Protocol version 4 (IPv4).
        /// @return true if the operating system and network adaptors support the IPv4 protocol; otherwise, false.
        /// @remarks The operating system may support both IPv4 and IPv6 protocols.
        static bool os_supports_ip_v4() noexcept;
        
        /// @brief Indicates whether the underlying operating system and network adaptors support Internet Protocol version 6 (IPv6).
        /// @return true if the operating system and network adaptors support the IPv6 protocol; otherwise, false.
        /// @remarks The operating system may support both IPv4 and IPv6 protocols.
        static bool os_supports_ip_v6() noexcept;
        
        /// @brief Gets the protocol type of the xtd::net::sockets::socket.
        /// @return One of the xtd::net::sockets::protocol_type values.
        /// @remarks The xtd::net::sockets::socket::protocol_type property is set when the xtd::net::sockets::socket is created, and specifies the protocol used by that xtd::net::sockets::socket.
        xtd::net::sockets::protocol_type protocol_type() const noexcept;
        
        /// @brief Gets a value that specifies the size of the receive buffer of the xtd::net::sockets::socket.
        /// @return An size_t that contains the size, in bytes, of the receive buffer. The default is 8192.
        /// @exception xtd::net::sockets::socket_exception This option is valid for a datagram socket only.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks A larger buffer size potentially reduces the number of empty acknowledgements (TCP packets with no data portion), but might also delay the recognition of connection difficulties. Consider increasing the buffer size if you are transferring large files, or you are using a high bandwidth, high latency connection (such as a satellite broadband provider.)
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        size_t receive_buffer_size() const;
        /// @brief Sets a value that specifies the size of the receive buffer of the xtd::net::sockets::socket.
        /// @param value An size_t that contains the size, in bytes, of the receive buffer. The default is 8192.
        /// @return This current instance.
        /// @exception xtd::net::sockets::socket_exception This option is valid for a datagram socket only.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks A larger buffer size potentially reduces the number of empty acknowledgements (TCP packets with no data portion), but might also delay the recognition of connection difficulties. Consider increasing the buffer size if you are transferring large files, or you are using a high bandwidth, high latency connection (such as a satellite broadband provider.)
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        socket& receive_buffer_size(size_t value);

        /// @brief Gets a value that specifies the amount of time after which a synchronous xtd::net::sockets::socket::receive call will time out.
        /// @return The time-out value, in milliseconds. The default value is 0, which indicates an infinite time-out period. Specifying -1 also indicates an infinite time-out period.
        /// @exception xtd::net::sockets::socket_exception This option is valid for a datagram socket only.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks This option applies to synchronous xtd::net::sockets::socket::receive calls only. If the time-out period is exceeded, the xtd::net::sockets::socket::receive method will throw a xtd::net::sockets::socket_exception.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        int32_t receive_timeout() const;
        /// @brief Sets a value that specifies the amount of time after which a synchronous xtd::net::sockets::socket::receive call will time out.
        /// @param value The time-out value, in milliseconds. The default value is 0, which indicates an infinite time-out period. Specifying -1 also indicates an infinite time-out period.
        /// @return This current instance.
        /// @exception xtd::net::sockets::socket_exception This option is valid for a datagram socket only.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @exception xtd::argument_out_of_range_exception The value specified for a set operation is less than -1.
        /// @remarks This option applies to synchronous xtd::net::sockets::socket::receive calls only. If the time-out period is exceeded, the xtd::net::sockets::socket::receive method will throw a xtd::net::sockets::socket_exception.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        socket& receive_timeout(int32_t value);
        
        /// @brief Gets the remote endpoint.
        /// @return The xtd::net::end_point with which the xtd::net::sockets::socket is communicating.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks If you are using a connection-oriented protocol, the xtd::net::sockets::socket::remote_end_point property gets the xtd::net::sockets::end_point that contains the remote IP address and port number to which the xtd::net::sockets::socket is connected. If you are using a connectionless protocol, xtd::net::sockets::socket::remote_end_point contains the default remote IP address and port number with which the xtd::net::sockets::socket will communicate. You must cast this xtd::net::end_point to an xtd::net::ip_end_point before retrieving any information. You can then call the xtd::net::ip_end_point::address method to retrieve the remote xtd::net::ip_address, and the xtd::net::ip_end_point::port method to retrieve the remote port number.
        /// @remarks The xtd::net::sockets::socket::remote_end_point is set after a call to either xtd::net::sockets::socket::accept or xtd::net::sockets::socket::connect. If you try to access this property earlier, xtd::net::sockets::socket::remote_end_point will throw a xtd::net::sockets::socket_exception. If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        std::shared_ptr<xtd::net::end_point> remote_end_point() const;

        /// @brief Gets a value that specifies the size of the send buffer of the xtd::net::sockets::socket.
        /// @return An size_t that contains the size, in bytes, of the send buffer. The default is 8192.
        /// @exception xtd::net::sockets::socket_exception This option is valid for a datagram socket only.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks A larger buffer size might delay the recognition of connection difficulties. Consider increasing the buffer size if you are transferring large files, or you are using a high bandwidth, high latency connection (such as a satellite broadband provider.)
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        size_t send_buffer_size() const;
        /// @brief Sets a value that specifies the size of the send buffer of the xtd::net::sockets::socket.
        /// @param value An size_t that contains the size, in bytes, of the send buffer. The default is 8192.
        /// @return This current instance.
        /// @exception xtd::net::sockets::socket_exception This option is valid for a datagram socket only.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks A larger buffer size might delay the recognition of connection difficulties. Consider increasing the buffer size if you are transferring large files, or you are using a high bandwidth, high latency connection (such as a satellite broadband provider.)
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        socket& send_buffer_size(size_t value);
        
        /// @brief Gets a value that specifies the amount of time after which a synchronous xtd::net::sockets::socket::send call will time out.
        /// @return The time-out value, in milliseconds. If you set the property with a value between 1 and 499, the value will be changed to 500. The default value is 0, which indicates an infinite time-out period. Specifying -1 also indicates an infinite time-out period.
        /// @exception xtd::net::sockets::socket_exception This option is valid for a datagram socket only.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks This option applies to synchronous Send calls only. If the time-out period is exceeded, the Send method will throw a xtd::net::sockets::socket::socket_exception.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        int32_t send_timeout() const;
        /// @brief Sets a value that specifies the amount of time after which a synchronous xtd::net::sockets::socket::send call will time out.
        /// @param value The time-out value, in milliseconds. If you set the property with a value between 1 and 499, the value will be changed to 500. The default value is 0, which indicates an infinite time-out period. Specifying -1 also indicates an infinite time-out period.
        /// @return This current instance.
        /// @exception xtd::net::sockets::socket_exception This option is valid for a datagram socket only.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @exception xtd::argument_out_of_range_exception The value specified for a set operation is less than -1.
        /// @remarks This option applies to synchronous Send calls only. If the time-out period is exceeded, the Send method will throw a xtd::net::sockets::socket::socket_exception.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        socket& send_timeout(int32_t value);

        /// @brief Gets the type of the xtd::net::sockets::socket.
        /// @return One of the xtd::net::sockets::socket_type values.
        /// @remarks xtd::net::sockets::socket::socket_type is read-only and is set when the xtd::net::sockets::socket is created.
        xtd::net::sockets::socket_type socket_type() const noexcept;

        /// @brief Gets a value that specifies the Time To Live (TTL) value of Internet Protocol (IP) packets sent by the xtd::net::sockets::socket.
        /// @return The TTL value.
        /// @exception xtd::net::sockets::socket_exception This option is valid for a datagram socket only.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @exception xtd::not_supported_exception he xtd::net::sockets::socket is not in the xtd::net::sockets::address_family::inter_network or xtd::net::sockets::address_family::inter_network_v6 families.
        /// @remarks The TTL value indicates the maximum number of routers the packet can traverse before the router discards the packet and an Internet Control Message Protocol (ICMP) "TTL exceeded" error message is returned to the sender.
        /// @remarks The TTL value may be set to a value from 0 to 255. When this property is not set, the default TTL value for a socket is 32.
        /// @remarks Setting this property on a Transmission Control Protocol (TCP) socket is ignored by the TCP/IP stack if a successful connection has been established using the socket.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        byte_t ttl() const;
        /// @brief Sets a value that specifies the Time To Live (TTL) value of Internet Protocol (IP) packets sent by the xtd::net::sockets::socket.
        /// @param value The TTL value.
        /// @return This current instance.
        /// @exception xtd::net::sockets::socket_exception This option is valid for a datagram socket only.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @exception xtd::not_supported_exception he xtd::net::sockets::socket is not in the xtd::net::sockets::address_family::inter_network or xtd::net::sockets::address_family::inter_network_v6 families.
        /// @remarks The TTL value indicates the maximum number of routers the packet can traverse before the router discards the packet and an Internet Control Message Protocol (ICMP) "TTL exceeded" error message is returned to the sender.
        /// @remarks The TTL value may be set to a value from 0 to 255. When this property is not set, the default TTL value for a socket is 32.
        /// @remarks Setting this property on a Transmission Control Protocol (TCP) socket is ignored by the TCP/IP stack if a successful connection has been established using the socket.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        socket& ttl(byte_t value);
        
        /// @brief Creates a new xtd::net::sockets::socket for a newly created connection.
        /// @return A xtd::net::sockets::socket for a newly created connection.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @exception xtd::invalid_operation_exception The accepting socket is not listening for connections. You must call xtd::net::sockets::socket::bind and xtd::net::sockets::socket::listen before calling xtd::net::sockets::socket::accept().
        /// @remarks xtd::net::sockets::socket::accept synchronously extracts the first pending connection request from the connection request queue of the listening socket, and then creates and returns a new xtd::net::sockets::socket. You cannot use this returned xtd::net::sockets::socket to accept any additional connections from the connection queue. However, you can call the xtd::net::sockets::socket::remote_end_point method of the returned xtd::net::sockets::socket to identify the remote host's network address and port number.
        /// @remarks In blocking mode, xtd::net::sockets::socket::accept blocks until an incoming connection attempt is queued. Once a connection is accepted, the original xtd::net::sockets::socket continues queuing incoming connection requests until you close it.
        /// @remarks If you call this method using a non-blocking xtd::net::sockets::socket, and no connection requests are queued, xtd::net::sockets::socket::accept throws a xtd::net::sockets::socket_exception. If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        /// @note Before calling the xtd::net::sockets::socket::accept method, you must first call the xtd::net::sockets::socket::listen method to listen for and queue incoming connection requests.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        socket accept();
        
        /// @brief Begins an asynchronous operation to accept an incoming connection attempt.
        /// @param e The xtd::net::sockets::socket::socket_async_event_args object to use for this asynchronous socket operation.
        /// @return true if the I/O operation is pending. The Completed event on the e parameter will be raised upon completion of the operation. false if the I/O operation completed synchronously. The Completed event on the e parameter will not be raised and the e object passed as a parameter may be examined immediately after the method call returns to retrieve the result of the operation.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @exception xtd::argument_exception An argument is not valid. This exception occurs if the buffer provided is not large enough. The buffer must be at least 2 * (sizeof(SOCKADDR_STORAGE + 16) bytes. This exception also occurs if multiple buffers are specified, the xtd::net::sockets::socket_async_event_args::buffer_list property is not empty.
        /// @exception xtd::invalid_operation_exception The accepting socket is not listening for connections. You must call xtd::net::sockets::socket::bind and xtd::net::sockets::socket::listen before calling xtd::net::sockets::socket::accept().
        /// @remarks Connection-oriented protocols can use the xtd::net::sockets::socket::accept_async method to asynchronously process incoming connection attempts. Accepting connections asynchronously gives you the ability to send and receive data within a separate execution thread. Before calling the xtd::net::sockets::socket::accept_async method, you must call the xtd::net::sockets::socket::listen method to listen for and queue incoming connection requests.
        /// @remarks To be notified of completion, you must create a callback method that implements the xtd::delegate<const xtd::net::sockets::socket_async_event_args&> delegate and hook it to the xtd::net::sockets::socket_async_event_args::completed event.
        /// @remarks The following properties and events on the xtd::net::sockets::socket_async_event_args object are required:
        /// * xtd::net::sockets::socket_async_event_args::completed
        /// @remarks The caller can optionally specify an existing xtd::net::sockets::socket to use for the incoming connection by specifying the xtd::net::sockets::socket to use with the xtd::net::sockets::socket_async_eventArgs::accept_socket property.
        /// @remarks If the xtd::net::sockets::socket_async_event_args::accept_socket property is empty, a new xtd::net::sockets::socket is constructed with the same xtd::net::sockets::address_family, xtd::net::sockets::socket_type, and xtd::net::sockets::protocol_type as the current xtd::net::sockets::socket and set as the xtd::net::sockets::socket_async_event_args::accept_socket property.
        /// @remarks The caller may set the xtd::net::sockets::socket_async_event_args::user_token property to any user state object desired before calling the xtd::net::sockets::socket::accept_async method, so that the information will be retrievable in the callback method. If the callback needs more information than a single object, a small class can be created to hold the other required state information as members.
        /// @remarks Optionally, a buffer may be provided in which to receive the initial block of data on the socket after the xtd::net::sockets::socket::connect_async method succeeds. In this case, the xtd::net::sockets::socket_async_event_args::buffer property needs to be set to the buffer containing the data to receive and the xtd::net::sockets::socket_async_event_args::count property needs to be set to the maximum number of bytes of data to receive in the buffer. These properties can be set using the xtd::net::sockets::socket_async_event_args::set_buffer method. Part of the buffer passed in will be consumed internally for use by the underlying Winsock AcceptEx call. This means that the amount of data returned will always be less than the value of the xtd::net::sockets::socket::async_event_args::count property on the xtd::net::sockets::socket_async_event_args instance provided. The amount of the buffer used internally varies based on the address family of the socket. The minimum buffer size required is 288 bytes. If a larger buffer size is specified, then the xtd::net::sockets::socket will expect some extra data other than the address data received by the Winsock AcceptEx call and will wait until this extra data is received. If a timeout occurs, the connection is reset. So if extra data is expected of a specific amount, then the buffer size should be set to the minimum buffer size plus this amount.
        /// @remarks The completion callback method should examine the xtd::net::sockets::socket_async_event_args::socket_error property to determine if the xtd::net::sockets::socket::accept_async operation was successful.
        /// @remarks The xtd::net::sockets::socket_async_event_args::completed event can occur in some cases when no connection has been accepted and cause the xtd::net::sockets::socket_async_event_args::socket_error property to be set to xtd::net::sockets::socket_error::connection_reset. This can occur as a result of port scanning using a half-open SYN type scan (a SYN -> SYN-ACK -> RST sequence). Applications using the xtd::net::sockets::socket::accept_async method should be prepared to handle this condition.
        bool accept_async(xtd::net::sockets::socket_async_event_args& e);

        /// @brief Begins an asynchronous operation to accept an incoming connection attempt.
        /// @param callback The xtd::async_callback delegate.
        /// @param state An object that contains state information for this request.
        /// @return An xtd::iasync_result that references the asynchronous connection.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @exception xtd::invalid_operation_exception The accepting socket is not listening for connections. You must call xtd::net::sockets::socket::bind and xtd::net::sockets::socket::listen before calling xtd::net::sockets::socket::accept().
        /// @exception xtd::invalid_operation_exception The accepting socket is not listening for connections. You must call xtd::net::sockets::socket::bind and xtd::net::sockets::socket::listen before calling xtd::net::sockets::socket::accept().
        /// @remarks Connection-oriented protocols can use the xtd::net::sockets::socket::begin_accept method to asynchronously process incoming connection attempts. Accepting connections asynchronously gives you the ability to send and receive data within a separate execution thread. Before calling the xtd::net::sockets::socket::begin_accept method, you must call the xtd::net::sockets::socket::socket::listen method to listen for and queue incoming connection requests.
        /// @remarks You must create a callback method that implements the xtd::async_callback delegate and pass its name to the xtd::net::sockets::socket::begin_accept method. To do this, at the very minimum, you must pass the listening xtd::net::sockets::socket::socket object to xtd::net::sockets::socket::begin_accept through the state parameter. If your callback needs more information, you can create a small class to hold the xtd::net::sockets::socket::socket and the other required information. Pass an instance of this class to the xtd::net::sockets::socket::begin_accept method through the state parameter.
        /// @remarks Your callback method should invoke the xtd::net::sockets::socket::end_accept method. When your application calls xtd::net::sockets::socket::begin_accept, the system usually uses a separate thread to execute the specified callback method and blocks on xtd::net::sockets::socket::end_accept until a pending connection is retrieved. xtd::net::sockets::socket::end_accept will return a new xtd::net::sockets::socket::socket object that you can use to send and receive data with the remote host. You cannot use this returned xtd::net::sockets::socket::socket to accept any additional connections from the connection queue. If you want the original thread to block after you call the xtd::net::sockets::socket::begin_accept method, use std::mutex::lock. Call the std::mutex::unlock method on a std::mutex in the callback method when you want the original thread to continue executing.
        /// @remarks The system may also use the calling thread to invoke the callback method. In this case, the xtd::iasync_result::completed_synchronously property on the returned xtd::iasync_result will be set to indicate that the xtd::net::sockets::socket::begin_accept method completed synchronously.
        /// @remarks To cancel a pending call to the xtd::net::sockets::socket::begin_accept method, close the xtd::net::sockets::socket::socket. When the xtd::sockets::socket::close method is called while an asynchronous operation is in progress, the callback provided to the xtd::net::sockets::socket::begin_accept method is called. A subsequent call to the xtd::net::sockets::socket::end_accept method will throw an xtd::object_closed_exception to indicate that the operation has been cancelled.
        /// @note You can use the xtd::net::sockets::socket::remote_end_point property of the returned xtd::net::sockets::socket::socket to identify the remote host's network address and port number.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        std::shared_ptr<xtd::iasync_result> begin_accept(xtd::async_callback callback, const std::any& state);

        /// @brief Begins an asynchronous request for a remote host connection.
        /// @param remote_end_point An xtd::net::end_point that represents the remote host.
        /// @param callback The xtd::async_callback delegate.
        /// @param state An object that contains state information for this request.
        /// @return An xtd::iasync_result that references the asynchronous connection.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @exception xtd::invalid_operation_exception The accepting socket is not listening for connections. You must call xtd::net::sockets::socket::bind and xtd::net::sockets::socket::listen before calling xtd::net::sockets::socket::accept().
        /// @remarks If you are using a connection-oriented protocol, the xtd::net::sockets::socket::begin_connect method starts an asynchronous request for a connection to the remote_end_point parameter. If you are using a connectionless protocol, xtd::net::sockets::socket::begin_connect establishes a default remote host. Connecting or setting the default remote host asynchronously gives you the ability to send and receive data within a separate execution thread.
        /// @remarks You can create a callback method that implements the xtd::async_callback delegate and pass its name to the xtd::net::sockets::socket::begin_connect method. At the very minimum, you must pass the xtd::net::sockets::socket::socket to xtd::net::sockets::socket::begin_connect through the state parameter. If your callback needs more information, you can create a small class to hold the xtd::net::sockets::socket::socket, and the other required information. Pass an instance of this class to the xtd::net::sockets::socket::begin_connect method through the state parameter.
        /// @remarks Your callback method should invoke the xtd::net::sockets::socket::end_connect method. When your application calls xtd::net::sockets::socket::begin_connect, the system will use a separate thread to execute the specified callback method, and will block on xtd::net::sockets::socket::end_connect until the xtd::net::sockets::socket::socket connects successfully or throws an exception. If you want the original thread to block after you call the xtd::net::sockets::socket::begin_connect method, use std::mutex::lock. Call the std::mutex::unlock method on a std::mutex in the callback method when you want the original thread to continue executing.
        /// @remarks If you are using a connectionless protocol such as UDP, you do not have to call xtd::net::sockets::socket::begin_connect before sending and receiving data. You can use xtd::net::sockets::socket::begin_send_to and xtd::net::sockets::socket::begin_receive_from to communicate with a remote host. If you do call xtd::net::sockets::socket::begin_connect, any datagrams that arrive from an address other than the specified default will be discarded. If you wish to set your default remote host to a broadcast address, you must first call xtd::net::sockets::socket::set_socket_option and set xtd::net::sockets::socket::socket_option_name::broadcast to true. If you cannot, xtd::net::sockets::socket::begin_connect will throw a xtd::net::sockets::socket_exception.
        /// @remarks If you are using a connection-oriented protocol and do not call xtd::net::sockets::socket::bind before calling xtd::net::sockets::socket::begin_connect, the underlying service provider will assign the most appropriate local network address and port number. If you are using a connectionless protocol, the service provider will not assign a local network address and port number until you call the xtd::net::sockets::socket::begin_send or xtd::net::sockets::socket::receive_from method. If you want to change the default remote host, call the xtd::net::sockets::socket::begin_connect method again with the desired endpoint.
        /// @remarks To cancel a pending call to the xtd::net::sockets::socket::begin_connect method, close the xtd::net::sockets::socket::socket. When the xtd::net::sockets::socket::socket::close method is called while an asynchronous operation is in progress, the callback provided to the xtd::net::sockets::socket::begin_connect method is called. A subsequent call to the xtd::net::sockets::socket::end_connect method will throw an xtd::object_closed_exception to indicate that the operation has been cancelled.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        /// @note If this socket has previously been disconnected, then xtd::net::sockets::socket::begin_connect must be called on a thread that will not exit until the operation is complete. This is a limitation of the underlying provider.
        template<typename end_point_t>
        std::shared_ptr<xtd::iasync_result> begin_connect(const end_point_t& remote_end_point, xtd::async_callback callback, const std::any& state) {
          return begin_connect_(std::make_shared<end_point_t>(remote_end_point), callback, state);
        }
        /// @brief Begins an asynchronous request for a remote host connection. The host is specified by an xtd::net::ip_address and a port number.
        /// @param address The xtd::net::ip_address of the remote host.
        /// @param port The port number of the remote host.
        /// @param callback The xtd::async_callback delegate.
        /// @param state An object that contains state information for this request.
        /// @return An xtd::iasync_result that references the asynchronous connection.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @exception xtd::invalid_operation_exception The accepting socket is not listening for connections. You must call xtd::net::sockets::socket::bind and xtd::net::sockets::socket::listen before calling xtd::net::sockets::socket::accept().
        /// @remarks The asynchronous xtd::net::sockets::socket::begin_connect operation must be completed by calling the xtd::net::sockets::socket::end_connect method. Typically, the method is invoked by the callback delegate.
        /// @remarks This method does not block until the operation is complete. To block until the operation is complete, use one of the xtd::net::sockets::socket::connect method overloads, or xtd::net::sockets::socket::end_connect.
        /// @remarks To cancel a pending call to the xtd::net::sockets::socket::begin_connect method, close the xtd::net::sockets::socket::socket. When the xtd::net::sockets::socket::socket::close method is called while an asynchronous operation is in progress, the callback provided to the xtd::net::sockets::socket::begin_connect method is called. A subsequent call to the xtd::net::sockets::socket::end_connect method will throw an xtd::object_closed_exception to indicate that the operation has been cancelled.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        /// @note If this socket has previously been disconnected, then xtd::net::sockets::socket::begin_connect must be called on a thread that will not exit until the operation is complete. This is a limitation of the underlying provider. Also the xtd::net::end_point that is used must be different.
        std::shared_ptr<xtd::iasync_result> begin_connect(const xtd::net::ip_address& address, uint16_t port, xtd::async_callback callback, const std::any& state);
        /// @brief Begins an asynchronous request for a remote host connection. The host is specified by an xtd::net::ip_address array and a port number.
        /// @param addresses At least one xtd::net::ip_address, designating the remote host.
        /// @param port The port number of the remote host.
        /// @param callback An xtd::async_callback delegate that references the method to invoke when the connect operation is complete.
        /// @param state A user-defined object that contains information about the connect operation. This object is passed to the requestCallback delegate when the operation is complete.
        /// @return An xtd::iasync_result that references the asynchronous connection.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @exception xtd::invalid_operation_exception The accepting socket is not listening for connections. You must call xtd::net::sockets::socket::bind and xtd::net::sockets::socket::listen before calling xtd::net::sockets::socket::accept().
        /// @remarks The asynchronous xtd::net::sockets::socket::begin_connect operation must be completed by calling the xtd::net::sockets::socket::end_connect method. Typically, the method is invoked by the callback delegate.
        /// @remarks This method does not block until the operation is complete. To block until the operation is complete, use one of the xtd::net::sockets::socket::connect method overloads.
        /// @remarks To cancel a pending call to the xtd::net::sockets::socket::begin_connect method, close the xtd::net::sockets::socket::socket. When the xtd::net::sockets::socket::socket::close method is called while an asynchronous operation is in progress, the callback provided to the xtd::net::sockets::socket::begin_connect method is called. A subsequent call to the xtd::net::sockets::socket::end_connect method will throw an xtd::object_closed_exception to indicate that the operation has been cancelled.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        /// @note If this socket has previously been disconnected, then xtd::net::sockets::socket::begin_connect must be called on a thread that will not exit until the operation is complete. This is a limitation of the underlying provider. Also the xtd::net::end_point that is used must be different.
        std::shared_ptr<xtd::iasync_result> begin_connect(const std::vector<xtd::net::ip_address>& addresses, uint16_t port, xtd::async_callback callback, const std::any& state);
        /// @brief Begins an asynchronous request for a remote host connection. The host is specified by a host name and a port number.
        /// @param host The name of the remote host.
        /// @param port The port number of the remote host.
        /// @param callback The xtd::async_callback delegate.
        /// @param state An object that contains state information for this request.
        /// @return An xtd::iasync_result that references the asynchronous connection.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @exception xtd::invalid_operation_exception The accepting socket is not listening for connections. You must call xtd::net::sockets::socket::bind and xtd::net::sockets::socket::listen before calling xtd::net::sockets::socket::accept().
        /// @remarks The asynchronous xtd::net::sockets::socket::begin_connect operation must be completed by calling the xtd::net::sockets::socket::end_connect method. Typically, the method is invoked by the callback delegate.
        /// @remarks This method does not block until the operation is complete. To block until the operation is complete, use one of the xtd::net::sockets::socket::connect method overloads.
        /// @remarks To cancel a pending call to the xtd::net::sockets::socket::begin_connect method, close the xtd::net::sockets::socket::socket. When the xtd::net::sockets::socket::socket::close method is called while an asynchronous operation is in progress, the callback provided to the xtd::net::sockets::socket::begin_connect method is called. A subsequent call to the xtd::net::sockets::socket::end_connect method will throw an xtd::object_closed_exception to indicate that the operation has been cancelled.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        /// @note If this socket has previously been disconnected, then xtd::net::sockets::socket::begin_connect must be called on a thread that will not exit until the operation is complete. This is a limitation of the underlying provider. Also the xtd::net::end_point that is used must be different.
        std::shared_ptr<xtd::iasync_result> begin_connect(const xtd::ustring& host, uint16_t port, xtd::async_callback callback, const std::any& state);

        /// @brief Begins an asynchronous request to disconnect from a remote endpoint.
        /// @param reuse_socket true if this socket can be reused after the connection is closed; otherwise, false.
        /// @param callback The xtd::async_callback delegate.
        /// @param state An object that contains state information for this request.
        /// @return An xtd::iasync_result that references the asynchronous connection.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @exception xtd::invalid_operation_exception The accepting socket is not listening for connections. You must call xtd::net::sockets::socket::bind and xtd::net::sockets::socket::listen before calling xtd::net::sockets::socket::accept().
        /// @remarks If you are using a connection-oriented protocol, you can call the xtd::net::sockets::socket::begin_disconnect method to request a disconnect from a remote endpoint. If reuse_socket is true, you can reuse the socket.
        /// @remarks The xtd::net::sockets::socket::begin_disconnect method uses a separate thread to invoke the specified callback method. The xtd::net::sockets::socket::end_disconnect method blocks until the pending disconnect is complete.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        std::shared_ptr<xtd::iasync_result> begin_disconnect(bool reuse_socket, xtd::async_callback callback, const std::any& state);
        
        /// @brief Begins to asynchronously receive data from a connected xtd::net::sockets::socket::socket.
        /// @param buffer An array of type byte_t that is the storage location for the received data.
        /// @param offset The zero-based position in the buffer parameter at which to store the received data.
        /// @param size The number of bytes to receive.
        /// @param socket_flags A bitwise combination of the xtd::net::sockets::socket_flags values.
        /// @param callback The xtd::async_callback delegate.
        /// @param state An object that contains state information for this request.
        /// @return An xtd::iasync_result that references the asynchronous connection.
        /// @exception xtd::argument_out_of_range_exception size is less than 0 or exceeds the size of the buffer.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @exception xtd::invalid_operation_exception The accepting socket is not listening for connections. You must call xtd::net::sockets::socket::bind and xtd::net::sockets::socket::listen before calling xtd::net::sockets::socket::accept().
        /// @remarks The asynchronous xtd::net::sockets::socket::begin_receive operation must be completed by calling the xtd::net::sockets::socket::end_receive method. Typically, the method is invoked by the callback delegate.
        /// @remarks This method does not block until the operation is complete. To block until the operation is complete, use one of the xtd::net::sockets::socket::receive method overloads.
        /// @remarks To cancel a pending xtd::net::sockets::socket::begin_receive, call the xtd::net::sockets::socket::socket::close method.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        /// @note All I/O initiated by a given thread is canceled when that thread exits. A pending asynchronous operation can fail if the thread exits before the operation completes.
        /// @note state is an instantiation of a user-defined class.
        std::shared_ptr<xtd::iasync_result> begin_receive(std::vector<byte_t>& buffer, size_t offset, size_t size, xtd::net::sockets::socket_flags socket_flags, xtd::async_callback callback, const std::any& state);
        /// @brief Begins to asynchronously receive data from a connected xtd::net::sockets::socket::socket.
        /// @param buffer An array of type byte_t that is the storage location for the received data.
        /// @param offset The zero-based position in the buffer parameter at which to store the received data.
        /// @param size The number of bytes to receive.
        /// @param socket_flags A bitwise combination of the xtd::net::sockets::socket_flags values.
        /// @param error_code A xtd::net::sockets::socket_error object that stores the socket error.
        /// @param callback The xtd::async_callback delegate.
        /// @param state An object that contains state information for this request.
        /// @return An xtd::iasync_result that references the asynchronous connection.
        /// @exception xtd::argument_out_of_range_exception size is less than 0 or exceeds the size of the buffer.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @exception xtd::invalid_operation_exception The accepting socket is not listening for connections. You must call xtd::net::sockets::socket::bind and xtd::net::sockets::socket::listen before calling xtd::net::sockets::socket::accept().
        /// @remarks The asynchronous xtd::net::sockets::socket::begin_receive operation must be completed by calling the xtd::net::sockets::socket::end_receive method. Typically, the method is invoked by the callback delegate.
        /// @remarks This method does not block until the operation is complete. To block until the operation is complete, use one of the xtd::net::sockets::socket::receive method overloads.
        /// @remarks To cancel a pending xtd::net::sockets::socket::begin_receive, call the xtd::net::sockets::socket::socket::close method.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        /// @note All I/O initiated by a given thread is canceled when that thread exits. A pending asynchronous operation can fail if the thread exits before the operation completes.
        /// @note state is an instantiation of a user-defined class.
        std::shared_ptr<xtd::iasync_result> begin_receive(std::vector<byte_t>& buffer, size_t offset, size_t size, xtd::net::sockets::socket_flags socket_flags, xtd::net::sockets::socket_error& error_code, xtd::async_callback callback, const std::any& state);
        
        /// @brief Begins to asynchronously receive data from a specified network device.
        /// @param buffer An array of type byte_t that is the storage location for the received data.
        /// @param offset The zero-based position in the buffer parameter at which to store the data.
        /// @param size The number of bytes to receive.
        /// @param socket_flags A bitwise combination of the xtd::net::sockets::socket_flags values.
        /// @param remote_end_point An xtd::net::end_point that represents the source of the data.
        /// @param callback The xtd::async_callback delegate.
        /// @param state An object that contains state information for this request.
        /// @return An xtd::iasync_result that references the asynchronous connection.
        /// @exception xtd::argument_out_of_range_exception size is less than 0 or exceeds the size of the buffer.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @exception xtd::invalid_operation_exception The accepting socket is not listening for connections. You must call xtd::net::sockets::socket::bind and xtd::net::sockets::socket::listen before calling xtd::net::sockets::socket::accept().
        /// @remarks The xtd::net::sockets::socket::begin_receive_from method starts asynchronously reading connectionless datagrams from a remote host. Calling the xtd::net::sockets::socket::begin_receive_from method gives you the ability to receive data within a separate execution thread.
        /// @remarks You can create a callback method that implements the xtd::async_callback delegate and pass its name to the xtd::net::sockets::socket::begin_receive_from method. To do this, at the very minimum, your state parameter must contain the connected or default xtd::net::sockets::socket::socket being used for communication. If your callback needs more information, you can create a small class to hold the xtd::net::sockets::socket::socket and the other required information. Pass an instance of this class to the xtd::net::sockets::socket::begin_receive_from method through the state parameter.
        /// @remarks Your callback method should invoke the xtd::net::sockets::socket::end_receive_from method. When your application calls xtd::net::sockets::socket::begin_receive_from, the system will use a separate thread to execute the specified callback method, and it will block on xtd::net::sockets::socket::end_receive_from until the xtd::net::sockets::socket::socket reads data or throws an exception. If you want the original thread to block after you call the xtd::net::sockets::socket::begin_receive_from method, use std::mutex::lock. Call the std::mutex::unlock method on a std::mutex in the callback method when you want the original thread to continue executing.
        /// @note Before calling xtd::net::sockets::socket::begin_receive_from, you must explicitly bind the xtd::net::sockets::socket::socket to a local endpoint using the xtd::net::sockets::socket::bind method, or xtd::net::sockets::socket::begin_receive_from will throw a xtd::net::sockets::socket_exception.
        /// @remarks This method reads data into the buffer parameter, and captures the remote host endpoint from which the data is sent. For information on how to retrieve this endpoint, refer to xtd::net::sockets::socket::end_receive_from. This method is most useful if you intend to asynchronously receive connectionless datagrams from an unknown host or multiple hosts. In these cases, xtd::net::sockets::socket::begin_receive_from will read the first enqueued datagram received into the local network buffer. If the datagram you receive is larger than the size of buffer, the xtd::net::sockets::socket::begin_receive_from method will fill buffer with as much of the message as is possible, and throw a xtd::net::sockets::socket_exception. If you are using an unreliable protocol, the excess data will be lost. If you are using a reliable protocol, the excess data will be retained by the service provider and you can retrieve it by calling the xtd::net::sockets::socket::begin_receive_from method with a large enough buffer.
        /// @remarks To guarantee that the remote host endpoint is always returned, an application should explicitly bind the xtd::net::sockets::socket::socket to a local endpoint using the xtd::net::sockets::socket::bind method and then call the xtd::net::sockets::socket::set_socket_option method with the optionLevel parameter set to IP or IPv6 as appropriate, the option_name parameter set to xtd::net::sockets::socket_option_name::packet_information, and the optionValue parameter to enable this option before calling the xtd::net::sockets::socket::begin_receive_from method. Otherwise, it is possible for the remote host endpoint to not be returned when the sender has sent a number of datagrams before the receiver has called the xtd::net::sockets::socket::begin_receive_from method.
        /// @remarks Although xtd::net::sockets::socket::begin_receive_from is intended for connectionless protocols, you can use a connection-oriented protocol as well. If you choose to do so, you must first either establish a remote host connection by calling the xtd::net::sockets::socket::connect / xtd::net::sockets::socket::begin_connect method or accept an incoming connection request by calling the xtd::net::sockets::socket::accept or xtd::net::sockets::socket::begin_accept method. If you call the xtd::net::sockets::socket::begin_receive_from method before establishing or accepting a connection, you will get a xtd::net::sockets::socket_exception. You can also establish a default remote host for a connectionless protocol prior to calling the xtd::net::sockets::socket::begin_receive_from method. In either of these cases, the xtd::net::sockets::socket::begin_receive_from method will ignore the remote_end_point parameter and only receive data from the connected or default remote host.
        /// @remarks With connection-oriented sockets, xtd::net::sockets::socket::begin_receive_from will read as much data as is available up to the number of bytes specified by the size parameter.
        /// @remarks To cancel a pending xtd::net::sockets::socket::begin_receive_from, call the xtd::net::sockets::socket::socket::close method.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        std::shared_ptr<xtd::iasync_result> begin_receive_from(std::vector<byte_t>& buffer, size_t offset, size_t size, xtd::net::sockets::socket_flags socket_flags, xtd::net::end_point& remote_end_point, xtd::async_callback callback, const std::any& state);
        
        /// @brief Begins to asynchronously receive the specified number of bytes of data into the specified location of the data buffer, using the specified xtd::net::sockets::socket_flags, and stores the endpoint and packet information.
        /// @param buffer An array of type byte_t that is the storage location for the received data.
        /// @param offset The zero-based position in the buffer parameter at which to store the data.
        /// @param size The number of bytes to receive.
        /// @param socket_flags A bitwise combination of the xtd::net::sockets::socket_flags values.
        /// @param remote_end_point An xtd::net::end_point that represents the source of the data.
        /// @param callback The xtd::async_callback delegate.
        /// @param state An object that contains state information for this request.
        /// @return An xtd::iasync_result that references the asynchronous connection.
        /// @exception xtd::argument_out_of_range_exception size is less than 0 or exceeds the size of the buffer.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @exception xtd::invalid_operation_exception The accepting socket is not listening for connections. You must call xtd::net::sockets::socket::bind and xtd::net::sockets::socket::listen before calling xtd::net::sockets::socket::accept().
        /// @remarks The asynchronous receive operation must be completed by calling the xtd::net::sockets::socket::end_receive_message_from method. Typically, the method is invoked by the callback delegate.
        /// @remarks This method does not block until the operation completes. To block until the operation completes, use the xtd::net::sockets::socket::receive_message_from method.
        /// @remarks To cancel a pending xtd::net::sockets::socket::begin_receive_message_from, call the xtd::net::sockets::socket::socket::close method.
        /// @remarks This method reads data into the buffer parameter, and captures the remote host endpoint from which the data is sent, as well as information about the received packet. For information on how to retrieve this endpoint, refer to xtd::net::sockets::socket::end_receive_from. This method is most useful if you intend to asynchronously receive connectionless datagrams from an unknown host or multiple hosts.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        std::shared_ptr<xtd::iasync_result> begin_receive_message_from(std::vector<byte_t>& buffer, size_t offset, size_t size, xtd::net::sockets::socket_flags socket_flags, xtd::net::end_point& remote_end_point, xtd::async_callback callback, const std::any& state);
        
        /// @brief Sends data asynchronously to a connected xtd::net::sockets::socket::socket.
        /// @param buffer An array of type byte_t that contains the data to send.
        /// @param offset The zero-based position in the buffer parameter at which to begin sending data.
        /// @param size The number of bytes to send.
        /// @param socket_flags A bitwise combination of the xtd::net::sockets::socket_flags values.
        /// @param callback The xtd::async_callback delegate.
        /// @param state An object that contains state information for this request.
        /// @return An xtd::iasync_result that references the asynchronous connection.
        /// @exception xtd::argument_out_of_range_exception size is less than 0 or exceeds the size of the buffer.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @exception xtd::invalid_operation_exception The accepting socket is not listening for connections. You must call xtd::net::sockets::socket::bind and xtd::net::sockets::socket::listen before calling xtd::net::sockets::socket::accept().
        /// @remarks The xtd::net::sockets::socket::begin_send method starts an asynchronous send operation to the remote host established in the xtd::net::sockets::socket::connect, xtd::net::sockets::socket::begin_connect, xtd::net::sockets::socket::accept, or xtd::net::sockets::socket::begin_accept method. xtd::net::sockets::socket::begin_send will throw an exception if you do not first call xtd::net::sockets::socket::accept, xtd::net::sockets::socket::begin_accept, xtd::net::sockets::socket::connect, or xtd::net::sockets::socket::begin_connect. Calling the xtd::net::sockets::socket::begin_send method gives you the ability to send data within a separate execution thread.
        /// @remarks You can create a callback method that implements the xtd::async_callback delegate and pass its name to the xtd::net::sockets::socket::begin_send method. To do this, at the very minimum, your state parameter must contain the connected or default xtd::net::sockets::socket::socket being used for communication. If your callback needs more information, you can create a small class or structure to hold the xtd::net::sockets::socket::socket and the other required information. Pass an instance of this class to the xtd::net::sockets::socket::begin_send method through the state parameter.
        /// @remarks Your callback method should invoke the xtd::net::sockets::socket::end_send method. When your application calls xtd::net::sockets::socket::begin_send, the system will use a separate thread to execute the specified callback method, and will block on xtd::net::sockets::socket::end_send until the xtd::net::sockets::socket::socket sends the number of bytes requested or throws an exception. If you want the original thread to block after you call the xtd::net::sockets::socket::begin_send method, use the std::mutex::lock method. Call the std::mutex::unlock method on a std::mutex in the callback method when you want the original thread to continue executing.
        /// @remarks Although intended for connection-oriented protocols, xtd::net::sockets::socket::begin_send also works for connectionless protocols, provided that you first call the xtd::net::sockets::socket::connect or xtd::net::sockets::socket::begin_connect method to establish a default remote host. If you are using a connectionless protocol and plan to send data to several different hosts, you should use xtd::net::sockets::socket::begin_send_to. It is okay to use xtd::net::sockets::socket::begin_send_to even after you have established a default remote host with xtd::net::sockets::socket::connect. You can also change the default remote host prior to calling xtd::net::sockets::socket::begin_send by making another call to xtd::net::sockets::socket::connect or xtd::net::sockets::socket::begin_connect. With connectionless protocols, you must also be sure that the size of your buffer does not exceed the maximum packet size of the underlying service provider. If it does, the datagram will not be sent and xtd::net::sockets::socket::begin_send will throw a xtd::net::sockets::socket_exception.
        /// @remarks If you specify the xtd::net::sockets::socket_flags::dont_route flag as the socketflags parameter, the data you are sending will not be routed.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        /// @note All I/O initiated by a given thread is canceled when that thread exits. A pending asynchronous operation can fail if the thread exits before the operation completes.
        /// @note state is an instantiation of a user-defined class.
        /// @note The successful completion of a send does not indicate that the data was successfully delivered. If no buffer space is available within the transport system to hold the data to be transmitted, send will block unless the socket has been placed in nonblocking mode.
        std::shared_ptr<xtd::iasync_result> begin_send(const std::vector<byte_t>& buffer, size_t offset, size_t size, xtd::net::sockets::socket_flags socket_flags, xtd::async_callback callback, const std::any& state);
        /// @brief Sends data asynchronously to a connected xtd::net::sockets::socket::socket.
        /// @param buffer An array of type byte_t that contains the data to send.
        /// @param offset The zero-based position in the buffer parameter at which to begin sending data.
        /// @param size The number of bytes to send.
        /// @param socket_flags A bitwise combination of the xtd::net::sockets::socket_flags values.
        /// @param error_code A xtd::net::sockets::socket_error object that stores the socket error.
        /// @param callback The xtd::async_callback delegate.
        /// @param state An object that contains state information for this request.
        /// @return An xtd::iasync_result that references the asynchronous connection.
        /// @exception xtd::argument_out_of_range_exception size is less than 0 or exceeds the size of the buffer.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @exception xtd::invalid_operation_exception The accepting socket is not listening for connections. You must call xtd::net::sockets::socket::bind and xtd::net::sockets::socket::listen before calling xtd::net::sockets::socket::accept().
        /// @remarks The xtd::net::sockets::socket::begin_send method starts an asynchronous send operation to the remote host established in the xtd::net::sockets::socket::connect, xtd::net::sockets::socket::begin_connect, xtd::net::sockets::socket::accept, or xtd::net::sockets::socket::begin_accept method. xtd::net::sockets::socket::begin_send will throw an exception if you do not first call xtd::net::sockets::socket::accept, xtd::net::sockets::socket::begin_accept, xtd::net::sockets::socket::connect, or xtd::net::sockets::socket::begin_connect. Calling the xtd::net::sockets::socket::begin_send method gives you the ability to send data within a separate execution thread.
        /// @remarks You can create a callback method that implements the xtd::async_callback delegate and pass its name to the xtd::net::sockets::socket::begin_send method. To do this, at the very minimum, your state parameter must contain the connected or default xtd::net::sockets::socket::socket being used for communication. If your callback needs more information, you can create a small class or structure to hold the xtd::net::sockets::socket::socket and the other required information. Pass an instance of this class to the xtd::net::sockets::socket::begin_send method through the state parameter.
        /// @remarks Your callback method should invoke the xtd::net::sockets::socket::end_send method. When your application calls xtd::net::sockets::socket::begin_send, the system will use a separate thread to execute the specified callback method, and will block on xtd::net::sockets::socket::end_send until the xtd::net::sockets::socket::socket sends the number of bytes requested or throws an exception. If you want the original thread to block after you call the xtd::net::sockets::socket::begin_send method, use the std::mutex::lock method. Call the std::mutex::unlock method on a std::mutex in the callback method when you want the original thread to continue executing.
        /// @remarks Although intended for connection-oriented protocols, xtd::net::sockets::socket::begin_send also works for connectionless protocols, provided that you first call the xtd::net::sockets::socket::connect or xtd::net::sockets::socket::begin_connect method to establish a default remote host. If you are using a connectionless protocol and plan to send data to several different hosts, you should use xtd::net::sockets::socket::begin_send_to. It is okay to use xtd::net::sockets::socket::begin_send_to even after you have established a default remote host with xtd::net::sockets::socket::connect. You can also change the default remote host prior to calling xtd::net::sockets::socket::begin_send by making another call to xtd::net::sockets::socket::connect or xtd::net::sockets::socket::begin_connect. With connectionless protocols, you must also be sure that the size of your buffer does not exceed the maximum packet size of the underlying service provider. If it does, the datagram will not be sent and xtd::net::sockets::socket::begin_send will throw a xtd::net::sockets::socket_exception.
        /// @remarks If you specify the xtd::net::sockets::socket_flags::dont_route flag as the socketflags parameter, the data you are sending will not be routed.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        /// @note All I/O initiated by a given thread is canceled when that thread exits. A pending asynchronous operation can fail if the thread exits before the operation completes.
        /// @note state is an instantiation of a user-defined class.
        /// @note The successful completion of a send does not indicate that the data was successfully delivered. If no buffer space is available within the transport system to hold the data to be transmitted, send will block unless the socket has been placed in nonblocking mode.
        std::shared_ptr<xtd::iasync_result> begin_send(const std::vector<byte_t>& buffer, size_t offset, size_t size, xtd::net::sockets::socket_flags socket_flags, xtd::net::sockets::socket_error& error_code, xtd::async_callback callback, const std::any& state);

        /// @brief Sends data asynchronously to a specific remote host.
        /// @param buffer An array of type byte_t that contains the data to send.
        /// @param offset The zero-based position in buffer at which to begin sending data.
        /// @param size The number of bytes to send.
        /// @param socket_flags A bitwise combination of the xtd::net::sockets::socket_flags values.
        /// @param remote_end_point An xtd::net::end_point that represents the remote device.
        /// @param callback The xtd::async_callback delegate.
        /// @param state An object that contains state information for this request.
        /// @return An xtd::iasync_result that references the asynchronous connection.
        /// @exception xtd::argument_out_of_range_exception size is less than 0 or exceeds the size of the buffer.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @exception xtd::invalid_operation_exception The accepting socket is not listening for connections. You must call xtd::net::sockets::socket::bind and xtd::net::sockets::socket::listen before calling xtd::net::sockets::socket::accept().
        /// @remarks The xtd::net::sockets::socket::begin_send_to method starts an asynchronous send operation to the remote host specified in the remote_end_point parameter. Calling the xtd::net::sockets::socket::begin_send_to method gives you the ability to send data within a separate execution thread. Although intended for connectionless protocols, xtd::net::sockets::socket::begin_send_to works with both connectionless and connection-oriented protocols.
        /// @remarks You can create a callback method that implements the xtd::async_callback delegate and pass its name to the xtd::net::sockets::socket::begin_send_to method. To do this, at the very minimum, your state parameter must contain the connected or default xtd::net::sockets::socket::socket being used for communication. If your callback needs more information, you can create a small class to hold the xtd::net::sockets::socket::socket, and the other required information. Pass an instance of this class to the xtd::net::sockets::socket::begin_send_to method through the state parameter.
        /// @remarks Your callback method should invoke the xtd::net::sockets::socket::end_send_to method. When your application calls xtd::net::sockets::socket::begin_send_to, the system will use a separate thread to execute the specified callback method, and will block on xtd::net::sockets::socket::end_send_to until the xtd::net::sockets::socket::socket sends the number of bytes requested or throws an exception. If you want the original thread to block after you call the xtd::net::sockets::socket::begin_send_to method, use the std::mutex::lock method. Call the std::mutex::unlock method on a T:System.Threading.std::mutex in the callback method when you want the original thread to continue executing. For additional information about writing callback methods see Marshaling a Delegate as a Callback Method.
        /// @remarks If you are using a connection-oriented protocol, you must first call the xtd::net::sockets::socket::connect, xtd::net::sockets::socket::begin_connect, xtd::net::sockets::socket::accept, or xtd::net::sockets::socket::begin_accept method, or xtd::net::sockets::socket::begin_send_to will throw a xtd::net::sockets::socket_exception. xtd::net::sockets::socket::begin_send_to will ignore the remote_end_point parameter and send data to the xtd::net::end_point established in the xtd::net::sockets::socket::connect, xtd::net::sockets::socket::begin_connect, xtd::net::sockets::socket::accept, or xtd::net::sockets::socket::begin_accept method.
        /// @remarks If you are using a connectionless protocol, you do not need to establish a default remote host with the xtd::net::sockets::socket::connect or xtd::net::sockets::socket::begin_connect method prior to calling xtd::net::sockets::socket::send_to. You only need to do this if you intend to call the xtd::net::sockets::socket::begin_send method. If you do call the xtd::net::sockets::socket::connect or xtd::net::sockets::socket::begin_connect method prior to calling xtd::net::sockets::socket::send_to, the remote_end_point parameter will override the specified default remote host for that send operation only. You are also not required to call the xtd::net::sockets::socket::bind method. In this case, the underlying service provider will assign the most appropriate local network address and port number. Use a port number of zero if you want the underlying service provider to select a free port. If you need to identify the assigned local network address and port number, you can use the xtd::net::sockets::socket::local_end_point property after the xtd::net::sockets::socket::end_send_to method successfully completes.
        /// @remarks If you want to send data to a broadcast address, you must first call the xtd::net::sockets::socket::set_socket_option method and set the socket option to xtd::net::sockets::socket::socket_option_name::broadcast. -You must also be sure that the size of your buffer does not exceed the maximum packet size of the underlying service provider. If it does, the datagram will not be sent and xtd::net::sockets::socket::end_send_to will throw a xtd::net::sockets::socket_exception.
        /// @remarks If you specify the xtd::net::sockets::socket_flags::dont_route flag as the socket_flags parameter, the data you are sending will not be routed.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        std::shared_ptr<xtd::iasync_result> begin_send_to(const std::vector<byte_t>& buffer, size_t offset, size_t size, xtd::net::sockets::socket_flags socket_flags, const xtd::net::end_point& remote_end_point, xtd::async_callback callback, const std::any& state);

        /// @brief Associates a xtd::net::sockets::socket with a local endpoint.
        /// @param localEndPoint The local xtd::net::sockets::end_point to associate with the xtd::net::sockets::socket.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks Use the xtd::net::sockets::socket::bind method if you need to use a specific local endpoint. You must call xtd::net::sockets::socket::bind before you can call the xtd::net::sockets::socket::socket::listen method. You do not need to call xtd::net::sockets::socket::bind before using the xtd::net::sockets::socket::connect method unless you need to use a specific local endpoint. You can use the xtd::net::sockets::socket::bind method on both connectionless and connection-oriented protocols.
        /// @remarks Before calling xtd::net::sockets::socket::bind, you must first create the local xtd::net::ip_end_point from which you intend to communicate data. If you do not care which local address is assigned, you can create an xtd::net::ip_end_point using xtd::net::ip_address::any as the address parameter, and the underlying service provider will assign the most appropriate network address. This might help simplify your application if you have multiple network interfaces. If you do not care which local port is used, you can create an xtd::net::ip_end_point using 0 for the port number. In this case, the service provider will assign an available port number between 1024 and 5000.
        /// @remarks If you use the above approach, you can discover what local network address and port number has been assigned by calling the xtd::net::sockets::socket::local_dnd_point. If you are using a connection-oriented protocol, xtd::net::sockets::socket::local_end_point will not return the locally assigned network address until after you have made a call to the xtd::net::sockets::socket::connect or xtd::net::sockets::socket::end_connect method. If you are using a connectionless protocol, you will not have access to this information until you have completed a send or receive.
        /// @remarks If a UDP socket wants to receive interface information on received packets, the xtd::net::sockets::socket::set_socket_option method should be explicitly called with the socket option set to xtd::net::sockets::socket_option_name::packet_information immediately after calling the xtd::net::sockets::socket::bind method.
        /// @note If you intend to receive multicast datagrams, you must call the xtd::net::sockets::socket::bind method with a multicast port number.
        /// @note You must call the xtd::net::sockets::socket::bind method if you intend to receive connectionless datagrams using the xtd::net::sockets::socket::receive_from method.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        template<typename end_point_t>
        void bind(const end_point_t& local_end_point) {
          bind_(std::make_shared<end_point_t>(local_end_point));
        }

        /// @brief Closes the xtd::net::sockets::socket connection and releases all associated resources.
        /// @remarks The xtd::net::sockets::socket::close method closes the remote host connection and releases all resources associated with the xtd::net::sockets::socket. Upon closing, the xtd::net::sockets::socket::connected property is set to false.
        /// @remarks For connection-oriented protocols, it is recommended that you call xtd::net::sockets::socket::shutdown before calling the xtd::net::sockets::socket::close method. This ensures that all data is sent and received on the connected socket before it is closed.
        /// @remarks If you need to call xtd::net::sockets::socket::close without first calling xtd::net::sockets::socket::shutdown, you can ensure that data queued for outgoing transmission will be sent by setting the xtd::net::sockets::socket::dont_linger xtd::net::sockets::socket option to false and specifying a non-zero time-out interval. xtd::net::sockets::socket::close will then block until this data is sent or until the specified time-out expires. If you set xtd::net::sockets::socket::dont_linger to false and specify a zero time-out interval, xtd::net::sockets::socket::close releases the connection and automatically discards outgoing queued data.
        /// @note To set the xtd::net::sockets::socket::dont_linger socket option to false, create a xtd::net::sockets::linger_option, set the xtd::net::sockets::linger_option::enabled property to true, and set the xtd::net::sockets::linger_option::linger_time property to the desired time out period. Use this xtd::net::sockets::linger_option along with the xtd::net::sockets::socket::dont_linger socket option to call the xtd::net::sockets::socket::set_socket_linger_option method.
        void close();

        /// @brief Establishes a connection to a remote host.
        /// @param remote_end_point An xtd::net::end_point that represents the remote device.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks If you are using a connection-oriented protocol such as TCP, the xtd::net::sockets::socket::connect method synchronously establishes a network connection between xtd::net::sockets::socket::local_end_point and the specified remote endpoint. If you are using a connectionless protocol, xtd::net::sockets::socket::connect establishes a default remote host. After you call xtd::net::sockets::socket::connect, you can send data to the remote device with the xtd::net::sockets::socket::send method, or receive data from the remote device with the xtd::net::sockets::socket::receive method.
        /// @remarks If you are using a connectionless protocol such as UDP, you do not have to call xtd::net::sockets::socket::connect before sending and receiving data. You can use xtd::net::sockets::socket::send_to and xtd::net::sockets::socket::receive_from to synchronously communicate with a remote host. If you do call xtd::net::sockets::socket::connect, any datagrams that arrive from an address other than the specified default will be discarded. If you want to set your default remote host to a broadcast address, you must first call the xtd::net::sockets::socket::set_socket_option method and set the socket option to xtd::net::sockets::socket::socket_option_name::broadcast, or xtd::net::sockets::socket::connect will throw a xtd::net::sockets::socket_exception. If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        /// @remarks The xtd::net::sockets::socket::connect method will block, unless you specifically set the xtd::net::sockets::socket::blocking property to false prior to calling xtd::net::sockets::socket::connect. If you are using a connection-oriented protocol like TCP and you do disable blocking, xtd::net::sockets::socket::connect will throw a xtd::net::sockets::socket_exception because it needs time to make the connection. Connectionless protocols will not throw an exception because they simply establish a default remote host. You can use xtd::net::sockets::socket_exception::error_code to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error. If the error returned WSAEWOULDBLOCK, the remote host connection has been initiated by a connection-oriented xtd::net::sockets::socket, but has not yet completed successfully. Use the Poll method to determine when the xtd::net::sockets::socket is finished connecting.
        /// @note If you are using a connection-oriented protocol and did not call xtd::net::sockets::socket::bind before calling xtd::net::sockets::socket::connect, the underlying service provider will assign the local network address and port number. If you are using a connectionless protocol, the service provider will not assign a local network address and port number until you complete a send or receive operation. If you want to change the default remote host, call xtd::net::sockets::socket::connect again with the desired endpoint.
        /// @note If the socket has been previously disconnected, then you cannot use this method to restore the connection. Use one of the asynchronous xtd::net::sockets::socket::begin_connect methods to reconnect. This is a limitation of the underlying provider.
        template<typename end_point_t>
        void connect(const end_point_t& remote_end_point) {
         connect_(std::make_shared<end_point_t>(remote_end_point));
        }
        
        /// @brief Establishes a connection to a remote host. The host is specified by an IP address and a port number.
        /// @param address The IP address of the remote host.
        /// @param port The port number of the remote host.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks If you are using a connection-oriented protocol such as TCP, the xtd::net::sockets::socket::connect method synchronously establishes a network connection between xtd::net::sockets::socket::local_end_point and the specified remote endpoint. If you are using a connectionless protocol, xtd::net::sockets::socket::connect establishes a default remote host. After you call xtd::net::sockets::socket::connect, you can send data to the remote device with the xtd::net::sockets::socket::send method, or receive data from the remote device with the xtd::net::sockets::socket::receive method.
        /// @remarks If you are using a connectionless protocol such as UDP, you do not have to call xtd::net::sockets::socket::connect before sending and receiving data. You can use xtd::net::sockets::socket::send_to and xtd::net::sockets::socket::receive_from to synchronously communicate with a remote host. If you do call xtd::net::sockets::socket::connect, any datagrams that arrive from an address other than the specified default will be discarded. If you want to set your default remote host to a broadcast address, you must first call the xtd::net::sockets::socket::set_socket_option method and set the socket option to xtd::net::sockets::socket::socket_option_name::broadcast, or xtd::net::sockets::socket::connect will throw a xtd::net::sockets::socket_exception. If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        /// @remarks The xtd::net::sockets::socket::connect method will block, unless you specifically set the xtd::net::sockets::socket::blocking property to false prior to calling xtd::net::sockets::socket::connect. If you are using a connection-oriented protocol like TCP and you do disable blocking, xtd::net::sockets::socket::connect will throw a xtd::net::sockets::socket_exception because it needs time to make the connection. Connectionless protocols will not throw an exception because they simply establish a default remote host. You can use xtd::net::sockets::socket_exception::error_code to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error. If the error returned WSAEWOULDBLOCK, the remote host connection has been initiated by a connection-oriented xtd::net::sockets::socket, but has not yet completed successfully. Use the Poll method to determine when the xtd::net::sockets::socket is finished connecting.
        /// @note If you are using a connection-oriented protocol and did not call xtd::net::sockets::socket::bind before calling xtd::net::sockets::socket::connect, the underlying service provider will assign the local network address and port number. If you are using a connectionless protocol, the service provider will not assign a local network address and port number until you complete a send or receive operation. If you want to change the default remote host, call xtd::net::sockets::socket::connect again with the desired endpoint.
        /// @note If the socket has been previously disconnected, then you cannot use this method to restore the connection. Use one of the asynchronous xtd::net::sockets::socket::begin_connect methods to reconnect. This is a limitation of the underlying provider.
        void connect(const xtd::net::ip_address& address, uint16_t port);
        
        /// @brief Establishes a connection to a remote host. The host is specified by an array of IP addresses and a port number.
        /// @param addresses The IP addresses of the remote host.
        /// @param port The port number of the remote host.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks This method is typically used immediately after a call to xtd::net::dns::get_host_addresses, which can return multiple IP addresses for a single host. If you are using a connection-oriented protocol such as TCP, the xtd::net::sockets::socket::connect method synchronously establishes a network connection between xtd::net::sockets::socket::local_end_point and the specified remote endpoint. If you are using a connectionless protocol, xtd::net::sockets::socket::connect establishes a default remote host. After you call xtd::net::sockets::socket::connect you can send data to the remote device with the xtd::net::sockets::socket::send method, or receive data from the remote device with the xtd::net::sockets::socket::receive method.
        /// @remarks If you are using a connection-oriented protocol such as TCP, the xtd::net::sockets::socket::connect method synchronously establishes a network connection between xtd::net::sockets::socket::local_end_point and the specified remote endpoint. If you are using a connectionless protocol, xtd::net::sockets::socket::connect establishes a default remote host. After you call xtd::net::sockets::socket::connect, you can send data to the remote device with the xtd::net::sockets::socket::send method, or receive data from the remote device with the xtd::net::sockets::socket::receive method.
        /// @remarks If you are using a connectionless protocol such as UDP, you do not have to call xtd::net::sockets::socket::connect before sending and receiving data. You can use xtd::net::sockets::socket::send_to and xtd::net::sockets::socket::receive_from to synchronously communicate with a remote host. If you do call xtd::net::sockets::socket::connect, any datagrams that arrive from an address other than the specified default will be discarded. If you want to set your default remote host to a broadcast address, you must first call the xtd::net::sockets::socket::set_socket_option method and set the socket option to xtd::net::sockets::socket::socket_option_name::broadcast, or xtd::net::sockets::socket::connect will throw a xtd::net::sockets::socket_exception. If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        /// @remarks The xtd::net::sockets::socket::connect method will block, unless you specifically set the xtd::net::sockets::socket::blocking property to false prior to calling xtd::net::sockets::socket::connect. If you are using a connection-oriented protocol like TCP and you do disable blocking, xtd::net::sockets::socket::connect will throw a xtd::net::sockets::socket_exception because it needs time to make the connection. Connectionless protocols will not throw an exception because they simply establish a default remote host. You can use xtd::net::sockets::socket_exception::error_code to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error. If the error returned WSAEWOULDBLOCK, the remote host connection has been initiated by a connection-oriented xtd::net::sockets::socket, but has not yet completed successfully. Use the Poll method to determine when the xtd::net::sockets::socket is finished connecting.
        /// @note If you are using a connection-oriented protocol and did not call xtd::net::sockets::socket::bind before calling xtd::net::sockets::socket::connect, the underlying service provider will assign the local network address and port number. If you are using a connectionless protocol, the service provider will not assign a local network address and port number until you complete a send or receive operation. If you want to change the default remote host, call xtd::net::sockets::socket::connect again with the desired endpoint.
        /// @note If the socket has been previously disconnected, then you cannot use this method to restore the connection. Use one of the asynchronous xtd::net::sockets::socket::begin_connect methods to reconnect. This is a limitation of the underlying provider.
        void connect(const std::vector<xtd::net::ip_address>& addresses, uint16_t port);
        
        /// @brief Establishes a connection to a remote host. The host is specified by a host name and a port number.
        /// @param host The name of the remote host.
        /// @param port The port number of the remote host.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks If you are using a connection-oriented protocol such as TCP, the xtd::net::sockets::socket::connect method synchronously establishes a network connection between xtd::net::sockets::socket::local_end_point and the specified remote endpoint. If you are using a connectionless protocol, xtd::net::sockets::socket::connect establishes a default remote host. After you call xtd::net::sockets::socket::connect, you can send data to the remote device with the xtd::net::sockets::socket::send method, or receive data from the remote device with the xtd::net::sockets::socket::receive method.
        /// @remarks If you are using a connectionless protocol such as UDP, you do not have to call xtd::net::sockets::socket::connect before sending and receiving data. You can use xtd::net::sockets::socket::send_to and xtd::net::sockets::socket::receive_from to synchronously communicate with a remote host. If you do call xtd::net::sockets::socket::connect, any datagrams that arrive from an address other than the specified default will be discarded. If you want to set your default remote host to a broadcast address, you must first call the xtd::net::sockets::socket::set_socket_option method and set the socket option to xtd::net::sockets::socket::socket_option_name::broadcast, or xtd::net::sockets::socket::connect will throw a xtd::net::sockets::socket_exception. If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        /// @remarks The xtd::net::sockets::socket::connect method will block, unless you specifically set the xtd::net::sockets::socket::blocking property to false prior to calling xtd::net::sockets::socket::connect. If you are using a connection-oriented protocol like TCP and you do disable blocking, xtd::net::sockets::socket::connect will throw a xtd::net::sockets::socket_exception because it needs time to make the connection. Connectionless protocols will not throw an exception because they simply establish a default remote host. You can use xtd::net::sockets::socket_exception::error_code to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error. If the error returned WSAEWOULDBLOCK, the remote host connection has been initiated by a connection-oriented xtd::net::sockets::socket, but has not yet completed successfully. Use the Poll method to determine when the xtd::net::sockets::socket is finished connecting.
        /// @note If you are using a connection-oriented protocol and did not call xtd::net::sockets::socket::bind before calling xtd::net::sockets::socket::connect, the underlying service provider will assign the local network address and port number. If you are using a connectionless protocol, the service provider will not assign a local network address and port number until you complete a send or receive operation. If you want to change the default remote host, call xtd::net::sockets::socket::connect again with the desired endpoint.
        /// @note If the socket has been previously disconnected, then you cannot use this method to restore the connection. Use one of the asynchronous xtd::net::sockets::socket::begin_connect methods to reconnect. This is a limitation of the underlying provider.
        void connect(const xtd::ustring& host, uint16_t port);
        
        /// @brief Closes the socket connection and allows reuse of the socket.
        /// @param reuse_socket true if this socket can be reused after the current connection is closed; otherwise, false.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks If you are using a connection-oriented protocol, you can use this method to close the socket. This method ends the connection and sets the xtd::net::sockets::socket::connected property to false. However, if reuseSocket is true, you can reuse the socket.
        /// @remarks To ensure that all data is sent and received before the socket is closed, you should call xtd::net::sockets::socket::shutdown before calling the xtd::net::sockets::socket::disconnect method.
        /// @remarks If you need to call xtd::net::sockets::socket::disconnect without first calling xtd::net::sockets::socket::shutdown, you can set the xtd::net::sockets::socket::dont_linger_socket option to false and specify a nonzero time-out interval to ensure that data queued for outgoing transmission is sent. xtd::net::sockets::socket::disconnect then blocks until the data is sent or until the specified time-out expires. If you set xtd::net::sockets::socket::dont_linger to false and specify a zero time-out interval, xtd::net::sockets::socket::close releases the connection and automatically discards outgoing queued data.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        void disconnect(bool reuse_socket);
        
        /// @brief Asynchronously accepts an incoming connection attempt and creates a new xtd::net::sockets::socket::socket to handle remote host communication.
        /// @param async_result An xtd::iasync_result that stores state information for this asynchronous operation as well as any user defined data.
        /// @return A xtd::net::sockets::socket::socket to handle communication with the remote host.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks xtd::net::sockets::socket::end_accept completes a call to xtd::net::sockets::socket::begin_accept. Before calling xtd::net::sockets::socket::begin_accept, you need to create a callback method that implements the xtd::async_callback delegate. This callback method executes in a separate thread, and is called by the system after the xtd::net::sockets::socket::begin_accept method returns. It must accept the asyncResult parameter returned from the xtd::net::sockets::socket::begin_accept method.
        /// @remarks Within the callback method, call the xtd::iasync_result::async_state method of the asyncResult parameter to obtain the xtd::net::sockets::socket::socket on which the connection attempt is being made. After obtaining the xtd::net::sockets::socket::socket, you can call the xtd::net::sockets::socket::end_accept method to successfully complete the connection attempt.
        /// @remarks The xtd::net::sockets::socket::end_accept method blocks until a connection is pending in the incoming connection queue. The xtd::net::sockets::socket::end_accept method accepts the incoming connection and returns a new xtd::net::sockets::socket::socket that can be used to send data to and receive data from the remote host.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        socket end_accept(std::shared_ptr<xtd::iasync_result> async_result);
        
        /// @brief Ends a pending asynchronous connection request.
        /// @param async_result An xtd::iasync_result that stores state information for this asynchronous operation as well as any user defined data.
        /// @exception argument_exception asyncResult was not returned by a call to the xtd::net::sockets::socket::begin_connect method.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks xtd::net::sockets::socket::end_connect is a blocking method that completes the asynchronous remote host connection request started in the xtd::net::sockets::socket::begin_connect method.
        /// @remarks Before calling xtd::net::sockets::socket::begin_connect, you need to create a callback method that implements the xtd::async_callback delegate. This callback method executes in a separate thread and is called by the system after xtd::net::sockets::socket::begin_connect returns. The callback method must accept the xtd::iasync_result returned by the xtd::net::sockets::socket::begin_connect method as a parameter.
        /// @remarks Within the callback method, call the xtd::iasync_result::async_state method of the xtd::iasync_result parameter to obtain the xtd::net::sockets::socket::socket on which the connection attempt is being made. After obtaining the xtd::net::sockets::socket::socket, you can call the xtd::net::sockets::socket::end_connect method to successfully complete the connection attempt.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        void end_connect(std::shared_ptr<xtd::iasync_result> async_result);
        
        /// @brief Ends a pending asynchronous disconnect request.
        /// @param async_result An xtd::iasync_result that stores state information for this asynchronous operation as well as any user defined data.
        /// @exception argument_exception asyncResult was not returned by a call to the xtd::net::sockets::socket::begin_disconnect method.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks xtd::net::sockets::socket::end_disconnect completes a call to xtd::net::sockets::socket::begin_disconnect. The xtd::net::sockets::socket::end_disconnect method blocks until the disconnect completes. For information about asynchronous operations, see Asynchronous Programming Model (APM).
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        void end_disconnect(std::shared_ptr<xtd::iasync_result> async_result);
       
        /// @brief Ends a pending asynchronous read.
        /// @param async_result An xtd::iasync_result that stores state information for this asynchronous operation as well as any user defined data.
        /// @return The number of bytes received.
        /// @exception argument_exception asyncResult was not returned by a call to the xtd::net::sockets::socket::begin_receive method.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks The xtd::net::sockets::socket::end_receive method completes the asynchronous read operation started in the xtd::net::sockets::socket::begin_receive method.
        /// @remarks Before calling xtd::net::sockets::socket::begin_receive, you need to create a callback method that implements the xtd::async_callback delegate. This callback method executes in a separate thread and is called by the system after xtd::net::sockets::socket::begin_receive returns. The callback method must accept the xtd::iasync_result returned by the xtd::net::sockets::socket::begin_receive method as a parameter.
        /// @remarks Within the callback method, call the xtd::iasync_result::async_state method of the xtd::iasync_result to obtain the state object passed to the xtd::net::sockets::socket::begin_receive method. Extract the receiving xtd::net::sockets::socket::socket from this state object. After obtaining the xtd::net::sockets::socket::socket, you can call the xtd::net::sockets::socket::end_receive method to successfully complete the read operation and return the number of bytes read.
        /// @remarks The xtd::net::sockets::socket::end_receive method will block until data is available. If you are using a connectionless protocol, xtd::net::sockets::socket::end_receive will read the first enqueued datagram available in the incoming network buffer. If you are using a connection-oriented protocol, the xtd::net::sockets::socket::end_receive method will read as much data as is available up to the number of bytes you specified in the size parameter of the xtd::net::sockets::socket::begin_receive method. If the remote host shuts down the xtd::net::sockets::socket::socket connection with the Shutdown method, and all available data has been received, the xtd::net::sockets::socket::end_receive method will complete immediately and return zero bytes.
        /// @remarks To obtain the received data, call the xtd::iasync_result::async_state method of the xtd::iasync_result, and extract the buffer contained in the resulting state object.
        /// @remarks To cancel a pending xtd::net::sockets::socket::begin_receive, call the xtd::net::sockets::socket::socket::close method.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        /// @note All I/O initiated by a given thread is canceled when that thread exits. A pending asynchronous operation can fail if the thread exits before the operation completes.
        size_t end_receive(std::shared_ptr<xtd::iasync_result> async_result);
        /// @brief Ends a pending asynchronous read.
        /// @param async_result An xtd::iasync_result that stores state information for this asynchronous operation as well as any user defined data.
        /// @param error_code A xtd::net::sockets::socket_error object that stores the socket error.
        /// @return The number of bytes received.
        /// @exception argument_exception asyncResult was not returned by a call to the xtd::net::sockets::socket::begin_receive method.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks The xtd::net::sockets::socket::end_receive method completes the asynchronous read operation started in the xtd::net::sockets::socket::begin_receive method.
        /// @remarks Before calling xtd::net::sockets::socket::begin_receive, you need to create a callback method that implements the xtd::async_callback delegate. This callback method executes in a separate thread and is called by the system after xtd::net::sockets::socket::begin_receive returns. The callback method must accept the xtd::iasync_result returned by the xtd::net::sockets::socket::begin_receive method as a parameter.
        /// @remarks Within the callback method, call the xtd::iasync_result::async_state method of the xtd::iasync_result to obtain the state object passed to the xtd::net::sockets::socket::begin_receive method. Extract the receiving xtd::net::sockets::socket::socket from this state object. After obtaining the xtd::net::sockets::socket::socket, you can call the xtd::net::sockets::socket::end_receive method to successfully complete the read operation and return the number of bytes read.
        /// @remarks The xtd::net::sockets::socket::end_receive method will block until data is available. If you are using a connectionless protocol, xtd::net::sockets::socket::end_receive will read the first enqueued datagram available in the incoming network buffer. If you are using a connection-oriented protocol, the xtd::net::sockets::socket::end_receive method will read as much data as is available up to the number of bytes you specified in the size parameter of the xtd::net::sockets::socket::begin_receive method. If the remote host shuts down the xtd::net::sockets::socket::socket connection with the Shutdown method, and all available data has been received, the xtd::net::sockets::socket::end_receive method will complete immediately and return zero bytes.
        /// @remarks To obtain the received data, call the xtd::iasync_result::async_state method of the xtd::iasync_result, and extract the buffer contained in the resulting state object.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        /// @note All I/O initiated by a given thread is canceled when that thread exits. A pending asynchronous operation can fail if the thread exits before the operation completes.
        size_t end_receive(std::shared_ptr<xtd::iasync_result> async_result, xtd::net::sockets::socket_error& error_code);

        /// @brief Ends a pending asynchronous read from a specific endpoint.
        /// @param async_result An xtd::iasync_result that stores state information for this asynchronous operation as well as any user defined data.
        /// @param end_point The source xtd::net::end_point.
        /// @exception argument_exception asyncResult was not returned by a call to the xtd::net::sockets::socket::begin_receive_from method.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks The xtd::net::sockets::socket::end_receive_from method completes the asynchronous read operation started in the xtd::net::sockets::socket::begin_receive_from method.
        /// @remarks Before calling xtd::net::sockets::socket::begin_receive_from, you need to create a callback method that implements the xtd::async_callback delegate. This callback method executes in a separate thread and is called by the system after xtd::net::sockets::socket::begin_receive_from returns. The callback method must accept the xtd::iasync_result returned by the xtd::net::sockets::socket::begin_receive_from method as a parameter.
        /// @remarks Within the callback method, call the xtd::iasync_result::async_state method of the xtd::iasync_result to obtain the state object passed to the xtd::net::sockets::socket::begin_receive_from method. Extract the receiving xtd::net::sockets::socket::socket from this state object. After obtaining the xtd::net::sockets::socket::socket, you can call the xtd::net::sockets::socket::end_receive_from method to successfully complete the read operation and return the number of bytes read.
        /// @remarks The xtd::net::sockets::socket::end_receive_from method will block until data is available. If you are using a connectionless protocol, xtd::net::sockets::socket::end_receive_from will read the first enqueued datagram available in the incoming network buffer. If you are using a connection-oriented protocol, the xtd::net::sockets::socket::end_receive_from method will read as much data as is available up to the number of bytes you specified in the size parameter of the xtd::net::sockets::socket::begin_receive_from method. If the remote host shuts down the xtd::net::sockets::socket::socket connection with the Shutdown method, and all available data has been received, the xtd::net::sockets::socket::end_receive_from method will complete immediately and return zero bytes. To obtain the received data, call the xtd::iasync_result::async_state method of the xtd::iasync_result object, and extract the buffer contained in the resulting state object. To identify the originating host, extract the xtd::net::end_point and cast it to an IPEndPoint. Use the IPEndPoint.Address method to obtain the IP address and the IPEndPoint.Port method to obtain the port number.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        size_t end_receive_from(std::shared_ptr<xtd::iasync_result> async_result, std::shared_ptr<xtd::net::end_point>& end_point);
        
        /// @brief Ends a pending asynchronous read from a specific endpoint. This method also reveals more information about the packet than xtd::net::sockets::socket::end_receive_from(xtd::iasync_result, xtd::net::end_point).
        /// @param async_result An xtd::iasync_result that stores state information for this asynchronous operation as well as any user defined data.
        /// @param socket_flags A bitwise combination of the xtd::net::sockets::socket_flags values for the received packet.
        /// @param end_point The source xtd::net::end_point.
        /// @param ip_packet_information The xtd::net::ip_address and interface of the received packet.
        /// @return If successful, the number of bytes received. If unsuccessful, returns 0.
        /// @exception argument_exception asyncResult was not returned by a call to the xtd::net::sockets::socket::begin_receive_message_from method.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks If the operation has not completed, this method blocks until it does.
        /// @remarks To perform this operation synchronously, use the xtd::net::sockets::socket::receive_message_from method.
        /// @remarks Examine ipPacketInformation if you need to know if the datagram was sent using a unicast, multicast, or broadcast address.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        size_t end_receive_message_from(std::shared_ptr<xtd::iasync_result> async_result, xtd::net::sockets::socket_flags& socket_flags, std::shared_ptr<xtd::net::end_point>& end_point, xtd::net::sockets::ip_packet_information& ip_packet_information);
        
        /// @brief Ends a pending asynchronous send.
        /// @param async_result An xtd::iasync_result that stores state information for this asynchronous operation as well as any user defined data.
        /// @return If successful, the number of bytes sent to the xtd::net::sockets::socket::socket; otherwise, an invalid xtd::net::sockets::socket::socket error.
        /// @exception argument_exception asyncResult was not returned by a call to the xtd::net::sockets::socket::begin_send method.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks xtd::net::sockets::socket::end_send completes the asynchronous send operation started in xtd::net::sockets::socket::begin_send.
        /// @remarks Before calling xtd::net::sockets::socket::begin_send, you need to create a callback method that implements the xtd::async_callback delegate. This callback method executes in a separate thread and is called by the system after xtd::net::sockets::socket::begin_send returns. The callback method must accept the xtd::iasync_result returned by the xtd::net::sockets::socket::begin_send method as a parameter.
        /// @remarks Within the callback method, call the xtd::iasync_result::async_state method of the xtd::iasync_result parameter to obtain the sending xtd::net::sockets::socket::socket. After obtaining the xtd::net::sockets::socket::socket, you can call the xtd::net::sockets::socket::end_send method to successfully complete the send operation and return the number of bytes sent.
        /// @remarks If you are using a connectionless protocol, xtd::net::sockets::socket::end_send will block until the datagram is sent. If you are using a connection-oriented protocol, xtd::net::sockets::socket::end_send will block until some of the buffer was sent. If the return value from xtd::net::sockets::socket::end_send indicates that the buffer was not completely sent, call the xtd::net::sockets::socket::begin_send method again, modifying the buffer to hold the unsent data.
        /// @remarks There is no guarantee that the data you send will appear on the network immediately. To increase network efficiency, the underlying system may delay transmission until a significant amount of outgoing data is collected. A successful completion of the xtd::net::sockets::socket::begin_send method means that the underlying system has had room to buffer your data for a network send.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        /// @note All I/O initiated by a given thread is canceled when that thread exits. A pending asynchronous operation can fail if the thread exits before the operation completes.
        /// @note The successful completion of a send does not indicate that the data was successfully delivered. If no buffer space is available within the transport system to hold the data to be transmitted, send will block unless the socket has been placed in nonblocking mode.
        size_t end_send(std::shared_ptr<xtd::iasync_result> async_result);
        /// @brief Ends a pending asynchronous send.
        /// @param async_result An xtd::iasync_result that stores state information for this asynchronous operation as well as any user defined data.
        /// @param error_code A xtd::net::sockets::socket_error object that stores the socket error.
        /// @return If successful, the number of bytes sent to the xtd::net::sockets::socket::socket; otherwise, an invalid xtd::net::sockets::socket::socket error.
        /// @exception argument_exception asyncResult was not returned by a call to the xtd::net::sockets::socket::begin_send method.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks xtd::net::sockets::socket::end_send completes the asynchronous send operation started in xtd::net::sockets::socket::begin_send.
        /// @remarks Before calling xtd::net::sockets::socket::begin_send, you need to create a callback method that implements the xtd::async_callback delegate. This callback method executes in a separate thread and is called by the system after xtd::net::sockets::socket::begin_send returns. The callback method must accept the xtd::iasync_result returned by the xtd::net::sockets::socket::begin_send method as a parameter.
        /// @remarks Within the callback method, call the xtd::iasync_result::async_state method of the xtd::iasync_result parameter to obtain the sending xtd::net::sockets::socket::socket. After obtaining the xtd::net::sockets::socket::socket, you can call the xtd::net::sockets::socket::end_send method to successfully complete the send operation and return the number of bytes sent.
        /// @remarks If you are using a connectionless protocol, xtd::net::sockets::socket::end_send will block until the datagram is sent. If you are using a connection-oriented protocol, xtd::net::sockets::socket::end_send will block until some of the buffer was sent. If the return value from xtd::net::sockets::socket::end_send indicates that the buffer was not completely sent, call the xtd::net::sockets::socket::begin_send method again, modifying the buffer to hold the unsent data.
        /// @remarks There is no guarantee that the data you send will appear on the network immediately. To increase network efficiency, the underlying system may delay transmission until a significant amount of outgoing data is collected. A successful completion of the xtd::net::sockets::socket::begin_send method means that the underlying system has had room to buffer your data for a network send.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        /// @note All I/O initiated by a given thread is canceled when that thread exits. A pending asynchronous operation can fail if the thread exits before the operation completes.
        /// @note The successful completion of a send does not indicate that the data was successfully delivered. If no buffer space is available within the transport system to hold the data to be transmitted, send will block unless the socket has been placed in nonblocking mode.
        size_t end_send(std::shared_ptr<xtd::iasync_result> async_result, xtd::net::sockets::socket_error& error_code);

        /// @brief Ends a pending asynchronous send to a specific location.
        /// @param async_result An xtd::iasync_result that stores state information for this asynchronous operation as well as any user defined data.
        /// @return If successful, the number of bytes sent; otherwise, an invalid xtd::net::sockets::socket::socket error.
        /// @exception argument_exception asyncResult was not returned by a call to the xtd::net::sockets::socket::begin_send_to method.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks xtd::net::sockets::socket::end_send_to completes the asynchronous send operation started in xtd::net::sockets::socket::begin_send_to.
        /// @remarks Before calling xtd::net::sockets::socket::begin_send_to, you need to create a callback method that implements the xtd::async_callback delegate. This callback method executes in a separate thread and is called by the system after xtd::net::sockets::socket::begin_receive returns. The callback method must accept the xtd::iasync_result returned by the xtd::net::sockets::socket::begin_send_to method as a parameter.
        /// @remarks Within the callback method, call the xtd::iasync_result::async_state method of the xtd::iasync_result parameter to obtain the sending xtd::net::sockets::socket::socket. After obtaining the xtd::net::sockets::socket::socket, you can call the xtd::net::sockets::socket::end_send_to method to successfully complete the send operation and return the number of bytes sent.
        /// @remarks If you are using a connectionless protocol, xtd::net::sockets::socket::end_send_to will block until the datagram is sent. If you are using a connection-oriented protocol, xtd::net::sockets::socket::end_send_to will block until the requested number of bytes are sent. There is no guarantee that the data you send will appear on the network immediately. To increase network efficiency, the underlying system may delay transmission until a significant amount of outgoing data is collected. A successful completion of the xtd::net::sockets::socket::begin_send_to method means that the underlying system has had room to buffer your data for a network send.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        size_t end_send_to(std::shared_ptr<xtd::iasync_result> async_result);

        /// @brief Gets a socket option value using platform-specific level and name identifiers.
        /// @param socket_option_level The platform-defined option level.
        /// @param socket_option_name The platform-defined option name.
        /// @param option_value The pointer into which the retrieved option value should be stored.
        /// @return The number of bytes written into option_value for a successfully retrieved value.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        size_t get_raw_socket_option(int32_t socket_option_level, int32_t socket_option_name, intptr_t option_value, size_t size_option_value) const;

        /// @brief Returns the value of a specified xtd::net::sockets::socket option, represented as integer.
        /// @param socket_option_level One of the xtd::net::sockets::socket_option_level values.
        /// @param socket_option_name One of the xtd::net::sockets::socket_option_name values.
        /// @return An object that represents the value of the option.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks xtd::net::sockets::socket options determine the behavior of the current xtd::net::sockets::socket.
        /// @remarks Use xtd::net::sockets::socket::get_socket_linger_option to get the xtd::net::sockets::socket_option_name::linger.
        /// @remarks Use xtd::net::sockets::socket::get_socket_multicast_option xtd::net::sockets::socket_option_name::add_membership, and xtd::net::sockets::socket_option_name::xtd::net::sockets::socket_option_name::drop_membership xtd::net::sockets::socket options for IP v4 socket.
        /// @remarks Use xtd::net::sockets::socket::get_socket_ip_v6__multicast_option xtd::net::sockets::socket_option_name::add_membership, and xtd::net::sockets::socket_option_name::xtd::net::sockets::socket_option_name::drop_membership xtd::net::sockets::socket options for IP v6 socket.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        int32_t get_socket_option(xtd::net::sockets::socket_option_level socket_option_level, xtd::net::sockets::socket_option_name socket_option_name) const;
        /// @brief Returns the linger xtd::net::sockets::socket option, represented as xtd::net::sockets::linger_option.
        /// @return An xtd::net::sockets::linger_option that represents the value of the linger option.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks xtd::net::sockets::socket options determine the behavior of the current xtd::net::sockets::socket. Use this overload to get the xtd::net::sockets::socket_option_name::linger, xtd::net::sockets::socket_option_name::add_membership, and xtd::net::sockets::socket_option_name::xtd::net::sockets::socket_option_name::drop_membership xtd::net::sockets::socket options. For the xtd::net::sockets::socket_option_name::linger option, use xtd::net::sockets::socket_option_level::socket for the option_level parameter. For xtd::net::sockets::socket_option_name::add_membership and xtd::net::sockets::socket_option_name::drop_membership, use xtd::net::sockets::socket_option_level::ip. If you want to set the value of any of the options listed above, use the xtd::net::sockets::socket_option_name::xtd::net::sockets::socket::set_socket_option method.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        xtd::net::sockets::linger_option get_socket_linger_option() const;
        /// @brief Returns the multicast xtd::net::sockets::socket option, represented as xtd::net::sockets::multicast_option.
        /// @param socket_option_name One of the xtd::net::sockets::socket_option_name values. Only xtd::net::sockets::socket_option_name::add_membership and xtd::net::sockets::socket_option_name::drop_membership values are accepted.
        /// @return An xtd::net::sockets::linger_option that represents the value of the multicast option.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        xtd::net::sockets::multicast_option get_socket_multicast_option(xtd::net::sockets::socket_option_name socket_option_name) const;
        /// @brief Returns the multicast xtd::net::sockets::socket option, represented as xtd::net::sockets::ip_v6_multicast_option.
        /// @param socket_option_name One of the xtd::net::sockets::socket_option_name values. Only xtd::net::sockets::socket_option_name::add_membership and xtd::net::sockets::socket_option_name::drop_membership values are accepted.
        /// @return An xtd::net::sockets::linger_option that represents the value of the multicast option.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        xtd::net::sockets::ip_v6_multicast_option get_socket_ip_v6_multicast_option(xtd::net::sockets::socket_option_name socket_option_name) const;

        /// @brief Sets low-level operating modes for the xtd::net::sockets::socket using numerical control codes.
        /// @param io_control_code An int32_t value that specifies the control code of the operation to perform.
        /// @param option_in_value A byte array that contains the input data required by the operation.
        /// @param option_out_value A byte array that contains the output data returned by the operation.
        /// @return The number of bytes in the option_out_value parameter.
        /// @remarks The xtd::net::sockets::socket::io_control method provides low-level access to the operating system xtd::net::sockets::socket underlying the current instance of the xtd::net::sockets::socket class.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        size_t io_control(int32_t io_control_code, std::vector<uint8_t>& option_in_value, std::vector<uint8_t>& option_out_value);
        /// @brief Sets low-level operating modes for the xtd::net::sockets::socket using xtd::net::sockets::io_control_code control codes.
        /// @param io_control_code A xtd::net::sockets::io_control_code value that specifies the control code of the operation to perform.
        /// @param option_in_value A byte array that contains the input data required by the operation.
        /// @param option_out_value A byte array that contains the output data returned by the operation.
        /// @return The number of bytes in the option_out_value parameter.
        /// @remarks The xtd::net::sockets::socket::io_control method provides low-level access to the operating system xtd::net::sockets::socket underlying the current instance of the xtd::net::sockets::socket class.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        size_t io_control(xtd::net::sockets::io_control_code io_control_code, std::vector<uint8_t>& option_in_value, std::vector<uint8_t>& option_out_value);
        
        /// @brief Places a xtd::net::sockets::socket in a listening state.
        /// @param backlog The maximum length of the pending connections queue.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks xtd::net::sockets::socket::listen causes a connection-oriented xtd::net::sockets::socket to listen for incoming connection attempts. The backlog parameter specifies the number of incoming connections that can be queued for acceptance. To determine the maximum number of connections you can specify, retrieve the xtd::net::sockets::socket_option_name::max_connections value. xtd::net::sockets::socket::listen does not block.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        /// @note You must call the xtd::net::sockets::socket::bind method before calling xtd::net::sockets::socket::listen, or xtd::net::sockets::socket::listen will throw a xtd::net::sockets::socket_exception.
        /// @note The backlog parameter is limited to different values depending on the Operating System. You may specify a higher value, but the backlog will be limited based on the Operating System.
        void listen(size_t backlog);
        
        /// @brief Places a xtd::net::sockets::socket in a listening state.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks The maximum length of the pending connections queue is determined automatically.
        /// @remarks xtd::net::sockets::socket::listen causes a connection-oriented xtd::net::sockets::socket to listen for incoming connection attempts. The backlog parameter specifies the number of incoming connections that can be queued for acceptance. To determine the maximum number of connections you can specify, retrieve the xtd::net::sockets::socket_option_name::max_connections value. xtd::net::sockets::socket::listen does not block.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        /// @note You must call the xtd::net::sockets::socket::bind method before calling xtd::net::sockets::socket::listen, or xtd::net::sockets::socket::listen will throw axed::net::sockets::socket_exception.
        /// @note The backlog parameter is limited to different values depending on the Operating System. You may specify a higher value, but the backlog will be limited based on the Operating System.
        void listen();
        
        /// @brief Determines the status of the xtd::net::sockets::socket.
        /// @param micro_seconds The time to wait for a response, in microseconds.
        /// @param mode One of the xtd::net::sockets::select_mode values.
        /// @return The status of the xtd::net::sockets::socket based on the polling mode value passed in the mode parameter.
        /// | Mode                                         | Return Value                                                                                                                                                                                                                                               |
        /// |----------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
        /// | xtd::net::sockets::select_mode::select_read  | true if xtd::net::sockets::socket::listen has been called and a connection is pending; -or- true if data is available for reading; -or- true if the connection has been closed, reset, or terminated; otherwise, returns false.                            |
        /// | xtd::net::sockets::select_mode::select_write | true, if processing a xtd::net::sockets::socket::connect, and the connection has succeeded; -or- true if data can be sent; otherwise, returns false.                                                                                                       |
        /// | xtd::net::sockets::select_mode::select_error | true if processing a xtd::net::sockets::socket::connect that does not block, and the connection has failed; -or- true if xtd::net::sockets::socket_option_name::out_of_band_inline is not set and out-of-band data is available; otherwise, returns false. |
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks The xtd::net::sockets::socket::poll method checks the state of the xtd::net::sockets::socket. Specify xtd::net::sockets::select_mode::select_read for the select_mode parameter to determine if the xtd::net::sockets::socket is readable. Specify xtd::net::sockets::select_mode::select_write to determine if the xtd::net::sockets::socket is writable. Use SelectMode.SelectError to detect an error condition. Poll will block execution until the specified time period, measured in microseconds, elapses. Set the microSeconds parameter to a negative integer if you would like to wait indefinitely for a response. If you want to check the status of multiple sockets, you might prefer to use the xtd::net::sockets::socket::select method.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        bool poll(int32_t micro_seconds, xtd::net::sockets::select_mode mode);

        /// @brief Receives data from a bound xtd::net::sockets::socket into a receive buffer.
        /// @param buffer An array of type byte that is the storage location for the received data.
        /// @return The number of bytes received.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks The xtd::net::sockets::socket::receive method reads data into the buffer parameter and returns the number of bytes successfully read. You can call xtd::net::sockets::socket::receive from both connection-oriented and connectionless sockets.
        /// @remarks This overload only requires you to provide a receive buffer. The buffer offset defaults to 0, the size defaults to the size of the buffer parameter, and the xtd::net::sockets::socket_flags value defaults to xtd::net::sockets::socket_flag::none.
        /// @remarks If you are using a connection-oriented protocol, you must either call xtd::net::sockets::socket::connect to establish a remote host connection, or xtd::net::sockets::socket::accept to accept an incoming connection prior to calling xtd::net::sockets::socket::receive. The xtd::net::sockets::socket::receive method will only read data that arrives from the remote host established in the xtd::net::sockets::socket::connect or xtd::net::sockets::socket::accept method. If you are using a connectionless protocol, you can also use the xtd::net::sockets::socket::receive_from method. xtd::net::sockets::socket::receive_from will allow you to receive data arriving from any host.
        /// @remarks If no data is available for reading, the xtd::net::sockets::socket::receive method will block until data is available, unless a time-out value was set by using xtd::net::sockets::socket::receive_timeout. If the time-out value was exceeded, the xtd::net::sockets::socket::receive call will throw a xtd::net::sockets::socket_exception. If you are in non-blocking mode, and there is no data available in the in the protocol stack buffer, the xtd::net::sockets::socket::receive method will complete immediately and throw a xtd::net::sockets::socket_exception. You can use the xtd::net::sockets::socket::available property to determine if data is available for reading. When xtd::net::sockets::socket::available is non-zero, retry the receive operation.
        /// @remarks If you are using a connection-oriented xtd::net::sockets::socket, the xtd::net::sockets::socket::receive method will read as much data as is available, up to the size of the buffer. If the remote host shuts down the xtd::net::sockets::socket connection with the xtd::net::sockets::socket::shutdown method, and all available data has been received, the xtd::net::sockets::socket::receive method will complete immediately and return zero bytes.
        /// @remarks If you are using a connectionless xtd::net::sockets::socket, xtd::net::sockets::socket::receive will read the first queued datagram from the destination address you specify in the xtd::net::sockets::socket::connect method. If the datagram you receive is larger than the size of the buffer parameter, buffer gets filled with the first part of the message, the excess data is lost and a xtd::net::sockets::socket::socket_exception is thrown.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        size_t receive(std::vector<byte_t>& buffer);
        
        /// @brief Receives data from a bound xtd::net::sockets::socket into a receive buffer, using the specified xtd::net::sockets::socket_flags.
        /// @param buffer An array of type byte that is the storage location for the received data.
        /// @param socket_flags A bitwise combination of the xtd::net::sockets::socket_flags values.
        /// @return The number of bytes received.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks The xtd::net::sockets::socket::receive method reads data into the buffer parameter and returns the number of bytes successfully read. You can call xtd::net::sockets::socket::receive from both connection-oriented and connectionless sockets.
        /// @remarks This overload only requires you to provide a receive buffer and the necessary xtd::net::sockets::socket_flags. The buffer offset defaults to 0, and the size defaults to the length of the byte parameter.
        /// @remarks If you are using a connection-oriented protocol, you must either call xtd::net::sockets::socket::connect to establish a remote host connection, or xtd::net::sockets::socket::accept to accept an incoming connection prior to calling xtd::net::sockets::socket::receive. The xtd::net::sockets::socket::receive method will only read data that arrives from the remote host established in the xtd::net::sockets::socket::connect or xtd::net::sockets::socket::accept method. If you are using a connectionless protocol, you can also use the xtd::net::sockets::socket::receive_from method. xtd::net::sockets::socket::receive_from will allow you to receive data arriving from any host.
        /// @remarks If no data is available for reading, the xtd::net::sockets::socket::receive method will block until data is available, unless a time-out value was set by using xtd::net::sockets::socket::receive_timeout. If the time-out value was exceeded, the xtd::net::sockets::socket::receive call will throw a xtd::net::sockets::socket_exception. If you are in non-blocking mode, and there is no data available in the in the protocol stack buffer, the xtd::net::sockets::socket::receive method will complete immediately and throw a xtd::net::sockets::socket_exception. You can use the xtd::net::sockets::socket::available property to determine if data is available for reading. When xtd::net::sockets::socket::available is non-zero, retry the receive operation.
        /// @remarks If you are using a connection-oriented xtd::net::sockets::socket, the xtd::net::sockets::socket::receive method will read as much data as is available, up to the size of the buffer. If the remote host shuts down the xtd::net::sockets::socket connection with the xtd::net::sockets::socket::shutdown method, and all available data has been received, the xtd::net::sockets::socket::receive method will complete immediately and return zero bytes.
        /// @remarks If you are using a connectionless xtd::net::sockets::socket, xtd::net::sockets::socket::receive will read the first queued datagram from the destination address you specify in the xtd::net::sockets::socket::connect method. If the datagram you receive is larger than the size of the buffer parameter, buffer gets filled with the first part of the message, the excess data is lost and a xtd::net::sockets::socket::socket_exception is thrown.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        size_t receive(std::vector<byte_t>& buffer, xtd::net::sockets::socket_flags socket_flags);
        
        /// @brief Receives the specified number of bytes of data from a bound xtd::net::sockets::socket into a receive buffer, using the specified xtd::net::sockets::socket_flags.
        /// @param buffer An array of type byte that is the storage location for the received data.
        /// @param size The number of bytes to receive.
        /// @param socket_flags A bitwise combination of the xtd::net::sockets::socket_flags values.
        /// @return The number of bytes received.
        /// @exception xtd::argument_out_of_range_exception size is less than 0 or exceeds the size of the buffer.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks The xtd::net::sockets::socket::receive method reads data into the buffer parameter and returns the number of bytes successfully read. You can call xtd::net::sockets::socket::receive from both connection-oriented and connectionless sockets.
        /// @remarks This overload only requires you to provide a receive buffer, the number of bytes you want to receive, and the necessary xtd::net::sockets::socket_flags.
        /// @remarks If you are using a connection-oriented protocol, you must either call xtd::net::sockets::socket::connect to establish a remote host connection, or xtd::net::sockets::socket::accept to accept an incoming connection prior to calling xtd::net::sockets::socket::receive. The xtd::net::sockets::socket::receive method will only read data that arrives from the remote host established in the xtd::net::sockets::socket::connect or xtd::net::sockets::socket::accept method. If you are using a connectionless protocol, you can also use the xtd::net::sockets::socket::receive_from method. xtd::net::sockets::socket::receive_from will allow you to receive data arriving from any host.
        /// @remarks If no data is available for reading, the xtd::net::sockets::socket::receive method will block until data is available, unless a time-out value was set by using xtd::net::sockets::socket::receive_timeout. If the time-out value was exceeded, the xtd::net::sockets::socket::receive call will throw a xtd::net::sockets::socket_exception. If you are in non-blocking mode, and there is no data available in the in the protocol stack buffer, the xtd::net::sockets::socket::receive method will complete immediately and throw a xtd::net::sockets::socket_exception. You can use the xtd::net::sockets::socket::available property to determine if data is available for reading. When xtd::net::sockets::socket::available is non-zero, retry the receive operation.
        /// @remarks If you are using a connection-oriented xtd::net::sockets::socket, the xtd::net::sockets::socket::receive method will read as much data as is available, up to the size of the buffer. If the remote host shuts down the xtd::net::sockets::socket connection with the xtd::net::sockets::socket::shutdown method, and all available data has been received, the xtd::net::sockets::socket::receive method will complete immediately and return zero bytes.
        /// @remarks If you are using a connectionless xtd::net::sockets::socket, xtd::net::sockets::socket::receive will read the first queued datagram from the destination address you specify in the xtd::net::sockets::socket::connect method. If the datagram you receive is larger than the size of the buffer parameter, buffer gets filled with the first part of the message, the excess data is lost and a xtd::net::sockets::socket::socket_exception is thrown.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        size_t receive(std::vector<byte_t>& buffer, size_t size, xtd::net::sockets::socket_flags socket_flags);
        
        /// @brief Receives the specified number of bytes from a bound xtd::net::sockets::socket into the specified offset position of the receive buffer, using the specified xtd::net::sockets::socket_flags.
        /// @param buffer An array of type byte that is the storage location for the received data.
        /// @param offset The location in buffer to store the received data.
        /// @param size The number of bytes to receive.
        /// @param socket_flags A bitwise combination of the xtd::net::sockets::socket_flags values.
        /// @return The number of bytes received.
        /// @exception xtd::argument_out_of_range_exception size is less than 0 or exceeds the size of the buffer.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks The xtd::net::sockets::socket::receive method reads data into the buffer parameter and returns the number of bytes successfully read. You can call xtd::net::sockets::socket::receive from both connection-oriented and connectionless sockets.
        /// @remarks If you are using a connection-oriented protocol, you must either call xtd::net::sockets::socket::connect to establish a remote host connection, or xtd::net::sockets::socket::accept to accept an incoming connection prior to calling xtd::net::sockets::socket::receive. The xtd::net::sockets::socket::receive method will only read data that arrives from the remote host established in the xtd::net::sockets::socket::connect or xtd::net::sockets::socket::accept method. If you are using a connectionless protocol, you can also use the xtd::net::sockets::socket::receive_from method. xtd::net::sockets::socket::receive_from will allow you to receive data arriving from any host.
        /// @remarks If no data is available for reading, the xtd::net::sockets::socket::receive method will block until data is available, unless a time-out value was set by using xtd::net::sockets::socket::receive_timeout. If the time-out value was exceeded, the xtd::net::sockets::socket::receive call will throw a xtd::net::sockets::socket_exception. If you are in non-blocking mode, and there is no data available in the in the protocol stack buffer, the xtd::net::sockets::socket::receive method will complete immediately and throw a xtd::net::sockets::socket_exception. You can use the xtd::net::sockets::socket::available property to determine if data is available for reading. When xtd::net::sockets::socket::available is non-zero, retry the receive operation.
        /// @remarks If you are using a connection-oriented xtd::net::sockets::socket, the xtd::net::sockets::socket::receive method will read as much data as is available, up to the size of the buffer. If the remote host shuts down the xtd::net::sockets::socket connection with the xtd::net::sockets::socket::shutdown method, and all available data has been received, the xtd::net::sockets::socket::receive method will complete immediately and return zero bytes.
        /// @remarks If you are using a connectionless xtd::net::sockets::socket, xtd::net::sockets::socket::receive will read the first queued datagram from the destination address you specify in the xtd::net::sockets::socket::connect method. If the datagram you receive is larger than the size of the buffer parameter, buffer gets filled with the first part of the message, the excess data is lost and a xtd::net::sockets::socket::socket_exception is thrown.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        size_t receive(std::vector<byte_t>& buffer, size_t offset, size_t size, xtd::net::sockets::socket_flags socket_flags);
        
        /// @brief Receives the specified number of bytes from a bound xtd::net::sockets::socket into the specified offset position of the receive buffer, using the specified xtd::net::sockets::socket_flags.
        /// @param buffer An array of type byte that is the storage location for the received data.
        /// @param offset The location in buffer to store the received data.
        /// @param size The number of bytes to receive.
        /// @param socket_flags A bitwise combination of the xtd::net::sockets::socket_flags values.
        /// @param error_code A xtd::net::sockets::socket_error object that stores the socket error.
        /// @return The number of bytes received.
        /// @exception xtd::argument_out_of_range_exception size is less than 0 or exceeds the size of the buffer.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks The xtd::net::sockets::socket::receive method reads data into the buffer parameter and returns the number of bytes successfully read. You can call xtd::net::sockets::socket::receive from both connection-oriented and connectionless sockets.
        /// @remarks If you are using a connection-oriented protocol, you must either call xtd::net::sockets::socket::connect to establish a remote host connection, or xtd::net::sockets::socket::accept to accept an incoming connection prior to calling xtd::net::sockets::socket::receive. The xtd::net::sockets::socket::receive method will only read data that arrives from the remote host established in the xtd::net::sockets::socket::connect or xtd::net::sockets::socket::accept method. If you are using a connectionless protocol, you can also use the xtd::net::sockets::socket::receive_from method. xtd::net::sockets::socket::receive_from will allow you to receive data arriving from any host.
        /// @remarks If no data is available for reading, the xtd::net::sockets::socket::receive method will block until data is available, unless a time-out value was set by using xtd::net::sockets::socket::receive_timeout. If the time-out value was exceeded, the xtd::net::sockets::socket::receive call will throw a xtd::net::sockets::socket_exception. If you are in non-blocking mode, and there is no data available in the in the protocol stack buffer, the xtd::net::sockets::socket::receive method will complete immediately and throw a xtd::net::sockets::socket_exception. You can use the xtd::net::sockets::socket::available property to determine if data is available for reading. When xtd::net::sockets::socket::available is non-zero, retry the receive operation.
        /// @remarks If you are using a connection-oriented xtd::net::sockets::socket, the xtd::net::sockets::socket::receive method will read as much data as is available, up to the size of the buffer. If the remote host shuts down the xtd::net::sockets::socket connection with the xtd::net::sockets::socket::shutdown method, and all available data has been received, the xtd::net::sockets::socket::receive method will complete immediately and return zero bytes.
        /// @remarks If you are using a connectionless xtd::net::sockets::socket, xtd::net::sockets::socket::receive will read the first queued datagram from the destination address you specify in the xtd::net::sockets::socket::connect method. If the datagram you receive is larger than the size of the buffer parameter, buffer gets filled with the first part of the message, the excess data is lost and a xtd::net::sockets::socket::socket_exception is thrown.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        size_t receive(std::vector<byte_t>& buffer, size_t offset, size_t size, xtd::net::sockets::socket_flags socket_flags, xtd::net::sockets::socket_error& error);
        
        /// @brief Receives data from a bound xtd::net::sockets::socket into a receive buffer.
        /// @param buffer An array of type byte that is the storage location for the received data.
        /// @param remote_end_point the remote host
        /// @return The number of bytes received.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks The xtd::net::sockets::socket::receive_from method reads data into the buffer parameter, returns the number of bytes successfully read, and captures the remote host endpoint from which the data was sent. This method is useful if you intend to receive connectionless datagrams from an unknown host or multiple hosts.
        /// @remarks This overload only requires you to provide a receive buffer, and an xtd::net::end_point that represents the remote host. The buffer offset defaults to 0. The size defaults to the size of the buffer parameter and the xtd::net::sockets::socket_flags value defaults to xtd::net::sockets::socket_flags::none.
        /// @note Before calling xtd::net::sockets::socket::receive_from, you must explicitly bind the xtd::net::sockets::socket to a local endpoint using the xtd::net::sockets::socket::bind method. If you do not, xtd::net::sockets::socket::receive_from will throw a xtd::net::sockets::socket::socket_exception.
        /// @remarks With connectionless protocols, xtd::net::sockets::socket::receive_from will read the first enqueued datagram received into the local network buffer. If the datagram you receive is larger than the size of buffer, the xtd::net::sockets::socket::receive_from method will fill buffer with as much of the message as is possible, and throw a xtd::net::sockets::socket::socket_exception. If you are using an unreliable protocol, the excess data will be lost. If you are using a reliable protocol, the excess data will be retained by the service provider and you can retrieve it by calling the xtd::net::sockets::socket::receive_from method with a large enough buffer.
        /// @remarks If no data is available for reading, the xtd::net::sockets::socket::receive_from method will block until data is available. If you are in non-blocking mode, and there is no data available in the in the protocol stack buffer, the xtd::net::sockets::socket::receive_from method will complete immediately and throw a xtd::net::sockets::socket::socket_exception. You can use the xtd::net::sockets::socket::socket::available property to determine if data is available for reading. When xtd::net::sockets::socket::socket::available is non-zero, retry the receive operation.
        /// @remarks Although xtd::net::sockets::socket::receive_from is intended for connectionless protocols, you can use a connection-oriented protocol as well. If you choose to do so, you must first either establish a remote host connection by calling the xtd::net::sockets::socket::socket::connect method or accept an incoming remote host connection by calling the xtd::net::sockets::socket::socket::accept method. If you do not establish or accept a connection before calling the xtd::net::sockets::socket::receive_from method, you will get a xtd::net::sockets::socket::socket_exception. You can also establish a default remote host for a connectionless protocol prior to calling the xtd::net::sockets::socket::receive_from method. In either of these cases, the xtd::net::sockets::socket::receive_from method will ignore the remote_end_point parameter and only receive data from the connected or default remote host.
        /// @remarks With connection-oriented sockets, xtd::net::sockets::socket::receive_from will read as much data as is available up to the size of buffer. If the remote host shuts down the xtd::net::sockets::socket connection with the xtd::net::sockets::socket::socket::shutdown method, and all available data has been received, the xtd::net::sockets::socket::receive_from method will complete immediately and return zero bytes.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        /// @note The xtd::net::sockets::sockets::address_family of the xtd::net::end_point used in xtd::net::sockets::socket::receive_from needs to match the xtd::net::sockets::sockets::address_family of the xtd::net::end_point used in xtd::net::sockets::sockets::socket::send_to.
        size_t receive_from(std::vector<byte_t>& buffer, xtd::net::end_point& remote_end_point);
        
        /// @brief Receives data from a bound xtd::net::sockets::socket into a receive buffer.
        /// @param buffer An array of type byte that is the storage location for the received data.
        /// @param socket_flags A bitwise combination of the xtd::net::sockets::socket_flags values.
        /// @param remote_end_point the remote host
        /// @return The number of bytes received.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks The xtd::net::sockets::socket::receive_from method reads data into the buffer parameter, returns the number of bytes successfully read, and captures the remote host endpoint from which the data was sent. This method is useful if you intend to receive connectionless datagrams from an unknown host or multiple hosts.
        /// @remarks This overload only requires you to provide a receive buffer, the necessary xtd::net::sockets::socket_flags, and an xtd::net::end_point that represents the remote host. The offset defaults to 0 and the size defaults to the size of the buffer parameter.
        /// @note Before calling xtd::net::sockets::socket::receive_from, you must explicitly bind the xtd::net::sockets::socket to a local endpoint using the xtd::net::sockets::socket::bind method. If you do not, xtd::net::sockets::socket::receive_from will throw a xtd::net::sockets::socket::socket_exception.
        /// @remarks With connectionless protocols, xtd::net::sockets::socket::receive_from will read the first enqueued datagram received into the local network buffer. If the datagram you receive is larger than the size of buffer, the xtd::net::sockets::socket::receive_from method will fill buffer with as much of the message as is possible, and throw a xtd::net::sockets::socket::socket_exception. If you are using an unreliable protocol, the excess data will be lost. If you are using a reliable protocol, the excess data will be retained by the service provider and you can retrieve it by calling the xtd::net::sockets::socket::receive_from method with a large enough buffer.
        /// @remarks If no data is available for reading, the xtd::net::sockets::socket::receive_from method will block until data is available. If you are in non-blocking mode, and there is no data available in the in the protocol stack buffer, the xtd::net::sockets::socket::receive_from method will complete immediately and throw a xtd::net::sockets::socket::socket_exception. You can use the xtd::net::sockets::socket::socket::available property to determine if data is available for reading. When xtd::net::sockets::socket::socket::available is non-zero, retry the receive operation.
        /// @remarks Although xtd::net::sockets::socket::receive_from is intended for connectionless protocols, you can use a connection-oriented protocol as well. If you choose to do so, you must first either establish a remote host connection by calling the xtd::net::sockets::socket::socket::connect method or accept an incoming remote host connection by calling the xtd::net::sockets::socket::socket::accept method. If you do not establish or accept a connection before calling the xtd::net::sockets::socket::receive_from method, you will get a xtd::net::sockets::socket::socket_exception. You can also establish a default remote host for a connectionless protocol prior to calling the xtd::net::sockets::socket::receive_from method. In either of these cases, the xtd::net::sockets::socket::receive_from method will ignore the remote_end_point parameter and only receive data from the connected or default remote host.
        /// @remarks With connection-oriented sockets, xtd::net::sockets::socket::receive_from will read as much data as is available up to the size of buffer. If the remote host shuts down the xtd::net::sockets::socket connection with the xtd::net::sockets::socket::socket::shutdown method, and all available data has been received, the xtd::net::sockets::socket::receive_from method will complete immediately and return zero bytes.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        /// @note The xtd::net::sockets::sockets::address_family of the xtd::net::end_point used in xtd::net::sockets::socket::receive_from needs to match the xtd::net::sockets::sockets::address_family of the xtd::net::end_point used in xtd::net::sockets::sockets::socket::send_to.
        size_t receive_from(std::vector<byte_t>& buffer, xtd::net::sockets::socket_flags socket_flags, xtd::net::end_point& remote_end_point);
        
        /// @brief Receives data from a bound xtd::net::sockets::socket into a receive buffer.
        /// @param buffer An array of type byte that is the storage location for the received data.
        /// @param size The number of bytes to receive.
        /// @param socket_flags A bitwise combination of the xtd::net::sockets::socket_flags values.
        /// @param remote_end_point the remote host
        /// @return The number of bytes received.
        /// @exception xtd::argument_out_of_range_exception size is less than 0 or exceeds the size of the buffer.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks The xtd::net::sockets::socket::receive_from method reads data into the buffer parameter, returns the number of bytes successfully read, and captures the remote host endpoint from which the data was sent. This method is useful if you intend to receive connectionless datagrams from an unknown host or multiple hosts.
        /// @remarks This overload only requires you to provide a receive buffer, the number of bytes you want to receive, the necessary xtd::net::sockets::socket_flags, and an xtd::net::end_point that represents the remote host. The buffer offset defaults to 0.
        /// @note Before calling xtd::net::sockets::socket::receive_from, you must explicitly bind the xtd::net::sockets::socket to a local endpoint using the xtd::net::sockets::socket::bind method. If you do not, xtd::net::sockets::socket::receive_from will throw a xtd::net::sockets::socket::socket_exception.
        /// @remarks With connectionless protocols, xtd::net::sockets::socket::receive_from will read the first enqueued datagram received into the local network buffer. If the datagram you receive is larger than the size of buffer, the xtd::net::sockets::socket::receive_from method will fill buffer with as much of the message as is possible, and throw a xtd::net::sockets::socket::socket_exception. If you are using an unreliable protocol, the excess data will be lost. If you are using a reliable protocol, the excess data will be retained by the service provider and you can retrieve it by calling the xtd::net::sockets::socket::receive_from method with a large enough buffer.
        /// @remarks If no data is available for reading, the xtd::net::sockets::socket::receive_from method will block until data is available. If you are in non-blocking mode, and there is no data available in the in the protocol stack buffer, the xtd::net::sockets::socket::receive_from method will complete immediately and throw a xtd::net::sockets::socket::socket_exception. You can use the xtd::net::sockets::socket::socket::available property to determine if data is available for reading. When xtd::net::sockets::socket::socket::available is non-zero, retry the receive operation.
        /// @remarks Although xtd::net::sockets::socket::receive_from is intended for connectionless protocols, you can use a connection-oriented protocol as well. If you choose to do so, you must first either establish a remote host connection by calling the xtd::net::sockets::socket::socket::connect method or accept an incoming remote host connection by calling the xtd::net::sockets::socket::socket::accept method. If you do not establish or accept a connection before calling the xtd::net::sockets::socket::receive_from method, you will get a xtd::net::sockets::socket::socket_exception. You can also establish a default remote host for a connectionless protocol prior to calling the xtd::net::sockets::socket::receive_from method. In either of these cases, the xtd::net::sockets::socket::receive_from method will ignore the remote_end_point parameter and only receive data from the connected or default remote host.
        /// @remarks With connection-oriented sockets, xtd::net::sockets::socket::receive_from will read as much data as is available up to the size of buffer. If the remote host shuts down the xtd::net::sockets::socket connection with the xtd::net::sockets::socket::socket::shutdown method, and all available data has been received, the xtd::net::sockets::socket::receive_from method will complete immediately and return zero bytes.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        /// @note The xtd::net::sockets::sockets::address_family of the xtd::net::end_point used in xtd::net::sockets::socket::receive_from needs to match the xtd::net::sockets::sockets::address_family of the xtd::net::end_point used in xtd::net::sockets::sockets::socket::send_to.
        size_t receive_from(std::vector<byte_t>& buffer, size_t size, xtd::net::sockets::socket_flags socket_flags, xtd::net::end_point& remote_end_point);
        
        /// @brief Receives data from a bound xtd::net::sockets::socket into a receive buffer.
        /// @param buffer An array of type byte that is the storage location for the received data.
        /// @param offset The position in the buffer parameter to store the received data.
        /// @param size The number of bytes to receive.
        /// @param socket_flags A bitwise combination of the xtd::net::sockets::socket_flags values.
        /// @param remote_end_point the remote host
        /// @return The number of bytes received.
        /// @exception xtd::argument_out_of_range_exception size is less than 0 or exceeds the size of the buffer.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks The xtd::net::sockets::socket::receive_from method reads data into the buffer parameter, returns the number of bytes successfully read, and captures the remote host endpoint from which the data was sent. This method is useful if you intend to receive connectionless datagrams from an unknown host or multiple hosts.
        /// @note Before calling xtd::net::sockets::socket::receive_from, you must explicitly bind the xtd::net::sockets::socket to a local endpoint using the xtd::net::sockets::socket::bind method. If you do not, xtd::net::sockets::socket::receive_from will throw a xtd::net::sockets::socket::socket_exception.
        /// @remarks With connectionless protocols, xtd::net::sockets::socket::receive_from will read the first enqueued datagram received into the local network buffer. If the datagram you receive is larger than the size of buffer, the xtd::net::sockets::socket::receive_from method will fill buffer with as much of the message as is possible, and throw a xtd::net::sockets::socket::socket_exception. If you are using an unreliable protocol, the excess data will be lost. If you are using a reliable protocol, the excess data will be retained by the service provider and you can retrieve it by calling the xtd::net::sockets::socket::receive_from method with a large enough buffer.
        /// @remarks If no data is available for reading, the xtd::net::sockets::socket::receive_from method will block until data is available. If you are in non-blocking mode, and there is no data available in the in the protocol stack buffer, the xtd::net::sockets::socket::receive_from method will complete immediately and throw a xtd::net::sockets::socket::socket_exception. You can use the xtd::net::sockets::socket::socket::available property to determine if data is available for reading. When xtd::net::sockets::socket::socket::available is non-zero, retry the receive operation.
        /// @remarks Although xtd::net::sockets::socket::receive_from is intended for connectionless protocols, you can use a connection-oriented protocol as well. If you choose to do so, you must first either establish a remote host connection by calling the xtd::net::sockets::socket::socket::connect method or accept an incoming remote host connection by calling the xtd::net::sockets::socket::socket::accept method. If you do not establish or accept a connection before calling the xtd::net::sockets::socket::receive_from method, you will get a xtd::net::sockets::socket::socket_exception. You can also establish a default remote host for a connectionless protocol prior to calling the xtd::net::sockets::socket::receive_from method. In either of these cases, the xtd::net::sockets::socket::receive_from method will ignore the remote_end_point parameter and only receive data from the connected or default remote host.
        /// @remarks With connection-oriented sockets, xtd::net::sockets::socket::receive_from will read as much data as is available up to the size of buffer. If the remote host shuts down the xtd::net::sockets::socket connection with the xtd::net::sockets::socket::socket::shutdown method, and all available data has been received, the xtd::net::sockets::socket::receive_from method will complete immediately and return zero bytes.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        /// @note The xtd::net::sockets::sockets::address_family of the xtd::net::end_point used in xtd::net::sockets::socket::receive_from needs to match the xtd::net::sockets::sockets::address_family of the xtd::net::end_point used in xtd::net::sockets::sockets::socket::send_to.
        size_t receive_from(std::vector<byte_t>& buffer, size_t offset, size_t size, xtd::net::sockets::socket_flags socket_flags, xtd::net::end_point& remote_end_point);
 
        size_t receive_message_from(std::vector<byte_t>& buffer, size_t offset, size_t size, xtd::net::sockets::socket_flags socket_flags, xtd::net::end_point& remote_end_point, xtd::net::sockets::ip_packet_information& ip_packet_information);
        
        /// @brief Determines the status of one or more sockets.
        /// @param check_read An array of xtd::net::sockets::socket instances to check for readability.
        /// @param check_write An array of xtd::net::sockets::socket instances to check for writability.
        /// @param check_error An array of xtd::net::sockets::socket instances to check for errors.
        /// @param microseconds The time-out value, in microseconds. A -1 value indicates an infinite time-out.
        /// @return 0 if the timeout expired; otherwise, the total number of sockets returned in the lists.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @remarks xtd::net::sockets::socket::select is a static method that determines the status of one or more xtd::net::sockets::socket instances. You must place one or more sockets into an array before you can use the xtd::net::sockets::socket::select method. Check for readability by calling xtd::net::sockets::socket::select with the array as the check_read parameter. To check your sockets for writability, use the check_write parameter. For detecting error conditions, use check_error. After calling xtd::net::sockets::socket::select, the array will be filled with only those sockets that satisfy the conditions.
        /// @remarks If you are in a listening state, readability means that a call to xtd::net::sockets::socket::accept will succeed without blocking. If you have already accepted the connection, readability means that data is available for reading. In these cases, all receive operations will succeed without blocking. Readability can also indicate whether the remote xtd::net::sockets::socket has shut down the connection; in that case a call to xtd::net::sockets::socket::::receive will return immediately, with zero bytes returned.
        /// @remarks xtd::net::sockets::socket::select returns when at least one of the sockets of interest (the sockets in the check_read, check_write, and check_error lists) meets its specified criteria, or the microseconds parameter is exceeded, whichever comes first. Setting microseconds to -1 specifies an infinite time-out.
        /// @remarks If you make a nonblocking call to xtd::net::sockets::socket::connect, writability means that you have connected successfully. If you already have a connection established, writability means that all send operations will succeed without blocking.
        /// @remarks If you have made a non-blocking call to xtd::net::sockets::socket::connect, the check_error parameter identifies sockets that have not connected successfully.
        /// @remarks Use the xtd::net::sockets::socket::poll method if you only want to determine the status of a single xtd::net::sockets::socket.
        /// @note This method cannot detect certain kinds of connection problems, such as a broken network cable, or that the remote host was shut down ungracefully. You must attempt to send or receive data to detect these kinds of errors.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        static size_t select(std::vector<socket>& check_read,std::vector<socket>& check_write, std::vector<socket>& check_error, int32_t microseconds);

        /// @brief Sends data to a connected xtd::net::sockets::socket.
        /// @param buffer An array of type byte that contains the data to be sent.
        /// @return The number of bytes sent to the xtd::net::sockets::socket.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks xtd::net::sockets::socket::send synchronously sends data to the remote host specified in the xtd::net::sockets::socket::connect or xtd::net::sockets::socket::accept method and returns the number of bytes successfully sent. xtd::net::sockets::socket::send can be used for both connection-oriented and connectionless protocols.
        /// @remarks This overload requires a buffer that contains the data you want to send. The xtd::net::sockets::socket_flags value defaults to xtd::net::sockets::socket_flags::none, the buffer offset defaults to 0, and the number of bytes to send defaults to the size of the buffer.
        /// @remarks If you are using a connectionless protocol, you must call xtd::net::sockets::socket::connect before calling this method, or xtd::net::sockets::socket::send will throw a xtd::net::sockets::socket_exception. If you are using a connection-oriented protocol, you must either use xtd::net::sockets::socket::connect to establish a remote host connection, or use xtd::net::sockets::socket::accept to accept an incoming connection.
        /// @remarks If you are using a connectionless protocol and plan to send data to several different hosts, you should use the xtd::net::sockets::socket::send_to method. If you do not use the xtd::net::sockets::socket::send_to method, you will have to call xtd::net::sockets::socket::connect before each call to xtd::net::sockets::socket::send. You can use xtd::net::sockets::socket::send_to even after you have established a default remote host with xtd::net::sockets::socket::connect. You can also change the default remote host prior to calling xtd::net::sockets::socket::send by making another call to xtd::net::sockets::socket::connect.
        /// @remarks If you are using a connection-oriented protocol, xtd::net::sockets::socket::send will block until all of the bytes in the buffer are sent, unless a time-out was set by using xtd::net::sockets::socket::send_timeout. If the time-out value was exceeded, the xtd::net::sockets::socket::send call will throw a xtd::net::sockets::socket_exception. In nonblocking mode, xtd::net::sockets::socket::send may complete successfully even if it sends less than the number of bytes in the buffer. It is your application's responsibility to keep track of the number of bytes sent and to retry the operation until the application sends the bytes in the buffer. There is also no guarantee that the data you send will appear on the network immediately. To increase network efficiency, the underlying system may delay transmission until a significant amount of outgoing data is collected. A successful completion of the Send method means that the underlying system has had room to buffer your data for a network send.
        /// @note The successful completion of a send does not indicate that the data was successfully delivered. If no buffer space is available within the transport system to hold the data to be transmitted, send will block unless the socket has been placed in nonblocking mode.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        size_t send(const std::vector<byte_t>& buffer);
        
        /// @brief Sends data to a connected xtd::net::sockets::socket using the specified xtd::net::sockets::socket_flags.
        /// @param buffer An array of type byte that contains the data to be sent.
        /// @param socket_flags A bitwise combination of the xtd::net::sockets::socket_flags values.
        /// @return The number of bytes sent to the xtd::net::sockets::socket.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks xtd::net::sockets::socket::send synchronously sends data to the remote host specified in the xtd::net::sockets::socket::connect or xtd::net::sockets::socket::accept method and returns the number of bytes successfully sent. xtd::net::sockets::socket::send can be used for both connection-oriented and connectionless protocols.
        /// @remarks This overload requires a buffer that contains the data you want to send and a bitwise combination of xtd::net::sockets::socket_flags. The buffer offset defaults to 0, and the number of bytes to send defaults to the size of the buffer. If you specify the xtd::net::sockets::socket_flags::dont_route flag as the socket_flags parameter value, the data you are sending will not be routed.
        /// @remarks If you are using a connectionless protocol, you must call xtd::net::sockets::socket::connect before calling this method, or xtd::net::sockets::socket::send will throw a xtd::net::sockets::socket_exception. If you are using a connection-oriented protocol, you must either use xtd::net::sockets::socket::connect to establish a remote host connection, or use xtd::net::sockets::socket::accept to accept an incoming connection.
        /// @remarks If you are using a connectionless protocol and plan to send data to several different hosts, you should use the xtd::net::sockets::socket::send_to method. If you do not use the xtd::net::sockets::socket::send_to method, you will have to call xtd::net::sockets::socket::connect before each call to xtd::net::sockets::socket::send. You can use xtd::net::sockets::socket::send_to even after you have established a default remote host with xtd::net::sockets::socket::connect. You can also change the default remote host prior to calling xtd::net::sockets::socket::send by making another call to xtd::net::sockets::socket::connect.
        /// @remarks If you are using a connection-oriented protocol, xtd::net::sockets::socket::send will block until all of the bytes in the buffer are sent, unless a time-out was set by using xtd::net::sockets::socket::send_timeout. If the time-out value was exceeded, the xtd::net::sockets::socket::send call will throw a xtd::net::sockets::socket_exception. In nonblocking mode, xtd::net::sockets::socket::send may complete successfully even if it sends less than the number of bytes in the buffer. It is your application's responsibility to keep track of the number of bytes sent and to retry the operation until the application sends the bytes in the buffer. There is also no guarantee that the data you send will appear on the network immediately. To increase network efficiency, the underlying system may delay transmission until a significant amount of outgoing data is collected. A successful completion of the Send method means that the underlying system has had room to buffer your data for a network send.
        /// @note The successful completion of a send does not indicate that the data was successfully delivered. If no buffer space is available within the transport system to hold the data to be transmitted, send will block unless the socket has been placed in nonblocking mode.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        size_t send(const std::vector<byte_t>& buffer, xtd::net::sockets::socket_flags socket_flags);
        
        /// @brief Sends the specified number of bytes of data to a connected xtd::net::sockets::socket, using the specified xtd::net::sockets::socket_flags.
        /// @param buffer An array of type byte that contains the data to be sent.
        /// @param size The number of bytes to send.
        /// @param socket_flags A bitwise combination of the xtd::net::sockets::socket_flags values.
        /// @return The number of bytes sent to the xtd::net::sockets::socket.
        /// @exception xtd::argument_out_of_range_exception size is less than 0 or exceeds the size of the buffer.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks xtd::net::sockets::socket::send synchronously sends data to the remote host specified in the xtd::net::sockets::socket::connect or xtd::net::sockets::socket::accept method and returns the number of bytes successfully sent. xtd::net::sockets::socket::send can be used for both connection-oriented and connectionless protocols.
        /// @remarks This overload requires a buffer that contains the data you want to send, the number of bytes you want to send, and a bitwise combination of any xtd::net::sockets::socket_flags. If you specify the xtd::net::sockets::socket_flags::dont_route flag as the socket_flags parameter, the data you're sending won't be routed.
        /// @remarks If you are using a connectionless protocol, you must call xtd::net::sockets::socket::connect before calling this method, or xtd::net::sockets::socket::send will throw a xtd::net::sockets::socket_exception. If you are using a connection-oriented protocol, you must either use xtd::net::sockets::socket::connect to establish a remote host connection, or use xtd::net::sockets::socket::accept to accept an incoming connection.
        /// @remarks If you are using a connectionless protocol and plan to send data to several different hosts, you should use the xtd::net::sockets::socket::send_to method. If you do not use the xtd::net::sockets::socket::send_to method, you will have to call xtd::net::sockets::socket::connect before each call to xtd::net::sockets::socket::send. You can use xtd::net::sockets::socket::send_to even after you have established a default remote host with xtd::net::sockets::socket::connect. You can also change the default remote host prior to calling xtd::net::sockets::socket::send by making another call to xtd::net::sockets::socket::connect.
        /// @remarks If you are using a connection-oriented protocol, xtd::net::sockets::socket::send will block until all of the bytes in the buffer are sent, unless a time-out was set by using xtd::net::sockets::socket::send_timeout. If the time-out value was exceeded, the xtd::net::sockets::socket::send call will throw a xtd::net::sockets::socket_exception. In nonblocking mode, xtd::net::sockets::socket::send may complete successfully even if it sends less than the number of bytes in the buffer. It is your application's responsibility to keep track of the number of bytes sent and to retry the operation until the application sends the bytes in the buffer. There is also no guarantee that the data you send will appear on the network immediately. To increase network efficiency, the underlying system may delay transmission until a significant amount of outgoing data is collected. A successful completion of the Send method means that the underlying system has had room to buffer your data for a network send.
        /// @note The successful completion of a send does not indicate that the data was successfully delivered. If no buffer space is available within the transport system to hold the data to be transmitted, send will block unless the socket has been placed in nonblocking mode.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        size_t send(const std::vector<byte_t>& buffer, size_t size, xtd::net::sockets::socket_flags socket_flags);
        
        /// @brief Sends the specified number of bytes of data to a connected xtd::net::sockets::socket, starting at the specified offset, and using the specified xtd::net::sockets::socket_flags.
        /// @param buffer An array of type byte that contains the data to be sent.
        /// @param offset The position in the data buffer at which to begin sending data.
        /// @param size The number of bytes to send.
        /// @param socket_flags A bitwise combination of the xtd::net::sockets::socket_flags values.
        /// @return The number of bytes sent to the xtd::net::sockets::socket.
        /// @exception xtd::argument_out_of_range_exception size is less than 0 or exceeds the size of the buffer.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks xtd::net::sockets::socket::send synchronously sends data to the remote host specified in the xtd::net::sockets::socket::connect or xtd::net::sockets::socket::accept method and returns the number of bytes successfully sent. xtd::net::sockets::socket::send can be used for both connection-oriented and connectionless protocols.
        /// @remarks In this overload, if you specify the xtd::net::sockets::socket_flags::dont_route flag as the socket_flags parameter, the data you're sending won't be routed.
        /// @remarks If you are using a connectionless protocol, you must call xtd::net::sockets::socket::connect before calling this method, or xtd::net::sockets::socket::send will throw a xtd::net::sockets::socket_exception. If you are using a connection-oriented protocol, you must either use xtd::net::sockets::socket::connect to establish a remote host connection, or use xtd::net::sockets::socket::accept to accept an incoming connection.
        /// @remarks If you are using a connectionless protocol and plan to send data to several different hosts, you should use the xtd::net::sockets::socket::send_to method. If you do not use the xtd::net::sockets::socket::send_to method, you will have to call xtd::net::sockets::socket::connect before each call to xtd::net::sockets::socket::send. You can use xtd::net::sockets::socket::send_to even after you have established a default remote host with xtd::net::sockets::socket::connect. You can also change the default remote host prior to calling xtd::net::sockets::socket::send by making another call to xtd::net::sockets::socket::connect.
        /// @remarks If you are using a connection-oriented protocol, xtd::net::sockets::socket::send will block until all of the bytes in the buffer are sent, unless a time-out was set by using xtd::net::sockets::socket::send_timeout. If the time-out value was exceeded, the xtd::net::sockets::socket::send call will throw a xtd::net::sockets::socket_exception. In nonblocking mode, xtd::net::sockets::socket::send may complete successfully even if it sends less than the number of bytes in the buffer. It is your application's responsibility to keep track of the number of bytes sent and to retry the operation until the application sends the bytes in the buffer. There is also no guarantee that the data you send will appear on the network immediately. To increase network efficiency, the underlying system may delay transmission until a significant amount of outgoing data is collected. A successful completion of the Send method means that the underlying system has had room to buffer your data for a network send.
        /// @note The successful completion of a send does not indicate that the data was successfully delivered. If no buffer space is available within the transport system to hold the data to be transmitted, send will block unless the socket has been placed in nonblocking mode.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        size_t send(const std::vector<byte_t>& buffer, size_t offset, size_t size, xtd::net::sockets::socket_flags socket_flags);
        
        /// @brief Sends the specified number of bytes of data to a connected xtd::net::sockets::socket, starting at the specified offset, and using the specified xtd::net::sockets::socket_flags.
        /// @param buffer An array of type byte that contains the data to be sent.
        /// @param offset The position in the data buffer at which to begin sending data.
        /// @param size The number of bytes to send.
        /// @param socket_flags A bitwise combination of the xtd::net::sockets::socket_flags values.
        /// @param error_code A xtd::net::sockets::socket_error object that stores the socket error.
        /// @return The number of bytes sent to the xtd::net::sockets::socket.
        /// @exception xtd::argument_out_of_range_exception size is less than 0 or exceeds the size of the buffer.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks xtd::net::sockets::socket::send synchronously sends data to the remote host specified in the xtd::net::sockets::socket::connect or xtd::net::sockets::socket::accept method and returns the number of bytes successfully sent. xtd::net::sockets::socket::send can be used for both connection-oriented and connectionless protocols.
        /// @remarks In this overload, if you specify the xtd::net::sockets::socket_flags::dont_route flag as the socket_flags parameter, the data you're sending won't be routed.
        /// @remarks If you are using a connectionless protocol, you must call xtd::net::sockets::socket::connect before calling this method, or xtd::net::sockets::socket::send will throw a xtd::net::sockets::socket_exception. If you are using a connection-oriented protocol, you must either use xtd::net::sockets::socket::connect to establish a remote host connection, or use xtd::net::sockets::socket::accept to accept an incoming connection.
        /// @remarks If you are using a connectionless protocol and plan to send data to several different hosts, you should use the xtd::net::sockets::socket::send_to method. If you do not use the xtd::net::sockets::socket::send_to method, you will have to call xtd::net::sockets::socket::connect before each call to xtd::net::sockets::socket::send. You can use xtd::net::sockets::socket::send_to even after you have established a default remote host with xtd::net::sockets::socket::connect. You can also change the default remote host prior to calling xtd::net::sockets::socket::send by making another call to xtd::net::sockets::socket::connect.
        /// @remarks If you are using a connection-oriented protocol, xtd::net::sockets::socket::send will block until all of the bytes in the buffer are sent, unless a time-out was set by using xtd::net::sockets::socket::send_timeout. If the time-out value was exceeded, the xtd::net::sockets::socket::send call will throw a xtd::net::sockets::socket_exception. In nonblocking mode, xtd::net::sockets::socket::send may complete successfully even if it sends less than the number of bytes in the buffer. It is your application's responsibility to keep track of the number of bytes sent and to retry the operation until the application sends the bytes in the buffer. There is also no guarantee that the data you send will appear on the network immediately. To increase network efficiency, the underlying system may delay transmission until a significant amount of outgoing data is collected. A successful completion of the Send method means that the underlying system has had room to buffer your data for a network send.
        /// @note The successful completion of a send does not indicate that the data was successfully delivered. If no buffer space is available within the transport system to hold the data to be transmitted, send will block unless the socket has been placed in nonblocking mode.
        size_t send(const std::vector<byte_t>& buffer, size_t offset, size_t size, xtd::net::sockets::socket_flags socket_flags, xtd::net::sockets::socket_error& error_code);
        
        /// @brief Sends data to the specified endpoint.
        /// @param buffer An array of type byte that contains the data to be sent.
        /// @param remote_end_point The xtd::net::end_point that represents the destination for the data.
        /// @return The number of bytes sent.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks In this overload, the buffer offset defaults to 0, the number of bytes to send defaults to the size of the buffer parameter, and the xtd::net::sockets::socket_flags value defaults to xtd::net::sockets::socket_flags::none.
        /// @remarks If you are using a connectionless protocol, you do not need to establish a default remote host with the xtd::net::sockets::socket::connect method prior to calling xtd::net::sockets::socket::send_to. You only need to do this if you intend to call the xtd::net::sockets::socket::send method. If you do call the xtd::net::sockets::socket::connect method prior to calling xtd::net::sockets::socket::send_tto, the remote_end_point parameter will override the specified default remote host for that send operation only. You are also not required to call the xtd::net::sockets::socket::bind method, because the underlying service provider will assign the most appropriate local network address and port number. If you need to identify the assigned local network address and port number, you can use the xtd::net::sockets::socket::local_end_point property after the xtd::net::sockets::socket::send_to method successfully completes.
        /// @remarks Although intended for connectionless protocols, xtd::net::sockets::socket::send_to also works with connection-oriented protocols. If you are using a connection-oriented protocol, you must first establish a remote host connection by calling the xtd::net::sockets::socket::connect method or accept an incoming connection request using the xtd::net::sockets::socket::accept method. If you do not establish or accept a remote host connection, xtd::net::sockets::socket::send_to will throw a xtd::net::sockets::socket_exception. You can also establish a default remote host for a connectionless protocol prior to calling the xtd::net::sockets::socket::send_to method. In either of these cases, xtd::net::sockets::socket::send_to will ignore the remote_end_point parameter and only send data to the connected or default remote host.
        /// @remarks Blocking sockets will block until the all of the bytes in the buffer are sent. Since a nonblocking xtd::net::sockets::socket completes immediately, it might not send all of the bytes in the buffer. It is your application's responsibility to keep track of the number of bytes sent and to retry the operation until the application sends all of the bytes in the buffer. There is also no guarantee that the data you send will appear on the network immediately. To increase network efficiency, the underlying system may delay transmission until a significant amount of outgoing data is collected. A successful completion of the xtd::net::sockets::socket::send_to method means that the underlying system has had room to buffer your data for a network send.
        /// @remarks If you are using a connectionless protocol in blocking mode, xtd::net::sockets::socket::send_to will block until the datagram is sent. If you want to send data to a broadcast address, you must first call the xtd::net::sockets::socket::set_socket_option method and set the socket option to xtd::net::sockets::socket_option_name::broadcast. You must also be sure that the number of bytes sent does not exceed the maximum packet size of the underlying service provider. If it does, the datagram will not be sent and xtd::net::sockets::socket::send_to will throw a xtd::net::sockets::socket_exception.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        size_t send_to(const std::vector<byte_t>& buffer, const xtd::net::end_point& remote_end_point);
        /// @brief Sends data to a specific endpoint using the specified xtd::net::sockets::socket_flags.
        /// @param socket_flags A bitwise combination of the xtd::net::sockets::socket_flags values.
        /// @param buffer An array of type byte that contains the data to be sent.
        /// @param remote_end_point The xtd::net::end_point that represents the destination for the data.
        /// @return The number of bytes sent.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks IIn this overload, the buffer offset defaults to 0, and the number of bytes to send defaults to the size of the buffer. If you specify the xtd::net::sockets::socket_flags::dont_route flag as the socket_flags parameter, the data you are sending will not be routed.
        /// @remarks If you are using a connectionless protocol, you do not need to establish a default remote host with the xtd::net::sockets::socket::connect method prior to calling xtd::net::sockets::socket::send_to. You only need to do this if you intend to call the xtd::net::sockets::socket::send method. If you do call the xtd::net::sockets::socket::connect method prior to calling xtd::net::sockets::socket::send_tto, the remote_end_point parameter will override the specified default remote host for that send operation only. You are also not required to call the xtd::net::sockets::socket::bind method, because the underlying service provider will assign the most appropriate local network address and port number. If you need to identify the assigned local network address and port number, you can use the xtd::net::sockets::socket::local_end_point property after the xtd::net::sockets::socket::send_to method successfully completes.
        /// @remarks Although intended for connectionless protocols, xtd::net::sockets::socket::send_to also works with connection-oriented protocols. If you are using a connection-oriented protocol, you must first establish a remote host connection by calling the xtd::net::sockets::socket::connect method or accept an incoming connection request using the xtd::net::sockets::socket::accept method. If you do not establish or accept a remote host connection, xtd::net::sockets::socket::send_to will throw a xtd::net::sockets::socket_exception. You can also establish a default remote host for a connectionless protocol prior to calling the xtd::net::sockets::socket::send_to method. In either of these cases, xtd::net::sockets::socket::send_to will ignore the remote_end_point parameter and only send data to the connected or default remote host.
        /// @remarks Blocking sockets will block until the all of the bytes in the buffer are sent. Since a nonblocking xtd::net::sockets::socket completes immediately, it might not send all of the bytes in the buffer. It is your application's responsibility to keep track of the number of bytes sent and to retry the operation until the application sends all of the bytes in the buffer. There is also no guarantee that the data you send will appear on the network immediately. To increase network efficiency, the underlying system may delay transmission until a significant amount of outgoing data is collected. A successful completion of the xtd::net::sockets::socket::send_to method means that the underlying system has had room to buffer your data for a network send.
        /// @remarks If you are using a connectionless protocol in blocking mode, xtd::net::sockets::socket::send_to will block until the datagram is sent. If you want to send data to a broadcast address, you must first call the xtd::net::sockets::socket::set_socket_option method and set the socket option to xtd::net::sockets::socket_option_name::broadcast. You must also be sure that the number of bytes sent does not exceed the maximum packet size of the underlying service provider. If it does, the datagram will not be sent and xtd::net::sockets::socket::send_to will throw a xtd::net::sockets::socket_exception.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        size_t send_to(const std::vector<byte_t>& buffer, xtd::net::sockets::socket_flags socket_flags, const xtd::net::end_point& remote_end_point);
        /// @brief Sends the specified number of bytes of data to the specified endpoint using the specified xtd::net::sockets::socket_flags.
        /// @param buffer An array of type byte that contains the data to be sent.
        /// @param size The number of bytes to send.
        /// @param socket_flags A bitwise combination of the xtd::net::sockets::socket_flags values.
        /// @param remote_end_point The xtd::net::end_point that represents the destination for the data.
        /// @return The number of bytes sent.
        /// @exception xtd::argument_out_of_range_exception size is less than 0 or exceeds the size of the buffer.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks In this overload, the buffer offset defaults to 0. If you specify the xtd::net::sockets::socket_flags::dont_route flag as the socket_flags parameter, the data you are sending will not be routed.
        /// @remarks If you are using a connectionless protocol, you do not need to establish a default remote host with the xtd::net::sockets::socket::connect method prior to calling xtd::net::sockets::socket::send_to. You only need to do this if you intend to call the xtd::net::sockets::socket::send method. If you do call the xtd::net::sockets::socket::connect method prior to calling xtd::net::sockets::socket::send_tto, the remote_end_point parameter will override the specified default remote host for that send operation only. You are also not required to call the xtd::net::sockets::socket::bind method, because the underlying service provider will assign the most appropriate local network address and port number. If you need to identify the assigned local network address and port number, you can use the xtd::net::sockets::socket::local_end_point property after the xtd::net::sockets::socket::send_to method successfully completes.
        /// @remarks Although intended for connectionless protocols, xtd::net::sockets::socket::send_to also works with connection-oriented protocols. If you are using a connection-oriented protocol, you must first establish a remote host connection by calling the xtd::net::sockets::socket::connect method or accept an incoming connection request using the xtd::net::sockets::socket::accept method. If you do not establish or accept a remote host connection, xtd::net::sockets::socket::send_to will throw a xtd::net::sockets::socket_exception. You can also establish a default remote host for a connectionless protocol prior to calling the xtd::net::sockets::socket::send_to method. In either of these cases, xtd::net::sockets::socket::send_to will ignore the remote_end_point parameter and only send data to the connected or default remote host.
        /// @remarks Blocking sockets will block until the all of the bytes in the buffer are sent. Since a nonblocking xtd::net::sockets::socket completes immediately, it might not send all of the bytes in the buffer. It is your application's responsibility to keep track of the number of bytes sent and to retry the operation until the application sends all of the bytes in the buffer. There is also no guarantee that the data you send will appear on the network immediately. To increase network efficiency, the underlying system may delay transmission until a significant amount of outgoing data is collected. A successful completion of the xtd::net::sockets::socket::send_to method means that the underlying system has had room to buffer your data for a network send.
        /// @remarks If you are using a connectionless protocol in blocking mode, xtd::net::sockets::socket::send_to will block until the datagram is sent. If you want to send data to a broadcast address, you must first call the xtd::net::sockets::socket::set_socket_option method and set the socket option to xtd::net::sockets::socket_option_name::broadcast. You must also be sure that the number of bytes sent does not exceed the maximum packet size of the underlying service provider. If it does, the datagram will not be sent and xtd::net::sockets::socket::send_to will throw a xtd::net::sockets::socket_exception.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        size_t send_to(const std::vector<byte_t>& buffer, size_t size, xtd::net::sockets::socket_flags socket_flags, const xtd::net::end_point& remote_end_point);
        /// @brief Sends the specified number of bytes of data to the specified endpoint, starting at the specified location in the buffer, and using the specified xtd::net::sockets::socket_flags.
        /// @param buffer An array of type byte that contains the data to be sent.
        /// @param offset The position in the data buffer at which to begin sending data.
        /// @param size The number of bytes to send.
        /// @param socket_flags A bitwise combination of the xtd::net::sockets::socket_flags values.
        /// @param remote_end_point The xtd::net::end_point that represents the destination for the data.
        /// @return The number of bytes sent.
        /// @exception xtd::argument_out_of_range_exception size is less than 0 or exceeds the size of the buffer.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks In this overload, if you specify the xtd::net::sockets::socket_flags::dont_route flag as the socket_flags parameter, the data you are sending will not be routed.
        /// @remarks If you are using a connectionless protocol, you do not need to establish a default remote host with the xtd::net::sockets::socket::connect method prior to calling xtd::net::sockets::socket::send_to. You only need to do this if you intend to call the xtd::net::sockets::socket::send method. If you do call the xtd::net::sockets::socket::connect method prior to calling xtd::net::sockets::socket::send_tto, the remote_end_point parameter will override the specified default remote host for that send operation only. You are also not required to call the xtd::net::sockets::socket::bind method, because the underlying service provider will assign the most appropriate local network address and port number. If you need to identify the assigned local network address and port number, you can use the xtd::net::sockets::socket::local_end_point property after the xtd::net::sockets::socket::send_to method successfully completes.
        /// @remarks Although intended for connectionless protocols, xtd::net::sockets::socket::send_to also works with connection-oriented protocols. If you are using a connection-oriented protocol, you must first establish a remote host connection by calling the xtd::net::sockets::socket::connect method or accept an incoming connection request using the xtd::net::sockets::socket::accept method. If you do not establish or accept a remote host connection, xtd::net::sockets::socket::send_to will throw a xtd::net::sockets::socket_exception. You can also establish a default remote host for a connectionless protocol prior to calling the xtd::net::sockets::socket::send_to method. In either of these cases, xtd::net::sockets::socket::send_to will ignore the remote_end_point parameter and only send data to the connected or default remote host.
        /// @remarks Blocking sockets will block until the all of the bytes in the buffer are sent. Since a nonblocking xtd::net::sockets::socket completes immediately, it might not send all of the bytes in the buffer. It is your application's responsibility to keep track of the number of bytes sent and to retry the operation until the application sends all of the bytes in the buffer. There is also no guarantee that the data you send will appear on the network immediately. To increase network efficiency, the underlying system may delay transmission until a significant amount of outgoing data is collected. A successful completion of the xtd::net::sockets::socket::send_to method means that the underlying system has had room to buffer your data for a network send.
        /// @remarks If you are using a connectionless protocol in blocking mode, xtd::net::sockets::socket::send_to will block until the datagram is sent. If you want to send data to a broadcast address, you must first call the xtd::net::sockets::socket::set_socket_option method and set the socket option to xtd::net::sockets::socket_option_name::broadcast. You must also be sure that the number of bytes sent does not exceed the maximum packet size of the underlying service provider. If it does, the datagram will not be sent and xtd::net::sockets::socket::send_to will throw a xtd::net::sockets::socket_exception.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        size_t send_to(const std::vector<byte_t>& buffer, size_t offset, size_t size, xtd::net::sockets::socket_flags socket_flags, const xtd::net::end_point& remote_end_point);

        /// @brief Sets the IP protection level on a socket.
        /// @param level The IP protection level to set on this socket.The IP protection level to set on this socket.
        /// @exception xtd::argument_exception The level argument is set to xtd::net::sockets::ip_protection_level::unspecified.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::not_supported_exception The socket is not in the xtd::net::sockets::address_family::inter_network_v6 or xtd::net::sockets::address_family::inter_network address families.
        /// @remarks The xtd::net::sockets::socket::set_ip_protection_level method enables restricting an a IPv6 or IP socket to listen on a specified scope, such as addresses with the same link local or site local prefix. This socket option enables applications to place access restrictions on IPv6 or IP sockets. Such restrictions enable an application running on a private LAN to simply and robustly harden itself against external attacks. This socket option can also be used to remove access restrictions if the level parameter is set to xtd::net::sockets::ip_protection_level xtd::net::sockets::ip_protection_level::unrestricted. This socket option widens or narrows the scope of a listening socket, enabling unrestricted access from public and private users when appropriate, or restricting access only to the same site, as required.
        /// @remarks This socket option has defined protection levels specified in the xtd::net::sockets::ip_protection_level enumeration.
        /// @remarks The xtd::net::sockets::socket::set_ip_protection_level method is used to enable or disable Network Address Traversal (NAT) for a xtd::net::sockets::socket instance. NAT traversal may be provided using Teredo, 6to4, or an ISATAP tunnel.
        /// @remarks When the level parameter is set to xtd::net::sockets::ip_protection_level::edge_restricted, or xtd::net::sockets::ip_protection_level::restricted, this explicitly disables NAT traversal for a xtd::net::sockets::socket instance.
        /// @remarks When the level parameter is set to xtd::net::sockets::ip_protection_level::edge_restricted, this may allow NAT traversal for a xtd::net::sockets::socket depending on firewall rules in place on the system.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        void set_ip_protection_level(xtd::net::sockets::ip_protection_level level);
        
        /// @brief Sets the specified xtd::net::sockets::socket option to the specified integer value.
        /// @param socket_option_level One of the xtd::net::sockets::socket_option_level values.
        /// @param socket_option_name One of the xtd::net::sockets::socket_option_name values.
        /// @param option_value A value of the option.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks xtd::net::sockets::socket options determine the behavior of the current xtd::net::sockets::socket. For an option with a Boolean data type, specify a nonzero value to enable the option, and a zero value to disable the option. For an option with an integer data type, specify the appropriate value. xtd::net::sockets::socket options are grouped by level of protocol support.
        /// @remarks xtd::net::sockets::socket options are grouped by level of protocol support.
        /// @remarks Listed below are the various xtd::net::sockets::socket options that can be set using this overload. These options are grouped by the appropriate SocketOptionLevel value. If you intend to set any of these options, be sure to use the appropriate SocketOptionLevel value for the optionLevel parameter. The option you choose to set must be specified in the optionName parameter. If you want to get the current value of any of the options listed, use the GetSocketOption method.
        ///  * xtd::net::sockets::socket_option_level::socket options that can be set using this overload:
        ///    * xtd::net::sockets::socket_option_name::accept_connection
        ///    * xtd::net::sockets::socket_option_name::broadcast
        ///    * xtd::net::sockets::socket_option_name::dont_linger
        ///    * xtd::net::sockets::socket_option_name::debug
        ///    * xtd::net::sockets::socket_option_name::keep_alive
        ///    * xtd::net::sockets::socket_option_name::out_of_band_inline
        ///    * xtd::net::sockets::socket_option_name::reuse_address
        ///  * xtd::net::sockets::socket_option_level::ip options that can be set using this overload:
        ///    * xtd::net::sockets::socket_option_name::header_included
        ///    * xtd::net::sockets::socket_option_name::multicast_loopback
        ///    * xtd::net::sockets::socket_option_name::use_loopback
        ///  * xtd::net::sockets::socket_option_level::tcp options that can be set using this overload:
        ///    * xtd::net::sockets::socket_option_name::bsd_urgent
        ///    * xtd::net::sockets::socket_option_name::expedited
        ///    * xtd::net::sockets::socket_option_name::no_delay
        ///  * xtd::net::sockets::socket_option_level::udp options that can be set using this overload :
        ///    * xtd::net::sockets::socket_option_name::no_checksum
        /// @remarks <br />For more information on these options, refer to the xtd::net::sockets::socket_option_name enumeration.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        void set_socket_option(xtd::net::sockets::socket_option_level socket_option_level, xtd::net::sockets::socket_option_name socket_option_name, bool option_value);

        /// @brief Sets the specified xtd::net::sockets::socket option to the specified integer value.
        /// @param socket_option_level One of the xtd::net::sockets::socket_option_level values.
        /// @param socket_option_name One of the xtd::net::sockets::socket_option_name values.
        /// @param option_value A value of the option.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks xtd::net::sockets::socket options determine the behavior of the current xtd::net::sockets::socket. For an option with a bool data type, specify a nonzero value to enable the option, and a zero value to disable the option. For an option with an int data type, specify the appropriate value. xtd::net::sockets::socket options are grouped by level of protocol support.
        /// @remarks Listed below are the various xtd::net::sockets::socket options that can be set using this overload. These options are grouped by the appropriate xtd::net::sockets::socket_option_level. If you intend to set any of these options, be sure to use the appropriate xtd::net::sockets::socket_option_level for the optionLevel parameter. The option you choose to set must be specified in the option_ame parameter. If you want to get the current value of any of the options listed, use the xtd::net::sockets::socket::get_socket_option method.
        /// * xtd::net::sockets::socket_option_level::socket options that can be set using this overload:
        ///   * xtd::net::sockets::socket_option_name::broadcast
        ///   * xtd::net::sockets::socket_option_name::dont_linger
        ///   * xtd::net::sockets::socket_option_name::debug
        ///   * xtd::net::sockets::socket_option_name::error
        ///   * xtd::net::sockets::socket_option_name::keep_alive
        ///   * xtd::net::sockets::socket_option_name::out_of_band_inline
        ///   * xtd::net::sockets::socket_option_name::receive_buffer
        ///   * xtd::net::sockets::socket_option_name::receive_timeout
        ///   * xtd::net::sockets::socket_option_name::reuse_address
        ///   * xtd::net::sockets::socket_option_name::send_buffer
        ///   * xtd::net::sockets::socket_option_name::send_timeout
        ///   * xtd::net::sockets::socket_option_name::type
        /// * xtd::net::sockets::socket_option_level::ip options that can be set using this overload:
        ///   * xtd::net::sockets::socket_option_name::header_included
        ///   * xtd::net::sockets::socket_option_name::ip_options
        ///   * xtd::net::sockets::socket_option_name::ip_time_to_live
        ///   * xtd::net::sockets::socket_option_name::multicast_interface
        ///   * xtd::net::sockets::socket_option_name::multicast_loopback
        ///   * xtd::net::sockets::socket_option_name::multicast_time_to_live
        ///   * xtd::net::sockets::socket_option_name::use_loopback
        /// * xtd::net::sockets::socket_option_level::tcp options that can be set using this overload:
        ///   * xtd::net::sockets::socket_option_name::bsd_urgent
        ///   * xtd::net::sockets::socket_option_name::expedited
        ///   * xtd::net::sockets::socket_option_name::no_delay
        /// * xtd::net::sockets::socket_option_level::udp options that can be set using this overload:
        ///   * xtd::net::sockets::socket_option_name::checksum_coverage
        ///   * xtd::net::sockets::socket_option_name::no_checksum
        /// * xtd::net::sockets::socket_option_level::ip_v6 options that can be set using this overload:
        ///   * xtd::net::sockets::socket_option_name::hop_limit
        /// @remarks <br />For more information on these options, refer to the xtd::net::sockets::socket_option_name enumeration.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        void set_socket_option(xtd::net::sockets::socket_option_level socket_option_level, xtd::net::sockets::socket_option_name socket_option_name, int32_t option_value);
        /// @brief Sets the linger xtd::net::sockets::socket option to the specified integer value.
        /// @param option_value A value of the option.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        void set_socket_option(xtd::net::sockets::linger_option option_value);
        /// @brief Sets the linger xtd::net::sockets::socket option to the specified integer value.
        /// @param socket_option_name One of the xtd::net::sockets::socket_option_name values. Only xtd::net::sockets::socket_option_name::add_membership and xtd::net::sockets::socket_option_name::drop_membership values are accepted.
        /// @param option_value A value of the option.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        void set_socket_option(xtd::net::sockets::socket_option_name socket_option_name, xtd::net::sockets::multicast_option option_value);
        /// @brief Sets the linger xtd::net::sockets::socket option to the specified integer value.
        /// @param socket_option_name One of the xtd::net::sockets::socket_option_name values. Only xtd::net::sockets::socket_option_name::add_membership and xtd::net::sockets::socket_option_name::drop_membership values are accepted.
        /// @param option_value A value of the option.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        void set_socket_option(xtd::net::sockets::socket_option_name socket_option_name, xtd::net::sockets::ip_v6_multicast_option option_value);

        /// @brief Sets a socket option value using platform-specific level and name identifiers.
        /// @param socket_option_level The platform-defined option name.
        /// @param socket_option_name The platform-defined option name.
        /// @param option_value A pointer of the option value.
        /// @param size_option_value The size of the option value.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks In general, the xtd::net::sockets::socket::set_socket_option method should be used whenever setting a xtd::net::sockets::socket option.
        /// @remarks The SetRawSocketOption(Int32, Int32, ReadOnlySpan<byte>) method should be used only when SocketOptionLevel and SocketOptionName do not expose the required option.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        void set_raw_socket_option(int32_t socket_option_level, int32_t socket_option_name, intptr_t option_value, size_t option_value_size);
       
        /// @brief Disables sends and receives on a xtd::net::sockets::socket.
        /// @param how One of the xtd::net::sockets::socket_shutdown values that specifies the operation that will no longer be allowed.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks When using a connection-oriented xtd::net::sockets::socket, always call the xtd::net::sockets::socket::shutdown method before closing the xtd::net::sockets::socket::socket. This ensures that all data is sent and received on the connected socket before it is closed.
        /// @remarks Call the xtd::net::sockets::socket::close method to free all resources associated with the xtd::net::sockets::socket. Do not attempt to reuse the xtd::net::sockets::socket after closing.
        /// @remarks The following table shows the xtd::net::sockets::socket_shutdown enumeration values that are valid for the how parameter.
        /// | Value                                       | Description                                                           |
        /// |---------------------------------------------|-----------------------------------------------------------------------|
        /// | xtd::net::sockets::socket_shutdown::send    | Disable sending on this xtd::net::sockets::socket.                    |
        /// | xtd::net::sockets::socket_shutdown::receive | Disable receiving on this xtd::net::sockets::socket.                  |
        /// | xtd::net::sockets::socket_shutdown::both    | Disable both sending and receiving on this xtd::net::sockets::socket. |
        /// @remarks Setting how to xtd::net::sockets::socket_shutdown::send specifies that subsequent calls to xtd::net::sockets::socket::send are not allowed. If you are using a connectionless xtd::net::sockets::socket, specifying xtd::net::sockets::socket_shutdown::send will have no effect.
        /// @remarks Setting how to xtd::net::sockets::socket_shutdown::receive specifies that subsequent calls to xtd::net::sockets::socket::receive are not allowed. This has no effect on lower protocol layers. If you are using a connection-oriented protocol, the connection is terminated if either of the following conditions exist after a call to xtd::net::sockets::socket::shutdown :
        /// * Data is in the incoming network buffer waiting to be received.
        /// * More data has arrived.
        /// @remarks If you are using a connectionless protocol, datagrams are accepted and queued. However, if no buffer space is available for additional incoming datagrams, they will be discarded and no error will be returned to the sender. Using xtd::net::sockets::socket::shutdown on a connectionless xtd::net::sockets::socket is not recommended.
        /// @remarks Setting how to xtd::net::sockets::socket_shutdown::both disables both sends and receives as described above.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        void shutdown(xtd::net::sockets::socket_shutdown how);
        
      private:
        static xtd::net::sockets::socket_error get_last_error_();
        std::shared_ptr<xtd::iasync_result> begin_connect_(std::shared_ptr<xtd::net::end_point> remote_end_point, xtd::async_callback callback, const std::any& state);
        void bind_(std::shared_ptr<xtd::net::end_point> local_end_point);
        void connect_(std::shared_ptr<xtd::net::end_point> remote_end_point);
        struct data;
        
        std::shared_ptr<data> data_;
      };
    }
  }
}
