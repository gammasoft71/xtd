#include <xtd/net/dns>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/string_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::net;
using namespace xtd::tunit;

namespace xtd::net::tests {
  class test_class_(dns_tests) {
    auto test_method_(get_host_name) {
      string host_name;
      assert::does_not_throw([&] {host_name = dns::get_host_name();});
    }
    
    auto test_method_(get_host_addresses_from_local_host_addrress_strring) {
      array<ip_address> addresses = dns::get_host_addresses("127.0.0.1");
      collection_assert::are_equal({ip_address(127, 0, 0, 1)}, addresses);
    }
    
    auto test_method_(get_host_addresses_from_local_host_name) {
      array<ip_address> addresses = dns::get_host_addresses("localhost");
      collection_assert::contains({ip_address(127, 0, 0, 1)}, addresses);
    }
    
    auto test_method_(get_host_addresses_from_host_name) {
      array<ip_address> addresses = dns::get_host_addresses(dns::get_host_name());
      assert::is_greater_or_equal(addresses.length(), 1u);
    }
    
    auto test_method_(get_host_entry_from_local_host_address_string) {
      ip_host_entry host_entry = dns::get_host_entry("127.0.0.1");
      #if !_WIN32
      // On Windows the local host name is the computer host name!
      assert::are_equal("localhost", host_entry.host_name().to_lower());
      #endif
      collection_assert::are_equal({ip_address(127, 0, 0, 1)}, host_entry.address_list());
    }
    
    auto test_method_(get_host_entry_from_local_host_name) {
      ip_host_entry host_entry = dns::get_host_entry("localhost");
      #if !_WIN32
      // On Windows the local host name is the computer host name!
      assert::are_equal("localhost", host_entry.host_name().to_lower());
      #endif
      collection_assert::contains({ip_address(127, 0, 0, 1)}, host_entry.address_list());
    }
    
    auto test_method_(get_host_entry_from_host_name) {
      ip_host_entry host_entry = dns::get_host_entry(dns::get_host_name());
      string_assert::starts_with(dns::get_host_name().to_lower(), host_entry.host_name().to_lower());
      assert::is_greater_or_equal(host_entry.address_list().length(), 1u);
    }
    
    auto test_method_(get_host_entry_from_host_address) {
      #if !_WIN32 && !__APPLE__
      ip_host_entry host_entry = dns::get_host_entry(dns::get_host_entry(dns::get_host_name()).address_list()[0]);
      //string_assert::starts_with(dns::get_host_name().to_lower(), host_entry.host_name().to_lower());
      assert::is_greater_or_equal(host_entry.address_list().length(), 1u);
      #endif
    }
    
    auto test_method_(get_host_entry_from_host_address_string) {
      #if !_WIN32 && !__APPLE__
      ip_host_entry host_entry = dns::get_host_entry(dns::get_host_entry(dns::get_host_name()).address_list()[0].to_string());
      //string_assert::starts_with(dns::get_host_name().to_lower(), host_entry.host_name().to_lower());
      assert::is_greater_or_equal(host_entry.address_list().length(), 1u);
      #endif
    }
  };
}
