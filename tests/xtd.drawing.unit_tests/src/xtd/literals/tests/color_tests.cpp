#include <xtd/drawing/color>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd {
  inline namespace literals {
    namespace tests {
      class test_class_(color_tests) {
        auto test_method_(_color_operator_on_char_ptr) {
          auto v = "dodger blue"_color;
          assert::is_instance_of<color>(v);
          assert::are_equal("color [dodger_blue]", v.to_string());
        }
        
        auto test_method_(_color_operator_on_char8_ptr) {
          auto v = u8"dodger blue"_color;
          assert::is_instance_of<color>(v);
          assert::are_equal("color [dodger_blue]", v.to_string());
        }
        
        auto test_method_(_color_operator_on_char16_ptr) {
          auto v = u"dodger blue"_color;
          assert::is_instance_of<color>(v);
          assert::are_equal("color [dodger_blue]", v.to_string());
        }
        
        auto test_method_(_color_operator_on_char32_ptr) {
          auto v = U"dodger blue"_color;
          assert::is_instance_of<color>(v);
          assert::are_equal("color [dodger_blue]", v.to_string());
        }
        
        auto test_method_(_color_operator_on_wchar_ptr) {
          auto v = L"dodger blue"_color;
          assert::is_instance_of<color>(v);
          assert::are_equal("color [dodger_blue]", v.to_string());
        }
      };
    }
  }
}
