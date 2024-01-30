#include <xtd/forms/picture_box_size_mode>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(picture_box_size_mode_tests) {
  public:
    void test_method_(normal) {
      assert::are_equal(0, enum_object<>::to_int32(picture_box_size_mode::normal), csf_);
      assert::are_equal("normal", enum_object<>::to_string(picture_box_size_mode::normal), csf_);
      assert::are_equal(picture_box_size_mode::normal, enum_object<>::parse<picture_box_size_mode>("normal"), csf_);
    }
    
    void test_method_(stretch_image) {
      assert::are_equal(1, enum_object<>::to_int32(picture_box_size_mode::stretch_image), csf_);
      assert::are_equal("stretch_image", enum_object<>::to_string(picture_box_size_mode::stretch_image), csf_);
      assert::are_equal(picture_box_size_mode::stretch_image, enum_object<>::parse<picture_box_size_mode>("stretch_image"), csf_);
    }
    
    void test_method_(auto_size) {
      assert::are_equal(2, enum_object<>::to_int32(picture_box_size_mode::auto_size), csf_);
      assert::are_equal("auto_size", enum_object<>::to_string(picture_box_size_mode::auto_size), csf_);
      assert::are_equal(picture_box_size_mode::auto_size, enum_object<>::parse<picture_box_size_mode>("auto_size"), csf_);
    }
    
    void test_method_(center_image) {
      assert::are_equal(3, enum_object<>::to_int32(picture_box_size_mode::center_image), csf_);
      assert::are_equal("center_image", enum_object<>::to_string(picture_box_size_mode::center_image), csf_);
      assert::are_equal(picture_box_size_mode::center_image, enum_object<>::parse<picture_box_size_mode>("center_image"), csf_);
    }
    
    void test_method_(zoom) {
      assert::are_equal(4, enum_object<>::to_int32(picture_box_size_mode::zoom), csf_);
      assert::are_equal("zoom", enum_object<>::to_string(picture_box_size_mode::zoom), csf_);
      assert::are_equal(picture_box_size_mode::zoom, enum_object<>::parse<picture_box_size_mode>("zoom"), csf_);
    }
  };
}
