#include "../../../include/xtd/net/ip_address.h"
#include "../../../include/xtd/net/socket_address.h"
#include "../../../include/xtd/argument_out_of_range_exception.h"
#include "../../../include/xtd/index_out_of_range_exception.h"
#include "../../../include/xtd/bit_converter.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/socket.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

socket_address::socket_address(sockets::address_family address_family) : socket_address(address_family, 32) {
}

socket_address::socket_address(sockets::address_family address_family, size_t buffer_size) : bytes_(buffer_size) {
  if (buffer_size < 2) throw argument_out_of_range_exception(csf_);
  bytes_[0] = static_cast<byte_t>(native::socket::address_family_to_native(static_cast<int32_t>(address_family)));
  bytes_[1] =0;
}

socket_address::socket_address(const vector<byte_t>& buffer) : bytes_(buffer) {
}

sockets::address_family socket_address::address_family() const {
  return static_cast<sockets::address_family>(native::socket::native_to_address_family(bytes_[0]));
}

size_t socket_address::size() const {
  return bytes_.size();
}

byte_t& socket_address::operator[](size_t index) {
  if (index >= bytes_.size()) throw index_out_of_range_exception(csf_);
  return bytes_[index];
}

const byte_t& socket_address::operator[](size_t index) const {
  if (index >= bytes_.size()) throw index_out_of_range_exception(csf_);
  return bytes_[index];
}

ustring socket_address::to_string() const noexcept {
  return ustring::format("{}:{}:{{{}}}", address_family(), size(), size() <= 2 ? "" : ustring::join(",", bytes_, 2, size() - 2));
}

