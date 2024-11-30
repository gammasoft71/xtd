#include "../../../include/xtd/argument_out_of_range_exception.hpp"
#include "../../../include/xtd/bit_converter.hpp"
#include "../../../include/xtd/format_exception.hpp"
#include "../../../include/xtd/block_scope.hpp"
#include "../../../include/xtd/net/ip_address.hpp"
#include "../../../include/xtd/net/sockets/socket_error.hpp"
#include "../../../include/xtd/net/sockets/socket_exception.hpp"

using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

const ip_address ip_address::any {0x00000000LL};
const ip_address ip_address::broadcast {0xFFFFFFFFLL};
const ip_address ip_address::ip_v6_any {std::vector<xtd::byte> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
const ip_address ip_address::ip_v6_loopback {std::vector<xtd::byte> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}};
const ip_address ip_address::ip_v6_none {std::vector<xtd::byte> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
const ip_address ip_address::loopback {0x0100007FLL};
const ip_address ip_address::none {0xFFFFFFFFLL};

ip_address::ip_address(uint32 address) {
  address_ = static_cast<int32>(address);
}

ip_address::ip_address(const std::vector<xtd::byte>& address) {
  if (address.size() != 4 && address.size() != 16) throw argument_exception {};
  
  if (address.size() == 4) {
    address_family_ = sockets::address_family::inter_network;
    address_ = ((address[3] << 24 | address[2] << 16 | address[1] << 8 | address[0]) & 0x0FFFFFFFF);
  }
  
  if (address.size() == 16) {
    address_family_ = sockets::address_family::inter_network_v6;
    for (auto index = 0_z; index < number_of_numbers_; index++)
      numbers_[index] = (static_cast<int16>(address[index * 2]) << 8) + static_cast<int16>(address[(index * 2) + 1]);
  }
}

ip_address::ip_address(const std::vector<xtd::byte>& address, uint32 scope_id) : address_family_(sockets::address_family::inter_network_v6) {
  if (address.size() != 16) throw argument_exception {};
  
  scope_id_ = scope_id;
  for (auto index = 0_z; index < number_of_numbers_; index++)
    numbers_[index] = (static_cast<int16>(address[index * 2]) << 8) + static_cast<int16>(address[(index * 2) + 1]);
}

ip_address::ip_address(xtd::byte quad_part_address1, xtd::byte quad_part_address2, xtd::byte quad_part_address3, xtd::byte quad_part_address4) : address_((quad_part_address4 << 24 | quad_part_address3 << 16 | quad_part_address2 << 8 | quad_part_address1) & 0x0FFFFFFFF) {
}

ip_address::ip_address(const std::vector<uint16>& numbers, uint32 scope_id) : numbers_(numbers), scope_id_(scope_id), address_family_(sockets::address_family::inter_network_v6) {
}

sockets::address_family ip_address::address_family() const noexcept {
  return address_family_;
}

bool ip_address::is_ip_v4_mapped_to_ip_v6() const noexcept {
  if (address_family_ != sockets::address_family::inter_network_v6) return false;
  for (auto index = 0_z; index < 5u; index++)
    if (numbers_[index] != 0) return false;
  return numbers_[5] == 0xFFFF;
}

bool ip_address::is_ip_v6_link_local() const noexcept {
  if (address_family_ == sockets::address_family::inter_network) return false;
  auto num = static_cast<uint32>(numbers_[0]) & 0xFFF0;
  return 0xFE80 <= num && num <= 0xFEC0;
}

bool ip_address::is_ip_v6_multicast() const noexcept {
  return address_family_ != sockets::address_family::inter_network && (static_cast<int16>(numbers_[0]) & 0xFF00) == 0xFF00;
}

bool ip_address::is_ip_v6_site_local() const noexcept {
  if (address_family_ == sockets::address_family::inter_network) return false;
  auto num = static_cast<uint32>(static_cast<int16>(numbers_[0])) & 0xFFF0;
  return 0xFEC0 <= num && num <= 0xFF00;
}

bool ip_address::is_ip_v6_teredo() const noexcept {
  return address_family_ == sockets::address_family::inter_network_v6 && numbers_[0] == 0x2001 && numbers_[1] == 0;
}

uint32 ip_address::scope_id() const {
  if (address_family_ == sockets::address_family::inter_network) throw socket_exception(socket_error::operation_not_supported);
  return scope_id_;
}

ip_address& ip_address::scope_id(uint32 value) {
  if (address_family_ == sockets::address_family::inter_network) throw socket_exception(socket_error::operation_not_supported);
  
  scope_id_ = static_cast<uint32>(value);
  return *this;
}

bool ip_address::equals(const ip_address& other) const noexcept {
  return address_ == other.address_ && numbers_ == other.numbers_ && scope_id_ == other.scope_id_ && address_family_ == other.address_family_;
}

std::vector<xtd::byte> ip_address::get_address_bytes() const {
  std::vector<xtd::byte> bytes;
  if (address_family_ == sockets::address_family::inter_network) {
    bytes.push_back(static_cast<xtd::byte>(address_));
    bytes.push_back(static_cast<xtd::byte>(address_ >> 8));
    bytes.push_back(static_cast<xtd::byte>(address_ >> 16));
    bytes.push_back(static_cast<xtd::byte>(address_ >> 24));
    return bytes;
  }
  
  for (auto number : numbers_) {
    bytes.push_back((number >> 8) & 0xFF);
    bytes.push_back(number & 0xFF);
  }
  return bytes;
}

double ip_address::host_to_network_order(double host) {
  return bit_converter::int64_bits_to_double(host_to_network_order(bit_converter::double_to_int64_bits(host)));
}

int16 ip_address::host_to_network_order(int16 host) {
  return int16(host_to_network_order(static_cast<uint16>(host)));
}

int32 ip_address::host_to_network_order(int32 host) {
  return int32(host_to_network_order(static_cast<uint32>(host)));
}

int64 ip_address::host_to_network_order(int64 host) {
  return int64(host_to_network_order(static_cast<uint64>(host)));
}

float ip_address::host_to_network_order(float host) {
  return bit_converter::int32_bits_to_single(host_to_network_order(bit_converter::single_to_int32_bits(host)));
}

uint16 ip_address::host_to_network_order(uint16 host) {
  if (bit_converter::is_little_endian == false) return host;
  return (host >> 8) | (host << 8);
}

uint32 ip_address::host_to_network_order(uint32 host) {
  if (bit_converter::is_little_endian == false) return host;
  return (host >> 24) | ((host << 8) & 0x00FF0000L) | ((host >> 8) & 0x0000FF00L) | (host << 24);
}

uint64 ip_address::host_to_network_order(uint64 host) {
  if (bit_converter::is_little_endian == false) return host;
  return (host >> 56) | ((host << 40) & 0x00FF000000000000LL) | ((host << 24) & 0x0000FF0000000000LL) | ((host << 8) & 0x000000FF00000000LL) | ((host >> 8) & 0x00000000FF000000LL) | ((host >> 24) & 0x0000000000FF0000LL) | ((host >> 40) & 0x000000000000FF00LL) | (host << 56);
}

bool ip_address::is_loopback(const ip_address& address) {
  if (address.address_family_ == sockets::address_family::inter_network) return static_cast<xtd::byte>(address.address_ & 0x00000000000000FF) == 0x7F;
  for (auto index = 0_z; index < number_of_numbers_ - 2; index++)
    if (address.numbers_[index] != 0) return false;
  return address.numbers_[7] == 1u;
}

ip_address ip_address::map_to_ip_v4() const noexcept {
  if (address_family_ == sockets::address_family::inter_network) return *this;
  uint32 address = (((static_cast<uint32>(numbers_[6]) & 0x0000FF00u) >> 8) | ((static_cast<uint32>(numbers_[6]) & 0x000000FFu) << 8)) | ((((static_cast<uint32>(numbers_[7]) & 0x0000FF00u) >> 8) | ((static_cast<uint32>(numbers_[7]) & 0x000000FFu) << 8)) << 16);
  return ip_address(address);
}

ip_address ip_address::map_to_ip_v6() const noexcept {
  if (address_family_ == sockets::address_family::inter_network_v6) return *this;
  std::vector<uint16> numbers(number_of_numbers_);
  numbers[5] = 0xFFFF;
  numbers[6] = static_cast<uint16>(((address_ & 0x0000FF00) >> 8) | ((address_ & 0x000000FF) << 8));
  numbers[7] = static_cast<uint16>(((address_ & 0xFF000000) >> 24) | ((address_ & 0x00FF0000) >> 8));
  return ip_address(numbers, 0);
}

double ip_address::network_to_host_order(double network) {
  return host_to_network_order(network);
}

int16 ip_address::network_to_host_order(int16 network) {
  return host_to_network_order(network);
}

int32 ip_address::network_to_host_order(int32 network) {
  return host_to_network_order(network);
}

int64 ip_address::network_to_host_order(int64 network) {
  return int64(network_to_host_order(uint64(network)));
}

float ip_address::network_to_host_order(float network) {
  return host_to_network_order(network);
}

uint16 ip_address::network_to_host_order(uint16 network) {
  return host_to_network_order(network);
}

uint32 ip_address::network_to_host_order(uint32 network) {
  return host_to_network_order(network);
}

uint64 ip_address::network_to_host_order(uint64 network) {
  return host_to_network_order(network);
}

ip_address ip_address::parse(const string& str) {
  block_scope_(std::vector<string> address_parts = str.split('.')) {
    if (address_parts.size() == 4) {
      std::vector<xtd::byte> addresses(4);
      for (auto index = 0_z; index < address_parts.size(); index++)
        addresses[index] = xtd::parse<xtd::byte>(address_parts[index]);
      return ip_address(addresses);
    }
  }
  
  string work_ip_string = ((str[0] == '[' && str[str.size() - 1] == ']') ? str.substring(1, str.size() - 2) : str);
  ip_address value;
  value.address_family_ = sockets::address_family::inter_network_v6;
  if (work_ip_string.index_of('%') != work_ip_string.npos) {
    value.scope_id_ = xtd::parse<uint32>(work_ip_string.substring(work_ip_string.index_of('%') + 1));
    work_ip_string = work_ip_string.remove(work_ip_string.index_of('%'));
  };
  
  block_scope_(std::vector<string> address_parts = work_ip_string.split(':')) {
    for (auto it = address_parts.begin(); it != address_parts.end(); ++it) {
      if (it->empty()) {
        *it = "0";
        auto fill_count = 8 - address_parts.size();
        for (size_t fc = 0; fc < fill_count; ++fc)
          it = address_parts.insert(it, "0");
      }
    }
    
    if (address_parts.size() == 8) {
      for (auto index = 0_z; index < address_parts.size(); index++)
        value.numbers_[index] = xtd::parse<uint16>(string::is_empty(address_parts[index]) ? "0" : address_parts[index], number_styles::hex_number);
      return value;
    }
  }
  
  throw xtd::format_exception {};
}

string ip_address::to_string() const noexcept {
  if (address_family_ == sockets::address_family::inter_network)
    return string::join(".", get_address_bytes());
    
  string str;
  for (size_t index = 0; index < 8; ++index) {
    if (index < 7 && numbers_[index] == 0 && numbers_[index + 1] == 0) {
      if (index == 0) str = ":";
      while (index < 7 && numbers_[index + 1] == 0) ++index;
      if (index < 8) str += ":";
    } else {
      str += string::format("{:x}", numbers_[index]);
      if (index < 7) str += ":";
    }
  }
  if (scope_id_ != 0) str += string::format("%{}", scope_id_);
  return str;
}

bool ip_address::try_parse(const string& str, ip_address& address) noexcept {
  try {
    address = parse(str);
  } catch (...) {
    return false;
  }
  
  return true;
}
