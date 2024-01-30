#include <xtd/forms/date_time_picker_format>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(date_time_picker_format_tests) {
  public:
    void test_method_(long_format) {
      assert::are_equal(1, enum_object<>::to_int32(date_time_picker_format::long_format), csf_);
      assert::are_equal("long_format", enum_object<>::to_string(date_time_picker_format::long_format), csf_);
      assert::are_equal(date_time_picker_format::long_format, enum_object<>::parse<date_time_picker_format>("long_format"), csf_);
    }
    
    void test_method_(short_format) {
      assert::are_equal(2, enum_object<>::to_int32(date_time_picker_format::short_format), csf_);
      assert::are_equal("short_format", enum_object<>::to_string(date_time_picker_format::short_format), csf_);
      assert::are_equal(date_time_picker_format::short_format, enum_object<>::parse<date_time_picker_format>("short_format"), csf_);
    }
    
    void test_method_(time) {
      assert::are_equal(4, enum_object<>::to_int32(date_time_picker_format::time), csf_);
      assert::are_equal("time", enum_object<>::to_string(date_time_picker_format::time), csf_);
      assert::are_equal(date_time_picker_format::time, enum_object<>::parse<date_time_picker_format>("time"), csf_);
    }
    
    void test_method_(custom) {
      assert::are_equal(8, enum_object<>::to_int32(date_time_picker_format::custom), csf_);
      assert::are_equal("custom", enum_object<>::to_string(date_time_picker_format::custom), csf_);
      assert::are_equal(date_time_picker_format::custom, enum_object<>::parse<date_time_picker_format>("custom"), csf_);
    }
  };
}
