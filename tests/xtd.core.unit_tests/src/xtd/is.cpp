#include <xtd/is.h>
#include <xtd/literals.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {  
  class test_class_(test_is) {
  public:
    void test_method_(is_string_with_string) {
      string v;
      assert::is_true(is<string>(v), csf_);
    }
    
    void test_method_(is_string_without_string) {
      exception v;
      assert::is_false(is<string>(v), csf_);
    }

    void test_method_(is_string_with_const_string) {
      assert::is_true(is<ustring>(""_s), csf_);
    }
    
    void test_method_(is_string_without_const_string) {
      assert::is_false(is<string>(exception()), csf_);
    }
    
    void test_method_(is_bool_with_bool) {
      bool v = true;
      assert::is_true(is<bool>(v), csf_);
    }
    
    void test_method_(is_bool_without_bool) {
      int v = 42;
      assert::is_false(is<bool>(v), csf_);
    }
    
    void test_method_(is_decimal_t_with_decimal_t) {
      decimal_t v = 4.2;
      assert::is_true(is<decimal_t>(v), csf_);
    }
    
    void test_method_(is_decimal_t_without_decimal_t) {
      bool v = true;
      assert::is_false(is<decimal_t>(v), csf_);
    }
    
    void test_method_(is_double_with_double) {
      double v = 4.2;
      assert::is_true(is<double>(v), csf_);
    }
    
    void test_method_(is_double_without_double) {
      bool v = true;
      assert::is_false(is<double>(v), csf_);
    }
    
    void test_method_(is_float_with_float) {
      float v = 4.2f;
      assert::is_true(is<float>(v), csf_);
    }
    
    void test_method_(is_float_without_float) {
      bool v = true;
      assert::is_false(is<float>(v), csf_);
    }

    void test_method_(is_int8_t_with_int8_t) {
      int8_t v = 42;
      assert::is_true(is<int8_t>(v), csf_);
    }
    
    void test_method_(is_int8_t_without_int8_t) {
      bool v = true;
      assert::is_false(is<int8_t>(v), csf_);
    }

    void test_method_(is_int16_t_with_int16_t) {
      int16_t v = 42;
      assert::is_true(is<int16_t>(v), csf_);
    }
    
    void test_method_(is_int16_t_without_int16_t) {
      bool v = true;
      assert::is_false(is<int16_t>(v), csf_);
    }

    void test_method_(is_int32_t_with_int32_t) {
      int32_t v = 42;
      assert::is_true(is<int32_t>(v), csf_);
    }
    
    void test_method_(is_int32_t_without_int32_t) {
      bool v = true;
      assert::is_false(is<int32_t>(v), csf_);
    }

    void test_method_(is_int64_t_with_int64_t) {
      int64_t v = 42;
      assert::is_true(is<int64_t>(v), csf_);
    }
    
    void test_method_(is_int64_t_without_int64_t) {
      bool v = true;
      assert::is_false(is<int64_t>(v), csf_);
    }

    void test_method_(is_short_with_short) {
      short v = 42;
      assert::is_true(is<short>(v), csf_);
    }
    
    void test_method_(is_short_without_short) {
      bool v = true;
      assert::is_false(is<short>(v), csf_);
    }
    
    void test_method_(is_int_with_int) {
      int v = 42;
      assert::is_true(is<int>(v), csf_);
    }
    
    void test_method_(is_int_without_int) {
      bool v = true;
      assert::is_false(is<int>(v), csf_);
    }
    
    void test_method_(is_long_with_long) {
      long v = 42;
      assert::is_true(is<long>(v), csf_);
    }
    
    void test_method_(is_long_without_long) {
      bool v = true;
      assert::is_false(is<long>(v), csf_);
    }

    void test_method_(is_llong_t_with_llong_t) {
      llong_t v = 42;
      assert::is_true(is<llong_t>(v), csf_);
    }
    
    void test_method_(is_llong_t_without_llong_t) {
      bool v = true;
      assert::is_false(is<llong_t>(v), csf_);
    }

    void test_method_(is_uint8_t_with_uint8_t) {
      uint8_t v = 42;
      assert::is_true(is<uint8_t>(v), csf_);
    }
    
    void test_method_(is_uint8_t_without_uint8_t) {
      bool v = true;
      assert::is_false(is<uint8_t>(v), csf_);
    }
    
    void test_method_(is_uint16_t_with_uint16_t) {
      uint16_t v = 42;
      assert::is_true(is<uint16_t>(v), csf_);
    }
    
    void test_method_(is_uint16_t_without_uint16_t) {
      bool v = true;
      assert::is_false(is<uint16_t>(v), csf_);
    }
    
    void test_method_(is_uint32_t_with_uint32_t) {
      uint32_t v = 42;
      assert::is_true(is<uint32_t>(v), csf_);
    }
    
    void test_method_(is_uint32_t_without_uint32_t) {
      bool v = true;
      assert::is_false(is<uint32_t>(v), csf_);
    }
    
    void test_method_(is_uint64_t_with_uint64_t) {
      uint64_t v = 42;
      assert::is_true(is<uint64_t>(v), csf_);
    }
    
    void test_method_(is_uint64_t_without_uint64_t) {
      bool v = true;
      assert::is_false(is<uint64_t>(v), csf_);
    }
    
    void test_method_(is_ushort_with_ushort) {
      ushort v = 42;
      assert::is_true(is<ushort>(v), csf_);
    }
    
    void test_method_(is_ushort_without_ushort) {
      bool v = true;
      assert::is_false(is<ushort>(v), csf_);
    }

    void test_method_(is_uint_with_uint) {
      uint v = 42;
      assert::is_true(is<uint>(v), csf_);
    }
    
    void test_method_(is_uint_without_uint) {
      bool v = true;
      assert::is_false(is<uint>(v), csf_);
    }
    
    void test_method_(is_ulong_with_ulong) {
      ulong v = 42;
      assert::is_true(is<ulong>(v), csf_);
    }
    
    void test_method_(is_ulong_without_ulong) {
      bool v = true;
      assert::is_false(is<ulong>(v), csf_);
    }
    
    void test_method_(is_ullong_t_with_ullong_t) {
      ullong_t v = 42;
      assert::is_true(is<ullong_t>(v), csf_);
    }
    
    void test_method_(is_ullong_t_without_ullong_t) {
      bool v = true;
      assert::is_false(is<ullong_t>(v), csf_);
    }
  };
}
