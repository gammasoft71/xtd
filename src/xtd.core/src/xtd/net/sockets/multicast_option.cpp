#include "../../../../include/xtd/net/sockets/multicast_option.h"
#include "../../../../include/xtd/argument_out_of_range_exception.h"

using namespace std;
using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

multicast_option::multicast_option(const xtd::net::ip_address& group, const xtd::net::ip_address& local_address) : group_(group), local_adress_(local_address) {
}

multicast_option::multicast_option(const xtd::net::ip_address& group) : group_(group), local_adress_(ip_address::any) {
}

multicast_option::multicast_option(const xtd::net::ip_address& group, uint32_t interface_index) : group_(group), interface_index_(interface_index) {
  if (interface_index > 0x00FFFFFF) throw argument_out_of_range_exception(csf_);
}

const xtd::net::ip_address& multicast_option::group() const noexcept {
  return group_;
}

multicast_option& multicast_option::group(const xtd::net::ip_address& value) noexcept {
  group_ = value;
  return *this;
}

uint32_t multicast_option::interface_index() const noexcept {
  return interface_index_;
}

multicast_option& multicast_option::interface_index(uint32_t value) {
  if (value > 0x00FFFFFF) throw argument_out_of_range_exception(csf_);
  interface_index_ = value;
  local_adress_ = ip_address::none;
  return *this;
}

const xtd::net::ip_address& multicast_option::local_adress() const noexcept {
  return local_adress_;
}

multicast_option& multicast_option::local_adress(const xtd::net::ip_address& value) noexcept {
  interface_index_ = 0;
  local_adress_ = value;
  return *this;
}
