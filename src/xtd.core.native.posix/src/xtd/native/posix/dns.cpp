#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/dns>
#include <xtd/native/address_family_constants>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <mutex>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

using namespace std;
using namespace xtd::native;

namespace {
  auto dns_mutex = mutex {};
}

void dns::cleanup() {
  endhostent();
}

void dns::destroy(intmax_t host) {
  delete reinterpret_cast<hostent*>(host);
}

intmax_t dns::get_host_by_address(const string& host_address, int_least32_t host_address_type) {
  auto lock = lock_guard<mutex> {dns_mutex};
  auto internet_address = int_least64_t {0};
  inet_pton(host_address_type, host_address.c_str(), &internet_address);
  auto host = gethostbyaddr(reinterpret_cast<char*>(&internet_address), host_address_type == ADDRESS_FAMILY_INTER_NETWORK ? 4 : 16, host_address_type);
  if (host == nullptr) return 0;
  return reinterpret_cast<intmax_t>(new hostent(*host));
}

intmax_t dns::get_host_by_name(const string& host_name) {
  auto lock = lock_guard<mutex> {dns_mutex};
  auto host = gethostbyname(host_name.c_str());
  if (host == nullptr) return 0;
  return reinterpret_cast<intmax_t>(new hostent(*host));
}

vector<string> dns::get_aliases(intmax_t host) {
  auto aliases = vector<string> {};
  auto index = size_t {0};
  while (reinterpret_cast<hostent*>(host)->h_aliases[index] != nullptr)
    aliases.push_back(reinterpret_cast<hostent*>(host)->h_aliases[index++]);
  return aliases;
}

vector<vector<uint_least8_t>> dns::get_addresses(intmax_t host) {
  auto addresses = vector<vector<uint_least8_t>> {};
  auto index = size_t {0};
  while (reinterpret_cast<hostent*>(host)->h_addr_list[index] != nullptr) {
    addresses.emplace_back(reinterpret_cast<const uint_least8_t*>(reinterpret_cast<hostent*>(host)->h_addr_list[index]), reinterpret_cast<const uint_least8_t*>(reinterpret_cast<hostent*>(host)->h_addr_list[index]) + (reinterpret_cast<hostent*>(host)->h_addrtype == ADDRESS_FAMILY_INTER_NETWORK ? 4 : 16));
    index++;
  }
  return addresses;
}

string dns::get_host_name(intmax_t host) {
  return reinterpret_cast<hostent*>(host)->h_name;
}

int_least32_t dns::get_host_name(string& host_name) {
  auto name_length = static_cast<size_t>(sysconf(_SC_HOST_NAME_MAX));
  auto name = string(name_length, '\0');
  auto result = gethostname(name.data(), name_length);
  host_name = name.data();
  return result;
}

void dns::startup() {
  sethostent(true);
}
