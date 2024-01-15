#include <xtd/uri_components>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(uri_components_tests) {
    void test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(uri_components::none), csf_);
      assert::are_equal("none", enum_object<>::to_string(uri_components::none), csf_);
      assert::are_equal(uri_components::none, enum_object<>::parse<uri_components>("none"), csf_);
    }
    
    void test_method_(scheme) {
      assert::are_equal(1, enum_object<>::to_int32(uri_components::scheme), csf_);
      assert::are_equal("scheme", enum_object<>::to_string(uri_components::scheme), csf_);
      assert::are_equal(uri_components::scheme, enum_object<>::parse<uri_components>("scheme"), csf_);
    }
    
    void test_method_(user_info) {
      assert::are_equal(2, enum_object<>::to_int32(uri_components::user_info), csf_);
      assert::are_equal("user_info", enum_object<>::to_string(uri_components::user_info), csf_);
      assert::are_equal(uri_components::user_info, enum_object<>::parse<uri_components>("user_info"), csf_);
    }
    
    void test_method_(host) {
      assert::are_equal(4, enum_object<>::to_int32(uri_components::host), csf_);
      assert::are_equal("host", enum_object<>::to_string(uri_components::host), csf_);
      assert::are_equal(uri_components::host, enum_object<>::parse<uri_components>("host"), csf_);
    }
    
    void test_method_(port) {
      assert::are_equal(8, enum_object<>::to_int32(uri_components::port), csf_);
      assert::are_equal("port", enum_object<>::to_string(uri_components::port), csf_);
      assert::are_equal(uri_components::port, enum_object<>::parse<uri_components>("port"), csf_);
    }
    
    void test_method_(path) {
      assert::are_equal(16, enum_object<>::to_int32(uri_components::path), csf_);
      assert::are_equal("path", enum_object<>::to_string(uri_components::path), csf_);
      assert::are_equal(uri_components::path, enum_object<>::parse<uri_components>("path"), csf_);
    }
    
    void test_method_(query) {
      assert::are_equal(32, enum_object<>::to_int32(uri_components::query), csf_);
      assert::are_equal("query", enum_object<>::to_string(uri_components::query), csf_);
      assert::are_equal(uri_components::query, enum_object<>::parse<uri_components>("query"), csf_);
    }
    
    void test_method_(fragment) {
      assert::are_equal(64, enum_object<>::to_int32(uri_components::fragment), csf_);
      assert::are_equal("fragment", enum_object<>::to_string(uri_components::fragment), csf_);
      assert::are_equal(uri_components::fragment, enum_object<>::parse<uri_components>("fragment"), csf_);
    }
    
    void test_method_(strong_port) {
      assert::are_equal(128, enum_object<>::to_int32(uri_components::strong_port), csf_);
      assert::are_equal("strong_port", enum_object<>::to_string(uri_components::strong_port), csf_);
      assert::are_equal(uri_components::strong_port, enum_object<>::parse<uri_components>("strong_port"), csf_);
    }
    
    void test_method_(keep_delimiter) {
      assert::are_equal(1073741824, enum_object<>::to_int32(uri_components::keep_delimiter), csf_);
      assert::are_equal("keep_delimiter", enum_object<>::to_string(uri_components::keep_delimiter), csf_);
      assert::are_equal(uri_components::keep_delimiter, enum_object<>::parse<uri_components>("keep_delimiter"), csf_);
    }
    
    void test_method_(host_and_port) {
      assert::are_equal(132, enum_object<>::to_int32(uri_components::host_and_port), csf_);
      assert::are_equal("host_and_port", enum_object<>::to_string(uri_components::host_and_port), csf_);
      assert::are_equal(uri_components::host_and_port, enum_object<>::parse<uri_components>("host_and_port"), csf_);
    }
    
    void test_method_(strong_authority) {
      assert::are_equal(134, enum_object<>::to_int32(uri_components::strong_authority), csf_);
      assert::are_equal("strong_authority", enum_object<>::to_string(uri_components::strong_authority), csf_);
      assert::are_equal(uri_components::strong_authority, enum_object<>::parse<uri_components>("strong_authority"), csf_);
    }
    
    void test_method_(scheme_and_server) {
      assert::are_equal(13, enum_object<>::to_int32(uri_components::scheme_and_server), csf_);
      assert::are_equal("scheme_and_server", enum_object<>::to_string(uri_components::scheme_and_server), csf_);
      assert::are_equal(uri_components::scheme_and_server, enum_object<>::parse<uri_components>("scheme_and_server"), csf_);
    }
    
    void test_method_(serialization_info_string) {
      assert::are_equal(134217728, enum_object<>::to_int32(uri_components::serialization_info_string), csf_);
      assert::are_equal("serialization_info_string", enum_object<>::to_string(uri_components::serialization_info_string), csf_);
      assert::are_equal(uri_components::serialization_info_string, enum_object<>::parse<uri_components>("serialization_info_string"), csf_);
    }
  };
}
