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

std::ostream& operator<<(std::ostream& os, day d) {
  switch (d) {
    case sunday: os << "sunday"; break;
    case monday: os << "monday"; break;
    case tuesday: os << "tuesday"; break;
    case wednesday: os << "wednesday"; break;
    case thursday: os << "thursday"; break;
    case friday: os << "friday"; break;
    case saturday: os << "saturday"; break;
  }
  return os;
}

namespace unit_tests {
  class test_class_(test_string_enum_format) {
  public:
    void test_method_(format_sunday_with_default_argument) {
      assert::are_equal("sunday", xtd::ustring::format("{0}", sunday), csf_);
    }
    
    void test_method_(format_monday_with_left_alignment) {
      assert::are_equal("    monday", ustring::format("{0,10}", monday), csf_);
    }
    
    void test_method_(format_tuesday_with_right_alignment) {
      assert::are_equal("tuesday   ", ustring::format("{0, -10}", tuesday), csf_);
    }
    
    void test_method_(format_wednesday_with_binary_argument) {
      assert::are_equal("11", xtd::ustring::format("{0:b}", wednesday), csf_);
    }
    
    void test_method_(format_thursday_with_decimal_argument) {
      assert::are_equal("4", xtd::ustring::format("{0:d}", thursday), csf_);
    }
    
    void test_method_(format_friday_with_general_argument) {
      assert::are_equal("friday", xtd::ustring::format("{0:g}", friday), csf_);
    }
    
    void test_method_(format_saturday_with_octal_argument) {
      assert::are_equal("6", xtd::ustring::format("{0:o}", saturday), csf_);
    }
    
    void test_method_(format_sunday_with_hexadecimal_argument) {
      assert::are_equal("0", xtd::ustring::format("{0:x}", sunday), csf_);
    }
    
    void test_method_(format_tuesday_with_invalid_argument) {
      assert::throws<xtd::format_exception>([]{xtd::ustring::format("{0:e}", tuesday);}, csf_);
    }
  };
}
