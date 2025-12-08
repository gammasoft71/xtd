#include <xtd/literals/ip_address>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::net;
using namespace xtd::tunit;

namespace xtd {
  inline namespace literals {
    namespace tests {
      class test_class_(ip_address_tests) {
        auto test_method_(_ip_operator_on_char_ptr) {
          auto v = "192.168.0.1"_ip;
          assert::is_instance_of<ip_address>(v);
          assert::are_equal("192.168.0.1", v.to_string());
        }
        
        auto test_method_(_ip_operator_on_char8_ptr) {
          auto v = u8"192.168.0.1"_ip;
          assert::is_instance_of<ip_address>(v);
          assert::are_equal("192.168.0.1", v.to_string());
        }
        
        auto test_method_(_ip_operator_on_char16_ptr) {
          auto v = u"192.168.0.1"_ip;
          assert::is_instance_of<ip_address>(v);
          assert::are_equal("192.168.0.1", v.to_string());
        }
        
        auto test_method_(_ip_operator_on_char32_ptr) {
          auto v = U"192.168.0.1"_ip;
          assert::is_instance_of<ip_address>(v);
          assert::are_equal("192.168.0.1", v.to_string());
        }
        
        auto test_method_(_ip_operator_on_wchar_ptr) {
          auto v = L"192.168.0.1"_ip;
          assert::is_instance_of<ip_address>(v);
          assert::are_equal("192.168.0.1", v.to_string());
        }
      };
    }
  }
}
