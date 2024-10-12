#include <xtd/collections/generic/key_not_found_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::tunit;

namespace xtd::collections::tests {
  class test_class_(key_not_found_exception_tests) {
    inline static bool stack_trace_enabled = false;
    inline static std::locale previous_locale;
    static void test_initialize_(test_initialize) {
      previous_locale = std::locale::global(std::locale("en_US.UTF-8"));
      stack_trace_enabled = system_exception::enable_stack_trace();
      system_exception::enable_stack_trace(false);
    }
    
    static void test_cleanup_(test_cleanup) {
      std::locale::global(previous_locale);
      system_exception::enable_stack_trace(stack_trace_enabled);
    }
  };
}
