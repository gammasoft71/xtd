/// @file
/// @brief Contains xtd::net::ip_end_point class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include "end_point.h"
#include "ip_address.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief Represents a network endpoint as an IP address and a port number.
    /// @remarks The xtd::net::ip_end_point class contains the host and local or remote port information needed by an application to connect to a service on a host. By combining the host's IP address and port number of a service, the ip_end_point class forms a connection point to a service.
    /// @par Namespace
    /// xtd::net
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    class core_export_ ip_end_point : public xtd::net::end_point {
    public:
      /// @brief Specifies the minimum value that can be assigned to the port property. The min_port value is set to 0x0000. This field is read-only.
      static constexpr const uint16_t min_port = 0x0000;
      /// @brief Specifies the maximum value that can be assigned to the port property. The max_port value is set to 0xFFFF. This field is read-only.
      static constexpr const uint16_t max_port = 0xFFFF;
      
      /// @brief Initializes a new instance of the xtd::net::ip_end_point class.
      /// @param address The IP address of the Internet host.
      /// @param port The port number associated with the address, or 0 to specify any available port. port is in host order.
      ip_end_point(uint32_t address, uint16_t port);
      
      /// @brief Initializes a new instance of the xtd::net::ip_end_point class.
      /// @param address An xtd::net::ip_address.
      /// @param port The port number associated with the address, or 0 to specify any available port. port is in host order.
      ip_end_point(const xtd::net::ip_address& address, uint16_t port);

      /// @cond
      ip_end_point() = default;
      ip_end_point(ip_end_point&&) = default;
      ip_end_point(const ip_end_point&) = default;
      ip_end_point& operator=(const ip_end_point&) = default;
      friend std::ostream& operator <<(std::ostream& os, const ip_end_point& end_point) noexcept {return os << end_point.to_string();}
      /// @endcond
      
      /// @brief Gets the IP address of the endpoint.
      /// @return An xtd::net::ip_address instance containing the IP address of the endpoint.
      const xtd::net::ip_address& address() const noexcept;
      /// @brief Sets the IP address of the endpoint.
      /// @param value An ip_address instance containing the IP address of the endpoint.
      /// @return The current instance.
      ip_end_point& address(const xtd::net::ip_address& value);
      
      /// @brief Gets or sets the port number of the endpoint.
      /// @param value An integer value in the range min_port to max_port indicating the port number of the endpoint.
      uint16_t port() const noexcept;
      /// @brief Sets the port number of the endpoint.
      /// @param value An integer value in the range min_port to max_port indicating the port number of the endpoint.
      ip_end_point& port(uint16_t value);

      /// @brief Creates an xtd::net::end_point instance from a xtd::net::socket_address instance.
      /// @param socket_address The socket address that serves as the endpoint for a connection.
      /// @return A new end_point instance that is initialized from the specified xtd::net::socket_address instance.
      /// @exception xtd::not_supported_exception Any attempt is made to access the method when the method is not overridden in a descendant class.
      std::unique_ptr<end_point> create(const xtd::net::socket_address& socket_address) const override;

      /// @brief Serializes endpoint information into a socket_address instance.
      /// @return A new xtd::net::socket_address instance that contains the endpoint information.
      xtd::net::socket_address serialize() const override;
      
      /// @brief Returns a string that represents the current object.
      /// @return string A string that represents the current object.
      xtd::ustring to_string() const noexcept override;

    private:
      xtd::net::ip_address address_;
      uint16_t port_ = 0;
    };
  }
}
