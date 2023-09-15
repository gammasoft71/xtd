#include <xtd/uri_kind>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(uri_kind_tests) {
  public:
    void test_method_(relative_or_absolute) {
      assert::are_equal(0, enum_object<>::to_int32(uri_kind::relative_or_absolute), csf_);
      assert::are_equal("relative_or_absolute", enum_object<>::to_string(uri_kind::relative_or_absolute), csf_);
      assert::are_equal(uri_kind::relative_or_absolute, enum_object<>::parse<uri_kind>("relative_or_absolute"), csf_);
    }
    
    void test_method_(absolute) {
      assert::are_equal(1, enum_object<>::to_int32(uri_kind::absolute), csf_);
      assert::are_equal("absolute", enum_object<>::to_string(uri_kind::absolute), csf_);
      assert::are_equal(uri_kind::absolute, enum_object<>::parse<uri_kind>("absolute"), csf_);
    }
    
    void test_method_(relative) {
      assert::are_equal(2, enum_object<>::to_int32(uri_kind::relative), csf_);
      assert::are_equal("relative", enum_object<>::to_string(uri_kind::relative), csf_);
      assert::are_equal(uri_kind::relative, enum_object<>::parse<uri_kind>("relative"), csf_);
    }
  };
}
