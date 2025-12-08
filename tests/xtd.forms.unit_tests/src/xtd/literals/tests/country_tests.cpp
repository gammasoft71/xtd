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
        auto test_method_(_country_operator_on_char_ptr_from_name) {
          auto v = "Belgium"_country;
          assert::is_instance_of<country>(v);
          assert::are_equal("country [name=Belgium, alpha_2_code=BE, alpha_3_code=BEL, numeric_code=56]", v.to_string());
        }
        
        auto test_method_(_country_operator_on_char8_ptr_from_name) {
          auto v = u8"Belgium"_country;
          assert::is_instance_of<country>(v);
          assert::are_equal("country [name=Belgium, alpha_2_code=BE, alpha_3_code=BEL, numeric_code=56]", v.to_string());
        }
        
        auto test_method_(_country_operator_on_char16_ptr_from_name) {
          auto v = u"Belgium"_country;
          assert::is_instance_of<country>(v);
          assert::are_equal("country [name=Belgium, alpha_2_code=BE, alpha_3_code=BEL, numeric_code=56]", v.to_string());
        }
        
        auto test_method_(_country_operator_on_char32_ptr_from_name) {
          auto v = U"Belgium"_country;
          assert::is_instance_of<country>(v);
          assert::are_equal("country [name=Belgium, alpha_2_code=BE, alpha_3_code=BEL, numeric_code=56]", v.to_string());
        }
        
        auto test_method_(_country_operator_on_wchar_ptr_from_name) {
          auto v = L"Belgium"_country;
          assert::is_instance_of<country>(v);
          assert::are_equal("country [name=Belgium, alpha_2_code=BE, alpha_3_code=BEL, numeric_code=56]", v.to_string());
        }
        
        auto test_method_(_country_operator_on_char_ptr_from_alpha_2_code) {
          auto v = "BE"_country;
          assert::is_instance_of<country>(v);
          assert::are_equal("country [name=Belgium, alpha_2_code=BE, alpha_3_code=BEL, numeric_code=56]", v.to_string());
        }
        
        auto test_method_(_country_operator_on_char8_ptr_from_alpha_2_code) {
          auto v = u8"BE"_country;
          assert::is_instance_of<country>(v);
          assert::are_equal("country [name=Belgium, alpha_2_code=BE, alpha_3_code=BEL, numeric_code=56]", v.to_string());
        }
        
        auto test_method_(_country_operator_on_char16_ptr_from_alpha_2_code) {
          auto v = u"BE"_country;
          assert::is_instance_of<country>(v);
          assert::are_equal("country [name=Belgium, alpha_2_code=BE, alpha_3_code=BEL, numeric_code=56]", v.to_string());
        }
        
        auto test_method_(_country_operator_on_char32_ptr_from_alpha_2_code) {
          auto v = U"BE"_country;
          assert::is_instance_of<country>(v);
          assert::are_equal("country [name=Belgium, alpha_2_code=BE, alpha_3_code=BEL, numeric_code=56]", v.to_string());
        }
        
        auto test_method_(_country_operator_on_wchar_ptr_from_alpha_2_code) {
          auto v = L"BE"_country;
          assert::is_instance_of<country>(v);
          assert::are_equal("country [name=Belgium, alpha_2_code=BE, alpha_3_code=BEL, numeric_code=56]", v.to_string());
        }
        
        auto test_method_(_country_operator_on_char_ptr_from_alpha_3_code) {
          auto v = "BEL"_country;
          assert::is_instance_of<country>(v);
          assert::are_equal("country [name=Belgium, alpha_2_code=BE, alpha_3_code=BEL, numeric_code=56]", v.to_string());
        }
        
        auto test_method_(_country_operator_on_char8_ptr_from_alpha_3_code) {
          auto v = u8"BEL"_country;
          assert::is_instance_of<country>(v);
          assert::are_equal("country [name=Belgium, alpha_2_code=BE, alpha_3_code=BEL, numeric_code=56]", v.to_string());
        }
        
        auto test_method_(_country_operator_on_char16_ptr_from_alpha_3_code) {
          auto v = u"BEL"_country;
          assert::is_instance_of<country>(v);
          assert::are_equal("country [name=Belgium, alpha_2_code=BE, alpha_3_code=BEL, numeric_code=56]", v.to_string());
        }
        
        auto test_method_(_country_operator_on_char32_ptr_from_alpha_3_code) {
          auto v = U"BEL"_country;
          assert::is_instance_of<country>(v);
          assert::are_equal("country [name=Belgium, alpha_2_code=BE, alpha_3_code=BEL, numeric_code=56]", v.to_string());
        }
        
        auto test_method_(_country_operator_on_wchar_ptr_from_alpha_3_code) {
          auto v = L"BEL"_country;
          assert::is_instance_of<country>(v);
          assert::are_equal("country [name=Belgium, alpha_2_code=BE, alpha_3_code=BEL, numeric_code=56]", v.to_string());
        }
      };
    }
  }
}
