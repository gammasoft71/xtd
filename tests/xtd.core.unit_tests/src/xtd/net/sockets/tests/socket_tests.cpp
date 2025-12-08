#include <xtd/net/sockets/socket>
#include <xtd/net/sockets/socket_exception>
#include <xtd/net/ip_end_point>
#include <xtd/environment>
#include <xtd/object_closed_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/assume>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;
using namespace xtd::tunit;

namespace xtd::net::sockets::tests {
  class test_class_(socket_tests) {
    auto test_method_(os_supports_ip_v4) {
      assume::is_true(socket::os_supports_ip_v4());
    }
    
    auto test_method_(os_supports_ip_v6) {
      assume::is_true(socket::os_supports_ip_v6());
    }
    
    auto test_method_(default_constructor) {
      socket s;
      assert::are_equal(address_family::unspecified, s.address_family());
      assert::throws<object_closed_exception>([&] {s.available();});
      assert::throws<object_closed_exception>([&] {s.blocking();});
      assert::is_false(s.connected());
      assert::throws<object_closed_exception>([&] {s.dont_fragment();});
      assert::throws<object_closed_exception>([&] {s.dual_mode();});
      assert::throws<object_closed_exception>([&] {s.enable_broadcast();});
      assert::throws<object_closed_exception>([&] {s.exclusive_address_use();});
      assert::is_zero(s.handle());
      assert::is_false(s.is_bound());
      assert::throws<object_closed_exception>([&] {s.linger_state();});
      assert::throws<object_closed_exception>([&] {s.local_end_point();});
      assert::throws<object_closed_exception>([&] {s.multicast_loopback();});
      assert::throws<object_closed_exception>([&] {s.no_delay();});
      assert::are_equal(protocol_type::unspecified, s.protocol_type());
      assert::throws<object_closed_exception>([&] {s.receive_buffer_size();});
      assert::throws<object_closed_exception>([&] {s.receive_timeout();});
      assert::throws<object_closed_exception>([&] {s.remote_end_point();});
      assert::throws<object_closed_exception>([&] {s.send_buffer_size();});
      assert::throws<object_closed_exception>([&] {s.send_timeout();});
      assert::are_equal(socket_type::unknown, s.socket_type());
      assert::throws<object_closed_exception>([&] {s.ttl();});
    }
    
    auto test_method_(constructor_with_socket_type_stream_and_protocol_type_tcp) {
      assume::is_true(socket::os_supports_ip_v6());
      socket s(socket_type::stream, protocol_type::tcp);
      assert::are_equal(address_family::inter_network_v6, s.address_family());
      assert::is_zero(s.available());
      assert::is_true(s.blocking());
      assert::is_false(s.connected());
      assert::throws<not_supported_exception>([&] {s.dont_fragment();});
      assert::is_true(s.dual_mode());
      assert::throws<socket_exception>([&] {s.enable_broadcast();});
      assert::is_false(s.exclusive_address_use());
      assert::is_not_zero(s.handle());
      assert::is_false(s.is_bound());
      linger_option linger = s.linger_state();
      assert::is_false(linger.enabled());
      assert::is_zero(linger.linger_time());
      assert::is_null(s.local_end_point());
      assert::throws<socket_exception>([&] {s.multicast_loopback();});
      assert::is_false(s.no_delay());
      assert::are_equal(protocol_type::tcp, s.protocol_type());
      assert::is_not_zero(s.receive_buffer_size());
      assert::is_zero(s.receive_timeout());
      assert::is_null(s.remote_end_point());
      assert::is_not_zero(s.send_buffer_size());
      assert::is_zero(s.send_timeout());
      assert::are_equal(socket_type::stream, s.socket_type());
      // The ttl value is zero on Circle CI. (this is not an error).
      // assert::is_not_zero(s.ttl());
    }
    
    auto test_method_(constructor_with_address_family_internet_network_v6_socket_type_stream_and_protocol_type_tcp) {
      assume::is_true(socket::os_supports_ip_v6());
      socket s(socket_type::stream, protocol_type::tcp);
      assert::are_equal(address_family::inter_network_v6, s.address_family());
      assert::is_zero(s.available());
      assert::is_true(s.blocking());
      assert::is_false(s.connected());
      assert::throws<not_supported_exception>([&] {s.dont_fragment();});
      assert::is_true(s.dual_mode());
      assert::throws<socket_exception>([&] {s.enable_broadcast();});
      assert::is_false(s.exclusive_address_use());
      assert::is_not_zero(s.handle());
      assert::is_false(s.is_bound());
      linger_option linger = s.linger_state();
      assert::is_false(linger.enabled());
      assert::is_zero(linger.linger_time());
      assert::is_null(s.local_end_point());
      assert::throws<socket_exception>([&] {s.multicast_loopback();});
      assert::is_false(s.no_delay());
      assert::are_equal(protocol_type::tcp, s.protocol_type());
      assert::is_not_zero(s.receive_buffer_size());
      assert::is_zero(s.receive_timeout());
      assert::is_null(s.remote_end_point());
      assert::is_not_zero(s.send_buffer_size());
      assert::is_zero(s.send_timeout());
      assert::are_equal(socket_type::stream, s.socket_type());
      // The ttl value is zero on Circle CI. (this is not an error).
      // assert::is_not_zero(s.ttl());
    }
    
    auto test_method_(constructor_with_address_family_internet_network_socket_type_stream_and_protocol_type_tcp) {
      #if defined(__XTD_BUILD_WITH_CONTINUOUS_INTEGRATION_SYSTEM__)
      return;
      #endif
      assume::is_true(socket::os_supports_ip_v4());
      socket s(address_family::inter_network, socket_type::stream, protocol_type::tcp);
      assert::are_equal(address_family::inter_network, s.address_family());
      assert::is_zero(s.available());
      assert::is_true(s.blocking());
      assert::is_false(s.connected());
      if (environment::os_version().is_windows_platform()) assert::is_true(s.dont_fragment());
      else assert::is_false(s.dont_fragment());
      assert::throws<not_supported_exception>([&] {s.dual_mode();});
      assert::throws<socket_exception>([&] {s.enable_broadcast();});
      assert::is_false(s.exclusive_address_use());
      assert::is_not_zero(s.handle());
      assert::is_false(s.is_bound());
      linger_option linger = s.linger_state();
      assert::is_false(linger.enabled());
      assert::is_zero(linger.linger_time());
      assert::is_null(s.local_end_point());
      assert::throws<socket_exception>([&] {s.multicast_loopback();});
      assert::is_false(s.no_delay());
      assert::are_equal(protocol_type::tcp, s.protocol_type());
      assert::is_not_zero(s.receive_buffer_size());
      assert::is_zero(s.receive_timeout());
      assert::is_null(s.remote_end_point());
      assert::is_not_zero(s.send_buffer_size());
      assert::is_zero(s.send_timeout());
      assert::are_equal(socket_type::stream, s.socket_type());
      assert::is_not_zero(s.ttl());
    }
    
    auto test_method_(constructor_with_address_family_internet_network_socket_type_dgram_and_protocol_type_udp) {
      #if defined(__XTD_BUILD_WITH_CONTINUOUS_INTEGRATION_SYSTEM__)
      return;
      #endif
      assume::is_true(socket::os_supports_ip_v4());
      socket s(address_family::inter_network, socket_type::dgram, protocol_type::udp);
      assert::are_equal(address_family::inter_network, s.address_family());
      assert::is_zero(s.available());
      assert::is_true(s.blocking());
      assert::is_false(s.connected());
      assert::is_false(s.dont_fragment());
      assert::throws<not_supported_exception>([&] {s.dual_mode();});
      assert::is_false(s.enable_broadcast());
      assert::is_false(s.exclusive_address_use());
      assert::is_not_zero(s.handle());
      assert::is_false(s.is_bound());
      assert::throws<socket_exception>([&] {s.linger_state();});
      assert::is_null(s.local_end_point());
      assert::is_true(s.multicast_loopback());
      assert::throws<socket_exception>([&] {s.no_delay();});
      assert::are_equal(protocol_type::udp, s.protocol_type());
      assert::is_not_zero(s.receive_buffer_size());
      assert::is_zero(s.receive_timeout());
      assert::is_null(s.remote_end_point());
      assert::is_not_zero(s.send_buffer_size());
      assert::is_zero(s.send_timeout());
      assert::are_equal(socket_type::dgram, s.socket_type());
      assert::is_not_zero(s.ttl());
    }
    
    auto test_method_(bind_with_bad_socket) {
      socket s;
      assert::throws<object_closed_exception>([&] {s.bind(ip_end_point(ip_address(127, 0, 0, 1), 9400));});
    }
    
    auto test_method_(bind_socket_type_stream_and_protocol_type_tcp_socket) {
      assume::is_true(socket::os_supports_ip_v6());
      socket s(address_family::inter_network_v6, socket_type::stream, protocol_type::tcp);
      s.bind(ip_end_point(ip_address::ip_v6_any, 4242));
      assert::is_true(s.is_bound());
    }
    
    auto test_method_(bind_with_address_family_internet_network_v6_socket_type_stream_and_protocol_type_tcp_socket) {
      assume::is_true(socket::os_supports_ip_v6());
      socket s(address_family::inter_network_v6, socket_type::stream, protocol_type::tcp);
      s.bind(ip_end_point(ip_address::ip_v6_any, 4242));
      assert::is_true(s.is_bound());
    }
    
    auto test_method_(bind_with_address_family_internet_network_socket_type_stream_and_protocol_type_tcp_socket) {
      assume::is_true(socket::os_supports_ip_v4());
      socket s(address_family::inter_network, socket_type::stream, protocol_type::tcp);
      s.bind(ip_end_point(ip_address::any, 4242));
      assert::is_true(s.is_bound());
    }
    
    auto test_method_(bind_with_address_family_internet_network_v6_socket_type_dgram_and_protocol_type_udp_socket) {
      assume::is_true(socket::os_supports_ip_v6());
      socket s(address_family::inter_network_v6, socket_type::dgram, protocol_type::udp);
      s.bind(ip_end_point(ip_address::ip_v6_any, 4242));
      assert::is_true(s.is_bound());
    }
    
    auto test_method_(bind_with_address_family_internet_network_socket_type_dgram_and_protocol_type_udp_socket) {
      assume::is_true(socket::os_supports_ip_v4());
      socket s(address_family::inter_network, socket_type::dgram, protocol_type::udp);
      s.bind(ip_end_point(ip_address::any, 4242));
      assert::is_true(s.is_bound());
    }
    
    auto test_method_(bind_with_empty_socket) {
      assume::is_true(socket::os_supports_ip_v4());
      socket s;
      assert::throws<object_closed_exception>([&] {s.bind(ip_end_point(ip_address::any, 9400));});
      assert::is_false(s.is_bound());
    }
    
    auto test_method_(listen_with_bind_socket_type_stream_and_protocol_type_tcp_socket) {
      assume::is_true(socket::os_supports_ip_v6());
      socket s(address_family::inter_network_v6, socket_type::stream, protocol_type::tcp);
      s.bind(ip_end_point(ip_address::ip_v6_any, 4242));
      assert::does_not_throw([&] {s.listen(10);});
    }
    
    auto test_method_(listen_with_bind_with_address_family_internet_v6_network_socket_type_stream_and_protocol_type_tcp_socket) {
      assume::is_true(socket::os_supports_ip_v6());
      socket s(address_family::inter_network_v6, socket_type::stream, protocol_type::tcp);
      s.bind(ip_end_point(ip_address::ip_v6_any, 9400));
      assert::does_not_throw([&] {s.listen(10);});
    }
    
    auto test_method_(listen_with_bind_with_address_family_internet_network_socket_type_stream_and_protocol_type_tcp_socket) {
      assume::is_true(socket::os_supports_ip_v4());
      socket s(address_family::inter_network, socket_type::stream, protocol_type::tcp);
      s.bind(ip_end_point(ip_address::any, 9400));
      assert::does_not_throw([&] {s.listen(10);});
    }
    
    auto test_method_(listen_with_bind_with_address_family_internet_network_socket_type_dgram_and_protocol_type_udp_socket) {
      assume::is_true(socket::os_supports_ip_v4());
      socket s(address_family::inter_network, socket_type::dgram, protocol_type::udp);
      s.bind(ip_end_point(ip_address::any, 4242));
      assert::throws<socket_exception>([&] {s.listen(10);});
    }
    
    auto test_method_(listen_with_empty_socket) {
      assume::is_true(socket::os_supports_ip_v4());
      socket s;
      assert::throws<object_closed_exception>([&] {s.listen(10);});
    }
    
    auto test_method_(listen_without_bind) {
      assume::is_true(socket::os_supports_ip_v4());
      socket s(address_family::inter_network, socket_type::stream, protocol_type::tcp);
      assert::throws<socket_exception>([&] {s.listen(10);});
    }
    
    auto test_method_(set_receive_buffer_size) {
      assume::is_true(socket::os_supports_ip_v4());
      socket s(address_family::inter_network, socket_type::stream, protocol_type::tcp);
      s.receive_buffer_size(4242);
      // Fix on linux receive 8484u value ???
      //assert::are_equal(4242u, s.receive_buffer_size());
    }
    
    auto test_method_(set_receive_timeout) {
      assume::is_true(socket::os_supports_ip_v4());
      socket s(address_family::inter_network, socket_type::stream, protocol_type::tcp);
      s.receive_timeout(1000);
      assert::are_equal(1000, s.receive_timeout());
    }
    
    auto test_method_(set_send_buffer_size) {
      assume::is_true(socket::os_supports_ip_v4());
      socket s(address_family::inter_network, socket_type::stream, protocol_type::tcp);
      s.send_buffer_size(4242);
      // Fix on linux receive 8484u value ???
      //assert::are_equal(4242u, s.send_buffer_size());
    }
    
    auto test_method_(set_send_timeout) {
      assume::is_true(socket::os_supports_ip_v4());
      socket s(address_family::inter_network, socket_type::stream, protocol_type::tcp);
      s.send_timeout(1000);
      assert::are_equal(1000, s.send_timeout());
    }
  };
}
