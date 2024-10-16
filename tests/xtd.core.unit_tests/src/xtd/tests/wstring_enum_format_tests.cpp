#include <xtd/string>
#include <xtd/format_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

enum day {
  sunday,
  monday,
  tuesday,
  wednesday,
  thursday,
  friday,
  saturday
};

std::wostream& operator <<(std::wostream& os, day d) {
  switch (d) {
    case sunday: os << L"sunday"; break;
    case monday: os << L"monday"; break;
    case tuesday: os << L"tuesday"; break;
    case wednesday: os << L"wednesday"; break;
    case thursday: os << L"thursday"; break;
    case friday: os << L"friday"; break;
    case saturday: os << L"saturday"; break;
  }
  return os;
}

namespace xtd::tests {
  class test_class_(wstring_enum_format_tests) {
    void test_method_(format_sunday_with_default_argument) {
      assert::are_equal(L"sunday", xtd::string::format(L"{0}", sunday));
    }
    
    void test_method_(format_monday_with_left_alignment) {
      assert::are_equal(L"    monday", string::format(L"{0,10}", monday));
    }
    
    void test_method_(format_tuesday_with_right_alignment) {
      assert::are_equal(L"tuesday   ", string::format(L"{0, -10}", tuesday));
    }
    
    void test_method_(format_wednesday_with_binary_argument) {
      assert::are_equal(L"11", xtd::string::format(L"{0:b}", wednesday));
    }
    
    void test_method_(format_thursday_with_decimal_argument) {
      assert::are_equal(L"4", xtd::string::format(L"{0:d}", thursday));
    }
    
    void test_method_(format_friday_with_general_argument) {
      assert::are_equal(L"friday", xtd::string::format(L"{0:g}", friday));
    }
    
    void test_method_(format_saturday_with_octal_argument) {
      assert::are_equal(L"6", xtd::string::format(L"{0:o}", saturday));
    }
    
    void test_method_(format_sunday_with_hexadecimal_argument) {
      assert::are_equal(L"0", xtd::string::format(L"{0:x}", sunday));
    }
    
    void test_method_(format_tuesday_with_invalid_argument) {
      assert::throws<xtd::format_exception>([] {xtd::string::format(L"{0:e}", tuesday);});
    }
  };
}
