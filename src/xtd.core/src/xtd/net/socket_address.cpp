#include "../../../include/xtd/net/ip_address"
#include "../../../include/xtd/net/socket_address"
#include "../../../include/xtd/argument_out_of_range_exception"
#include "../../../include/xtd/as"
#include "../../../include/xtd/index_out_of_range_exception"
#include "../../../include/xtd/bit_converter"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/socket>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

socket_address::socket_address(sockets::address_family address_family) : socket_address(address_family, 32) {
}

socket_address::socket_address(sockets::address_family address_family, size_t buffer_size) : bytes_(buffer_size) {
  if (buffer_size < 2) throw argument_out_of_range_exception {csf_};
  bytes_[0] = static_cast<xtd::byte>(native::socket::address_family_to_native(as<int32>(address_family))); // do not use as because sockets::address_family::unknown is -1 and as<byte> throw an exception overflow_exception.
  bytes_[1] = 0;
}

socket_address::socket_address(const vector<xtd::byte>& buffer) : bytes_(buffer) {
}

sockets::address_family socket_address::address_family() const {
  return static_cast<sockets::address_family>(native::socket::native_to_address_family(bytes_[0]));
}

size_t socket_address::size() const {
  return bytes_.size();
}

xtd::byte& socket_address::operator [](size_t index) {
  if (index >= bytes_.size()) throw index_out_of_range_exception {csf_};
  return bytes_[index];
}

const xtd::byte& socket_address::operator [](size_t index) const {
  if (index >= bytes_.size()) throw index_out_of_range_exception {csf_};
  return bytes_[index];
}

ustring socket_address::to_string() const noexcept {
  return ustring::format("{}:{}:{{{}}}", address_family(), size(), size() <= 2 ? "" : ustring::join(",", bytes_, 2, size() - 2));
}

