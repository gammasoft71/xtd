#define UNICODE
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/socket>
#include <xtd/native/address_family_constants>
#include <xtd/native/protocol_type_constants>
#include <xtd/native/select_mode_constants>
#include <xtd/native/socket_option_name_constants>
#include <xtd/native/socket_option_level_constants>
#include <xtd/native/socket_shutdown_constants>
#include <xtd/native/socket_type_constants>
#include "../../../../include/xtd/native/win32/strings.hpp"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <map>
#include <sstream>
#include <string>
#include <Winsock2.h>
#include <Windows.h>

using namespace std;
using namespace xtd::native;

namespace {
  static int32_t protocol_type_to_native(int32_t protocol_type) {
    static auto protocol_types = map<int32_t, int32_t> {{PROTOCOL_TYPE_UNKNOWN, IPPROTO_IP}, {PROTOCOL_TYPE_IP, IPPROTO_IP}, {PROTOCOL_TYPE_ICMP, IPPROTO_ICMP}, {PROTOCOL_TYPE_IGMP, IPPROTO_IGMP}, {PROTOCOL_TYPE_GGP, IPPROTO_GGP}, {PROTOCOL_TYPE_IP_V4, IPPROTO_IPV4}, {PROTOCOL_TYPE_IP_V6, IPPROTO_IPV6}, {PROTOCOL_TYPE_TCP, IPPROTO_TCP}, {PROTOCOL_TYPE_PUP, IPPROTO_PUP}, {PROTOCOL_TYPE_UDP, IPPROTO_UDP}, {PROTOCOL_TYPE_IDP, IPPROTO_IDP}, {PROTOCOL_TYPE_IP_V6, IPPROTO_IPV6}, {PROTOCOL_TYPE_IP_V6_ROUTING_HEADER, IPPROTO_ROUTING}, {PROTOCOL_TYPE_IP_V6_FRAGMENT_HEADER, IPPROTO_FRAGMENT}, {PROTOCOL_TYPE_IP_SEC_ENCAPSULATING_SECURITY_PAYLOAD, IPPROTO_ESP}, {PROTOCOL_TYPE_IP_SEC_AUTHENTICATION_HEADER, IPPROTO_AH}, {PROTOCOL_TYPE_ICMP_V6, IPPROTO_ICMPV6}, {PROTOCOL_TYPE_IP_V6_NO_NEXT_HEADER, IPPROTO_NONE}, {PROTOCOL_TYPE_IP_V6_DESTINATION_OPTIONS, IPPROTO_DSTOPTS}, {PROTOCOL_TYPE_ND, IPPROTO_ND}, {PROTOCOL_TYPE_RAW, IPPROTO_RAW}, {PROTOCOL_TYPE_SPX, IPPROTO_IP}, {PROTOCOL_TYPE_SPX_2, IPPROTO_IP}};
    auto it = protocol_types.find(protocol_type);
    if (it == protocol_types.end()) return IPPROTO_IP;
    return it->second;
  }
  
  static int32_t socket_option_name_to_native(int32_t socket_option_name) {
    static auto socket_option_names = map<int32_t, int32_t> {{SOCKET_OPTION_NAME_DEBUG, SO_DEBUG}, {SOCKET_OPTION_NAME_ACCEPT_CONNECTION, SO_ACCEPTCONN}, {SOCKET_OPTION_NAME_REUSE_ADDRESS, SO_REUSEADDR}, {SOCKET_OPTION_NAME_KEEP_ALIVE, SO_KEEPALIVE}, {SOCKET_OPTION_NAME_DONT_ROUTE, SO_DONTROUTE}, {SOCKET_OPTION_NAME_BROADCAST, SO_BROADCAST}, {SOCKET_OPTION_NAME_USE_LOOPBACK, SO_USELOOPBACK}, {SOCKET_OPTION_NAME_LINGER, SO_LINGER}, {SOCKET_OPTION_NAME_OUT_OF_BAND_INLINE, SO_OOBINLINE}, {SOCKET_OPTION_NAME_SEND_BUFFER, SO_SNDBUF}, {SOCKET_OPTION_NAME_RECEIVE_BUFFER, SO_RCVBUF}, {SOCKET_OPTION_NAME_SEND_LOW_WATER, SO_SNDLOWAT}, {SOCKET_OPTION_NAME_RECEIVE_LOW_WATER, SO_RCVLOWAT}, {SOCKET_OPTION_NAME_SEND_TIMEOUT, SO_SNDTIMEO}, {SOCKET_OPTION_NAME_RECEIVE_TIMEOUT, SO_RCVTIMEO}, {SOCKET_OPTION_NAME_ERROR, SO_ERROR}, {SOCKET_OPTION_NAME_TYPE, SO_TYPE}};
    auto it = socket_option_names.find(socket_option_name);
    if (it == socket_option_names.end()) return socket_option_name;
    return it->second;
  }
  
  static int32_t socket_option_level_to_native(int32_t socket_option_level) {
    static auto socket_option_levels = map<int32_t, int32_t> {{SOCKET_OPTION_LEVEL_SOCKET, SOL_SOCKET}, {SOCKET_OPTION_LEVEL_IP, IPPROTO_IP}, {SOCKET_OPTION_LEVEL_IP_V6, IPPROTO_IPV6}, {SOCKET_OPTION_LEVEL_TCP, IPPROTO_TCP}, {SOCKET_OPTION_LEVEL_UDP, IPPROTO_UDP}};
    auto it = socket_option_levels.find(socket_option_level);
    if (it == socket_option_levels.end()) return SOL_SOCKET;
    return it->second;
  }
  
  static int32_t socket_type_to_native(int32_t socket_type) {
    static auto socket_types = map<int32_t, int32_t> {{SOCKET_TYPE_UNKNOWN, SOCK_STREAM}, {SOCKET_TYPE_STREAM, SOCK_STREAM}, {SOCKET_TYPE_DGRAM, SOCK_DGRAM}, {SOCKET_TYPE_RAW, SOCK_RAW}, {SOCKET_TYPE_RDM, SOCK_RDM}, {SOCKET_TYPE_SEQPACKET, SOCK_SEQPACKET}};
    auto it = socket_types.find(socket_type);
    if (it == socket_types.end()) return SOCK_STREAM;
    return it->second;
  }
}

int32_t socket::address_family_to_native(int32_t address_family) {
  static auto address_families = map<int32_t, int32_t> {{ADDRESS_FAMILY_UNIX, AF_UNIX}, {ADDRESS_FAMILY_INTER_NETWORK, AF_INET}, {ADDRESS_FAMILY_IMP_LINK, AF_IMPLINK}, {ADDRESS_FAMILY_PUP, AF_PUP}, {ADDRESS_FAMILY_CHAOS, AF_CHAOS}, {ADDRESS_FAMILY_NS, AF_NS}, {ADDRESS_FAMILY_ISO, AF_ISO}, {ADDRESS_FAMILY_ECMA, AF_ECMA}, {ADDRESS_FAMILY_DATA_KIT, AF_DATAKIT}, {ADDRESS_FAMILY_CCITT, AF_CCITT}, {ADDRESS_FAMILY_SNA, AF_SNA}, {ADDRESS_FAMILY_DEC_NET, AF_DECnet}, {ADDRESS_FAMILY_DATA_LINK, AF_DLI}, {ADDRESS_FAMILY_LAT, AF_LAT}, {ADDRESS_FAMILY_HYPER_CHANNEL, AF_HYLINK}, {ADDRESS_FAMILY_APPLE_TALK, AF_APPLETALK}, {ADDRESS_FAMILY_NET_BIOS, AF_NETBIOS}, {ADDRESS_FAMILY_VOICE_VIEW, AF_VOICEVIEW}, {ADDRESS_FAMILY_FIRE_FOX, AF_FIREFOX}, {ADDRESS_FAMILY_BANYAN, AF_BAN}, {ADDRESS_FAMILY_ATM, AF_ATM}, {ADDRESS_FAMILY_INTER_NETWORK_V6, AF_INET6}, {ADDRESS_FAMILY_CLUSTER, AF_CLUSTER}, {ADDRESS_FAMILY_IEEE12844, AF_12844}, {ADDRESS_FAMILY_IRDA, AF_IRDA}, {ADDRESS_FAMILY_NETWORK_DESIGNERS, AF_NETDES}, {ADDRESS_FAMILY_MAX, AF_MAX}};
  auto it = address_families.find(address_family);
  if (it == address_families.end()) return AF_UNSPEC;
  return it->second;
}

int32_t socket::native_to_address_family(int32_t address_family) {
  static auto address_families = map<int32_t, int32_t> {{AF_UNIX, ADDRESS_FAMILY_UNIX}, {AF_INET, ADDRESS_FAMILY_INTER_NETWORK}, {AF_IMPLINK, ADDRESS_FAMILY_IMP_LINK}, {AF_PUP, ADDRESS_FAMILY_PUP}, {AF_CHAOS, ADDRESS_FAMILY_CHAOS}, {AF_NS, ADDRESS_FAMILY_NS}, {AF_ISO, ADDRESS_FAMILY_ISO}, {AF_ECMA, ADDRESS_FAMILY_ECMA}, {AF_DATAKIT, ADDRESS_FAMILY_DATA_KIT}, {AF_CCITT, ADDRESS_FAMILY_CCITT}, {AF_SNA, ADDRESS_FAMILY_SNA}, {AF_DECnet, ADDRESS_FAMILY_DEC_NET}, {AF_DLI, ADDRESS_FAMILY_DATA_LINK}, {AF_LAT, ADDRESS_FAMILY_LAT}, {AF_HYLINK, ADDRESS_FAMILY_HYPER_CHANNEL}, {AF_APPLETALK, ADDRESS_FAMILY_APPLE_TALK}, {AF_NETBIOS, ADDRESS_FAMILY_NET_BIOS}, {AF_VOICEVIEW, ADDRESS_FAMILY_VOICE_VIEW}, {AF_FIREFOX, ADDRESS_FAMILY_FIRE_FOX}, {AF_BAN, ADDRESS_FAMILY_BANYAN}, {AF_ATM, ADDRESS_FAMILY_ATM}, {AF_INET6, ADDRESS_FAMILY_INTER_NETWORK_V6}, {AF_CLUSTER, ADDRESS_FAMILY_CLUSTER}, {AF_12844, ADDRESS_FAMILY_IEEE12844}, {AF_IRDA, ADDRESS_FAMILY_IRDA}, {AF_NETDES, ADDRESS_FAMILY_NETWORK_DESIGNERS}, {AF_MAX, ADDRESS_FAMILY_MAX}};
  auto it = address_families.find(address_family);
  if (it == address_families.end()) return ADDRESS_FAMILY_UNSPECIFIED;
  return it->second;
}

intmax_t socket::accept(intmax_t handle, vector<uint8_t>& socket_address) {
  auto address_length = static_cast<int32_t>(socket_address.size());
  auto socket = static_cast<intmax_t>(::accept(static_cast<SOCKET>(handle), reinterpret_cast<SOCKADDR*>(socket_address.data()), &address_length));
  if (socket_address.size() != static_cast<size_t>(address_length)) socket_address.resize(static_cast<size_t>(address_length));
  return socket;
}

int32_t socket::bind(intmax_t handle, const vector<uint8_t>& socket_address) {
  return ::bind(static_cast<SOCKET>(handle), reinterpret_cast<const SOCKADDR*>(socket_address.data()), static_cast<int32_t>(socket_address.size()));
}

void socket::cleanup() {
  WSACleanup();
}

int32_t socket::connect(intmax_t handle, const vector<uint8_t>& socket_address) {
  return ::connect(static_cast<SOCKET>(handle), reinterpret_cast<const SOCKADDR*>(socket_address.data()), static_cast<int32_t>(socket_address.size()));
}

intmax_t socket::create(int32_t address_family, int32_t socket_type, int32_t protocol_type) {
  return static_cast<intmax_t>(::socket(address_family_to_native(address_family), socket_type_to_native(socket_type), protocol_type_to_native(protocol_type)));
}

int32_t socket::destroy(intmax_t handle) {
  return ::closesocket(static_cast<SOCKET>(handle));
}

std::string socket::socket_error_to_string(int32_t socket_error) {
  auto message_buffer = LPWSTR {nullptr};
  auto size = FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, nullptr, socket_error, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), reinterpret_cast<LPWSTR>(&message_buffer), 0, nullptr);
  if (message_buffer == nullptr) {
    auto ss = std::wstringstream {};
    ss << L"Unknown error (0x" << std::hex << socket_error << L")";
    return xtd::native::win32::strings::to_string(ss.str());
  }
  auto result = std::wstring {message_buffer, size - 1};
  LocalFree(message_buffer);
  return xtd::native::win32::strings::to_string(result);
}

size_t socket::get_available(intmax_t handle) {
  auto nbr_bytes_available = u_long {};
  if (::ioctlsocket(static_cast<SOCKET>(handle), FIONREAD, &nbr_bytes_available) != 0) return static_cast<size_t>(-1);
  return static_cast<size_t>(nbr_bytes_available);
}

int32_t socket::get_last_error() {
  return WSAGetLastError();
}

bool socket::get_os_supports_ip_v4() noexcept {
  auto s = ::socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
  if (s == INVALID_SOCKET) return false;
  closesocket(s);
  return true;
}

bool socket::get_os_supports_ip_v6() noexcept {
  auto s = ::socket(AF_INET6, SOCK_STREAM, IPPROTO_IP);
  if (s == INVALID_SOCKET) return false;
  closesocket(s);
  return true;
}

int32_t socket::get_raw_socket_option(intmax_t handle, int32_t socket_option_level, int32_t socket_option_name, intmax_t option, size_t& option_length) {
  return ::getsockopt(static_cast<SOCKET>(handle), socket_option_level, socket_option_name, reinterpret_cast<char*>(option), reinterpret_cast<int32_t*>(&option_length));
}

int32_t socket::get_socket_option(intmax_t handle, int32_t socket_option_level, int32_t socket_option_name, intmax_t option, size_t& option_length) {
  return ::getsockopt(static_cast<SOCKET>(handle), socket_option_level_to_native(socket_option_level), socket_option_name_to_native(socket_option_name), reinterpret_cast<char*>(option), reinterpret_cast<int32_t*>(&option_length));
}

int32_t socket::get_socket_linger_option(intmax_t handle, bool& enabled, uint32_t& linger_time) {
  auto l = LINGER {static_cast<u_short>(enabled), static_cast<u_short>(linger_time)};
  auto linger_size = sizeof(LINGER);
  auto result = ::getsockopt(static_cast<SOCKET>(handle), SOL_SOCKET, SO_LINGER, reinterpret_cast<char*>(&l), reinterpret_cast<int32_t*>(&linger_size));
  if (result == 0) {
    enabled = static_cast<bool>(l.l_onoff);
    linger_time = static_cast<uint32_t>(l.l_linger);
  }
  return result;
}

int32_t socket::get_socket_multicast_option(intmax_t handle, int32_t socket_option_name, uint32_t& multicast_address, uint32_t& interface_index) {
  struct multicast {
    uint32_t multicast_address;
    uint32_t interface_index;
  } m;
  auto multicast_size = sizeof(multicast);
  auto result = getsockopt(static_cast<SOCKET>(handle), IPPROTO_IP, socket_option_name_to_native(socket_option_name), reinterpret_cast<char*>(&m), reinterpret_cast<int32_t*>(&multicast_size));
  if (result == 0) {
    multicast_address = m.multicast_address;
    interface_index = m.interface_index;
  }
  return result;
}

int32_t socket::get_socket_ip_v6_multicast_option(intmax_t handle, int32_t socket_option_name, vector<uint8_t>& multicast_address, uint64_t& interface_index) {
  struct multicast {
    uint8_t multicast_address[16];
    uint64_t interface_index;
  } m;
  auto multicast_size = sizeof(multicast);
  auto result = getsockopt(static_cast<SOCKET>(handle), IPPROTO_IP, socket_option_name_to_native(socket_option_name), reinterpret_cast<char*>(&m), reinterpret_cast<int32_t*>(&multicast_size));
  if (result == 0) {
    for (auto index = 0U; index < multicast_address.size(); ++index)
      multicast_address[index] = m.multicast_address[index];
    interface_index = m.interface_index;
  }
  return result;
}

int32_t socket::io_control(intmax_t handle, int32_t io_control, vector<uint8_t>& option_in_value, vector<uint8_t>& option_out_value) {
  auto option_out_value_size = size_t {};
  auto result = WSAIoctl(static_cast<SOCKET>(handle), io_control, option_in_value.data(), static_cast<int32_t>(option_in_value.size()), option_out_value.data(), static_cast<int32_t>(option_out_value.size()), reinterpret_cast<LPDWORD>(&option_out_value_size), nullptr, nullptr);
  if (option_out_value.size() != option_out_value_size) option_out_value.resize(option_out_value_size);
  return result;
}

int32_t socket::listen(intmax_t handle, size_t backlog) {
  auto backlog_value = backlog != static_cast<size_t>(-1) ? static_cast<int32_t>(backlog) : SOMAXCONN;
  return ::listen(static_cast<SOCKET>(handle), backlog_value);
}

int32_t socket::poll(intmax_t handle, int32_t microseconds, int32_t mode) {
  if (handle == 0 || microseconds < 0) return -1;
  
  auto timeout = timeval {microseconds / 1000000, microseconds % 1000000};
  auto fdset = fd_set {};
  FD_ZERO(&fdset);
  FD_SET(static_cast<SOCKET>(handle), &fdset);
  switch (mode) {
    case SELECT_MODE_READ: return ::select(0, &fdset, nullptr, nullptr, microseconds == -1 ? nullptr : &timeout);
    case SELECT_MODE_WRITE: return ::select(0, nullptr, &fdset, nullptr, microseconds == -1 ? nullptr : &timeout);
    case SELECT_MODE_ERROR: return ::select(0, nullptr, nullptr, &fdset, microseconds == -1 ? nullptr : &timeout);
    default: return -1;
  }
}

int32_t socket::receive(intmax_t handle, vector<uint8_t>& buffer, size_t offset, size_t size, int32_t flags) {
  return static_cast<int32_t>(::recv(static_cast<SOCKET>(handle), reinterpret_cast<char*>(&buffer.data()[offset]), static_cast<int32_t>(size), flags));
}

int32_t socket::receive_from(intmax_t handle, vector<uint8_t>& buffer, size_t offset, size_t size, int32_t flags, vector<uint8_t>& socket_address) {
  auto address_length = static_cast<int32_t>(socket_address.size());
  auto result = static_cast<int32_t>(::recvfrom(static_cast<SOCKET>(handle), reinterpret_cast<char*>(&buffer.data()[offset]), static_cast<int32_t>(size), flags, reinterpret_cast<SOCKADDR*>(socket_address.data()), &address_length));
  if (socket_address.size() != static_cast<size_t>(address_length)) socket_address.resize(static_cast<size_t>(address_length));
  return result;
}

int32_t socket::select(vector<intmax_t>& check_read, vector<intmax_t>& check_write, vector<intmax_t>& check_error, int32_t microseconds) {
  auto nfds = size_t {};
  
  auto read_fds = fd_set {};
  FD_ZERO(&read_fds);
  for (auto i = 0U; i < check_read.size() && i < FD_SETSIZE; i++)
    FD_SET(static_cast<SOCKET>(check_read[i]), &read_fds);
  if (check_read.size() > nfds) nfds = check_read.size();
  
  auto write_fds = fd_set {};
  FD_ZERO(&write_fds);
  for (auto i = 0U; i < check_write.size() && i < FD_SETSIZE; i++)
    FD_SET(static_cast<SOCKET>(check_write[i]), &write_fds);
  if (check_write.size() > nfds) nfds = check_write.size();
  
  auto error_fds = fd_set{};
  FD_ZERO(&error_fds);
  for (auto i = 0U; i < check_error.size() && i < FD_SETSIZE; i++)
    FD_SET(static_cast<SOCKET>(check_error[i]), &error_fds);
  if (check_error.size() > nfds) nfds = check_error.size();
  
  auto tv = timeval {};
  if (microseconds != -1) {
    tv.tv_sec = microseconds / 1000000;
    tv.tv_usec = microseconds % 1000000;
  }
  auto result = ::select(static_cast<int32_t>(nfds + 1), &read_fds, &write_fds, &error_fds, &tv);
  
  for (auto i = 0U; i < check_read.size(); i++) {
    FD_CLR(static_cast<SOCKET>(check_read[i]), &read_fds);
    if (FD_ISSET(static_cast<SOCKET>(check_read[i]), &read_fds) == 0) check_read[i] = 0;
  }
  
  for (auto i = 0U; i < check_write.size(); i++) {
    FD_CLR(static_cast<SOCKET>(check_write[i]), &write_fds);
    if (FD_ISSET(static_cast<SOCKET>(check_write[i]), &write_fds) == 0) check_write[i] = 0;
  }
  
  for (auto i = 0U; i < check_error.size(); i++) {
    FD_CLR(static_cast<SOCKET>(check_error[i]), &error_fds);
    if (FD_ISSET(static_cast<SOCKET>(check_error[i]), &error_fds) == 0) check_error[i] = 0;
  }
  
  return result;
}

int32_t socket::send(intmax_t handle, const vector<uint8_t>& buffer, size_t offset, size_t size, int32_t flags) {
  return static_cast<int32_t>(::send(static_cast<SOCKET>(handle), reinterpret_cast<const char*>(&buffer.data()[offset]), static_cast<int32_t>(size), flags));
}

int32_t socket::send_to(intmax_t handle, const vector<uint8_t>& buffer, size_t offset, size_t size, int32_t flags, const vector<uint8_t>& socket_address) {
  return static_cast<int32_t>(::sendto(static_cast<SOCKET>(handle), reinterpret_cast<const char*>(&buffer.data()[offset]), static_cast<int32_t>(size), flags, reinterpret_cast<const SOCKADDR*>(socket_address.data()), static_cast<int32_t>(socket_address.size())));
}

int32_t socket::set_blocking(intmax_t handle, bool blocking) {
  auto mode = u_long {blocking ? 0ul : 1ul};
  return ioctlsocket(static_cast<SOCKET>(handle), FIONBIO, &mode);
}

int32_t socket::set_raw_socket_option(intmax_t handle, int32_t socket_option_level, int32_t socket_option_name, intmax_t option, size_t option_length) {
  return setsockopt(static_cast<SOCKET>(handle), socket_option_level, socket_option_name, reinterpret_cast<const char*>(option), static_cast<int32_t>(option_length));
}

int32_t socket::set_socket_option(intmax_t handle, int32_t socket_option_level, int32_t socket_option_name, intmax_t option, size_t option_length) {
  return setsockopt(static_cast<SOCKET>(handle), socket_option_level_to_native(socket_option_level), socket_option_name_to_native(socket_option_name), reinterpret_cast<const char*>(option), static_cast<int32_t>(option_length));
}

int32_t socket::set_socket_linger_option(intmax_t handle, bool enabled, uint32_t linger_time) {
  LINGER l {static_cast<u_short>(enabled), static_cast<u_short>(linger_time)};
  return setsockopt(static_cast<SOCKET>(handle), SOL_SOCKET, SO_LINGER, reinterpret_cast<const char*>(&l), static_cast<int32_t>(sizeof(LINGER)));
}

int32_t socket::set_socket_multicast_option(intmax_t handle, int32_t socket_option_name, uint32_t multicast_address, uint32_t interface_index) {
  struct multicast {
    uint32_t multicast_address;
    uint32_t interface_index;
  } m {multicast_address, interface_index};
  return setsockopt(static_cast<SOCKET>(handle), IPPROTO_TCP, socket_option_name_to_native(socket_option_name), reinterpret_cast<const char*>(&m), static_cast<int32_t>(sizeof(multicast)));
}

int32_t socket::set_socket_ip_v6_multicast_option(intmax_t handle, int32_t socket_option_name, const vector<uint8_t>& multicast_address, uint64_t interface_index) {
  struct multicast {
    uint8_t multicast_address[16];
    uint64_t interface_index;
  } m;
  for (auto index = 0U; index < multicast_address.size(); ++index)
    m.multicast_address[index] = multicast_address[index];
  m.interface_index = interface_index;
  return setsockopt(static_cast<SOCKET>(handle), IPPROTO_TCP, socket_option_name_to_native(socket_option_name), reinterpret_cast<const char*>(&m), static_cast<int32_t>(sizeof(multicast)));
}

int32_t socket::shutdown(intmax_t handle, int32_t how) {
  return ::shutdown(static_cast<SOCKET>(handle), how);
}

void socket::startup() {
  static auto version_requested = MAKEWORD(2, 2);
  static auto wsa_data = WSADATA {};
  WSAStartup(version_requested, &wsa_data);
}
