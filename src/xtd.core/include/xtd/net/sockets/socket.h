/// @file
/// @brief Contains xtd::net::sockets::socket class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <memory>
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
#include "socket_information.h"
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
      public:
        /// @brief Initializes a new instance of the xtd::net::sockets::socket class.
        socket() = default;
        
        /// @brief Initializes a new instance of the xtd::net::sockets::socket class for the specified socket handle.
        /// @param handle The socket handle for the socket that the xtd::net::sockets::socket object will encapsulate.
        /// @exception xtd::argument_exception The handle is invalid.
        /// @remarks This method populates the xtd::net::sockets::socket instance with data gathered from the supplied inttptr_tt. Different operating systems provide varying levels of support for querying a socket handle or file descriptor for its properties and configuration. Some of the public APIs on the resulting xtd::net::sockets::socket instance may differ based on operating system, such as xtd::net::sockets::socket::protocol_type and xtd::net::sockets::socket::blocking.
        socket(intptr_t handle);
        /// @brief Initializes a new instance of the xtd::net::sockets::socket class using the specified value returned from xtd::net::sockets::socket::duplicate_and_close.
        /// @param socket_informattion The socket information returned by xtd::net::sockets::socket::duplicate_and_close.
        /// @remarks If you call the xtd::net::sockets::socket constructor multiple times with the same byte array as the argument for each call, you will create multiple xtd::net::sockets::socket with the same underlying socket. This practice is strongly discouraged.
        socket(const xtd::net::sockets::socket_information& socket_informattion);
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
        socket(socket&& socket) = default;
        socket(const socket& socket) = default;
        ~socket();
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
        /// @return true if the xtd::net::sockets::socket doesn't allow datagram fragmentation; otherwise, false. The default is true.
        /// @exception xtd::not_suupported_exception The socket is not in the xtd::net::sockets::adddress_family::inter_network family.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        bool dont_fragment() const;
        /// @brief Sets a value that specifies whether the xtd::net::sockets::socket allows Internet Protocol (IP) datagrams to be fragmented.
        /// @param value true if the xtd::net::sockets::socket doesn't allow datagram fragmentation; otherwise, false. The default is true.
        /// @return This current instance.
        /// @exception xtd::not_suupported_exception The socket is not in the xtd::net::sockets::adddress_family::inter_network family.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        socket& dont_fragment(bool value);

        /// @brief Gets a value that specifies whether the xtd::net::sockets::socket is a dual-mode socket used for both IPv4 and IPv6.
        /// @return true if the xtd::net::sockets::socket is a dual-mode socket; otherwise, false. The default is true if the socket was created by calling the xtd::net::sockets::socket(xtd::net::sockets::socket_type, xtd::net::sockets::protocol_type) constructor and the operating system supports IPv6; otherwise, the default is false.
        /// @exception xtd::not_suupported_exception The socket is not in the xtd::net::sockets::adddress_family::inter_network_v6 family.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        bool dual_mode() const;
        /// @brief Sets a value that specifies whether the xtd::net::sockets::socket is a dual-mode socket used for both IPv4 and IPv6.
        /// @param value true if the xtd::net::sockets::socket is a dual-mode socket; otherwise, false. The default is true if the socket was created by calling the xtd::net::sockets::socket(xtd::net::sockets::socket_type, xtd::net::sockets::protocol_type) constructor and the operating system supports IPv6; otherwise, the default is false.
        /// @return This current instance.
        /// @exception xtd::not_suupported_exception The socket is not in the xtd::net::sockets::adddress_family::inter_network_v6 family.
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
        /// @remarks If xtd::net::sockets::socket::exclusive_address_use is true, the first use of the xtd::net::sockets::socket::bind method to attempt to bind to a particular port, regardless of Internet Protocol (IP) address, will succeed; all subsequent uses of the Bind method to attempt to bind to that port will fail until the original bound socket is destroyed.
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
        /// @remarks If xtd::net::sockets::socket::exclusive_address_use is true, the first use of the xtd::net::sockets::socket::bind method to attempt to bind to a particular port, regardless of Internet Protocol (IP) address, will succeed; all subsequent uses of the Bind method to attempt to bind to that port will fail until the original bound socket is destroyed.
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
        /// @remarks The following table describes the behavior of the xtd::net::sockets::socket::close method for the possible values of the xtd::net::sockets::inger_option::enabled property and the xtd::net::sockets::lingeer_option::linger_time property stored in the xtd::net::sockets::socket::linger_state property.
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
        /// @remarks The following table describes the behavior of the xtd::net::sockets::socket::close method for the possible values of the xtd::net::sockets::inger_option::enabled property and the xtd::net::sockets::lingeer_option::linger_time property stored in the xtd::net::sockets::socket::linger_state property.
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
        const std::unique_ptr<xtd::net::end_point>& local_end_point() const;
        
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
        /// @remarks The xtd::net::sockets::socket::protocol_type property is set when thextd::net::sockets::socket is created, and specifies the protocol used by that xtd::net::sockets::socket.
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
        /// @remarks The xtd::net::sockets::socket::remote_end_point is set after a call to either xtd::net::sockets::socket::accept or xtd::net::sockets::socke::connect. If you try to access this property earlier, xtd::net::sockets::socket::remote_end_point will throw a xtd::net::sockets::socket_exception. If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        const std::unique_ptr<xtd::net::end_point>& remote_end_point() const;

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
        /// @remarks This option applies to synchronous Send calls only. If the time-out period is exceeded, the Send method will throw a SocketException.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        int32_t send_timeout() const;
        /// @brief Sets a value that specifies the amount of time after which a synchronous xtd::net::sockets::socket::send call will time out.
        /// @param value The time-out value, in milliseconds. If you set the property with a value between 1 and 499, the value will be changed to 500. The default value is 0, which indicates an infinite time-out period. Specifying -1 also indicates an infinite time-out period.
        /// @return This current instance.
        /// @exception xtd::net::sockets::socket_exception This option is valid for a datagram socket only.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @exception xtd::argument_out_of_range_exception The value specified for a set operation is less than -1.
        /// @remarks This option applies to synchronous Send calls only. If the time-out period is exceeded, the Send method will throw a SocketException.
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
        
        /// @brief Closes the xtd::net::sockets::socket connection and releases all associated resources.
        /// @remarks The xtd::net::sockets::socket::close method closes the remote host connection and releases all resources associated with the xtd::net::sockets::socket. Upon closing, the xtd::net::sockets::socket::connected property is set to false.
        /// @remarks For connection-oriented protocols, it is recommended that you call xtd::net::sockets::socket::shutdown before calling the xtd::net::sockets::socket::close method. This ensures that all data is sent and received on the connected socket before it is closed.
        /// @remarks If you need to call xtd::net::sockets::socket::close without first calling xtd::net::sockets::socket::shutdown, you can ensure that data queued for outgoing transmission will be sent by setting the xtd::net::sockets::socket::dont_linger xtd::net::sockets::socket option to false and specifying a non-zero time-out interval. xtd::net::sockets::socket::close will then block until this data is sent or until the specified time-out expires. If you set xtd::net::sockets::socket::dont_linger to false and specify a zero time-out interval, xtd::net::sockets::socket::close releases the connection and automatically discards outgoing queued data.
        /// @note To set the xtd::net::sockets::socket::dont_linger socket option to false, create a xtd::net::sockets::linger_option, set the xtd::net::sockets::linger_option::enabled property to true, and set the xtd::net::sockets::linger_option::linger_time property to the desired time out period. Use this xtd::net::sockets::linger_option along with the xtd::net::sockets::socket::dont_linger socket option to call the xtd::net::sockets::socket::set_socket_linger_option method.
        void close();
        
        /// @brief Gets a socket option value using platform-specific level and name identifiers.
        /// @param socket_option_level The platform-defined option level.
        /// @param socket_option_name The platform-defined option name.
        /// @param option_value The pointer into which the retrieved option value should be stored.
        /// @return The number of bytes written into option_value for a successfully retrieved value.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exceptionxtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
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
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exceptionxtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        int32_t get_socket_option(xtd::net::sockets::socket_option_level socket_option_level, xtd::net::sockets::socket_option_name socket_option_name) const;
        /// @brief Returns the linger xtd::net::sockets::socket option, represented as xtd::net::sockets::linger_option.
        /// @return An xtd::net::sockets::linger_option that represents the value of the linger option.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks xtd::net::sockets::socket options determine the behavior of the current xtd::net::sockets::socket. Use this overload to get the xtd::net::sockets::socket_option_name::linger, xtd::net::sockets::socket_option_name::add_membership, and xtd::net::sockets::socket_option_name::xtd::net::sockets::socket_option_name::drop_membership xtd::net::sockets::socket options. For the xtd::net::sockets::socket_option_name::llinger option, use xtd::net::sockets::socket_option_level::socket for the option_level parameter. For xtd::net::sockets::socket_option_name::add_membership and xtd::net::sockets::socket_option_name::drop_membership, use xtd::net::sockets::socket_option_level::ip. If you want to set the value of any of the options listed above, use the xtd::net::sockets::socket_option_name::xtd::net::sockets::socket::set_socket_option method.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exceptionxtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        xtd::net::sockets::linger_option get_socket_linger_option() const;
        /// @brief Returns the multicast xtd::net::sockets::socket option, represented as xtd::net::sockets::multicast_option.
        /// @param socket_option_name One of the xtd::net::sockets::socket_option_name values. Only xtd::net::sockets::socket_option_name::add_membership and xtd::net::sockets::socket_option_name::drop_membership values are accexpted.
        /// @return An xtd::net::sockets::linger_option that represents the value of the multicast option.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exceptionxtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        xtd::net::sockets::multicast_option get_socket_multicast_option(xtd::net::sockets::socket_option_name socket_option_name) const;
        /// @brief Returns the multicast xtd::net::sockets::socket option, represented as xtd::net::sockets::ip_v6_multicast_option.
        /// @param socket_option_name One of the xtd::net::sockets::socket_option_name values. Only xtd::net::sockets::socket_option_name::add_membership and xtd::net::sockets::socket_option_name::drop_membership values are accexpted.
        /// @return An xtd::net::sockets::linger_option that represents the value of the multicast option.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exceptionxtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        xtd::net::sockets::ip_v6_multicast_option get_socket_ip_v6_multicast_option(xtd::net::sockets::socket_option_name socket_option_name) const;

        /// @brief Sets the specified xtd::net::sockets::socket option to the specified integer value.
        /// @param socket_option_level One of the xtd::net::sockets::socket_option_level values.
        /// @param socket_option_name One of the xtd::net::sockets::socket_option_name values.
        /// @param option_value A value of the option.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks xtd::net::sockets::socket options determine the behavior of the current xtd::net::sockets::socket. For an option with a Boolean data type, specify a nonzero value to enable the option, and a zero value to disable the option. For an option with an integer data type, specify the appropriate value. Socket options are grouped by level of protocol support.
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
        /// @param socket_option_name One of the xtd::net::sockets::socket_option_name values. Only xtd::net::sockets::socket_option_name::add_membership and xtd::net::sockets::socket_option_name::drop_membership values are accexpted.
        /// @param option_value A value of the option.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        void set_socket_option(xtd::net::sockets::socket_option_name socket_option_name, xtd::net::sockets::multicast_option option_value);
        /// @brief Sets the linger xtd::net::sockets::socket option to the specified integer value.
        /// @param socket_option_name One of the xtd::net::sockets::socket_option_name values. Only xtd::net::sockets::socket_option_name::add_membership and xtd::net::sockets::socket_option_name::drop_membership values are accexpted.
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
        /// @remarks In general, the SetSocketOption method should be used whenever setting a xtd::net::sockets::socket option.
        /// @remarks The SetRawSocketOption(Int32, Int32, ReadOnlySpan<Byte>) method should be used only when SocketOptionLevel and SocketOptionName do not expose the required option.
        /// @note If you receive a xtd::net::sockets::socket_exception exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        void set_raw_socket_option(int32_t socket_option_level, int32_t socket_option_name, intptr_t option_value, size_t option_value_size);
        
      private:
        static xtd::net::sockets::socket_error get_last_error();
        struct data {
          xtd::net::sockets::address_family address_family = xtd::net::sockets::address_family::unspecified;
          bool blocking = true;
          bool connected = false;
          intptr_t handle = 0;
          bool is_bound = false;
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
