#include "../../../include/xtd/net/ip_host_entry.hpp"

using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

auto ip_host_entry::address_list() const noexcept -> const array<ip_address>& {
  return address_list_;
}

auto ip_host_entry::address_list() noexcept -> array<ip_address>& {
  return address_list_;
}

auto ip_host_entry::address_list(const array<ip_address>& address_list) noexcept -> ip_host_entry& {
  address_list_ = address_list;
  return self_;
}

auto ip_host_entry::aliases() const noexcept -> const array<string>& {
  return aliases_;
}

auto ip_host_entry::aliases() noexcept -> array<string>& {
  return aliases_;
}

auto ip_host_entry::aliases(const array<string>& aliases) noexcept -> ip_host_entry& {
  aliases_ = aliases;
  return self_;
}

auto ip_host_entry::host_name() const noexcept -> const string& {
  return host_name_;
}

auto ip_host_entry::host_name(const string& host_name) noexcept -> ip_host_entry& {
  host_name_ = host_name;
  return self_;
}

