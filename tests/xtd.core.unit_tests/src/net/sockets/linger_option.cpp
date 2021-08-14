#include <xtd/net/sockets/linger_option.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_linger_option) {
  public:
    void test_method_(default_constructor) {
      linger_option linger;
      assert::is_false(linger.enabled(), line_info_);
      assert::is_zero(linger.linger_time(), line_info_);
    }

    void test_method_(constructor_wtih_enabled_and_linger_time) {
      linger_option linger(true, 5);
      assert::is_true(linger.enabled(), line_info_);
      assert::are_equal(5U, linger.linger_time(), line_info_);
    }
    
    void test_method_(set_enabled) {
      linger_option linger;
      linger.enabled(true);
      assert::is_true(linger.enabled(), line_info_);
      assert::is_zero(linger.linger_time(), line_info_);
    }
    
    void test_method_(set_linger_time) {
      linger_option linger;
      linger.linger_time(5);
      assert::is_false(linger.enabled(), line_info_);
      assert::are_equal(5U, linger.linger_time(), line_info_);
    }
  };
}
