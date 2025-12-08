#include <xtd/literals/uri>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd {
  inline namespace literals {
    namespace tests {
      class test_class_(uri_tests) {
        auto test_method_(_uri_operator_on_char_ptr) {
          auto v = "http://www.contoso.com"_uri;
          assert::is_instance_of<uri>(v);
          assert::are_equal("http://www.contoso.com/", v.to_string());
        }
        
        auto test_method_(_uri_operator_on_char8_ptr) {
          auto v = u8"http://www.contoso.com"_uri;
          assert::is_instance_of<uri>(v);
          assert::are_equal("http://www.contoso.com/", v.to_string());
        }
        
        auto test_method_(_uri_operator_on_char16_ptr) {
          auto v = u"http://www.contoso.com"_uri;
          assert::is_instance_of<uri>(v);
          assert::are_equal("http://www.contoso.com/", v.to_string());
        }
        
        auto test_method_(_uri_operator_on_char32_ptr) {
          auto v = U"http://www.contoso.com"_uri;
          assert::is_instance_of<uri>(v);
          assert::are_equal("http://www.contoso.com/", v.to_string());
        }
        
        auto test_method_(_uri_operator_on_wchar_ptr) {
          auto v = L"http://www.contoso.com"_uri;
          assert::is_instance_of<uri>(v);
          assert::are_equal("http://www.contoso.com/", v.to_string());
        }
      };
    }
  }
}
