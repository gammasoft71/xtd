#include <xtd/net/sockets/ip_v6_multicast_option>
#include <xtd/argument_out_of_range_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;
using namespace xtd::tunit;

namespace xtd::net::sockets::tests {
  class test_class_(ip_v6_multicast_option_tests) {
    auto test_method_(default_constructor) {
      ip_v6_multicast_option mo;
      assert::are_equal(ip_address::ip_v6_none, mo.group());
      assert::is_zero(mo.interface_index());
    }
    
    auto test_method_(constructor_with_group) {
      ip_v6_multicast_option mo(ip_address(array<xtd::byte> {0x20, 0x01, 0x00, 0x00, 0x5e, 0xf5, 0x73, 0xb8, 0x2c, 0x2c, 0x30, 0x28, 0x2a, 0x4e, 0xb2, 0x83}, 15));
      assert::are_equal("2001:0:5ef5:73b8:2c2c:3028:2a4e:b283%15", mo.group().to_string());
      assert::is_zero(mo.interface_index());
    }
    
    auto test_method_(constructor_with_group_and_interface_index) {
      ip_v6_multicast_option mo(ip_address(array<xtd::byte> {0x20, 0x01, 0x00, 0x00, 0x5e, 0xf5, 0x73, 0xb8, 0x2c, 0x2c, 0x30, 0x28, 0x2a, 0x4e, 0xb2, 0x83}, 15), 427);
      assert::are_equal("2001:0:5ef5:73b8:2c2c:3028:2a4e:b283%15", mo.group().to_string());
      assert::are_equal(427u, mo.interface_index());
    }
    
    auto test_method_(constructor_with_group_and_interface_index_greater_than_0x00000000FFFFFFFF) {
      assert::throws<argument_out_of_range_exception>([] {ip_v6_multicast_option(ip_address(array<xtd::byte> {0x20, 0x01, 0x00, 0x00, 0x5e, 0xf5, 0x73, 0xb8, 0x2c, 0x2c, 0x30, 0x28, 0x2a, 0x4e, 0xb2, 0x83}, 15), 0x100000000);});
    }
    
    auto test_method_(set_group) {
      ip_v6_multicast_option mo;
      mo.group(ip_address(array<xtd::byte> {0x20, 0x01, 0x00, 0x00, 0x5e, 0xf5, 0x73, 0xb8, 0x2c, 0x2c, 0x30, 0x28, 0x2a, 0x4e, 0xb2, 0x83}, 15));
      assert::are_equal("2001:0:5ef5:73b8:2c2c:3028:2a4e:b283%15", mo.group().to_string());
      assert::is_zero(mo.interface_index());
    }
    
    auto test_method_(set_interface_index) {
      ip_v6_multicast_option mo;
      mo.interface_index(427);
      assert::are_equal(ip_address::ip_v6_none, mo.group());
      assert::are_equal(427u, mo.interface_index());
    }
    
    auto test_method_(set_interface_index_greater_than_0x00000000FFFFFFFF) {
      ip_v6_multicast_option mo;
      assert::throws<argument_out_of_range_exception>([&] {mo.interface_index(0x100000000);});
    }
  };
}
