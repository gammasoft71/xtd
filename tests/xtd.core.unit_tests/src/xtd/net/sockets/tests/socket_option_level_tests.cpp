#include <xtd/net/sockets/socket_option_level>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::net::sockets;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(socket_option_level_tests) {
  public:
    void test_method_(socket) {
      assert::are_equal(65535, enum_object<>::to_int32(socket_option_level::socket), csf_);
      assert::are_equal("socket", enum_object<>::to_string(socket_option_level::socket), csf_);
      assert::are_equal(socket_option_level::socket, enum_object<>::parse<socket_option_level>("socket"), csf_);
    }
    
    void test_method_(ip) {
      assert::are_equal(0, enum_object<>::to_int32(socket_option_level::ip), csf_);
      assert::are_equal("ip", enum_object<>::to_string(socket_option_level::ip), csf_);
      assert::are_equal(socket_option_level::ip, enum_object<>::parse<socket_option_level>("ip"), csf_);
    }
    
    void test_method_(ip_v6) {
      assert::are_equal(41, enum_object<>::to_int32(socket_option_level::ip_v6), csf_);
      assert::are_equal("ip_v6", enum_object<>::to_string(socket_option_level::ip_v6), csf_);
      assert::are_equal(socket_option_level::ip_v6, enum_object<>::parse<socket_option_level>("ip_v6"), csf_);
    }
    
    void test_method_(tcp) {
      assert::are_equal(6, enum_object<>::to_int32(socket_option_level::tcp), csf_);
      assert::are_equal("tcp", enum_object<>::to_string(socket_option_level::tcp), csf_);
      assert::are_equal(socket_option_level::tcp, enum_object<>::parse<socket_option_level>("tcp"), csf_);
    }
    
    void test_method_(udp) {
      assert::are_equal(17, enum_object<>::to_int32(socket_option_level::udp), csf_);
      assert::are_equal("udp", enum_object<>::to_string(socket_option_level::udp), csf_);
      assert::are_equal(socket_option_level::udp, enum_object<>::parse<socket_option_level>("udp"), csf_);
    }
  };
}
