/// @file
/// @brief Contains xtd::net::end_point class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "socket_address.hpp"
#include "sockets/address_family.hpp"
#include "../core_export.hpp"
#include "../object.hpp"
#include "../types.hpp"
#include "../string.hpp"
#include <memory>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief Identifies a network address. This is an abstract class.
    /// @par Header
    /// ```cpp
    /// #include <xtd/net/end_point>
    /// ```
    /// @par Namespace
    /// xtd::net
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    class core_export_ end_point : public xtd::object {
    public:
      /// @cond
      end_point(end_point&& end_point) = default;
      end_point(const end_point& end_point) = default;
      end_point& operator =(const end_point&) = default;
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the address family to which the endpoint belongs.
      /// @return One of the address_family values.
      sockets::address_family address_family() const noexcept;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Creates an xtd::net::end_point instance from a socket_address instance.
      /// @param socket_address The socket address that serves as the endpoint for a connection.
      /// @return A new xtd::net::end_point instance that is initialized from the specified xtd::net::socket_address instance.
      /// @exception xtd::not_supported_exception Any attempt is made to access the method when the method is not overridden in a descendant class.
      virtual xtd::uptr<end_point> create(const socket_address& socket_address) const;
      
      /// @brief Serializes endpoint information into a socket_address instance.
      /// @return A new xtd::net::socket_address instance that contains the endpoint information.
      virtual socket_address serialize() const;
      
      /// @brief Returns a string that represents the current object.
      /// @return A string that represents the current object.
      string to_string() const noexcept override;
      /// @}
      
    protected:
      /// @name Protected constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::net::end_point class.
      explicit end_point(sockets::address_family address_family) : address_family_(address_family) {}
      /// @}
      
      /// @cond
      end_point() = default;
      
      sockets::address_family address_family_ = sockets::address_family::unknown;
      /// @endcond
    };
  }
}
