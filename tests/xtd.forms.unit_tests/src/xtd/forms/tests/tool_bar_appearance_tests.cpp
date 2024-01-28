#include <xtd/forms/tool_bar_appearance>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(tool_bar_appearance_tests) {
  public:
    void test_method_(normal) {
      assert::are_equal(0, enum_object<>::to_int32(tool_bar_appearance::normal), csf_);
      assert::are_equal("normal", enum_object<>::to_string(tool_bar_appearance::normal), csf_);
      assert::are_equal(tool_bar_appearance::normal, enum_object<>::parse<tool_bar_appearance>("normal"), csf_);
    }
    
    void test_method_(flat) {
      assert::are_equal(1, enum_object<>::to_int32(tool_bar_appearance::flat), csf_);
      assert::are_equal("flat", enum_object<>::to_string(tool_bar_appearance::flat), csf_);
      assert::are_equal(tool_bar_appearance::flat, enum_object<>::parse<tool_bar_appearance>("flat"), csf_);
    }
    
    void test_method_(system) {
      assert::are_equal(2, enum_object<>::to_int32(tool_bar_appearance::system), csf_);
      assert::are_equal("system", enum_object<>::to_string(tool_bar_appearance::system), csf_);
      assert::are_equal(tool_bar_appearance::system, enum_object<>::parse<tool_bar_appearance>("system"), csf_);
    }
  };
}
