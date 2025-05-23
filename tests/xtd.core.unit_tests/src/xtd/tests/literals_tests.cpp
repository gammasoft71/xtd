#include <xtd/literals>
#include <xtd/is>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(lietarls_tests) {
    void test_method_(operator_b_on_char_ptr) {
      auto b = "42"_b;
      assert::is_true(is<byte>(b));
      assert::are_equal(42_b, b);
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(operator_b_on_char8_ptr) {
      auto b = u8"42"_b;
      assert::is_true(is<byte>(b));
      assert::are_equal(42_b, b);
    }
#endif
    
    void test_method_(operator_b_on_char16_ptr) {
      auto b = u"42"_b;
      assert::is_true(is<byte>(b));
      assert::are_equal(42_b, b);
    }
    
    void test_method_(operator_b_on_char32_ptr) {
      auto b = U"42"_b;
      assert::is_true(is<byte>(b));
      assert::are_equal(42_b, b);
    }
    
    void test_method_(operator_b_on_wchar_ptr) {
      auto b = L"42"_b;
      assert::is_true(is<byte>(b));
      assert::are_equal(42_b, b);
    }

    void test_method_(operator_b_on_long_double) {
      auto b = 42.0_b;
      assert::is_true(is<byte>(b));
      assert::are_equal(42_b, b);
    }

    void test_method_(operator_b_on_unsigned_long_long) {
      auto b = 42_b;
      assert::is_true(is<byte>(b));
      assert::are_equal(42_b, b);
    }

    void test_method_(operator_s_on_char_ptr) {
      auto s = "string"_s;
      assert::is_instance_of<string>(s);
      assert::are_equal("string", s);
    }
    
#if defined(__xtd__cpp_lib_char8_t)
    void test_method_(operator_s_on_char8_ptr) {
      auto s = u8"string"_s;
      assert::is_instance_of<string>(s);
      assert::are_equal("string", s);
    }
#endif
    
    void test_method_(operator_s_on_char16_ptr) {
      auto s = u"string"_s;
      assert::is_instance_of<string>(s);
      assert::are_equal("string", s);
    }
    
    void test_method_(operator_s_on_char32_ptr) {
      auto s = U"string"_s;
      assert::is_instance_of<string>(s);
      assert::are_equal("string", s);
    }

    void test_method_(operator_sd_on_long_double) {
      auto s = 42.0_sd;
      assert::is_instance_of<string>(s);
      assert::are_equal("42", s);
    }

    void test_method_(operator_sd_on_unsigned_long_long) {
      auto s = 42_sd;
      assert::is_instance_of<string>(s);
      assert::are_equal("42", s);
    }
  };
}
