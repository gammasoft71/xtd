/// @file
/// @brief Contains xtd::net::sockets::tcp_client class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include "../../object.h"
#include "../../ustring.h"
#include "../ip_end_point.h"
#include "network_stream.h"
#include "socket.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief The xtd::net::sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
    namespace sockets {
      /// @cond
      class tcp_listener;
      /// @endcond

      /// @brief Provides client connections for TCP network services.
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core net
      /// @remarks The xtd::net::sockets::tcp_client class provides simple methods for connecting, sending, and receiving stream data over a network in synchronous blocking mode.
      /// @remarks In order for xtd::net::sockets::tcp_client to connect and exchange data, a TcpListener or xtd::net::sockets::socket created with the TCP ProtocolType must be listening for incoming connection requests. You can connect to this listener in one of the following two ways:
      /// * Create a xtd::net::sockets::tcp_client and call one of the three available xtd::net::sockets::tcp_client::connect methods.
      /// * Create a xtd::net::sockets::tcp_client using the host name and port number of the remote host. This constructor will automatically attempt a connection.
      /// @note If you want to send connectionless datagrams in synchronous blocking mode, use the xtd::net::sockets::udp_client class.
      /// @par Examples
      /// The following example shows how to use IPv4 xtd::net::sockets::tcp_client class with xtd::net::sockets::network_stream, xtd::net::sockets::socket, xtd::io::stream_reader and xtd::io::stream_writer classes.
      /// @include tcp_client_ip_v4.cpp
      /// @par Examples
      /// The following example shows how to use IPv6 xtd::net::sockets::tcp_client class with xtd::net::sockets::network_stream, xtd::net::sockets::socket, xtd::io::stream_reader and xtd::io::stream_writer classes.
      /// @include tcp_client_ip_v6.cpp
      class tcp_client : public xtd::object {
      public:
        /// @brief Initializes a new instance of the xtd::net::sockets::tcp_client class.
        /// @remarks This constructor creates a new xtd::net::sockets::tcp_client and allows the underlying service provider to assign the most appropriate local IP address and port number. You must first call the xtd::net::sockets::tcp_client::connect method before sending and receiving data.
        /// @note This constructor works only with IPv4 address types.
        tcp_client();
        /// @brief Initializes a new instance of the xtd::net::sockets::tcp_client class and binds it to the specified local endpoint.
        /// @param local_end_point The xtd::net::ip_end_point to which you bind the TCP xtd::net::sockets::socket.
        /// @remarks This constructor creates a new xtd::net::sockets::tcp_client and binds it to the xtd::net::ip_end_point specified by the local_end_point parameter. Before you call this constructor, you must create an xtd::net::ip_end_point using the IP address and port number from which you intend to send and receive data. You do not need to specify a local IP address and port number before connecting and communicating. If you create a xtd::net::sockets::tcp_client using any other constructor, the underlying service provider will assign the most appropriate local IP address and port number.
        /// @remarks You must call the xtd::net::sockets::tcp_client::connect method before sending and receiving data.
        tcp_client(const xtd::net::ip_end_point& end_point);
        /// @brief The xtd::net::sockets::address_family of the IP protocol.
        /// @exception xtd::argument_exception The family parameter is not equal to xtd::net::sockects::address_family::inter_network -or- The family parameter is not equal to xtd::net::sockects::address_family::inter_network_v6.
        tcp_client(xtd::net::sockets::address_family address_family);
        /// @brief Initializes a new instance of the xtd::net::sockets::tcp_client class and connects to the specified port on the specified host.
        /// @param hostname The DNS name of the remote host to which you intend to connect.
        /// @param port The port number of the remote host to which you intend to connect.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks This constructor creates a new xtd::net::sockets::tcp_client and makes a synchronous connection attempt to the provided host name and port number. The underlying service provider will assign the most appropriate local IP address and port number. xtd::net::sockets::tcp_client will block until it either connects or fails. This constructor allows you to initialize, resolve the DNS host name, and connect in one convenient step.
        /// @remarks If IPv6 is enabled and the xtd::net::sockets::tcp_client method is called to connect to a host that resolves to both IPv6 and IPv4 addresses, the connection to the IPv6 address will be attempted first before the IPv4 address. This may have the effect of delaying the time to establish the connection if the host is not listening on the IPv6 address.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        tcp_client(const xtd::ustring& hostname, uint16_t port);

        /// @cond
        tcp_client(tcp_client&&) = default;
        tcp_client(const tcp_client&) = default;
        ~tcp_client();
        tcp_client& operator=(const tcp_client&) = default;
        friend std::ostream& operator <<(std::ostream& os, const tcp_client& tc) noexcept {return os << tc.to_string();}
        bool operator==(const tcp_client& s) const {return data_ == s.data_;};
        bool operator!=(const tcp_client& s) const {return !operator==(s);};
        /// @endcond

        /// @brief Gets the amount of data that has been received from the network and is available to be read.
        /// @return The number of bytes of data received from the network and available to be read.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket. See the Remarks section for more information.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks available is a way to determine whether data is queued for reading. If data is available, call xtd::iostream::read to get the data.
        /// @remarks The available data is the total amount of data queued in the network buffer for reading. If no data is queued in the network buffer, available returns 0.
        /// @remarks If the remote host shuts down or closes the connection, available may throw a xtd::net::sockets::socket_exception. If you receive a xtd::net::sockets::socket_exception, use xtd::net::sockets::socket_exception.ErrorCode to obtain the specific error code.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        size_t available() const;
        
        /// @brief Gets the underlying network xtd::net::sockets::socket
        /// @return The underlying network xtd::net::sockets::socket
        /// @remarks xtd::net::sockets::tcp_client creates a xtd::net::sockets::socket to send and receive data over a network. Classes deriving from xtd::net::sockets::tcp_client can use this property to get or set this xtd::net::sockets::socket.
        /// @remarks Use the underlying xtd::net::sockets::socket returned from xtd::net::sockets::tcp_client::client if you require access beyond that which xtd::net::sockets::tcp_client provides.
        /// @remarks You can also use xtd::net::sockets::tcp_client::client to set the underlying xtd::net::sockets::socket to an existing xtd::net::sockets::socket. This might be useful if you want to take advantage of the simplicity
        /// @remarks of xtd::net::sockets::tcp_client using a pre-existing xtd::net::sockets::socket.
        xtd::net::sockets::socket client() const noexcept;
        /// @brief Sets the underlying network xtd::net::sockets::socket
        /// @param value The underlying network xtd::net::sockets::socket
        /// @return This current instance.
        /// @remarks xtd::net::sockets::tcp_client creates a xtd::net::sockets::socket to send and receive data over a network. Classes deriving from xtd::net::sockets::tcp_client can use this property to get or set this xtd::net::sockets::socket.
        /// @remarks Use the underlying xtd::net::sockets::socket returned from xtd::net::sockets::tcp_client::client if you require access beyond that which xtd::net::sockets::tcp_client provides.
        /// @remarks You can also use xtd::net::sockets::tcp_client::client to set the underlying xtd::net::sockets::socket to an existing xtd::net::sockets::socket. This might be useful if you want to take advantage of the simplicity
        /// @remarks of xtd::net::sockets::tcp_client using a pre-existing xtd::net::sockets::socket.
        tcp_client& client(const xtd::net::sockets::socket& value) noexcept;

        /// @brief Gets a value indicating whether the underlying xtd::net::sockets::socket for a xtd::net::sockets::tcp_client is connected to a remote host.
        /// @return bool true if the xtd::net::sockets::tcp_client::client was connected to a remote resource as of the most recent operation; otherwise, false.
        /// @remarks The xtd::net::sockets::tcp_client::client::connected property gets the connection state of the xtd::net::sockets::tcp_client::client socket as of the last I/O operation. When it returns false,
        /// @remarks the xtd::net::sockets::tcp_client::client socket was either never connected, or is no longer connected.Because the xtd::net::sockets::tcp_client::client::connected property only reflects the state
        /// @remarks of the connection as of the most recent operation, you should attempt to send or receive a message to determine the current state.
        /// @remarks After the message send fails, this property no longer returns true. Note that this behavior is by design.
        /// @remarks You cannot reliably test the state of the connection because, in the time between the test and a send/receive,
        /// @remarks the connection could have been lost. Your code should assume the socket is connected, and gracefully handle failed transmissions.
        bool connected() const noexcept;
        
        /// @brief Gets a bool value that specifies whether the xtd::net::sockets::tcp_client allows only one client to use a port.
        /// @return bool true if the xtd::net::sockets::tcp_client allows only one client to use a specific port; otherwise, false.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket. See the Remarks section for more information.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks By default, multiple clients can use a specific port; however, only one of the clients can perform operations on the network traffic sent to the port.
        /// @remarks You can use the xtd::net::sockets::tcp_client::client::exclusive_address_use property to prevent multiple clients from using a specific port.
        /// @remarks This property must be set before the underlying socket is bound to a client port. If you call xtd::net::sockets::tcp_client::connect, xtd::net::sockets::tcp_client::client::begin_connect, xtd::net::sockets::tcp_client(xtd::net::ip_end_point), or xtd::net::sockets::tcp_client(xtd::ustring, uint16_t), the client port is bound as a side effect of the method, and you cannot subsequently set the xtd::net::sockets::tcp_client::client::exclusive_address_use property.
        bool exclusive_address_use() const;
        /// @brief Sets a bool value that specifies whether the xtd::net::sockets::tcp_client allows only one client to use a port.
        /// @param value bool true if the xtd::net::sockets::tcp_client allows only one client to use a specific port; otherwise, false.
        /// @return This current instance.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket. See the Remarks section for more information.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks By default, multiple clients can use a specific port; however, only one of the clients can perform operations on the network traffic sent to the port.
        /// @remarks You can use the xtd::net::sockets::tcp_client::client::exclusive_address_use property to prevent multiple clients from using a specific port.
        /// @remarks This property must be set before the underlying socket is bound to a client port. If you call xtd::net::sockets::tcp_client::connect, xtd::net::sockets::tcp_client::client::begin_connect, xtd::net::sockets::tcp_client(xtd::net::ip_end_point), or xtd::net::sockets::tcp_client(xtd::ustring, uint16_t), the client port is bound as a side effect of the method, and you cannot subsequently set the xtd::net::sockets::tcp_client::client::exclusive_address_use property.
        tcp_client& exclusive_address_use(bool value);
        
        /// @brief Gets a value that specifies whether the xtd::net::sockets::socket will delay closing a socket in an attempt to send all pending data.
        /// @return A xtd::net::sockets::linger_option that specifies how to linger while closing a socket.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket. See the Remarks section for more information.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks The xtd::net::sockets::tcp_client::linger_state property changes the way xtd::net::sockets::tcp_client::close method behaves. This property when set modifies the conditions under which the connection can be reset by Winsock. Connection resets can still occur based on the IP protocol behavior.
        /// @remarks This property controls the length of time that the TCP connection will remain open after a call to xtd::net::sockets::tcp_client::close when data remains to be sent. When you call the Write method, data is placed in the outgoing network buffer. This property can be used to ensure that this data is sent to the remote host before the xtd::net::sockets::tcp_client::close method drops the connection.
        /// @remarks To enable lingering, create a xtd::net::sockets::linger_option instance containing the desired values, and set the xtd::net::sockets::tcp_client::linger_state property to this instance.
        /// @remarks The following table describes the behavior of the xtd::net::sockets::tcp_client::close method for the possible values of the xtd::net::sockets::linger_option::enabled property and the xtd::net::sockets::linger_option::linger_time property stored in the xtd::net::sockets::tcp_client::linger_state property.
        /// | xtd::net::sockets::linger_option::enabled | xtd::net::sockets::linger_option::linger_time | Behavior                                                                                                                          |
        /// |-------------------------------------------|-----------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------|
        /// | false (disabled), the default value       | The time-out is not applicable, (default).    | Attempts to send pending data until the default IP protocol time-out expires.                                                     |
        /// | true (enabled)                            | A nonzero time-out                            | Attempts to send pending data until the specified time-out expires, and if the attempt fails, then Winsock resets the connection. |
        /// | true (enabled)                            | A zero timeout.                               | Discards any pending data and Winsock resets the connection.                                                                      |
        /// @remarks The IP stack computes the default IP protocol time-out period to use based on the round trip time of the connection. In most cases, the time-out computed by the stack is more relevant than one defined by an application.
        /// @remarks This is the default behavior for a socket when the xtd::net::sockets::tcp_client::linger_state property is not set.
        /// @remarks When the xtd::net::sockets::linger_option::linger_time property stored in the xtd::net::sockets::tcp_client::linger_state property is set greater than the default IP protocol time-out, the default IP protocol time-out will still apply and virtual.
        xtd::net::sockets::linger_option linger_state() const;
        /// @brief Sets a value that specifies whether the xtd::net::sockets::socket will delay closing a socket in an attempt to send all pending data.
        /// @param value A xtd::net::sockets::linger_option that specifies how to linger while closing a socket.
        /// @return This current instance.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket. See the Remarks section for more information.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks The xtd::net::sockets::tcp_client::linger_state property changes the way xtd::net::sockets::tcp_client::close method behaves. This property when set modifies the conditions under which the connection can be reset by Winsock. Connection resets can still occur based on the IP protocol behavior.
        /// @remarks This property controls the length of time that the TCP connection will remain open after a call to xtd::net::sockets::tcp_client::close when data remains to be sent. When you call the Write method, data is placed in the outgoing network buffer. This property can be used to ensure that this data is sent to the remote host before the xtd::net::sockets::tcp_client::close method drops the connection.
        /// @remarks To enable lingering, create a xtd::net::sockets::linger_option instance containing the desired values, and set the xtd::net::sockets::tcp_client::linger_state property to this instance.
        /// @remarks The following table describes the behavior of the xtd::net::sockets::tcp_client::close method for the possible values of the xtd::net::sockets::linger_option::enabled property and the xtd::net::sockets::linger_option::linger_time property stored in the xtd::net::sockets::tcp_client::linger_state property.
        /// | xtd::net::sockets::linger_option::enabled | xtd::net::sockets::linger_option::linger_time | Behavior                                                                                                                          |
        /// |-------------------------------------------|-----------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------|
        /// | false (disabled), the default value       | The time-out is not applicable, (default).    | Attempts to send pending data until the default IP protocol time-out expires.                                                     |
        /// | true (enabled)                            | A nonzero time-out                            | Attempts to send pending data until the specified time-out expires, and if the attempt fails, then Winsock resets the connection. |
        /// | true (enabled)                            | A zero timeout.                               | Discards any pending data and Winsock resets the connection.                                                                      |
        /// @remarks The IP stack computes the default IP protocol time-out period to use based on the round trip time of the connection. In most cases, the time-out computed by the stack is more relevant than one defined by an application.
        /// @remarks This is the default behavior for a socket when the xtd::net::sockets::tcp_client::linger_state property is not set.
        /// @remarks When the xtd::net::sockets::linger_option::linger_time property stored in the xtd::net::sockets::tcp_client::linger_state property is set greater than the default IP protocol time-out, the default IP protocol time-out will still apply and virtual.
        tcp_client& linger_state(const xtd::net::sockets::linger_option& value);

        /// @brief Gets a value that disables a delay when send or receive buffers are not full.
        /// @return true if the delay is disabled; otherwise, false. The default value is false.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket. See the Remarks section for more information.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks When xtd::net::sockets::tcp_client::no_delay is false, a xtd::net::sockets::tcp_client does not send a packet over the network until it has collected a significant amount of outgoing data.
        bool no_delay() const;
        /// @brief Sets a value that disables a delay when send or receive buffers are not full.
        /// @param value true if the delay is disabled; otherwise, false. The default value is false.
        /// @return This current instance.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket. See the Remarks section for more information.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks When xtd::net::sockets::tcp_client::no_delay is false, a xtd::net::sockets::tcp_client does not send a packet over the network until it has collected a significant amount of outgoing data.
        tcp_client& no_delay(bool value);
        
        /// @brief Gets the size of the receive buffer.
        /// @return A size_t that contains the size, in bytes, of the receive buffer. The default is 8192.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket. See the Remarks section for more information.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks The xtd::net::sockets::tcp_client::receive_buffer_size property gets or sets the number of bytes that you are expecting to store in the receive buffer for each read operation. This property actually manipulates the network buffer space allocated for receiving incoming data.
        /// @remarks Your network buffer should be at least as large as your application buffer to ensure that the desired data will be available when you call the std::iostream::read method. Use the xtd::net::sockets::tcp_client::receive_buffer_size property to set this size. If your application will be receiving bulk data, you should pass the Read method a very large application buffer.
        /// @remarks If the network buffer is smaller than the amount of data you request in the std::iostream::read method, you will not be able to retrieve the desired amount of data in one read operation. This incurs the overhead of additional calls to the std::iostream::read method.
        size_t receive_buffer_size() const;
        /// @brief Sets the size of the receive buffer.
        /// @param value A size_t that contains the size, in bytes, of the receive buffer. The default is 8192.
        /// @return This current instance.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket. See the Remarks section for more information.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks The xtd::net::sockets::tcp_client::receive_buffer_size property gets or sets the number of bytes that you are expecting to store in the receive buffer for each read operation. This property actually manipulates the network buffer space allocated for receiving incoming data.
        /// @remarks Your network buffer should be at least as large as your application buffer to ensure that the desired data will be available when you call the std::iostream::read method. Use the xtd::net::sockets::tcp_client::receive_buffer_size property to set this size. If your application will be receiving bulk data, you should pass the Read method a very large application buffer.
        /// @remarks If the network buffer is smaller than the amount of data you request in the std::iostream::read method, you will not be able to retrieve the desired amount of data in one read operation. This incurs the overhead of additional calls to the std::iostream::read method.
        tcp_client& receive_buffer_size(size_t value);
        
        /// @brief Gets the amount of time a xtd::net::sockets::tcp_client will wait to receive data once a read operation is initiated.
        /// @return The time-out value of the connection in milliseconds. The default value is 0.
        /// @remarks The xtd::net::sockets::tcp_client::receive_timeout property determines the amount of time that the Read method will block until it is able to receive data. This time is measured in milliseconds. If the time-out expires before Read successfully completes, xtd::net::sockets::tcp_client throws a xtd::io::io_exception. There is no time-out by default.
        int32_t receive_timeout() const;
        /// @brief Sets the amount of time a xtd::net::sockets::tcp_client will wait to receive data once a read operation is initiated.
        /// @param value The time-out value of the connection in milliseconds. The default value is 0.
        /// @return This current instance.
        /// @remarks The xtd::net::sockets::tcp_client::receive_timeout property determines the amount of time that the Read method will block until it is able to receive data. This time is measured in milliseconds. If the time-out expires before Read successfully completes, xtd::net::sockets::tcp_client throws a xtd::io::io_exception. There is no time-out by default.
        tcp_client& receive_timeout(int32_t value);
        
        /// @brief Gets the size of the send buffer.
        /// @return The size of the send buffer, in bytes. The default value is 8192 bytes.
        /// @remarks The xtd::net::sockets::tcp_client::send_buffer_size property gets or sets the number of bytes that you are expecting to send in each call to the std::iostream::write method. This property actually manipulates the network buffer space allocated for send operation.
        /// @remarks Your network buffer should be at least as large as your application buffer to ensure that the desired data will be stored and sent in one operation. Use the xtd::net::sockets::tcp_client::send_buffer_size property to set this size. If your application will be sending bulk data, you should pass the std::iostream::write method a very large application buffer.
        /// @remarks If the network buffer is smaller than the amount of data you provide the std::iostream::write method, several network send operations will be performed for every call you make to the std::iostream::write method. You can achieve greater data throughput by ensuring that your network buffer is at least as large as your application buffer.
        size_t send_buffer_size() const;
        /// @brief Sets the size of the send buffer.
        /// @param value The size of the send buffer, in bytes. The default value is 8192 bytes.
        /// @return This current instance.
        /// @remarks The xtd::net::sockets::tcp_client::send_buffer_size property gets or sets the number of bytes that you are expecting to send in each call to the std::iostream::write method. This property actually manipulates the network buffer space allocated for send operation.
        /// @remarks Your network buffer should be at least as large as your application buffer to ensure that the desired data will be stored and sent in one operation. Use the xtd::net::sockets::tcp_client::send_buffer_size property to set this size. If your application will be sending bulk data, you should pass the std::iostream::write method a very large application buffer.
        /// @remarks If the network buffer is smaller than the amount of data you provide the std::iostream::write method, several network send operations will be performed for every call you make to the std::iostream::write method. You can achieve greater data throughput by ensuring that your network buffer is at least as large as your application buffer.
        tcp_client& send_buffer_size(size_t value);

        /// @brief Gets the amount of time a xtd::net::sockets::tcp_client will wait for a send operation to complete successfully.
        /// @return The send time-out value, in milliseconds. The default value is 0.
        /// @remarks The xtd::net::sockets::tcp_client::send_timeout property determines the amount of time that the xtd::net::sockets::send method will block until it is able to return successfully. This time is measured in milliseconds..
        /// @remarks After you call the Write method, the underlying xtd::net::sockets::socket returns the number of bytes actually sent to the host. The xtd::net::sockets::tcp_client::send_timeout property determines the amount of time a xtd::net::sockets::tcp_client will wait before receiving the number of bytes returned. If the time-out expires before the Send method successfully completes, xtd::net::sockets::tcp_client will throw a xtd::net::sockets::socket_exception. There is no time-out by default.
        int32_t send_timeout() const;
        /// @brief Gets the amount of time a xtd::net::sockets::tcp_client will wait for a send operation to complete successfully.
        /// @param value The send time-out value, in milliseconds. The default value is 0.
        /// @return This current instance.
        /// @remarks The xtd::net::sockets::tcp_client::send_timeout property determines the amount of time that the xtd::net::sockets::send method will block until it is able to return successfully. This time is measured in milliseconds..
        /// @remarks After you call the Write method, the underlying xtd::net::sockets::socket returns the number of bytes actually sent to the host. The xtd::net::sockets::tcp_client::send_timeout property determines the amount of time a xtd::net::sockets::tcp_client will wait before receiving the number of bytes returned. If the time-out expires before the Send method successfully completes, xtd::net::sockets::tcp_client will throw a xtd::net::sockets::socket_exception. There is no time-out by default.
        tcp_client& send_timeout(int32_t value);

        /// @brief Begins an asynchronous request for a remote host connection. The remote host is specified by an xtd::net::ip_address and a port number (uint16_t).
        /// @param address The xtd::net::ip_address of the remote host.
        /// @param port The port number of the remote host.
        /// @param callback An xtd::async_callback delegate that references the method to invoke when the operation is complete.
        /// @param state A user-defined object that contains information about the connect operation. This object is passed to the callback delegate when the operation is complete.
        /// @return An xtd::iasync_result object that references the asynchronous connection.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks The asynchronous xtd::net::sockets::tcp_client::client::begin_connect operation must be completed by calling the xtd::net::sockets::tcp_client::end_connect method. Typically, the method is invoked by the callback delegate.
        /// @remarks This method does not block until the operation completes. To block until the operation completes, use one of the xtd::net::sockets::tcp_client::connect method overloads.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        std::shared_ptr<xtd::iasync_result> begin_connect(const xtd::net::ip_address& address, uint16_t port, xtd::async_callback callback, const std::any& state);
        /// @brief Begins an asynchronous request for a remote host connection. The remote host is specified by an xtd::net::ip_address array and a port number (uint16_t).
        /// @param addresses At least one xtd::net::ip_address that designates the remote hosts.
        /// @param port The port number of the remote host.
        /// @param callback An xtd::async_callback delegate that references the method to invoke when the operation is complete.
        /// @param state A user-defined object that contains information about the connect operation. This object is passed to the requestCallback delegate when the operation is complete.
        /// @return An xtd::iasync_result object that references the asynchronous connection.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks The asynchronous xtd::net::sockets::tcp_client::client::begin_connect operation must be completed by calling the xtd::net::sockets::tcp_client::end_connect method. Typically, the method is invoked by the asyncCallback delegate.
        /// @remarks This method does not block until the operation completes. To block until the operation completes, use one of the xtd::net::sockets::tcp_client::connect method overloads.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        std::shared_ptr<xtd::iasync_result> begin_connect(const std::vector<xtd::net::ip_address>& addresses, uint16_t port, xtd::async_callback callback, const std::any& state);
        /// @brief Begins an asynchronous request for a remote host connection. The remote host is specified by a host name (xtd::ustring) and a port number (uint16_t).
        /// @param host The name of the remote host.
        /// @param port The port number of the remote host.
        /// @param callback An xtd::async_callback delegate that references the method to invoke when the operation is complete.
        /// @param state A user-defined object that contains information about the connect operation. This object is passed to the requestCallback delegate when the operation is complete.
        /// @return An xtd::iasync_result object that references the asynchronous connection.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks The asynchronous xtd::net::sockets::tcp_client::client::begin_connect operation must be completed by calling the xtd::net::sockets::tcp_client::end_connect method. Typically, the method is invoked by the asyncCallback delegate.
        /// @remarks This method does not block until the operation completes. To block until the operation completes, use one of the xtd::net::sockets::tcp_client::connect method overloads.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        std::shared_ptr<xtd::iasync_result> begin_connect(const xtd::ustring& host, uint16_t port, xtd::async_callback callback, const std::any& state);

        /// @brief Disposes this xtd::net::sockets::tcp_client instance and requests that the underlying TCP connection be closed.
        /// @remarks The xtd::net::sockets::tcp_client::close method marks the instance as disposed and requests that the associated xtd::net::sockets::socket close the TCP connection. Based on the xtd::net::sockets::tcp_client::linger_state property,
        /// @remarks the TCP connection may stay open for some time after the xtd::net::sockets::tcp_client::close method is called when data remains to be sent. There is no notification provided when
        /// @remarks the underlying connection has completed closing.
        /// @remarks Calling this method will eventually result in the close of the associated xtd::net::sockets::socket and will also close the associated xtd::net::sockets::network_stream that is used to send and receive data if one was created.
        void close();

        /// @brief Connects the client to a remote TCP host using the specified remote network endpoint.
        /// @param remote_end_point The xtd::net::ip_end_point to which you intend to connect.
        /// @exception xtd::net::sockets::socket_exception An error occurred when accessing the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks Call this method to establish a synchronous remote host connection to the specified xtd::net::ip_end_point. Before you call xtd::net::sockets::tcp_client::connect you must create an instance of the xtd::net::ip_end_point class using an IP address and a port number. Use this xtd::net::ip_end_point as the remote_end_point parameter. The xtd::net::sockets::tcp_client::connect method will block until it either connects or fails. After connecting with the remote host, use the xtd::net::sockets::tcp_client::get_stream method to obtain the underlying xtd::net::sockets::network_stream. Use this xtd::net::sockets::network_stream to send and receive data.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        void connect(const xtd::net::ip_end_point& remote_end_point);
        /// @brief Connects the client to a remote TCP host using the specified IP address and port number.
        /// @param ip_address The xtd::net::ip_address of the remote host to which you intend to send data
        /// @param port The port number to which you intend send data
        /// @exception xtd::net::sockets::socket_exception An error occurred when accessing the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks Call this method to establish a synchronous remote host connection to the specified xtd::net::ip_address and port number.
        /// @remarks The xtd::net::sockets::tcp_client::connect method will block until it either connects or fails.
        /// @remarks After connecting with the remote host, use the xtd::net::sockets::tcp_client::get_stream method to obtain the underlying xtd::net::sockets::network_stream.
        /// @remarks Use this xtd::net::sockets::network_stream to send and receive data.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        void connect(const xtd::net::ip_address& ip_address, uint16_t port);
        /// @brief Connects the client to the specified port on the specified host.
        /// @param hostname The DNS name of the remote host to which you intend to connect.
        /// @param port The port number of the remote host to which you intend to connect.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks This constructor creates a new xtd::net::sockets::tcp_client and makes a synchronous connection attempt to the provided host name and port number. The underlying service provider will assign the most appropriate local IP address and port number. xtd::net::sockets::tcp_client will block until it either connects or fails. This constructor allows you to initialize, resolve the DNS host name, and connect in one convenient step.
        /// @remarks If IPv6 is enabled and the xtd::net::sockets::tcp_client(xtd::ustring, uint16_t) method is called to connect to a host that resolves to both IPv6 and IPv4 addresses, the connection to the IPv6 address will be attempted first before the IPv4 address. This may have the effect of delaying the time to establish the connection if the host is not listening on the IPv6 address.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        void connect(const xtd::ustring& hostname, uint16_t port);

        /// @brief Ends a pending asynchronous connection attempt.
        /// @param result An xtd::iasync_result object returned by a call to xtd::net::sockets::tcp_client::client::begin_connect.
        /// @exception argument_exception async_result was not returned by a call to the xtd::net::sockets::socket::begin_connect method.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks This method blocks until the operation is complete. To perform this operation synchronously, use a xtd::net::sockets::tcp_client::connect method.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        void end_connect(std::shared_ptr<xtd::iasync_result> async_result);

        /// @brief Returns the xtd::net::sockets::network_stream used to send and receive data.
        /// @return The underlying xtd::net::sockets::network_stream.
        /// @remarks xtd::net::sockets::tcp_client::get_stream returns a xtd::net::sockets::network_stream that you can use to send and receive data. The xtd::net::sockets::network_stream class inherits from the std::iostream class, which provides a rich collection of methods and properties used to facilitate network communications.You must call the xtd::net::sockets::tcp_client::connect method first, or the xtd::net::sockets::tcp_client::get_stream method will throw an xtd::invalid_operation_exception. After you have obtained the xtd::net::sockets::network_stream, call the std::iostream::write method to send data to the remote host. Call the std::iostream::read method to receive data arriving from the remote host. Both of these methods block until the specified operation is performed. You can avoid blocking on a read operation by checking the xtd::net::sockets::network_stream::data_available property. A true value means that data has arrived from the remote host and is available for reading. In this case, std::iostream::read is guaranteed to complete immediately. If the remote host has shutdown its connection, std::iostream::read will immediately return with zero bytes.
        /// @note You must close the xtd::net::sockets::network_stream when you are through sending and receiving data. Closing xtd::net::sockets::tcp_client does not release the xtd::net::sockets::network_stream.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        xtd::net::sockets::network_stream get_stream() const;

      protected:
        /// @brief Gets a value that indicates whether a connection has been made.
        /// @return true if the connection has been made; otherwise, false.
        /// @remarks Classes deriving from xtd::net::sockets::tcp_client can use this property to determine if a connection attempt has succeeded. It does not monitor the ongoing connection state of xtd::net::sockets::tcp_client. If the remote host closes the connection, xtd::net::sockets::tcp_client::active will not be updated. If you are deriving from xtd::net::sockets::tcp_client and require closer attention to the connection state, use the xtd::net::sockets::tcp_client::client::connected property of the xtd::net::sockets::socket returned by the xtd::net::sockets::tcp_client::client property.
        bool active() const noexcept;
        /// @brief Sets a value that indicates whether a connection has been made.
        /// @param value true if the connection has been made; otherwise, false.
        /// @return This current instance.
        /// @remarks Classes deriving from xtd::net::sockets::tcp_client can use this property to determine if a connection attempt has succeeded. It does not monitor the ongoing connection state of xtd::net::sockets::tcp_client. If the remote host closes the connection, xtd::net::sockets::tcp_client::active will not be updated. If you are deriving from xtd::net::sockets::tcp_client and require closer attention to the connection state, use the xtd::net::sockets::tcp_client::client::connected property of the xtd::net::sockets::socket returned by the xtd::net::sockets::tcp_client::client property.
        tcp_client& active(bool value) noexcept;
        
      private:
        friend tcp_listener;
        tcp_client(const xtd::net::sockets::socket& socket);
        struct data;
        std::shared_ptr<data> data_;
      };
    }
  }
}
