#include <xtd/net/sockets/multicast_option.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_multicast_option) {
  public:
    void test_method_(default_constructor) {
      multicast_option mo;
      assert::are_equal(ip_address::none, mo.group(), csf_);
      assert::is_zero(mo.interface_index(), csf_);
      assert::are_equal(ip_address::none, mo.local_adress(), csf_);
    }

    void test_method_(constructor_with_group_and_local_address) {
      multicast_option mo(ip_address(172, 16, 12, 24), ip_address(172, 16, 12, 1));
      assert::are_equal("172.16.12.24", mo.group().to_string(), csf_);
      assert::is_zero(mo.interface_index(), csf_);
      assert::are_equal("172.16.12.1", mo.local_adress().to_string(), csf_);
    }

    void test_method_(constructor_with_group) {
      multicast_option mo(ip_address(172, 16, 12, 24));
      assert::are_equal("172.16.12.24", mo.group().to_string(), csf_);
      assert::is_zero(mo.interface_index(), csf_);
      assert::are_equal(ip_address::any, mo.local_adress(), csf_);
   }

    void test_method_(constructor_with_group_and_interface_index) {
      multicast_option mo(ip_address(172, 16, 12, 24), 427);
      assert::are_equal("172.16.12.24", mo.group().to_string(), csf_);
      assert::are_equal(427U, mo.interface_index(), csf_);
      assert::are_equal(ip_address::none, mo.local_adress(), csf_);
    }
    
    void test_method_(constructor_with_group_and_interface_index_greather_than_0x00FFFFFF) {
      assert::throws<argument_out_of_range_exception>([]{multicast_option(ip_address(172, 16, 12, 24), 0x1000000);}, csf_);
    }
    
    void test_method_(set_group) {
      multicast_option mo;
      mo.group(ip_address(172, 16, 12, 24));
      assert::are_equal("172.16.12.24", mo.group().to_string(), csf_);
      assert::is_zero(mo.interface_index(), csf_);
      assert::are_equal(ip_address::none, mo.local_adress(), csf_);
    }

    void test_method_(set_interface_index) {
      multicast_option mo;
      mo.interface_index(427);
      assert::are_equal(ip_address::none, mo.group(), csf_);
      assert::are_equal(427U, mo.interface_index(), csf_);
      assert::are_equal(ip_address::none, mo.local_adress(), csf_);
    }

    void test_method_(set_interface_index_greather_than_0x00FFFFFF) {
      multicast_option mo;
      assert::throws<argument_out_of_range_exception>([&]{mo.interface_index(0x1000000);}, csf_);
    }

    void test_method_(set_local_address) {
      multicast_option mo;
      mo.local_adress(ip_address(172, 16, 12, 1));
      assert::are_equal(ip_address::none, mo.group(), csf_);
      assert::is_zero(mo.interface_index(), csf_);
      assert::are_equal("172.16.12.1", mo.local_adress().to_string(), csf_);
    }
  };
}
