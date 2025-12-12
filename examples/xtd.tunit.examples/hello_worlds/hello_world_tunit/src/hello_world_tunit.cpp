#include <xtd/xtd>

namespace unit_tests {
  class test_class_(hello_world_test) {
    auto test_method_(create_string_from_literal) {
      auto s = string {"Hello, World!"};
      valid::are_equal(13_z, s.length());
      assert::are_equal("Hello, World!", s);
    }
    
    auto test_method_(create_string_from_chars) {
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
