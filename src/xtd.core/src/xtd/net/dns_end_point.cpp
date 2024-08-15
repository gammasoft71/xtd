#include "../../../include/xtd/net/dns_end_point.h"
#include "../../../include/xtd/net/dns.h"
#include "../../../include/xtd/net/ip_host_entry.h"
#include "../../../include/xtd/argument_exception.h"
#include "../../../include/xtd/not_implemented_exception.h"

using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

dns_end_point::dns_end_point(const xtd::string& host, uint16 port) : dns_end_point(host, port, sockets::address_family::unspecified) {
}

dns_end_point::dns_end_point(const xtd::string& host, uint16 port, sockets::address_family address_family) {
  if (string::is_empty(host)) throw xtd::argument_exception {csf_};
  if (address_family != sockets::address_family::unspecified && address_family != sockets::address_family::inter_network && address_family != sockets::address_family::inter_network_v6) throw xtd::argument_exception {csf_};
  
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

xtd::string dns_end_point::to_string() const noexcept {
  return string::format("{}/{}:{:D}", address_family_, host_, port_);
}
