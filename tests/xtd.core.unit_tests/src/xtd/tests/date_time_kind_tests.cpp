#include <xtd/date_time_kind>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(date_time_kind_tests) {
    auto test_method_(unspecified) {
      assert::are_equal(0, enum_object<>::to_int32(date_time_kind::unspecified));
      assert::are_equal("unspecified", enum_object<>::to_string(date_time_kind::unspecified));
      assert::are_equal(date_time_kind::unspecified, enum_object<>::parse<date_time_kind>("unspecified"));
    }
    
    auto test_method_(utc) {
      assert::are_equal(1, enum_object<>::to_int32(date_time_kind::utc));
      assert::are_equal("utc", enum_object<>::to_string(date_time_kind::utc));
      assert::are_equal(date_time_kind::utc, enum_object<>::parse<date_time_kind>("utc"));
    }
    
    auto test_method_(local) {
      assert::are_equal(2, enum_object<>::to_int32(date_time_kind::local));
      assert::are_equal("local", enum_object<>::to_string(date_time_kind::local));
      assert::are_equal(date_time_kind::local, enum_object<>::parse<date_time_kind>("local"));
    }
  };
}
