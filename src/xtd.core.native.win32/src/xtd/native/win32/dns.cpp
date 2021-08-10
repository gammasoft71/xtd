#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/dns.h>
#include <xtd/native/address_families.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <mutex>
#include <winsock2.h>
#include <ws2tcpip.h>

using namespace std;
using namespace xtd::native;

namespace {
  mutex dns_mutex;
}

void dns::destroy(intptr_t host) {
  delete (hostent*)host;
}

void dns::end_hostent() {
  WSACleanup();
}

intptr_t dns::get_host_by_address(const string& host_address, int32_t host_address_type) {
  lock_guard<mutex> lock(dns_mutex);
  int64_t internet_address = 0;
  inet_pton(host_address_type, host_address.c_str(), &internet_address);
  hostent* host = gethostbyaddr(reinterpret_cast<char*>(&internet_address), host_address_type == ADDRESS_FAMILY_INTER_NETWORK ? 4 : 16, host_address_type);
  if (host == nullptr) return 0;
  return reinterpret_cast<intptr_t>(new hostent(*host));
}

intptr_t dns::get_host_by_name(const string& host_name) {
  lock_guard<mutex> lock(dns_mutex);
  hostent* host = gethostbyname(host_name.c_str());
  if (host == nullptr) return 0;
  return reinterpret_cast<intptr_t>(new hostent(*host));
}

vector<string> dns::get_aliases(intptr_t host) {
  vector<string> aliases;
  size_t index = 0;
  while (reinterpret_cast<hostent*>(host)->h_aliases[index] != nullptr)
    aliases.push_back(reinterpret_cast<hostent*>(host)->h_aliases[index++]);
  return aliases;
}

vector<vector<uint8_t>> dns::get_addresses(intptr_t host) {
  size_t index = 0;
  vector<vector<uint8_t>> addresses;
  while (reinterpret_cast<hostent*>(host)->h_addr_list[index] != nullptr) {
    addresses.push_back(vector<uint8_t>(reinterpret_cast<const uint8_t*>(reinterpret_cast<hostent*>(host)->h_addr_list[index]), reinterpret_cast<const uint8_t*>(reinterpret_cast<hostent*>(host)->h_addr_list[index]) + (reinterpret_cast<hostent*>(host)->h_addrtype == ADDRESS_FAMILY_INTER_NETWORK ? 4 : 16)));
    index++;
  }
  return addresses;
}

string dns::get_host_name(intptr_t host) {
  return reinterpret_cast<hostent*>(host)->h_name;
}

int32_t dns::get_host_name(string& host_name) {
  char name[1024];
  int32_t result = gethostname(name, 1024);
  host_name = name;
  return result;
}

void dns::set_hostent(bool stay_open) {
  static WORD version_requested = MAKEWORD(2, 2);
  static WSADATA wsa_data = {0};
  WSAStartup(version_requested, &wsa_data);
}
