#include <xtd/net/sockets/socket_information.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_socket_information) {
  public:
    void test_method_(default_constructor) {
      socket_information si;
      assert::are_equal(socket_information_options::none, si.options(), csf_);
      assert::is_empty(si.protocol_information(), csf_);
    }

    void test_method_(set_options) {
      socket_information si;
      si.options(socket_information_options::connected|socket_information_options::listening);
      assert::are_equal(socket_information_options::connected|socket_information_options::listening, si.options(), csf_);
      assert::is_empty(si.protocol_information(), csf_);
    }

    void test_method_(set_protocol_information) {
      socket_information si;
      si.protocol_information({1, 2, 3, 4, 5});
      assert::are_equal(socket_information_options::none, si.options(), csf_);
      collection_assert::are_equal({1U, 2U, 3U, 4U, 5U}, si.protocol_information(), csf_);
    }
  };
}
