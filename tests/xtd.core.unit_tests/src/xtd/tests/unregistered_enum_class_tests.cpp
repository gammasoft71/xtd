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
  public:
    void test_method_(format) {
      assert::are_equal("0", ustring::format("{}", unregistered_enum_class_test::none), csf_);
      assert::are_equal("1", ustring::format("{}", unregistered_enum_class_test::one), csf_);
      assert::are_equal("2", ustring::format("{}", unregistered_enum_class_test::two), csf_);
      assert::are_equal("3", ustring::format("{}", unregistered_enum_class_test::three), csf_);
      assert::are_equal("4", ustring::format("{}", unregistered_enum_class_test::four), csf_);
    }
    
    void test_method_(format_with_invalid_enum) {
      assert::are_equal("5", ustring::format("{}", as<unregistered_enum_class_test>(5)), csf_);
    }
    
    void test_method_(format_with_specified_format) {
      assert::are_equal("0b100", ustring::format("0b{:b}", unregistered_enum_class_test::four), csf_);
      assert::are_equal("0b100", ustring::format("0b{:B}", unregistered_enum_class_test::four), csf_);
      assert::are_equal("4", ustring::format("{:d}", unregistered_enum_class_test::four), csf_);
      assert::are_equal("4", ustring::format("{:D}", unregistered_enum_class_test::four), csf_);
      assert::are_equal("4", ustring::format("{:g}", unregistered_enum_class_test::four), csf_);
      assert::are_equal("4", ustring::format("{:G}", unregistered_enum_class_test::four), csf_);
      assert::are_equal("04", ustring::format("0{:o}", unregistered_enum_class_test::four), csf_);
      assert::are_equal("04", ustring::format("0{:O}", unregistered_enum_class_test::four), csf_);
      assert::are_equal("0x4", ustring::format("0x{:x}", unregistered_enum_class_test::four), csf_);
      assert::are_equal("0x4", ustring::format("0x{:X}", unregistered_enum_class_test::four), csf_);
    }
    
    void test_method_(parse) {
      assert::are_equal(unregistered_enum_class_test::none, ustring::parse<unregistered_enum_class_test>("0"), csf_);
      assert::are_equal(unregistered_enum_class_test::one, ustring::parse<unregistered_enum_class_test>("1"), csf_);
      assert::are_equal(unregistered_enum_class_test::two, ustring::parse<unregistered_enum_class_test>("2"), csf_);
      assert::are_equal(unregistered_enum_class_test::three, ustring::parse<unregistered_enum_class_test>("3"), csf_);
      assert::are_equal(unregistered_enum_class_test::four, ustring::parse<unregistered_enum_class_test>("4"), csf_);
    }
    
    void test_method_(parse_with_invalid_enum) {
      assert::are_equal(as<unregistered_enum_class_test>(5), ustring::parse<unregistered_enum_class_test>("5"), csf_);
      assert::throws<format_exception>([] {ustring::parse<unregistered_enum_class_test>("one");}, csf_);
    }
  };
}
