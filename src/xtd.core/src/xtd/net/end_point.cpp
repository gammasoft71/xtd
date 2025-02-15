#include "../../../include/xtd/net/end_point.hpp"
#include "../../../include/xtd/not_implemented_exception.hpp"

using namespace xtd;
using namespace xtd::helpers;
using namespace xtd::net;
using namespace xtd::net::sockets;

sockets::address_family end_point::address_family() const noexcept {
  return address_family_;
}

xtd::uptr<end_point> end_point::create(const socket_address&) const {
  throw_helper::throws(exception_case::not_implemented);
}

socket_address end_point::serialize() const {
  throw_helper::throws(exception_case::not_implemented);
}

string end_point::to_string() const noexcept {
  return string::format("{}", address_family_);
}

