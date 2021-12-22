#include <xtd/ustring.h>
#include <xtd/format_exception.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  enum class wday {
    sunday,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday
  };
  
  std::ostream& operator<<(std::ostream& os, wday d) {
    switch (d) {
      case wday::sunday: os << "sunday"; break;
      case wday::monday: os << "monday"; break;
      case wday::tuesday: os << "tuesday"; break;
      case wday::wednesday: os << "wednesday"; break;
      case wday::thursday: os << "thursday"; break;
      case wday::friday: os << "friday"; break;
      case wday::saturday: os << "saturday"; break;
    }
    return os;
  }
  
  class test_class_(test_wstring_enum_class_format) {
  public:
    void test_method_(format_sunday_with_default_argument) {
      assert::are_equal(L"sunday", xtd::ustring::format(L"{0}", wday::sunday), csf_);
    }
    
    void test_method_(format_monday_with_left_alignment) {
      assert::are_equal(L"    monday", ustring::format(L"{0,10}", wday::monday), csf_);
    }
    
    void test_method_(format_tuesday_with_right_alignment) {
      assert::are_equal(L"tuesday   ", ustring::format(L"{0, -10}", wday::tuesday), csf_);
    }
    
    void test_method_(format_wednesday_with_binary_argument) {
      assert::are_equal(L"11", xtd::ustring::format(L"{0:b}", wday::wednesday), csf_);
    }
    
    void test_method_(format_thursday_with_decimal_argument) {
      assert::are_equal(L"4", xtd::ustring::format(L"{0:d}", wday::thursday), csf_);
    }
    
    void test_method_(format_friday_with_general_argument) {
      assert::are_equal(L"friday", xtd::ustring::format(L"{0:g}", wday::friday), csf_);
    }
    
    void test_method_(format_saturday_with_octal_argument) {
      assert::are_equal(L"6", xtd::ustring::format(L"{0:o}", wday::saturday), csf_);
    }
    
    void test_method_(format_sunday_with_hexadecimal_argument) {
      assert::are_equal(L"0", xtd::ustring::format(L"{0:x}", wday::sunday), csf_);
    }
    
    void test_method_(format_tuesday_with_invalid_argument) {
      assert::throws<xtd::format_exception>([]{xtd::ustring::format(L"{0:e}", wday::tuesday);}, csf_);
    }
  };
}
