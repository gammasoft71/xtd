#include <xtd/net/sockets/socket_shutdown>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::net::sockets;
using namespace xtd::tunit;

namespace xtd::net::sockets::tests {
  class test_class_(socket_shutdown_tests) {
    auto test_method_(receive) {
      assert::are_equal(0, enum_object<>::to_int32(socket_shutdown::receive));
      assert::are_equal("receive", enum_object<>::to_string(socket_shutdown::receive));
      assert::are_equal(socket_shutdown::receive, enum_object<>::parse<socket_shutdown>("receive"));
    }
    
    auto test_method_(send) {
      assert::are_equal(1, enum_object<>::to_int32(socket_shutdown::send));
      assert::are_equal("send", enum_object<>::to_string(socket_shutdown::send));
      assert::are_equal(socket_shutdown::send, enum_object<>::parse<socket_shutdown>("send"));
    }
    
    auto test_method_(both) {
      assert::are_equal(2, enum_object<>::to_int32(socket_shutdown::both));
      assert::are_equal("both", enum_object<>::to_string(socket_shutdown::both));
      assert::are_equal(socket_shutdown::both, enum_object<>::parse<socket_shutdown>("both"));
    }
  };
}
