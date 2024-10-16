#include "../../../include/xtd/net/end_point.h"
#include "../../../include/xtd/not_implemented_exception.h"

using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

sockets::address_family end_point::address_family() const noexcept {
  return address_family_;
}

xtd::uptr<end_point> end_point::create(const socket_address&) const {
  throw not_implemented_exception {};
}

socket_address end_point::serialize() const {
  throw not_implemented_exception {};
}

string end_point::to_string() const noexcept {
  return string::format("{}", address_family_);
}

