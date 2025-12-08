#include <xtd/net/sockets/multicast_option>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;
using namespace xtd::tunit;

namespace xtd::net::sockets::tests {
  class test_class_(multicast_option_tests) {
    auto test_method_(default_constructor) {
      multicast_option mo;
      assert::are_equal(ip_address::none, mo.group());
      assert::is_zero(mo.interface_index());
      assert::are_equal(ip_address::none, mo.local_address());
    }
    
    auto test_method_(constructor_with_group_and_local_address) {
      multicast_option mo(ip_address(172, 16, 12, 24), ip_address(172, 16, 12, 1));
      assert::are_equal("172.16.12.24", mo.group().to_string());
      assert::is_zero(mo.interface_index());
      assert::are_equal("172.16.12.1", mo.local_address().to_string());
    }
    
    auto test_method_(constructor_with_group) {
      multicast_option mo(ip_address(172, 16, 12, 24));
      assert::are_equal("172.16.12.24", mo.group().to_string());
      assert::is_zero(mo.interface_index());
      assert::are_equal(ip_address::any, mo.local_address());
    }
    
    auto test_method_(constructor_with_group_and_interface_index) {
      multicast_option mo(ip_address(172, 16, 12, 24), 427);
      assert::are_equal("172.16.12.24", mo.group().to_string());
      assert::are_equal(427u, mo.interface_index());
      assert::are_equal(ip_address::none, mo.local_address());
    }
    
    auto test_method_(set_group) {
      multicast_option mo;
      mo.group(ip_address(172, 16, 12, 24));
      assert::are_equal("172.16.12.24", mo.group().to_string());
      assert::is_zero(mo.interface_index());
      assert::are_equal(ip_address::none, mo.local_address());
    }
    
    auto test_method_(set_interface_index) {
      multicast_option mo;
      mo.interface_index(427);
      assert::are_equal(ip_address::none, mo.group());
      assert::are_equal(427u, mo.interface_index());
      assert::are_equal(ip_address::none, mo.local_address());
    }
    
    auto test_method_(set_local_address) {
      multicast_option mo;
      mo.local_address(ip_address(172, 16, 12, 1));
      assert::are_equal(ip_address::none, mo.group());
      assert::is_zero(mo.interface_index());
      assert::are_equal("172.16.12.1", mo.local_address().to_string());
    }
  };
}
