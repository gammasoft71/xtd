#include <xtd/forms/power_line_status.h>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(power_line_status_tests) {
  public:
    void test_method_(offline) {
      assert::are_equal(0, enum_object<>::to_int32(power_line_status::offline), csf_);
      assert::are_equal("offline", enum_object<>::to_string(power_line_status::offline), csf_);
      assert::are_equal(power_line_status::offline, enum_object<>::parse<power_line_status>("offline"), csf_);
    }
    
    void test_method_(online) {
      assert::are_equal(1, enum_object<>::to_int32(power_line_status::online), csf_);
      assert::are_equal("online", enum_object<>::to_string(power_line_status::online), csf_);
      assert::are_equal(power_line_status::online, enum_object<>::parse<power_line_status>("online"), csf_);
    }
    
    void test_method_(unknown) {
      assert::are_equal(255, enum_object<>::to_int32(power_line_status::unknown), csf_);
      assert::are_equal("unknown", enum_object<>::to_string(power_line_status::unknown), csf_);
      assert::are_equal(power_line_status::unknown, enum_object<>::parse<power_line_status>("unknown"), csf_);
    }
  };
}

