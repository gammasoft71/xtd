#include "../../../include/xtd/net/end_point.h"
#include "../../../include/xtd/not_implemented_exception.h"

using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

end_point::end_point(const end_point& end_point) : address_family_(end_point.address_family_) {
}

sockets::address_family end_point::address_family() const noexcept {
  return address_family_;
}

std::unique_ptr<end_point> end_point::create(const socket_address&) const {
  throw not_implemented_exception(csf_);
}

ustring end_point::to_string() const noexcept {
  return ustring::format("{}", address_family_);
}

socket_address end_point::serialize() const {
  return socket_address(address_family_, 2);
}

