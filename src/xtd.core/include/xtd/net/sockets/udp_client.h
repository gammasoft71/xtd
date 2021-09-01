/// @file
/// @brief Contains xtd::net::sockets::udp_client class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include "../../object.h"
#include "../../ustring.h"
#include "../ip_end_point.h"
#include "socket.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief The xtd::net::sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
    namespace sockets {
      /// @brief Provides User Datagram Protocol (UDP) network services.
      /// @par Namespace
      /// xtd::net::sockets
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core net
      /// @remarks The xtd::net::sockets::udp_client class provides simple methods for sending and receiving connectionless UDP datagrams in blocking synchronous mode. Because UDP is a connectionless transport protocol, you do not need to establish a remote host connection prior to sending and receiving data. You do, however, have the option of establishing a default remote host in one of the following two ways:
      /// * Create an instance of the xtd::net::sockets::udp_client class using the remote host name and port number as parameters.
      /// * Create an instance of the xtd::net::sockets::udp_client class and then call the xtd::net::sockets::udp_client::connect method.
      /// @remarks You can use any of the send methods provided in the xtd::net::sockets::udp_client to send data to a remote device. Use the xtd::net::sockets::udp_client::receive method to receive data from remote hosts.
      /// @note Do not call xtd::net::sockets::udp_client::send using a host name or xtd::net::ip_end_point if you have already specified a default remote host. If you do, xtd::net::sockets::udp_client will throw an exception.
      /// @remarks xtd::net::sockets::udp_client methods also allow you to send and receive multicast datagrams. Use the xtd::net::sockets::udp_client::join_multicast_group method to subscribe a xtd::net::sockets::udp_client to a multicast group. Use the xtd::net::sockets::udp_client::drop_multicast_group method to unsubscribe a xtd::net::sockets::udp_client from a multicast group.
      /// @par Examples
      /// The following example shows how to use IPv4 xtd::net::sockets::udp_client class.
      /// @include udp_client_ip_v4.cpp
      /// @par Examples
      /// The following example shows how to use IPv6 xtd::net::sockets::udp_client class.
      /// @include udp_client_ip_v6.cpp
      class udp_client : public xtd::object {
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

        class async_result_receive : public async_result_socket {
        public:
          async_result_receive(std::any async_state) : async_result_socket(async_state) {}
          std::vector<byte_t> buffer_;
          xtd::net::ip_end_point remote_end_point_;
        };

        class async_result_send : public async_result_socket {
        public:
          async_result_send(std::any async_state) : async_result_socket(async_state) {}
          size_t number_of_bytes_sent_;
        };

      public:
        /// @brief Initializes a new instance of the xtd::net::sockets::udp_client class
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the underlying socket.
        /// @remarks This constructor creates a new xtd::net::sockets::udp_client and allows the underlying service provider to assign the most appropriate local IPv4 address and port number. If this constructor is used, the xtd::net::sockets::udp_client instance is set with an address family of IPv4 that cannot be changed or overwritten by a connect method call with an IPv6 target.
        /// @remarks This constructor is not suitable for joining a multicast group because it does not perform socket binding. Also, it works only with IPv4 address types.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        udp_client();
        /// @brief Initializes a new instance of the xtd::net::sockets::udp_client class and binds it to the local port number provided.
        /// @param port The local port number from which you intend to communicate.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the underlying socket.
        /// @remarks This constructor creates an underlying xtd::net::sockets::socket and binds it to the port number from which you intend to communicate. Use this constructor if you are only interested in setting the local port number. The underlying service provider will assign the local IP address. If you pass 0 to the constructor, the underlying service provider will assign a port number. If this constructor is used, the xtd::net::sockets::udp_client instance is set with an address family of IPv4 that cannot be changed or overwritten by a connect method call with an IPv6 target.
        /// @remarks This constructor works only with IPv4 address types.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        explicit udp_client(uint16_t port);
        /// @brief Initializes a new instance of the xtd::net::sockets::udp_client class and binds it to the specified local endpoint.
        /// @param local_end_point An xtd::net::ip_end_point that represents the local endpoint to which you bind the UDP connection.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the underlying socket.
        /// @remarks This constructor creates a new xtd::net::sockets::udp_client and binds it to the xtd::net::ip_end_point specified by the local_end_point parameter. Before you call this constructor, you must create an xtd::net::ip_end_point using the IP address and port number from which you intend to send and receive data. You do not need to specify a local IP address and port number for sending and receiving data. If you do not, the underlying service provider will assign the most appropriate local IP address and port number.
        /// @remarks If this constructor is used, the xtd::net::sockets::udp_client instance is set with the address family specified by the local_end_point parameter that cannot be changed or overwritten by a connect method call with a different address family.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        explicit udp_client(const xtd::net::ip_end_point& local_end_point);
        /// @brief Initializes a new instance of the xtd::net::sockets::udp_client class
        /// @param address_family one of the xtd::net::sockets::address_family values that specifies the addressing scheme of the socket.
        /// @exception xtd::argument_exception family is not xtd::net::sockets::address_family::inter_network or xtd::net::sockets::address_family::inter_network_v6.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the underlying socket.
        /// @remarks The family parameter determines whether the listener uses an IP version 4 address (IPv4) or an IP version 6 (IPv6) address. To use an IPv4 address, pass the xtd::net::sockets::address_family::inter_network value. To use an IPv6 address, pass the xtd::net::sockets::address_family::inter_network_v6 value. Passing any other value will cause the method to throw an xtd::argument_exception.
        /// @remarks If this constructor is used, the xtd::net::sockets::udp_client instance is set with the address family specified by the family parameter that cannot be changed or overwritten by a connect method call with a different address family.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        /// @remarks The xtd::net::sockets::udp_client.xtd::net::sockets::udp_client(xtd::net::sockets::address_family) is not suitable for joining a multicast group because it does not perform socket binding.
        explicit udp_client(xtd::net::sockets::address_family address_Family);
        /// @brief Initializes a new instance of the xtd::net::sockets::udp_client class and binds it to the local port number provided.
        /// @param port The port on which to listen for incoming connection attempts.
        /// @param address_family One of the xtd::net::sockets::address_family values that specifies the addressing scheme of the socket.
        /// @exception xtd::argument_exception family is not xtd::net::sockets::address_family::inter_network or xtd::net::sockets::address_family::inter_network_v6.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the underlying socket.
        /// @remarks This constructor creates an underlying xtd::net::sockets::socket and binds it to the port number from which you intend to communicate.
        /// @remarks The family parameter determines whether the listener uses an IP version 4 address (IPv4) or an IP version 6 (IPv6) address. To use an IPv4 address, pass the xtd::net::sockets::address_family::inter_network value. To use an IPv6 address, pass the xtd::net::sockets::address_family::inter_network_v6 value. Passing any other value will cause the method to throw an xtd::argument_exception.
        /// @remarks If this constructor is used, the xtd::net::sockets::udp_client instance is set with the address family specified by the family parameter that cannot be changed or overwritten by a connect method call with a different address family.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        udp_client(uint16_t port, xtd::net::sockets::address_family addressFamily);
        /// @brief Initializes a new instance of the xtd::net::sockets::udp_client class and establishes a default remote host.
        /// @param hostname The name of the remote DNS host to which you intend to connect.
        /// @param port The remote port number to which you intend to connect.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the underlying socket.
        /// @remarks This constructor initializes a new xtd::net::sockets::udp_client and establishes a remote host using the hostname and port parameters. Establishing a default remote host is optional. If you use this constructor, you do not have to specify a remote host in each call to the xtd::net::sockets::udp_client::send method. Specifying a default remote host limits you to that host only. You can change the default remote host at any time by calling the xtd::net::sockets::udp_client::connect method. If you want to specify a remote host in your call to the xtd::net::sockets::udp_client::send method, do not use this constructor.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        udp_client(const xtd::ustring& hostname, uint16_t port);

        /// @cond
        udp_client(udp_client&&) = default;
        udp_client(const udp_client&) = default;
        ~udp_client();
        udp_client& operator=(const udp_client&) = default;
        friend std::ostream& operator <<(std::ostream& os, const udp_client& uc) noexcept {return os << uc.to_string();}
        bool operator==(const udp_client& s) const {return data_ == s.data_;};
        bool operator!=(const udp_client& s) const {return !operator==(s);};
        /// @endcond

        /// @brief Gets the amount of data received from the network that is available to read.
        /// @return The number of bytes of data received from the network.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the underlying socket.
        /// @exception xtd::object_closed_exception The underlying xtd::net::sockets::socket has been closed.
        /// @remarks The xtd::net::sockets::udp_client::available property is used to determine the amount of data queued in the network buffer for reading. If data is available, call Read to get the data. If no data is available, the xtd::net::sockets::udp_client::available property returns 0.
        /// @remarks If the remote host shuts down or closes the connection, the xtd::net::sockets::udp_client::available property throws a xtd::net::sockets::socket_exception.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        size_t available() const;
        
        /// @brief Gets the underlying network xtd::net::sockets::socket.
        /// @return The underlying Network xtd::net::sockets::socket.
        /// @remarks xtd::net::sockets::udp_client creates a xtd::net::sockets::socket used to send and receive data over a network. Classes deriving from xtd::net::sockets::udp_client can use this property to get or set this xtd::net::sockets::socket. Use the underlying xtd::net::sockets::socket returned fromxtd::net::sockets::udp_client::client if you require access beyond that which xtd::net::sockets::udp_client provides. You can also usextd::net::sockets::udp_client::client to set the underlying xtd::net::sockets::socket to an existing xtd::net::sockets::socket. This is useful if you want to take advantage of the simplicity of xtd::net::sockets::udp_client using a pre-existing xtd::net::sockets::socket.
        xtd::net::sockets::socket client() const noexcept;
        /// @brief Sets the underlying network xtd::net::sockets::socket
        /// @param value The underlying Network xtd::net::sockets::socket.
        /// @return This current instance.
        /// @remarks xtd::net::sockets::udp_client creates a xtd::net::sockets::socket used to send and receive data over a network. Classes deriving from xtd::net::sockets::udp_client can use this property to get or set this xtd::net::sockets::socket. Use the underlying xtd::net::sockets::socket returned fromxtd::net::sockets::udp_client::client if you require access beyond that which xtd::net::sockets::udp_client provides. You can also usextd::net::sockets::udp_client::client to set the underlying xtd::net::sockets::socket to an existing xtd::net::sockets::socket. This is useful if you want to take advantage of the simplicity of xtd::net::sockets::udp_client using a pre-existing xtd::net::sockets::socket.
        udp_client& client(const xtd::net::sockets::socket& value) noexcept;

        /// @brief Gets a boolean value that specifies whether the xtd::net::sockets::udp_client allows Internet Protocol (IP) datagrams to be fragmented.
        /// @return true if the xtd::net::sockets::udp_client allows datagram fragmentation; otherwise, false. The default is true.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the underlying socket.
        /// @exception xtd::object_closed_exception The underlying xtd::net::sockets::socket has been closed.
        /// @remarks Datagrams require fragmentation when their size exceeds the Maximum Transfer Unit (MTU) of the transmission medium. Datagrams may be fragmented by the sending host or by an intermediate router. If a datagram must be fragmented, and the xtd::net::sockets::socket_option_name::dont_fragment option is set, the datagram is discarded, and an Internet Control Message Protocol (ICMP) error message is sent back to the sender of the datagram.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        bool dont_fragment() const;
        /// @brief Sets boolean value that specifies whether the xtd::net::sockets::udp_client allows Internet Protocol (IP) datagrams to be fragmented.
        /// @param value true if the xtd::net::sockets::udp_client allows datagram fragmentation; otherwise, false. The default is true.
        /// @return This current instance.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the underlying socket.
        /// @exception xtd::object_closed_exception The underlying xtd::net::sockets::socket has been closed.
        /// @remarks Datagrams require fragmentation when their size exceeds the Maximum Transfer Unit (MTU) of the transmission medium. Datagrams may be fragmented by the sending host or by an intermediate router. If a datagram must be fragmented, and the xtd::net::sockets::socket_option_name::dont_fragment option is set, the datagram is discarded, and an Internet Control Message Protocol (ICMP) error message is sent back to the sender of the datagram.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        udp_client& dont_fragment(bool value);

        /// @brief Gets a boolean value that specifies whether the xtd::net::sockets::udp_client may send or receive broadcast packets.
        /// @return true if the xtd::net::sockets::udp_client allows broadcast packets; otherwise, false. The default is false.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the underlying socket.
        /// @exception xtd::object_closed_exception The underlying xtd::net::sockets::socket has been closed.
        /// @remarks Broadcasting is limited to a specific subnet. You can broadcast to your local subnet by sending a packet to 255.255.255.255; or, you can use the directed broadcast address, which is the network portion of an Internet Protocol (IP) address with all bits set in the host portion. For example, if your IP address is 192.168.1.40 (a Class C address, with the network portion as the first three octets, and the host portion is the last octet), your directed broadcast address is 192.168.1.255.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        bool enable_broadcast() const;
        /// @brief Sets a boolean value that specifies whether the xtd::net::sockets::udp_client may send or receive broadcast packets.
        /// @param value true if the xtd::net::sockets::udp_client allows broadcast packets; otherwise, false. The default is false.
        /// @return This current instance.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the underlying socket.
        /// @exception xtd::object_closed_exception The underlying xtd::net::sockets::socket has been closed.
        /// @remarks Broadcasting is limited to a specific subnet. You can broadcast to your local subnet by sending a packet to 255.255.255.255; or, you can use the directed broadcast address, which is the network portion of an Internet Protocol (IP) address with all bits set in the host portion. For example, if your IP address is 192.168.1.40 (a Class C address, with the network portion as the first three octets, and the host portion is the last octet), your directed broadcast address is 192.168.1.255.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        udp_client& enable_broadcast(bool value);
        
        /// @brief Gets a boolean value that specifies whether the xtd::net::sockets::udp_client allows only one client to use a port.
        /// @return true if the xtd::net::sockets::udp_client allows only one client to use a specific port; otherwise, false. The default is true for Windows Server 2003 and Windows XP Service Pack 2 and later, and false for all other versions.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the underlying socket.
        /// @exception xtd::object_closed_exception The underlying xtd::net::sockets::socket has been closed.
        /// @remarks By default, multiple clients can use a specific port; however, only one of the clients can perform operations on the network traffic sent to the port. You can use the xtd::net::sockets::udp_client::exclusive_address_use property to prevent multiple clients from using a specific port.
        /// @remarks This property must be set before the underlying socket is bound to a client port. If you call xtd::net::sockets::udp_client.xtd::net::sockets::udp_client(Int32), xtd::net::sockets::udp_client.xtd::net::sockets::udp_client(Int32, xtd::net::sockets::address_family), xtd::net::sockets::udp_client.xtd::net::sockets::udp_client(xtd::net::ip_end_point), or xtd::net::sockets::udp_client.xtd::net::sockets::udp_client(String, Int32), the client port is bound as a side effect of the constructor, and you cannot subsequently set the xtd::net::sockets::udp_client::exclusive_address_use property
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        bool exclusive_address_use() const;
        /// @brief Sets a boolean value that specifies whether the xtd::net::sockets::udp_client allows only one client to use a port.
        /// @param value true if the xtd::net::sockets::udp_client allows only one client to use a specific port; otherwise, false. The default is true for Windows Server 2003 and Windows XP Service Pack 2 and later, and false for all other versions.
        /// @return This current instance.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the underlying socket.
        /// @exception xtd::object_closed_exception The underlying xtd::net::sockets::socket has been closed.
        /// @remarks By default, multiple clients can use a specific port; however, only one of the clients can perform operations on the network traffic sent to the port. You can use the xtd::net::sockets::udp_client::exclusive_address_use property to prevent multiple clients from using a specific port.
        /// @remarks This property must be set before the underlying socket is bound to a client port. If you call xtd::net::sockets::udp_client.xtd::net::sockets::udp_client(Int32), xtd::net::sockets::udp_client.xtd::net::sockets::udp_client(Int32, xtd::net::sockets::address_family), xtd::net::sockets::udp_client.xtd::net::sockets::udp_client(xtd::net::ip_end_point), or xtd::net::sockets::udp_client.xtd::net::sockets::udp_client(String, Int32), the client port is bound as a side effect of the constructor, and you cannot subsequently set the xtd::net::sockets::udp_client::exclusive_address_use property
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        udp_client& exclusive_address_use(bool value);

        /// @brief Gets a boolean value that specifies whether outgoing multicast packets are delivered to the sending application.
        /// @return true if the xtd::net::sockets::udp_client receives outgoing multicast packets; otherwise, false.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the underlying socket.
        /// @exception xtd::object_closed_exception The underlying xtd::net::sockets::socket has been closed.
        /// @remarks Multicast is a scalable method for many-to-many communication on the Internet. If a process subscribes to a multicast address, any packets sent by that process are received by every other process that has subscribed to the multicast address.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        bool multicast_loopback() const;
        /// @brief Sets a boolean value that specifies whether outgoing multicast packets are delivered to the sending application.
        /// @param value true if the xtd::net::sockets::udp_client receives outgoing multicast packets; otherwise, false.
        /// @return This current instance.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the underlying socket.
        /// @exception xtd::object_closed_exception The underlying xtd::net::sockets::socket has been closed.
        /// @remarks Multicast is a scalable method for many-to-many communication on the Internet. If a process subscribes to a multicast address, any packets sent by that process are received by every other process that has subscribed to the multicast address.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        udp_client& multicast_loopback(bool value);
        
        /// @brief Gets a value that specifies the Time to Live (TTL) value of Internet Protocol (IP) packets sent by the xtd::net::sockets::udp_client.
        /// @return The TTL value.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the underlying socket.
        /// @exception xtd::object_closed_exception The underlying xtd::net::sockets::socket has been closed.
        /// @remarks The TTL value indicates the maximum number of routers a packet can traverse before the router discards the packet and an Internet Control Message Protocol (ICMP) "TTL exceeded" error message is returned to the sender.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        byte_t ttl() const;
        /// @brief Sets a value that specifies the Time to Live (TTL) value of Internet Protocol (IP) packets sent by the xtd::net::sockets::udp_client.
        /// @param value The TTL value.
        /// @return This current instance.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the underlying socket.
        /// @exception xtd::object_closed_exception The underlying xtd::net::sockets::socket has been closed.
        /// @remarks The TTL value indicates the maximum number of routers a packet can traverse before the router discards the packet and an Internet Control Message Protocol (ICMP) "TTL exceeded" error message is returned to the sender.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        udp_client& ttl(byte_t value);

        /// @brief Enables or disables Network Address Translation (NAT) traversal on a xtd::net::sockets::udp_client instance.
        /// @param allowed A boolean value that specifies whether to enable or disable NAT traversal.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the underlying socket.
        /// @remarks The xtd::net::sockets::udp_client::allow_nat_traversal method is used to enable or disable NAT traversal for a xtd::net::sockets::udp_client instance. NAT traversal may be provided using Teredo, 6to4, or an ISATAP tunnel.
        /// @remarks When the allowed parameter is false, the xtd::net::sockets::ip_protection_level option on the associated socket is set to xtd::net::sockets::ip_protection_level::edge_restricted. This explicitly disables NAT traversal for a xtd::net::sockets::udp_client instance.
        /// @remarks When the allowed parameter is true, the xtd::net::sockets::ip_protection_level option on the associated socket is set to xtd::net::sockets::ip_protection_level::edge_unrestricted. This may allow NAT traversal for a xtd::net::sockets::udp_client depending on firewall rules in place on the system.
        /// @remarks A Teredo address is an IPv6 address with the prefix of 2001::/32. Teredo addresses can be returned through normal DNS name resolution or enumerated as an IPv6 address assigned to a local interface.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        void allow_nat_traversal(bool allowed);
        
        /// @brief xtd::net::sockets::udp_client::receives a datagram from a remote host asynchronously.
        /// @param callback An xtd::async_callback delegate that references the method to invoke when the operation is complete.
        /// @param state A user-defined object that contains information about the receive operation. This object is passed to the callback delegate when the operation is complete.
        /// @return An xtd::iasync_result object that references the asynchronous receive.
        /// @remarks The asynchronous xtd::net::sockets::udp_client::begin_receive operation must be completed by calling the xtd::net::sockets::udp_client::end_receive method. Typically, the method is invoked by the callback delegate.
        /// @remarks This method does not block until the operation is complete. To block until the operation is complete, use the xtd::net::sockets::udp_client::receive method.
        std::shared_ptr<xtd::iasync_result> begin_receive(xtd::async_callback callback, const std::any& state);

        /// @brief xtd::net::sockets::udp_client::sends a datagram to a destination asynchronously. The destination is specified by the host name and port number.
        /// @param dgram A byte array that contains the data to be sent.
        /// @param bytes The number of bytes to send.
        /// @param hostname The destination host.
        /// @param port The destination port number.
        /// @param callback An xtd::async_callback delegate that references the method to invoke when the operation is complete.
        /// @param state A user-defined object that contains information about the send operation. This object is passed to the callback delegate when the operation is complete.
        /// @return An xtd::iasync_result object that references the asynchronous send.
        /// @remarks The asynchronous xtd::net::sockets::udp_client::begin_send operation must be completed by calling the xtd::net::sockets::udp_client::end_send method. Typically, the method is invoked by the callback delegate.
        /// @remarks This method does not block until the operation is complete. To block until the operation is complete, use one of the xtd::net::sockets::udp_client::send method overloads.
        std::shared_ptr<xtd::iasync_result> begin_send(const std::vector<byte_t>& dgram, size_t bytes, const xtd::ustring& hostname, uint16_t port, xtd::async_callback callback, const std::any& state);
        
        /// @brief xtd::net::sockets::udp_client::sends a datagram to a destination asynchronously. The destination is specified by a EndPoint.
        /// @param dgram A byte array that contains the data to be sent.
        /// @param bytes The number of bytes to send.
        /// @param end_point The EndPoint that represents the destination for the data.
        /// @param callback An xtd::async_callback delegate that references the method to invoke when the operation is complete.
        /// @param state A user-defined object that contains information about the send operation. This object is passed to the callback delegate when the operation is complete.
        /// @return An xtd::iasync_result object that references the asynchronous send.
        /// @remarks The asynchronous xtd::net::sockets::udp_client::begin_send operation must be completed by calling the xtd::net::sockets::udp_client::end_send method. Typically, the method is invoked by the callback delegate.
        /// @remarks This method does not block until the operation is complete. To block until the operation is complete, use one of the xtd::net::sockets::udp_client::send method overloads.
        std::shared_ptr<xtd::iasync_result> begin_send(const std::vector<byte_t>& dgram, size_t bytes, const xtd::net::ip_end_point& end_point, xtd::async_callback callback, const std::any& state);
        /// @brief xtd::net::sockets::udp_client::sends a datagram to a remote host asynchronously. The destination was specified previously by a call to xtd::net::sockets::udp_client::connect.
        /// @param dgram A byte array that contains the data to be sent.
        /// @param bytes The number of bytes to send.
        /// @param callback An xtd::async_callback delegate that references the method to invoke when the operation is complete.
        /// @param state A user-defined object that contains information about the send operation. This object is passed to the callback delegate when the operation is complete.
        /// @return An xtd::iasync_result object that references the asynchronous send.
        /// @remarks The asynchronous xtd::net::sockets::udp_client::begin_send operation must be completed by calling the xtd::net::sockets::udp_client::end_send method. Typically, the method is invoked by the callback delegate.
        /// @remarks This method does not block until the operation completes. To block until the operation is complete, use one of the xtd::net::sockets::udp_client::send method overloads.
        std::shared_ptr<xtd::iasync_result> begin_send(const std::vector<byte_t>& dgram, size_t bytes, xtd::async_callback callback, const std::any& state);

        /// @brief  Closes the UDP connection
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the underlying socket.
        /// @remarks The xtd::net::sockets::udp_client::close disables the underlying xtd::net::sockets::socket and releases all managed and unmanaged resources associated with the xtd::net::sockets::udp_client.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        void close();
        
        /// @brief Establishes a default remote host using the specified network endpoint.
        /// @param end_point An xtd::net::ip_end_point that specifies the network endpoint to which you intend to send data
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the underlying socket.
        /// @exception xtd::object_closed_exception The underlying xtd::net::sockets::socket has been closed.
        /// @remarks The xtd::net::sockets::udp_client::connect method establishes a default remote host using the value specified in the endPoint parameter. Once established, you do not have to specify a remote host in each call to the xtd::net::sockets::udp_client::send method.
        /// @remarks Establishing a default remote host is optional. Specifying a default remote host limits you to that host only. If you want to send datagrams to a different remote host, you must make another call to the xtd::net::sockets::udp_client::connect method or create another xtd::net::sockets::udp_client without a default remote host. If you have established a default remote host and you also provide a remote host in your call to the xtd::net::sockets::udp_client::send method, xtd::net::sockets::udp_client::send will throw a xtd::net::sockets::socket_exception. If you receive a xtd::net::sockets::socket_exception, use xtd::net::sockets::socket_exception.ErrorCode to obtain the specific error code. Once you have obtained this code, you can refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        /// @remarks If you call the xtd::net::sockets::udp_client::connect method, any datagrams that arrive from an address other than the specified default will be discarded. You cannot set the default remote host to a broadcast address using this method unless you inherit from xtd::net::sockets::udp_client, use thextd::net::sockets::udp_client::client method to obtain the underlying xtd::net::sockets::socket, and set the socket option to SocketOptionName.Broadcast.
        /// @remarks You can however, broadcast data to the default broadcast address, 255.255.255.255, if you specify xtd::net::ip_address::broadcast in your call to the xtd::net::sockets::udp_client::send method. If your application requires greater control over broadcast addresses, you can also revert to using the xtd::net::sockets::socket class.
        /// @note Since the UDP protocol is connectionless, the xtd::net::sockets::udp_client::connect method does not block. Do not call the xtd::net::sockets::udp_client::connect method if you intend to receive multicasted datagrams.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        void connect(const xtd::net::ip_end_point& end_point);
        /// @brief Establishes a default remote host using the specified IP address and port number.
        /// @param ip_address The xtd::net::ip_address of the remote host to which you intend to send data
        /// @param port The port number to which you intend send data
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the underlying socket.
        /// @exception xtd::object_closed_exception The underlying xtd::net::sockets::socket has been closed.
        /// @remarks The xtd::net::sockets::udp_client::connect method establishes a default remote host using the values specified in the addr and port parameters. Once established, you do not have to specify a remote host in each call to the xtd::net::sockets::udp_client::send method.
        /// @remarks Establishing a default remote host is optional. Specifying a default remote host limits you to that host only. If you want to send datagrams to a different remote host, you must make another call to the xtd::net::sockets::udp_client::connect method or create another xtd::net::sockets::udp_client without a default remote host. If you have established a default remote host and you also provide a remote host in your call to the xtd::net::sockets::udp_client::send method, xtd::net::sockets::udp_client::send will throw a xtd::net::sockets::socket_exception. If you receive a xtd::net::sockets::socket_exception, use xtd::net::sockets::socket_exception.ErrorCode to obtain the specific error code. Once you have obtained this code, you can refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        /// @remarks If you call the xtd::net::sockets::udp_client::connect method, any datagrams that arrive from an address other than the specified default will be discarded. You cannot set the default remote host to a broadcast address using this method unless you inherit from xtd::net::sockets::udp_client, use the client method to obtain the underlying xtd::net::sockets::socket, and set the socket option to SocketOptionName.Broadcast.
        /// @remarks You can however, broadcast data to the default broadcast address, 255.255.255.255, if you specify xtd::net::ip_address::broadcast in your call to the xtd::net::sockets::udp_client::send method. If your application requires greater control over broadcast addresses, you can also revert to using the xtd::net::sockets::socket class.
        /// @note Since the UDP protocol is connectionless, the xtd::net::sockets::udp_client::connect method does not block. Do not call the xtd::net::sockets::udp_client::connect method if you intend to receive multicasted datagrams.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        void connect(const xtd::net::ip_address& ip_address, uint16_t port);
        /// @brief Establishes a default remote host using the specified hostname and port number
        /// @param hostname the hostname to connect to.
        /// @param port The port number to which you intend send data
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the underlying socket.
        /// @exception xtd::object_closed_exception The underlying xtd::net::sockets::socket has been closed.
        /// @remarks The xtd::net::sockets::udp_client::connect method establishes a default remote host using the values specified in the addr and port parameters. Once established, you do not have to specify a remote host in each call to the xtd::net::sockets::udp_client::send method.
        /// @remarks Establishing a default remote host is optional. Specifying a default remote host limits you to that host only. If you want to send datagrams to a different remote host, you must make another call to the xtd::net::sockets::udp_client::connect method or create another xtd::net::sockets::udp_client without a default remote host. If you have established a default remote host and you also provide a remote host in your call to the xtd::net::sockets::udp_client::send method, xtd::net::sockets::udp_client::send will throw a xtd::net::sockets::socket_exception. If you receive a xtd::net::sockets::socket_exception, use xtd::net::sockets::socket_exception.ErrorCode to obtain the specific error code. Once you have obtained this code, you can refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        /// @remarks If you call the xtd::net::sockets::udp_client::connect method, any datagrams that arrive from an address other than the specified default will be discarded. You cannot set the default remote host to a broadcast address using this method unless you inherit from xtd::net::sockets::udp_client, use the client method to obtain the underlying xtd::net::sockets::socket, and set the socket option to SocketOptionName.Broadcast.
        /// @remarks You can however, broadcast data to the default broadcast address, 255.255.255.255, if you specify xtd::net::ip_address::broadcast in your call to the xtd::net::sockets::udp_client::send method. If your application requires greater control over broadcast addresses, you can also revert to using the xtd::net::sockets::socket class.
        /// @note Since the UDP protocol is connectionless, the xtd::net::sockets::udp_client::connect method does not block. Do not call the xtd::net::sockets::udp_client::connect method if you intend to receive multicasted datagrams.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        void connect(const xtd::ustring& hostname, uint16_t port);

        /// @brief Leaves a multicast group.
        /// @param multicast_address The xtd::net::ip_address of the multicast group to leave.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the underlying socket.
        /// @exception xtd::object_closed_exception The underlying xtd::net::sockets::socket has been closed.
        /// @remarks The xtd::net::sockets::udp_client::drop_multicast_group method withdraws the xtd::net::sockets::udp_client from the multicast group identified by the specified xtd::net::ip_address. After calling the xtd::net::sockets::udp_client::drop_multicast_group method, the underlying xtd::net::sockets::socket sends an Internet Group Management Protocol (IGMP) packet to the router, removing the router from the multicast group. After a xtd::net::sockets::udp_client withdraws from the group, it will no longer be able to receive datagrams sent to that group.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        void drop_multicast_group(const xtd::net::ip_address& multicast_address);
        /// @brief Leaves a multicast group.
        /// @param multicast_address The xtd::net::ip_address of the multicast group to leave.
        /// @param if_index The local address of the multicast group to leave.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the underlying socket.
        /// @exception xtd::object_closed_exception The underlying xtd::net::sockets::socket has been closed.
        /// @remarks The xtd::net::sockets::udp_client::drop_multicast_group method withdraws the xtd::net::sockets::udp_client from the multicast group identified by the specified xtd::net::ip_address. After calling the xtd::net::sockets::udp_client::drop_multicast_group method, the underlying xtd::net::sockets::socket sends an Internet Group Management Protocol (IGMP) packet to the router, removing the router from the multicast group. After a xtd::net::sockets::udp_client withdraws from the group, it will no longer be able to receive datagrams sent to that group.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        void dropo_multicast_group(const xtd::net::ip_address& multicast_address, size_t if_index);

        /// @brief Ends a pending asynchronous receive.
        /// @param async_result An xtd::iasync_result object returned by a call to xtd::net::sockets::udp_client::begin_receive(xtd::async_callback, Object).
        /// @param remote_end_point The specified remote endpoint.
        /// @return If successful, an array of bytes that contains datagram data.
        /// @exception argument_exception asyncResult was not returned by a call to the xtd::net::sockets::udp_clientt::begin_receive method.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the underlying socket.
        /// @exception xtd::object_closed_exception The underlying xtd::net::sockets::socket has been closed.
        /// @remarks This method blocks until the operation is complete.
        /// @remarks To perform this operation synchronously, use the xtd::net::sockets::udp_client::receive method.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        std::vector<byte_t> end_receive(std::shared_ptr<xtd::iasync_result> async_result, xtd::net::ip_end_point& remote_end_point);

        /// @brief Ends a pending asynchronous send.
        /// @param async_result An xtd::iasync_result object returned by a call to xtd::net::sockets::udp_client::begin_send.
        /// @return If successful, the number of bytes sent to the xtd::net::sockets::udp_client.
        /// @exception argument_exception asyncResult was not returned by a call to the xtd::net::sockets::udp_client::begin_send method.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the underlying socket.
        /// @exception xtd::object_closed_exception The underlying xtd::net::sockets::socket has been closed.
        /// @remarks This method blocks until the operation is complete.
        /// @remarks To perform this operation synchronously, use the xtd::net::sockets::udp_client::send method.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        size_t end_send(std::shared_ptr<xtd::iasync_result> async_result);

        /// @brief Adds a xtd::net::sockets::udp_client to a multicast group.
        /// @param multicast_address The multicast xtd::net::ip_address of the group you want to join.
        /// @exception argument_exception The IP address is not compatible with the xtd::net::sockets::address_family value that defines the addressing scheme of the socket.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the underlying socket.
        /// @exception xtd::object_closed_exception The underlying xtd::net::sockets::socket has been closed.
        /// @remarks The xtd::net::sockets::udp_client::join_multicast_group method subscribes the xtd::net::sockets::udp_client to a multicast group using the specified xtd::net::ip_address. After calling the xtd::net::sockets::udp_client::join_multicast_group method, the underlying xtd::net::sockets::socket sends an Internet Group Management Protocol (IGMP) packet to the router requesting membership to the multicast group. The multicast address range is 224.0.0.0 to 239.255.255.255. If you specify an address outside this range or if the router to which the request is made is not multicast enabled, xtd::net::sockets::udp_client will throw a xtd::net::sockets::socket_exception. If you receive a xtd::net::sockets::socket_exception, use xtd::net::sockets::socket_exception.ErrorCode to obtain the specific error code. Once you have obtained this code, you can refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error. Once the xtd::net::sockets::udp_client is listed with the router as a member of the multicast group, it will be able to receive multicasted datagrams sent to the specified xtd::net::ip_address.
        /// @note You must create the xtd::net::sockets::udp_client using the multicast port number; otherwise, you will not be able to receive multicasted datagrams. Do not call the xtd::net::sockets::udp_client::connect method prior to calling the xtd::net::sockets::udp_client::join_multicast_group method, or the xtd::net::sockets::udp_client::receive method will not work. You do not need to belong to a multicast group to send datagrams to a multicast IP address.
        /// @remarks Before joining a multicast group, make sure the socket is bound to the port or endpoint. You do that by calling one of the constructors that accept a port or an endpoint as a parameter.
        /// @remarks To stop receiving multicasted datagrams, call the xtd::net::sockets::udp_client::drop_multicast_group method and provide the xtd::net::ip_address of the group from which you would like to withdraw.
        /// @note In the IPv6 case, there are several multicast address ranges you can choose from. Please, refer to the IETF RFC 2375.
        /// @note You cannot call xtd::net::sockets::udp_client::join_multicast_group on a xtd::net::sockets::udp_client constructed without a specific local port (that is, using the xtd::net::sockets::udp_client() or xtd::net::sockets::udp_client(xtd::net::sockets::address_family) constructor).
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        void join_multicast_group(const xtd::net::ip_address& multicast_address);
        /// @brief Adds a xtd::net::sockets::udp_client to a multicast group.
        /// @param if_index The interface index associated with the local IP address on which to join the multicast group.
        /// @param multicast_address The multicast xtd::net::ip_address of the group you want to join.
        /// @exception argument_exception The IP address is not compatible with the xtd::net::sockets::address_family value that defines the addressing scheme of the socket.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the underlying socket.
        /// @exception xtd::object_closed_exception The underlying xtd::net::sockets::socket has been closed.
        /// @remarks The xtd::net::sockets::udp_client::join_multicast_group method subscribes the xtd::net::sockets::udp_client to a multicast group using the specified xtd::net::ip_address. After calling the xtd::net::sockets::udp_client::join_multicast_group method, the underlying xtd::net::sockets::socket sends an Internet Group Management Protocol (IGMP) packet to the router requesting membership to the multicast group. The multicast address range is 224.0.0.0 to 239.255.255.255. If you specify an address outside this range or if the router to which the request is made is not multicast enabled, xtd::net::sockets::udp_client will throw a xtd::net::sockets::socket_exception. If you receive a xtd::net::sockets::socket_exception, use xtd::net::sockets::socket_exception.ErrorCode to obtain the specific error code. Once you have obtained this code, you can refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error. Once the xtd::net::sockets::udp_client is listed with the router as a member of the multicast group, it will be able to receive multicasted datagrams sent to the specified xtd::net::ip_address.
        /// @remarks Before joining a multicast group, make sure the socket is bound to the port or endpoint. You do that by calling one of the constructors that accept a port or an endpoint as a parameter.
        /// @remarks The if_index parameter is used to identify a hardware interface on the same link.
        /// @note There are several multicast address ranges to choose from. Refer to the IETF RFC 2375.
        /// @note You cannot call xtd::net::sockets::udp_client::join_multicast_group on a xtd::net::sockets::udp_client constructed without a specific local port (that is, using the xtd::net::sockets::udp_client() or xtd::net::sockets::udp_client(xtd::net::sockets::address_family) constructor).
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        void join_multicast_group(size_t if_index, const xtd::net::ip_address& multicast_address);
        /// @brief Adds a xtd::net::sockets::udp_client to a multicast group with the specified Time to Live (TTL).
        /// @param multicast_address The multicast xtd::net::ip_address of the group you want to join.
        /// @param ttl The Time to Live (TTL), measured in router hops.
        /// @exception argument_exception The IP address is not compatible with the xtd::net::sockets::address_family value that defines the addressing scheme of the socket.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the underlying socket.
        /// @exception xtd::object_closed_exception The underlying xtd::net::sockets::socket has been closed.
        /// @remarks The xtd::net::sockets::udp_client::join_multicast_group method subscribes the xtd::net::sockets::udp_client to a multicast group using the specified xtd::net::ip_address. After calling the xtd::net::sockets::udp_client::join_multicast_group method, the underlying xtd::net::sockets::socket sends an Internet Group Management Protocol (IGMP) packet to the router requesting membership to the multicast group. The multicast address range is 224.0.0.0 to 239.255.255.255. If you specify an address outside this range or if the router to which the request is made is not multicast enabled, xtd::net::sockets::udp_client will throw a xtd::net::sockets::socket_exception. If you receive a xtd::net::sockets::socket_exception, use xtd::net::sockets::socket_exception.ErrorCode to obtain the specific error code. Once you have obtained this code, you can refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error. Once the xtd::net::sockets::udp_client is listed with the router as a member of the multicast group, it will be able to receive multicasted datagrams sent to the specified xtd::net::ip_address.
        /// @note You must create the xtd::net::sockets::udp_client using the multicast port number; otherwise, you will not be able to receive multicasted datagrams. Do not call the xtd::net::sockets::udp_client::connect method prior to calling the xtd::net::sockets::udp_client::join_multicast_group method, or the xtd::net::sockets::udp_client::receive method will not work. You do not need to belong to a multicast group to send datagrams to a multicast IP address.
        /// @remarks Before joining a multicast group, make sure the socket is bound to the port or endpoint. You do that by calling one of the constructors that accept a port or an endpoint as a parameter.
        /// @remarks To stop receiving multicasted datagrams, call the xtd::net::sockets::udp_client::drop_multicast_group method and provide the xtd::net::ip_address of the group from which you would like to withdraw.
        /// @note You cannot call xtd::net::sockets::udp_client::join_multicast_group on a xtd::net::sockets::udp_client constructed without a specific local port (that is, using the xtd::net::sockets::udp_client() or xtd::net::sockets::udp_client(xtd::net::sockets::address_family) constructor).
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        void join_multicast_group(const xtd::net::ip_address& multicast_address, byte_t ttl);
        /// @brief Adds a xtd::net::sockets::udp_client to a multicast group.
        /// @param multicast_address The multicast xtd::net::ip_address of the group you want to join.
        /// @param local_address The local xtd::net::ip_address.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the underlying socket.
        /// @exception xtd::object_closed_exception The underlying xtd::net::sockets::socket has been closed.
        /// @remarks Before joining a multicast group, make sure the socket is bound to the port or endpoint. You do that by calling one of the constructors that accept a port or an endpoint as a parameter.
        /// @note There are several multicast address ranges to choose from. Refer to the IETF RFC 2375.
        /// @note You cannot call xtd::net::sockets::udp_client::join_multicast_group on a xtd::net::sockets::udp_client constructed without a specific local port (that is, using the xtd::net::sockets::udp_client() or xtd::net::sockets::udp_client(xtd::net::sockets::address_family) constructor).
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        void join_multicast_group(const xtd::net::ip_address& multicast_address, const xtd::net::ip_address& local_address);

        /// @brief Returns a UDP datagram that was sent by a remote host.
        /// @param remote_end_point An xtd::net::ip_end_point that represents the remote host from which the data was sent.
        /// @return An array of type Byte that contains datagram data.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the underlying socket.
        /// @exception xtd::object_closed_exception The underlying xtd::net::sockets::socket has been closed.
        /// @remarks The xtd::net::sockets::udp_client::receive method will block until a datagram arrives from a remote host. When data is available, the xtd::net::sockets::udp_client::receive method will read the first enqueued datagram and return the data portion as a byte array. This method populates the remoteEP parameter with the xtd::net::ip_address and port number of the sender.
        /// @remarks If you specify a default remote host in the xtd::net::sockets::udp_client::connect method, the xtd::net::sockets::udp_client::receive method will accept datagrams from that host only. All other datagrams will be discarded.
        /// @remarks If you receive a xtd::net::sockets::socket_exception, use xtd::net::sockets::socket_exception.ErrorCode to obtain the specific error code. Once you have obtained this code, you can refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        /// @note If you intend to receive multicasted datagrams, do not call the xtd::net::sockets::udp_client::connect method prior to calling the xtd::net::sockets::udp_client::receive method. The xtd::net::sockets::udp_client you use to receive datagrams must be created using the multicast port number.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        std::vector<byte_t> receive(xtd::net::ip_end_point& remote_end_point);
        
        /// @brief xtd::net::sockets::udp_client::sends a UDP datagram to a specified port on a specified remote host.
        /// @param dgram An array of type Byte that specifies the UDP datagram that you intend to send represented as an array of bytes.
        /// @param bytes The number of bytes in the datagram.
        /// @param hostname The name of the remote host to which you intend to send the datagram.
        /// @param port The remote port number with which you intend to communicate.
        /// @return The number of bytes sent.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the underlying socket.
        /// @exception xtd::object_closed_exception The underlying xtd::net::sockets::socket has been closed.
        /// @remarks The xtd::net::sockets::udp_client::send method sends datagrams to the values specified by the hostname and port parameters and returns the number of bytes successfully sent. You can send datagrams to the default broadcast address by specifying "255.255.255.255" for the hostname parameter value.
        /// @remarks If you want to send datagrams to any other broadcast address, use thextd::net::sockets::udp_client::client method to obtain the underlying xtd::net::sockets::socket, and set the socket option to SocketOptionName.Broadcast. You can also revert to using the xtd::net::sockets::socket class.
        /// @note Do not provide a host name or port number to this method if you have already established a remote host with the xtd::net::sockets::udp_client::connect method. If you do, the xtd::net::sockets::udp_client::send method will throw a xtd::net::sockets::socket_exception. If you receive a xtd::net::sockets::socket_exception, use xtd::net::sockets::socket_exception.ErrorCode to obtain the specific error code. Once you have obtained this code, you can refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        size_t send(const std::vector<byte_t>& dgram, size_t bytes, const xtd::ustring& hostname, uint16_t port);
        /// @brief xtd::net::sockets::udp_client::sends a UDP datagram to the host at the specified remote endpoint.
        /// @param dgram An array of type Byte that specifies the UDP datagram that you intend to send, represented as an array of bytes.
        /// @param bytes The number of bytes in the datagram.
        /// @param end_point An xtd::net::ip_end_point that represents the host and port to which to send the datagram.
        /// @return The number of bytes sent.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the underlying socket.
        /// @exception xtd::object_closed_exception The underlying xtd::net::sockets::socket has been closed.
        /// @remarks The xtd::net::sockets::udp_client::send method sends datagrams to the specified endpoint and returns the number of bytes successfully sent. Before calling this overload, you must first create an xtd::net::ip_end_point using the IP address and port number of the remote host to which your datagrams will be delivered. You can send datagrams to the default broadcast address, 255.255.255.255, by specifying SocketOptionName.Broadcast for the Address property of the xtd::net::ip_end_point. After you have created this xtd::net::ip_end_point, pass it to the xtd::net::sockets::udp_client::send method as the endPoint parameter.
        /// @remarks If you want to send datagrams to any other broadcast address, use thextd::net::sockets::udp_client::client method to obtain the underlying xtd::net::sockets::socket, and set the socket option to SocketOptionName.Broadcast. You can also revert to using the xtd::net::sockets::socket class.
        /// @remarks Do not provide an endPoint parameter to this method if you have already established a remote host with the xtd::net::sockets::udp_client::connect method. If you do, the xtd::net::sockets::udp_client::send method will throw a xtd::net::sockets::socket_exception. If you receive a xtd::net::sockets::socket_exception, use xtd::net::sockets::socket_exception.ErrorCode to obtain the specific error code. Once you have obtained this code, you can refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        size_t send(const std::vector<byte_t>& dgram, size_t bytes, const xtd::net::ip_end_point& end_point);
        /// @brief xtd::net::sockets::udp_client::sends a UDP datagram to a remote host.
        /// @param dgram An array of type Byte that specifies the UDP datagram that you intend to send represented as an array of bytes.
        /// @param bytes The number of bytes in the datagram.
        /// @return The number of bytes sent.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the underlying socket.
        /// @exception xtd::object_closed_exception The underlying xtd::net::sockets::socket has been closed.
        /// @remarks This overload sends datagrams to the remote host established in the xtd::net::sockets::udp_client::connect method and returns the number of bytes sent. If you do not call xtd::net::sockets::udp_client::connect before calling this overload, the xtd::net::sockets::udp_client::send method will throw a xtd::net::sockets::socket_exception. If you receive a xtd::net::sockets::socket_exception, use xtd::net::sockets::socket_exception.ErrorCode to obtain the specific error code. Once you have obtained this code, you can refer to the Windows Sockets version 2 API error code documentation for a detailed description of the error.
        /// @remarks If you want to send datagrams to a different remote host, you must call the xtd::net::sockets::udp_client::connect method and specify the desired remote host. Use either of the other xtd::net::sockets::udp_client::send method overloads to send datagrams to a broadcast address.
        /// @note If you receive a xtd::net::sockets::socket_exception, use the xtd::net::sockets::socket_exception::error_code property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
        size_t send(const std::vector<byte_t>& dgram, size_t bytes);

      protected:        
        /// @brief Gets a value that indicates whether a connection has been made.
        /// @return bool true if the connection has been made; otherwise, false.
        /// @remarks Classes deriving from xtd::net::sockets::udp_client can use this property to determine if a default remote host has been established. You can establish a default remote host by using the appropriate constructor or by calling the xtd::net::sockets::udp_client::connect method. If you do establish a default remote host, you cannot specify a remote host in your call to xtd::net::sockets::udp_client::send.
        bool active() const noexcept;
        /// @brief Sets a value that indicates whether a connection has been made.
        /// @param value bool true if the connection has been made; otherwise, false.
        /// @return This current instance.
        /// @remarks Classes deriving from xtd::net::sockets::udp_client can use this property to determine if a default remote host has been established. You can establish a default remote host by using the appropriate constructor or by calling the xtd::net::sockets::udp_client::connect method. If you do establish a default remote host, you cannot specify a remote host in your call to xtd::net::sockets::udp_client::send.
        udp_client& active(bool value) noexcept;

      private:
        udp_client(const xtd::net::sockets::socket& socket);
        struct data;
        std::shared_ptr<data> data_;
      };
    }
  }
}
