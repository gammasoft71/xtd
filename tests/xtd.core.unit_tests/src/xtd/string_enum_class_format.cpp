#include <xtd/ustring.h>
#include <xtd/format_exception.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  enum class day {
    sunday,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday
  };
  
  std::ostream& operator<<(std::ostream& os, unit_tests::day d) {
    switch (d) {
      case unit_tests::day::sunday: os << "sunday"; break;
      case unit_tests::day::monday: os << "monday"; break;
      case unit_tests::day::tuesday: os << "tuesday"; break;
      case unit_tests::day::wednesday: os << "wednesday"; break;
      case unit_tests::day::thursday: os << "thursday"; break;
      case unit_tests::day::friday: os << "friday"; break;
      case unit_tests::day::saturday: os << "saturday"; break;
    }
    return os;
  }
}

namespace unit_tests {
  class test_class_(test_string_enum_class_format) {
  public:
    void test_method_(format_sunday_with_default_argument) {
      assert::are_equal("sunday", xtd::ustring::format("{0}", day::sunday), csf_);
    }
    
    void test_method_(format_monday_with_left_alignment) {
      assert::are_equal("    monday", ustring::format("{0,10}", day::monday), csf_);
    }
    
    void test_method_(format_tuesday_with_right_alignment) {
      assert::are_equal("tuesday   ", ustring::format("{0, -10}", day::tuesday), csf_);
    }
    
    void test_method_(format_wednesday_with_binary_argument) {
      assert::are_equal("11", xtd::ustring::format("{0:b}", day::wednesday), csf_);
    }
    
    void test_method_(format_thursday_with_decimal_argument) {
      assert::are_equal("4", xtd::ustring::format("{0:d}", day::thursday), csf_);
    }
    
    void test_method_(format_friday_with_general_argument) {
      assert::are_equal("friday", xtd::ustring::format("{0:g}", day::friday), csf_);
    }
    
    void test_method_(format_saturday_with_octal_argument) {
      assert::are_equal("6", xtd::ustring::format("{0:o}", day::saturday), csf_);
    }
    
    void test_method_(format_sunday_with_hexadecimal_argument) {
      assert::are_equal("0", xtd::ustring::format("{0:x}", day::sunday), csf_);
    }
    
    void test_method_(format_tuesday_with_invalid_argument) {
      assert::throws<xtd::format_exception>([] {xtd::ustring::format("{0:e}", day::tuesday);}, csf_);
    }
  };
}
