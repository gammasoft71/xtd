#include <xtd/literals/version>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd {
  inline namespace literals {
    namespace tests {
      class test_class_(version_tests) {
        auto test_method_(_vers_operator_on_char_ptr) {
          auto v = "1.2.3"_vers;
          assert::is_instance_of<version>(v);
          assert::are_equal("1.2.3", v.to_string());
        }
        
        auto test_method_(_vers_operator_on_char8_ptr) {
          auto v = u8"1.2.3"_vers;
          assert::is_instance_of<version>(v);
          assert::are_equal("1.2.3", v.to_string());
        }
        
        auto test_method_(_vers_operator_on_char16_ptr) {
          auto v = u"1.2.3"_vers;
          assert::is_instance_of<version>(v);
          assert::are_equal("1.2.3", v.to_string());
        }
        
        auto test_method_(_vers_operator_on_char32_ptr) {
          auto v = U"1.2.3"_vers;
          assert::is_instance_of<version>(v);
          assert::are_equal("1.2.3", v.to_string());
        }
        
        auto test_method_(_vers_operator_on_wchar_ptr) {
          auto v = L"1.2.3"_vers;
          assert::is_instance_of<version>(v);
          assert::are_equal("1.2.3", v.to_string());
        }
      };
    }
  }
}
