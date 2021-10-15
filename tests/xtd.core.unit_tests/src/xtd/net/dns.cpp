#include <xtd/net/dns.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd;
using namespace xtd::net;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_dns) {
  public:
    void test_method_(get_host_name) {
      ustring host_name;
      assert::does_not_throw([&]{host_name = dns::get_host_name();}, csf_);
    }
    
    void test_method_(get_host_addresses_from_local_host_addrress_strring) {
      vector<ip_address> addresses = dns::get_host_addresses("127.0.0.1");
      collection_assert::are_equal({ip_address(127, 0, 0, 1)}, addresses, csf_);
    }
    
    void test_method_(get_host_addresses_from_local_host_name) {
      vector<ip_address> addresses = dns::get_host_addresses("localhost");
      collection_assert::contains({ip_address(127, 0, 0, 1)}, addresses, csf_);
    }

    void test_method_(get_host_addresses_from_host_name) {
      vector<ip_address> addresses = dns::get_host_addresses(dns::get_host_name());
      assert::is_greater_or_equal(addresses.size(), 1U, csf_);
    }
    
    void test_method_(get_host_entry_from_local_host_address_string) {
      ip_host_entry host_entry = dns::get_host_entry("127.0.0.1");
#if !_WIN32
      // On Windows the local host name is the computer host name!
      assert::are_equal("localhost", host_entry.host_name().to_lower(), csf_);
#endif
      collection_assert::are_equal({ip_address(127, 0, 0, 1)}, host_entry.address_list(), csf_);
    }

    void test_method_(get_host_entry_from_local_host_name) {
      ip_host_entry host_entry = dns::get_host_entry("localhost");
#if !_WIN32
      // On Windows the local host name is the computer host name!
      assert::are_equal("localhost", host_entry.host_name().to_lower(), csf_);
#endif
      collection_assert::contains({ip_address(127, 0, 0, 1)}, host_entry.address_list(), csf_);
   }
    
    void test_method_(get_host_entry_from_host_name) {
      ip_host_entry host_entry = dns::get_host_entry(dns::get_host_name());
      string_assert::starts_with(dns::get_host_name().to_lower(), host_entry.host_name().to_lower(), csf_);
      assert::is_greater_or_equal(host_entry.address_list().size(), 1U, csf_);
    }
    
    void test_method_(get_host_entry_from_host_address) {
      ip_host_entry host_entry = dns::get_host_entry(dns::get_host_entry(dns::get_host_name()).address_list()[0]);
#if !_WIN32
      string_assert::starts_with(dns::get_host_name().to_lower(), host_entry.host_name().to_lower(), csf_);
#endif
      assert::is_greater_or_equal(host_entry.address_list().size(), 1U, csf_);
    }
    
    void test_method_(get_host_entry_from_host_address_string) {
      ip_host_entry host_entry = dns::get_host_entry(dns::get_host_entry(dns::get_host_name()).address_list()[0].to_string());
#if !_WIN32
      string_assert::starts_with(dns::get_host_name().to_lower(), host_entry.host_name().to_lower(), csf_);
#endif
      assert::is_greater_or_equal(host_entry.address_list().size(), 1U, csf_);
    }
  };
}
