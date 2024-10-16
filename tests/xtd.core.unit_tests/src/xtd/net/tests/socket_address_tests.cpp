#include <xtd/net/socket_address>
#include <xtd/argument_out_of_range_exception>
#include <xtd/index_out_of_range_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;
using namespace xtd::tunit;

namespace xtd::net::tests {
  class test_class_(socket_address_tests) {
    void test_method_(create_socket_address_with_address_family_unnown) {
      socket_address sa(address_family::unknown);
      assert::are_equal(address_family::unspecified, sa.address_family());
      assert::are_equal(32_z, sa.size());
      assert::are_equal("unspecified:32:{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}", sa.to_string());
    }
    
    void test_method_(create_socket_address_with_address_family_unspecified) {
      socket_address sa(address_family::unspecified);
      assert::are_equal(address_family::unspecified, sa.address_family());
      assert::are_equal(32_z, sa.size());
      assert::are_equal("unspecified:32:{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}", sa.to_string());
    }
    
    void test_method_(create_socket_address_with_address_family_unix) {
      socket_address sa(address_family::unix);
      assert::are_equal(address_family::unix, sa.address_family());
      assert::are_equal(32_z, sa.size());
      assert::are_equal("unix:32:{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}", sa.to_string());
    }
    
    void test_method_(create_socket_address_with_address_family_inter_network) {
      socket_address sa(address_family::inter_network);
      assert::are_equal(address_family::inter_network, sa.address_family());
      assert::are_equal(32_z, sa.size());
      assert::are_equal("inter_network:32:{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}", sa.to_string());
    }
    
    void test_method_(create_socket_address_with_address_family_sna) {
      socket_address sa(address_family::sna);
      assert::are_equal(address_family::sna, sa.address_family());
      assert::are_equal(32_z, sa.size());
      assert::are_equal("sna:32:{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}", sa.to_string());
    }
    
    void test_method_(create_socket_address_with_address_family_dec_net) {
      socket_address sa(address_family::dec_net);
      assert::are_equal(address_family::dec_net, sa.address_family());
      assert::are_equal(32_z, sa.size());
      assert::are_equal("dec_net:32:{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}", sa.to_string());
    }
    
    void test_method_(create_socket_address_with_address_family_apple_talk) {
      socket_address sa(address_family::apple_talk);
      assert::are_equal(address_family::apple_talk, sa.address_family());
      assert::are_equal(32_z, sa.size());
      assert::are_equal("apple_talk:32:{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}", sa.to_string());
    }
    
    void test_method_(create_socket_address_with_address_family_inter_network_v6) {
      socket_address sa(address_family::inter_network_v6);
      assert::are_equal(address_family::inter_network_v6, sa.address_family());
      assert::are_equal(32_z, sa.size());
      assert::are_equal("inter_network_v6:32:{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}", sa.to_string());
    }
    
    void test_method_(create_socket_address_with_address_family_max) {
      socket_address sa(address_family::max);
      assert::are_equal(address_family::max, sa.address_family());
      assert::are_equal(32_z, sa.size());
      assert::are_equal("max:32:{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}", sa.to_string());
    }
    
    void test_method_(create_socket_address_with_address_family_inter_network_and_size_16) {
      socket_address sa(address_family::inter_network, 16);
      assert::are_equal(address_family::inter_network, sa.address_family());
      assert::are_equal(16_z, sa.size());
      assert::are_equal("inter_network:16:{0,0,0,0,0,0,0,0,0,0,0,0,0,0}", sa.to_string());
    }
    
    void test_method_(create_socket_address_with_address_family_inter_network_and_size_1) {
      assert::throws<argument_out_of_range_exception>([] {socket_address sa(address_family::inter_network, 1);});
    }
    
    void test_method_(socket_address_value_operator) {
      socket_address sa(address_family::inter_network);
      assert::are_equal(static_cast<xtd::byte>(address_family::inter_network), sa[0]);
      assert::are_equal(0, sa[1]);
      assert::are_equal(0, sa[24]);
      sa[24] = 42;
      assert::are_equal(42, sa[24]);
      assert::are_equal("inter_network:32:{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,42,0,0,0,0,0,0,0}", sa.to_string());
    }
    
    void test_method_(socket_address_value_operator_with_out_of_range_index) {
      socket_address sa(address_family::inter_network);
      assert::throws<index_out_of_range_exception>([&] {sa[32] = 42;});
    }
    
    void test_method_(socket_address_to_string) {
      socket_address sa(address_family::inter_network);
      for (auto index = 2u; index < sa.size(); ++index)
        sa[index] = static_cast<xtd::byte>(index);
      assert::are_equal("inter_network:32:{2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31}", sa.to_string());
    }
  };
}
