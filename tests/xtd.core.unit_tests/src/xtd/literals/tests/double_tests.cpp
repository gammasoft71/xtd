#include <xtd/literals/double>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd {
  inline namespace literals {
    namespace tests {
      class test_class_(double_tests) {
        auto test_method_(_d_operator_on_long_double) {
          auto v = 42.0_d;
          assert::is_true(is<double>(v));
          assert::are_equal(42.0_d, v);
        }
        
        auto test_method_(_d_operator_on_unsigned_long_long) {
          auto v = 42_d;
          assert::is_true(is<double>(v));
          assert::are_equal(42.0_d, v);
        }
        
        auto test_method_(_d_operator_on_char_ptr) {
          auto v = "42.0"_d;
          assert::is_true(is<double>(v));
          assert::are_equal(42.0_d, v);
        }
        
        auto test_method_(_d_operator_on_invalid_char_ptr) {
          assert::throws<xtd::format_exception>([] {"42str"_d;});
        }
        
        auto test_method_(_d_operator_on_char8_ptr) {
          auto v = u8"42.0"_d;
          assert::is_true(is<double>(v));
          assert::are_equal(42.0_d, v);
        }
        
        auto test_method_(_d_operator_on_invalid_char8_ptr) {
          assert::throws<xtd::format_exception>([] {u8"42str"_d;});
        }
        
        auto test_method_(_d_operator_on_char16_ptr) {
          auto v = u"42.0"_d;
          assert::is_true(is<double>(v));
          assert::are_equal(42.0_d, v);
        }
        
        auto test_method_(_d_operator_on_invalid_char16_ptr) {
          assert::throws<xtd::format_exception>([] {u"42str"_d;});
        }
        
        auto test_method_(_d_operator_on_char32_ptr) {
          auto v = U"42.0"_d;
          assert::is_true(is<double>(v));
          assert::are_equal(42.0_d, v);
        }
        
        auto test_method_(_d_operator_on_invalid_char32_ptr) {
          assert::throws<xtd::format_exception>([] {U"42str"_d;});
        }
        
        auto test_method_(_d_operator_on_wchar_ptr) {
          auto v = L"42.0"_d;
          assert::is_true(is<double>(v));
          assert::are_equal(42.0_d, v);
        }
        
        auto test_method_(_d_operator_on_invalid_wchar_ptr) {
          assert::throws<xtd::format_exception>([] {L"42str"_d;});
        }
      };
    }
  }
}
