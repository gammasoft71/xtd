#include <xtd/forms/segment_style>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(segment_style_tests) {
  public:
    void test_method_(standard) {
      assert::are_equal(0, enum_object<>::to_int32(segment_style::standard), csf_);
      assert::are_equal("standard", enum_object<>::to_string(segment_style::standard), csf_);
      assert::are_equal(segment_style::standard, enum_object<>::parse<segment_style>("standard"), csf_);
    }
    
    void test_method_(modern) {
      assert::are_equal(1, enum_object<>::to_int32(segment_style::modern), csf_);
      assert::are_equal("modern", enum_object<>::to_string(segment_style::modern), csf_);
      assert::are_equal(segment_style::modern, enum_object<>::parse<segment_style>("modern"), csf_);
    }
    
    void test_method_(mixed) {
      assert::are_equal(2, enum_object<>::to_int32(segment_style::mixed), csf_);
      assert::are_equal("mixed", enum_object<>::to_string(segment_style::mixed), csf_);
      assert::are_equal(segment_style::mixed, enum_object<>::parse<segment_style>("mixed"), csf_);
    }
    
    void test_method_(expanded) {
      assert::are_equal(3, enum_object<>::to_int32(segment_style::expanded), csf_);
      assert::are_equal("expanded", enum_object<>::to_string(segment_style::expanded), csf_);
      assert::are_equal(segment_style::expanded, enum_object<>::parse<segment_style>("expanded"), csf_);
    }
    
    void test_method_(design) {
      assert::are_equal(4, enum_object<>::to_int32(segment_style::design), csf_);
      assert::are_equal("design", enum_object<>::to_string(segment_style::design), csf_);
      assert::are_equal(segment_style::design, enum_object<>::parse<segment_style>("design"), csf_);
    }
    
    void test_method_(stick) {
      assert::are_equal(5, enum_object<>::to_int32(segment_style::stick), csf_);
      assert::are_equal("stick", enum_object<>::to_string(segment_style::stick), csf_);
      assert::are_equal(segment_style::stick, enum_object<>::parse<segment_style>("stick"), csf_);
    }
  };
}
