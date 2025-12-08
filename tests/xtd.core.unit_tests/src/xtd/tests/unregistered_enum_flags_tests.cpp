#include <xtd/as>
#include <xtd/enum>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

enum unregistered_enum_flags_test {
  none,
  one = 0b1,
  two = 0b10,
  three = 0b100,
  four = 0b1000
};

inline unregistered_enum_flags_test operator |(unregistered_enum_flags_test lhs, unregistered_enum_flags_test rhs) {return static_cast<unregistered_enum_flags_test>(static_cast<std::underlying_type<unregistered_enum_flags_test>::type>(lhs) | static_cast<std::underlying_type<unregistered_enum_flags_test>::type>(rhs));}

namespace xtd::tests {
  class test_class_(unregistered_enum_flags_tests) {
    auto test_method_(format) {
      assert::are_equal("0", string::format("{}", unregistered_enum_flags_test::none));
      assert::are_equal("1", string::format("{}", unregistered_enum_flags_test::one));
      assert::are_equal("2", string::format("{}", unregistered_enum_flags_test::two));
      assert::are_equal("4", string::format("{}", unregistered_enum_flags_test::three));
      assert::are_equal("8", string::format("{}", unregistered_enum_flags_test::four));
      assert::are_equal("3", string::format("{}", unregistered_enum_flags_test::one | unregistered_enum_flags_test::two));
      assert::are_equal("12", string::format("{}", unregistered_enum_flags_test::three | unregistered_enum_flags_test::four));
    }
    
    auto test_method_(format_with_invalid_enum) {
      assert::are_equal("16", string::format("{}", as<unregistered_enum_flags_test>(16)));
    }
    
    auto test_method_(format_with_specified_format) {
      assert::are_equal("0b1100", string::format("0b{:b}", unregistered_enum_flags_test::three | unregistered_enum_flags_test::four));
      assert::are_equal("0b1100", string::format("0b{:B}", unregistered_enum_flags_test::three | unregistered_enum_flags_test::four));
      assert::are_equal("12", string::format("{:d}", unregistered_enum_flags_test::three | unregistered_enum_flags_test::four));
      assert::are_equal("12", string::format("{:D}", unregistered_enum_flags_test::three | unregistered_enum_flags_test::four));
      assert::are_equal("12", string::format("{:g}", unregistered_enum_flags_test::three | unregistered_enum_flags_test::four));
      assert::are_equal("12", string::format("{:G}", unregistered_enum_flags_test::three | unregistered_enum_flags_test::four));
      assert::are_equal("014", string::format("0{:o}", unregistered_enum_flags_test::three | unregistered_enum_flags_test::four));
      assert::are_equal("014", string::format("0{:O}", unregistered_enum_flags_test::three | unregistered_enum_flags_test::four));
      assert::are_equal("0xc", string::format("0x{:x}", unregistered_enum_flags_test::three | unregistered_enum_flags_test::four));
      assert::are_equal("0xC", string::format("0x{:X}", unregistered_enum_flags_test::three | unregistered_enum_flags_test::four));
    }
    
    auto test_method_(parse) {
      assert::are_equal(unregistered_enum_flags_test::none, string::parse<unregistered_enum_flags_test>("0"));
      assert::are_equal(unregistered_enum_flags_test::one, string::parse<unregistered_enum_flags_test>("1"));
      assert::are_equal(unregistered_enum_flags_test::two, string::parse<unregistered_enum_flags_test>("2"));
      assert::are_equal(unregistered_enum_flags_test::three, string::parse<unregistered_enum_flags_test>("4"));
      assert::are_equal(unregistered_enum_flags_test::four, string::parse<unregistered_enum_flags_test>("8"));
      assert::are_equal(unregistered_enum_flags_test::one | unregistered_enum_flags_test::two, string::parse<unregistered_enum_flags_test>("3"));
      assert::are_equal(unregistered_enum_flags_test::three | unregistered_enum_flags_test::four, string::parse<unregistered_enum_flags_test>("12"));
    }
    
    auto test_method_(parse_with_invalid_enum) {
      assert::are_equal(as<unregistered_enum_flags_test>(16), string::parse<unregistered_enum_flags_test>("16"));
      assert::throws<format_exception>([] {string::parse<unregistered_enum_flags_test>("one");});
    }
  };
}
