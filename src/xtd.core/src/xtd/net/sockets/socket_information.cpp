#include "../../../../include/xtd/net/sockets/socket_information.hpp"

using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

xtd::net::sockets::socket_information_options socket_information::options() const noexcept {
  return options_;
}

socket_information& socket_information::options(xtd::net::sockets::socket_information_options value) noexcept {
  options_ = value;
  return *this;
}

const xtd::array<xtd::byte>& socket_information::protocol_information() const noexcept {
  return protocol_information_;
}

socket_information& socket_information::protocol_information(const xtd::array<xtd::byte>& value) noexcept {
  protocol_information_ = value;
  return *this;
}
