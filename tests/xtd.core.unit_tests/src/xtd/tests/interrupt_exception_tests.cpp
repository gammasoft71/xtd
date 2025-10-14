#include <xtd/interrupt_exception>
#include <xtd/globalization/culture_info>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(interrupt_exception_tests) {
    inline static bool stack_trace_enabled = false;
    inline static xtd::globalization::culture_info previous_culture;
    
    static void test_initialize_(test_initialize) {
      previous_culture = xtd::globalization::culture_info::current_culture();
      xtd::globalization::culture_info::current_culture(xtd::globalization::culture_info {"en-US"});
      stack_trace_enabled = interrupt_exception::enable_stack_trace();
      interrupt_exception::enable_stack_trace(false);
    }
    
    static void test_cleanup_(test_cleanup) {
      xtd::globalization::culture_info::current_culture(previous_culture);
      interrupt_exception::enable_stack_trace(stack_trace_enabled);
    }
  };
}
