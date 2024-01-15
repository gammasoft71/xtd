#include <xtd/net/sockets/ip_protection_level>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::net::sockets;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(ip_protection_level_tests) {
    void test_method_(unspecified) {
      assert::are_equal(-1, enum_object<>::to_int32(ip_protection_level::unspecified), csf_);
      assert::are_equal("unspecified", enum_object<>::to_string(ip_protection_level::unspecified), csf_);
      assert::are_equal(ip_protection_level::unspecified, enum_object<>::parse<ip_protection_level>("unspecified"), csf_);
    }
    
    void test_method_(unrestricted) {
      assert::are_equal(10, enum_object<>::to_int32(ip_protection_level::unrestricted), csf_);
      assert::are_equal("unrestricted", enum_object<>::to_string(ip_protection_level::unrestricted), csf_);
      assert::are_equal(ip_protection_level::unrestricted, enum_object<>::parse<ip_protection_level>("unrestricted"), csf_);
    }
    
    void test_method_(edge_restricted) {
      assert::are_equal(20, enum_object<>::to_int32(ip_protection_level::edge_restricted), csf_);
      assert::are_equal("edge_restricted", enum_object<>::to_string(ip_protection_level::edge_restricted), csf_);
      assert::are_equal(ip_protection_level::edge_restricted, enum_object<>::parse<ip_protection_level>("edge_restricted"), csf_);
    }
    
    void test_method_(restricted) {
      assert::are_equal(30, enum_object<>::to_int32(ip_protection_level::restricted), csf_);
      assert::are_equal("restricted", enum_object<>::to_string(ip_protection_level::restricted), csf_);
      assert::are_equal(ip_protection_level::restricted, enum_object<>::parse<ip_protection_level>("restricted"), csf_);
    }
  };
}
