#include <xtd/drawing/imaging/image_lock_mode>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing::imaging;
using namespace xtd::tunit;

namespace xtd::drawing::imaging::tests {
  class test_class_(image_lock_mode_tests) {
  public:
    void test_method_(read_only) {
      assert::are_equal(1, enum_object<>::to_int32(image_lock_mode::read_only), csf_);
      assert::are_equal("read_only", enum_object<>::to_string(image_lock_mode::read_only), csf_);
      assert::are_equal(image_lock_mode::read_only, enum_object<>::parse<image_lock_mode>("read_only"), csf_);
    }
    
    void test_method_(write_only) {
      assert::are_equal(2, enum_object<>::to_int32(image_lock_mode::write_only), csf_);
      assert::are_equal("write_only", enum_object<>::to_string(image_lock_mode::write_only), csf_);
      assert::are_equal(image_lock_mode::write_only, enum_object<>::parse<image_lock_mode>("write_only"), csf_);
    }
    
    void test_method_(read_write) {
      assert::are_equal(3, enum_object<>::to_int32(image_lock_mode::read_write), csf_);
      assert::are_equal("read_write", enum_object<>::to_string(image_lock_mode::read_write), csf_);
      assert::are_equal(image_lock_mode::read_write, enum_object<>::parse<image_lock_mode>("read_write"), csf_);
    }
    
    void test_method_(user_input_buffer) {
      assert::are_equal(4, enum_object<>::to_int32(image_lock_mode::user_input_buffer), csf_);
      assert::are_equal("user_input_buffer", enum_object<>::to_string(image_lock_mode::user_input_buffer), csf_);
      assert::are_equal(image_lock_mode::user_input_buffer, enum_object<>::parse<image_lock_mode>("user_input_buffer"), csf_);
    }
  };
}

