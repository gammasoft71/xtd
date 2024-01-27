#include <xtd/forms/input_box_style.h>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(input_box_style_tests) {
  public:
    void test_method_(normal) {
      assert::are_equal(0, enum_object<>::to_int32(input_box_style::normal), csf_);
      assert::are_equal("normal", enum_object<>::to_string(input_box_style::normal), csf_);
      assert::are_equal(input_box_style::normal, enum_object<>::parse<input_box_style>("normal"), csf_);
    }
    
    void test_method_(multiline) {
      assert::are_equal(1, enum_object<>::to_int32(input_box_style::multiline), csf_);
      assert::are_equal("multiline", enum_object<>::to_string(input_box_style::multiline), csf_);
      assert::are_equal(input_box_style::multiline, enum_object<>::parse<input_box_style>("multiline"), csf_);
    }
    
    void test_method_(password) {
      assert::are_equal(2, enum_object<>::to_int32(input_box_style::password), csf_);
      assert::are_equal("password", enum_object<>::to_string(input_box_style::password), csf_);
      assert::are_equal(input_box_style::password, enum_object<>::parse<input_box_style>("password"), csf_);
    }
  };
}

