#include <xtd/strings>
#include <xtd/tunit>

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  template <typename Value>
  class test_numeric_parse_string;
  
  test_class_attribute<test_numeric_parse_string<char>> test_numeric_parse_string_class_char_attr {"test_numeric_parse_string<char>"};
  test_class_attribute<test_numeric_parse_string<unsigned char>> test_numeric_parse_string_class_unsigned_char_attr {"test_numeric_parse_string<unsigned char>"};
  test_class_attribute<test_numeric_parse_string<short>> test_numeric_parse_string_class_short_attr {"test_numeric_parse_string<short>"};
  test_class_attribute<test_numeric_parse_string<unsigned short>> test_numeric_parse_string_class_unsigned_short_attr {"test_numeric_parse_string<unsigned short>"};
  test_class_attribute<test_numeric_parse_string<int>> test_numeric_parse_string_class_int_attr {"test_numeric_parse_string<int>"};
  test_class_attribute<test_numeric_parse_string<unsigned int>> test_numeric_parse_string_class_unsigned_int_attr {"test_numeric_parse_string<unsigned int>"};
  test_class_attribute<test_numeric_parse_string<long>> test_numeric_parse_string_class_long_attr {"test_numeric_parse_string<long>"};
  test_class_attribute<test_numeric_parse_string<unsigned long>> test_numeric_parse_string_class_unsigned_long_attr {"test_numeric_parse_string<unsigned long>"};
  test_class_attribute<test_numeric_parse_string<long long>> test_numeric_parse_string_class_long_long_attr {"test_numeric_parse_string<long long>"};
  test_class_attribute<test_numeric_parse_string<unsigned long long>> test_numeric_parse_string_class_unsigned_long_long_attr {"test_numeric_parse_string<unsigned long long>"};
  test_class_attribute<test_numeric_parse_string<int8_t>> test_numeric_parse_string_class_int8_t_attr {"test_numeric_parse_string<int8_t>"};
  test_class_attribute<test_numeric_parse_string<int16_t>> test_numeric_parse_string_class_int16_t_attr {"test_numeric_parse_string<int16_t>"};
  test_class_attribute<test_numeric_parse_string<int32_t>> test_numeric_parse_string_class_int32_t_attr {"test_numeric_parse_string<int32_t>"};
  test_class_attribute<test_numeric_parse_string<int64_t>> test_numeric_parse_string_class_int64_t_attr {"test_numeric_parse_string<int64_t>"};
  test_class_attribute<test_numeric_parse_string<intptr_t>> test_numeric_parse_string_class_intptr_t_attr {"test_numeric_parse_string<intptr_t>"};
  test_class_attribute<test_numeric_parse_string<ptrdiff_t>> test_numeric_parse_string_class_ptrdiff_t_attr {"test_numeric_parse_string<ptrdiff_t>"};
  test_class_attribute<test_numeric_parse_string<size_t>> test_numeric_parse_string_class_size_t_attr {"test_numeric_parse_string<size_t>"};
  test_class_attribute<test_numeric_parse_string<uint8_t>> test_numeric_parse_string_class_uint8_t_attr {"test_numeric_parse_string<uint8_t>"};
  test_class_attribute<test_numeric_parse_string<uint16_t>> test_numeric_parse_string_class_uint16_t_attr {"test_numeric_parse_string<uint16_t>"};
  test_class_attribute<test_numeric_parse_string<uint32_t>> test_numeric_parse_string_class_uint32_t_attr {"test_numeric_parse_string<uint32_t>"};
  test_class_attribute<test_numeric_parse_string<uint64_t>> test_numeric_parse_string_class_uint64_t_attr {"test_numeric_parse_string<uint64_t>"};
  test_class_attribute<test_numeric_parse_string<uintptr_t>> test_numeric_parse_string_class_uintptr_t_attr {"test_numeric_parse_string<uintptr_t>"};
  
  template <typename Value>
  class test_numeric_parse_string : public test_class {
  public:
    void test_method_(parse_default) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("42"));
    }
    
    void test_method_(parse_default_with_leading_plus_sign) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("+42"));
    }
    
    void test_method_(parse_default_with_two_leading_plus_sign) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("++42");});
    }
    
    void test_method_(parse_default_with_leading_minus_sign) {
      if (std::is_signed<Value>::value)
        assert::are_equal(static_cast<Value>(-42), xtd::parse<Value>("-42"));
      else
        assert::throws<std::invalid_argument>([]{xtd::parse<Value>("-42");});
    }
    
    void test_method_(parse_default_with_two_leading_minus_sign) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("--42");});
    }

    void test_method_(invalid_parse_default) {
      assert::throws<std::invalid_argument>([]{xtd::parse<Value>("z42");});
    }
    
    void test_method_(parse_with_number_styles_none) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("42", number_styles::none));
    }
    
    void test_method_(parse_with_number_styles_integer) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("42", number_styles::integer));
    }
    
    void test_method_(parse_with_number_styles_binary) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("0b101010", number_styles::binary_number));
    }

    void test_method_(parse_with_number_styles_octal) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("052", number_styles::octal_number));
    }

    void test_method_(parse_with_number_styles_hexa) {
      assert::are_equal(static_cast<Value>(42), xtd::parse<Value>("0x2A", number_styles::hex_number));
    }
  };
}
