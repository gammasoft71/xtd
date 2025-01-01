/// @file
/// @brief Contains xtd::net::dns_end_point class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "end_point.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief Represents a network endpoint as a host name or a string representation of an IP address and a port number.
    /// @par Header
    /// ```cpp
    /// #include <xtd/net/dns_end_point>
    /// ```
    /// @par Namespace
    /// xtd::net
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    class core_export_ dns_end_point : public xtd::net::end_point {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::net::dns_end_point class with the host name or string representation of an IP address and a port number.
      /// @param host The host name or a string representation of the IP address.
      /// @param port The port number associated with the address, or 0 to specify any available port. port is in host order.
      /// @exception xtd::argument_exception The host parameter contains an empty string.
      /// @remarks The xtd::dns_end_point::dns_end_point(const xtd::string& host, int32 port) constructor can be used to initialize a xtd::net::dns_end_point class using either a host name or a string that represents an IP address and a port. This constructor sets the xtd::net::sockets::address_family property to xtd::net::sockets::address_family::unknown.
      /// @remarks When using this constructor with a host name rather than a string representation of an IP address, the address family of the dns_end_point will remain Unknown even after use. The xtd::net::sockets::address_family property of any Socket that is created by calls to the ConnectAsync method will be the address family of the first address to which a connection can be successfully established (not necessarily the first address to be resolved).
      dns_end_point(const xtd::string& host, uint16 port);
      
      /// @brief Initializes a new instance of the xtd::net::dns_end_point class with the host name or string representation of an IP address, a port number, and an address family.
      /// @param host The host name or a string representation of the IP address.
      /// @param port The port number associated with the address, or 0 to specify any available port. port is in host order.
      /// @param address_family One of the xtd::net::sockets::address_family values.
      /// @exception xtd::argument_exception The host parameter contains an empty string.
      /// @remarks The xtd::dns_end_point::dns_end_point(const xtd::string& host, int32 port, xtd::net::sockets::address_family) constructor can be used to initialize a dns_end_point class using either a host name or a string that represents an IP address, a port, and an address family.
      /// @remarks When using the constructor with a host name rather than a string representation of an IP address, the address family restricts DNS resolution to prefer addresses of the specified address family value. When using the constructor with the address family specified as Unknown, the address family of the dns_end_point will remain Unknown even after use. The xtd::net::sockets::address_family property of any Socket that is created by calls to the ConnectAsync method will be the address family of the first address to which a connection can be successfully established (not necessarily the first address to be resolved).
      dns_end_point(const xtd::string& host, uint16 port, sockets::address_family address_family);
      /// @}
      
      /// @cond
      dns_end_point(dns_end_point&&) = default;
      dns_end_point(const dns_end_point&) = default;
      dns_end_point& operator =(const dns_end_point&) = default;
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the host name or string representation of the Internet Protocol (IP) address of the host.
      /// @return The host name or a string representation of the IP address.
      const xtd::string& host() const noexcept;
      
      /// @brief Gets the port number of the endpoint.
      /// @return An integer value in the range xtd::net::ip_end_point::min_port to xtd::net::ip_end_point::max_port indicating the port number of the endpoint.
      uint16 port() const noexcept;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Returns a string that represents the current object.
      /// @return string A string that represents the current object.
      xtd::string to_string() const noexcept override;
      /// @}
      
    private:
      xtd::string host_;
      uint16 port_ = 0;
    };
  }
}
