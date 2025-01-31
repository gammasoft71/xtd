/// @file
/// @brief Contains xtd::net::sockets::network_stream class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "socket.hpp"
#include "../../io/file_access.hpp"
#include "../../io/stream.hpp"
#include "../../object_closed_exception.hpp"
#include "../../not_supported_exception.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief The xtd::net::sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
    namespace sockets {
      /// @brief Provides the underlying stream of data for network access.
      /// ```cpp
      /// class core_export_ network_stream : public xtd::io::stream;
      /// ```
      /// @par Inheritance
      /// xtd::object → xtd::abstract_object → xtd::io::stream → xtd::net::sockets::network_stream
      /// @par Header
      /// ```cpp
      /// #include <xtd/net/sockets/network_stream>
      /// ```
      /// @par Namespace
      /// xtd::net::sockets
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core net
      /// @remarks The xtd::net::sockets::network_stream class provides methods for sending and receiving data over std::iostream sockets in blocking mode. You can use the xtd::net::sockets::network_stream class for both synchronous and asynchronous data transfer.
      /// @remarks To create a xtd::net::sockets::network_stream, you must provide a connected xtd::net::sockets::socket. By default, closing the xtd::net::sockets::network_stream does not close the provided xtd::net::sockets::socket. If you want the xtd::net::sockets::network_stream to have permission to close the provided xtd::net::sockets::socket, you must specify `true` for the value of the owns_socket parameter.
      /// @remarks Use the std::iostream::write and std::iostream::read methods for simple single thread synchronous blocking I/O.
      /// @remarks The xtd::net::sockets::network_stream does not support random access to the network data stream.
      /// @remarks std::iostream::read and std::iostream::write operations can be performed simultaneously on an instance of the xtd::net::sockets::network_stream class without the need for synchronization. As long as there is one unique thread for the write operations and one unique thread for the read operations, there will be no cross-interference between read and write threads and no synchronization is required.
      /// @par Examples
      /// The following example shows how to use xtd::net::sockets::network_stream class with xtd::net::sockets::socket, xtd::io::stream_reader and xtd::io::stream_writer classes.
      /// @include network_stream.cpp
      class core_export_ network_stream : public xtd::io::stream {
      public:
        /// @name Public Constructors
        
        /// @{
        /// @brief Creates a new instance of the network_stream class for the specified xtd::net::sockets::socket.
        /// @param socket The xtd::net::sockets::socket that the xtd::net::sockets::network_stream will use to send and receive data.
        /// @remarks The xtd::net::sockets::network_stream is created with read/write access to the specified xtd::net::sockets::socket. The xtd::net::sockets::network_stream does not own the underlying xtd::net::sockets::socket, so calling the close method does not close the xtd::net::sockets::socket.
        explicit network_stream(const xtd::net::sockets::socket& socket);
        
        /// @brief Initializes a new instance of the xtd::net::sockets::network_stream class for the specified xtd::net::sockets::socket with the specified xtd::net::sockets::socket ownership.
        /// @param socket The xtd::net::sockets::socket that the xtd::net::sockets::network_stream will use to send and receive data.
        /// @param owns_socket Set to `true` to indicate that the xtd::net::sockets::network_stream will take ownership of the xtd::net::sockets::socket; otherwise, `false`.
        /// @remarks The xtd::net::sockets::network_stream is created with read/write access to the specified xtd::net::sockets::socket. If the value of owns_socket parameter is `true`, the xtd::net::sockets::network_stream takes ownership of the underlying xtd::net::sockets::socket, and calling the close method also closes the underlying xtd::net::sockets::socket.
        network_stream(const xtd::net::sockets::socket& socket, bool owns_socket);

        /// @brief Initializes a new instance of the network_stream class for the specified xtd::net::sockets::socket with the specified access rights.
        /// @param socket The xtd::net::sockets::socket that the xtd::net::sockets::network_stream will use to send and receive data.
        /// @param access A bitwise combination of the xtd::io::file_access values that specify the type of access given to the xtd::net::sockets::network_stream over the provided xtd::net::sockets::socket.
        network_stream(const xtd::net::sockets::socket& socket, xtd::io::file_access access);
        /// @brief Initializes a new instance of the network_stream class for the specified xtd::net::sockets::socket with the specified access rights and the specified xtd::net::sockets::socket ownership.
        /// @param socket The xtd::net::sockets::socket that the xtd::net::sockets::network_stream will use to send and receive data.
        /// @param access A bitwise combination of the xtd::io::file_access values that specify the type of access given to the xtd::net::sockets::network_stream over the provided xtd::net::sockets::socket.
        /// @param owns_socket Set to `true` to indicate that the xtd::net::sockets::network_stream will take ownership of the xtd::net::sockets::socket; otherwise, `false`.
        network_stream(const xtd::net::sockets::socket& socket, xtd::io::file_access access, bool owns_socket);
        /// @}
        
        /// @cond
        ~network_stream();
        /// @endcond
        
        /// @name Public Properties
        
        /// @{
        /// @brief Gets a value indicating whether the current stream supports reading.
        /// @return `true` if the stream supports reading; otherwise, `false`.
        bool can_read() const noexcept override;
        
        /// @brief Gets a value indicating whether the current stream supports seeking.
        /// @return `true` if the stream supports seeking; otherwise, `false`.
        bool can_seek() const noexcept override;
        
        /// @brief Indicates whether timeout properties are usable for xtd::net::sockets::network_stream.
        /// @return `true` in all cases.
        bool can_timeout() const noexcept override;
        
        /// @brief Gets a value indicating whether the current stream supports writing.
        /// @return `true` if the stream supports writing; otherwise, `false`.
        bool can_write() const noexcept override;
        
        /// @brief Gets a value that indicates whether data is available on the xtd::net::sockets::network_stream to be read.
        /// @return `true` if data is available on the stream to be read; otherwise, `false`.
        /// @exception xtd::net::sockets::socket_exception An error occurred when attempting to access the socket.
        /// @exception xtd::object_closed_exception The xtd::net::sockets::socket has been closed.
        /// @remarks Use the xtd::net::sockets::network_stream::data_available property to determine if data is ready to be read. If xtd::net::sockets::network_stream::data_available is `true`, a call to std::iostream::read returns immediately. If the remote host shuts down or closes the connection, xtd::net::sockets::network_stream::data_available may throw a xtd::net::sockets::socket_exception.
        virtual bool data_available() const;
        
        /// @brief Gets the length of the stream in bytes.
        /// @return The length of the stream in bytes.
        xtd::size length() const override;
        
        /// @brief Gets the current position within the stream.
        /// @return The current position within the stream.
        xtd::size position() const override;
        /// @brief Sets the current position within the stream.
        /// @param value The current position within the stream.
        void position(xtd::size value) override;
        
        /// @brief Gets the amount of time that a read operation blocks waiting for data.
        /// @return A xtd::int32 that specifies the amount of time, in milliseconds, that will elapse before a read operation fails. The default value, xtd::threading::timeout::infinite, specifies that the read operation does not time out.
        int32 read_timeout() const override;
        /// @brief Sets the amount of time that a read operation blocks waiting for data.
        /// @param value A xtd::int32 that specifies the amount of time, in milliseconds, that will elapse before a read operation fails. The default value, xtd::threading::timeout::infinite, specifies that the read operation does not time out.
        void read_timeout(int32 value) override;
        
        /// @brief Gets the amount of time that a write operation blocks waiting for data.
        /// @return A xtd::int32 that specifies the amount of time, in milliseconds, that will elapse before a read operation fails. The default value, xtd::threading::timeout::infinite, specifies that the read operation does not time out.
        int32 write_timeout() const override;
        /// @brief Sets the amount of time that a write operation blocks waiting for data.
        /// @param value A xtd::int32 that specifies the amount of time, in milliseconds, that will elapse before a read operation fails. The default value, xtd::threading::timeout::infinite, specifies that the read operation does not time out.
        void write_timeout(int32 value) override;
        
        /// @brief Gets the underlying xtd::net::sockets::socket.
        /// @return A xtd::net::sockets::socket that represents the underlying network connection.
        /// @remarks Classes deriving from xtd::net::sockets::network_stream can use this property to get the underlying xtd::net::sockets::socket. Use the underlying xtd::net::sockets::socket returned from the xtd::net::sockets::socket property if you require access beyond that which xtd::net::sockets::network_stream provides.
        xtd::net::sockets::socket socket() const;
        /// @}
        
        /// @name Public Methods
        
        /// @{
        /// @brief Flushes data from the stream. This method is reserved for future use.
        /// @remarks The Flush method implements the xtd::io::stream::flush method; however, because xtd::net::sockets::network_stream is not buffered, it has no effect on network streams. Calling the xtd::net::sockets::network_stream::flush method does not throw an exception.
        void flush() override;

        using xtd::io::stream::read;
        /// @brief Reads a block of bytes from the current stream and writes the data to a buffer.
        /// @param buffer When this method returns, contains the specified byte array with the values between `offset` and (`offset` + `count` - 1) replaced by the characters read from the current stream.
        /// @param offset The zero-based byte offset in buffer at which to begin storing data from the current stream.
        /// @param count The maximum number of bytes to read.
        /// @return The total number of bytes written into the buffer. This can be less than the number of bytes requested if that number of bytes are not currently available, or zero if the end of the stream is reached before any bytes are read.
        /// @remarks The `offset` parameter gives the offset of the first byte in `buffer` to which data from the current stream is written. The `count` parameter gives the maximum number of bytes to read from the current stream. The returned value is the actual number of bytes read, or zero if the end of the stream is reached.
        /// @remarks If the read operation is successful, the current position within the stream advances by the number of bytes read. If an exception occurs, the current position within the stream remains unchanged.
        /// @remarks The `read` method will return zero only if the end of the stream is reached. In all other cases, `read` always reads at least one byte from the stream before returning. By definition, if no data is available from the stream upon a call to `read`, the `read` method returns zero (the end of the stream is reached automatically). An implementation is free to return fewer bytes than requested even if the end of the stream has not been reached.
        /// @remarks Use xtd::io::binary_reader for reading primitive data types.
        xtd::size read(xtd::array<xtd::byte>& buffer, size offset, size count) override;
        
        /// @brief Sets the length of the current stream to the specified value.
        /// @param value The value at which to set the length.
        /// @remarks If the specified value is less than the current length of the stream, the stream is truncated. If after the truncation the current position within the stream is past the end of the stream, the xtd::io::memery_stream::read_byte method returns -1, the xtd::io::memery_stream::read method reads zero bytes into the provided byte array, and xtd::io::memery_stream::write and xtd::io::memery_stream::write_byte methods append specified bytes at the end of the stream, increasing its length. If the specified value is larger than the current capacity and the stream is resizable, the capacity is increased, and the current position within the stream is unchanged. If the length is increased, the contents of the stream between the old and the new length are initialized to zeros.
        void set_length(xtd::size value) override;
        
        using xtd::io::stream::write;
        /// @brief Writes a block of bytes to the current stream using data read from a buffer.
        /// @param buffer The buffer to write data from.
        /// @param offset The zero-based byte offset in buffer at which to begin copying bytes to the current stream.
        /// @param count The maximum number of bytes to write.
        /// @par Examples
        /// This code example is part of a larger example provided for the xtd::io::memory_stream class.
        /// ```cpp
        /// // Write the first string to the stream.
        /// mem_stream.write(first_string, 0 , first_string.length());
        /// ```
        /// @remarks The `offset` parameter gives the offset of the first byte in `buffer` to write from, and the `count` parameter gives the number of bytes to write. If the write operation is successful, the current position within the stream is advanced by the number of bytes written. If an exception occurs, the current position within the stream is unchanged.
        /// @remarks Except for a `memory_stream` constructed with a byte[] parameter, write operations at the end of a `memory_stream` expand the `memory_stream`.
        void write(const xtd::array<xtd::byte>& buffer, size offset, size count) override;
        /// @}
        
      private:
        struct data {
          xtd::net::sockets::socket socket;
          xtd::io::file_access access = xtd::io::file_access::read_write;
          bool owns_socket = false;
        };
        ptr<data> data_ = new_ptr<data>();
      };
    }
  }
}
