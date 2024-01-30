#include <xtd/forms/lcd_style>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(lcd_style_tests) {
  public:
    void test_method_(seven_segment_display) {
      assert::are_equal(0, enum_object<>::to_int32(lcd_style::seven_segment_display), csf_);
      assert::are_equal("seven_segment_display", enum_object<>::to_string(lcd_style::seven_segment_display), csf_);
      assert::are_equal(lcd_style::seven_segment_display, enum_object<>::parse<lcd_style>("seven_segment_display"), csf_);
    }
    
    void test_method_(nine_segment_display) {
      assert::are_equal(1, enum_object<>::to_int32(lcd_style::nine_segment_display), csf_);
      assert::are_equal("nine_segment_display", enum_object<>::to_string(lcd_style::nine_segment_display), csf_);
      assert::are_equal(lcd_style::nine_segment_display, enum_object<>::parse<lcd_style>("nine_segment_display"), csf_);
    }
    
    void test_method_(fourteen_segment_display) {
      assert::are_equal(2, enum_object<>::to_int32(lcd_style::fourteen_segment_display), csf_);
      assert::are_equal("fourteen_segment_display", enum_object<>::to_string(lcd_style::fourteen_segment_display), csf_);
      assert::are_equal(lcd_style::fourteen_segment_display, enum_object<>::parse<lcd_style>("fourteen_segment_display"), csf_);
    }
    
    void test_method_(sixteen_segment_display) {
      assert::are_equal(3, enum_object<>::to_int32(lcd_style::sixteen_segment_display), csf_);
      assert::are_equal("sixteen_segment_display", enum_object<>::to_string(lcd_style::sixteen_segment_display), csf_);
      assert::are_equal(lcd_style::sixteen_segment_display, enum_object<>::parse<lcd_style>("sixteen_segment_display"), csf_);
    }
    
    void test_method_(dot_matrix_display) {
      assert::are_equal(4, enum_object<>::to_int32(lcd_style::dot_matrix_display), csf_);
      assert::are_equal("dot_matrix_display", enum_object<>::to_string(lcd_style::dot_matrix_display), csf_);
      assert::are_equal(lcd_style::dot_matrix_display, enum_object<>::parse<lcd_style>("dot_matrix_display"), csf_);
    }
  };
}
