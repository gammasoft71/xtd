#include "../../../include/xtd/net/ip_host_entry.hpp"

using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

const xtd::array<xtd::net::ip_address>& ip_host_entry::address_list() const noexcept {
  return address_list_;
}

xtd::array<xtd::net::ip_address>& ip_host_entry::address_list() noexcept {
  return address_list_;
}

ip_host_entry& ip_host_entry::address_list(const xtd::array<xtd::net::ip_address>& address_list) noexcept {
  address_list_ = address_list;
  return *this;
}

const xtd::array<xtd::string>& ip_host_entry::aliases() const noexcept {
  return aliases_;
}

xtd::array<xtd::string>& ip_host_entry::aliases() noexcept {
  return aliases_;
}

ip_host_entry& ip_host_entry::aliases(const xtd::array<xtd::string>& aliases) noexcept {
  aliases_ = aliases;
  return *this;
}

const xtd::string& ip_host_entry::host_name() const noexcept {
  return host_name_;
}

ip_host_entry& ip_host_entry::host_name(const xtd::string& host_name) noexcept {
  host_name_ = host_name;
  return *this;
}

