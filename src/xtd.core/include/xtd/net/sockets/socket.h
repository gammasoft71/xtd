/// @file
/// @brief Contains xtd::net::socket class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include "../../core_export.h"
#include "../../argument_exception.h"
#include "../../as.h"
#include "../../not_implemented_exception.h"
#include "../../not_supported_exception.h"
#include "../../object.h"
#include "../../types.h"
#include "../../ustring.h"
#include "../end_point.h"
#include "../ip_address.h"
#include "address_family.h"
#include "linger_option.h"
#include "multicast_option.h"
#include "ip_v6_multicast_option.h"
#include "protocol_type.h"
#include "socket_error.h"
#include "socket_option_level.h"
#include "socket_option_name.h"
#include "socket_type.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief The xtd::net::sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
    namespace sockets {
      /// @brief Implements the Berkeley sockets interface.
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core net
      /// @remarks The xtd::net::sockets::socket class provides a rich set of methods and properties for network communications. The xtd::net::sockets::socket class allows you to perform both synchronous and asynchronous data transfer using any of the communication protocols listed in the xtd::net::sockets::protocol_type enumeration.
      /// @remarks The xtd::net::sockets::socket class follows the xttd naming pattern for asynchronous methods. For example, the synchronous xtd::net::sockets::receive method corresponds to the asynchronous xtd::net::sockets::begin_receive and xtd::net::sockets::end_receive methods.
      /// @remarks If your application only requires one thread during execution, use the following methods, which are designed for synchronous operation mode.
      /// * If you are using a connection-oriented protocol such as TCP, your server can listen for connections using the xtd::net::sockets::socket::listen method. The xtd::net::sockets::socket::xtd::net::sockets::socket::accept method processes any incoming connection requests and returns a xtd::net::sockets::socket that you can use to communicate data with the remote host. Use this returned xtd::net::sockets::socket to call the xtd::net::sockets::socket::send or xtd::net::sockets::socket::receive method. Call the xtd::net::sockets::socket::bind method prior to calling the xtd::net::sockets::socket::listen method if you want to specify the local IP address and port number. Use a port number of zero if you want the underlying service provider to assign a free port for you. If you want to connect to a listening host, call the xtd::net::sockets::socket::connect method. To communicate data, call the xtd::net::sockets::socket::send or xtd::net::sockets::socket::receive method.
      /// * If you are using a connectionless protocol such as UDP, you do not need to listen for connections at all. Call the xtd::net::sockets::socket::receiveF_from method to accept any incoming datagrams. Use the xtd::net::sockets::socket::send_to method to send datagrams to a remote host.
      /// @remarks To process communications using separate threads during execution, use the following methods, which are designed for asynchronous operation mode.
      /// * If you are using a connection-oriented protocol such as TCP, use the xtd::net::sockets::socket, xtd::net::sockets::socket::begin_connect, and xtd::net::sockets::socket::end_connect methods to connect with a listening host. Use the xtd::net::sockets::socket::begin_send and xtd::net::sockets::socket::end_send or xtd::net::sockets::socket::begin_receive and xtd::net::sockets::socket::end_receive methods to communicate data asynchronously. Incoming connection requests can be processed using xtd::net::sockets::socket::begin_accept and xtd::net::sockets::socket::end_accept.
      /// * If you are using a connectionless protocol such as UDP, you can use xtd::net::sockets::socket::begin_send_to and xtd::net::sockets::socket::end_send_tto to send datagrams, and xtd::net::sockets::socket::begin_receive_from and xtd::net::sockets::socket::end_receive_from to receive datagrams.
      /// @remarks If you perform multiple asynchronous operations on a socket, they do not necessarily complete in the order in which they are started.
      /// @remarks When you are finished sending and receiving data, use the xtd::net::sockets::socket::shutdown method to disable the xtd::net::sockets::socket. After calling xtd::net::sockets::socket::shutdown, call the xtd::net::sockets::socket::close method to release all resources associated with the xtd::net::sockets::socket.
      /// @remarks The xtd::net::sockets::socket class allows you to configure your xtd::net::sockets::socket using the xtd::net::sockets::socket::set_socket_option method. Retrieve these settings using the xtd::net::sockets::socket::get_socket_option method.
      /// @note If you are writing a relatively simple application and do not require maximum performance, consider using xtd::net::sockets::tcp_client, xtd::net::sockets::tcp_listener, and xtd::net::sockets::udp_client. These classes provide a simpler and more user-friendly interface to xtd::net::sockets::socket communications.
      class core_export_ socket : public xtd::object {
      public:
        /// @brief Initializes a new instance of the xtd::net::sockets::socket class.
        socket() = default;
        
        socket(xtd::net::sockets::socket_type socket_type, xtd::net::sockets::protocol_type protocol_type);
        socket(xtd::net::sockets::address_family address_family, xtd::net::sockets::socket_type socket_type, xtd::net::sockets::protocol_type protocol_type);

        /// @cond
        socket(socket&& socket) = default;
        socket(const socket& socket) = default;
        socket& operator=(const socket&) = default;
        friend std::ostream& operator <<(std::ostream& os, const socket& mo) noexcept {return os << mo.to_string();}
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
        /// @return true if the Socket doesn't allow datagram fragmentation; otherwise, false. The default is true.
        /// @exception xtd::not_suupported_exception The socket is not in the xtd::net::sockets::adddress_family::inter_network family.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        bool dont_fragment() const;
        /// @brief Sets a value that specifies whether the xtd::net::sockets::socket allows Internet Protocol (IP) datagrams to be fragmented.
        /// @param value true if the Socket doesn't allow datagram fragmentation; otherwise, false. The default is true.
        /// @return This current instance.
        /// @exception xtd::not_suupported_exception The socket is not in the xtd::net::sockets::adddress_family::inter_network family.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        socket& dont_fragment(bool value);

        /// @brief Gets a value that specifies whether the xtd::net::sockets::socket is a dual-mode socket used for both IPv4 and IPv6.
        /// @return true if the xtd::net::sockets::socket is a dual-mode socket; otherwise, false. The default is true if the socket was created by calling the xtd::net::sockets::socket(xtd::net::sockets::socket_type, xtd::net::sockets::protocol_type) constructor and the operating system supports IPv6; otherwise, the default is false.
        /// @exception xtd::not_suupported_exception The socket is not in the xtd::net::sockets::adddress_family::inter_network_v6 family.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        bool dual_mode() const;
        /// @brief SGets a value that specifies whether the xtd::net::sockets::socket is a dual-mode socket used for both IPv4 and IPv6.
        /// @param value true if the xtd::net::sockets::socket is a dual-mode socket; otherwise, false. The default is true if the socket was created by calling the xtd::net::sockets::socket(xtd::net::sockets::socket_type, xtd::net::sockets::protocol_type) constructor and the operating system supports IPv6; otherwise, the default is false.
        /// @return This current instance.
        /// @exception xtd::not_suupported_exception The socket is not in the xtd::net::sockets::adddress_family::inter_network_v6 family.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        socket& dual_mode(bool value);
        
        bool enable_broadcast() const;
        socket& enable_broadcast(bool value);
        
        intptr_t handle() const noexcept;

        bool os_supports_ip_v4() const noexcept;
        
        bool os_supports_ip_v6() const noexcept;

        /// @brief Returns the value of a specified xtd::net::sockets::socket option, represented as integer.
        /// @param socket_option_level One of the xtd::net::sockets::socket_option_level values.
        /// @param socket_option_name One of the xtd::net::sockets::socket_option_name values.
        /// @return An object that represents the value of the option.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks xtd::net::sockets::socket options determine the behavior of the current Socket. Use this overload to get the xtd::net::sockets::socket_option_name::linger, xtd::net::sockets::socket_option_name::add_membership, and xtd::net::sockets::socket_option_name::xtd::net::sockets::socket_option_name::drop_membership xtd::net::sockets::socket options. For the xtd::net::sockets::socket_option_name::llinger option, use xtd::net::sockets::socket_option_level::socket for the option_level parameter. For xtd::net::sockets::socket_option_name::add_membership and xtd::net::sockets::socket_option_name::drop_membership, use xtd::net::sockets::socket_option_level::ip. If you want to set the value of any of the options listed above, use the xtd::net::sockets::socket_option_name::xtd::net::sockets::socket::set_socket_option method.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exceptionxtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        template<typename value_t>
        value_t get_socket_option(xtd::net::sockets::socket_option_level socket_option_level, xtd::net::sockets::socket_option_name socket_option_name) const {
          throw xtd::argument_exception(csf_);
        }
        
        /// @brief Returns the value of a specified xtd::net::sockets::socket option, represented as integer.
        /// @param socket_option_level One of the xtd::net::sockets::socket_option_level values.
        /// @param socket_option_name One of the xtd::net::sockets::socket_option_name values.
        /// @return An object that represents the value of the option.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks xtd::net::sockets::socket options determine the behavior of the current Socket. Use this overload to get the xtd::net::sockets::socket_option_name::linger, xtd::net::sockets::socket_option_name::add_membership, and xtd::net::sockets::socket_option_name::xtd::net::sockets::socket_option_name::drop_membership xtd::net::sockets::socket options. For the xtd::net::sockets::socket_option_name::llinger option, use xtd::net::sockets::socket_option_level::socket for the option_level parameter. For xtd::net::sockets::socket_option_name::add_membership and xtd::net::sockets::socket_option_name::drop_membership, use xtd::net::sockets::socket_option_level::ip. If you want to set the value of any of the options listed above, use the xtd::net::sockets::socket_option_name::xtd::net::sockets::socket::set_socket_option method.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exceptionxtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        template<>
        int32_t get_socket_option<int32_t>(xtd::net::sockets::socket_option_level socket_option_level, xtd::net::sockets::socket_option_name socket_option_name) const {
          return get_socket_option(socket_option_level, socket_option_name);
        }
        
        /// @brief Returns the value of a specified xtd::net::sockets::socket option, represented as integer.
        /// @param socket_option_level One of the xtd::net::sockets::socket_option_level values.
        /// @param socket_option_name One of the xtd::net::sockets::socket_option_name values.
        /// @return An object that represents the value of the option.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks xtd::net::sockets::socket options determine the behavior of the current Socket. Use this overload to get the xtd::net::sockets::socket_option_name::linger, xtd::net::sockets::socket_option_name::add_membership, and xtd::net::sockets::socket_option_name::xtd::net::sockets::socket_option_name::drop_membership xtd::net::sockets::socket options. For the xtd::net::sockets::socket_option_name::llinger option, use xtd::net::sockets::socket_option_level::socket for the option_level parameter. For xtd::net::sockets::socket_option_name::add_membership and xtd::net::sockets::socket_option_name::drop_membership, use xtd::net::sockets::socket_option_level::ip. If you want to set the value of any of the options listed above, use the xtd::net::sockets::socket_option_name::xtd::net::sockets::socket::set_socket_option method.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exceptionxtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        template<>
        xtd::net::sockets::linger_option get_socket_option<xtd::net::sockets::linger_option>(xtd::net::sockets::socket_option_level socket_option_level, xtd::net::sockets::socket_option_name socket_option_name) const {
          throw xtd::not_implemented_exception(csf_);
        }
        
        /// @brief Returns the value of a specified xtd::net::sockets::socket option, represented as integer.
        /// @param socket_option_level One of the xtd::net::sockets::socket_option_level values.
        /// @param socket_option_name One of the xtd::net::sockets::socket_option_name values.
        /// @return An object that represents the value of the option.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks xtd::net::sockets::socket options determine the behavior of the current Socket. Use this overload to get the xtd::net::sockets::socket_option_name::linger, xtd::net::sockets::socket_option_name::add_membership, and xtd::net::sockets::socket_option_name::xtd::net::sockets::socket_option_name::drop_membership xtd::net::sockets::socket options. For the xtd::net::sockets::socket_option_name::llinger option, use xtd::net::sockets::socket_option_level::socket for the option_level parameter. For xtd::net::sockets::socket_option_name::add_membership and xtd::net::sockets::socket_option_name::drop_membership, use xtd::net::sockets::socket_option_level::ip. If you want to set the value of any of the options listed above, use the xtd::net::sockets::socket_option_name::xtd::net::sockets::socket::set_socket_option method.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exceptionxtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        template<>
        xtd::net::sockets::multicast_option get_socket_option<xtd::net::sockets::multicast_option>(xtd::net::sockets::socket_option_level socket_option_level, xtd::net::sockets::socket_option_name socket_option_name) const {
          throw xtd::not_implemented_exception(csf_);
        }
        
        /// @brief Returns the value of a specified xtd::net::sockets::socket option, represented as integer.
        /// @param socket_option_level One of the xtd::net::sockets::socket_option_level values.
        /// @param socket_option_name One of the xtd::net::sockets::socket_option_name values.
        /// @return An object that represents the value of the option.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks xtd::net::sockets::socket options determine the behavior of the current Socket. Use this overload to get the xtd::net::sockets::socket_option_name::linger, xtd::net::sockets::socket_option_name::add_membership, and xtd::net::sockets::socket_option_name::xtd::net::sockets::socket_option_name::drop_membership xtd::net::sockets::socket options. For the xtd::net::sockets::socket_option_name::llinger option, use xtd::net::sockets::socket_option_level::socket for the option_level parameter. For xtd::net::sockets::socket_option_name::add_membership and xtd::net::sockets::socket_option_name::drop_membership, use xtd::net::sockets::socket_option_level::ip. If you want to set the value of any of the options listed above, use the xtd::net::sockets::socket_option_name::xtd::net::sockets::socket::set_socket_option method.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exceptionxtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        template<>
        xtd::net::sockets::ip_v6_multicast_option get_socket_option<xtd::net::sockets::ip_v6_multicast_option>(xtd::net::sockets::socket_option_level socket_option_level, xtd::net::sockets::socket_option_name socket_option_name) const {
          throw xtd::not_implemented_exception(csf_);
        }

        /// @brief Returns the value of a specified xtd::net::sockets::socket option, represented as integer.
        /// @param socket_option_level One of the xtd::net::sockets::socket_option_level values.
        /// @param socket_option_name One of the xtd::net::sockets::socket_option_name values.
        /// @return An object that represents the value of the option.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks xtd::net::sockets::socket options determine the behavior of the current Socket. Use this overload to get the xtd::net::sockets::socket_option_name::linger, xtd::net::sockets::socket_option_name::add_membership, and xtd::net::sockets::socket_option_name::xtd::net::sockets::socket_option_name::drop_membership xtd::net::sockets::socket options. For the xtd::net::sockets::socket_option_name::llinger option, use xtd::net::sockets::socket_option_level::socket for the option_level parameter. For xtd::net::sockets::socket_option_name::add_membership and xtd::net::sockets::socket_option_name::drop_membership, use xtd::net::sockets::socket_option_level::ip. If you want to set the value of any of the options listed above, use the xtd::net::sockets::socket_option_name::xtd::net::sockets::socket::set_socket_option method.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exceptionxtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        int32_t get_socket_option(xtd::net::sockets::socket_option_level socket_option_level, xtd::net::sockets::socket_option_name socket_option_name) const;
        
        /// @brief Sets the specified Socket option to the specified integer value.
        /// @param socket_option_level One of the xtd::net::sockets::socket_option_level values.
        /// @param socket_option_name One of the xtd::net::sockets::socket_option_name values.
        /// @param option_value A value of the option.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks xtd::net::sockets::socket options determine the behavior of the current Socket. For an option with a Boolean data type, specify a nonzero value to enable the option, and a zero value to disable the option. For an option with an integer data type, specify the appropriate value. Socket options are grouped by level of protocol support.
        /// @remarks xtd::net::sockets::socket options are grouped by level of protocol support.
        /// @remarks Listed below are the various Socket options that can be set using this overload. These options are grouped by the appropriate SocketOptionLevel value. If you intend to set any of these options, be sure to use the appropriate SocketOptionLevel value for the optionLevel parameter. The option you choose to set must be specified in the optionName parameter. If you want to get the current value of any of the options listed, use the GetSocketOption method.
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
        
        /// @brief Sets the specified Socket option to the specified integer value.
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

      private:
        static xtd::net::sockets::socket_error get_last_error();
        struct data {
          xtd::net::sockets::address_family address_family = xtd::net::sockets::address_family::unspecified;
          bool blocking = true;
          bool bound = false;
          bool connected = false;
          intptr_t handle = 0;
          bool listening = false;
          std::unique_ptr<xtd::net::end_point> local_end_point;
          xtd::net::sockets::protocol_type protocol_type = xtd::net::sockets::protocol_type::unspecified;
          std::unique_ptr<xtd::net::end_point> remote_end_point;
          xtd::net::sockets::socket_type socket_type = xtd::net::sockets::socket_type::unknown;
        };
        
        std::shared_ptr<data> data_ = std::make_shared<data>();
      };
    }
  }
}
