/// @file
/// @brief Contains xtd::net::ip_address class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "sockets/address_family.hpp"
#include "../core_export.hpp"
#include "../iequatable.hpp"
#include "../object.hpp"
#include "../types.hpp"
#include "../string.hpp"
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @cond
    namespace sockets {
      class socket;
    }
    /// @endcond
    
    /// @brief Provides an Internet Protocol (IP) address.
    /// @par Header
    /// ```cpp
    /// #include <xtd/net/ip_address>
    /// ```
    /// @par Namespace
    /// xtd::net
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core net
    /// @par Examples
    /// The following code example shows how to query a server to obtain the family addresses and the IP addresses it supports.
    /// @include ip_address.cpp
    /// @remarks The xtd::net::ip_address class contains the address of a computer on an IP network.
    class core_export_ ip_address : public xtd::object, public xtd::iequatable<ip_address> {
    public:
      /// @name Public Fields
      
      /// @{
      /// @brief Provides an IP address that indicates that the server must listen for client activity on all network interfaces. This field is constant.
      /// @remarks The xtd::net::ip_address::any field is equivalent to 0.0.0.0 in dotted-quad notation
      static const ip_address any;
      /// @brief Provides the IP broadcast address. This field is constant.
      /// @remarks The xtd::net::ip_address::broadcast field is equivalent to 255.255.255.255 in dotted-quad notation.
      static const ip_address broadcast;
      /// @brief The Socket::Bind method uses the cIPv6Any field to indicate that a Socket must listen for client activity on all network interfaces. This field is constant.
      /// @remarks The xtd::net::ip_address::ip_v6_any field is equivalent to 0:0:0:0:0:0:0:0 in colon-hexadecimal notation, or to :: in compact notation.
      static const ip_address ip_v6_any;
      /// @brief Provides the IP loopback address. This field is constant.
      /// @remarks The xtd::net::ip_address::ip_v6_loopback field is equivalent to 0:0:0:0:0:0:0:1 in colon-hexadecimal notation, or to ::1 in compact notation.
      static const ip_address ip_v6_loopback;
      /// @brief Provides an IP address that indicates that no network interface should be used. This field is constant.
      /// @remarks The Socket::Bind method uses the cIPv6None field to indicate that a Socket must not listen for client activity.
      /// @remarks The xtd::net::ip_address::ip_v6_none field is equivalent to 0:0:0:0:0:0:0:0 in colon-hexadecimal notation, or to ::0 in compact notation.
      static const ip_address ip_v6_none;
      /// @brief Provides the IP loopback address. This field is constant.
      /// @remarks The xtd::net::ip_address::loopback field is equivalent to 127.0.0.1 in dotted-quad notation.
      static const ip_address loopback;
      /// @brief Provides an IP address that indicates that no network interface should be used. This field is constant.
      /// @remarks The xtd::net::ip_address::none field is equivalent to 255.255.255.255 in dotted-quad notation.
      static const ip_address none;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::net::ip_address.
      /// @remarks ip_address is initialized by default value xtd::net::ip_address::none.
      ip_address() = default;
      /// @brief Initializes a new instance of the xtd::net::ip_address class with the address specified as an uint32.
      /// @param address The value of the IP address. For example, the value 0x2414188F in big-endian format would be the IP address "143.24.20.36".
      explicit ip_address(uint32 address);
      /// @brief Initializes a new instance of the xtd::net::ip_address class with the address specified as a byte array.
      /// @param address The byte array value of the IP address.
      explicit ip_address(const std::vector<xtd::byte>& address);
      /// @brief Initializes a new instance of the xtd::net::ip_address class with the address specified as a byte array.
      /// @param address The byte array value of the IP address.
      /// @param scope_id The long value of the scope identifier.
      /// @exception xtd::argument_out_of_range_exception scope_id < 0 or scope_id > 0x00000000FFFFFFFF.
      /// @remarks This constructor instantiates an IPv6 address. The scope_dd identifies a network interface in the case of a link-local address.
      /// @remarks The scope is valid only for link-local and site-local addresses.
      /// @remarks The byte array is assumed to be in network byte order with the most significant byte first in index position 0.
      ip_address(const std::vector<xtd::byte>& address, uint32 scope_id);
      /// @brief Initializes a new instance of the xtd::net::ip_address class with the address specified as a four Bytes.
      /// @param quad_part_address1 The first quad part of the IP address.
      /// @param quad_part_address2 The second quad part of the IP address.
      /// @param quad_part_address3 The third quad part of the IP address.
      /// @param quad_part_address4 The fourth quad part of the IP address.
      ip_address(xtd::byte quad_part_address1, xtd::byte quad_part_address2, xtd::byte quad_part_address3, xtd::byte quad_part_address4);
      /// @}
      
      /// @cond
      ip_address(ip_address&& ip_address) = default;
      ip_address(const ip_address& ip_address) = default;
      ip_address& operator =(const ip_address&) = default;
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the address family of the IP address.
      /// @return Returns sockets::address_family::inter_network for IPv4 or sockets::address_family::inter_network_v6 for IPv6.
      sockets::address_family address_family() const noexcept;
      
      /// @brief Gets whether the IP address is an IPv4-mapped IPv6 address.
      /// @return true if the IP address is an IPv4-mapped IPv6 address; otherwise, false.
      /// @remarks Dual-stack sockets always require IPv6 addresses. The ability to interact with an IPv4 address requires the use of the IPv4-mapped IPv6 address format. Any IPv4 addresses must be represented in the IPv4-mapped IPv6 address format which enables an IPv6 only application to communicate with an IPv4 node. The IPv4-mapped IPv6 address format allows the IPv4 address of an IPv4 node to be represented as an IPv6 address. The IPv4 address is encoded into the low-order 32 bits of the IPv6 address, and the high-order 96 bits hold the fixed prefix 0:0:0:0:0:FFFF. The IPv4-mapped IPv6 address format is specified in RFC 4291. For more information, see www.ietf.org/rfc/rfc4291.txt.
      bool is_ip_v4_mapped_to_ip_v6() const noexcept;
      
      /// @brief Gets whether the address is an IPv6 link local address.
      /// @return bool true if the IP address is an IPv6 link local address; otherwise, false.
      bool is_ip_v6_link_local() const noexcept;
      
      /// @brief Gets whether the address is an IPv6 multicast global address.
      /// @return bool true if the IP address is an IPv6 multicast global address; otherwise, false.
      bool is_ip_v6_multicast() const noexcept;
      
      /// @brief Gets whether the address is an IPv6 site local address.
      /// @return bool true if the IP address is an IPv6 site local address; otherwise, false.
      bool is_ip_v6_site_local() const noexcept;
      
      /// @brief Gets whether the address is an IPv6 Teredo address.
      /// @return true if the IP address is an IPv6 Teredo address; otherwise, false.
      /// @remarks A Teredo address is an IPv6 address with the prefix of 2001::/32. Teredo addresses can be returned through normal DNS name resolution or enumerated as an IPv6 address assigned to a local interface.
      bool is_ip_v6_teredo() const noexcept;
      
      /// @brief Gets the IPv6 address scope identifier.
      /// @return A uint32 that specifies the scope of the address.
      /// @exception xtd::net::sockets::socket_exception if address_family = sockets::address_family::inter_network
      uint32 scope_id() const;
      /// @brief Sets the IPv6 address scope identifier.
      /// @param value A uint32 that specifies the scope of the address.
      /// @exception xtd::net::sockets::socket_exception if address_family = sockets::address_family::inter_network
      ip_address& scope_id(uint32 value);
      /// @}
      
      /// @name Public Methods
      
      /// @{
      using object::equals;
      bool equals(const ip_address& other) const noexcept override;
      
      /// @brief Provides a copy of the IPAddress as an array of bytes.
      /// @return  A byte array.
      std::vector<xtd::byte> get_address_bytes() const;
      
      /// @brief Maps the xtd::net::ip_address object to an IPv4 address.
      /// @return An IPv4 address.
      /// @remarks Dual-stack sockets always require IPv6 addresses. The ability to interact with an IPv4 address requires the use of the IPv4-mapped IPv6 address format. Any IPv4 addresses must be represented in the IPv4-mapped IPv6 address format which enables an IPv6 only application to communicate with an IPv4 node. The IPv4-mapped IPv6 address format allows the IPv4 address of an IPv4 node to be represented as an IPv6 address. The IPv4 address is encoded into the low-order 32 bits of the IPv6 address, and the high-order 96 bits hold the fixed prefix 0:0:0:0:0:FFFF. The IPv4-mapped IPv6 address format is specified in RFC 4291. For more information, see www.ietf.org/rfc/rfc4291.txt.
      ip_address map_to_ip_v4() const noexcept;
      
      /// @brief Maps the xtd::net::ip_address object to an IPv6 address.
      /// @return An IPv6 address.
      /// @remarks Dual-stack sockets always require IPv6 addresses. The ability to interact with an IPv4 address requires the use of the IPv4-mapped IPv6 address format. Any IPv4 addresses must be represented in the IPv4-mapped IPv6 address format which enables an IPv6 only application to communicate with an IPv4 node. The IPv4-mapped IPv6 address format allows the IPv4 address of an IPv4 node to be represented as an IPv6 address. The IPv4 address is encoded into the low-order 32 bits of the IPv6 address, and the high-order 96 bits hold the fixed prefix 0:0:0:0:0:FFFF. The IPv4-mapped IPv6 address format is specified in RFC 4291. For more information, see www.ietf.org/rfc/rfc4291.txt.
      ip_address map_to_ip_v6() const noexcept;
      
      /// @brief Converts an Internet address to its standard notation.
      /// @return A string that contains the IP address in either IPv4 dotted-quad or in IPv6 colon-hexadecimal notation.
      string to_string() const noexcept override;
      /// @}

      /// @name Public Static Methods
      
      /// @{
      /// @brief Converts a Double value from host byte order to network byte order.
      /// @param host The number to convert, expressed in host byte order.
      /// @return A Double value, expressed in network byte order.
      /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values.Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order). To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has the most significant byte first.
      /// @remarks The xtd::net::sockets::socket::host_to_network_order method converts multibyte integer values that are stored on the host system from the byte order used by the host to the byte order used by the network.
      static double host_to_network_order(double host);
      
      /// @brief Converts a short value from host byte order to network byte order.
      /// @param host The number to convert, expressed in host byte order.
      /// @return A short value, expressed in network byte order.
      /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values.Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order). To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has the most significant byte first.
      /// @remarks The xtd::net::sockets::socket::host_to_network_order method converts multibyte integer values that are stored on the host system from the byte order used by the host to the byte order used by the network.
      static int16 host_to_network_order(int16 host);
      
      /// @brief Converts a integer value from host byte order to network byte order.
      /// @param host The number to convert, expressed in host byte order.
      /// @return A integer value, expressed in network byte order.
      /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values.Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order). To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has the most significant byte first.
      /// @remarks The xtd::net::sockets::socket::host_to_network_order method converts multibyte integer values that are stored on the host system from the byte order used by the host to the byte order used by the network.
      static int32 host_to_network_order(int32 host);
      
      /// @brief Converts a long value from host byte order to network byte order.
      /// @param host The number to convert, expressed in host byte order.
      /// @return A long value, expressed in network byte order.
      /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values.Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order). To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has the most significant byte first.
      /// @remarks The xtd::net::sockets::socket::host_to_network_order method converts multibyte integer values that are stored on the host system from the byte order used by the host to the byte order used by the network.
      static int64 host_to_network_order(int64 host);
      
      /// @brief Converts a Single value from host byte order to network byte order.
      /// @param host The number to convert, expressed in host byte order.
      /// @return A Single value, expressed in network byte order.
      /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values.Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order). To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has the most significant byte first.
      /// @remarks The xtd::net::sockets::socket::host_to_network_order method converts multibyte integer values that are stored on the host system from the byte order used by the host to the byte order used by the network.
      static float host_to_network_order(float host);
      
      /// @brief Converts a short value from host byte order to network byte order.
      /// @param host The number to convert, expressed in host byte order.
      /// @return A unsigned short value, expressed in network byte order.
      /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values.Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order). To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has the most significant byte first.
      /// @remarks The xtd::net::sockets::socket::host_to_network_order method converts multibyte integer values that are stored on the host system from the byte order used by the host to the byte order used by the network.
      static uint16 host_to_network_order(uint16 host);
      
      /// @brief Converts a integer value from host byte order to network byte order.
      /// @param host The number to convert, expressed in host byte order.
      /// @return A unsigned integer value, expressed in network byte order.
      /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values.Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order). To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has the most significant byte first.
      /// @remarks The xtd::net::sockets::socket::host_to_network_order method converts multibyte integer values that are stored on the host system from the byte order used by the host to the byte order used by the network.
      static uint32 host_to_network_order(uint32 host);
      
      /// @brief Converts a long value from host byte order to network byte order.
      /// @param host The number to convert, expressed in host byte order.
      /// @return A unsigned long value, expressed in network byte order.
      /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values.Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order). To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has the most significant byte first.
      /// @remarks The xtd::net::sockets::socket::host_to_network_order method converts multibyte integer values that are stored on the host system from the byte order used by the host to the byte order used by the network.
      static uint64 host_to_network_order(uint64 host);
      
      /// @brief Indicates whether the specified IP address is the loopback address.
      /// @param address An IP address.
      /// @return bool true if address is the loopback address; otherwise, false.
      static bool is_loopback(const ip_address& address);
      
      /// @brief Converts a Double value from network byte order to host byte order.
      /// @param network The number to convert, expressed in network byte order.
      /// @return A Double value, expressed in host byte order.
      /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values. Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order). To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has the most significant byte first.
      /// @remarks The xtd::net::sockets::socket::network_to_host_order method converts multibyte integer values that are stored on the host system from the byte order used by the network to the byte order used by the host.
      static double network_to_host_order(double network);
      
      /// @brief Converts a short value from network byte order to host byte order.
      /// @param network The number to convert, expressed in network byte order.
      /// @return A short value, expressed in host byte order.
      /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values. Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order). To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has the most significant byte first.
      /// @remarks The xtd::net::sockets::socket::network_to_host_order method converts multibyte integer values that are stored on the host system from the byte order used by the network to the byte order used by the host.
      static int16 network_to_host_order(int16 network);
      
      /// @brief Converts a integer value from network byte order to host byte order.
      /// @param host The number to convert, expressed in network byte order.
      /// @return A integer value, expressed in host byte order.
      /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values. Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order). To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has the most significant byte first.
      /// @remarks The xtd::net::sockets::socket::network_to_host_order method converts multibyte integer values that are stored on the host system from the byte order used by the network to the byte order used by the host.
      static int32 network_to_host_order(int32 host);
      
      /// @brief Converts a long value from network byte order to host byte order.
      /// @param network The number to convert, expressed in network byte order.
      /// @return A long value, expressed in host byte order.
      /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values. Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order). To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has the most significant byte first.
      /// @remarks The xtd::net::sockets::socket::network_to_host_order method converts multibyte integer values that are stored on the host system from the byte order used by the network to the byte order used by the host.
      static int64 network_to_host_order(int64 network);
      
      /// @brief Converts a Single value from network byte order to host byte order.
      /// @param network The number to convert, expressed in host byte order.
      /// @return A Single value, expressed in host byte order.
      /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values. Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order). To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has the most significant byte first.
      /// @remarks The xtd::net::sockets::socket::network_to_host_order method converts multibyte integer values that are stored on the host system from the byte order used by the network to the byte order used by the host.
      static float network_to_host_order(float network);
      
      /// @brief Converts a short value from network byte order to host byte order.
      /// @param network The number to convert, expressed in network byte order.
      /// @return A unsigned short value, expressed in host byte order.
      /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values. Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order). To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has the most significant byte first.
      /// @remarks The xtd::net::sockets::socket::network_to_host_order method converts multibyte integer values that are stored on the host system from the byte order used by the network to the byte order used by the host.
      static uint16 network_to_host_order(uint16 network);
      
      /// @brief Converts a integer value from network byte order to host byte order.
      /// @param network The number to convert, expressed in network byte order.
      /// @return A unsigned integer value, expressed in host byte order.
      /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values. Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order). To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has the most significant byte first.
      /// @remarks The xtd::net::sockets::socket::network_to_host_order method converts multibyte integer values that are stored on the host system from the byte order used by the network to the byte order used by the host.
      static uint32 network_to_host_order(uint32 network);
      
      /// @brief Converts a long value from network byte order to host byte order.
      /// @param network The number to convert, expressed in network byte order.
      /// @return A unsigned long value, expressed in host byte order.
      /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values. Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order). To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has the most significant byte first.
      /// @remarks The xtd::net::sockets::socket::network_to_host_order method converts multibyte integer values that are stored on the host system from the byte order used by the network to the byte order used by the host.
      static uint64 network_to_host_order(uint64 network);
      
      /// @brief Converts an IP address string to an xtd::net::ip_address instance.
      /// @param str A string that contains an IP address in dotted-quad notation for IPv4 and in colon-hexadecimal notation for IPv6.
      /// @return An xtd::net::ip_address instance.
      /// @exception xtd::format_exception str is not a valid IP address.
      /// @remarks The static xtd::net::ip_address::parse method creates an xtd::net::ip_address instance from an IP address expressed in dotted-quad notation for IPv4 and in colon-hexadecimal notation for IPv6.
      /// @remarks The number of parts (each part is separated by a period) in str determines how the IP address is constructed. A one part address is stored directly in the network address. A two part address, convenient for specifying a class A address, puts the leading part in the first byte and the trailing part in the right-most three bytes of the network address. A three part address, convenient for specifying a class B address, puts the first part in the first byte, the second part in the second byte, and the final part in the right-most two bytes of the network address.
      static ip_address parse(const string& str);
      
      /// @brief Determines whether a string is a valid IP address.
      /// @param str The string to validate.
      /// @param address The xtd::net::ip_address version of the string.
      /// @return bool true if str is a valid IP address; otherwise, false.
      static bool try_parse(const string& str, ip_address& address) noexcept;
      /// @}

    private:
      friend xtd::net::sockets::socket;
      static constexpr size_t number_of_numbers_ = 8;
      ip_address(const std::vector<uint16>& numbers, uint32 scope_id);
      uint32 address_ = 0xFFFFFFFF;
      std::vector<uint16> numbers_ = std::vector<uint16>(number_of_numbers_);
      uint32 scope_id_ = 0;
      sockets::address_family address_family_ = sockets::address_family::inter_network;
    };
  }
}
