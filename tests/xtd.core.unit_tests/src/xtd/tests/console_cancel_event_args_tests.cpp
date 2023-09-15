#include <xtd/console_cancel_event_args>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(console_cancel_event_args_tests) {
  public:
    void test_method_(default_constructor) {
      auto ea = console_cancel_event_args();
      assert::is_false(ea.cancel(), csf_);
      assert::is_zero(ea.special_key(), csf_);
    }
    
    void test_method_(constructor_with_special_key_control_break) {
      auto ea = console_cancel_event_args(console_special_key::control_break);
      assert::is_false(ea.cancel(), csf_);
      assert::are_equal(console_special_key::control_break, ea.special_key(), csf_);
    }
    
    void test_method_(constructor_with_special_key_control_backslash) {
      auto ea = console_cancel_event_args(console_special_key::control_backslash);
      assert::is_false(ea.cancel(), csf_);
      assert::are_equal(console_special_key::control_backslash, ea.special_key(), csf_);
    }
    
    void test_method_(cancel) {
      auto ea = console_cancel_event_args(console_special_key::control_break);
      assert::is_false(ea.cancel(), csf_);
      ea.cancel(true);
      assert::is_true(ea.cancel(), csf_);
    }
  };
}
