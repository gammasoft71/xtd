#include <xtd/as>
#include <xtd/enum_class>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

enum_class_(, registered_enum_class_test,
  none,
  one,
  two,
  three,
  four
);

namespace xtd::tests {
  class test_class_(registered_enum_class_tests) {
    void test_method_(format) {
      assert::are_equal("none", string::format("{}", registered_enum_class_test::none), csf_);
      assert::are_equal("one", string::format("{}", registered_enum_class_test::one), csf_);
      assert::are_equal("two", string::format("{}", registered_enum_class_test::two), csf_);
      assert::are_equal("three", string::format("{}", registered_enum_class_test::three), csf_);
      assert::are_equal("four", string::format("{}", registered_enum_class_test::four), csf_);
    }
    
    void test_method_(format_with_invalid_enum) {
      assert::are_equal("5", string::format("{}", as<registered_enum_class_test>(5)), csf_);
    }
    
    void test_method_(format_with_specified_format) {
      assert::are_equal("0b100", string::format("0b{:b}", registered_enum_class_test::four), csf_);
      assert::are_equal("0b100", string::format("0b{:B}", registered_enum_class_test::four), csf_);
      assert::are_equal("4", string::format("{:d}", registered_enum_class_test::four), csf_);
      assert::are_equal("4", string::format("{:D}", registered_enum_class_test::four), csf_);
      assert::are_equal("four", string::format("{:g}", registered_enum_class_test::four), csf_);
      assert::are_equal("four", string::format("{:G}", registered_enum_class_test::four), csf_);
      assert::are_equal("04", string::format("0{:o}", registered_enum_class_test::four), csf_);
      assert::are_equal("04", string::format("0{:O}", registered_enum_class_test::four), csf_);
      assert::are_equal("0x4", string::format("0x{:x}", registered_enum_class_test::four), csf_);
      assert::are_equal("0x4", string::format("0x{:X}", registered_enum_class_test::four), csf_);
    }
    
    void test_method_(parse) {
      assert::are_equal(registered_enum_class_test::none, string::parse<registered_enum_class_test>("none"), csf_);
      assert::are_equal(registered_enum_class_test::one, string::parse<registered_enum_class_test>("one"), csf_);
      assert::are_equal(registered_enum_class_test::two, string::parse<registered_enum_class_test>("two"), csf_);
      assert::are_equal(registered_enum_class_test::three, string::parse<registered_enum_class_test>("three"), csf_);
      assert::are_equal(registered_enum_class_test::four, string::parse<registered_enum_class_test>("four"), csf_);
      
      assert::are_equal(registered_enum_class_test::none, string::parse<registered_enum_class_test>("0"), csf_);
      assert::are_equal(registered_enum_class_test::one, string::parse<registered_enum_class_test>("1"), csf_);
      assert::are_equal(registered_enum_class_test::two, string::parse<registered_enum_class_test>("2"), csf_);
      assert::are_equal(registered_enum_class_test::three, string::parse<registered_enum_class_test>("3"), csf_);
      assert::are_equal(registered_enum_class_test::four, string::parse<registered_enum_class_test>("4"), csf_);
    }
    
    void test_method_(parse_with_invalid_enum) {
      assert::are_equal(as<registered_enum_class_test>(5), string::parse<registered_enum_class_test>("5"), csf_);
      assert::throws<format_exception>([] {string::parse<registered_enum_class_test>("five");}, csf_);
    }
  };
}
