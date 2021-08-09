#include "../../../include/xtd/argument_out_of_range_exception.h"
#include "../../../include/xtd/bit_converter.h"
#include "../../../include/xtd/format_exception.h"
#include "../../../include/xtd/using.h"
#include "../../../include/xtd/net/ip_address.h"
#include "../../../include/xtd/net/sockets/socket_error.h"
#include "../../../include/xtd/net/sockets/socket_exception.h"

using namespace std;
using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

ip_address ip_address::any {0x0000000000000000LL};
ip_address ip_address::broadcast {0x00000000FFFFFFFFLL};
ip_address ip_address::ip_v6_any {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
ip_address ip_address::ip_v6_loopback {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}};
ip_address ip_address::ip_v6_none {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
ip_address ip_address::loopback {0x000000000100007FLL};
ip_address ip_address::none {0x00000000FFFFFFFFLL};

ip_address::ip_address(int64_t address) {
  if (address < 0 || address > 0x0000000FFFFFFFFLL) throw argument_out_of_range_exception(csf_);
  address_ = static_cast<int32_t>(address);
}

ip_address::ip_address(const vector<byte_t>& address) {
  if (address.size() != 4 && address.size() != 16) throw argument_exception(csf_);
  
  if (address.size() == 4) {
    address_family_ = sockets::address_family::inter_network;
    address_ = ((address[3] << 24 | address[2] <<16 | address[1] << 8| address[0]) & 0x0FFFFFFFF);
  }
  
  if (address.size() == 16) {
    address_family_ = sockets::address_family::inter_network_v6;
    for (auto index = 0U; index < number_of_numbers_; index++)
      numbers_[index] = (static_cast<int16_t>(address[index * 2]) << 8) + static_cast<int16_t>(address[(index * 2) + 1]);
  }
}

ip_address::ip_address(const vector<byte_t>& address, int64 scope_id) : address_family_(sockets::address_family::inter_network_v6) {
  if (address.size() != 16) throw argument_exception(csf_);
  if (scope_id < 0 || scope_id > 0x00000000FFFFFFFFLL) throw argument_out_of_range_exception(csf_);
  
  scope_id_ = static_cast<int32_t>(scope_id);
   for (auto index = 0U; index < number_of_numbers_; index++)
    numbers_[index] = (static_cast<int16_t>(address[index * 2]) << 8) + static_cast<int16_t>(address[(index * 2) + 1]);
}

ip_address::ip_address(byte_t quad_part_address1, byte_t quad_part_address2, byte_t quad_part_address3, byte_t quad_part_address4) : address_((quad_part_address4 << 24 | quad_part_address3 <<16 | quad_part_address2 << 8| quad_part_address1) & 0x0FFFFFFFF) {
}

ip_address::ip_address(const std::vector<uint16_t>& numbers, int64_t scope_id) : numbers_(numbers), scope_id_(scope_id), address_family_(sockets::address_family::inter_network_v6) {
}

sockets::address_family ip_address::address_family() const noexcept {
  return address_family_;
}

bool ip_address::is_ip_v4_mapped_to_ip_v6() const noexcept {
  if (address_family_ != sockets::address_family::inter_network_v6) return false;
  for (auto index = 0U; index < 5U; index++)
    if (numbers_[index] != 0) return false;
  return numbers_[5] == 0xFFFF;
}

bool ip_address::is_ip_v6_link_local() const noexcept {
  if (address_family_ == sockets::address_family::inter_network) return false;
  auto num = static_cast<uint32_t>(numbers_[0]) & 0xFFF0;
  return 0xFE80 <= num && num <= 0xFEC0;
}

bool ip_address::is_ip_v6_multicast() const noexcept {
  return address_family_ != sockets::address_family::inter_network && (static_cast<int16_t>(numbers_[0]) & 0xFF00) == 0xFF00;
}

bool ip_address::is_ip_v6_site_local() const noexcept {
  if (address_family_ == sockets::address_family::inter_network) return false;
  auto num = static_cast<uint32_t>(static_cast<int16_t>(numbers_[0])) & 0xFFF0;
  return 0xFEC0 <= num && num <= 0xFF00;
}

bool ip_address::is_ip_v6_teredo() const noexcept {
  return address_family_ == sockets::address_family::inter_network_v6 && numbers_[0] == 0x2001 && numbers_[1] == 0;
}

uint64_t ip_address::scope_id() const {
  if (address_family_ == sockets::address_family::inter_network) throw socket_exception(socket_error::operation_not_supported, csf_);
  return scope_id_;
}

ip_address& ip_address::scope_id(uint64_t value) {
  if (address_family_ == sockets::address_family::inter_network) throw socket_exception(socket_error::operation_not_supported, csf_);
  if (value > 0xFFFFFFFF) throw argument_out_of_range_exception(csf_);
  
  scope_id_ = static_cast<uint32_t>(value);
  return *this;
}

bool ip_address::equals(const object& other) const noexcept {
  return dynamic_cast<const ip_address*>(&other) && equals(static_cast<const ip_address&>(other));
}
bool ip_address::equals(const ip_address& other) const noexcept {
  return address_ == other.address_ && numbers_ == other.numbers_ && scope_id_ == other.scope_id_ && address_family_ == other.address_family_;
}

vector<byte_t> ip_address::get_address_bytes() const {
  vector<byte_t> bytes;
  if (address_family_ == sockets::address_family::inter_network) {
    bytes.push_back(static_cast<byte_t>(address_));
    bytes.push_back(static_cast<byte_t>(address_ >> 8));
    bytes.push_back(static_cast<byte_t>(address_ >> 16));
    bytes.push_back(static_cast<byte_t>(address_ >> 24));
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

int16_t ip_address::host_to_network_order(int16_t host) {
  return int16(host_to_network_order(static_cast<uint16>(host)));
}

int32_t ip_address::host_to_network_order(int32_t host) {
  return int32(host_to_network_order(static_cast<uint32>(host)));
}

int64_t ip_address::host_to_network_order(int64_t host) {
  return int64(host_to_network_order(static_cast<uint64>(host)));
}

float ip_address::host_to_network_order(float host) {
  return bit_converter::int32_bits_to_single(host_to_network_order(bit_converter::single_to_int32_bits(host)));
}

uint16_t ip_address::host_to_network_order(uint16_t host) {
  if (bit_converter::is_little_endian == false) return host;
  return (host >> 8) | (host << 8);
}

uint32_t ip_address::host_to_network_order(uint32_t host) {
  if (bit_converter::is_little_endian == false) return host;
  return (host >> 24) | ((host << 8) & 0x00FF0000L) | ((host >> 8) & 0x0000FF00L) | (host << 24);
}

uint64_t ip_address::host_to_network_order(uint64_t host) {
  if (bit_converter::is_little_endian == false) return host;
  return (host >> 56) | ((host << 40) & 0x00FF000000000000LL) | ((host << 24) & 0x0000FF0000000000LL) | ((host << 8) & 0x000000FF00000000LL) | ((host >> 8) & 0x00000000FF000000LL) | ((host >> 24) & 0x0000000000FF0000LL) | ((host >> 40) & 0x000000000000FF00LL) | (host << 56);
}

bool ip_address::is_loopback(const ip_address& address) {
  if (address.address_family_ == sockets::address_family::inter_network) return static_cast<byte_t>(address.address_ & 0x00000000000000FF) == 0x7F;
  for (auto index = 0U; index < number_of_numbers_ - 2; index++)
    if (address.numbers_[index] != 0) return false;
  return address.numbers_[7] == 1U;
}

ip_address ip_address::map_to_ip_v4() const noexcept {
  if (address_family_ == sockets::address_family::inter_network) return *this;
  uint64_t address = address = (((static_cast<uint64_t>(numbers_[6]) & 0x0000FF00u) >> 8) | ((static_cast<uint64_t>(numbers_[6]) & 0x000000FFu) << 8)) | ((((static_cast<uint64_t>(numbers_[7]) & 0x0000FF00u) >> 8) | ((static_cast<uint64_t>(numbers_[7]) & 0x000000FFu) << 8)) << 16);
  return ip_address(address);
}

ip_address ip_address::map_to_ip_v6() const noexcept {
  if (address_family_ == sockets::address_family::inter_network_v6) return *this;
  vector<uint16_t> numbers(number_of_numbers_);
  numbers[5] = 0xFFFF;
  numbers[6] = static_cast<uint16_t>(((address_ & 0x0000FF00) >> 8) | ((address_ & 0x000000FF) << 8));
  numbers[7] = static_cast<uint16_t>(((address_ & 0xFF000000) >> 24) | ((address_ & 0x00FF0000) >> 8));
  return ip_address(numbers, 0);
}

double ip_address::network_to_host_order(double network) {
  return host_to_network_order(network);
}

int16_t ip_address::network_to_host_order(int16_t network) {
  return host_to_network_order(network);
}

int32_t ip_address::network_to_host_order(int32_t network) {
  return host_to_network_order(network);
}

int64_t ip_address::network_to_host_order(int64_t network) {
  return int64(network_to_host_order(uint64(network)));
}

float ip_address::network_to_host_order(float network) {
  return host_to_network_order(network);
}

uint16_t ip_address::network_to_host_order(uint16_t network) {
  return host_to_network_order(network);
}

uint32_t ip_address::network_to_host_order(uint32_t network) {
  return host_to_network_order(network);
}

uint64_t ip_address::network_to_host_order(uint64_t network) {
  return host_to_network_order(network);
}

ip_address ip_address::parse(const ustring& str) {
  using_(vector<ustring> address_parts = str.split({'.'})) {
    if (address_parts.size() == 4) {
      vector<byte_t> addresses(4);
      for (auto index = 0U; index < address_parts.size(); index++)
        addresses[index] = xtd::parse<byte_t>(address_parts[index]);
      return ip_address(addresses);
    }
  }
  
  ustring work_ip_string = ((str[0] == '[' && str[str.size() - 1] == ']') ? str.substring(1, str.size() - 2) : str);
  ip_address value;
  value.address_family_ = sockets::address_family::inter_network_v6;
  if (work_ip_string.index_of('%') != work_ip_string.npos) {
    value.scope_id_ = xtd::parse<uint32_t>(work_ip_string.substring(work_ip_string.index_of('%') + 1));
    work_ip_string = work_ip_string.remove(work_ip_string.index_of('%'));
  };
  
  using_(vector<ustring> address_parts = work_ip_string.split({':'})) {
    if (address_parts.size() == 8) {
      for (auto index = 0U; index < address_parts.size(); index++)
        value.numbers_[index] = xtd::parse<uint16_t>(address_parts[index].is_empty() ? "0" : address_parts[index], number_styles::hex_number);
      return value;
    }
  }
  
  throw xtd::format_exception(csf_);
}

ustring ip_address::to_string() const noexcept {
  if (address_family_ == sockets::address_family::inter_network) {
    auto bytes = get_address_bytes();
    vector<uint32_t> values (bytes.begin(), bytes.end());
    return ustring::join(".", values);
  }
  
  ustring str;
  for (auto number : numbers_)
    str += ustring::format("{:x}:", number);
  str = str.remove(str.size() - 1, 1);
  if (scope_id_ != 0) str += ustring::format("%{}", scope_id_);
  return str;
}

bool ip_address::try_parse(const ustring& str, ip_address& address) {
  try {
    address = parse(str);
  } catch (...) {
    return false;
  }
  
  return true;
}
