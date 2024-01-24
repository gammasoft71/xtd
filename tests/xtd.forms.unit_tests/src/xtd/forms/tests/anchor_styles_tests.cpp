#include <xtd/forms/anchor_styles>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(anchor_styles_tests) {
    void test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(anchor_styles::none), csf_);
      assert::are_equal("none", enum_object<>::to_string(anchor_styles::none), csf_);
      assert::are_equal(anchor_styles::none, enum_object<>::parse<anchor_styles>("none"), csf_);
    }
    
    void test_method_(top) {
      assert::are_equal(1, enum_object<>::to_int32(anchor_styles::top), csf_);
      assert::are_equal("top", enum_object<>::to_string(anchor_styles::top), csf_);
      assert::are_equal(anchor_styles::top, enum_object<>::parse<anchor_styles>("top"), csf_);
    }
    
    void test_method_(bottom) {
      assert::are_equal(2, enum_object<>::to_int32(anchor_styles::bottom), csf_);
      assert::are_equal("bottom", enum_object<>::to_string(anchor_styles::bottom), csf_);
      assert::are_equal(anchor_styles::bottom, enum_object<>::parse<anchor_styles>("bottom"), csf_);
    }
    
    void test_method_(left) {
      assert::are_equal(4, enum_object<>::to_int32(anchor_styles::left), csf_);
      assert::are_equal("left", enum_object<>::to_string(anchor_styles::left), csf_);
      assert::are_equal(anchor_styles::left, enum_object<>::parse<anchor_styles>("left"), csf_);
    }
    
    void test_method_(right) {
      assert::are_equal(8, enum_object<>::to_int32(anchor_styles::right), csf_);
      assert::are_equal("right", enum_object<>::to_string(anchor_styles::right), csf_);
      assert::are_equal(anchor_styles::right, enum_object<>::parse<anchor_styles>("right"), csf_);
    }
  };
}
