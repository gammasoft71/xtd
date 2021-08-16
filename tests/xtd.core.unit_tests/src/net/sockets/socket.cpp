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
    }
  };
}
