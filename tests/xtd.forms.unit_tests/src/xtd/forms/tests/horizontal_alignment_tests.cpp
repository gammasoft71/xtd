#include <xtd/forms/horizontal_alignment>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(horizontal_alignment_tests) {
  public:
    void test_method_(left) {
      assert::are_equal(0, enum_object<>::to_int32(horizontal_alignment::left), csf_);
      assert::are_equal("left", enum_object<>::to_string(horizontal_alignment::left), csf_);
      assert::are_equal(horizontal_alignment::left, enum_object<>::parse<horizontal_alignment>("left"), csf_);
    }
    
    void test_method_(right) {
      assert::are_equal(1, enum_object<>::to_int32(horizontal_alignment::right), csf_);
      assert::are_equal("right", enum_object<>::to_string(horizontal_alignment::right), csf_);
      assert::are_equal(horizontal_alignment::right, enum_object<>::parse<horizontal_alignment>("right"), csf_);
    }
    
    void test_method_(center) {
      assert::are_equal(2, enum_object<>::to_int32(horizontal_alignment::center), csf_);
      assert::are_equal("center", enum_object<>::to_string(horizontal_alignment::center), csf_);
      assert::are_equal(horizontal_alignment::center, enum_object<>::parse<horizontal_alignment>("center"), csf_);
    }
  };
}
