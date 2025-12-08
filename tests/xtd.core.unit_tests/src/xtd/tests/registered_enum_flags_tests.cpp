#include <xtd/as>
#include <xtd/enum>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

enum_(, registered_enum_flags_test,
  none,
  one = 0b1,
  two = 0b10,
  three = 0b100,
  four = 0b1000
);

flags_attribute_(, registered_enum_flags_test);

namespace xtd::tests {
  class test_class_(registered_enum_flags_tests) {
    auto test_method_(format) {
      assert::are_equal("none", string::format("{}", registered_enum_flags_test::none));
      assert::are_equal("one", string::format("{}", registered_enum_flags_test::one));
      assert::are_equal("two", string::format("{}", registered_enum_flags_test::two));
      assert::are_equal("three", string::format("{}", registered_enum_flags_test::three));
      assert::are_equal("four", string::format("{}", registered_enum_flags_test::four));
      assert::are_equal("one, two", string::format("{}", registered_enum_flags_test::one | registered_enum_flags_test::two));
      assert::are_equal("three, four", string::format("{}", registered_enum_flags_test::three | registered_enum_flags_test::four));
      assert::are_equal("one, two, three, four", string::format("{}", registered_enum_flags_test::none | registered_enum_flags_test::one | registered_enum_flags_test::two | registered_enum_flags_test::three | registered_enum_flags_test::four));
    }
    
    auto test_method_(format_with_invalid_enum) {
      assert::are_equal("16", string::format("{}", as<registered_enum_flags_test>(16)));
    }
    
    auto test_method_(format_with_specified_format) {
      assert::are_equal("0b1100", string::format("0b{:b}", registered_enum_flags_test::three | registered_enum_flags_test::four));
      assert::are_equal("0b1100", string::format("0b{:B}", registered_enum_flags_test::three | registered_enum_flags_test::four));
      assert::are_equal("12", string::format("{:d}", registered_enum_flags_test::three | registered_enum_flags_test::four));
      assert::are_equal("12", string::format("{:D}", registered_enum_flags_test::three | registered_enum_flags_test::four));
      assert::are_equal("three, four", string::format("{:g}", registered_enum_flags_test::three | registered_enum_flags_test::four));
      assert::are_equal("three, four", string::format("{:G}", registered_enum_flags_test::three | registered_enum_flags_test::four));
      assert::are_equal("014", string::format("0{:o}", registered_enum_flags_test::three | registered_enum_flags_test::four));
      assert::are_equal("014", string::format("0{:O}", registered_enum_flags_test::three | registered_enum_flags_test::four));
      assert::are_equal("0xc", string::format("0x{:x}", registered_enum_flags_test::three | registered_enum_flags_test::four));
      assert::are_equal("0xC", string::format("0x{:X}", registered_enum_flags_test::three | registered_enum_flags_test::four));
    }
    
    auto test_method_(parse) {
      assert::are_equal(registered_enum_flags_test::none, string::parse<registered_enum_flags_test>("none"));
      assert::are_equal(registered_enum_flags_test::one, string::parse<registered_enum_flags_test>("one"));
      assert::are_equal(registered_enum_flags_test::two, string::parse<registered_enum_flags_test>("two"));
      assert::are_equal(registered_enum_flags_test::three, string::parse<registered_enum_flags_test>("three"));
      assert::are_equal(registered_enum_flags_test::four, string::parse<registered_enum_flags_test>("four"));
      assert::are_equal(registered_enum_flags_test::one | registered_enum_flags_test::two, string::parse<registered_enum_flags_test>("one, two"));
      assert::are_equal(registered_enum_flags_test::three | registered_enum_flags_test::four, string::parse<registered_enum_flags_test>("three, four"));
      
      assert::are_equal(registered_enum_flags_test::none, string::parse<registered_enum_flags_test>("0"));
      assert::are_equal(registered_enum_flags_test::one, string::parse<registered_enum_flags_test>("1"));
      assert::are_equal(registered_enum_flags_test::two, string::parse<registered_enum_flags_test>("2"));
      assert::are_equal(registered_enum_flags_test::three, string::parse<registered_enum_flags_test>("4"));
      assert::are_equal(registered_enum_flags_test::four, string::parse<registered_enum_flags_test>("8"));
      assert::are_equal(registered_enum_flags_test::one | registered_enum_flags_test::two, string::parse<registered_enum_flags_test>("3"));
      assert::are_equal(registered_enum_flags_test::three | registered_enum_flags_test::four, string::parse<registered_enum_flags_test>("12"));
    }
    
    auto test_method_(parse_with_invalid_enum) {
      assert::are_equal(as<registered_enum_flags_test>(16), string::parse<registered_enum_flags_test>("16"));
      assert::throws<format_exception>([] {string::parse<registered_enum_flags_test>("five");});
    }
  };
}
