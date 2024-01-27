#include <xtd/forms/screen_orientation>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(screen_orientation_tests) {
  public:
    void test_method_(angle_0) {
      assert::are_equal(0, enum_object<>::to_int32(screen_orientation::angle_0), csf_);
      assert::are_equal("angle_0", enum_object<>::to_string(screen_orientation::angle_0), csf_);
      assert::are_equal(screen_orientation::angle_0, enum_object<>::parse<screen_orientation>("angle_0"), csf_);
    }
    
    void test_method_(angle_90) {
      assert::are_equal(1, enum_object<>::to_int32(screen_orientation::angle_90), csf_);
      assert::are_equal("angle_90", enum_object<>::to_string(screen_orientation::angle_90), csf_);
      assert::are_equal(screen_orientation::angle_90, enum_object<>::parse<screen_orientation>("angle_90"), csf_);
    }
    
    void test_method_(angle_180) {
      assert::are_equal(2, enum_object<>::to_int32(screen_orientation::angle_180), csf_);
      assert::are_equal("angle_180", enum_object<>::to_string(screen_orientation::angle_180), csf_);
      assert::are_equal(screen_orientation::angle_180, enum_object<>::parse<screen_orientation>("angle_180"), csf_);
    }
    
    void test_method_(angle_270) {
      assert::are_equal(3, enum_object<>::to_int32(screen_orientation::angle_270), csf_);
      assert::are_equal("angle_270", enum_object<>::to_string(screen_orientation::angle_270), csf_);
      assert::are_equal(screen_orientation::angle_270, enum_object<>::parse<screen_orientation>("angle_270"), csf_);
    }
  };
}
