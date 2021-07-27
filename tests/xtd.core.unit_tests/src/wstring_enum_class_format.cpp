#include <xtd/ustring.h>
#include <xtd/format_exception.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::tunit;

enum class day_of_week {
  sunday,
  monday,
  tuesday,
  wednesday,
  thursday,
  friday,
  saturday
};

std::ostream& operator<<(std::ostream& os, day_of_week d) {
  switch (d) {
    case day_of_week::sunday: os << "sunday"; break;
    case day_of_week::monday: os << "monday"; break;
    case day_of_week::tuesday: os << "tuesday"; break;
    case day_of_week::wednesday: os << "wednesday"; break;
    case day_of_week::thursday: os << "thursday"; break;
    case day_of_week::friday: os << "friday"; break;
    case day_of_week::saturday: os << "saturday"; break;
  }
  return os;
}

namespace unit_tests {
  class test_class_(test_wstring_enum_class_format) {
  public:
    void test_method_(format_sunday_with_default_argument) {
      assert::are_equal(L"sunday", xtd::ustring::format(L"{0}", day_of_week::sunday));
    }
    
    void test_method_(format_monday_with_left_alignment) {
      assert::are_equal(L"    monday", ustring::format(L"{0,10}", day_of_week::monday));
    }
    
    void test_method_(format_tuesday_with_right_alignment) {
      assert::are_equal(L"tuesday   ", ustring::format(L"{0, -10}", day_of_week::tuesday));
    }
    
    void test_method_(format_wednesday_with_binary_argument) {
      assert::are_equal(L"11", xtd::ustring::format(L"{0:b}", day_of_week::wednesday));
    }
    
    void test_method_(format_thursday_with_decimal_argument) {
      assert::are_equal(L"4", xtd::ustring::format(L"{0:d}", day_of_week::thursday));
    }
    
    void test_method_(format_friday_with_general_argument) {
      assert::are_equal(L"friday", xtd::ustring::format(L"{0:g}", day_of_week::friday));
    }
    
    void test_method_(format_saturday_with_octal_argument) {
      assert::are_equal(L"6", xtd::ustring::format(L"{0:o}", day_of_week::saturday));
    }
    
    void test_method_(format_sunday_with_hexadecimal_argument) {
      assert::are_equal(L"0", xtd::ustring::format(L"{0:x}", day_of_week::sunday));
    }
    
    void test_method_(format_tuesday_with_invalid_argument) {
      assert::throws<xtd::format_exception>([]{xtd::ustring::format(L"{0:e}", day_of_week::tuesday);});
    }
  };
}
