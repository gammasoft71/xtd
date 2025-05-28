#include <xtd/literals/int64>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd {
  inline namespace literals {
    namespace tests {
      class test_class_(int64_tests) {
        void test_method_(_i64_operator_on_long_double) {
          auto v = 42.0_i64;
          assert::is_true(is<int64>(v));
          assert::are_equal(42_i64, v);
        }
        
        void test_method_(_i64_operator_on_unsigned_long_long) {
          auto v = 42_i64;
          assert::is_true(is<int64>(v));
          assert::are_equal(42_i64, v);
        }
        
        void test_method_(_i64_operator_on_char_ptr) {
          auto v = "42"_i64;
          assert::is_true(is<int64>(v));
          assert::are_equal(42_i64, v);
        }
        
        void test_method_(_i64_operator_on_invalid_char_ptr) {
          assert::throws<xtd::format_exception>([] {"42str"_i64;});
        }
        
#if defined(__xtd__cpp_lib_char8_t)
        void test_method_(_i64_operator_on_char8_ptr) {
          auto v = u8"42"_i64;
          assert::is_true(is<int64>(v));
          assert::are_equal(42_i64, v);
        }
        
        void test_method_(_i64_operator_on_invalid_char8_ptr) {
          assert::throws<xtd::format_exception>([] {u8"42str"_i64;});
        }
#endif
        
        void test_method_(_i64_operator_on_char16_ptr) {
          auto v = u"42"_i64;
          assert::is_true(is<int64>(v));
          assert::are_equal(42_i64, v);
        }
        
        void test_method_(_i64_operator_on_invalid_char16_ptr) {
          assert::throws<xtd::format_exception>([] {u"42str"_i64;});
        }
        
        void test_method_(_i64_operator_on_char32_ptr) {
          auto v = U"42"_i64;
          assert::is_true(is<int64>(v));
          assert::are_equal(42_i64, v);
        }
        
        void test_method_(_i64_operator_on_invalid_char32_ptr) {
          assert::throws<xtd::format_exception>([] {U"42str"_i64;});
        }
        
        void test_method_(_i64_operator_on_wchar_ptr) {
          auto v = L"42"_i64;
          assert::is_true(is<int64>(v));
          assert::are_equal(42_i64, v);
        }
        
        void test_method_(_i64_operator_on_invalid_wchar_ptr) {
          assert::throws<xtd::format_exception>([] {L"42str"_i64;});
        }
        
        void test_method_(_s64_operator_on_long_double) {
          auto v = 42.0_s64;
          assert::is_true(is<int64>(v));
          assert::are_equal(42_s64, v);
        }
        
        void test_method_(_s64_operator_on_unsigned_long_long) {
          auto v = 42_s64;
          assert::is_true(is<int64>(v));
          assert::are_equal(42_s64, v);
        }
        
        void test_method_(_s64_operator_on_char_ptr) {
          auto v = "42"_s64;
          assert::is_true(is<int64>(v));
          assert::are_equal(42_s64, v);
        }
        
        void test_method_(_s64_operator_on_invalid_char_ptr) {
          assert::throws<xtd::format_exception>([] {"42str"_s64;});
        }
        
#if defined(__xtd__cpp_lib_char8_t)
        void test_method_(_s64_operator_on_char8_ptr) {
          auto v = u8"42"_s64;
          assert::is_true(is<int64>(v));
          assert::are_equal(42_s64, v);
        }
        
        void test_method_(_s64_operator_on_invalid_char8_ptr) {
          assert::throws<xtd::format_exception>([] {u8"42str"_s64;});
        }
#endif
        
        void test_method_(_s64_operator_on_char16_ptr) {
          auto v = u"42"_s64;
          assert::is_true(is<int64>(v));
          assert::are_equal(42_s64, v);
        }
        
        void test_method_(_s64_operator_on_invalid_char16_ptr) {
          assert::throws<xtd::format_exception>([] {u"42str"_s64;});
        }
        
        void test_method_(_s64_operator_on_char32_ptr) {
          auto v = U"42"_s64;
          assert::is_true(is<int64>(v));
          assert::are_equal(42_s64, v);
        }
        
        void test_method_(_s64_operator_on_invalid_char32_ptr) {
          assert::throws<xtd::format_exception>([] {U"42str"_s64;});
        }
        
        void test_method_(_s64_operator_on_wchar_ptr) {
          auto v = L"42"_s64;
          assert::is_true(is<int64>(v));
          assert::are_equal(42_s64, v);
        }
        
        void test_method_(_s64_operator_on_invalid_wchar_ptr) {
          assert::throws<xtd::format_exception>([] {L"42str"_s64;});
        }
      };
    }
  }
}
