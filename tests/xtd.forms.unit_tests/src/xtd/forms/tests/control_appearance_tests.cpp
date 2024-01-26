#include <xtd/forms/control_appearance.h>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(control_appearance_tests) {
  public:
    void test_method_(standard) {
      assert::are_equal(0, enum_object<>::to_int32(control_appearance::standard), csf_);
      assert::are_equal("standard", enum_object<>::to_string(control_appearance::standard), csf_);
      assert::are_equal(control_appearance::standard, enum_object<>::parse<control_appearance>("standard"), csf_);
    }
    
    void test_method_(system) {
      assert::are_equal(1, enum_object<>::to_int32(control_appearance::system), csf_);
      assert::are_equal("system", enum_object<>::to_string(control_appearance::system), csf_);
      assert::are_equal(control_appearance::system, enum_object<>::parse<control_appearance>("system"), csf_);
    }
  };
}

