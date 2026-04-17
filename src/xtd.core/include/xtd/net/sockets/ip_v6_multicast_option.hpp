/// @file
/// @brief Contains xtd::net::sockets::ip_v6_multicast_option class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../ip_address.hpp"
#include "../../core_export.hpp"
#include "../../iequatable.hpp"
#include "../../object.hpp"
#include "../../types.hpp"
#include "../../string.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief The xtd::net::sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
    namespace sockets {
      /// @brief Contains option values for joining an IPv6 multicast group.
      /// ```cpp
      /// class core_export_ ip_v6_multicast_option : public xtd::object, public xtd::iequatable<xtd::net::sockets::ip_v6_multicast_option>;
      /// ```
      /// @par Inheritance
      /// xtd::object → xtd::net::sockets::ip_v6_multicast_option
      /// @par Header
      /// ```cpp
      /// #include <xtd/net/sockets/ip_v6_multicast_option>
      /// ```
      /// @par Namespace
      /// xtd::net::sockets
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core
      class core_export_ ip_v6_multicast_option : public xtd::object, public xtd::iequatable<xtd::net::sockets::ip_v6_multicast_option> {
      public:
        /// @name Public Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::net::sockets::ip_v6_multicast_option class.
        ip_v6_multicast_option() = default;
        /// @brief Initializes a new version of the xtd::net::sockets::ip_v6_multicast_option class for the specified IP multicast group.
        /// @param group The xtd::net::ip_address of the multicast group.
        explicit ip_v6_multicast_option(const xtd::net::ip_address& group);
        /// @brief Initializes a new instance of the xtd::net::sockets::ip_v6_multicast_option class with the specified IP multicast group and the local interface address.
        /// @param group The xtd::net::ip_address of the multicast group.
        /// @param interface_index The address of the interface.
        ip_v6_multicast_option(const xtd::net::ip_address& group, uint64 interface_index);
        /// @}
        
        /// @cond
        ip_v6_multicast_option(ip_v6_multicast_option&& ip_v6_multicast_option) = default;
        auto operator =(ip_v6_multicast_option&&) -> ip_v6_multicast_option& = default;
        ip_v6_multicast_option(const ip_v6_multicast_option& ip_v6_multicast_option) = default;
        auto operator =(const ip_v6_multicast_option&) -> ip_v6_multicast_option& = default;
        /// @endcond
        
        /// @name Public Properties
        
        /// @{
        /// @brief Gets the IP address of a multicast group.
        /// @return An xtd::net::ip_address that contains the Internet address of a multicast group.
        [[nodiscard]] auto group() const noexcept -> const xtd::net::ip_address&;
        /// @brief Sets the IP address of a multicast group.
        /// @param value An xtd::net::ip_address that contains the Internet address of a multicast group.
        /// @return the current instance.
        auto group(const xtd::net::ip_address& value) noexcept -> xtd::net::sockets::ip_v6_multicast_option&;
        
        /// @brief Gets the interface index that is associated with a multicast group.
        /// @return A uint64 value that specifies the address of the interface.
        /// @remarks This property specifies the interface on which data is received or sent.
        [[nodiscard]] auto interface_index() const noexcept -> xtd::uint64;
        /// @brief Sets the interface index that is associated with a multicast group.
        /// @param value A uint64 value that specifies the address of the interface.
        /// @return the current instance.
        /// @exception xtd::argument_out_of_range_exception value > 0x00000000FFFFFFFF.
        /// @remarks This property specifies the interface on which data is received or sent.
        auto interface_index(xtd::uint64 value) -> xtd::net::sockets::ip_v6_multicast_option&;
        /// @}
        
        /// @name Public Methods
        
        /// @{
        /// @brief Determines whether the specified object is equal to the current object.
        /// @param obj The object to compare with the current object.
        /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
        [[nodiscard]] auto equals(const xtd::object& obj) const noexcept -> bool override;
        /// @brief Determines whether the specified object is equal to the current object.
        /// @param other The object to compare with the current object.
        /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
        [[nodiscard]] auto equals(const xtd::net::sockets::ip_v6_multicast_option& other) const noexcept -> bool override;
        
        /// @brief Serves as a hash function for a particular type.
        /// @return A hash code for the current object.
        [[nodiscard]] auto get_hash_code() const noexcept -> xtd::usize override;
        /// @}
        
      private:
        xtd::net::ip_address group_ = xtd::net::ip_address::ip_v6_none;
        xtd::uint64 interface_index_ = 0;
      };
    }
  }
}
