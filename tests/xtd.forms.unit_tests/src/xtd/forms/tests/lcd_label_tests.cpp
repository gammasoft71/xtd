#include <xtd/forms/lcd_label>
#include <xtd/forms/form>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(lcd_label_tests) {
    void test_method_(new_lcd_label) {
      form form;
      lcd_label label;
      label.parent(form);
      assert::are_equal(drawing::size(100, 25),  label.size());
    }
    
    void test_method_(new_lcd_label_adn_add_to_form) {
      form form;
      lcd_label label;
      label.parent(form);
      assert::are_equal(drawing::size(100, 25),  label.size());
    }
    
    void test_method_(lcd_label_auto_size_with_one_char) {
      form form;
      lcd_label label;
      label.parent(form);
      label.auto_size(true);
      label.text("0");
      assert::are_equal(drawing::size(13, 25),  label.size());
    }
    
    void test_method_(lcd_label_auto_size_with_default_spacing_with_2_chars) {
      form form;
      lcd_label label;
      label.parent(form);
      label.auto_size(true);
      label.text("00");
      assert::are_equal(drawing::size(27, 25),  label.size());
    }
    
    void test_method_(lcd_label_auto_size_with_default_spacing_with_3_chars) {
      form form;
      lcd_label label;
      label.parent(form);
      label.auto_size(true);
      label.text("000");
      assert::are_equal(drawing::size(41, 25),  label.size());
    }
    
    void test_method_(lcd_label_auto_size_set_spacing_to_8_with_2_chars) {
      form form;
      lcd_label label;
      label.parent(form);
      label.auto_size(true);
      label.digit_spacing(8);
      label.text("00");
      assert::are_equal(drawing::size(32, 25),  label.size());
    }
    
    void test_method_(lcd_label_auto_size_set_spacing_to_8_with_3_chars) {
      form form;
      lcd_label label;
      label.parent(form);
      label.auto_size(true);
      label.digit_spacing(8);
      label.text("000");
      assert::are_equal(drawing::size(51, 25),  label.size());
    }
    
    void test_method_(lcd_label_auto_size_with_default_spacing_with_5_chars_and_height_to_203) {
      form form;
      lcd_label label;
      label.parent(form);
      label.auto_size(true);
      label.height(203);
      label.text("00000");
      assert::are_equal(drawing::size(586, 203),  label.size());
    }
    
    void test_method_(lcd_label_auto_size_set_spacing_to_10_with_5_chars_and_height_to_203) {
      form form;
      lcd_label label;
      label.parent(form);
      label.digit_spacing(10);
      label.height(203);
      label.auto_size(true);
      label.text("0.001");
      assert::are_equal(drawing::size(542, 203),  label.size());
    }
    
    void test_method_(lcd_label_auto_size_with_default_spacing_with_11_chars) {
      form form;
      lcd_label label;
      label.parent(form);
      label.auto_size(true);
      label.text("12345678.90");
      assert::are_equal(drawing::size(153, 25),  label.size());
    }
  };
}
