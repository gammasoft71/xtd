/// @file
/// @brief Contains xtd::net::sockets::send_packets_element class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <fstream>
#include <functional>
#include <vector>
#include "../../ustring.h"
#include "../ip_address.h"

/// @cond
#undef unix
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief The xtd::net::sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
    namespace sockets {
      /// @cond
      class socket;
      /// @endcond
      
      /// @brief Represents an element in a xtd::net::sockets::send_packets_element array.
      /// @remarks The xtd::net::sockets::send_packets_element class is used to enhance the xtd::net::sockets::socket class for use by server applications that use asynchronous network I/O to achieve the highest performance. The xtd::net::sockets::send_packets_element class is used with the xtd::net::sockets::socket_async_event_args::send_packets_elements property to get or set a data buffer or file to be sent using the xtd::net::sockets::socket::send_packets_async method.
      class send_packets_element {
      public:
        /// @brief Represent ta std::ifsttrream reference.
        using ifstream_ref = std::reference_wrapper<std::ifstream>;
        
        /// @brief Initializes a new instance of the xtd::net::sockets::send_packets_element class
        send_packets_element() = default;
        
        /// @brief Initializes a new instance of the xtd::net::sockets::send_packets_element class using the specified buffer.
        /// @param buffer A byte array of data to send using the xtd::net::sockets::socket::send_packets_async method.
        /// @remarks The xtd::net::sockets::send_packets_element class is used with the xtd::net::sockets::socket::socket_async_event_args::send_packets_elements property to get or set a data buffer or file to be sent using the xtd::net::sockets::socket::socket::send_packets_async method.
        send_packets_element(const std::vector<byte_t>& buffer);

        /// @brief Initializes a new instance of the xtd::net::sockets::send_packets_element class using the specified range of the file with an option to combine this element with the next element in a single send request from the sockets layer to the transport.
        /// @param file_path The filename of the file to be transmitted using the xtd::net::sockets::socket::send_packets_async method.
        /// @param offset The offset, in bytes, from the beginning of the file to the location in the file to start sending the file specified in the file_path parameter.
        /// @param count The number of bytes to send starting from the offset parameter. If count is zero, the entire file is sent.
        /// @param end_of_packet Specifies that this element should not be combined with the next element in a single send request from the sockets layer to the transport. This flag is used for granular control of the content of each message on a datagram or message-oriented socket.
        /// @remarks The xtd::net::sockets::send_packets_element class is used with the xtd::net::sockets::socket::socket_async_event_args::send_packets_elements property to get or set a data buffer or file to be sent using the xtd::net::sockets::socket::socket::send_packets_async method.
        /// @remarks Universal Naming Convention (UNC) paths are supported by the file_path parameter. If the file is in the current working directory, no path information needs to be specified.
        send_packets_element(const xtd::ustring& file_path, size_t offset, size_t count, bool end_of_packet);

        /// @brief Initializes a new instance of the xtd::net::sockets::send_packets_element class using the specified range of the buffer with an option to combine this element with the next element in a single send request from the sockets layer to the transport.
        /// @param buffer A byte array of data to send using the xtd::net::sockets::socket::send_packets_async method.
        /// @param offset The offset, in bytes, from the beginning of the buffer to the location in the buffer to start sending the data specified in the buffer parameter.
        /// @param count The number bytes to send starting from the offset parameter. If count is zero, no bytes are sent.
        /// @param end_of_packet Specifies that this element should not be combined with the next element in a single send request from the sockets layer to the transport. This flag is used for granular control of the content of each message on a datagram or message-oriented socket.
        /// @remarks The xtd::net::sockets::send_packets_element class is used with the xtd::net::sockets::socket::socket_async_event_args::send_packets_elements property to get or set a data buffer or file to be sent using the xtd::net::sockets::socket::socket::send_packets_async method.
        send_packets_element(const std::vector<byte_t>& buffer, size_t offset, size_t count, bool end_of_packet);

        /// @brief Initializes a new instance of the xtd::net::sockets::send_packets_element class using the specified range of the file with an option to combine this element with the next element in a single send request from the sockets layer to the transport.
        /// @param file_path The filename of the file to be transmitted using the xtd::net::sockets::socket::send_packets_async method.
        /// @param offset The offset, in bytes, from the beginning of the file to the location in the file to start sending the file specified in the file_path parameter.
        /// @param count The number of bytes to send starting from the offset parameter. If count is zero, the entire file is sent.
        /// @remarks The xtd::net::sockets::send_packets_element class is used with the xtd::net::sockets::socket::socket_async_event_args::send_packets_elements property to get or set a data buffer or file to be sent using the xtd::net::sockets::socket::socket::send_packets_async method.
        /// @remarks Universal Naming Convention (UNC) paths are supported by the file_path parameter. If the file is in the current working directory, no path information needs to be specified.
        send_packets_element(const xtd::ustring& file_path, size_t offset, size_t count);
        
        /// @brief Initializes a new instance of the xtd::net::sockets::send_packets_element class using the specified range of the buffer with an option to combine this element with the next element in a single send request from the sockets layer to the transport.
        /// @param file_stream The file to be transmitted using the xtd::net::sockets::socket::send_packets_async method.
        /// @param offset The offset, in bytes, from the beginning of the file to the location in the file to start sending the bytes in the file.
        /// @param count The number of bytes to send starting from the offset parameter. If count is zero, the entire file is sent.
        /// @param end_of_packet Specifies that this element should not be combined with the next element in a single send request from the sockets layer to the transport. This flag is used for granular control of the content of each message on a datagram or message-oriented socket.
        /// @remarks The xtd::net::sockets::send_packets_element class is used with the xtd::net::sockets::socket::socket_async_event_args::send_packets_elements property to get or set a data buffer or file to be sent using the xtd::net::sockets::socket::socket::send_packets_async method.
        send_packets_element(std::ifstream& file_stream, size_t offset, size_t count, bool end_of_packet);

        /// @brief Initializes a new instance of the xtd::net::sockets::send_packets_element class using the specified range of the buffer with an option to combine this element with the next element in a single send request from the sockets layer to the transport.
        /// @param buffer A byte array of data to send using the xtd::net::sockets::socket::send_packets_async method.
        /// @param offset The offset, in bytes, from the beginning of the buffer to the location in the buffer to start sending the data specified in the buffer parameter.
        /// @param count The number bytes to send starting from the offset parameter. If count is zero, no bytes are sent.
        /// @remarks The xtd::net::sockets::send_packets_element class is used with the xtd::net::sockets::socket::socket_async_event_args::send_packets_elements property to get or set a data buffer or file to be sent using the xtd::net::sockets::socket::socket::send_packets_async method.
        send_packets_element(const std::vector<byte_t>& buffer, size_t offset, size_t count);

        /// @brief Initializes a new instance of the xtd::net::sockets::send_packets_element class using the specified file.
        /// @param file_path The filename of the file to be transmitted using the xtd::net::sockets::socket::send_packets_async method.
        /// @remarks The xtd::net::sockets::send_packets_element class is used with the xtd::net::sockets::socket::socket_async_event_args::send_packets_elements property to get or set a data buffer or file to be sent using the xtd::net::sockets::socket::socket::send_packets_async method.
        /// @remarks Universal Naming Convention (UNC) paths are supported by the file_path parameter. If the file is in the current working directory, no path information needs to be specified.
        send_packets_element(const xtd::ustring& file_path);

        /// @brief Initializes a new instance of the xtd::net::sockets::send_packets_element class using the specified FileStream object.
        /// @param file_stream The file to be transmitted using the xtd::net::sockets::socket::send_packets_async method.
        /// @remarks The xtd::net::sockets::send_packets_element class is used with the xtd::net::sockets::socket::socket_async_event_args::send_packets_elements property to get or set a data buffer or file to be sent using the xtd::net::sockets::socket::socket::send_packets_async method.
        send_packets_element(std::ifstream& file_stream);

        /// @cond
        send_packets_element(send_packets_element&& socket) = default;
        ~send_packets_element();
        /// @endcond

        /// @brief Gets the buffer to be sent if the xtd::net::sockets::send_packets_element object was initialized with a buffer parameter.
        /// @return The byte buffer to send if the xtd::net::sockets::send_packets_element object was initialized with a buffer parameter.
        /// @remarks The default value for the xtd::net::sockets::send_packets_element::buffer property is empty if the xtd::net::sockets::send_packets_element object was not initialized with a buffer parameter.
        std::vector<byte_t> buffer() const noexcept;
        
        /// @brief Gets the count of bytes to be sent.
        /// @return The count of bytes to send if the xtd::net::sockets::send_packets_element class was initialized with a count parameter.
        /// @remarks The default value for the xtd::net::sockets::send_packets_element::count property is zero if the xtd::net::sockets::send_packets_element class was not initialized with a count parameter.
        /// @remarks If Count is zero for a file, the entire file is sent. If xtd::net::sockets::send_packets_element::count is zero for a buffer, no bytes are sent.
        size_t count() const noexcept;
        
        /// @brief Gets a bool value that indicates if this element should not be combined with the next element in a single send request from the sockets layer to the transport.
        /// @return A bool value that indicates if this element should not be combined with the next element in a single send request.
        /// @remarks The default value for the xtd::net::sockets::send_packets_element::end_of_packet property is false if the xtd::net::sockets::send_packets_element class was not initialized with an end_of_packet parameter set to true.
        bool end_of_packet() const noexcept;
        
        /// @brief Gets the filename of the file to send if the xtd::net::sockets::send_packets_element object was initialized with a file_path parameter.
        /// @return The filename of the file to send if the xtd::net::sockets::send_packets_element object was initialized with a file_path parameter.
        /// @remarks Universal Naming Convention (UNC) paths are supported by the xtd::net::sockets::send_packets_element::file_path property. If the file is in the current working directory, no path information needs to be specified.
        /// @remarks The default value for the xtd::net::sockets::send_packets_element::file_path property is empty if the xtd::net::sockets::send_packets_element object was not initialized with a file_path parameter.
        const xtd::ustring& file_path() const noexcept;
        
        /// @brief Gets the object representation of the file to send if the xtd::net::sockets::send_packets_element object was initialized with a std::ifstream parameter.
        /// @remarks An object representation of the file to send if the xtd::net::sockets::send_packets_element object was initialized with a std::ifstrea parameter.
        /// @remarks The default value for the xtd::net::sockets::send_packets_element::file_stream property is empty if the xtd::net::sockets::send_packets_element object was not initialized with a file_stream parameter.
        std::optional<ifstream_ref> file_stream() const noexcept;

        /// @brief Gets the offset, in bytes, from the beginning of the data buffer or file to the location in the buffer or file to start sending the data.
        /// @return The offset, in bytes, from the beginning of the data buffer or file to the location in the buffer or file to start sending the data.
        /// @remarks The default value for the xtd::net::sockets::send_packets_element::offset property is zero if the xtd::net::sockets::send_packets_element class was not initialized with an offset parameter.
        size_t offset() const noexcept;

      private:
        std::vector<byte_t> buffer_;
        size_t count_ = 0;
        bool end_of_packet_ = false;
        xtd::ustring file_path_;
        std::ifstream* file_stream_ = nullptr;
        size_t offset_ = 0;
        bool delete_file_stream_when_destroy_ = false;
      };
    }
  }
}
