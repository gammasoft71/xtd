#include <xtd/event_args>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(event_args_tests) {
    class test_event_args : public event_args {
    public:
      test_event_args() = default;
      test_event_args(int32 args) : args_(args) {}
      test_event_args(test_event_args&&) = default;
      test_event_args(const test_event_args&) = default;
      test_event_args& operator=(const test_event_args&) = default;
      
      int32 args() const {return args_;}
      test_event_args& args(int32 value) {
        args_ = value;
        return *this;
      }
    private:
      int32 args_ = 0;
    };
    
    void test_method_(event_args_ctor) {
      assert::does_not_throw([] {event_args {};}, csf_);
    }
    
    void test_method_(event_args_copy) {
      event_args e1;
      assert::does_not_throw([&] {auto e2 = e1;}, csf_);
    }
    
    void test_method_(event_args_using) {
      auto m_executed = false;
      auto m = [&](const event_args & e) {
        m_executed = true;
      };
      
      assert::is_false(m_executed, csf_);
      m(event_args {});
      assert::is_true(m_executed, csf_);
    }
    
    void test_method_(event_args_using_empty) {
      auto m_executed = false;
      auto m = [&](const event_args & e) {
        m_executed = true;
      };
      
      assert::is_false(m_executed, csf_);
      m(event_args::empty);
      assert::is_true(m_executed, csf_);
    }
    
    void test_method_(event_args_copy_with_empty) {
      assert::does_not_throw([&] {auto e = event_args::empty;}, csf_);
    }
    
    void test_method_(test_event_args_ctor) {
      test_event_args e{};
      assert::is_zero(e.args(), csf_);
    }
    
    void test_method_(test_event_args_ctor_with_args) {
      test_event_args e{42};
      assert::are_equal(42, e.args(), csf_);
    }
    
    void test_method_(test_event_args_copy) {
      test_event_args e1;
      auto e2 = e1;
      assert::is_zero(e2.args(), csf_);
    }
    
    void test_method_(test_event_args_copy_with_args) {
      test_event_args e1 {42};
      auto e2 = e1;
      assert::are_equal(42, e2.args(), csf_);
    }
  };
}
