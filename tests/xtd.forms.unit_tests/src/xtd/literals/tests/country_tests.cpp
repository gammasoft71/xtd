#include <xtd/forms/country>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd {
  inline namespace literals {
    namespace tests {
      class test_class_(country_tests) {
        void test_method_(_country_operator_on_char_ptr) {
          auto v = "Belgium"_country;
          assert::is_instance_of<country>(v);
          assert::are_equal("country [name=Belgium, alpha_2_code=BE, alpha_3_code=BEL, numeric_code=56]", v.to_string());
        }
        
#if defined(__xtd__cpp_lib_char8_t)
        void test_method_(_country_operator_on_char8_ptr) {
          auto v = u8"Belgium"_country;
          assert::is_instance_of<country>(v);
          assert::are_equal("country [name=Belgium, alpha_2_code=BE, alpha_3_code=BEL, numeric_code=56]", v.to_string());
        }
#endif
        
        void test_method_(_country_operator_on_char16_ptr) {
          auto v = u"Belgium"_country;
          assert::is_instance_of<country>(v);
          assert::are_equal("country [name=Belgium, alpha_2_code=BE, alpha_3_code=BEL, numeric_code=56]", v.to_string());
        }
        
        void test_method_(_country_operator_on_char32_ptr) {
          auto v = U"Belgium"_country;
          assert::is_instance_of<country>(v);
          assert::are_equal("country [name=Belgium, alpha_2_code=BE, alpha_3_code=BEL, numeric_code=56]", v.to_string());
        }
        
        void test_method_(_country_operator_on_wchar_ptr) {
          auto v = L"Belgium"_country;
          assert::is_instance_of<country>(v);
          assert::are_equal("country [name=Belgium, alpha_2_code=BE, alpha_3_code=BEL, numeric_code=56]", v.to_string());
        }
      };
    }
  }
}
