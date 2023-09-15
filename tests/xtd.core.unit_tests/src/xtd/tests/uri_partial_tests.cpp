#include <xtd/uri_partial>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(uri_partial_tests) {
  public:
    void test_method_(scheme) {
      assert::are_equal(0, enum_object<>::to_int32(uri_partial::scheme), csf_);
      assert::are_equal("scheme", enum_object<>::to_string(uri_partial::scheme), csf_);
      assert::are_equal(uri_partial::scheme, enum_object<>::parse<uri_partial>("scheme"), csf_);
    }
    
    void test_method_(authority) {
      assert::are_equal(1, enum_object<>::to_int32(uri_partial::authority), csf_);
      assert::are_equal("authority", enum_object<>::to_string(uri_partial::authority), csf_);
      assert::are_equal(uri_partial::authority, enum_object<>::parse<uri_partial>("authority"), csf_);
    }
    
    void test_method_(path) {
      assert::are_equal(2, enum_object<>::to_int32(uri_partial::path), csf_);
      assert::are_equal("path", enum_object<>::to_string(uri_partial::path), csf_);
      assert::are_equal(uri_partial::path, enum_object<>::parse<uri_partial>("path"), csf_);
    }
    
    void test_method_(query) {
      assert::are_equal(3, enum_object<>::to_int32(uri_partial::query), csf_);
      assert::are_equal("query", enum_object<>::to_string(uri_partial::query), csf_);
      assert::are_equal(uri_partial::query, enum_object<>::parse<uri_partial>("query"), csf_);
    }
  };
}
