#include <xtd/uri_host_name_type>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(uri_host_name_type_tests) {
    auto test_method_(unknown) {
      assert::are_equal(0, enum_object<>::to_int32(uri_host_name_type::unknown));
      assert::are_equal("unknown", enum_object<>::to_string(uri_host_name_type::unknown));
      assert::are_equal(uri_host_name_type::unknown, enum_object<>::parse<uri_host_name_type>("unknown"));
    }
    
    auto test_method_(basic) {
      assert::are_equal(1, enum_object<>::to_int32(uri_host_name_type::basic));
      assert::are_equal("basic", enum_object<>::to_string(uri_host_name_type::basic));
      assert::are_equal(uri_host_name_type::basic, enum_object<>::parse<uri_host_name_type>("basic"));
    }
    
    auto test_method_(dns) {
      assert::are_equal(2, enum_object<>::to_int32(uri_host_name_type::dns));
      assert::are_equal("dns", enum_object<>::to_string(uri_host_name_type::dns));
      assert::are_equal(uri_host_name_type::dns, enum_object<>::parse<uri_host_name_type>("dns"));
    }
    
    auto test_method_(ip_v4) {
      assert::are_equal(3, enum_object<>::to_int32(uri_host_name_type::ip_v4));
      assert::are_equal("ip_v4", enum_object<>::to_string(uri_host_name_type::ip_v4));
      assert::are_equal(uri_host_name_type::ip_v4, enum_object<>::parse<uri_host_name_type>("ip_v4"));
    }
    
    auto test_method_(ip_v6) {
      assert::are_equal(4, enum_object<>::to_int32(uri_host_name_type::ip_v6));
      assert::are_equal("ip_v6", enum_object<>::to_string(uri_host_name_type::ip_v6));
      assert::are_equal(uri_host_name_type::ip_v6, enum_object<>::parse<uri_host_name_type>("ip_v6"));
    }
  };
}
