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
  public:
    void test_method_(format) {
      assert::are_equal("0", ustring::format("{}", unregistered_enum_flags_test::none), csf_);
      assert::are_equal("1", ustring::format("{}", unregistered_enum_flags_test::one), csf_);
      assert::are_equal("2", ustring::format("{}", unregistered_enum_flags_test::two), csf_);
      assert::are_equal("4", ustring::format("{}", unregistered_enum_flags_test::three), csf_);
      assert::are_equal("8", ustring::format("{}", unregistered_enum_flags_test::four), csf_);
      assert::are_equal("3", ustring::format("{}", unregistered_enum_flags_test::one | unregistered_enum_flags_test::two), csf_);
      assert::are_equal("12", ustring::format("{}", unregistered_enum_flags_test::three | unregistered_enum_flags_test::four), csf_);
    }
    
    void test_method_(format_with_invalid_enum) {
      assert::are_equal("16", ustring::format("{}", as<unregistered_enum_flags_test>(16)), csf_);
    }
    
    void test_method_(format_with_specified_format) {
      assert::are_equal("0b1100", ustring::format("0b{:b}", unregistered_enum_flags_test::three | unregistered_enum_flags_test::four), csf_);
      assert::are_equal("0b1100", ustring::format("0b{:B}", unregistered_enum_flags_test::three | unregistered_enum_flags_test::four), csf_);
      assert::are_equal("12", ustring::format("{:d}", unregistered_enum_flags_test::three | unregistered_enum_flags_test::four), csf_);
      assert::are_equal("12", ustring::format("{:D}", unregistered_enum_flags_test::three | unregistered_enum_flags_test::four), csf_);
      assert::are_equal("12", ustring::format("{:g}", unregistered_enum_flags_test::three | unregistered_enum_flags_test::four), csf_);
      assert::are_equal("12", ustring::format("{:G}", unregistered_enum_flags_test::three | unregistered_enum_flags_test::four), csf_);
      assert::are_equal("014", ustring::format("0{:o}", unregistered_enum_flags_test::three | unregistered_enum_flags_test::four), csf_);
      assert::are_equal("014", ustring::format("0{:O}", unregistered_enum_flags_test::three | unregistered_enum_flags_test::four), csf_);
      assert::are_equal("0xc", ustring::format("0x{:x}", unregistered_enum_flags_test::three | unregistered_enum_flags_test::four), csf_);
      assert::are_equal("0xC", ustring::format("0x{:X}", unregistered_enum_flags_test::three | unregistered_enum_flags_test::four), csf_);
    }
    
    void test_method_(parse) {
      assert::are_equal(unregistered_enum_flags_test::none, ustring::parse<unregistered_enum_flags_test>("0"), csf_);
      assert::are_equal(unregistered_enum_flags_test::one, ustring::parse<unregistered_enum_flags_test>("1"), csf_);
      assert::are_equal(unregistered_enum_flags_test::two, ustring::parse<unregistered_enum_flags_test>("2"), csf_);
      assert::are_equal(unregistered_enum_flags_test::three, ustring::parse<unregistered_enum_flags_test>("4"), csf_);
      assert::are_equal(unregistered_enum_flags_test::four, ustring::parse<unregistered_enum_flags_test>("8"), csf_);
      assert::are_equal(unregistered_enum_flags_test::one | unregistered_enum_flags_test::two, ustring::parse<unregistered_enum_flags_test>("3"), csf_);
      assert::are_equal(unregistered_enum_flags_test::three | unregistered_enum_flags_test::four, ustring::parse<unregistered_enum_flags_test>("12"), csf_);
    }
    
    void test_method_(parse_with_invalid_enum) {
      assert::are_equal(as<unregistered_enum_flags_test>(16), ustring::parse<unregistered_enum_flags_test>("16"), csf_);
      assert::throws<format_exception>([] {ustring::parse<unregistered_enum_flags_test>("one");}, csf_);
    }
  };
}
