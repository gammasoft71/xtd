#include <xtd/net/sockets/linger_option>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;
using namespace xtd::tunit;

namespace xtd::net::sockets::tests {
  class test_class_(linger_option_tests) {
    void test_method_(default_constructor) {
      linger_option linger;
      assert::is_false(linger.enabled());
      assert::is_zero(linger.linger_time());
    }
    
    void test_method_(constructor_wtih_enabled_and_linger_time) {
      linger_option linger(true, 5);
      assert::is_true(linger.enabled());
      assert::are_equal(5u, linger.linger_time());
    }
    
    void test_method_(set_enabled) {
      linger_option linger;
      linger.enabled(true);
      assert::is_true(linger.enabled());
      assert::is_zero(linger.linger_time());
    }
    
    void test_method_(set_linger_time) {
      linger_option linger;
      linger.linger_time(5);
      assert::is_false(linger.enabled());
      assert::are_equal(5u, linger.linger_time());
    }
  };
}
