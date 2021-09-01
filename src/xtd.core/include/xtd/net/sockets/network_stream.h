/// @file
/// @brief Contains xtd::net::sockets::network_stream class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <iostream>
#include "socket.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief The xtd::net::sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
    namespace sockets {
      /// @brief Provides the underlying stream of data for network access.
      /// @par Namespace
      /// xtd::net::sockets
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core net
      /// @remarks The xtd::net::sockets::network_stream class provides methods for sending and receiving data over sttd::iostrream sockets in blocking mode. You can use the xtd::net::sockets::network_stream class for both synchronous and asynchronous data transfer.
      /// @remarks To create a xtd::net::sockets::network_stream, you must provide a connected xtd::net::sockets::socket. By default, closing the xtd::net::sockets::network_stream does not close the provided xtd::net::sockets::socket. If you want the xtd::net::sockets::network_stream to have permission to close the provided xtd::net::sockets::socket, you must specify true for the value of the owns_socket parameter.
      /// @remarks Use the std::iostream::write and std::iostream::read methods for simple single thread synchronous blocking I/O.
      /// @remarks The xtd::net::sockets::network_stream does not support random access to the network data stream.
      /// @remarks std::iostream::read and std::iostream::write operations can be performed simultaneously on an instance of the xtd::net::sockets::network_stream class without the need for synchronization. As long as there is one unique thread for the write operations and one unique thread for the read operations, there will be no cross-interference between read and write threads and no synchronization is required.
      /// @par Examples
      /// The following example shows how to use xtd::net::sockets::network_stream class with xtd::net::sockets::socket, xtd::io::stream_reader and xtd::io::stream_writer classes.
      /// @include network_stream.cpp
      class network_stream : public std::iostream {
        class socket_streambuf : public std::streambuf {
        public:
          socket_streambuf(const xtd::net::sockets::socket& socket, bool owns_socket);
          ~socket_streambuf();
          
          int underflow() override;
          int overflow(int value) override;
          
          xtd::net::sockets::socket socket_;
          bool owns_socket_ = false;
          char value_ = EOF;
        };
        
      public:
        /// @brief Creates a new instance of the network_stream class for the specified xtd::net::sockets::socket.
        /// @param socket The xtd::net::sockets::socket that the xtd::net::sockets::network_stream will use to send and receive data.
        /// @remarks The xtd::net::sockets::network_stream is created with read/write access to the specified xtd::net::sockets::socket. The xtd::net::sockets::network_stream does not own the underlying xtd::net::sockets::socket, so calling the close method does not close the xtd::net::sockets::socket.
        network_stream(const xtd::net::sockets::socket& socket);

        /// @brief Initializes a new instance of the xtd::net::sockets::network_stream class for the specified xtd::net::sockets::socket with the specified xtd::net::sockets::socket ownership.
        /// @param socket The xtd::net::sockets::socket that the xtd::net::sockets::network_stream will use to send and receive data.
        /// @param owns_socket Set to true to indicate that the xtd::net::sockets::network_stream will take ownership of the xtd::net::sockets::socket; otherwise, false.
        /// @remarks The xtd::net::sockets::network_stream is created with read/write access to the specified xtd::net::sockets::socket. If the value of owns_socket parameter is true, the xtd::net::sockets::network_stream takes ownership of the underlying xtd::net::sockets::socket, and calling the close method also closes the underlying xtd::net::sockets::socket.
        network_stream(const xtd::net::sockets::socket& socket, bool owns_socket);

        /// @brief Gets a value that indicates whether data is available on the xtd::net::sockets::network_stream to be read.
        /// @return true if data is available on the stream to be read; otherwise, false.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks Use the xtd::net::sockets::network_stream::data_available property to determine if data is ready to be read. If xtd::net::sockets::network_stream::data_available is true, a call to std::iostream::read returns immediately. If the remote host shuts down or closes the connection, xtd::net::sockets::network_stream::data_available may throw a xtd::net::sockets::socket_exception.
        virtual bool data_availlable() const;
        
        /// @brief Gets the underlying xtd::net::sockets::socket.
        /// @return A xtd::net::sockets::socket that represents the underlying network connection.
        /// @remarks Classes deriving from xtd::net::sockets::network_stream can use this property to get the underlying xtd::net::sockets::socket. Use the underlying xtd::net::sockets::socket returned from the xtd::net::sockets::socketproperty if you require access beyond that which xtd::net::sockets::network_stream provides.
        xtd::net::sockets::socket socket() const;
        
      private:
        socket_streambuf stream_buf_;
      };
    }
  }
}
