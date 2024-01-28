#include <xtd/forms/tab_alignment>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(tab_alignment_tests) {
  public:
    void test_method_(top) {
      assert::are_equal(0, enum_object<>::to_int32(tab_alignment::top), csf_);
      assert::are_equal("top", enum_object<>::to_string(tab_alignment::top), csf_);
      assert::are_equal(tab_alignment::top, enum_object<>::parse<tab_alignment>("top"), csf_);
    }
    
    void test_method_(bottom) {
      assert::are_equal(1, enum_object<>::to_int32(tab_alignment::bottom), csf_);
      assert::are_equal("bottom", enum_object<>::to_string(tab_alignment::bottom), csf_);
      assert::are_equal(tab_alignment::bottom, enum_object<>::parse<tab_alignment>("bottom"), csf_);
    }
    
    void test_method_(left) {
      assert::are_equal(2, enum_object<>::to_int32(tab_alignment::left), csf_);
      assert::are_equal("left", enum_object<>::to_string(tab_alignment::left), csf_);
      assert::are_equal(tab_alignment::left, enum_object<>::parse<tab_alignment>("left"), csf_);
    }
    
    void test_method_(right) {
      assert::are_equal(3, enum_object<>::to_int32(tab_alignment::right), csf_);
      assert::are_equal("right", enum_object<>::to_string(tab_alignment::right), csf_);
      assert::are_equal(tab_alignment::right, enum_object<>::parse<tab_alignment>("right"), csf_);
    }
  };
}
