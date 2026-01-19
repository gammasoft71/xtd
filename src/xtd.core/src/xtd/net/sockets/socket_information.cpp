#include "../../../../include/xtd/net/sockets/socket_information.hpp"

using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

auto socket_information::options() const noexcept -> socket_information_options {
  return options_;
}

auto socket_information::options(socket_information_options value) noexcept -> socket_information& {
  options_ = value;
  return *this;
}

auto socket_information::protocol_information() const noexcept -> const array<xtd::byte>& {
  return protocol_information_;
}

auto socket_information::protocol_information(const array<xtd::byte>& value) noexcept -> socket_information& {
  protocol_information_ = value;
  return *this;
}
