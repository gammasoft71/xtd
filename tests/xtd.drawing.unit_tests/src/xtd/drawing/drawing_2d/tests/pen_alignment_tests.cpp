#include <xtd/drawing/drawing_2d/pen_alignment>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing::drawing_2d;
using namespace xtd::tunit;

namespace xtd::drawing::drawing_2d::tests {
  class test_class_(pen_alignment_tests) {
  public:
    void test_method_(center) {
      assert::are_equal(0, enum_object<>::to_int32(pen_alignment::center), csf_);
      assert::are_equal("center", enum_object<>::to_string(pen_alignment::center), csf_);
      assert::are_equal(pen_alignment::center, enum_object<>::parse<pen_alignment>("center"), csf_);
    }
    
    void test_method_(inset) {
      assert::are_equal(1, enum_object<>::to_int32(pen_alignment::inset), csf_);
      assert::are_equal("inset", enum_object<>::to_string(pen_alignment::inset), csf_);
      assert::are_equal(pen_alignment::inset, enum_object<>::parse<pen_alignment>("inset"), csf_);
    }
    
    void test_method_(outset) {
      assert::are_equal(2, enum_object<>::to_int32(pen_alignment::outset), csf_);
      assert::are_equal("outset", enum_object<>::to_string(pen_alignment::outset), csf_);
      assert::are_equal(pen_alignment::outset, enum_object<>::parse<pen_alignment>("outset"), csf_);
    }
    
    void test_method_(left) {
      assert::are_equal(3, enum_object<>::to_int32(pen_alignment::left), csf_);
      assert::are_equal("left", enum_object<>::to_string(pen_alignment::left), csf_);
      assert::are_equal(pen_alignment::left, enum_object<>::parse<pen_alignment>("left"), csf_);
    }
    
    void test_method_(right) {
      assert::are_equal(4, enum_object<>::to_int32(pen_alignment::right), csf_);
      assert::are_equal("right", enum_object<>::to_string(pen_alignment::right), csf_);
      assert::are_equal(pen_alignment::right, enum_object<>::parse<pen_alignment>("right"), csf_);
    }
  };
}
