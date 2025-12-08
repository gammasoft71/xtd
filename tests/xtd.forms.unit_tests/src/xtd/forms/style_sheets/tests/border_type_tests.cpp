#include <xtd/forms/style_sheets/border_type>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms::style_sheets;
using namespace xtd::tunit;

namespace xtd::forms::style_sheets::tests {
  class test_class_(border_type_tests) {
  public:
    auto test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(border_type::none));
      assert::are_equal("hidden", enum_object<>::to_string(border_type::none));
      assert::are_equal(border_type::none, enum_object<>::parse<border_type>("hidden"));
    }
    
    auto test_method_(hidden) {
      assert::are_equal(0, enum_object<>::to_int32(border_type::none));
      assert::are_equal("hidden", enum_object<>::to_string(border_type::none));
      assert::are_equal(border_type::none, enum_object<>::parse<border_type>("hidden"));
    }
    
    auto test_method_(solid) {
      assert::are_equal(1, enum_object<>::to_int32(border_type::solid));
      assert::are_equal("solid", enum_object<>::to_string(border_type::solid));
      assert::are_equal(border_type::solid, enum_object<>::parse<border_type>("solid"));
    }
    
    auto test_method_(inset) {
      assert::are_equal(2, enum_object<>::to_int32(border_type::inset));
      assert::are_equal("inset", enum_object<>::to_string(border_type::inset));
      assert::are_equal(border_type::inset, enum_object<>::parse<border_type>("inset"));
    }
    
    auto test_method_(outset) {
      assert::are_equal(3, enum_object<>::to_int32(border_type::outset));
      assert::are_equal("outset", enum_object<>::to_string(border_type::outset));
      assert::are_equal(border_type::outset, enum_object<>::parse<border_type>("outset"));
    }
    
    auto test_method_(groove) {
      assert::are_equal(4, enum_object<>::to_int32(border_type::groove));
      assert::are_equal("groove", enum_object<>::to_string(border_type::groove));
      assert::are_equal(border_type::groove, enum_object<>::parse<border_type>("groove"));
    }
    
    auto test_method_(ridge) {
      assert::are_equal(5, enum_object<>::to_int32(border_type::ridge));
      assert::are_equal("ridge", enum_object<>::to_string(border_type::ridge));
      assert::are_equal(border_type::ridge, enum_object<>::parse<border_type>("ridge"));
    }
    
    auto test_method_(theme) {
      assert::are_equal(6, enum_object<>::to_int32(border_type::theme));
      assert::are_equal("theme", enum_object<>::to_string(border_type::theme));
      assert::are_equal(border_type::theme, enum_object<>::parse<border_type>("theme"));
    }
    
    auto test_method_(dashed) {
      assert::are_equal(7, enum_object<>::to_int32(border_type::dashed));
      assert::are_equal("dashed", enum_object<>::to_string(border_type::dashed));
      assert::are_equal(border_type::dashed, enum_object<>::parse<border_type>("dashed"));
    }
    
    auto test_method_(dot_dash) {
      assert::are_equal(8, enum_object<>::to_int32(border_type::dot_dash));
      assert::are_equal("dot_dash", enum_object<>::to_string(border_type::dot_dash));
      assert::are_equal(border_type::dot_dash, enum_object<>::parse<border_type>("dot_dash"));
    }
    
    auto test_method_(dot_dot_dash) {
      assert::are_equal(9, enum_object<>::to_int32(border_type::dot_dot_dash));
      assert::are_equal("dot_dot_dash", enum_object<>::to_string(border_type::dot_dot_dash));
      assert::are_equal(border_type::dot_dot_dash, enum_object<>::parse<border_type>("dot_dot_dash"));
    }
    
    auto test_method_(dotted) {
      assert::are_equal(10, enum_object<>::to_int32(border_type::dotted));
      assert::are_equal("dotted", enum_object<>::to_string(border_type::dotted));
      assert::are_equal(border_type::dotted, enum_object<>::parse<border_type>("dotted"));
    }
    
    auto test_method_(double_border) {
      assert::are_equal(11, enum_object<>::to_int32(border_type::double_border));
      assert::are_equal("double_border", enum_object<>::to_string(border_type::double_border));
      assert::are_equal(border_type::double_border, enum_object<>::parse<border_type>("double_border"));
    }
  };
}
