#include "../../../include/xtd/net/dns.h"
#include "../../../include/xtd/invalid_operation_exception.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/dns.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;


class __xtd__hostent__ {
public:
  __xtd__hostent__() {native::dns::set_hostent(true);}
  ~__xtd__hostent__() {native::dns::end_hostent();}
};

vector<ip_address> dns::get_host_addresses(const ustring& host_name_or_address) {
  ip_host_entry host_entry = get_host_entry(host_name_or_address);
  return host_entry.address_list();
}

ip_host_entry dns::get_host_entry(const ip_address& address) {
  return get_host_entry(address.to_string());
}

ip_host_entry dns::get_host_entry(const ustring& host_name_or_address) {
  __xtd__hostent__ hostent;
  ip_address address;
  intptr host;
  if (ip_address::try_parse(host_name_or_address, address) == false) {
    host = native::dns::get_host_by_name(host_name_or_address);
    if (host == 0) throw invalid_operation_exception(csf_);
  } else {
    host = native::dns::get_host_by_address(address.to_string(), static_cast<int32_t>(address.address_family()));
    if (host == 0) throw invalid_operation_exception(csf_);
  }
  
  ip_host_entry host_entry;
  host_entry.host_name(native::dns::get_host_name(host));
  for (auto address : native::dns::get_addresses(host))
    host_entry.address_list().push_back(ip_address(address));
  
  for (auto alias : native::dns::get_aliases(host))
    host_entry.aliases().push_back(alias);
  
  native::dns::destroy(host);
  return host_entry;
}

ustring dns::get_host_name() {
  __xtd__hostent__ hotent;
  string host_name;
  if (native::dns::get_host_name(host_name) != 0) throw invalid_operation_exception(csf_);
  return host_name;
}
