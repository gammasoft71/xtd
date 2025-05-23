#include <xtd/literals>
#include <xtd/is>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(lietarls_tests) {
    void test_method_(_b_operator_on_char_ptr) {
      auto v = "42"_b;
      assert::is_true(is<byte>(v));
      assert::are_equal(42_b, v);
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(_b_operator_on_char8_ptr) {
      auto v = u8"42"_b;
      assert::is_true(is<byte>(v));
      assert::are_equal(42_b, v);
    }
#endif
    
    void test_method_(_b_operator_on_char16_ptr) {
      auto v = u"42"_b;
      assert::is_true(is<byte>(v));
      assert::are_equal(42_b, v);
    }
    
    void test_method_(_b_operator_on_char32_ptr) {
      auto v = U"42"_b;
      assert::is_true(is<byte>(v));
      assert::are_equal(42_b, v);
    }
    
    void test_method_(_b_operator_on_wchar_ptr) {
      auto v = L"42"_b;
      assert::is_true(is<byte>(v));
      assert::are_equal(42_b, v);
    }

    void test_method_(_b_operator_on_long_double) {
      auto v = 42.0_b;
      assert::is_true(is<byte>(v));
      assert::are_equal(42_b, v);
    }

    void test_method_(_b_operator_on_unsigned_long_long) {
      auto v = 42_b;
      assert::is_true(is<byte>(v));
      assert::are_equal(42_b, v);
    }

    void test_method_(_d_operator_on_char_ptr) {
      auto v = "42.0"_d;
      assert::is_true(is<double>(v));
      assert::are_equal(42.0_d, v);
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(_d_operator_on_char8_ptr) {
      auto v = u8"42.0"_d;
      assert::is_true(is<double>(v));
      assert::are_equal(42.0_d, v);
    }
#endif
    
    void test_method_(_d_operator_on_char16_ptr) {
      auto v = u"42.0"_d;
      assert::is_true(is<double>(v));
      assert::are_equal(42.0_d, v);
    }
    
    void test_method_(_d_operator_on_char32_ptr) {
      auto v = U"42.0"_d;
      assert::is_true(is<double>(v));
      assert::are_equal(42.0_d, v);
    }
    
    void test_method_(_d_operator_on_wchar_ptr) {
      auto v = L"42.0"_d;
      assert::is_true(is<double>(v));
      assert::are_equal(42.0_d, v);
    }
    
    void test_method_(_d_operator_on_long_double) {
      auto v = 42.0_d;
      assert::is_true(is<double>(v));
      assert::are_equal(42.0_d, v);
    }
    
    void test_method_(_d_operator_on_unsigned_long_long) {
      auto v = 42_d;
      assert::is_true(is<double>(v));
      assert::are_equal(42.0_d, v);
    }

    void test_method_(_f_operator_on_char_ptr) {
      auto v = "42.0"_f;
      assert::is_true(is<float>(v));
      assert::are_equal(42.0_f, v);
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(_f_operator_on_char8_ptr) {
      auto v = u8"42.0"_f;
      assert::is_true(is<float>(v));
      assert::are_equal(42.0_f, v);
    }
#endif
    
    void test_method_(_f_operator_on_char16_ptr) {
      auto v = u"42.0"_f;
      assert::is_true(is<float>(v));
      assert::are_equal(42.0_f, v);
    }
    
    void test_method_(_f_operator_on_char32_ptr) {
      auto v = U"42.0"_f;
      assert::is_true(is<float>(v));
      assert::are_equal(42.0_f, v);
    }
    
    void test_method_(_f_operator_on_wchar_ptr) {
      auto v = L"42.0"_f;
      assert::is_true(is<float>(v));
      assert::are_equal(42.0_f, v);
    }
    
    void test_method_(_f_operator_on_long_double) {
      auto v = 42.0_f;
      assert::is_true(is<float>(v));
      assert::are_equal(42.0_f, v);
    }
    
    void test_method_(_f_operator_on_unsigned_long_long) {
      auto v = 42_f;
      assert::is_true(is<float>(v));
      assert::are_equal(42.0_f, v);
    }

    void test_method_(_s_operator_on_char_ptr) {
      auto v = "string"_s;
      assert::is_instance_of<string>(v);
      assert::are_equal("string", v);
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(_s_operator_on_char8_ptr) {
      auto v = u8"string"_s;
      assert::is_instance_of<string>(v);
      assert::are_equal("string", v);
    }
#endif
    
    void test_method_(_s_operator_on_char16_ptr) {
      auto v = u"string"_s;
      assert::is_instance_of<string>(v);
      assert::are_equal("string", v);
    }
    
    void test_method_(_s_operator_on_char32_ptr) {
      auto v = U"string"_s;
      assert::is_instance_of<string>(v);
      assert::are_equal("string", v);
    }

    void test_method_(_sd_operator_on_long_double) {
      auto v = 42.0_sd;
      assert::is_instance_of<string>(v);
      assert::are_equal("42", v);
    }

    void test_method_(_sd_operator_on_unsigned_long_long) {
      auto v = 42_sd;
      assert::is_instance_of<string>(v);
      assert::are_equal("42", v);
    }
  };
}
