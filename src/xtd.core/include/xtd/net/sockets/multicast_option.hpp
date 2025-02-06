/// @file
/// @brief Contains xtd::net::sockets::multicast_option class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../ip_address.hpp"
#include "../../core_export.hpp"
#include "../../object.hpp"
#include "../../types.hpp"
#include "../../string.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief The xtd::net::sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
    namespace sockets {
      /// @brief Contains IPAddress values used to join and drop multicast groups.
      /// ```cpp
      /// class core_export_ multicast_option : public xtd::object, public xtd::iequatable<xtd::net::sockets::multicast_option>;
      /// ```
      /// @par Inheritance
      /// xtd::object → xtd::net::sockets::multicast_option
      /// @par Header
      /// ```cpp
      /// #include <xtd/net/sockets/multicast_option>
      /// ```
      /// @par Namespace
      /// xtd::net::sockets
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core
      /// @remarks Use a xtd::net::sockets::multicast_option to store the xtd::net::ip_address of a multicast group you want to join or drop. Use the xtd::net::sockets::socket::set_socket_option method with the following parameters to join a multicast group.
      /// | Parameter         | Value                                                   |
      /// | ----------------- | ------------------------------------------------------- |
      /// | socket_option_level | xtd::net::sockets::socket_option_level::udp           |
      /// | socket_option_name  | xtd::net::sockets::socket_option_name::add_membership |
      /// | object            | xtd::net::sockets::multicast_option                     |
      /// @remarks Use xtd::net::sockets::socket_option_name::drop_membership to drop a multicast group.
      class core_export_ multicast_option : public xtd::object, public xtd::iequatable<xtd::net::sockets::multicast_option> {
      public:
        /// @name Public Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::net::sockets::multicast_option class.
        multicast_option() = default;
        /// @brief Initializes a new instance of the xtd::net::sockets::multicast_option class with the specified IP multicast group and the local interface address.
        /// @param group The xtd::net::ip_address of the multicast group.
        /// @param local_address The local xtd::net::ip_address.
        multicast_option(const xtd::net::ip_address& group, const xtd::net::ip_address& local_address);
        /// @brief Initializes a new version of the xtd::net::sockets::multicast_option class for the specified IP multicast group.
        /// @param group The xtd::net::ip_address of the multicast group.
        explicit multicast_option(const xtd::net::ip_address& group);
        /// @brief Initializes a new instance of the xtd::net::sockets::multicast_option class with the specified IP multicast group and the local interface address.
        /// @param group The xtd::net::ip_address of the multicast group.
        /// @param interface_index The address of the interface.
        /// @exception xtd::argument_out_of_range_exception interface_index > 0x00FFFFFF.
        multicast_option(const xtd::net::ip_address& group, uint32 interface_index);
        /// @}
        
        /// @cond
        multicast_option(multicast_option&& multicast_option) = default;
        multicast_option(const multicast_option& multicast_option) = default;
        multicast_option& operator =(const multicast_option&) = default;
        /// @endcond
        
        /// @name Public Properties
        
        /// @{
        /// @brief Gets the IP address of a multicast group.
        /// @return An xtd::net::ip_address that contains the Internet address of a multicast group.
        const xtd::net::ip_address& group() const noexcept;
        /// @brief Sets the IP address of a multicast group.
        /// @param value An xtd::net::ip_address that contains the Internet address of a multicast group.
        /// @return the current instance.
        multicast_option& group(const xtd::net::ip_address& value) noexcept;
        
        /// @brief Gets the interface index that is associated with a multicast group.
        /// @return A uint32 value that specifies the address of the interface.
        /// @remarks This property specifies the interface on which data is received or sent.
        uint32 interface_index() const noexcept;
        /// @brief Sets the interface index that is associated with a multicast group.
        /// @param value A uint32 value that specifies the address of the interface.
        /// @return the current instance.
        /// @remarks This property specifies the interface on which data is received or sent.
        multicast_option& interface_index(uint32 value) noexcept;
        
        /// @brief Gets the local IP address associated with a multicast group.
        /// @return An xtd::net::ip_address that contains the local address associated with a multicast group.
        const xtd::net::ip_address& local_address() const noexcept;
        /// @brief Sets he local IP address associated with a multicast group.
        /// @param value An xtd::net::ip_address that contains the local address associated with a multicast group.
        /// @return the current instance.
        multicast_option& local_address(const xtd::net::ip_address& value) noexcept;
        /// @}

        /// @name Public Methods
        
        /// @{
        /// @brief Determines whether the specified object is equal to the current object.
        /// @param obj The object to compare with the current object.
        /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
        bool equals(const object& obj) const noexcept override;
        /// @brief Determines whether the specified object is equal to the current object.
        /// @param other The object to compare with the current object.
        /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
        bool equals(const multicast_option& other) const noexcept override;
        
        /// @brief Serves as a hash function for a particular type.
        /// @return A hash code for the current object.
        xtd::size get_hash_code() const noexcept override;
        /// @}
        
      private:
        xtd::net::ip_address group_ = xtd::net::ip_address::none;
        uint32 interface_index_ = 0;
        xtd::net::ip_address local_address_ = xtd::net::ip_address::none;
      };
    }
  }
}
