#include <xtd/forms/image_layout>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(image_layout_tests) {
  public:
    void test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(image_layout::none), csf_);
      assert::are_equal("none", enum_object<>::to_string(image_layout::none), csf_);
      assert::are_equal(image_layout::none, enum_object<>::parse<image_layout>("none"), csf_);
    }
    
    void test_method_(tile) {
      assert::are_equal(1, enum_object<>::to_int32(image_layout::tile), csf_);
      assert::are_equal("tile", enum_object<>::to_string(image_layout::tile), csf_);
      assert::are_equal(image_layout::tile, enum_object<>::parse<image_layout>("tile"), csf_);
    }
    
    void test_method_(center) {
      assert::are_equal(2, enum_object<>::to_int32(image_layout::center), csf_);
      assert::are_equal("center", enum_object<>::to_string(image_layout::center), csf_);
      assert::are_equal(image_layout::center, enum_object<>::parse<image_layout>("center"), csf_);
    }
    
    void test_method_(stretch) {
      assert::are_equal(3, enum_object<>::to_int32(image_layout::stretch), csf_);
      assert::are_equal("stretch", enum_object<>::to_string(image_layout::stretch), csf_);
      assert::are_equal(image_layout::stretch, enum_object<>::parse<image_layout>("stretch"), csf_);
    }
    
    void test_method_(zoom) {
      assert::are_equal(4, enum_object<>::to_int32(image_layout::zoom), csf_);
      assert::are_equal("zoom", enum_object<>::to_string(image_layout::zoom), csf_);
      assert::are_equal(image_layout::zoom, enum_object<>::parse<image_layout>("zoom"), csf_);
    }
  };
}
