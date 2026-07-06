#include <xtd/literals/uint64>
#include <xtd/format_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd {
  inline namespace literals {
    namespace tests {
      class test_class_(uint64_tests) {
        auto test_method_(_u64_operator_on_long_double) {
          auto v = 42.0_u64;
          assert::is_true(is<uint64>(v));
          assert::are_equal(42_u64, v);
        }
        
        auto test_method_(_u64_operator_on_unsigned_long_long) {
          auto v = 42_u64;
          assert::is_true(is<uint64>(v));
          assert::are_equal(42_u64, v);
        }
        
        auto test_method_(_u64_operator_on_char_ptr) {
          auto v = "42"_u64;
          assert::is_true(is<uint64>(v));
          assert::are_equal(42_u64, v);
        }
        
        auto test_method_(_u64_operator_on_invalid_char_ptr) {
          assert::throws<xtd::format_exception>([] {[[maybe_unused]] auto __ = "42str"_u64;});
        }
        
        auto test_method_(_u64_operator_on_char8_ptr) {
          auto v = u8"42"_u64;
          assert::is_true(is<uint64>(v));
          assert::are_equal(42_u64, v);
        }
        
        auto test_method_(_u64_operator_on_invalid_char8_ptr) {
          assert::throws<xtd::format_exception>([] {[[maybe_unused]] auto __ = u8"42str"_u64;});
        }
        
        auto test_method_(_u64_operator_on_char16_ptr) {
          auto v = u"42"_u64;
          assert::is_true(is<uint64>(v));
          assert::are_equal(42_u64, v);
        }
        
        auto test_method_(_u64_operator_on_invalid_char16_ptr) {
          assert::throws<xtd::format_exception>([] {[[maybe_unused]] auto __ = u"42str"_u64;});
        }
        
        auto test_method_(_u64_operator_on_char32_ptr) {
          auto v = U"42"_u64;
          assert::is_true(is<uint64>(v));
          assert::are_equal(42_u64, v);
        }
        
        auto test_method_(_u64_operator_on_invalid_char32_ptr) {
          assert::throws<xtd::format_exception>([] {[[maybe_unused]] auto __ = U"42str"_u64;});
        }
        
        auto test_method_(_u64_operator_on_wchar_ptr) {
          auto v = L"42"_u64;
          assert::is_true(is<uint64>(v));
          assert::are_equal(42_u64, v);
        }
        
        auto test_method_(_u64_operator_on_invalid_wchar_ptr) {
          assert::throws<xtd::format_exception>([] {[[maybe_unused]] auto __ = L"42str"_u64;});
        }
      };
    }
  }
}
