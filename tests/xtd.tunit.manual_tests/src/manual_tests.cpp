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
      void that(bool condition, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {assert::is_true(condition, stack_frame);}
      void that(bool condition, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {assert::is_true(condition, message, stack_frame);}
      
      template<class ...args_t>
      void that(bool condition, const xtd::string& message, args_t... args) {
        assert::is_true(condition, string::format(message, args...));
      }
      
      template<class actual_t>
      void that(actual_t condition) {
      
      }
    };
  }
}

using namespace xtd::tunit;

namespace xtd::tunit::tests {
  class test_class_(manual_test_tunit) {
  public:
    auto test_method_(test_method1) {
      assert::is_true(true);
    }
  };
}

startup_(tunit_main_);
