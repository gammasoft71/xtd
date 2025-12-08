#include <xtd/literals/single>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd {
  inline namespace literals {
    namespace tests {
      class test_class_(single_tests) {
        auto test_method_(_f_operator_on_long_double) {
          auto v = 42.0_f;
          assert::is_true(is<float>(v));
          assert::are_equal(42.0_f, v);
        }
        
        auto test_method_(_f_operator_on_unsigned_long_long) {
          auto v = 42_f;
          assert::is_true(is<float>(v));
          assert::are_equal(42.0_f, v);
        }
        
        auto test_method_(_f_operator_on_char_ptr) {
          auto v = "42.0"_f;
          assert::is_true(is<float>(v));
          assert::are_equal(42.0_f, v);
        }
        
        auto test_method_(_f_operator_on_invalid_char_ptr) {
          assert::throws<xtd::format_exception>([] {"42str"_f;});
        }
        
        auto test_method_(_f_operator_on_char8_ptr) {
          auto v = u8"42.0"_f;
          assert::is_true(is<float>(v));
          assert::are_equal(42.0_f, v);
        }
        
        auto test_method_(_f_operator_on_invalid_char8_ptr) {
          assert::throws<xtd::format_exception>([] {u8"42str"_f;});
        }
        
        auto test_method_(_f_operator_on_char16_ptr) {
          auto v = u"42.0"_f;
          assert::is_true(is<float>(v));
          assert::are_equal(42.0_f, v);
        }
        
        auto test_method_(_f_operator_on_invalid_char16_ptr) {
          assert::throws<xtd::format_exception>([] {u"42str"_f;});
        }
        
        auto test_method_(_f_operator_on_char32_ptr) {
          auto v = U"42.0"_f;
          assert::is_true(is<float>(v));
          assert::are_equal(42.0_f, v);
        }
        
        auto test_method_(_f_operator_on_invalid_char32_ptr) {
          assert::throws<xtd::format_exception>([] {U"42str"_f;});
        }
        
        auto test_method_(_f_operator_on_wchar_ptr) {
          auto v = L"42.0"_f;
          assert::is_true(is<float>(v));
          assert::are_equal(42.0_f, v);
        }
        
        auto test_method_(_f_operator_on_invalid_wchar_ptr) {
          assert::throws<xtd::format_exception>([] {L"42str"_f;});
        }
      };
    }
  }
}
