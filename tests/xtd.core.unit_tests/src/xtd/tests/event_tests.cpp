#include <xtd/event>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(event_tests) {
    class test_object : public object {
    public:
      event<test_object, event_handler> updated;
      
      void update() {
        updated(*this, event_args::empty);
      }
      
    };
  public:
    void test_method_(add_event) {
      auto c = 0;
      auto l = [&](const object & sender, const event_args & e) {++c;};
      auto o = test_object {};
      o.updated += l;
      assert::is_zero(c, csf_);
    }
    
    void test_method_(add_event_and_invoke_it) {
      auto c = 0;
      auto l = [&](const object & sender, const event_args & e) {++c;};
      auto o = test_object {};
      o.updated += l;
      o.update();
      assert::are_equal(1, c, csf_);
      o.update();
      o.update();
      o.update();
      o.update();
      assert::are_equal(5, c, csf_);
    }
    
    void test_method_(add_event_with_auto_argument) {
      auto c = 0;
      auto l = [&](auto sender, auto e) {++c;};
      auto o = test_object {};
      o.updated += l;
      assert::is_zero(c, csf_);
    }
    
    void test_method_(add_event_with_auto_argument_and_invoke_it) {
      auto c = 0;
      auto l = [&](auto sender, auto e) {++c;};
      auto o = test_object {};
      o.updated += l;
      o.update();
      assert::are_equal(1, c, csf_);
      o.update();
      o.update();
      o.update();
      o.update();
      assert::are_equal(5, c, csf_);
    }
    
    void test_method_(add_event_without_argument) {
      auto c = 0;
      auto l = [&] {++c;};
      auto o = test_object {};
      o.updated += l;
      assert::is_zero(c, csf_);
    }
    
    void test_method_(add_event_without_argument_and_invoke_it) {
      auto c = 0;
      auto l = [&] {++c;};
      auto o = test_object {};
      o.updated += l;
      o.update();
      assert::are_equal(1, c, csf_);
      o.update();
      o.update();
      o.update();
      o.update();
      assert::are_equal(5, c, csf_);
    }
  };
}
