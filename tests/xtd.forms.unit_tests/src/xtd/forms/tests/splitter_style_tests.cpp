#include <xtd/forms/splitter_style>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(splitter_style_tests) {
  public:
    void test_method_(draw_line) {
      assert::are_equal(0, enum_object<>::to_int32(splitter_style::draw_line), csf_);
      assert::are_equal("draw_line", enum_object<>::to_string(splitter_style::draw_line), csf_);
      assert::are_equal(splitter_style::draw_line, enum_object<>::parse<splitter_style>("draw_line"), csf_);
    }
    
    void test_method_(update_children) {
      assert::are_equal(1, enum_object<>::to_int32(splitter_style::update_children), csf_);
      assert::are_equal("update_children", enum_object<>::to_string(splitter_style::update_children), csf_);
      assert::are_equal(splitter_style::update_children, enum_object<>::parse<splitter_style>("update_children"), csf_);
    }
  };
}
