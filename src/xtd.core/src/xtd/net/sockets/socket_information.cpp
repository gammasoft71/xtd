#include "../../../../include/xtd/net/sockets/socket_information.h"

using namespace std;
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

const std::vector<byte_t>& socket_information::protocol_information() const noexcept {
  return protocol_information_;
}

socket_information& socket_information::protocol_information(const std::vector<byte_t>& value) noexcept {
  protocol_information_ = value;
  return *this;
}
