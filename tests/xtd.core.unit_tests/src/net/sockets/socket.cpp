#include <xtd/net/sockets/socket.h>
#include <xtd/object_closed_exception.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_socket) {
  public:
    void test_method_(default_constructor) {
      socket s;
      assert::are_equal(address_family::unspecified, s.address_family(), line_info_);
      assert::throws<object_closed_exception>([&]{s.available();}, line_info_);
      assert::throws<object_closed_exception>([&]{s.blocking();}, line_info_);
      assert::is_false(s.connected(), line_info_);
      assert::throws<object_closed_exception>([&]{s.dont_fragment();}, line_info_);
      assert::throws<object_closed_exception>([&]{s.dual_mode();}, line_info_);
      assert::is_zero(s.handle(), line_info_);
    }

    void test_method_(constructor_with_socket_type_stream_and_protocol_type_tcp) {
      socket s(socket_type::stream, protocol_type::tcp);
      if (s.os_supports_ip_v6()) assert::are_equal(address_family::inter_network_v6, s.address_family(), line_info_);
      else assert::are_equal(address_family::inter_network, s.address_family(), line_info_);
      assert::is_zero(s.available(), line_info_);
      assert::is_true(s.blocking(), line_info_);
      assert::is_false(s.connected(), line_info_);
      if (s.os_supports_ip_v6()) assert::throws<not_supported_exception>([&]{s.dont_fragment();}, line_info_);
      else assert::is_true(s.dont_fragment(), line_info_);
      if (s.os_supports_ip_v6()) assert::is_true(s.dual_mode(), line_info_);
      else assert::throws<not_supported_exception>([&]{s.dual_mode();}, line_info_);
      assert::is_not_zero(s.handle(), line_info_);
    }

    void test_method_(constructor_with_address_family_internet_network_socket_type_stream_and_protocol_type_tcp) {
      socket s(address_family::inter_network, socket_type::stream, protocol_type::tcp);
      assert::are_equal(address_family::inter_network, s.address_family(), line_info_);
      assert::is_zero(s.available(), line_info_);
      assert::is_true(s.blocking(), line_info_);
      assert::is_false(s.connected(), line_info_);
      assert::throws<socket_exception>([&]{s.dont_fragment();}, line_info_);
      assert::throws<not_supported_exception>([&]{s.dual_mode();}, line_info_);
      assert::is_not_zero(s.handle(), line_info_);
    }

    void test_method_(constructor_with_address_family_internet_network_socket_type_dgram_and_protocol_type_udp) {
      socket s(address_family::inter_network, socket_type::dgram, protocol_type::udp);
      assert::are_equal(address_family::inter_network, s.address_family(), line_info_);
      assert::is_zero(s.available(), line_info_);
      assert::is_true(s.blocking(), line_info_);
      assert::is_false(s.connected(), line_info_);
      //assert::is_true(s.dont_fragment(), line_info_);
      assert::throws<not_supported_exception>([&]{s.dual_mode();}, line_info_);
      assert::is_not_zero(s.handle(), line_info_);
    }
  };
}
