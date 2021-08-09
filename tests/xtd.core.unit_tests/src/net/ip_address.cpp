#include <xtd/net/ip_address.h>
#include <xtd/argument_exception.h>
#include <xtd/argument_out_of_range_exception.h>
#include <xtd/format_exception.h>
#include <xtd/net/sockets/socket_exception.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_ip_address) {
  public:
    void test_method_(any) {
      assert::are_equal("0.0.0.0", ip_address::any.to_string(), line_info_);
    }
    
    void test_method_(broadcast) {
      assert::are_equal("255.255.255.255", ip_address::broadcast.to_string(), line_info_);
    }
    
    void test_method_(ip_v6_any) {
      assert::are_equal("0:0:0:0:0:0:0:0", ip_address::ip_v6_any.to_string(), line_info_);
    }
    
    void test_method_(ip_v6_loopback) {
      assert::are_equal("0:0:0:0:0:0:0:1", ip_address::ip_v6_loopback.to_string(), line_info_);
    }
    
    void test_method_(ip_v6_none) {
      assert::are_equal("0:0:0:0:0:0:0:0", ip_address::ip_v6_none.to_string(), line_info_);
    }
    
    void test_method_(loopback) {
      assert::are_equal("127.0.0.1", ip_address::loopback.to_string(), line_info_);
    }
    
    void test_method_(none) {
      assert::are_equal("255.255.255.255", ip_address::none.to_string(), line_info_);
    }
    
    void test_method_(default_constructor) {
      assert::are_equal("255.255.255.255", ip_address().to_string(), line_info_);
    }
    
    void test_method_(constructor_with_int64_t) {
      assert::are_equal("0.0.0.0", ip_address(static_cast<int64_t>(0x0000000000000000LL)).to_string(), line_info_);
      assert::are_equal("255.255.255.255", ip_address(static_cast<int64_t>(0x00000000FFFFFFFFLL)).to_string(), line_info_);
      assert::are_equal("172.0.10.35", ip_address(static_cast<int64_t>(0x00000000230A00ACLL)).to_string(), line_info_);
    }
    
    void test_method_(copy_constructor) {
      assert::are_equal("0.0.0.0", ip_address(ip_address::any).to_string(), line_info_);
      assert::are_equal("255.255.255.255", ip_address(ip_address::broadcast).to_string(), line_info_);
      assert::are_equal("0:0:0:0:0:0:0:0", ip_address(ip_address::ip_v6_any).to_string(), line_info_);
      assert::are_equal("0:0:0:0:0:0:0:1", ip_address(ip_address::ip_v6_loopback).to_string(), line_info_);
      assert::are_equal("0:0:0:0:0:0:0:0", ip_address(ip_address::ip_v6_none).to_string(), line_info_);
      assert::are_equal("127.0.0.1", ip_address(ip_address::loopback).to_string(), line_info_);
      assert::are_equal("255.255.255.255", ip_address(ip_address::none).to_string(), line_info_);
    }
    
    void test_method_(constructors_wtith_bytes_array_ip_v4) {
      assert::are_equal("172.16.10.30", ip_address(vector<byte_t> {172, 16, 10, 30}).to_string(), line_info_);
    }
    
    void test_method_(constructors_wtih_bytes_array_ip_v6) {
      assert::are_equal("2001:0:5ef5:73b8:2c2c:3028:2a4e:b283", ip_address({0x20, 0x01, 0x00, 0x00, 0x5e, 0xf5, 0x73, 0xb8, 0x2c, 0x2c, 0x30, 0x28, 0x2a, 0x4e, 0xb2, 0x83}).to_string(), line_info_);
      assert::are_equal("2001:0:5ef5:73b8:2c2c:3028:2a4e:b283%15", ip_address(vector<byte_t> {0x20, 0x01, 0x00, 0x00, 0x5e, 0xf5, 0x73, 0xb8, 0x2c, 0x2c, 0x30, 0x28, 0x2a, 0x4e, 0xb2, 0x83}, 15).to_string(), line_info_);
    }
    
    void test_method_(constructors_with_invalid_bytes_array) {
      assert::throws<argument_exception>([]{ip_address({172, 16});}, line_info_);
      assert::throws<argument_exception>([]{ip_address({172, 16, 10, 30, 25, 42});}, line_info_);
    }

    void test_method_(constructors_wtih_quad_part) {
      assert::are_equal("147.24.35.22", ip_address(ip_address(147, 24, 35, 22)).to_string(), line_info_);
      assert::are_equal("0.0.0.0", ip_address(0, 0, 0, 0).to_string(), line_info_);
      assert::are_equal("10.11.12.35", ip_address(10, 11, 12, 35).to_string(), line_info_);
      assert::are_equal("255.255.255.255", ip_address(255, 255, 255, 255).to_string(), line_info_);
    }
    
    void test_method_(address_family) {
      assert::are_equal(address_family::inter_network, ip_address(vector<byte_t> {172, 16, 10, 30}).address_family(), line_info_);
      assert::are_equal(address_family::inter_network_v6, ip_address(vector<byte_t> {0x20, 0x01, 0x00, 0x00, 0x5e, 0xf5, 0x73, 0xb8, 0x2c, 0x2c, 0x30, 0x28, 0x2a, 0x4e, 0xb2, 0x83}).address_family(), line_info_);
    }
    
    void test_method_(get_scope_id) {
      assert::throws<socket_exception>([]{ip_address(vector<byte_t> {172, 16, 10, 30}).scope_id();}, line_info_);
      assert::are_equal(0U, ip_address(vector<byte_t> {0x20, 0x01, 0x00, 0x00, 0x5e, 0xf5, 0x73, 0xb8, 0x2c, 0x2c, 0x30, 0x28, 0x2a, 0x4e, 0xb2, 0x83}).scope_id(), line_info_);
      assert::are_equal(15U, ip_address(vector<byte_t> {0x20, 0x01, 0x00, 0x00, 0x5e, 0xf5, 0x73, 0xb8, 0x2c, 0x2c, 0x30, 0x28, 0x2a, 0x4e, 0xb2, 0x83}, 15).scope_id(), line_info_);
    }
    
    void test_method_(is_ip_v4_mapped_to_ip_v6) {
      
    }
    
    void test_method_(is_ip_v6_link_local) {
      
    }
    
    void test_method_(is_ip_v6_multicast) {
      
    }
    
    void test_method_(is_ip_v6_site_local) {
      
    }
    
    void test_method_(is_ip_v6_teredo) {
      
    }
    
    void test_method_(equals) {
      assert::is_true(ip_address(172, 16, 12, 24).equals(ip_address(172, 16, 12, 24)), line_info_);
      assert::is_false(ip_address(172, 16, 12, 24).equals(ip_address(172, 16, 12, 25)), line_info_);
      
      ip_address addr1(172, 16, 12, 24);
      ip_address addr2(172, 16, 12, 25);
      object* obj1 = &addr1;
      object* obj2 = &addr2;
      assert::is_true(ip_address(172, 16, 12, 24).equals(*obj1), line_info_);
      assert::is_false(ip_address(172, 16, 12, 24).equals(*obj2), line_info_);
      assert::is_false(ip_address(172, 16, 12, 24).equals(ustring("172.16.12.24")), line_info_);
    }

    void test_method_(get_address_bytes) {
      collection_assert::are_equal({172, 16, 12, 24}, ip_address(172, 16, 12, 24).get_address_bytes(), line_info_);
      collection_assert::are_equal({172, 16, 12, 24}, ip_address(static_cast<uint64_t>(bit_converter::to_int32({172, 16, 12, 24}, 0))).get_address_bytes(), line_info_);
      collection_assert::are_equal({145, 32, 7, 18}, ip_address(145, 32, 7, 18).get_address_bytes(), line_info_);
      
      collection_assert::are_equal({32, 1, 0, 0, 94, 245, 115, 184, 44, 44, 48, 40, 42, 78, 178, 131}, ip_address(vector<byte_t> {0x20, 0x01, 0x00, 0x00, 0x5e, 0xf5, 0x73, 0xb8, 0x2c, 0x2c, 0x30, 0x28, 0x2a, 0x4e, 0xb2, 0x83}).get_address_bytes(), line_info_);
    }

    void test_method_(host_to_network_order) {
      if (bit_converter::is_little_endian) {
        assert::are_equal(0x3412U, ip_address::host_to_network_order(static_cast<uint16_t>(0x1234)), line_info_);
        assert::are_equal(0x78563412U, ip_address::host_to_network_order(static_cast<uint32_t>(0x12345678)), line_info_);
        assert::are_equal(0xF0DEBC9A78563412ULL, ip_address::host_to_network_order(static_cast<uint64_t>(0x123456789ABCDEF0)), line_info_);
      } else {
        assert::are_equal(0x1234U, ip_address::host_to_network_order(static_cast<uint16_t>(0x1234)), line_info_);
        assert::are_equal(0x12345678U, ip_address::host_to_network_order(static_cast<uint32_t>(0x12345678)), line_info_);
        assert::are_equal(0x123456789ABCDEF0ULL, ip_address::host_to_network_order(static_cast<uint64_t>(0x123456789ABCDEF0)), line_info_);
      }
    }
    
    void test_method_(is_loopback) {
      assert::is_false(ip_address::is_loopback(ip_address(172, 16, 12, 24)), line_info_);
      assert::is_false(ip_address::is_loopback(ip_address(0, 0, 0, 0)), line_info_);
      assert::is_true(ip_address::is_loopback(ip_address(127, 0, 0, 1)), line_info_);
      assert::is_true(ip_address::is_loopback(ip_address::loopback), line_info_);
      assert::is_true(ip_address::is_loopback(ip_address::ip_v6_loopback), line_info_);
    }
    
    void test_method_(network_to_host_order) {
      if (bit_converter::is_little_endian) {
        assert::are_equal(0x3412U, ip_address::network_to_host_order(static_cast<uint16_t>(0x1234)), line_info_);
        assert::are_equal(0x78563412U, ip_address::network_to_host_order(static_cast<uint32_t>(0x12345678)), line_info_);
        assert::are_equal(0xF0DEBC9A78563412ULL, ip_address::network_to_host_order(static_cast<uint64_t>(0x123456789ABCDEF0)), line_info_);
      } else {
        assert::are_equal(0x1234U, ip_address::network_to_host_order(static_cast<uint16_t>(0x1234)), line_info_);
        assert::are_equal(0x12345678U, ip_address::network_to_host_order(static_cast<uint32_t>(0x12345678)), line_info_);
        assert::are_equal(0x123456789ABCDEF0ULL, ip_address::network_to_host_order(static_cast<uint64_t>(0x123456789ABCDEF0)), line_info_);
      }
    }
    
    void test_method_(parse_ip_v4) {
      assert::are_equal("172.16.12.24", ip_address::parse("172.16.12.24").to_string(), line_info_);
    }
    
    void test_method_(parse_ip_v6) {
      assert::are_equal("2001:0:5ef5:73b8:2c2c:3028:2a4e:b283", ip_address::parse("2001:0:5ef5:73b8:2c2c:3028:2a4e:b283").to_string(), line_info_);
      assert::are_equal("2001:0:5ef5:73b8:2c2c:3028:2a4e:b283", ip_address::parse("2001::5ef5:73b8:2c2c:3028:2a4e:b283").to_string(), line_info_);
      assert::are_equal("2001:0:5ef5:73b8:2c2c:3028:2a4e:b283%15", ip_address::parse("2001:0:5ef5:73b8:2c2c:3028:2a4e:b283%15").to_string(), line_info_);
    }

    void test_method_(parse_with_bad_string) {
      assert::throws<format_exception>([]{ip_address::parse("172.16.12.24.1");}, line_info_);
    }
  };
}
