/// @file
/// @brief Contains xtd::net::sockets::tcp_listener class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include "tcp_client.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief The xtd::net::sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
    namespace sockets {
      /// @brief Listens for connections from TCP network clients.
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core net
      /// @remarks The xtd::net::sockets::tcp_listener class provides simple methods that listen for and accept incoming connection requests in blocking synchronous mode. You can use either a xtd::net::sockets::tcp_client or a xtd::net::sockets::socket to connect with a xtd::net::sockets::tcp_listener. Create a xtd::net::sockets::tcp_listener using an xtd::net::ip_end_point, a Local IP address and port number, or just a port number. Specify Any for the local IP address and 0 for the local port number if you want the underlying service provider to assign those values for you. If you choose to do this, you can use the xtd::net::sockets::tcp_listener::local_end_point property to identify the assigned information, after the socket has connected.
      /// @remarks Use the xtd::net::sockets::tcp_listener::start method to begin listening for incoming connection requests. xtd::net::sockets::tcp_listener::start will queue incoming connections until you either call the xtd::net::sockets::tcp_listener::stop method or it has queued xtd::net::sockets::socket_option_name::max_connections. Use either xtd::net::sockets::tcp_listener::accept_socket or xtd::net::sockets::tcp_listener::accept_tcp_client to pull a connection from the incoming connection request queue. These two methods will block. If you want to avoid blocking, you can use the xtd::net::sockets::tcp_listener::pending method first to determine if connection requests are available in the queue.
      /// @remarks Call the xtd::net::sockets::tcp_listener::stop method to close the xtd::net::sockets::tcp_listener.
      /// @note The xtd::net::sockets::tcp_listener::stop method does not close any accepted connections. You are responsible for closing these separately.
      /// @par Examples
      /// The following example shows how to use IPv4 xtd::net::sockets::tcp_listener class with use xtd::net::sockets::tcp_client, xtd::net::sockets::network_stream, xtd::net::sockets::socket, xtd::io::stream_reader and xtd::io::stream_writer classes.
      /// @include tcp_client_ip_v4.cpp
      /// @par Examples
      /// The following example shows how to use IPv6 xtd::net::sockets::tcp_listener class with use xtd::net::sockets::tcp_client, xtd::net::sockets::network_stream, xtd::net::sockets::socket, xtd::io::stream_reader and xtd::io::stream_writer classes.
      /// @include tcp_client_ip_v6.cpp
      class tcp_listener : public xtd::object {
      public:
        /// @brief Initializes a new instance of the xtd::net::sockets::tcp_listener class with the specified local endpoint.
        /// @param local_end_point An xtd::net::ip_end_point that represents the local endpoint to which to bind the listener xtd::net::sockets::socket.
        /// @remarks This constructor allows you to specify the local IP address and port number on which to listen for incoming connection attempts.
        /// @remarks Before using this constructor, you must create an xtd::net::ip_end_point using the desired local IP address and port number. Pass this xtd::net::ip_end_point to the constructor as the local_end_point parameter.
        /// @remarks If you do not care which local address is assigned, you can create an xtd::net::ip_end_point using xtd::net::ip_address::any as the address parameter, and the underlying service provider will assign the most appropriate network address. This might help simplify your application if you have multiple network interfaces. If you do not care which local port is used, you can create an xtd::net::ip_end_point using 0 for the port number. In this case, the service provider will assign an available port number between 1024 and 5000. If you use this approach, you can discover what local network address and port number has been assigned by using the xtd::net::sockets::tcp_listener::local_end_point property.
        /// @remarks Call the xtd::net::sockets::tcp_listener::start method to begin listening for incoming connection attempts.
        /// @note The 0 for local port functionality is not available.
        explicit tcp_listener(const xtd::net::ip_end_point& local_end_point);
        
        /// @brief Initializes a new instance of the xtd::net::sockets::tcp_listener class that listens for incoming connection attempts on the specified local IP address and port number.
        /// @param ip_address An xtd::net::ip_address that represents the local IP address.
        /// @param port The port on which to listen for incoming connection attempts.
        /// @remarks This constructor allows you to specify the local IP address and port number on which to listen for incoming connection attempts.
        /// @remarks Before calling this constructor you must first create an xtd::net::ip_address using the desired local address. Pass this xtd::net::ip_address to the constructor as the ip_address parameter.
        /// @remarks If you do not care which local address is assigned, specify xtd::net::ip_address::any for the localaddr parameter, and the underlying service provider will assign the most appropriate network address. This might help simplify your application if you have multiple network interfaces. If you do not care which local port is used, you can specify 0 for the port number. In this case, the service provider will assign an available port number between 1024 and 5000. If you use this approach, you can discover what local network address and port number has been assigned by using the xtd::net::sockets::tcp_listener::local_end_point property.
        /// @remarks Call the xtd::net::sockets::tcp_listener::start method to begin listening for incoming connection attempts.
        /// @note The 0 for local port functionality is not available.
        tcp_listener(const xtd::net::ip_address& ip_address, uint16_t port);
        
        /// @cond
        tcp_listener(tcp_listener&&) = default;
        tcp_listener(const tcp_listener&) = default;
        ~tcp_listener();
        tcp_listener& operator=(const tcp_listener&) = default;
        friend std::ostream& operator <<(std::ostream& os, const tcp_listener& tl) noexcept {return os << tl.to_string();}
        bool operator==(const tcp_listener& s) const {return data_ == s.data_;};
        bool operator!=(const tcp_listener& s) const {return !operator==(s);};
        /// @endcond
        
        /// @brief Gets a bool value that specifies whether the xtd::net::sockets::tcp_listener allows only one underlying socket to listen to a specific port.
        /// @return true if the xtd::net::sockets::tcp_listener allows only one xtd::net::sockets::tcp_listener to listen to a specific port; otherwise, false. .
        /// @exception xtd::invalid_operation_exception The xtd::net::sockets::tcp_listener has been started. Call the xtd::net::sockets::tcp_listener::stop() method and then set the xtd::net::sockets::tcp_listener::exclusive_address_use property.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks By default, multiple listeners can listen to a specific port. However, only one of the listeners can perform operations on the network traffic sent to the port.
        /// @remarks If more than one listener attempts to bind to a particular port, then the one with the more specific IP address handles the network traffic sent to that port.
        /// @remarks You can use the xtd::net::sockets::tcp_listener::exclusive_address_use property to prevent multiple listeners from listening to a specific port.
        /// @remarks Set this property before calling xtd::net::sockets::tcp_listener::start, or call the xtd::net::sockets::tcp_listener::stop method and then set this property.
        bool exclusive_address_use() const;
        /// @brief Sets a bool value that specifies whether the xtd::net::sockets::tcp_listener allows only one underlying socket to listen to a specific port.
        /// @param value true if the xtd::net::sockets::tcp_listener allows only one xtd::net::sockets::tcp_listener to listen to a specific port; otherwise, false. .
        /// @return This current instance.
        /// @exception xtd::invalid_operation_exception The xtd::net::sockets::tcp_listener has been started. Call the xtd::net::sockets::tcp_listener::stop() method and then set the xtd::net::sockets::tcp_listener::exclusive_address_use property.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks By default, multiple listeners can listen to a specific port. However, only one of the listeners can perform operations on the network traffic sent to the port.
        /// @remarks If more than one listener attempts to bind to a particular port, then the one with the more specific IP address handles the network traffic sent to that port.
        /// @remarks You can use the xtd::net::sockets::tcp_listener::exclusive_address_use property to prevent multiple listeners from listening to a specific port.
        /// @remarks Set this property before calling xtd::net::sockets::tcp_listener::start, or call the xtd::net::sockets::tcp_listener::stop method and then set this property.
        tcp_listener& exclusive_address_use(bool value);

        /// @brief Gets the underlying xtd::net::end_point of the current xtd::net::sockets::tcp_listener.
        /// @return The xtd::net::end_point to which the xtd::net::sockets::socket is bound.
        /// @remarks You can use the xtd::net::sockets::tcp_listener::local_end_point property to identify the local network interface and port number being used to listen for incoming client connection requests, after a socket connection has been made. You must first cast this xtd::net::end_point to an xtd::net::ip_end_point. You can then call the xtd::net::ip_end_point::address property to retrieve the local IP address, and the xtd::net::ip_end_point::port property to retrieve the local port number.
        const xtd::net::end_point& local_end_point() const noexcept;
        
        /// @brief Gets the underlying network xtd::net::sockets::socket.
        /// @return The underlying xtd::net::sockets::socket.
        /// @remarks xtd::net::sockets::tcp_listener creates a xtd::net::sockets::socket to listen for incoming client connection requests. Classes deriving from xtd::net::sockets::tcp_listener can use this property to get this xtd::net::sockets::socket.
        /// @remarks Use the underlying xtd::net::sockets::socket returned by the xtd::net::sockets::tcp_listener::server property if you require access beyond that which xtd::net::sockets::tcp_listener provides.
        /// @note The xtd::net::sockets::tcp_listener::server property only returns the xtd::net::sockets::socket used to listen for incoming client connection requests. Use the xtd::net::sockets::tcp_listener::accept_socket method to accept a pending connection request and obtain a xtd::net::sockets::socket for sending and receiving data. You can also use the xtd::net::sockets::tcp_listener::accept_tcp_client method to accept a pending connection request and obtain a xtd::net::sockets::tcp_client for sending and receiving data.
        xtd::net::sockets::socket server() const noexcept;
        
        /// @brief Accepts a pending connection request.
        /// @return A xtd::net::sockets::socket used to send and receive data.
        /// @exception xtd::invalid_operation_exception The listener has not been started with a call to xtd::net::sockets::tcp_listener::start.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @remarks xtd::net::sockets::tcp_listener::accept_socket is a blocking method that returns a xtd::net::sockets::socket that you can use to send and receive data. If you want to avoid blocking, use the xtd::net::sockets::tcp_listener::pending method to determine if connection requests are available in the incoming connection queue.
        /// @remarks The xtd::net::sockets::socket returned is initialized with the IP address and port number of the remote host.
        /// @remarks You can use any of the xtd::net::sockets::socket::send and xtd::net::sockets::socket::receive methods available in the xtd::net::sockets::socket class to communicate with the remote host. When you are finished using the xtd::net::sockets::socket, be sure to call its xtd::net::sockets::tcp_listener::close method. If your application is relatively simple, consider using the xtd::net::sockets::tcp_listener::accept_tcp_client method rather than the xtd::net::sockets::tcp_listener::accept_socket method.
        /// @remarks xtd::net::sockets::tcp_client provides you with simple methods for sending and receiving data over a network in blocking synchronous mode.
        xtd::net::sockets::socket accept_socket();
        
        /// @brief Accepts a pending connection request.
        /// @return A xtd::net::sockets::tcp_client used to send and receive data.
        /// @exception xtd::invalid_operation_exception The listener has not been started with a call to xtd::net::sockets::tcp_listener::start.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @remarks xtd::net::sockets::tcp_listener::accept_tcp_client is a blocking method that returns a xtd::net::sockets::tcp_client that you can use to send and receive data. Use the xtd::net::sockets::tcp_listener::pending method to determine if connection  requests are available in the incoming connection queue if you want to avoid blocking.
        /// @remarks Use the xtd::net::sockets::tcp_client::get_stream method to obtain the underlying xtd::net::sockets::network_stream of the returned xtd::net::sockets::tcp_client. The xtd::net::sockets::network_stream will provide you with methods for sending and receiving with the remote host. When you are through with the xtd::net::sockets::tcp_client, be sure to call its xtd::net::sockets::tcp_listener::close method. If you want greater flexibility than a xtd::net::sockets::tcp_client offers, consider using xtd::net::sockets::tcp_listener::accept_socket.
        xtd::net::sockets::tcp_client accept_tcp_client();
        
        /// @brief Creates a new xtd::net::sockets::tcp_listener instance to listen on the specified port.
        /// @param port The port on which to listen for incoming connection attempts.
        /// @return xtd::net::sockets::tcp_listener A new xtd::net::sockets::tcp_listener instance to listen on the specified port.
        static tcp_listener create(uint16_t port);
        
        /// @brief Determines if there are pending connection requests.
        /// @return true if connections are pending; otherwise, false.
        /// @exception xtd::invalid_operation_exception The listener has not been started with a call to xtd::net::sockets::tcp_listener::start.
        /// @remarks This non-blocking method determines if there are any pending connection requests. Because the xtd::net::sockets::tcp_listener::accept_socket and xtd::net::sockets::tcp_listener::accept_tcp_client methods block execution until
        /// @remarks the xtd::net::sockets::tcp_listener::start method has queued an incoming connection request, the xtd::net::sockets::tcp_listener::pending method can be used to determine if connections are available before attempting to accept them.
        bool pending();

        /// @brief xtd::net::sockets::tcp_listener::starts listening for incoming connection requests.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @remarks The xtd::net::sockets::tcp_listener::start method initializes the underlying xtd::net::sockets::socket, binds it to a local endpoint, and listens for incoming connection attempts. If a connection request is received, the xtd::net::sockets::tcp_listener::start method will queue the request and continue listening for additional requests until you call the xtd::net::sockets::tcp_listener::stop method. If xtd::net::sockets::tcp_listener receives a connection request after it has already queued the maximum number of connections, it will throw a xtd::net::sockets::socket_exception on the client.
        /// @remarks To remove a connection from the incoming connection queue, use either the xtd::net::sockets::tcp_listener::accept_tcp_client method or the xtd::net::sockets::tcp_listener::accept_socket method. The xtd::net::sockets::tcp_listener::accept_tcp_client method will remove a connection from the queue and return a xtd::net::sockets::tcp_client that you can use to send and receive data. The xtd::net::sockets::tcp_listener::accept_socket method will return a xtd::net::sockets::socket that you can use to do the same. If your application only requires synchronous I/O, use xtd::net::sockets::tcp_listener::accept_tcp_client. For more detailed behavioral control, use xtd::net::sockets::tcp_listener::accept_socket. Both of these methods block until a connection request is available in the queue.
        /// @remarks Use the xtd::net::sockets::tcp_listener::stop method to close the xtd::net::sockets::tcp_listener and stop listening. You are responsible for closing your accepted connections separately.
        void start();
        
        /// @brief xtd::net::sockets::tcp_listener::starts listening for incoming connection requests with a maximum number of pending connection.
        /// @param backlog The maximum length of the pending connections queue.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception ArgumentOutOfRangeException The backlog parameter is less than zero or exceeds the maximum number of permitted connections.
        /// @exception xtd::invalid_operation_exception The underlying xtd::net::sockets::socket is null.
        /// @remarks The xtd::net::sockets::tcp_listener::start method initializes the underlying xtd::net::sockets::socket, binds it to a local endpoint, and listens for incoming connection attempts. If a connection request is received, the xtd::net::sockets::tcp_listener::start method will queue the request and continue listening for additional requests until you call the xtd::net::sockets::tcp_listener::stop method. If xtd::net::sockets::tcp_listener receives a connection request after it has already queued the maximum number of connections, it will throw a xtd::net::sockets::socket_exception on the client.
        /// @remarks To remove a connection from the incoming connection queue, use either the xtd::net::sockets::tcp_listener::accept_tcp_client method or the xtd::net::sockets::tcp_listener::accept_socket method. The xtd::net::sockets::tcp_listener::accept_tcp_client method will remove a connection from the queue and return a xtd::net::sockets::tcp_client that you can use to send and receive data. The xtd::net::sockets::tcp_listener::accept_socket method will return a xtd::net::sockets::socket that you can use to do the same. If your application only requires synchronous I/O, use xtd::net::sockets::tcp_listener::accept_tcp_client. For more detailed behavioral control, use xtd::net::sockets::tcp_listener::accept_socket. Both of these methods block until a connection request is available in the queue.
        /// @remarks Use the xtd::net::sockets::tcp_listener::stop method to close the xtd::net::sockets::tcp_listener and stop listening. You are responsible for closing your accepted connections separately.
        void start(size_t backlog);
        
        /// @brief Closes the listener.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @remarks xtd::net::sockets::tcp_listener::stop closes the listener. Any unaccepted connection requests in the queue will be lost. Remote hosts waiting for a connection to be accepted will throw a xtd::net::sockets::socket_exception. You are responsible for closing your accepted connections separately.
        /// @note The xtd::net::sockets::tcp_listener::stop method also closes the underlying xtd::net::sockets::socket, and creates a new xtd::net::sockets::socket for the xtd::net::sockets::tcp_listener. If you set any properties on the underlying xtd::net::sockets::socket prior to calling the xtd::net::sockets::tcp_listener::stop method, those properties will not carry over to the new xtd::net::sockets::socket.
        void stop();

      protected:
        /// @brief Gets a value that indicates whether xtd::net::sockets::tcp_listener is actively listening for client connections.
        /// @return true if xtd::net::sockets::tcp_listener is actively listening; otherwise, false.
        /// @remarks Classes deriving from xtd::net::sockets::tcp_listener can use this property to determine if the xtd::net::sockets::socket is currently listening for incoming connection attempts.
        /// @remarks The Active property can be used to avoid redundant xtd::net::sockets::tcp_listener::start attempts.
        bool active() const noexcept;

      private:
        struct data;
        std::shared_ptr<data> data_;
      };
    }
  }
}
