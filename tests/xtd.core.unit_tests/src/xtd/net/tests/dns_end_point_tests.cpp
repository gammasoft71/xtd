#include <xtd/net/dns_end_point>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;
using namespace xtd::tunit;

namespace xtd::net::tests {
  class test_class_(dns_end_point_tests) {
  public:
    void test_method_(constructor_with_host_and_port) {
      dns_end_point end_point("localhost", 9500);
      assert::are_equal("localhost", end_point.host(), csf_);
      assert::are_equal(9500U, end_point.port(), csf_);
      assert::are_equal(address_family::unspecified, end_point.address_family(), csf_);
      assert::are_equal("unspecified/localhost:9500", end_point.to_string(), csf_);
    }
    
    void test_method_(constructor_with_host_port_and_adress_family_to_inter_network) {
      dns_end_point end_point("localhost", 9500, address_family::inter_network);
      assert::are_equal("localhost", end_point.host(), csf_);
      assert::are_equal(9500U, end_point.port(), csf_);
      assert::are_equal(address_family::inter_network, end_point.address_family(), csf_);
      assert::are_equal("inter_network/localhost:9500", end_point.to_string(), csf_);
    }
    
    void test_method_(constructor_with_host_port_and_adress_family_to_inter_network_v6) {
      dns_end_point end_point("localhost", 9500, address_family::inter_network_v6);
      assert::are_equal("localhost", end_point.host(), csf_);
      assert::are_equal(9500U, end_point.port(), csf_);
      assert::are_equal(address_family::inter_network_v6, end_point.address_family(), csf_);
      assert::are_equal("inter_network_v6/localhost:9500", end_point.to_string(), csf_);
    }
    
    void test_method_(constructor_with_host_empty) {
      assert::throws<argument_exception>([] {dns_end_point end_point("", 9500, address_family::inter_network);}, csf_);
    }
    
    void test_method_(constructor_with_address_family_invalid) {
      assert::throws<argument_exception>([] {dns_end_point end_point("localhost", 9500, address_family::apple_talk);}, csf_);
    }
  };
}
