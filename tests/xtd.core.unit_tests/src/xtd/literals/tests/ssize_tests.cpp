#include <xtd/literals/ssize>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd {
  inline namespace literals {
    namespace tests {
      class test_class_(ssize_tests) {
        auto test_method_(_sz_operator_on_long_double) {
          auto v = 42.0_sz;
          assert::is_true(is<ssize>(v));
          assert::are_equal(42_sz, v);
        }
        
        auto test_method_(_sz_operator_on_unsigned_long_long) {
          auto v = 42_sz;
          assert::is_true(is<ssize>(v));
          assert::are_equal(42_sz, v);
        }
        
        auto test_method_(_sz_operator_on_char_ptr) {
          auto v = "42"_sz;
          assert::is_true(is<ssize>(v));
          assert::are_equal(42_sz, v);
        }
        
        auto test_method_(_sz_operator_on_invalid_char_ptr) {
          assert::throws<xtd::format_exception>([] {[[maybe_unused]] auto result = "42str"_sz;});
        }
        
        auto test_method_(_sz_operator_on_char8_ptr) {
          auto v = u8"42"_sz;
          assert::is_true(is<ssize>(v));
          assert::are_equal(42_sz, v);
        }
        
        auto test_method_(_sz_operator_on_invalid_char8_ptr) {
          assert::throws<xtd::format_exception>([] {[[maybe_unused]] auto result = u8"42str"_sz;});
        }
        
        auto test_method_(_sz_operator_on_char16_ptr) {
          auto v = u"42"_sz;
          assert::is_true(is<ssize>(v));
          assert::are_equal(42_sz, v);
        }
        
        auto test_method_(_sz_operator_on_invalid_char16_ptr) {
          assert::throws<xtd::format_exception>([] {[[maybe_unused]] auto result = u"42str"_sz;});
        }
        
        auto test_method_(_sz_operator_on_char32_ptr) {
          auto v = U"42"_sz;
          assert::is_true(is<ssize>(v));
          assert::are_equal(42_sz, v);
        }
        
        auto test_method_(_sz_operator_on_invalid_char32_ptr) {
          assert::throws<xtd::format_exception>([] {[[maybe_unused]] auto result = U"42str"_sz;});
        }
        
        auto test_method_(_sz_operator_on_wchar_ptr) {
          auto v = L"42"_sz;
          assert::is_true(is<ssize>(v));
          assert::are_equal(42_sz, v);
        }
        
        auto test_method_(_sz_operator_on_invalid_wchar_ptr) {
          assert::throws<xtd::format_exception>([] {[[maybe_unused]] auto result = L"42str"_sz;});
        }
      };
    }
  }
}
