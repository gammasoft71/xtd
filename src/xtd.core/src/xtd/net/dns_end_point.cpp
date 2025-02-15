#include "../../../include/xtd/net/dns_end_point.hpp"
#include "../../../include/xtd/net/dns.hpp"
#include "../../../include/xtd/net/ip_host_entry.hpp"
#include "../../../include/xtd/argument_exception.hpp"
#include "../../../include/xtd/not_implemented_exception.hpp"

using namespace xtd;
using namespace xtd::helpers;
using namespace xtd::net;
using namespace xtd::net::sockets;

dns_end_point::dns_end_point(const xtd::string& host, uint16 port) : dns_end_point(host, port, sockets::address_family::unspecified) {
}

dns_end_point::dns_end_point(const xtd::string& host, uint16 port, sockets::address_family address_family) {
  if (string::is_empty(host)) throw_helper::throws(exception_case::argument);;
  if (address_family != sockets::address_family::unspecified && address_family != sockets::address_family::inter_network && address_family != sockets::address_family::inter_network_v6) throw_helper::throws(exception_case::argument);;
  
  host_ = host;
  port_ = port;
  address_family_ = address_family;
}

const xtd::string& dns_end_point::host() const noexcept {
  return host_;
}

uint16 dns_end_point::port() const noexcept {
  return port_;
}

bool dns_end_point::equals(const object& obj) const noexcept {
  return is<dns_end_point>(obj) && equals(static_cast<const dns_end_point&>(obj));
}

bool dns_end_point::equals(const dns_end_point& other) const noexcept {
  return address_family_ == other.address_family_ && host_ == other.host_ && port_ == other.port_;
}

size dns_end_point::get_hash_code() const noexcept {
  return hash_code::combine(address_family_, host_, port_);
}

xtd::string dns_end_point::to_string() const noexcept {
  return string::format("{}/{}:{:D}", address_family_, host_, port_);
}
