#include <xtd/xtd>

namespace unit_tests {
  class test_class_(assert_syntax_tests) {
    auto test_method_(equality) {
      // Constraint Syntax
      assert_that(2 + 2).is().equal_to(4);
      assert_that(2 + 2).is().not_().equal_to(5);

      // Classic Syntax
      assert::are_equal(4, 2 + 2);
      assert::are_not_equal(5, 2 + 2);
    }
    
    auto test_method_(empty) {
      // Constraint Syntax
      assert_that("").is().empty();
      assert_that(array<int> {}).is().empty();
      assert_that("Hello!").is().not_().empty();
      assert_that(array {1, 2, 3}).is().not_().empty();
      
      // Classic Syntax
      assert::is_empty("");
      assert::is_empty(array<int> {});
      assert::is_not_empty("Hello!");
      assert::is_not_empty(array {1, 2, 3});
    }
    
    auto test_method_(same) {
      // Constraint Syntax
      auto v1 = 1;
      auto& v2 = v1;
      auto v3 = v1;
      assert_that(v2).is().same_as(v1);
      assert_that(v3).is().not_().same_as(v1);
      
      // Classic Syntax
      assert::are_same(v1, v2);
      assert::are_not_same(v1, v3);
    }
  };
}

auto main() -> int {
  return console_unit_test {}.run();
}

// output :
//
// Start 3 tests from 1 test case
// Run tests:
//   SUCCEED unit_tests::assert_syntax_tests.equality [< 1 ms]
//   SUCCEED unit_tests::assert_syntax_tests.empty [< 1 ms]
//   SUCCEED unit_tests::assert_syntax_tests.same [< 1 ms]
//
// Test results:
//   SUCCEED 3 tests.
// End 3 tests from 1 test case ran. [0.0002 seconds]
