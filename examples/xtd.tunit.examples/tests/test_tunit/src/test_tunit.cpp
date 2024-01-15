#include <xtd/xtd.tunit>
#include <xtd/typeof>
#include <string>

using namespace std;
using namespace xtd::tunit;

namespace unit_tests {
  class test_tunit;
  
  test_class_attribute<test_tunit> test_tunit_class_attr {typeof_<test_tunit>().full_name().replace("::", ".")};
  class test_tunit : public test_class {
  public:
    test_method_attribute create_string_from_literal_attr {"create_string_from_literal", *this, &test_tunit::create_string_from_literal};
    void create_string_from_literal() {
      auto s = string {"Hello, World!"};
      valid::are_equal(13, s.size());
      assert::are_equal("Hello, World!", s);
    }
    
    test_method_attribute create_string_from_chars_attr {"create_string_from_chars", *this, &test_tunit::create_string_from_chars};
    void create_string_from_chars() {
      auto s = string {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
      valid::are_equal(13, s.size());
      string_assert::starts_with("Hello,", s);
      string_assert::ends_with(" World!", s);
    }
  };
}

auto main()->int {
  return console_unit_test().run();
}

// This code produces the following output:
//
// Start 2 tests from 1 test case
// Run tests:
//   SUCCEED test_tunit.create_string_from_literal (0 ms total)
//   SUCCEED test_tunit.create_string_from_chars (0 ms total)
//
// Test results:
//   SUCCEED 2 tests.
// End 2 tests from 1 test case ran. (0 ms total)
