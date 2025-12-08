#include <xtd/signal>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(signal_tests) {
    auto test_method_(abnormal_termination) {
      assert::are_equal(SIGABRT, enum_object<>::to_int32(signal::abnormal_termination));
      assert::are_equal("abnormal_termination", enum_object<>::to_string(signal::abnormal_termination));
      assert::are_equal(signal::abnormal_termination, enum_object<>::parse<signal>("abnormal_termination"));
    }
    
    auto test_method_(floating_point_exception) {
      assert::are_equal(SIGFPE, enum_object<>::to_int32(signal::floating_point_exception));
      assert::are_equal("floating_point_exception", enum_object<>::to_string(signal::floating_point_exception));
      assert::are_equal(signal::floating_point_exception, enum_object<>::parse<signal>("floating_point_exception"));
    }
    
    auto test_method_(illegal_instruction) {
      assert::are_equal(SIGILL, enum_object<>::to_int32(signal::illegal_instruction));
      assert::are_equal("illegal_instruction", enum_object<>::to_string(signal::illegal_instruction));
      assert::are_equal(signal::illegal_instruction, enum_object<>::parse<signal>("illegal_instruction"));
    }
    
    auto test_method_(interrupt) {
      assert::are_equal(SIGINT, enum_object<>::to_int32(signal::interrupt));
      assert::are_equal("interrupt", enum_object<>::to_string(signal::interrupt));
      assert::are_equal(signal::interrupt, enum_object<>::parse<signal>("interrupt"));
    }
    
    auto test_method_(segmentation_violation) {
      assert::are_equal(SIGSEGV, enum_object<>::to_int32(signal::segmentation_violation));
      assert::are_equal("segmentation_violation", enum_object<>::to_string(signal::segmentation_violation));
      assert::are_equal(signal::segmentation_violation, enum_object<>::parse<signal>("segmentation_violation"));
    }
    
    auto test_method_(software_termination) {
      assert::are_equal(SIGTERM, enum_object<>::to_int32(signal::software_termination));
      assert::are_equal("software_termination", enum_object<>::to_string(signal::software_termination));
      assert::are_equal(signal::software_termination, enum_object<>::parse<signal>("software_termination"));
    }
  };
}
