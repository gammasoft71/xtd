/// @file
/// @brief Contains xtd::net::socket_address class.
#pragma once

#include <vector>
#include "../core_export.h"
#include "../object.h"
#include "../types.h"
#include "../ustring.h"
#include "sockets/address_family.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @cond
    class ip_end_point;
    namespace sockets {class socket;}
    /// @endcond
    
    /// @brief Stores serialized information from end_point derived classes.
    /// @par Namespace
    /// xtd::net
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @remarks The first 2 bytes of the underlying buffer are reserved for the xtd::net::sockets::address_family enumerated value. When the xtd::net::socket_address is used to store a serialized xtd::net::ipend_point, the third and fourth bytes are used to store port number information. The next bytes are used to store the IP address. You can access any information within this underlying byte buffer by referring to its index position; the byte buffer uses zero-based indexing. You can also use the xtd::net::socket_address::family and xtd::net::socket_address::size properties to get the xtd::net::sockets::address_family value and the buffer size, respectively. To view any of this information as a string, use the xtd::net::socket_address::to_string method.
    class core_export_ socket_address : public xtd::object {
    public:
      /// @brief Creates a new instance of the xtd::net::socket_address class for the given address family.
      explicit socket_address(sockets::address_family address_family);
      
      /// @brief Creates a new instance of the xtd::net::socket_address class using the specified address family and buffer size.
      socket_address(sockets::address_family address_family, size_t buffer_size);
      
      /// @brief Creates a new instance of the xtd::net::socket_address class using the specified byte buffer .
      explicit socket_address(const std::vector<byte_t>& buffer);
      
      /// @cond
      socket_address(const socket_address& socket_address) = default;
      socket_address& operator=(const socket_address& socket_address) = default;
      friend std::ostream& operator <<(std::ostream& os, const socket_address& socket_address) noexcept {return os << socket_address.to_string();}
      /// @endcond
      
      /// @brief Gets the address family to which the endpoint belongs.
      /// @return One of the sockets::address_family values.
      sockets::address_family address_family() const;
      
      /// @brief Gets the underlying buffer size of the xtd::net::socket_address.
      /// @return The underlying buffer size of the xtd::net::socket_address.
      size_t size() const;
      
      /// @brief Gets or sets the specified index element in the underlying buffer.
      /// @param index The array index element of the desired information.
      /// @return The value of the specified index element in the underlying buffer.
      /// @exception xtd::argument_out_of_range_exception index is equal to or greater than size.
      /// @remarks This property gets or sets the specified byte position in the underlying buffer.
      /// @note Be sure to call xtd::net::socket_address::size before referring to elements in the underlying buffer. Referring to an index that does not exist will cause the xtd::net::socket_address to throw an xtd::argument_out_of_range_exception.
      byte& operator[](size_t index);
      
      /// @brief Gets the specified index element in the underlying buffer.
      /// @param index The array index element of the desired information.
      /// @return The value of the specified index element in the underlying buffer.
      /// @exception xtd::argument_out_of_range_exception index is equal to or greater than size.
      /// @remarks This property gets or sets the specified byte position in the underlying buffer.
      /// @note Be sure to call xtd::net::socket_address::size before referring to elements in the underlying buffer. Referring to an index that does not exist will cause the xtd::net::socket_address to throw an xtd::argument_out_of_range_exception.
      const byte& operator[](size_t index) const;
      
      /// @brief Returns information about the socket address.
      /// @return A string that contains information about the xtd::net::socket_address.
      /// @remarks The xtd::net::socket_address::to_string method returns a string that contains the xtd::net::sockets::address_family enumerated value, the size of the underlying buffer of the socket_address structure, and the remaining contents of the buffer.
      xtd::ustring to_string() const noexcept override;
      
    private:
      friend class ip_end_point;
      friend class sockets::socket;
      std::vector<byte_t> bytes_;
    };
  }
}
