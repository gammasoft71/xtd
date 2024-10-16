#include <xtd/enum_class>
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
  class test_class_(string_enum_class_format_tests) {
    void test_method_(format_sunday_with_default_argument) {
      assert::are_equal("sunday", xtd::string::format("{0}", day::sunday));
    }
    
    void test_method_(format_monday_with_left_alignment) {
      assert::are_equal("    monday", string::format("{0,10}", day::monday));
    }
    
    void test_method_(format_tuesday_with_right_alignment) {
      assert::are_equal("tuesday   ", string::format("{0, -10}", day::tuesday));
    }
    
    void test_method_(format_wednesday_with_binary_argument) {
      assert::are_equal("11", xtd::string::format("{0:b}", day::wednesday));
    }
    
    void test_method_(format_thursday_with_decimal_argument) {
      assert::are_equal("4", xtd::string::format("{0:d}", day::thursday));
    }
    
    void test_method_(format_friday_with_general_argument) {
      assert::are_equal("friday", xtd::string::format("{0:g}", day::friday));
    }
    
    void test_method_(format_saturday_with_octal_argument) {
      assert::are_equal("6", xtd::string::format("{0:o}", day::saturday));
    }
    
    void test_method_(format_sunday_with_hexadecimal_argument) {
      assert::are_equal("0", xtd::string::format("{0:x}", day::sunday));
    }
    
    void test_method_(format_tuesday_with_invalid_argument) {
      assert::throws<xtd::format_exception>([] {xtd::string::format("{0:e}", day::tuesday);});
    }
  };
}
