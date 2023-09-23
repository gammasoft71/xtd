/// @file
/// @brief Contains xtd::net::sockets::io_control_code enum.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once

#include "../../enum"

/// @cond
#undef unix
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief The xtd::net::sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
    namespace sockets {
      /// @brief Specifies the IO control codes supported by the xtd::net::sockets::socket::io_control method.
      /// @code
      /// enum class io_control_code : uint64
      /// @endcode
      /// @par Header
      /// @code #include <xtd/net/sockets/io_control_code> @endcode
      /// @par Namespace
      /// xtd::net::sockets
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core
      enum class io_control_code : uint64 {
        /// @brief Replace the oldest queued datagram with an incoming datagram when the incoming message queues are full. This value is equal to the Winsock†2 SIO_ENABLE_CIRCULAR_QUEUEING constant.
        enable_circular_queuing = 671088642ul,
        /// @brief Discard the contents of the sending queue. This value is equal to the Winsock†2 SIO_FLUSH constant.
        flush = 671088644ul,
        /// @brief Enable receiving notification when the list of local interfaces for the socket's protocol family changes. This control code is supported on Windows 2000 and later operating systems. This value is equal to the Winsock†2 SIO_ADDRESS_LIST_CHANGE constant.
        address_list_change = 671088663ul,
        /// @brief Return the number of bytes available for reading. This value is equal to the Winsock†2 FIONREAD constant.
        data_to_read = 1074030207ul,
        /// @brief Return information about out-of-band data waiting to be received. When using this control code on stream sockets, the return value indicates the number of bytes available.
        oob_data_read = 1074033415ul,
        /// @brief Return a SOCKADDR structure that contains the broadcast address for the address family of the current socket. The returned address can be used with the Overload xtd:nNet::sockets::socket::send_to method. This value is equal to the Winsock†2 SIO_GET_BROADCAST_ADDRESS constant. This value can be used on User Datagram Protocol (UDP) sockets only.
        get_broadcast_address = 1207959557ul,
        /// @brief Return the list of local interfaces that the socket can bind to. This control code is supported on Windows 2000 and later operating systems. This value is equal to the Winsock†2 SIO_ADDRESS_LIST_QUERY constant.
        address_list_query = 1207959574ul,
        /// @brief Retrieve the underlying provider's SOCKET handle. This handle can be used to receive plug-and-play event notification. This control code is supported on Windows 2000 and later operating systems. This value is equal to the Winsock†2 SIO_QUERY_TARGET_PNP_HANDLE constant.
        query_target_pnp_handle = 1207959576ul,
        /// @brief Enable notification for when data is waiting to be received. This value is equal to the Winsock†2 FIOASYNC constant.
        async_io = 2147772029ul,
        /// @brief Control the blocking behavior of the socket. If the argument specified with this control code is zero, the socket is placed in blocking mode. If the argument is nonzero, the socket is placed in nonblocking mode. This value is equal to the Winsock†2 FIONBIO constant.
        non_blocking_io = 2147772030ul,
        /// @brief Associate this socket with the specified handle of a companion interface. Refer to the appropriate protocol-specific annex in the Winsock†2 reference or documentation for the particular companion interface for additional details. It is recommended that the Component object Model (COM) be used instead of this IOCTL to discover and track other interfaces that might be supported by a socket. This control code is present for backward compatibility with systems where COM is not available or cannot be used for some other reason. This value is equal to the Winsock†2 SIO_ASSOCIATE_HANDLE constant.
        associate_handle = 2281701377ul,
        /// @brief Control whether multicast data sent by the socket appears as incoming data in the sockets receive queue. This value is equal to the Winsock†2 SIO_MULTIPOINT_LOOPBACK constant.
        multipoint_loopback = 2281701385ul,
        /// @brief Control the number of times a multicast packet can be forwarded by a router, also known as the Time to Live (TTL), or hop count. This value is equal to the Winsock†2 SIO_MULTICAST_SCOPE constant.
        multicast_scope = 2281701386ul,
        /// @brief Sets the Quality of Service (QOS) attributes for the socket. QOS defines the bandwidth requirements for the socket. This control code is supported on Windows Me, Windows 2000, and later operating systems. This value is equal to the Winsock†2 SIO_SET_QOS constant.
        set_qos = 2281701387ul,
        /// @brief Sets the Quality of Service (QOS) attributes for the socket group. This value is reserved for future use and is equal to the Winsock†2 SIO_SET_GROUP_QOS constant.
        set_group_qos = 2281701388ul,
        /// @brief Enable receiving notification when the local interface used to access a remote endpoint changes. This value is equal to the Winsock†2 SIO_ROUTING_INTERFACE_CHANGE constant.
        routing_interface_change = 2281701397ul,
        /// @brief Control whether the socket receives notification when a namespace query becomes invalid. This control code is supported on Windows XP and later operating systems. This value is equal to the Winsock†2 SIO_NSP_NOTIFY_CHANGE constant.
        namespace_change = 2281701401ul,
        /// @brief Enable receiving all IPv4 packets on the network. The socket must have address family xtd::net::sockets::address_family::inter_network, the socket type must bextd::net::sockets::socket_type::raw, and the protocol type must be xtd::net::sockets::protocol_type::ip. The current user must belong to the Administrators group on the local computer, and the socket must be bound to a specific port. This control code is supported on Windows 2000 and later operating systems. This value is equal to the Winsock†2 SIO_RCVALL constant.
        receive_all = 2550136833ul,
        /// @brief Enable receiving all multicast IPv4 packets on the network. These are packets with destination addresses in the range 224.0.0.0 through 239.255.255.255. The socket must have address family xtd::net::sockets::address_family::inter_network, the socket type must be xtd::net::sockets::socket_type::raw, and the protocol type must be xtd::net::sockets::protocol_type::udp. The current user must belong to the Administrators group on the local computer, and the socket must be bound to a specific port. This control code is supported on Windows 2000 and later operating systems. This value is equal to the Winsock†2 SIO_RCVALL_MCAST constant.
        receive_all_multicast = 2550136834ul,
        /// @brief Enable receiving all Internet Group Management Protocol (IGMP) packets on the network. The socket must have address family xtd::net::sockets::address_family::inter_network, the socket type must be xtd::net::sockets::socket_type::raw, and the protocol type must be xtd::net::sockets::protocol_type::igmp. The current user must belong to the Administrators group on the local computer, and the socket must be bound to a specific port. This control code is supported on Windows 2000 and later operating systems. This value is equal to the Winsock†2 SIO_RCVALL_IGMPMCAST constant.
        receive_all_igmp_multicast = 2550136835ul,
        /// @brief Control sending TCP keep-alive packets and the interval at which they are sent. This control code is supported on Windows 2000 and later operating systems. For additional information, see RFC 1122 section 4.2.3.6. This value is equal to the Winsock†2 SIO_KEEPALIVE_VALS constant.
        keep_alive_values = 2550136836ul,
        /// @brief This value is equal to the Winsock†2 SIO_ABSORB_RTRALERT constant.
        absorb_router_alert = 2550136837ul,
        /// @brief Sets the interface used for outgoing unicast packets. This value is equal to the Winsock†2 SIO_UCAST_IF constant.
        unicast_interface = 2550136838ul,
        /// @brief This value is equal to the Winsock†2 SIO_LIMIT_BROADCASTS constant.
        limit_broadcasts = 2550136839ul,
        /// @brief Bind the socket to a specified interface index. This control code is supported on Windows 2000 and later operating systems. This value is equal to the Winsock†2 SIO_INDEX_BIND constant.
        bind_to_interface = 2550136840ul,
        /// @brief Sets the interface used for outgoing multicast packets. The interface is identified by its index. This control code is supported on Windows 2000 and later operating systems. This value is equal to the Winsock†2 SIO_INDEX_MCASTIF constant.
        multicast_interface = 2550136841ul,
        /// @brief Join a multicast group using an interface identified by its index. This control code is supported on Windows 2000 and later operating systems. This value is equal to the Winsock†2 SIO_INDEX_ADD_MCAST constant.
        add_multicast_group_on_interface = 2550136842ul,
        /// @brief Remove the socket from a multicast group. This control code is supported on Windows 2000 and later operating systems. This value is equal to the Winsock†2 SIO_INDEX_ADD_MCAST constant.
        delete_multicast_group_from_interface = 2550136843ul,
        /// @brief Obtain provider-specific functions that are not part of the Winsock specification. Functions are specified using their provider-assigned GUID. This value is equal to the Winsock†2 SIO_GET_EXTENSION_FUNCTION_POINTER constant.
        get_extension_function_pointer = 3355443206ul,
        /// @brief Retrieve the QOS structure associated with the socket. This control is only supported on platforms that provide a QOS capable transport (Windows Me, Windows 2000, and later.) This value is equal to the Winsock†2 SIO_GET_QOS constant.
        get_qos = 3355443207ul,
        /// @brief Return the Quality of Service (QOS) attributes for the socket group. This value is reserved for future use, and is equal to the Winsock†2 SIO_GET_GROUP_QOS constant.
        get_group_qos = 3355443208ul,
        /// @brief Return a handle for the socket that is valid in the context of a companion interface. This value is equal to the Winsock†2 SIO_TRANSLATE_HANDLE constant.
        translate_handle = 3355443213ul,
        /// @brief Return the interface addresses that can be used to connect to the specified remote address. This value is equal to the Winsock†2 SIO_ROUTING_INTERFACE_QUERY constant.
        routing_interface_query = 3355443220ul,
        /// @brief Sort the structure returned by the xtd::net::sockets::io_control_code::address_list_query field and add scope ID information for IPv6 addresses. This control code is supported on Windows XP and later operating systems. This value is equal to the Winsock†2 SIO_ADDRESS_LIST_SORT constant.
        address_list_sort = 3355443225ul
      };
    }
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::net::sockets::io_control_code> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::net::sockets::io_control_code> {{xtd::net::sockets::io_control_code::enable_circular_queuing, "enable_circular_queuing"}, {xtd::net::sockets::io_control_code::flush, "flush"}, {xtd::net::sockets::io_control_code::address_list_change, "address_list_change"}, {xtd::net::sockets::io_control_code::data_to_read, "data_to_read"}, {xtd::net::sockets::io_control_code::oob_data_read, "oob_data_read"}, {xtd::net::sockets::io_control_code::get_broadcast_address, "get_broadcast_address"}, {xtd::net::sockets::io_control_code::address_list_query, "address_list_query"}, {xtd::net::sockets::io_control_code::query_target_pnp_handle, "query_target_pnp_handle"}, {xtd::net::sockets::io_control_code::async_io, "async_io"}, {xtd::net::sockets::io_control_code::non_blocking_io, "non_blocking_io"}, {xtd::net::sockets::io_control_code::associate_handle, "associate_handle"}, {xtd::net::sockets::io_control_code::multipoint_loopback, "multipoint_loopback"}, {xtd::net::sockets::io_control_code::multicast_scope, "multicast_scope"}, {xtd::net::sockets::io_control_code::set_qos, "set_qos"}, {xtd::net::sockets::io_control_code::set_group_qos, "set_group_qos"}, {xtd::net::sockets::io_control_code::routing_interface_change, "routing_interface_change"}, {xtd::net::sockets::io_control_code::namespace_change, "namespace_change"}, {xtd::net::sockets::io_control_code::receive_all, "receive_all"}, {xtd::net::sockets::io_control_code::receive_all_multicast, "receive_all_multicast"}, {xtd::net::sockets::io_control_code::receive_all_igmp_multicast, "receive_all_igmp_multicast"}, {xtd::net::sockets::io_control_code::keep_alive_values, "keep_alive_values"}, {xtd::net::sockets::io_control_code::absorb_router_alert, "absorb_router_alert"}, {xtd::net::sockets::io_control_code::unicast_interface, "unicast_interface"}, {xtd::net::sockets::io_control_code::limit_broadcasts, "limit_broadcasts"}, {xtd::net::sockets::io_control_code::bind_to_interface, "bind_to_interface"}, {xtd::net::sockets::io_control_code::multicast_interface, "multicast_interface"}, {xtd::net::sockets::io_control_code::add_multicast_group_on_interface, "add_multicast_group_on_interface"}, {xtd::net::sockets::io_control_code::delete_multicast_group_from_interface, "delete_multicast_group_from_interface"}, {xtd::net::sockets::io_control_code::get_extension_function_pointer, "get_extension_function_pointer"}, {xtd::net::sockets::io_control_code::get_qos, "get_qos"}, {xtd::net::sockets::io_control_code::get_group_qos, "get_group_qos"}, {xtd::net::sockets::io_control_code::translate_handle, "translate_handle"}, {xtd::net::sockets::io_control_code::routing_interface_query, "routing_interface_query"}, {xtd::net::sockets::io_control_code::address_list_sort, "address_list_sort"}};}
};
/// @endcond
