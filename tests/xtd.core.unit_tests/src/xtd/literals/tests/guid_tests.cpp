#include <xtd/literals/guid>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::net;
using namespace xtd::tunit;

namespace xtd {
  inline namespace literals {
    namespace tests {
      class test_class_(guid_tests) {
        auto test_method_(_guid_operator_on_char_ptr) {
          auto v = "1dae5efa-d701-42b9-8d61-09d3b38f802a"_guid;
          assert::is_instance_of<guid>(v);
          assert::are_equal("1dae5efa-d701-42b9-8d61-09d3b38f802a", v.to_string());
        }
        
        auto test_method_(_guid_operator_on_char8_ptr) {
          auto v = u8"1dae5efa-d701-42b9-8d61-09d3b38f802a"_guid;
          assert::is_instance_of<guid>(v);
          assert::are_equal("1dae5efa-d701-42b9-8d61-09d3b38f802a", v.to_string());
        }
        
        auto test_method_(_guid_operator_on_char16_ptr) {
          auto v = u"1dae5efa-d701-42b9-8d61-09d3b38f802a"_guid;
          assert::is_instance_of<guid>(v);
          assert::are_equal("1dae5efa-d701-42b9-8d61-09d3b38f802a", v.to_string());
        }
        
        auto test_method_(_guid_operator_on_char32_ptr) {
          auto v = U"1dae5efa-d701-42b9-8d61-09d3b38f802a"_guid;
          assert::is_instance_of<guid>(v);
          assert::are_equal("1dae5efa-d701-42b9-8d61-09d3b38f802a", v.to_string());
        }
        
        auto test_method_(_guid_operator_on_wchar_ptr) {
          auto v = L"1dae5efa-d701-42b9-8d61-09d3b38f802a"_guid;
          assert::is_instance_of<guid>(v);
          assert::are_equal("1dae5efa-d701-42b9-8d61-09d3b38f802a", v.to_string());
        }
      };
    }
  }
}
