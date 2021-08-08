#include "../../../include/xtd/argument_out_of_range_exception.h"
#include "../../../include/xtd/net/ip_address.h"
#include "../../../include/xtd/net/sockets/socket_exception.h"

using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

sockets::address_family ip_address::address_family() const {
  return family_;
}

int64 ip_address::scope_id() const {
  if (family_ == sockets::address_family::inter_network) throw socket_exception(csf_);
  return scope_id_;
}

ip_address& ip_address::scope_id(int64_t value) {
  if (family_ == sockets::address_family::inter_network) throw socket_exception(csf_);
  if (value < 0 || value > 0xFFFFFFFF) throw argument_out_of_range_exception(csf_);
  
  scope_id_ = static_cast<int32_t>(value);
  return *this;
}
