#include <xtd/forms/content_alignment>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(content_alignment_tests) {
  public:
    void test_method_(top_left) {
      assert::are_equal(1, enum_object<>::to_int32(content_alignment::top_left), csf_);
      assert::are_equal("top_left", enum_object<>::to_string(content_alignment::top_left), csf_);
      assert::are_equal(content_alignment::top_left, enum_object<>::parse<content_alignment>("top_left"), csf_);
    }
    
    void test_method_(top_center) {
      assert::are_equal(2, enum_object<>::to_int32(content_alignment::top_center), csf_);
      assert::are_equal("top_center", enum_object<>::to_string(content_alignment::top_center), csf_);
      assert::are_equal(content_alignment::top_center, enum_object<>::parse<content_alignment>("top_center"), csf_);
    }
    
    void test_method_(top_right) {
      assert::are_equal(4, enum_object<>::to_int32(content_alignment::top_right), csf_);
      assert::are_equal("top_right", enum_object<>::to_string(content_alignment::top_right), csf_);
      assert::are_equal(content_alignment::top_right, enum_object<>::parse<content_alignment>("top_right"), csf_);
    }
    
    void test_method_(middle_left) {
      assert::are_equal(16, enum_object<>::to_int32(content_alignment::middle_left), csf_);
      assert::are_equal("middle_left", enum_object<>::to_string(content_alignment::middle_left), csf_);
      assert::are_equal(content_alignment::middle_left, enum_object<>::parse<content_alignment>("middle_left"), csf_);
    }
    
    void test_method_(middle_center) {
      assert::are_equal(32, enum_object<>::to_int32(content_alignment::middle_center), csf_);
      assert::are_equal("middle_center", enum_object<>::to_string(content_alignment::middle_center), csf_);
      assert::are_equal(content_alignment::middle_center, enum_object<>::parse<content_alignment>("middle_center"), csf_);
    }
    
    void test_method_(middle_right) {
      assert::are_equal(64, enum_object<>::to_int32(content_alignment::middle_right), csf_);
      assert::are_equal("middle_right", enum_object<>::to_string(content_alignment::middle_right), csf_);
      assert::are_equal(content_alignment::middle_right, enum_object<>::parse<content_alignment>("middle_right"), csf_);
    }
    
    void test_method_(bottom_left) {
      assert::are_equal(256, enum_object<>::to_int32(content_alignment::bottom_left), csf_);
      assert::are_equal("bottom_left", enum_object<>::to_string(content_alignment::bottom_left), csf_);
      assert::are_equal(content_alignment::bottom_left, enum_object<>::parse<content_alignment>("bottom_left"), csf_);
    }
    
    void test_method_(bottom_center) {
      assert::are_equal(512, enum_object<>::to_int32(content_alignment::bottom_center), csf_);
      assert::are_equal("bottom_center", enum_object<>::to_string(content_alignment::bottom_center), csf_);
      assert::are_equal(content_alignment::bottom_center, enum_object<>::parse<content_alignment>("bottom_center"), csf_);
    }
    
    void test_method_(bottom_right) {
      assert::are_equal(1024, enum_object<>::to_int32(content_alignment::bottom_right), csf_);
      assert::are_equal("bottom_right", enum_object<>::to_string(content_alignment::bottom_right), csf_);
      assert::are_equal(content_alignment::bottom_right, enum_object<>::parse<content_alignment>("bottom_right"), csf_);
    }
  };
}
