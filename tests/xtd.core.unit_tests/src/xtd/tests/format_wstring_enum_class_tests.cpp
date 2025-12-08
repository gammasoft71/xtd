#include <xtd/enum_class>
#include <xtd/format>
#include <xtd/format_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  enum class day {
    sunday,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday
  };
};

template<> struct xtd::enum_register<xtd::tests::day> {
  explicit operator auto() const noexcept {return xtd::enum_collection<tests::day> {{xtd::tests::day::sunday,  "sunday"}, {xtd::tests::day::monday, "monday"}, {xtd::tests::day::tuesday, "tuesday"}, {xtd::tests::day::wednesday, "wednesday"}, {xtd::tests::day::thursday, "thursday"}, {xtd::tests::day::friday, "friday"}, {xtd::tests::day::saturday, "saturday"}};}
};

namespace xtd::tests {
  class test_class_(format_wstring_enum_class_tests) {
    auto test_method_(format_sunday_with_default_argument) {
      assert::are_equal(L"sunday", format(L"{0}", day::sunday));
    }
    
    auto test_method_(format_monday_with_left_alignment) {
      assert::are_equal(L"    monday", string::format(L"{0,10}", day::monday));
    }
    
    auto test_method_(format_tuesday_with_right_alignment) {
      assert::are_equal(L"tuesday   ", string::format(L"{0, -10}", day::tuesday));
    }
    
    auto test_method_(format_wednesday_with_binary_argument) {
      assert::are_equal(L"11", format(L"{0:b}", day::wednesday));
    }
    
    auto test_method_(format_thursday_with_decimal_argument) {
      assert::are_equal(L"4", format(L"{0:d}", day::thursday));
    }
    
    auto test_method_(format_friday_with_general_argument) {
      assert::are_equal(L"friday", format(L"{0:g}", day::friday));
    }
    
    auto test_method_(format_saturday_with_octal_argument) {
      assert::are_equal(L"6", format(L"{0:o}", day::saturday));
    }
    
    auto test_method_(format_sunday_with_hexadecimal_argument) {
      assert::are_equal(L"0", format(L"{0:x}", day::sunday));
    }
    
    auto test_method_(format_tuesday_with_invalid_argument) {
      assert::throws<xtd::format_exception>([] {format(L"{0:e}", day::tuesday);});
    }
  };
}
