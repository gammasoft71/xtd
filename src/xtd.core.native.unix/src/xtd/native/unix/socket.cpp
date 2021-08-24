#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/socket.h>
#include <xtd/native/address_family_constants.h>
#include <xtd/native/protocol_type_constants.h>
#include <xtd/native/select_mode_constants.h>
#include <xtd/native/socket_option_name_constants.h>
#include <xtd/native/socket_option_level_constants.h>
#include <xtd/native/socket_error_constants.h>
#include <xtd/native/socket_shutdown_constants.h>
#include <xtd/native/socket_type_constants.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <map>
#include <fcntl.h>
#include <poll.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

using namespace std;
using namespace xtd::native;

namespace {
  static int32_t native_to_socket_error(int32_t error) {
#if defined(__APPLE__)
    static map<int32_t, int32_t> socket_errors {
      {0, SOCKET_ERROR_SUCCESS},
      {EINTR, SOCKET_ERROR_INTERRUPTED},
      {EACCES, SOCKET_ERROR_ACCESS_DENIED},
      {EFAULT, SOCKET_ERROR_FAULT},
      {EINVAL, SOCKET_ERROR_INVALID_ARGUMENT},
      {EMFILE, SOCKET_ERROR_TOO_MANY_OPEN_SOCKETS},
      {EAGAIN, SOCKET_ERROR_WOULD_BLOCK},
      {EINPROGRESS, SOCKET_ERROR_IN_PROGRESS},
      {EALREADY, SOCKET_ERROR_ALREADY_IN_PROGRESS},
      {ENOTSOCK, SOCKET_ERROR_NOT_SOCKET},
      {EDESTADDRREQ, SOCKET_ERROR_DESTINATION_ADDDRESS_REQUIRED},
      {EMSGSIZE, SOCKET_ERROR_MESSAGE_SIZE},
      {EPROTOTYPE, SOCKET_ERROR_PROTOCOL_TYPE},
      {ENOPROTOOPT, SOCKET_ERROR_PROTOCOL_OPTION},
      {EPROTONOSUPPORT, SOCKET_ERROR_PROTOCOL_NOT_SUPPORTED},
      {ESOCKTNOSUPPORT, SOCKET_ERROR_SOCKET_NOT_SUPPORTED},
      {ENOTSUP, SOCKET_ERROR_OPERATION_NOT_SUPPORTED},
      {EPFNOSUPPORT, SOCKET_ERROR_PROTOCOL_FAMILY_NOT_SUPPORTED},
      {EAFNOSUPPORT, SOCKET_ERROR_ADDRESS_FAMILY_NOT_SUPPORTED},
      {EADDRINUSE, SOCKET_ERROR_ADDRESS_ALREADY_IN_USE},
      {EADDRNOTAVAIL, SOCKET_ERROR_ADDRESS_NOT_AVAILABLE},
      {ENETDOWN, SOCKET_ERROR_NETWORK_DOWN},
      {ENETUNREACH, SOCKET_ERROR_NETWORK_UNREACHABLE},
      {ENETRESET, SOCKET_ERROR_NETWORK_RESET},
      {ECONNABORTED, SOCKET_ERROR_CONNECTION_ABORTED},
      {ECONNRESET, SOCKET_ERROR_CONNECTION_RESET},
      {ENOBUFS, SOCKET_ERROR_NO_BUFFER_SPACE_AVAILABLE},
      {EISCONN, SOCKET_ERROR_IS_CONNECTED},
      {ENOTCONN, SOCKET_ERROR_NOT_CONNECTED},
      {ESHUTDOWN, SOCKET_ERROR_SHUTDOWN},
      {ETIMEDOUT, SOCKET_ERROR_TIMED_OUT},
      {ECONNREFUSED, SOCKET_ERROR_CONNECTION_REFUSED},
      {EHOSTDOWN, SOCKET_ERROR_HOST_DOWN},
      {EHOSTUNREACH, SOCKET_ERROR_HOST_UNREACHABLE},
      {EPROCLIM, SOCKET_ERROR_PROCESS_LIMIT},
      {ERPCMISMATCH, SOCKET_ERROR_VERSION_NOT_SUPPORTED},
      {EOPNOTSUPP, SOCKET_ERROR_SOCKET_NOT_SUPPORTED}
    };
#else
    static map<int32_t, int32_t> socket_errors {
      {0, SOCKET_ERROR_SUCCESS},
      {EINTR, SOCKET_ERROR_INTERRUPTED},
      {EACCES, SOCKET_ERROR_ACCESS_DENIED},
      {EFAULT, SOCKET_ERROR_FAULT},
      {EINVAL, SOCKET_ERROR_INVALID_ARGUMENT},
      {EMFILE, SOCKET_ERROR_TOO_MANY_OPEN_SOCKETS},
      {EAGAIN, SOCKET_ERROR_WOULD_BLOCK},
      {EINPROGRESS, SOCKET_ERROR_IN_PROGRESS},
      {EALREADY, SOCKET_ERROR_ALREADY_IN_PROGRESS},
      {ENOTSOCK, SOCKET_ERROR_NOT_SOCKET},
      {EDESTADDRREQ, SOCKET_ERROR_DESTINATION_ADDDRESS_REQUIRED},
      {EMSGSIZE, SOCKET_ERROR_MESSAGE_SIZE},
      {EPROTOTYPE, SOCKET_ERROR_PROTOCOL_TYPE},
      {ENOPROTOOPT, SOCKET_ERROR_PROTOCOL_OPTION},
      {EPROTONOSUPPORT, SOCKET_ERROR_PROTOCOL_NOT_SUPPORTED},
      {ESOCKTNOSUPPORT, SOCKET_ERROR_SOCKET_NOT_SUPPORTED},
      {ENOTSUP, SOCKET_ERROR_OPERATION_NOT_SUPPORTED},
      {EPFNOSUPPORT, SOCKET_ERROR_PROTOCOL_FAMILY_NOT_SUPPORTED},
      {EAFNOSUPPORT, SOCKET_ERROR_ADDRESS_FAMILY_NOT_SUPPORTED},
      {EADDRINUSE, SOCKET_ERROR_ADDRESS_ALREADY_IN_USE},
      {EADDRNOTAVAIL, SOCKET_ERROR_ADDRESS_NOT_AVAILABLE},
      {ENETDOWN, SOCKET_ERROR_NETWORK_DOWN},
      {ENETUNREACH, SOCKET_ERROR_NETWORK_UNREACHABLE},
      {ENETRESET, SOCKET_ERROR_NETWORK_RESET},
      {ECONNABORTED, SOCKET_ERROR_CONNECTION_ABORTED},
      {ECONNRESET, SOCKET_ERROR_CONNECTION_RESET},
      {ENOBUFS, SOCKET_ERROR_NO_BUFFER_SPACE_AVAILABLE},
      {EISCONN, SOCKET_ERROR_IS_CONNECTED},
      {ENOTCONN, SOCKET_ERROR_NOT_CONNECTED},
      {ESHUTDOWN, SOCKET_ERROR_SHUTDOWN},
      {ETIMEDOUT, SOCKET_ERROR_TIMED_OUT},
      {ECONNREFUSED, SOCKET_ERROR_CONNECTION_REFUSED},
      {EHOSTDOWN, SOCKET_ERROR_HOST_DOWN},
      {EHOSTUNREACH, SOCKET_ERROR_HOST_UNREACHABLE},
      {EOPNOTSUPP, SOCKET_ERROR_SOCKET_NOT_SUPPORTED}
    };
#endif
    auto it = socket_errors.find(error);
    if (it == socket_errors.end()) return SOCKET_ERROR_SOCKET_ERROR;
    return it->second;
  }
  
  static int32_t protocol_type_to_native(int32_t protocol_type) {
#if defined(__APPLE__)
    static map<int32_t, int32_t> protocol_types = {
      //{PROTOCOL_TYPE_UNKNWON, IPPROTO_},
      //{PROTOCOL_TYPE_IP_V6_HOP_BY_HOP_OPTIONS, IPPROTO_},
      //{PROTOCOL_TYPE_UNSPECIFIED, IPPROTO_},
      {PROTOCOL_TYPE_IP, IPPROTO_IP},
      {PROTOCOL_TYPE_ICMP, IPPROTO_ICMP},
      {PROTOCOL_TYPE_IGMP, IPPROTO_IGMP},
      {PROTOCOL_TYPE_GGP, IPPROTO_GGP},
      {PROTOCOL_TYPE_IP_V4, IPPROTO_IPV4},
      {PROTOCOL_TYPE_TCP, IPPROTO_TCP},
      {PROTOCOL_TYPE_PUP, IPPROTO_PUP},
      {PROTOCOL_TYPE_UDP, IPPROTO_UDP},
      {PROTOCOL_TYPE_IDP, IPPROTO_IDP},
      {PROTOCOL_TYPE_IP_V6, IPPROTO_IPV6},
      {PROTOCOL_TYPE_IP_V6_ROUTING_HEADER, IPPROTO_ROUTING},
      {PROTOCOL_TYPE_IP_V6_FRAGMENT_HEADER, IPPROTO_FRAGMENT},
      {PROTOCOL_TYPE_IP_SEC_ENCAPSULATING_SECURITY_PAYLOAD, IPPROTO_ESP},
      {PROTOCOL_TYPE_IP_SEC_AUTHENTIFICATION_HEADER, IPPROTO_AH},
      {PROTOCOL_TYPE_ICMP_V6, IPPROTO_ICMPV6},
      {PROTOCOL_TYPE_IP_V6_NO_NEXT_HEADER, IPPROTO_NONE},
      {PROTOCOL_TYPE_IP_V6_DESTINATION_OPTIONS, IPPROTO_DSTOPTS},
      {PROTOCOL_TYPE_ND, IPPROTO_ND},
      {PROTOCOL_TYPE_RAW, IPPROTO_RAW}
      //{PROTOCOL_TYPE_IPX, IPPROTO_},
      //{PROTOCOL_TYPE_SPX, IPPROTO_IP},
      //{PROTOCOL_TYPE_SPX_2, IPPROTO_},
    };
#else
    static map<int32_t, int32_t> protocol_types = {
      //{PROTOCOL_TYPE_UNKNWON, IPPROTO_},
      //{PROTOCOL_TYPE_IP_V6_HOP_BY_HOP_OPTIONS, IPPROTO_},
      //{PROTOCOL_TYPE_UNSPECIFIED, IPPROTO_},
      {PROTOCOL_TYPE_IP, IPPROTO_IP},
      {PROTOCOL_TYPE_ICMP, IPPROTO_ICMP},
      {PROTOCOL_TYPE_IGMP, IPPROTO_IGMP},
      {PROTOCOL_TYPE_GGP, 3}, // IPPROTO_GGP
      {PROTOCOL_TYPE_IP_V4, IPPROTO_IPIP},
      {PROTOCOL_TYPE_TCP, IPPROTO_TCP},
      {PROTOCOL_TYPE_PUP, IPPROTO_PUP},
      {PROTOCOL_TYPE_UDP, IPPROTO_UDP},
      {PROTOCOL_TYPE_IDP, IPPROTO_IDP},
      {PROTOCOL_TYPE_IP_V6, IPPROTO_IPV6},
      {PROTOCOL_TYPE_IP_V6_ROUTING_HEADER, IPPROTO_ROUTING},
      {PROTOCOL_TYPE_IP_V6_FRAGMENT_HEADER, IPPROTO_FRAGMENT},
      {PROTOCOL_TYPE_IP_SEC_ENCAPSULATING_SECURITY_PAYLOAD, IPPROTO_ESP},
      {PROTOCOL_TYPE_IP_SEC_AUTHENTIFICATION_HEADER, IPPROTO_AH},
      {PROTOCOL_TYPE_ICMP_V6, IPPROTO_ICMPV6},
      {PROTOCOL_TYPE_IP_V6_NO_NEXT_HEADER, IPPROTO_NONE},
      {PROTOCOL_TYPE_IP_V6_DESTINATION_OPTIONS, IPPROTO_DSTOPTS},
      {PROTOCOL_TYPE_ND, IPPROTO_IP},
      {PROTOCOL_TYPE_RAW, IPPROTO_RAW}
      //{PROTOCOL_TYPE_IPX, IPPROTO_},
      //{PROTOCOL_TYPE_SPX, IPPROTO_IP},
      //{PROTOCOL_TYPE_SPX_2, IPPROTO_},
    };
#endif
    auto it = protocol_types.find(protocol_type);
    if (it == protocol_types.end()) return IPPROTO_IP;
    return it->second;
  }
  
  static int32_t socket_option_level_to_native(int32_t socket_option_level) {
#if defined(__APPLE__)
    static map<int32_t, int32_t> socket_option_levels = {
      {SOCKET_OPTION_LEVEL_SOCKET, SOL_SOCKET},
      {SOCKET_OPTION_LEVEL_IP, IPPROTO_IP},
      {SOCKET_OPTION_LEVEL_IP_V6, IPPROTO_IPV6},
      {SOCKET_OPTION_LEVEL_TCP, IPPROTO_TCP},
      {SOCKET_OPTION_LEVEL_UDP, IPPROTO_UDP}
    };
#else
    static map<int32_t, int32_t> socket_option_levels = {
      {SOCKET_OPTION_LEVEL_SOCKET, SOL_SOCKET},
      {SOCKET_OPTION_LEVEL_IP, IPPROTO_IP},
      {SOCKET_OPTION_LEVEL_IP_V6, IPPROTO_IPV6},
      {SOCKET_OPTION_LEVEL_TCP, IPPROTO_TCP},
      {SOCKET_OPTION_LEVEL_UDP, IPPROTO_UDP}
    };
#endif
    auto it = socket_option_levels.find(socket_option_level);
    if (it == socket_option_levels.end()) return SOL_SOCKET;
    return it->second;
  }

  static int32_t socket_option_name_to_native(int32_t socket_option_name) {
#if defined(__APPLE__)
    static map<int32_t, int32_t> socket_option_names = {
      {SOCKET_OPTION_NAME_DEBUG, SO_DEBUG},
      {SOCKET_OPTION_NAME_ACCEPT_CONNECTION, SO_ACCEPTCONN},
      {SOCKET_OPTION_NAME_REUSE_ADDRESS, SO_REUSEADDR},
      {SOCKET_OPTION_NAME_KEEP_ALIVE, SO_KEEPALIVE},
      {SOCKET_OPTION_NAME_DONT_ROUTE, SO_DONTROUTE},
      {SOCKET_OPTION_NAME_BROADCAST, SO_BROADCAST},
      {SOCKET_OPTION_NAME_USE_LOOPBACK, SO_USELOOPBACK},
      {SOCKET_OPTION_NAME_LINGER, SO_LINGER},
      {SOCKET_OPTION_NAME_EXCLUSIVE_ADDRESS_USE, SO_REUSEADDR},
      {SOCKET_OPTION_NAME_OUT_OF_BAND_INLINE, SO_OOBINLINE},
      {SOCKET_OPTION_NAME_SEND_BUFFER, SO_SNDBUF},
      {SOCKET_OPTION_NAME_RECEIVE_BUFFER, SO_RCVBUF},
      {SOCKET_OPTION_NAME_SEND_LOW_WATER, SO_SNDLOWAT},
      {SOCKET_OPTION_NAME_RECEIVE_LOW_WATER, SO_RCVLOWAT},
      {SOCKET_OPTION_NAME_SEND_TIMEOUT, SO_SNDTIMEO},
      {SOCKET_OPTION_NAME_RECEIVE_TIMEOUT, SO_RCVTIMEO},
      {SOCKET_OPTION_NAME_ERROR, SO_ERROR},
      {SOCKET_OPTION_NAME_TYPE, SO_TYPE},
      //{SOCKET_OPTION_NAME_MAX_CONNECTION, SO_},
      {SOCKET_OPTION_NAME_IP_OPTIONS, IP_OPTIONS},
      {SOCKET_OPTION_NAME_HEADER_INCLUDED, IP_HDRINCL},
      {SOCKET_OPTION_NAME_TYPE_OF_SERVICE, IP_TOS},
      {SOCKET_OPTION_NAME_IP_TIME_TO_LIVE, IP_TTL},
      {SOCKET_OPTION_NAME_MULTICAST_INTERFACE, IP_MULTICAST_IF},
      {SOCKET_OPTION_NAME_MULTICAST_TIME_TO_LIVE, IP_MULTICAST_TTL},
      {SOCKET_OPTION_NAME_MULTICAST_LOOPBACK, IP_MULTICAST_LOOP},
      {SOCKET_OPTION_NAME_ADD_MEMBERSHIP, IP_ADD_MEMBERSHIP},
      {SOCKET_OPTION_NAME_DROP_MEMBERSHIP, IP_DROP_MEMBERSHIP},
      {SOCKET_OPTION_NAME_DONT_FRAGMENT, IP_DONTFRAG},
      {SOCKET_OPTION_NAME_ADD_SOURCE_MEMBERSHIP, IP_ADD_SOURCE_MEMBERSHIP},
      {SOCKET_OPTION_NAME_DROP_SOURCE_MEMBERSHIP, IP_DROP_SOURCE_MEMBERSHIP},
      {SOCKET_OPTION_NAME_BLOCK_SOURCE, IP_BLOCK_SOURCE},
      {SOCKET_OPTION_NAME_UNBLOCK_SOURCE, IP_UNBLOCK_SOURCE},
      {SOCKET_OPTION_NAME_PACKET_INFORMATION, IP_PKTINFO},
      {SOCKET_OPTION_NAME_HOP_LIMIT, IPV6_2292HOPLIMIT}, // IPV6_HOPLIMIT
      //{SOCKET_OPTION_NAME_IP_PROTECT_LEVEL, IPV6_},
      {SOCKET_OPTION_NAME_IP_V6_ONLY, IPV6_V6ONLY},
      //{SOCKET_OPTION_NAME_NO_DILAY, TCP_},
      //{SOCKET_OPTION_NAME_BSD_URGENT, TCP_},
      //{SOCKET_OPTION_NAME_EXPEDITED, TCP_},
      //{SOCKET_OPTION_NAME_NO_CHECKSUM, UDP_},
      //{SOCKET_OPTION_NAME_CHECKSUM_COVERAGE, ...},
      //{SOCKET_OPTION_NAME_UPDATE_ACCEPT_CONTEXT, ...},
      //{SOCKET_OPTION_NAME_UPDATE_CONNECT_CONTEXT, ...},
    };
#else
    static map<int32_t, int32_t> socket_option_names = {
      {SOCKET_OPTION_NAME_DEBUG, SO_DEBUG},
      {SOCKET_OPTION_NAME_ACCEPT_CONNECTION, SO_ACCEPTCONN},
      {SOCKET_OPTION_NAME_REUSE_ADDRESS, SO_REUSEADDR},
      {SOCKET_OPTION_NAME_KEEP_ALIVE, SO_KEEPALIVE},
      {SOCKET_OPTION_NAME_DONT_ROUTE, SO_DONTROUTE},
      {SOCKET_OPTION_NAME_BROADCAST, SO_BROADCAST},
      {SOCKET_OPTION_NAME_USE_LOOPBACK, SO_OOBINLINE},
      {SOCKET_OPTION_NAME_LINGER, SO_LINGER},
      {SOCKET_OPTION_NAME_EXCLUSIVE_ADDRESS_USE, SO_REUSEADDR},
      {SOCKET_OPTION_NAME_OUT_OF_BAND_INLINE, SO_OOBINLINE},
      {SOCKET_OPTION_NAME_SEND_BUFFER, SO_SNDBUF},
      {SOCKET_OPTION_NAME_RECEIVE_BUFFER, SO_RCVBUF},
      {SOCKET_OPTION_NAME_SEND_LOW_WATER, SO_SNDLOWAT},
      {SOCKET_OPTION_NAME_RECEIVE_LOW_WATER, SO_RCVLOWAT},
      {SOCKET_OPTION_NAME_SEND_TIMEOUT, SO_SNDTIMEO},
      {SOCKET_OPTION_NAME_RECEIVE_TIMEOUT, SO_RCVTIMEO},
      {SOCKET_OPTION_NAME_ERROR, SO_ERROR},
      {SOCKET_OPTION_NAME_TYPE, SO_TYPE},
      //{SOCKET_OPTION_NAME_MAX_CONNECTION, SO_},
      {SOCKET_OPTION_NAME_IP_OPTIONS, IP_OPTIONS},
      {SOCKET_OPTION_NAME_HEADER_INCLUDED, IP_HDRINCL},
      {SOCKET_OPTION_NAME_TYPE_OF_SERVICE, IP_TOS},
      {SOCKET_OPTION_NAME_IP_TIME_TO_LIVE, IP_TTL},
      {SOCKET_OPTION_NAME_MULTICAST_INTERFACE, IP_MULTICAST_IF},
      {SOCKET_OPTION_NAME_MULTICAST_TIME_TO_LIVE, IP_MULTICAST_TTL},
      {SOCKET_OPTION_NAME_MULTICAST_LOOPBACK, IP_MULTICAST_LOOP},
      {SOCKET_OPTION_NAME_ADD_MEMBERSHIP, IP_ADD_MEMBERSHIP},
      {SOCKET_OPTION_NAME_DROP_MEMBERSHIP, IP_DROP_MEMBERSHIP},
      {SOCKET_OPTION_NAME_DONT_FRAGMENT, IP_NODEFRAG},
      {SOCKET_OPTION_NAME_ADD_SOURCE_MEMBERSHIP, IP_ADD_SOURCE_MEMBERSHIP},
      {SOCKET_OPTION_NAME_DROP_SOURCE_MEMBERSHIP, IP_DROP_SOURCE_MEMBERSHIP},
      {SOCKET_OPTION_NAME_BLOCK_SOURCE, IP_BLOCK_SOURCE},
      {SOCKET_OPTION_NAME_UNBLOCK_SOURCE, IP_UNBLOCK_SOURCE},
      {SOCKET_OPTION_NAME_PACKET_INFORMATION, IP_PKTINFO},
      {SOCKET_OPTION_NAME_HOP_LIMIT, IPV6_HOPLIMIT},
      //{SOCKET_OPTION_NAME_IP_PROTECT_LEVEL, IPV6_},
      {SOCKET_OPTION_NAME_IP_V6_ONLY, IPV6_V6ONLY},
      //{SOCKET_OPTION_NAME_NO_DILAY, TCP_},
      //{SOCKET_OPTION_NAME_BSD_URGENT, TCP_},
      //{SOCKET_OPTION_NAME_EXPEDITED, TCP_},
      //{SOCKET_OPTION_NAME_NO_CHECKSUM, UDP_},
      //{SOCKET_OPTION_NAME_CHECKSUM_COVERAGE, ...},
      //{SOCKET_OPTION_NAME_UPDATE_ACCEPT_CONTEXT, ...},
      //{SOCKET_OPTION_NAME_UPDATE_CONNECT_CONTEXT, ...},
    };
#endif
    auto it = socket_option_names.find(socket_option_name);
    if (it == socket_option_names.end()) return -1;
    return it->second;
  }
  
  static int32_t socket_type_to_native(int32_t socket_type) {
#if defined(__APPLE__)
    static map<int32_t, int32_t> socket_types = {{SOCKET_TYPE_UNKNWON, SOCK_STREAM},
      //{SOCKET_TYPE_UNKNWON, SOCK_},
      {SOCKET_TYPE_STREAM, SOCK_STREAM},
      {SOCKET_TYPE_DGRAM, SOCK_DGRAM},
      {SOCKET_TYPE_RAW, SOCK_RAW},
      {SOCKET_TYPE_RDM, SOCK_RDM},
      {SOCKET_TYPE_SEQPACKET, SOCK_SEQPACKET}
    };
#else
    static map<int32_t, int32_t> socket_types = {
      {SOCKET_TYPE_UNKNWON, SOCK_STREAM | SOCK_CLOEXEC},
      {SOCKET_TYPE_STREAM, SOCK_STREAM | SOCK_CLOEXEC},
      {SOCKET_TYPE_DGRAM, SOCK_DGRAM | SOCK_CLOEXEC},
      {SOCKET_TYPE_RAW, SOCK_RAW | SOCK_CLOEXEC},
      {SOCKET_TYPE_RDM, SOCK_RDM | SOCK_CLOEXEC},
      {SOCKET_TYPE_SEQPACKET, SOCK_SEQPACKET | SOCK_CLOEXEC}
    };
#endif
    auto it = socket_types.find(socket_type);
    if (it == socket_types.end()) return SOCK_STREAM;
    return it->second;
  }
}

int32_t socket::address_family_to_native(int32_t address_family) {
#if defined(__APPLE__)
  static map<int32_t, int32_t> address_families = {
    {ADDRESS_FAMILY_UNKNOWN, -1},
    {ADDRESS_FAMILY_UNSPECIFIED, AF_UNSPEC},
    {ADDRESS_FAMILY_UNIX, AF_UNIX},
    {ADDRESS_FAMILY_INTER_NETWORK, AF_INET},
    {ADDRESS_FAMILY_IMP_LINK, AF_IMPLINK},
    {ADDRESS_FAMILY_PUP, AF_PUP},
    {ADDRESS_FAMILY_CHAOS, AF_CHAOS},
    {ADDRESS_FAMILY_NS, AF_NS},
    //{ADDRESS_FAMILY_IPX, AF_},
    {ADDRESS_FAMILY_ISO, AF_ISO},
    {ADDRESS_FAMILY_ECMA, AF_ECMA},
    {ADDRESS_FAMILY_DATA_KIT, AF_DATAKIT},
    {ADDRESS_FAMILY_CCITT, AF_CCITT},
    {ADDRESS_FAMILY_SNA, AF_SNA},
    {ADDRESS_FAMILY_DEC_NET, AF_DECnet},
    {ADDRESS_FAMILY_DATA_LINK, AF_DLI},
    {ADDRESS_FAMILY_LAT, AF_LAT},
    {ADDRESS_FAMILY_HYPER_CHANNEL, AF_HYLINK},
    {ADDRESS_FAMILY_APPLE_TALK, AF_APPLETALK},
    {ADDRESS_FAMILY_NET_BIOS, AF_NETBIOS},
    //{ADDRESS_FAMILY_VOICE_VIEW, AF_},
    //{ADDRESS_FAMILY_FIRE_FOX, AF_},
    //{ADDRESS_FAMILY_BANYAN, AF_},
    {ADDRESS_FAMILY_ATM, AF_NATM},
    {ADDRESS_FAMILY_INTER_NETWORK_V6, AF_INET6},
    //{ADDRESS_FAMILY_CLUSTER, AF_},
    //{ADDRESS_FAMILY_IEEE12844, AF_},
    //{ADDRESS_FAMILY_IRDA, AF_},
    //{ADDRESS_FAMILY_NETWORK_DESIGNERS, AF_},
    {ADDRESS_FAMILY_MAX, AF_MAX}
  };
#else
  static map<int32_t, int32_t> address_families = {
    {ADDRESS_FAMILY_UNKNOWN, -1},
    {ADDRESS_FAMILY_UNSPECIFIED, AF_UNSPEC},
    {ADDRESS_FAMILY_UNIX, AF_UNIX},
    {ADDRESS_FAMILY_INTER_NETWORK, AF_INET},
    {ADDRESS_FAMILY_SNA, AF_SNA},
    //{ADDRESS_FAMILY_IMP_LINK, AF_IMPLINK},
    //{ADDRESS_FAMILY_PUP, AF_PUP},
    //{ADDRESS_FAMILY_CHAOS, AF_CHAOS},
    //{ADDRESS_FAMILY_NS, AF_NS},
    //{ADDRESS_FAMILY_IPX, AF_},
    //{ADDRESS_FAMILY_ISO, AF_ISO},
    //{ADDRESS_FAMILY_ECMA, AF_ECMA},
    //{ADDRESS_FAMILY_DATA_KIT, AF_DATAKIT},
    //{ADDRESS_FAMILY_CCITT, AF_CCITT},
    {ADDRESS_FAMILY_SNA, AF_SNA},
    {ADDRESS_FAMILY_DEC_NET, AF_DECnet},
    //{ADDRESS_FAMILY_DATA_LINK, AF_DLI},
    //{ADDRESS_FAMILY_LAT, AF_LAT},
    //{ADDRESS_FAMILY_HYPER_CHANNEL, AF_HYLINK},
    {ADDRESS_FAMILY_APPLE_TALK, AF_APPLETALK},
    //{ADDRESS_FAMILY_NET_BIOS, AF_NETBIOS},
    //{ADDRESS_FAMILY_VOICE_VIEW, AF_},
    //{ADDRESS_FAMILY_FIRE_FOX, AF_},
    //{ADDRESS_FAMILY_BANYAN, AF_},
    //{ADDRESS_FAMILY_ATM, AF_NATM},
    {ADDRESS_FAMILY_INTER_NETWORK_V6, AF_INET6},
    //{ADDRESS_FAMILY_CLUSTER, AF_},
    //{ADDRESS_FAMILY_IEEE12844, AF_},
    //{ADDRESS_FAMILY_IRDA, AF_},
    //{ADDRESS_FAMILY_NETWORK_DESIGNERS, AF_},
    {ADDRESS_FAMILY_MAX, AF_MAX}
  };
#endif
  auto it = address_families.find(address_family);
  if (it == address_families.end()) return AF_UNSPEC;
  return it->second;
}

int32_t socket::native_to_address_family(int32_t address_family) {
#if defined(__APPLE__)
  static map<int32_t, int32_t> address_families = {
    //{-1, ADDRESS_FAMILY_UNKNOWN},
    {AF_UNSPEC, ADDRESS_FAMILY_UNSPECIFIED},
    {AF_UNIX, ADDRESS_FAMILY_UNIX},
    {AF_INET, ADDRESS_FAMILY_INTER_NETWORK},
    {AF_IMPLINK, ADDRESS_FAMILY_IMP_LINK},
    {AF_PUP, ADDRESS_FAMILY_PUP},
    {AF_CHAOS, ADDRESS_FAMILY_CHAOS},
    {AF_NS, ADDRESS_FAMILY_NS},
    {AF_ISO, ADDRESS_FAMILY_ISO},
    //{AF_, ADDRESS_FAMILY_IPX},
    {AF_ECMA, ADDRESS_FAMILY_ECMA},
    {AF_DATAKIT, ADDRESS_FAMILY_DATA_KIT},
    {AF_CCITT, ADDRESS_FAMILY_CCITT},
    {AF_SNA, ADDRESS_FAMILY_SNA},
    {AF_DECnet, ADDRESS_FAMILY_DEC_NET},
    {AF_DLI, ADDRESS_FAMILY_DATA_LINK},
    {AF_LAT, ADDRESS_FAMILY_LAT},
    {AF_HYLINK, ADDRESS_FAMILY_HYPER_CHANNEL},
    {AF_APPLETALK, ADDRESS_FAMILY_APPLE_TALK},
    {AF_NETBIOS, ADDRESS_FAMILY_NET_BIOS},
    //{AF_, ADDRESS_FAMILY_VOICE_VIEW},
    //{AF_, ADDRESS_FAMILY_FIRE_FOX},
    //{AF_, ADDRESS_FAMILY_BANYAN},
    {AF_NATM, ADDRESS_FAMILY_ATM},
    {AF_INET6, ADDRESS_FAMILY_INTER_NETWORK_V6},
    //{AF_, ADDRESS_FAMILY_CLUSTER},
    //{AF_, ADDRESS_FAMILY_IEEE12844},
    //{AF_, ADDRESS_FAMILY_IRDA},
    //{AF_, ADDRESS_FAMILY_NETWORK_DESIGNERS},
    {AF_MAX, ADDRESS_FAMILY_MAX}
  };
#else
  static map<int32_t, int32_t> address_families = {
    //{-1, ADDRESS_FAMILY_UNKNOWN},
    {AF_UNSPEC, ADDRESS_FAMILY_UNSPECIFIED},
    {AF_UNIX, ADDRESS_FAMILY_UNIX},
    {AF_INET, ADDRESS_FAMILY_INTER_NETWORK},
    //{AF_IMPLINK, ADDRESS_FAMILY_IMP_LINK},
    //{AF_PUP, ADDRESS_FAMILY_PUP},
    //{AF_CHAOS, ADDRESS_FAMILY_CHAOS},
    //{AF_NS, ADDRESS_FAMILY_NS},
    //{AF_ISO, ADDRESS_FAMILY_ISO},
    //{AF_, ADDRESS_FAMILY_IPX},
    //{AF_ECMA, ADDRESS_FAMILY_ECMA},
    //{AF_DATAKIT, ADDRESS_FAMILY_DATA_KIT},
    //{AF_CCITT, ADDRESS_FAMILY_CCITT},
    {AF_SNA, ADDRESS_FAMILY_SNA},
    {AF_DECnet, ADDRESS_FAMILY_DEC_NET},
    //{AF_DLI, ADDRESS_FAMILY_DATA_LINK},
    //{AF_LAT, ADDRESS_FAMILY_LAT},
    //{AF_HYLINK, ADDRESS_FAMILY_HYPER_CHANNEL},
    {AF_APPLETALK, ADDRESS_FAMILY_APPLE_TALK},
    //{AF_NETBIOS, ADDRESS_FAMILY_NET_BIOS},
    //{AF_, ADDRESS_FAMILY_VOICE_VIEW},
    //{AF_, ADDRESS_FAMILY_FIRE_FOX},
    //{AF_, ADDRESS_FAMILY_BANYAN},
    //{AF_NATM, ADDRESS_FAMILY_ATM},
    {AF_INET6, ADDRESS_FAMILY_INTER_NETWORK_V6},
    //{AF_, ADDRESS_FAMILY_CLUSTER},
    //{AF_, ADDRESS_FAMILY_IEEE12844},
    //{AF_, ADDRESS_FAMILY_IRDA},
    //{AF_, ADDRESS_FAMILY_NETWORK_DESIGNERS},
    {AF_MAX, ADDRESS_FAMILY_MAX}
  };
#endif
  auto it = address_families.find(address_family);
  if (it == address_families.end()) return ADDRESS_FAMILY_UNSPECIFIED;
  return it->second;
}

intptr_t socket::accept(intptr_t handle, vector<uint8_t>& socket_address) {
#if defined(__APPLE__)
  swap(socket_address[0], socket_address[1]);
#endif
  socklen_t address_length = static_cast<socklen_t>(socket_address.size());
  intptr_t socket = static_cast<intptr_t>(::accept(static_cast<int32_t>(handle), reinterpret_cast<sockaddr*>(socket_address.data()), &address_length));
  //if (socket_address.size() != address_length) socket_address.resize(address_length);
#if defined(__APPLE__)
  swap(socket_address[0], socket_address[1]);
#endif
  return socket;
}

int32_t socket::bind(intptr_t handle, const vector<uint8_t>& socket_address) {
#if defined(__APPLE__)
  swap(const_cast<vector<uint8_t>&>(socket_address)[0], const_cast<vector<uint8_t>&>(socket_address)[1]);
#endif
  auto result = ::bind(static_cast<int32_t>(handle), reinterpret_cast<const sockaddr*>(socket_address.data()), static_cast<socklen_t>(socket_address.size()));
#if defined(__APPLE__)
  swap(const_cast<vector<uint8_t>&>(socket_address)[0], const_cast<vector<uint8_t>&>(socket_address)[1]);
#endif
  return result;
}

void socket::cleanup() {
  // Nothing to do on linux and macOS.
}

int32_t socket::connect(intptr_t handle, const vector<uint8_t>& socket_address) {
#if defined(__APPLE__)
  swap(const_cast<vector<uint8_t>&>(socket_address)[0], const_cast<vector<uint8_t>&>(socket_address)[1]);
#endif
  auto result = ::connect(static_cast<int32_t>(handle), reinterpret_cast<const sockaddr*>(socket_address.data()), socket_address.size());
#if defined(__APPLE__)
  swap(const_cast<vector<uint8_t>&>(socket_address)[0], const_cast<vector<uint8_t>&>(socket_address)[1]);
#endif
  return result;
}

intptr_t socket::create(int32_t address_family, int32_t socket_type, int32_t protocol_type) {
  return static_cast<intptr_t>(::socket(address_family_to_native(address_family), socket_type_to_native(socket_type), protocol_type_to_native(protocol_type)));
}

int32_t socket::destroy(intptr_t handle) {
  return ::close(static_cast<int32_t>(handle));
}

size_t socket::get_available(intptr_t handle) {
  int32_t nbr_bytes_available = 0;
  if (ioctl(static_cast<int32_t>(handle), FIONREAD, &nbr_bytes_available) != 0) return -1;
  return static_cast<size_t>(nbr_bytes_available);
}

int32_t socket::get_last_error() {
  return native_to_socket_error(errno);
}

bool socket::get_os_supports_ip_v4() noexcept {
  int32_t s = ::socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
  if (s == -1) return false;
  close(s);
  return true;
}

bool socket::get_os_supports_ip_v6() noexcept {
  int32_t s = ::socket(AF_INET6, SOCK_STREAM, IPPROTO_IP);
  if (s == -1) return false;
  close(s);
  return true;
}

int32_t socket::get_raw_socket_option(intptr_t handle, int32_t socket_option_level, int32_t socket_option_name, intptr_t option, size_t& option_length) {
  return ::getsockopt(static_cast<int32_t>(handle), socket_option_level, socket_option_name, reinterpret_cast<void*>(option), reinterpret_cast<socklen_t*>(&option_length));
}

int32_t socket::get_socket_option(intptr_t handle, int32_t socket_option_level, int32_t socket_option_name, intptr_t option, size_t& option_length) {
  if (socket_option_name_to_native(socket_option_name) == -1) {
    errno = ENOTSUP;
    return -1;
  }
  if (socket_option_level == SOCKET_OPTION_LEVEL_SOCKET && (socket_option_name == SOCKET_OPTION_NAME_SEND_TIMEOUT || socket_option_name == SOCKET_OPTION_NAME_RECEIVE_TIMEOUT)) {
    timeval timeout = {0, 0};
    int32_t result = ::getsockopt(static_cast<int32_t>(handle), socket_option_level_to_native(socket_option_level), socket_option_name_to_native(socket_option_name), &timeout, reinterpret_cast<socklen_t*>(&option_length));
    *reinterpret_cast<int32_t*>(option) = static_cast<int32_t>(timeout.tv_sec * 1000 + timeout.tv_usec / 1000);
    return result;
  }
  
  return ::getsockopt(static_cast<int32_t>(handle), socket_option_level_to_native(socket_option_level), socket_option_name_to_native(socket_option_name), reinterpret_cast<void*>(option), reinterpret_cast<socklen_t*>(&option_length));
}

int32_t socket::get_socket_linger_option(intptr_t handle, bool& enabled, uint32_t& linger_time) {
  linger l {static_cast<int32_t>(enabled), static_cast<int32_t>(linger_time)};
  size_t linger_size = 0;
  int32_t result = ::getsockopt(static_cast<int32_t>(handle), SOL_SOCKET, SO_LINGER, &l, reinterpret_cast<socklen_t*>(&linger_size));
  if (result == 0) {
    enabled = static_cast<bool>(l.l_onoff);
    linger_time = static_cast<uint32_t>(l.l_linger);
  }
  return result;
}

int32_t socket::get_socket_multicast_option(intptr_t handle, int32_t socket_option_name, uint32_t& multicast_address, uint32_t& interface_index) {
  struct multicast {
    uint32_t multicast_address;
    uint32_t interface_index;
  } m;
  size_t multicast_size = 0;
  int32_t result = getsockopt(static_cast<int32_t>(handle), IPPROTO_IP, socket_option_name_to_native(socket_option_name), &m, reinterpret_cast<socklen_t*>(&multicast_size));
  if (result == 0) {
    multicast_address = m.multicast_address;
    interface_index = m.interface_index;
  }
  return result;
}

int32_t socket::get_socket_ip_v6_multicast_option(intptr_t handle, int32_t socket_option_name, vector<uint8_t>& multicast_address, uint32_t& interface_index) {
  struct multicast {
    uint8_t multicast_address[16];
    uint32_t interface_index;
  } m;
  size_t multicast_size = 0;
  int32_t result = getsockopt(static_cast<int32_t>(handle), IPPROTO_IP, socket_option_name_to_native(socket_option_name), &m, reinterpret_cast<socklen_t*>(&multicast_size));
  if (result == 0) {
    for (auto index = 0U; index < multicast_address.size(); ++index)
      multicast_address[index] = m.multicast_address[index];
    interface_index = m.interface_index;
  }
  return result;
}

int32_t socket::io_control(intptr_t handle, int32_t io_control, vector<uint8_t>& option_in_value, vector<uint8_t>& option_out_value) {
  // Not implemented
  errno = ENOTSUP;
  return -1;
}

int32_t socket::listen(intptr_t handle, size_t backlog) {
  return ::listen(static_cast<int32_t>(handle), static_cast<int32_t>(backlog));
}

int32_t socket::poll(intptr_t handle, int32_t microseconds, int32_t mode) {
  if (handle == 0 || microseconds < 0) return -1;
  
  pollfd poll_fd {};
  poll_fd.fd = static_cast<int32_t>(handle);
  switch (mode) {
    case SELECT_MODE_READ: poll_fd.events = POLLIN; break;
    case SELECT_MODE_WRITE: poll_fd.events = POLLOUT; break;
    case SELECT_MODE_ERROR: poll_fd.events = POLLERR; break;
    default: return -1;
  }
  return ::poll(&poll_fd, 1, microseconds);
}

int32_t socket::receive(intptr_t handle, vector<uint8_t>& buffer, size_t offset, size_t size, int32_t flags) {
  int32_t result = static_cast<int32_t>(::recv(static_cast<int32_t>(handle), &buffer.data()[offset], size, flags));
  if (result == -1 && errno == EBADF) errno = EINTR;
  if (result == -1 && errno == EAGAIN) errno = ETIMEDOUT;
  return result;
}

int32_t socket::receive_from(intptr_t handle, vector<uint8_t>& buffer, size_t offset, size_t size, int32_t flags, vector<uint8_t>& socket_address) {
#if defined(__APPLE__)
  swap(socket_address[0], socket_address[1]);
#endif
  socklen_t address_length = static_cast<socklen_t>(socket_address.size());
  int32_t result = static_cast<int32_t>(::recvfrom(static_cast<int32_t>(handle), &buffer.data()[offset], size, flags, reinterpret_cast<sockaddr*>(socket_address.data()), &address_length));
  //if (socket_address.size() != address_length) socket_address.resize(address_length);
#if defined(__APPLE__)
  swap(socket_address[0], socket_address[1]);
#endif
  
  if (result == -1 && errno == EBADF) errno = EINTR;
  if (result == -1 && errno == EAGAIN) errno = ETIMEDOUT;
  return result;
}

int32_t socket::select(vector<intptr_t>& check_read, vector<intptr_t>& check_write, vector<intptr_t>& check_error, int32_t microseconds) {
  size_t nfds = 0;
  
  fd_set read_fds;
  FD_ZERO(&read_fds);
  for (auto i = 0U; i < check_read.size() && i < FD_SETSIZE; i++)
    FD_SET(static_cast<int32_t>(check_read[i]), &read_fds);
  if (check_read.size() > nfds) nfds = check_read.size();
  
  fd_set write_fds;
  FD_ZERO(&write_fds);
  for (auto i = 0U; i < check_write.size() && i < FD_SETSIZE; i++)
    FD_SET(static_cast<int32_t>(check_write[i]), &write_fds);
  if (check_write.size() > nfds) nfds = check_write.size();
  
  fd_set error_fds;
  FD_ZERO(&error_fds);
  for (auto i = 0U; i < check_error.size() && i < FD_SETSIZE; i++)
    FD_SET(static_cast<int32_t>(check_error[i]), &error_fds);
  if (check_error.size() > nfds) nfds = check_error.size();
  
  timeval timeout {microseconds / 1000000, microseconds % 1000000};
  int32_t result = ::select(static_cast<int32_t>(nfds + 1), &read_fds, &write_fds, &error_fds, microseconds == -1 ? nullptr : &timeout);
  
  for (auto i = 0U; i < check_read.size(); i++) {
    FD_CLR(static_cast<int32_t>(check_read[i]), &read_fds);
    if (FD_ISSET(static_cast<int32_t>(check_read[i]), &read_fds) == 0) check_read[i] = 0;
  }
  
  for (auto i = 0U; i < check_write.size(); i++) {
    FD_CLR(static_cast<int32_t>(check_write[i]), &write_fds);
    if (FD_ISSET(static_cast<int32_t>(check_write[i]), &write_fds) == 0) check_write[i] = 0;
  }
  
  for (auto i = 0U; i < check_error.size(); i++) {
    FD_CLR(static_cast<int32_t>(check_error[i]), &error_fds);
    if (FD_ISSET(static_cast<int32_t>(check_error[i]), &error_fds) == 0) check_error[i] = 0;
  }
  
  return result;
}

int32_t socket::send(intptr_t handle, const vector<uint8_t>& buffer, size_t offset, size_t size, int32_t flags) {
  return static_cast<int32_t>(::send(static_cast<int32_t>(handle), &buffer.data()[offset], size, flags));
}

int32_t socket::send_to(intptr_t handle, const vector<uint8_t>& buffer, size_t offset, size_t size, int32_t flags, const vector<uint8_t>& socket_address) {
#if defined(__APPLE__)
  swap(const_cast<vector<uint8_t>&>(socket_address)[0], const_cast<vector<uint8_t>&>(socket_address)[1]);
#endif
  auto result = static_cast<int32_t>(::sendto(static_cast<int32_t>(handle), &buffer.data()[offset], size, flags, reinterpret_cast<const sockaddr*>(socket_address.data()), static_cast<socklen_t>(socket_address.size())));
#if defined(__APPLE__)
  swap(const_cast<vector<uint8_t>&>(socket_address)[0], const_cast<vector<uint8_t>&>(socket_address)[1]);
#endif
  return result;
}

int32_t socket::set_blocking(intptr_t handle, bool blocking) {
  int32_t result = -1;
  
  if ((result = fcntl(static_cast<int32_t>(handle), F_GETFL, 0)) != -1) {
    int32_t flags = result;
    if (blocking == true) flags &= ~O_NONBLOCK;
    else flags |= O_NONBLOCK;
    result = fcntl(static_cast<int32_t>(handle), F_SETFL, flags)  == -1 ? -1 : 0;
  }
  
  return result;
}

int32_t socket::set_raw_socket_option(intptr_t handle, int32_t socket_option_level, int32_t socket_option_name, intptr_t option, size_t option_length) {
  return setsockopt(static_cast<int32_t>(handle), socket_option_level, socket_option_name, reinterpret_cast<const void*>(option), static_cast<socklen_t>(option_length));
}

int32_t socket::set_socket_option(intptr_t handle, int32_t socket_option_level, int32_t socket_option_name, intptr_t option, size_t option_length) {
  if (socket_option_name_to_native(socket_option_name) == -1) {
    errno = ENOTSUP;
    return -1;
  }
  if (socket_option_level == SOCKET_OPTION_LEVEL_SOCKET && (socket_option_name == SOCKET_OPTION_NAME_SEND_TIMEOUT || socket_option_name == SOCKET_OPTION_NAME_RECEIVE_TIMEOUT)) {
    timeval timeout = {*reinterpret_cast<const int32_t*>(option) / 1000, *reinterpret_cast<const int32_t*>(option) % 1000 * 1000};
    return ::setsockopt(static_cast<int32_t>(handle), socket_option_level_to_native(socket_option_level), socket_option_name_to_native(socket_option_name), &timeout, sizeof(timeval));
  }
  return setsockopt(static_cast<int32_t>(handle), socket_option_level_to_native(socket_option_level), socket_option_name_to_native(socket_option_name), reinterpret_cast<const void*>(option), static_cast<socklen_t>(option_length));
}

int32_t socket::set_socket_linger_option(intptr_t handle, bool enabled, uint32_t linger_time) {
  linger l {static_cast<int32_t>(enabled), static_cast<int32_t>(linger_time)};
  return setsockopt(static_cast<int32_t>(handle), SOL_SOCKET, SO_LINGER, &l, static_cast<socklen_t>(sizeof(linger)));
}

int32_t socket::set_socket_multicast_option(intptr_t handle, int32_t socket_option_name, uint32_t multicast_address, uint32_t interface_index) {
  struct multicast {
    uint32_t multicast_address;
    uint32_t interface_index;
  } m {multicast_address, interface_index};
  return setsockopt(static_cast<int32_t>(handle), IPPROTO_TCP, socket_option_name_to_native(socket_option_name), &m, static_cast<socklen_t>(sizeof(multicast)));
}

int32_t socket::set_socket_ip_v6_multicast_option(intptr_t handle, int32_t socket_option_name, const vector<uint8_t>& multicast_address, uint32_t interface_index) {
  struct multicast {
    uint8_t multicast_address[16];
    uint32_t interface_index;
  } m;
  for (auto index = 0U; index < multicast_address.size(); ++index)
    m.multicast_address[index] = multicast_address[index];
  m.interface_index = interface_index;
  return setsockopt(static_cast<int32_t>(handle), IPPROTO_IP, socket_option_name_to_native(socket_option_name), &m, static_cast<socklen_t>(sizeof(multicast)));
}

int32_t socket::shutdown(intptr_t handle, int32_t how) {
  int32_t result = ::shutdown(static_cast<int32_t>(handle), how);
  if (how == SOCKET_SHUTDOWN_BOTH && result == -1 && errno == ENOTCONN) {
    errno = 0;
    result = 0;
  }
  return result;
}

void socket::startup() {
  // Nothing on linux and macOS
}
