#include <xtd/ustring>
#include <xtd/format_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  enum class wday {
    sunday,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday
  };
};

template<> struct xtd::enum_register<xtd::tests::wday> {
  explicit operator auto() const noexcept {return xtd::enum_collection<tests::wday> {{xtd::tests::wday::sunday,  "sunday"}, {xtd::tests::wday::monday, "monday"}, {xtd::tests::wday::tuesday, "tuesday"}, {xtd::tests::wday::wednesday, "wednesday"}, {xtd::tests::wday::thursday, "thursday"}, {xtd::tests::wday::friday, "friday"}, {xtd::tests::wday::saturday, "saturday"}};}
};

namespace xtd::tests {
  class test_class_(wstring_enum_class_format_tests) {
    void test_method_(format_sunday_with_default_argument) {
      assert::are_equal(L"sunday", xtd::ustring::format(L"{0}", wday::sunday), csf_);
    }
    
    void test_method_(format_monday_with_left_alignment) {
      assert::are_equal(L"    monday", ustring::format(L"{0,10}", wday::monday), csf_);
    }
    
    void test_method_(format_tuesday_with_right_alignment) {
      assert::are_equal(L"tuesday   ", ustring::format(L"{0, -10}", wday::tuesday), csf_);
    }
    
    void test_method_(format_wednesday_with_binary_argument) {
      assert::are_equal(L"11", xtd::ustring::format(L"{0:b}", wday::wednesday), csf_);
    }
    
    void test_method_(format_thursday_with_decimal_argument) {
      assert::are_equal(L"4", xtd::ustring::format(L"{0:d}", wday::thursday), csf_);
    }
    
    void test_method_(format_friday_with_general_argument) {
      assert::are_equal(L"friday", xtd::ustring::format(L"{0:g}", wday::friday), csf_);
    }
    
    void test_method_(format_saturday_with_octal_argument) {
      assert::are_equal(L"6", xtd::ustring::format(L"{0:o}", wday::saturday), csf_);
    }
    
    void test_method_(format_sunday_with_hexadecimal_argument) {
      assert::are_equal(L"0", xtd::ustring::format(L"{0:x}", wday::sunday), csf_);
    }
    
    void test_method_(format_tuesday_with_invalid_argument) {
      assert::throws<xtd::format_exception>([] {xtd::ustring::format(L"{0:e}", wday::tuesday);}, csf_);
    }
  };
}
