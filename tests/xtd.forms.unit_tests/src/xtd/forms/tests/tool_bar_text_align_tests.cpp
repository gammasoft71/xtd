#include <xtd/forms/tool_bar_text_align>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(tool_bar_text_align_tests) {
  public:
    void test_method_(underneath) {
      assert::are_equal(0, enum_object<>::to_int32(tool_bar_text_align::underneath), csf_);
      assert::are_equal("underneath", enum_object<>::to_string(tool_bar_text_align::underneath), csf_);
      assert::are_equal(tool_bar_text_align::underneath, enum_object<>::parse<tool_bar_text_align>("underneath"), csf_);
    }
    
    void test_method_(right) {
      assert::are_equal(1, enum_object<>::to_int32(tool_bar_text_align::right), csf_);
      assert::are_equal("right", enum_object<>::to_string(tool_bar_text_align::right), csf_);
      assert::are_equal(tool_bar_text_align::right, enum_object<>::parse<tool_bar_text_align>("right"), csf_);
    }
  };
}
