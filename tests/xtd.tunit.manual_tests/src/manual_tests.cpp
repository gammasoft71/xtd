#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include <xtd/tunit/tunit_main>
#include <xtd/startup>

namespace xtd {
  namespace tunit {
    namespace constraints {
      class is : public xtd::object {
      public:
      
      };
    }
    
    class assert2 : public base_assert {
      /// @cond
      assert2() = delete;
      /// @endcond
      
    public:
      void that(bool condition) {assert::is_true(condition);}
      void that(bool condition, const xtd::diagnostics::stack_frame& stack_frame) {assert::is_true(condition, stack_frame);}
      void that(bool condition, const xtd::ustring& message) {assert::is_true(condition, message);}
      void that(bool condition, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {assert::is_true(condition, message, stack_frame);}
      
      template<typename ...args_t>
      void that(bool condition, const xtd::ustring& message, args_t... args) {
        assert::is_true(condition, ustring::format(message, args...));
      }
      
      template <typename actual_t>
      void that(actual_t condition) {
      
      }
    };
  }
}

using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(manual_test_tunit) {
  public:
    void test_method_(test_case1) {
      //assert::are_equal(42, 0x2A, csf_);
      assert::abort(csf_);
    }
  };
}

startup_(tunit_main_);
