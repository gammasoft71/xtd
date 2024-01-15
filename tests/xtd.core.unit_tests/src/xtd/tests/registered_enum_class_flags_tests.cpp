#include <xtd/enum_class>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

enum_class_(, registered_enum_class_flags_test,
  none,
  one = 0b1,
  two = 0b10,
  three = 0b100,
  four = 0b1000
);

flags_attribute_(, registered_enum_class_flags_test);

namespace xtd::tests {
  class test_class_(registered_enum_class_flags_tests) {
    void test_method_(format) {
      assert::are_equal("none", ustring::format("{}", registered_enum_class_flags_test::none), csf_);
      assert::are_equal("one", ustring::format("{}", registered_enum_class_flags_test::one), csf_);
      assert::are_equal("two", ustring::format("{}", registered_enum_class_flags_test::two), csf_);
      assert::are_equal("three", ustring::format("{}", registered_enum_class_flags_test::three), csf_);
      assert::are_equal("four", ustring::format("{}", registered_enum_class_flags_test::four), csf_);
      assert::are_equal("one, two", ustring::format("{}", registered_enum_class_flags_test::one | registered_enum_class_flags_test::two), csf_);
      assert::are_equal("three, four", ustring::format("{}", registered_enum_class_flags_test::three | registered_enum_class_flags_test::four), csf_);
      assert::are_equal("one, two, three, four", ustring::format("{}", registered_enum_class_flags_test::none | registered_enum_class_flags_test::one | registered_enum_class_flags_test::two | registered_enum_class_flags_test::three | registered_enum_class_flags_test::four), csf_);
    }
    
    void test_method_(format_with_invalid_enum) {
      assert::are_equal("16", ustring::format("{}", as<registered_enum_class_flags_test>(16)), csf_);
    }
    
    void test_method_(format_with_specified_format) {
      assert::are_equal("0b1100", ustring::format("0b{:b}", registered_enum_class_flags_test::three | registered_enum_class_flags_test::four), csf_);
      assert::are_equal("0b1100", ustring::format("0b{:B}", registered_enum_class_flags_test::three | registered_enum_class_flags_test::four), csf_);
      assert::are_equal("12", ustring::format("{:d}", registered_enum_class_flags_test::three | registered_enum_class_flags_test::four), csf_);
      assert::are_equal("12", ustring::format("{:D}", registered_enum_class_flags_test::three | registered_enum_class_flags_test::four), csf_);
      assert::are_equal("three, four", ustring::format("{:g}", registered_enum_class_flags_test::three | registered_enum_class_flags_test::four), csf_);
      assert::are_equal("three, four", ustring::format("{:G}", registered_enum_class_flags_test::three | registered_enum_class_flags_test::four), csf_);
      assert::are_equal("014", ustring::format("0{:o}", registered_enum_class_flags_test::three | registered_enum_class_flags_test::four), csf_);
      assert::are_equal("014", ustring::format("0{:O}", registered_enum_class_flags_test::three | registered_enum_class_flags_test::four), csf_);
      assert::are_equal("0xc", ustring::format("0x{:x}", registered_enum_class_flags_test::three | registered_enum_class_flags_test::four), csf_);
      assert::are_equal("0xC", ustring::format("0x{:X}", registered_enum_class_flags_test::three | registered_enum_class_flags_test::four), csf_);
    }
    
    void test_method_(parse) {
      assert::are_equal(registered_enum_class_flags_test::none, ustring::parse<registered_enum_class_flags_test>("none"), csf_);
      assert::are_equal(registered_enum_class_flags_test::one, ustring::parse<registered_enum_class_flags_test>("one"), csf_);
      assert::are_equal(registered_enum_class_flags_test::two, ustring::parse<registered_enum_class_flags_test>("two"), csf_);
      assert::are_equal(registered_enum_class_flags_test::three, ustring::parse<registered_enum_class_flags_test>("three"), csf_);
      assert::are_equal(registered_enum_class_flags_test::four, ustring::parse<registered_enum_class_flags_test>("four"), csf_);
      assert::are_equal(registered_enum_class_flags_test::one | registered_enum_class_flags_test::two, ustring::parse<registered_enum_class_flags_test>("one, two"), csf_);
      assert::are_equal(registered_enum_class_flags_test::three | registered_enum_class_flags_test::four, ustring::parse<registered_enum_class_flags_test>("three, four"), csf_);
      
      assert::are_equal(registered_enum_class_flags_test::none, ustring::parse<registered_enum_class_flags_test>("0"), csf_);
      assert::are_equal(registered_enum_class_flags_test::one, ustring::parse<registered_enum_class_flags_test>("1"), csf_);
      assert::are_equal(registered_enum_class_flags_test::two, ustring::parse<registered_enum_class_flags_test>("2"), csf_);
      assert::are_equal(registered_enum_class_flags_test::three, ustring::parse<registered_enum_class_flags_test>("4"), csf_);
      assert::are_equal(registered_enum_class_flags_test::four, ustring::parse<registered_enum_class_flags_test>("8"), csf_);
      assert::are_equal(registered_enum_class_flags_test::one | registered_enum_class_flags_test::two, ustring::parse<registered_enum_class_flags_test>("3"), csf_);
      assert::are_equal(registered_enum_class_flags_test::three | registered_enum_class_flags_test::four, ustring::parse<registered_enum_class_flags_test>("12"), csf_);
    }
    
    void test_method_(parse_with_invalid_enum) {
      assert::are_equal(as<registered_enum_class_flags_test>(16), ustring::parse<registered_enum_class_flags_test>("16"), csf_);
      assert::throws<format_exception>([] {ustring::parse<registered_enum_class_flags_test>("five");}, csf_);
    }
  };
}
