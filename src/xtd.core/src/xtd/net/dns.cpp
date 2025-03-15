#include "../../../include/xtd/net/dns.hpp"
#include "../../../include/xtd/invalid_operation_exception.hpp"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/dns>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::helpers;
using namespace xtd::net;
using namespace xtd::net::sockets;


class __using_dns__ {
public:
  __using_dns__() {native::dns::startup();}
  ~__using_dns__() {native::dns::cleanup();}
};

array<ip_address> dns::get_host_addresses(const string& host_name_or_address) {
  ip_host_entry host_entry = get_host_entry(host_name_or_address);
  return host_entry.address_list();
}

ip_host_entry dns::get_host_entry(const ip_address& address) {
  return get_host_entry(address.to_string());
}

ip_host_entry dns::get_host_entry(const string& host_name_or_address) {
  __using_dns__ hostent;
  ip_address host_address;
  intptr host;
  if (ip_address::try_parse(host_name_or_address, host_address) == false) {
    host = native::dns::get_host_by_name(host_name_or_address);
    if (host == 0) throw_helper::throws(exception_case::invalid_operation);
  } else {
    host = native::dns::get_host_by_address(host_address.to_string(), static_cast<int32>(host_address.address_family()));
    if (host == 0) throw_helper::throws(exception_case::invalid_operation);
  }
  
  ip_host_entry host_entry;
  host_entry.host_name(native::dns::get_host_name(host));
  
  auto addresses = native::dns::get_addresses(host);
  host_entry.address_list(array<ip_address> {addresses.size()});
  for (auto index= 0_z; index < addresses.size(); ++index)
    host_entry.address_list()[index] = ip_address(addresses[index]);

  auto aliases = native::dns::get_aliases(host);
  host_entry.aliases(array<string> {aliases.size()});
  for (auto index= 0_z; index < aliases.size(); ++index)
    host_entry.aliases()[index] = aliases[index];
    
  native::dns::destroy(host);
  return host_entry;
}

string dns::get_host_name() {
  __using_dns__ hotent;
  std::string host_name;
  if (native::dns::get_host_name(host_name) != 0) throw_helper::throws(exception_case::invalid_operation);
  return host_name;
}
