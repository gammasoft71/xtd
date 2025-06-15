#include <xtd/literals/translator>
#include <xtd/environment>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd {
  inline namespace literals {
    namespace tests {
      class test_class_(translator_tests) {
        void test_method_(_t_operator_on_char_ptr) {
          auto v = "Belgium"_t;
          assert::are_equal("Belgium"_t, string {v});
        }
        
        void test_method_(_t_operator_on_char8_ptr) {
          auto v = u8"Belgium"_t;
          assert::are_equal(u8"Belgium"_t, string {v});
        }
        
        void test_method_(_t_operator_on_char16_ptr) {
          auto v = u"Belgium"_t;
          assert::are_equal("Belgium"_t, string {v});
        }
        
        void test_method_(_t_operator_on_char32_ptr) {
          auto v = U"Belgium"_t;
          assert::are_equal("Belgium"_t, string {v});
        }
        
        void test_method_(_t_operator_on_wchar_ptr) {
          auto v = L"Belgium"_t;
          assert::are_equal("Belgium"_t, string {v});
        }
      };
    }
  }
}
