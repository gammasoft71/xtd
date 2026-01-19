#include "../../../include/xtd/net/end_point.hpp"
#include "../../../include/xtd/not_implemented_exception.hpp"

using namespace xtd;
using namespace xtd::helpers;
using namespace xtd::net;
using namespace xtd::net::sockets;

auto end_point::address_family() const noexcept -> sockets::address_family {
  return address_family_;
}

auto end_point::create(const socket_address&) const -> uptr<end_point> {
  throw_helper::throws(exception_case::not_implemented);
}

auto end_point::serialize() const -> socket_address {
  throw_helper::throws(exception_case::not_implemented);
}

auto end_point::to_string() const noexcept -> string {
  return string::format("{}", address_family_);
}

