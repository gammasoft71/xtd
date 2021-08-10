/// @file
/// @brief Contains xtd::net::ip_address class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <vector>
#include "../core_export.h"
#include "../iequatable.h"
#include "../object.h"
#include "../types.h"
#include "../ustring.h"
#include "sockets/address_family.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief Provides an Internet Protocol (IP) address.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core net
    class core_export_ ip_address : public xtd::object, public xtd::iequatable<ip_address> {
    public:
      /// @brief Provides an IP address that indicates that the server must listen for client activity on all network interfaces. This field is constant.
      /// @remarks The td::net::ip_address::any field is equivalent to 0.0.0.0 in dotted-quad notation
      static ip_address any;
      /// @brief Provides the IP broadcast address. This field is constant.
      /// @remarks The td::net::ip_address::broadcast field is equivalent to 255.255.255.255 in dotted-quad notation.
      static ip_address broadcast;
      /// @brief The Socket::Bind method uses the cIPv6Any field to indicate that a Socket must listen for client activity on all network interfaces. This field is constant.
      /// @remarks The td::net::ip_address::ip_v6_any field is equivalent to 0:0:0:0:0:0:0:0 in colon-hexadecimal notation, or to :: in compact notation.
      static ip_address ip_v6_any;
      /// @brief Provides the IP loopback address. This field is constant.
      /// @remarks The td::net::ip_address::ip_v6_loopback field is equivalent to 0:0:0:0:0:0:0:1 in colon-hexadecimal notation, or to ::1 in compact notation.
      static ip_address ip_v6_loopback;
      /// @brief Provides an IP address that indicates that no network interface should be used. This field is constant.
      /// @remarks The Socket::Bind method uses the cIPv6None field to indicate that a Socket must not listen for client activity.
      /// @remarks The td::net::ip_address::ip_v6_none field is equivalent to 0:0:0:0:0:0:0:0 in colon-hexadecimal notation, or to ::0 in compact notation.
      static ip_address ip_v6_none;
      /// @brief Provides the IP loopback address. This field is constant.
      /// @remarks The td::net::ip_address::loopback field is equivalent to 127.0.0.1 in dotted-quad notation.
      static ip_address loopback;
      /// @brief Provides an IP address that indicates that no network interface should be used. This field is constant.
      /// @remarks The td::net::ip_address::none field is equivalent to 255.255.255.255 in dotted-quad notation.
      static ip_address none;

      /// @brief Initializes a new instance of the xtd::net::ip_address.
      /// @remarks ip_address is initialized by default value xtd::net::ip_address::none.
      ip_address() = default;
      /// @brief Initializes a new instance of the xtd::net::ip_address class with the address specified as an int64_t.
      /// @param address The value of the IP address. For example, the value 0x2414188F in big-endian format would be the IP address "143.24.20.36".
      explicit ip_address(uint32_t address);
      /// @brief Initializes a new instance of the xtd::net::ip_address class with the address specified as a byte array.
      /// @param address The byte array value of the IP address.
      explicit ip_address(const std::vector<byte_t>& address);
      /// @brief Initializes a new instance of the xtd::net::ip_address class with the address specified as a byte array.
      /// @param address The byte array value of the IP address.
      /// @param scope_id The long value of the scope identifier.
      /// @exception xtd::argument_out_of_range_exception scope_id < 0 or scope_id > 0x00000000FFFFFFFF.
      /// @remarks This constructor instantiates an IPv6 address. The scope_dd identifies a network interface in the case of a link-local address.
      /// @remarks The scope is valid only for link-local and site-local addresses.
      /// @remarks The byte array is assumed to be in network byte order with the most significant byte first in index position 0.
      ip_address(const std::vector<byte_t>& address, uint32_t scope_id);
      /// @brief Initializes a new instance of the xtd::net::ip_address class with the address specified as a four Bytes.
      /// @param quad_part_address1 The first quad part of the IP address.
      /// @param quad_part_address2 The second quad part of the IP address.
      /// @param quad_part_address3 The third quad part of the IP address.
      /// @param quad_part_address4 The fourth quad part of the IP address.
      ip_address(byte_t quad_part_address1, byte_t quad_part_address2, byte_t quad_part_address3, byte_t quad_part_address4);

      /// @cond
      ip_address(ip_address&& ip_address) = default;
      ip_address(const ip_address& ip_address) = default;
       ip_address& operator=(const ip_address&) = default;
      /// @endcond
      
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
      /// @return A uint32_t that specifies the scope of the address.
      /// @exception xtd::net::sockets::socket_exception if address_family = sockets::address_family::inter_network
      uint32_t scope_id() const;
      /// @brief Sets the IPv6 address scope identifier.
      /// @param value A uint32_t that specifies the scope of the address.
      /// @exception xtd::net::sockets::socket_exception if address_family = sockets::address_family::inter_network
      ip_address& scope_id(uint32_t value);

      bool equals(const object& other) const noexcept override;
      bool equals(const ip_address& other) const noexcept override;
      
      /// @brief Provides a copy of the IPAddress as an array of bytes.
      /// @return  A byte array.
      std::vector<byte_t> get_address_bytes() const;

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
      static int16_t host_to_network_order(int16_t host);
      
      /// @brief Converts a integer value from host byte order to network byte order.
      /// @param host The number to convert, expressed in host byte order.
      /// @return A integer value, expressed in network byte order.
      /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values.Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order). To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has the most significant byte first.
      /// @remarks The xtd::net::sockets::socket::host_to_network_order method converts multibyte integer values that are stored on the host system from the byte order used by the host to the byte order used by the network.
      static int32_t host_to_network_order(int32_t host);
      
      /// @brief Converts a long value from host byte order to network byte order.
      /// @param host The number to convert, expressed in host byte order.
      /// @return A long value, expressed in network byte order.
      /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values.Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order). To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has the most significant byte first.
      /// @remarks The xtd::net::sockets::socket::host_to_network_order method converts multibyte integer values that are stored on the host system from the byte order used by the host to the byte order used by the network.
      static int64_t host_to_network_order(int64_t host);
      
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
      static uint16_t host_to_network_order(uint16_t host);
      
      /// @brief Converts a integer value from host byte order to network byte order.
      /// @param host The number to convert, expressed in host byte order.
      /// @return A unsigned integer value, expressed in network byte order.
      /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values.Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order). To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has the most significant byte first.
      /// @remarks The xtd::net::sockets::socket::host_to_network_order method converts multibyte integer values that are stored on the host system from the byte order used by the host to the byte order used by the network.
      static uint32_t host_to_network_order(uint32_t host);
      
      /// @brief Converts a long value from host byte order to network byte order.
      /// @param host The number to convert, expressed in host byte order.
      /// @return A unsigned long value, expressed in network byte order.
      /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values.Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order). To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has the most significant byte first.
      /// @remarks The xtd::net::sockets::socket::host_to_network_order method converts multibyte integer values that are stored on the host system from the byte order used by the host to the byte order used by the network.
      static uint64_t host_to_network_order(uint64_t host);

      /// @brief Indicates whether the specified IP address is the loopback address.
      /// @param address An IP address.
      /// @return bool true if address is the loopback address; otherwise, false.
      static bool is_loopback(const ip_address& address);
      
      /// @brief Maps the xtd::net::ip_address object to an IPv4 address.
      /// @return An IPv4 address.
      /// @remarks Dual-stack sockets always require IPv6 addresses. The ability to interact with an IPv4 address requires the use of the IPv4-mapped IPv6 address format. Any IPv4 addresses must be represented in the IPv4-mapped IPv6 address format which enables an IPv6 only application to communicate with an IPv4 node. The IPv4-mapped IPv6 address format allows the IPv4 address of an IPv4 node to be represented as an IPv6 address. The IPv4 address is encoded into the low-order 32 bits of the IPv6 address, and the high-order 96 bits hold the fixed prefix 0:0:0:0:0:FFFF. The IPv4-mapped IPv6 address format is specified in RFC 4291. For more information, see www.ietf.org/rfc/rfc4291.txt.
      ip_address map_to_ip_v4() const noexcept;

      /// @brief Maps the xtd::net::ip_address object to an IPv6 address.
      /// @return An IPv6 address.
      /// @remarks Dual-stack sockets always require IPv6 addresses. The ability to interact with an IPv4 address requires the use of the IPv4-mapped IPv6 address format. Any IPv4 addresses must be represented in the IPv4-mapped IPv6 address format which enables an IPv6 only application to communicate with an IPv4 node. The IPv4-mapped IPv6 address format allows the IPv4 address of an IPv4 node to be represented as an IPv6 address. The IPv4 address is encoded into the low-order 32 bits of the IPv6 address, and the high-order 96 bits hold the fixed prefix 0:0:0:0:0:FFFF. The IPv4-mapped IPv6 address format is specified in RFC 4291. For more information, see www.ietf.org/rfc/rfc4291.txt.
      ip_address map_to_ip_v6() const noexcept;

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
      static int16_t network_to_host_order(int16_t network);
      
      /// @brief Converts a integer value from network byte order to host byte order.
      /// @param host The number to convert, expressed in network byte order.
      /// @return A integer value, expressed in host byte order.
      /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values. Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order). To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has the most significant byte first.
      /// @remarks The xtd::net::sockets::socket::network_to_host_order method converts multibyte integer values that are stored on the host system from the byte order used by the network to the byte order used by the host.
      static int32_t network_to_host_order(int32_t host);
      
      /// @brief Converts a long value from network byte order to host byte order.
      /// @param network The number to convert, expressed in network byte order.
      /// @return A long value, expressed in host byte order.
      /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values. Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order). To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has the most significant byte first.
      /// @remarks The xtd::net::sockets::socket::network_to_host_order method converts multibyte integer values that are stored on the host system from the byte order used by the network to the byte order used by the host.
      static int64_t network_to_host_order(int64_t network);
      
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
      static uint16_t network_to_host_order(uint16_t network);
      
      /// @brief Converts a integer value from network byte order to host byte order.
      /// @param network The number to convert, expressed in network byte order.
      /// @return A unsigned integer value, expressed in host byte order.
      /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values. Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order). To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has the most significant byte first.
      /// @remarks The xtd::net::sockets::socket::network_to_host_order method converts multibyte integer values that are stored on the host system from the byte order used by the network to the byte order used by the host.
      static uint32_t network_to_host_order(uint32_t network);
      
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
      static ip_address parse(const ustring& str);
      
      /// @brief Converts an Internet address to its standard notation.
      /// @return A string that contains the IP address in either IPv4 dotted-quad or in IPv6 colon-hexadecimal notation.
      ustring to_string() const noexcept override;
      
      /// @brief Determines whether a string is a valid IP address.
      /// @param str The string to validate.
      /// @param address The xtd::net::ip_address version of the string.
      /// @return bool true if str is a valid IP address; otherwise, false.
      static bool try_parse(const ustring& str, ip_address& address);

    private:
      static constexpr const size_t number_of_numbers_ = 8;
      ip_address(const std::vector<uint16_t>& numbers, uint32_t scope_id);
      uint32_t address_ = 0xFFFFFFFF;
      std::vector<uint16_t> numbers_ = std::vector<uint16_t>(number_of_numbers_);
      uint32_t scope_id_ = 0;
      sockets::address_family address_family_ = sockets::address_family::inter_network;
    };
  }
}
