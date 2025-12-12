#include <xtd/xtd>

namespace unit_tests {
  class hello_world_test;
  
  test_class_attribute<hello_world_test> hello_world_test_class_attr {"unit_tests::hello_world_test"};
  class hello_world_test : public test_class {
    test_method_attribute create_string_from_literal_attr {"create_string_from_literal", *this, &hello_world_test::create_string_from_literal};
    auto create_string_from_literal() -> void {
      auto s = string {"Hello, World!"};
      valid::are_equal(13_z, s.length());
      assert::are_equal("Hello, World!", s);
    }
    
    test_method_attribute create_string_from_chars_attr {"create_string_from_chars", *this, &hello_world_test::create_string_from_chars};
    auto create_string_from_chars() -> void {
      auto s = string {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
      valid::are_equal(13_z, s.length());
      string_assert::starts_with("Hello,", s);
      string_assert::does_end_with(" World!", s);
    }
  };
}

auto main() -> int {
  return console_unit_test().run();
}

// This code produces the following output :
//
// Start 2 tests from 1 test case
// Run tests:
//   SUCCEED unit_tests::hello_world_test.create_string_from_literal [< 1 ms]
//   SUCCEED unit_tests::hello_world_test.create_string_from_chars [< 1 ms]
//
// Test results:
//   SUCCEED 2 tests.
// End 2 tests from 1 test case ran. [0.0001 seconds]
