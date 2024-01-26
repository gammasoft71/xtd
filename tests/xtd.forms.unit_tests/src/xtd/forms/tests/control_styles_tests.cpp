#include <xtd/forms/control_styles.h>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(control_styles_tests) {
  public:
    void test_method_(container_control) {
      assert::are_equal(1, enum_object<>::to_int32(control_styles::container_control), csf_);
      assert::are_equal("container_control", enum_object<>::to_string(control_styles::container_control), csf_);
      assert::are_equal(control_styles::container_control, enum_object<>::parse<control_styles>("container_control"), csf_);
    }
    
    void test_method_(user_paint) {
      assert::are_equal(2, enum_object<>::to_int32(control_styles::user_paint), csf_);
      assert::are_equal("user_paint", enum_object<>::to_string(control_styles::user_paint), csf_);
      assert::are_equal(control_styles::user_paint, enum_object<>::parse<control_styles>("user_paint"), csf_);
    }
    
    void test_method_(opaque) {
      assert::are_equal(4, enum_object<>::to_int32(control_styles::opaque), csf_);
      assert::are_equal("opaque", enum_object<>::to_string(control_styles::opaque), csf_);
      assert::are_equal(control_styles::opaque, enum_object<>::parse<control_styles>("opaque"), csf_);
    }
    
    void test_method_(resize_redraw) {
      assert::are_equal(16, enum_object<>::to_int32(control_styles::resize_redraw), csf_);
      assert::are_equal("resize_redraw", enum_object<>::to_string(control_styles::resize_redraw), csf_);
      assert::are_equal(control_styles::resize_redraw, enum_object<>::parse<control_styles>("resize_redraw"), csf_);
    }
    
    void test_method_(fixed_width) {
      assert::are_equal(32, enum_object<>::to_int32(control_styles::fixed_width), csf_);
      assert::are_equal("fixed_width", enum_object<>::to_string(control_styles::fixed_width), csf_);
      assert::are_equal(control_styles::fixed_width, enum_object<>::parse<control_styles>("fixed_width"), csf_);
    }
    
    void test_method_(fixed_height) {
      assert::are_equal(64, enum_object<>::to_int32(control_styles::fixed_height), csf_);
      assert::are_equal("fixed_height", enum_object<>::to_string(control_styles::fixed_height), csf_);
      assert::are_equal(control_styles::fixed_height, enum_object<>::parse<control_styles>("fixed_height"), csf_);
    }
    
    void test_method_(standard_click) {
      assert::are_equal(256, enum_object<>::to_int32(control_styles::standard_click), csf_);
      assert::are_equal("standard_click", enum_object<>::to_string(control_styles::standard_click), csf_);
      assert::are_equal(control_styles::standard_click, enum_object<>::parse<control_styles>("standard_click"), csf_);
    }
    
    void test_method_(selectable) {
      assert::are_equal(512, enum_object<>::to_int32(control_styles::selectable), csf_);
      assert::are_equal("selectable", enum_object<>::to_string(control_styles::selectable), csf_);
      assert::are_equal(control_styles::selectable, enum_object<>::parse<control_styles>("selectable"), csf_);
    }
    
    void test_method_(user_mouse) {
      assert::are_equal(1024, enum_object<>::to_int32(control_styles::user_mouse), csf_);
      assert::are_equal("user_mouse", enum_object<>::to_string(control_styles::user_mouse), csf_);
      assert::are_equal(control_styles::user_mouse, enum_object<>::parse<control_styles>("user_mouse"), csf_);
    }
    
    void test_method_(supports_transparent_back_color) {
      assert::are_equal(2048, enum_object<>::to_int32(control_styles::supports_transparent_back_color), csf_);
      assert::are_equal("supports_transparent_back_color", enum_object<>::to_string(control_styles::supports_transparent_back_color), csf_);
      assert::are_equal(control_styles::supports_transparent_back_color, enum_object<>::parse<control_styles>("supports_transparent_back_color"), csf_);
    }
    
    void test_method_(standard_double_click) {
      assert::are_equal(4096, enum_object<>::to_int32(control_styles::standard_double_click), csf_);
      assert::are_equal("standard_double_click", enum_object<>::to_string(control_styles::standard_double_click), csf_);
      assert::are_equal(control_styles::standard_double_click, enum_object<>::parse<control_styles>("standard_double_click"), csf_);
    }
    
    void test_method_(all_painting_in_wm_paint) {
      assert::are_equal(8192, enum_object<>::to_int32(control_styles::all_painting_in_wm_paint), csf_);
      assert::are_equal("all_painting_in_wm_paint", enum_object<>::to_string(control_styles::all_painting_in_wm_paint), csf_);
      assert::are_equal(control_styles::all_painting_in_wm_paint, enum_object<>::parse<control_styles>("all_painting_in_wm_paint"), csf_);
    }
    
    void test_method_(cache_text) {
      assert::are_equal(16384, enum_object<>::to_int32(control_styles::cache_text), csf_);
      assert::are_equal("cache_text", enum_object<>::to_string(control_styles::cache_text), csf_);
      assert::are_equal(control_styles::cache_text, enum_object<>::parse<control_styles>("cache_text"), csf_);
    }
    
    void test_method_(enable_notify_message) {
      assert::are_equal(32768, enum_object<>::to_int32(control_styles::enable_notify_message), csf_);
      assert::are_equal("enable_notify_message", enum_object<>::to_string(control_styles::enable_notify_message), csf_);
      assert::are_equal(control_styles::enable_notify_message, enum_object<>::parse<control_styles>("enable_notify_message"), csf_);
    }
    
    void test_method_(double_buffer) {
      assert::are_equal(65536, enum_object<>::to_int32(control_styles::double_buffer), csf_);
      assert::are_equal("double_buffer", enum_object<>::to_string(control_styles::double_buffer), csf_);
      assert::are_equal(control_styles::double_buffer, enum_object<>::parse<control_styles>("double_buffer"), csf_);
    }
    
    void test_method_(optimized_double_buffer) {
      assert::are_equal(131072, enum_object<>::to_int32(control_styles::optimized_double_buffer), csf_);
      assert::are_equal("optimized_double_buffer", enum_object<>::to_string(control_styles::optimized_double_buffer), csf_);
      assert::are_equal(control_styles::optimized_double_buffer, enum_object<>::parse<control_styles>("optimized_double_buffer"), csf_);
    }
    
    void test_method_(use_text_for_accessibility) {
      assert::are_equal(262144, enum_object<>::to_int32(control_styles::use_text_for_accessibility), csf_);
      assert::are_equal("use_text_for_accessibility", enum_object<>::to_string(control_styles::use_text_for_accessibility), csf_);
      assert::are_equal(control_styles::use_text_for_accessibility, enum_object<>::parse<control_styles>("use_text_for_accessibility"), csf_);
    }
  };
}

