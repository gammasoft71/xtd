#include <xtd/enum>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

enum_(, registered_enum_test,
  none,
  one,
  two,
  three,
  four
);

namespace xtd::tests {
  class test_class_(registered_enum_tests) {
  public:
    void test_method_(format) {
      assert::are_equal("none", ustring::format("{}", registered_enum_test::none), csf_);
      assert::are_equal("one", ustring::format("{}", registered_enum_test::one), csf_);
      assert::are_equal("two", ustring::format("{}", registered_enum_test::two), csf_);
      assert::are_equal("three", ustring::format("{}", registered_enum_test::three), csf_);
      assert::are_equal("four", ustring::format("{}", registered_enum_test::four), csf_);
    }
    
    void test_method_(format_with_invalid_enum) {
      assert::are_equal("5", ustring::format("{}", as<registered_enum_test>(5)), csf_);
    }
    
    void test_method_(format_with_specified_format) {
      assert::are_equal("0b100", ustring::format("0b{:b}", registered_enum_test::four), csf_);
      assert::are_equal("0b100", ustring::format("0b{:B}", registered_enum_test::four), csf_);
      assert::are_equal("4", ustring::format("{:d}", registered_enum_test::four), csf_);
      assert::are_equal("4", ustring::format("{:D}", registered_enum_test::four), csf_);
      assert::are_equal("four", ustring::format("{:g}", registered_enum_test::four), csf_);
      assert::are_equal("four", ustring::format("{:G}", registered_enum_test::four), csf_);
      assert::are_equal("04", ustring::format("0{:o}", registered_enum_test::four), csf_);
      assert::are_equal("04", ustring::format("0{:O}", registered_enum_test::four), csf_);
      assert::are_equal("0x4", ustring::format("0x{:x}", registered_enum_test::four), csf_);
      assert::are_equal("0x4", ustring::format("0x{:X}", registered_enum_test::four), csf_);
    }
    
    void test_method_(parse) {
      assert::are_equal(registered_enum_test::none, ustring::parse<registered_enum_test>("none"), csf_);
      assert::are_equal(registered_enum_test::one, ustring::parse<registered_enum_test>("one"), csf_);
      assert::are_equal(registered_enum_test::two, ustring::parse<registered_enum_test>("two"), csf_);
      assert::are_equal(registered_enum_test::three, ustring::parse<registered_enum_test>("three"), csf_);
      assert::are_equal(registered_enum_test::four, ustring::parse<registered_enum_test>("four"), csf_);
      
      assert::are_equal(registered_enum_test::none, ustring::parse<registered_enum_test>("0"), csf_);
      assert::are_equal(registered_enum_test::one, ustring::parse<registered_enum_test>("1"), csf_);
      assert::are_equal(registered_enum_test::two, ustring::parse<registered_enum_test>("2"), csf_);
      assert::are_equal(registered_enum_test::three, ustring::parse<registered_enum_test>("3"), csf_);
      assert::are_equal(registered_enum_test::four, ustring::parse<registered_enum_test>("4"), csf_);
    }
    
    void test_method_(parse_with_invalid_enum) {
      assert::are_equal(as<registered_enum_test>(5), ustring::parse<registered_enum_test>("5"), csf_);
      assert::throws<format_exception>([] {ustring::parse<registered_enum_test>("five");}, csf_);
    }
  };
}
