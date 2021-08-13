#include <xtd/net/sockets/ip_v6_multicast_option.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_ip_v6_multicast_option) {
  public:
    void test_method_(default_constructor) {
      ip_v6_multicast_option mo;
      assert::are_equal(ip_address::ip_v6_none, mo.group(), line_info_);
      assert::is_zero(mo.interface_index(), line_info_);
    }

    void test_method_(constructor_with_group) {
      ip_v6_multicast_option mo(ip_address(vector<byte_t> {0x20, 0x01, 0x00, 0x00, 0x5e, 0xf5, 0x73, 0xb8, 0x2c, 0x2c, 0x30, 0x28, 0x2a, 0x4e, 0xb2, 0x83}, 15));
      assert::are_equal("2001:0:5ef5:73b8:2c2c:3028:2a4e:b283%15", mo.group().to_string(), line_info_);
      assert::is_zero(mo.interface_index(), line_info_);
    }

    void test_method_(constructor_with_group_and_interface_index) {
      ip_v6_multicast_option mo(ip_address(vector<byte_t> {0x20, 0x01, 0x00, 0x00, 0x5e, 0xf5, 0x73, 0xb8, 0x2c, 0x2c, 0x30, 0x28, 0x2a, 0x4e, 0xb2, 0x83}, 15), 427);
      assert::are_equal("2001:0:5ef5:73b8:2c2c:3028:2a4e:b283%15", mo.group().to_string(), line_info_);
      assert::are_equal(427, mo.interface_index(), line_info_);
    }

    void test_method_(set_group) {
      ip_v6_multicast_option mo;
      mo.group(ip_address(vector<byte_t> {0x20, 0x01, 0x00, 0x00, 0x5e, 0xf5, 0x73, 0xb8, 0x2c, 0x2c, 0x30, 0x28, 0x2a, 0x4e, 0xb2, 0x83}, 15));
      assert::are_equal("2001:0:5ef5:73b8:2c2c:3028:2a4e:b283%15", mo.group().to_string(), line_info_);
      assert::is_zero(mo.interface_index(), line_info_);
    }

    void test_method_(set_interface_index) {
      ip_v6_multicast_option mo;
      mo.interface_index(427);
      assert::are_equal(ip_address::ip_v6_none, mo.group(), line_info_);
      assert::are_equal(427, mo.interface_index(), line_info_);
    }
  };
}
