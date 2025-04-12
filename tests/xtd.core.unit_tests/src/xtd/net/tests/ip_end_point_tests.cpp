#include <xtd/as>
#include <xtd/net/ip_end_point>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;
using namespace xtd::tunit;

namespace xtd::net::tests {
  class test_class_(ip_end_point_tests) {
    void test_method_(min_port) {
      assert::are_equal(0u, ip_end_point::min_port);
    }
    
    void test_method_(max_port) {
      assert::are_equal(0xFFFFu, ip_end_point::max_port);
    }
    
    void test_method_(construstor_with_uint32_address_and_port) {
      ip_end_point ep(0x230A00AC, 9500);
      assert::are_equal("172.0.10.35", ep.address().to_string());
      assert::are_equal(9500, ep.port());
      assert::are_equal("172.0.10.35:9500", ep.to_string());
      assert::are_equal("inter_network:16:{37,28,172,0,10,35,0,0,0,0,0,0,0,0}", ep.serialize().to_string());
    }
    
    void test_method_(construstor_with_address_ip_v4_and_port) {
      ip_end_point ep(ip_address(172, 0, 10, 35), 9500);
      assert::are_equal("172.0.10.35", ep.address().to_string());
      assert::are_equal(9500, ep.port());
      assert::are_equal("172.0.10.35:9500", ep.to_string());
      assert::are_equal("inter_network:16:{37,28,172,0,10,35,0,0,0,0,0,0,0,0}", ep.serialize().to_string());
    }
    
    void test_method_(construstor_with_address_ip_v6_and_port) {
      ip_end_point ep(ip_address(xtd::array<xtd::byte> {0x20, 0x01, 0x00, 0x00, 0x5e, 0xf5, 0x73, 0xb8, 0x2c, 0x2c, 0x30, 0x28, 0x2a, 0x4e, 0xb2, 0x83}, 15), 9500);
      assert::are_equal("2001:0:5ef5:73b8:2c2c:3028:2a4e:b283%15", ep.address().to_string());
      assert::are_equal(9500, ep.port());
      assert::are_equal("[2001:0:5ef5:73b8:2c2c:3028:2a4e:b283%15]:9500", ep.to_string());
      assert::are_equal("inter_network_v6:28:{37,28,0,0,0,0,32,1,0,0,94,245,115,184,44,44,48,40,42,78,178,131,15,0,0,0}", ep.serialize().to_string());
    }
    
    void test_method_(ip_end_point_ip_v4_create_with_socket_address_ip_v4) {
      xtd::uptr<ip_end_point> ep = as<ip_end_point>(ip_end_point(ip_address::none, 0).create(ip_end_point(0x230A00AC, 9500).serialize()));
      assert::are_equal("172.0.10.35", ep->address().to_string());
      assert::are_equal(9500, ep->port());
      assert::are_equal("172.0.10.35:9500", ep->to_string());
      assert::are_equal("inter_network:16:{37,28,172,0,10,35,0,0,0,0,0,0,0,0}", ep->serialize().to_string());
    }
    
    void test_method_(ip_end_point_ip_v4_create_with_socket_address_ip_v6) {
      assert::throws<argument_exception>([] {ip_end_point(ip_address::none, 0).create(ip_end_point(ip_address(xtd::array<xtd::byte> {0x20, 0x01, 0x00, 0x00, 0x5e, 0xf5, 0x73, 0xb8, 0x2c, 0x2c, 0x30, 0x28, 0x2a, 0x4e, 0xb2, 0x83}, 15), 9500).serialize());});
    }
    
    void test_method_(ip_end_point_ip_v6_create_with_socket_address_ip_v6) {
      xtd::uptr<ip_end_point> ep = as<ip_end_point>(ip_end_point(ip_address::ip_v6_none, 0).create(ip_end_point(ip_address(xtd::array<xtd::byte> {0x20, 0x01, 0x00, 0x00, 0x5e, 0xf5, 0x73, 0xb8, 0x2c, 0x2c, 0x30, 0x28, 0x2a, 0x4e, 0xb2, 0x83}, 15), 9500).serialize()));
      assert::are_equal("2001:0:5ef5:73b8:2c2c:3028:2a4e:b283%15", ep->address().to_string());
      assert::are_equal(9500, ep->port());
      assert::are_equal("[2001:0:5ef5:73b8:2c2c:3028:2a4e:b283%15]:9500", ep->to_string());
      assert::are_equal("inter_network_v6:28:{37,28,0,0,0,0,32,1,0,0,94,245,115,184,44,44,48,40,42,78,178,131,15,0,0,0}", ep->serialize().to_string());
    }
    
    void test_method_(ip_end_point_ip_v6_create_with_socket_address_ip_v6_loopback_and_port_9400) {
      ip_end_point ep = ip_end_point(ip_address::ip_v6_loopback, 9400);
      assert::are_equal("inter_network_v6:28:{36,184,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0}", ep.serialize().to_string());
      assert::are_equal(28_z, ep.serialize().size());
    }
    
    void test_method_(ip_end_point_ip_v6_create_with_socket_address_ip_v4) {
      assert::throws<argument_exception>([] {ip_end_point(ip_address::ip_v6_none, 0).create(ip_end_point(0x230A00AC, 9500).serialize());});
    }
  };
}
