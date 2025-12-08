#include <xtd/format>
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

template<> struct xtd::enum_register<day> {
  explicit operator auto() const noexcept {return xtd::enum_collection<day> {{day::sunday,  "sunday"}, {day::monday, "monday"}, {day::tuesday, "tuesday"}, {day::wednesday, "wednesday"}, {day::thursday, "thursday"}, {day::friday, "friday"}, {day::saturday, "saturday"}};}
};

namespace xtd::tests {
  class test_class_(format_wstring_enum_tests) {
    auto test_method_(format_sunday_with_default_argument) {
      assert::are_equal(L"sunday", format(L"{0}", sunday));
    }
    
    auto test_method_(format_monday_with_left_alignment) {
      assert::are_equal(L"    monday", string::format(L"{0,10}", monday));
    }
    
    auto test_method_(format_tuesday_with_right_alignment) {
      assert::are_equal(L"tuesday   ", string::format(L"{0, -10}", tuesday));
    }
    
    auto test_method_(format_wednesday_with_binary_argument) {
      assert::are_equal(L"11", format(L"{0:b}", wednesday));
    }
    
    auto test_method_(format_thursday_with_decimal_argument) {
      assert::are_equal(L"4", format(L"{0:d}", thursday));
    }
    
    auto test_method_(format_friday_with_general_argument) {
      assert::are_equal(L"friday", format(L"{0:g}", friday));
    }
    
    auto test_method_(format_saturday_with_octal_argument) {
      assert::are_equal(L"6", format(L"{0:o}", saturday));
    }
    
    auto test_method_(format_sunday_with_hexadecimal_argument) {
      assert::are_equal(L"0", format(L"{0:x}", sunday));
    }
    
    auto test_method_(format_tuesday_with_invalid_argument) {
      assert::throws<xtd::format_exception>([] {format(L"{0:e}", tuesday);});
    }
  };
}
