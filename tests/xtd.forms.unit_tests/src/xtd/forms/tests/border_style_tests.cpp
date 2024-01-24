#include <xtd/forms/border_style.h>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(border_style_tests) {
  public:
    void test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(border_style::none), csf_);
      assert::are_equal("none", enum_object<>::to_string(border_style::none), csf_);
      assert::are_equal(border_style::none, enum_object<>::parse<border_style>("none"), csf_);
    }
    
    void test_method_(hidden) {
      assert::are_equal(0, enum_object<>::to_int32(border_style::hidden), csf_);
      assert::are_equal("none", enum_object<>::to_string(border_style::hidden), csf_);
      assert::are_equal(border_style::hidden, enum_object<>::parse<border_style>("none"), csf_);
    }
    
    void test_method_(fixed_single) {
      assert::are_equal(1, enum_object<>::to_int32(border_style::fixed_single), csf_);
      assert::are_equal("fixed_single", enum_object<>::to_string(border_style::fixed_single), csf_);
      assert::are_equal(border_style::fixed_single, enum_object<>::parse<border_style>("fixed_single"), csf_);
    }
    
    void test_method_(fixed_3d) {
      assert::are_equal(2, enum_object<>::to_int32(border_style::fixed_3d), csf_);
      assert::are_equal("fixed_3d", enum_object<>::to_string(border_style::fixed_3d), csf_);
      assert::are_equal(border_style::fixed_3d, enum_object<>::parse<border_style>("fixed_3d"), csf_);
    }
    
    void test_method_(solid) {
      assert::are_equal(1, enum_object<>::to_int32(border_style::solid), csf_);
      assert::are_equal("fixed_single", enum_object<>::to_string(border_style::solid), csf_);
      assert::are_equal(border_style::solid, enum_object<>::parse<border_style>("fixed_single"), csf_);
    }
    
    void test_method_(inset) {
      assert::are_equal(2, enum_object<>::to_int32(border_style::inset), csf_);
      assert::are_equal("fixed_3d", enum_object<>::to_string(border_style::inset), csf_);
      assert::are_equal(border_style::inset, enum_object<>::parse<border_style>("fixed_3d"), csf_);
    }
    
    void test_method_(outset) {
      assert::are_equal(3, enum_object<>::to_int32(border_style::outset), csf_);
      assert::are_equal("outset", enum_object<>::to_string(border_style::outset), csf_);
      assert::are_equal(border_style::outset, enum_object<>::parse<border_style>("outset"), csf_);
    }
    
    void test_method_(groove) {
      assert::are_equal(4, enum_object<>::to_int32(border_style::groove), csf_);
      assert::are_equal("groove", enum_object<>::to_string(border_style::groove), csf_);
      assert::are_equal(border_style::groove, enum_object<>::parse<border_style>("groove"), csf_);
    }
    
    void test_method_(ridge) {
      assert::are_equal(5, enum_object<>::to_int32(border_style::ridge), csf_);
      assert::are_equal("ridge", enum_object<>::to_string(border_style::ridge), csf_);
      assert::are_equal(border_style::ridge, enum_object<>::parse<border_style>("ridge"), csf_);
    }
    
    void test_method_(theme) {
      assert::are_equal(6, enum_object<>::to_int32(border_style::theme), csf_);
      assert::are_equal("theme", enum_object<>::to_string(border_style::theme), csf_);
      assert::are_equal(border_style::theme, enum_object<>::parse<border_style>("theme"), csf_);
    }
    
    void test_method_(dashed) {
      assert::are_equal(7, enum_object<>::to_int32(border_style::dashed), csf_);
      assert::are_equal("dashed", enum_object<>::to_string(border_style::dashed), csf_);
      assert::are_equal(border_style::dashed, enum_object<>::parse<border_style>("dashed"), csf_);
    }
    
    void test_method_(dot_dash) {
      assert::are_equal(8, enum_object<>::to_int32(border_style::dot_dash), csf_);
      assert::are_equal("dot_dash", enum_object<>::to_string(border_style::dot_dash), csf_);
      assert::are_equal(border_style::dot_dash, enum_object<>::parse<border_style>("dot_dash"), csf_);
    }
    
    void test_method_(dot_dot_dash) {
      assert::are_equal(9, enum_object<>::to_int32(border_style::dot_dot_dash), csf_);
      assert::are_equal("dot_dot_dash", enum_object<>::to_string(border_style::dot_dot_dash), csf_);
      assert::are_equal(border_style::dot_dot_dash, enum_object<>::parse<border_style>("dot_dot_dash"), csf_);
    }
    
    void test_method_(dotted) {
      assert::are_equal(10, enum_object<>::to_int32(border_style::dotted), csf_);
      assert::are_equal("dotted", enum_object<>::to_string(border_style::dotted), csf_);
      assert::are_equal(border_style::dotted, enum_object<>::parse<border_style>("dotted"), csf_);
    }
    
    void test_method_(double_border) {
      assert::are_equal(11, enum_object<>::to_int32(border_style::double_border), csf_);
      assert::are_equal("double_border", enum_object<>::to_string(border_style::double_border), csf_);
      assert::are_equal(border_style::double_border, enum_object<>::parse<border_style>("double_border"), csf_);
    }
    
    void test_method_(bevel_inset) {
      assert::are_equal(12, enum_object<>::to_int32(border_style::bevel_inset), csf_);
      assert::are_equal("bevel_inset", enum_object<>::to_string(border_style::bevel_inset), csf_);
      assert::are_equal(border_style::bevel_inset, enum_object<>::parse<border_style>("bevel_inset"), csf_);
    }
    
    void test_method_(bevel_outset) {
      assert::are_equal(13, enum_object<>::to_int32(border_style::bevel_outset), csf_);
      assert::are_equal("bevel_outset", enum_object<>::to_string(border_style::bevel_outset), csf_);
      assert::are_equal(border_style::bevel_outset, enum_object<>::parse<border_style>("bevel_outset"), csf_);
    }
    
    void test_method_(rounded) {
      assert::are_equal(14, enum_object<>::to_int32(border_style::rounded), csf_);
      assert::are_equal("rounded", enum_object<>::to_string(border_style::rounded), csf_);
      assert::are_equal(border_style::rounded, enum_object<>::parse<border_style>("rounded"), csf_);
    }
  };
}

