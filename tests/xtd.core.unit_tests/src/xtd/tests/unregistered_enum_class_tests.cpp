#include <xtd/as>
#include <xtd/enum_class>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

enum class unregistered_enum_class_test {
  none,
  one,
  two,
  three,
  four
};

namespace xtd::tests {
  class test_class_(unregistered_enum_class_tests) {
    void test_method_(format) {
      assert::are_equal("0", string::format("{}", unregistered_enum_class_test::none));
      assert::are_equal("1", string::format("{}", unregistered_enum_class_test::one));
      assert::are_equal("2", string::format("{}", unregistered_enum_class_test::two));
      assert::are_equal("3", string::format("{}", unregistered_enum_class_test::three));
      assert::are_equal("4", string::format("{}", unregistered_enum_class_test::four));
    }
    
    void test_method_(format_with_invalid_enum) {
      assert::are_equal("5", string::format("{}", as<unregistered_enum_class_test>(5)));
    }
    
    void test_method_(format_with_specified_format) {
      assert::are_equal("0b100", string::format("0b{:b}", unregistered_enum_class_test::four));
      assert::are_equal("0b100", string::format("0b{:B}", unregistered_enum_class_test::four));
      assert::are_equal("4", string::format("{:d}", unregistered_enum_class_test::four));
      assert::are_equal("4", string::format("{:D}", unregistered_enum_class_test::four));
      assert::are_equal("4", string::format("{:g}", unregistered_enum_class_test::four));
      assert::are_equal("4", string::format("{:G}", unregistered_enum_class_test::four));
      assert::are_equal("04", string::format("0{:o}", unregistered_enum_class_test::four));
      assert::are_equal("04", string::format("0{:O}", unregistered_enum_class_test::four));
      assert::are_equal("0x4", string::format("0x{:x}", unregistered_enum_class_test::four));
      assert::are_equal("0x4", string::format("0x{:X}", unregistered_enum_class_test::four));
    }
    
    void test_method_(parse) {
      assert::are_equal(unregistered_enum_class_test::none, string::parse<unregistered_enum_class_test>("0"));
      assert::are_equal(unregistered_enum_class_test::one, string::parse<unregistered_enum_class_test>("1"));
      assert::are_equal(unregistered_enum_class_test::two, string::parse<unregistered_enum_class_test>("2"));
      assert::are_equal(unregistered_enum_class_test::three, string::parse<unregistered_enum_class_test>("3"));
      assert::are_equal(unregistered_enum_class_test::four, string::parse<unregistered_enum_class_test>("4"));
    }
    
    void test_method_(parse_with_invalid_enum) {
      assert::are_equal(as<unregistered_enum_class_test>(5), string::parse<unregistered_enum_class_test>("5"));
      assert::throws<format_exception>([] {string::parse<unregistered_enum_class_test>("one");});
    }
  };
}
