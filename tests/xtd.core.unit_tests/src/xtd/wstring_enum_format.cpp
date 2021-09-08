#include <xtd/ustring.h>
#include <xtd/format_exception.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace std::string_literals;
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

std::wostream& operator<<(std::wostream& os, day d) {
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

namespace unit_tests {
  class test_class_(test_wstring_enum_format) {
  public:
    void test_method_(format_sunday_with_default_argument) {
      assert::are_equal(L"sunday", xtd::ustring::format(L"{0}", sunday), csf_);
    }
    
    void test_method_(format_monday_with_left_alignment) {
      assert::are_equal(L"    monday", ustring::format(L"{0,10}", monday), csf_);
    }
    
    void test_method_(format_tuesday_with_right_alignment) {
      assert::are_equal(L"tuesday   ", ustring::format(L"{0, -10}", tuesday), csf_);
    }
    
    void test_method_(format_wednesday_with_binary_argument) {
      assert::are_equal(L"11", xtd::ustring::format(L"{0:b}", wednesday), csf_);
    }
    
    void test_method_(format_thursday_with_decimal_argument) {
      assert::are_equal(L"4", xtd::ustring::format(L"{0:d}", thursday), csf_);
    }
    
    void test_method_(format_friday_with_general_argument) {
      assert::are_equal(L"friday", xtd::ustring::format(L"{0:g}", friday), csf_);
    }
    
    void test_method_(format_saturday_with_octal_argument) {
      assert::are_equal(L"6", xtd::ustring::format(L"{0:o}", saturday), csf_);
    }
    
    void test_method_(format_sunday_with_hexadecimal_argument) {
      assert::are_equal(L"0", xtd::ustring::format(L"{0:x}", sunday), csf_);
    }
    
    void test_method_(format_tuesday_with_invalid_argument) {
      assert::throws<xtd::format_exception>([]{xtd::ustring::format(L"{0:e}", tuesday);}, csf_);
    }
  };
}
