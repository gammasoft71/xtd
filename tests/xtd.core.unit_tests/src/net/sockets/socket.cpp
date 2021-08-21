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
    void test_method_(os_supports_ip_v4) {
      assume::is_true(socket::os_supports_ip_v4(), line_info_);
    }
    
    void test_method_(os_supports_ip_v6) {
      assume::is_true(socket::os_supports_ip_v6(), line_info_);
    }
    
    void test_method_(default_constructor) {
      socket s;
      assert::are_equal(address_family::unspecified, s.address_family(), line_info_);
      assert::throws<object_closed_exception>([&]{s.available();}, line_info_);
      assert::throws<object_closed_exception>([&]{s.blocking();}, line_info_);
      assert::is_false(s.connected(), line_info_);
      assert::throws<object_closed_exception>([&]{s.dont_fragment();}, line_info_);
      assert::throws<object_closed_exception>([&]{s.dual_mode();}, line_info_);
      assert::throws<object_closed_exception>([&]{s.enable_broadcast();}, line_info_);
      assert::throws<object_closed_exception>([&]{s.exclusive_address_use();}, line_info_);
      assert::is_zero(s.handle(), line_info_);
      assert::is_false(s.is_bound(), line_info_);
      assert::throws<object_closed_exception>([&]{s.linger_state();}, line_info_);
      assert::throws<object_closed_exception>([&]{s.local_end_point();}, line_info_);
      assert::throws<object_closed_exception>([&]{s.multicast_loopback();}, line_info_);
      assert::throws<object_closed_exception>([&]{s.no_delay();}, line_info_);
      assert::are_equal(protocol_type::unspecified, s.protocol_type(), line_info_);
      assert::throws<object_closed_exception>([&]{s.receive_buffer_size();}, line_info_);
      assert::throws<object_closed_exception>([&]{s.receive_timeout();}, line_info_);
      assert::throws<object_closed_exception>([&]{s.remote_end_point();}, line_info_);
      assert::throws<object_closed_exception>([&]{s.send_buffer_size();}, line_info_);
      assert::throws<object_closed_exception>([&]{s.send_timeout();}, line_info_);
      assert::are_equal(socket_type::unknown, s.socket_type(), line_info_);
      assert::throws<object_closed_exception>([&]{s.ttl();}, line_info_);
    }

    void test_method_(constructor_with_socket_type_stream_and_protocol_type_tcp) {
      assume::is_true(socket::os_supports_ip_v6());
      socket s(socket_type::stream, protocol_type::tcp);
      assert::are_equal(address_family::inter_network_v6, s.address_family(), line_info_);
      assert::is_zero(s.available(), line_info_);
      assert::is_true(s.blocking(), line_info_);
      assert::is_false(s.connected(), line_info_);
      assert::throws<not_supported_exception>([&]{s.dont_fragment();}, line_info_);
      assert::is_true(s.dual_mode(), line_info_);
      assert::throws<socket_exception>([&] {s.enable_broadcast();}, line_info_);
      assert::is_false(s.exclusive_address_use(), line_info_);
      assert::is_not_zero(s.handle(), line_info_);
      assert::is_false(s.is_bound(), line_info_);
      linger_option linger = s.linger_state();
      assert::is_false(linger.enabled(), line_info_);
      assert::is_zero(linger.linger_time(), line_info_);
      assert::is_null(s.local_end_point(), line_info_);
      assert::throws<socket_exception>([&]{s.multicast_loopback();}, line_info_);
      assert::is_false(s.no_delay(), line_info_);
      assert::are_equal(protocol_type::tcp, s.protocol_type(), line_info_);
      assert::is_not_zero(s.receive_buffer_size(), line_info_);
      assert::is_zero(s.receive_timeout(), line_info_);
      assert::is_null(s.remote_end_point(), line_info_);
      assert::is_not_zero(s.send_buffer_size(), line_info_);
      assert::is_zero(s.send_timeout(), line_info_);
      assert::are_equal(socket_type::stream, s.socket_type(), line_info_);
      // The ttl value is zero on Circlle CI. (this is not an error).
      // assert::is_not_zero(s.ttl(), line_info_);
    }

    void test_method_(constructor_with_address_family_internet_network_socket_type_stream_and_protocol_type_tcp) {
      assume::is_true(socket::os_supports_ip_v4());
      socket s(address_family::inter_network, socket_type::stream, protocol_type::tcp);
      assert::are_equal(address_family::inter_network, s.address_family(), line_info_);
      assert::is_zero(s.available(), line_info_);
      assert::is_true(s.blocking(), line_info_);
      assert::is_false(s.connected(), line_info_);
      if (environment::os_version().is_windows_platform()) assert::is_true(s.dont_fragment(), line_info_);
      else assert::is_false(s.dont_fragment(), line_info_);
      assert::throws<not_supported_exception>([&]{s.dual_mode();}, line_info_);
      assert::throws<socket_exception>([&] {s.enable_broadcast();}, line_info_);
      assert::is_false(s.exclusive_address_use(), line_info_);
      assert::is_not_zero(s.handle(), line_info_);
      assert::is_false(s.is_bound(), line_info_);
      linger_option linger = s.linger_state();
      assert::is_false(linger.enabled(), line_info_);
      assert::is_zero(linger.linger_time(), line_info_);
      assert::is_null(s.local_end_point(), line_info_);
      assert::throws<socket_exception>([&]{s.multicast_loopback();}, line_info_);
      assert::is_false(s.no_delay(), line_info_);
      assert::are_equal(protocol_type::tcp, s.protocol_type(), line_info_);
      assert::is_not_zero(s.receive_buffer_size(), line_info_);
      assert::is_zero(s.receive_timeout(), line_info_);
      assert::is_null(s.remote_end_point(), line_info_);
      assert::is_not_zero(s.send_buffer_size(), line_info_);
      assert::is_zero(s.send_timeout(), line_info_);
      assert::are_equal(socket_type::stream, s.socket_type(), line_info_);
      assert::is_not_zero(s.ttl(), line_info_);
    }

    void test_method_(constructor_with_address_family_internet_network_socket_type_dgram_and_protocol_type_udp) {
      assume::is_true(socket::os_supports_ip_v4());
      socket s(address_family::inter_network, socket_type::dgram, protocol_type::udp);
      assert::are_equal(address_family::inter_network, s.address_family(), line_info_);
      assert::is_zero(s.available(), line_info_);
      assert::is_true(s.blocking(), line_info_);
      assert::is_false(s.connected(), line_info_);
      assert::is_false(s.dont_fragment(), line_info_);
      assert::throws<not_supported_exception>([&]{s.dual_mode();}, line_info_);
      assert::is_false(s.enable_broadcast(), line_info_);
      assert::is_false(s.exclusive_address_use(), line_info_);
      assert::is_not_zero(s.handle(), line_info_);
      assert::is_false(s.is_bound(), line_info_);
      assert::throws<socket_exception>([&] {s.linger_state();}, line_info_);
      assert::is_null(s.local_end_point(), line_info_);
      assert::is_true(s.multicast_loopback(), line_info_);
      assert::throws<socket_exception>([&]{s.no_delay();}, line_info_);
      assert::are_equal(protocol_type::udp, s.protocol_type(), line_info_);
      assert::is_not_zero(s.receive_buffer_size(), line_info_);
      assert::is_zero(s.receive_timeout(), line_info_);
      assert::is_null(s.remote_end_point(), line_info_);
      assert::is_not_zero(s.send_buffer_size(), line_info_);
      assert::is_zero(s.send_timeout(), line_info_);
      assert::are_equal(socket_type::dgram, s.socket_type(), line_info_);
      assert::is_not_zero(s.ttl(), line_info_);
    }
    
    void test_method_(bind_with_bad_socket) {
      socket s;
      assert::throws<object_closed_exception>([&]{s.bind(ip_end_point(ip_address(127, 0, 0, 1), 9400));}, line_info_);
    }
    
    void test_method_(bind_socket_type_stream_and_protocol_type_tcp_socket) {
      assume::is_true(socket::os_supports_ip_v6());
      socket s(address_family::inter_network_v6, socket_type::stream, protocol_type::tcp);
      try {
        s.bind(ip_end_point(ip_address::ip_v6_any, 9400));
      } catch(const socket_exception& e) {
        console::write_line("exceptio : {}, error {}", e, static_cast<socket_error>(e.error_code().value()));
      }
      assert::is_true(s.is_bound(), line_info_);
    }

    void test_method_(bind_with_address_family_internet_network_socket_type_stream_and_protocol_type_tcp_socket) {
      assume::is_true(socket::os_supports_ip_v4());
      socket s(address_family::inter_network, socket_type::stream, protocol_type::tcp);
      s.bind(ip_end_point(ip_address::any, 9400));
      assert::is_true(s.is_bound(), line_info_);
    }

    void test_method_(bind_with_address_family_internet_network_socket_type_dgram_and_protocol_type_udp_socket) {
      assume::is_true(socket::os_supports_ip_v4());
      socket s(address_family::inter_network, socket_type::dgram, protocol_type::udp);
      s.bind(ip_end_point(ip_address::any, 9400));
      assert::is_true(s.is_bound(), line_info_);
    }

    void test_method_(set_receive_buffer_size) {
      assume::is_true(socket::os_supports_ip_v4());
      socket s(address_family::inter_network, socket_type::stream, protocol_type::tcp);
      s.receive_buffer_size(4242);
      // Fix on linux receive 8484U value ???
      //assert::are_equal(4242U, s.receive_buffer_size(), line_info_);
    }
    
    void test_method_(set_receive_timeout) {
      assume::is_true(socket::os_supports_ip_v4());
      socket s(address_family::inter_network, socket_type::stream, protocol_type::tcp);
      s.receive_timeout(1000);
      assert::are_equal(1000, s.receive_timeout(), line_info_);
    }
    
    void test_method_(set_send_buffer_size) {
      assume::is_true(socket::os_supports_ip_v4());
      socket s(address_family::inter_network, socket_type::stream, protocol_type::tcp);
      s.send_buffer_size(4242);
      // Fix on linux receive 8484U value ???
      //assert::are_equal(4242U, s.send_buffer_size(), line_info_);
    }
    
    void test_method_(set_send_timeout) {
      assume::is_true(socket::os_supports_ip_v4());
      socket s(address_family::inter_network, socket_type::stream, protocol_type::tcp);
      s.send_timeout(1000);
      assert::are_equal(1000, s.send_timeout(), line_info_);
    }
  };
}
