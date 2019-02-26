#define TUNIT_CONFIG_MAIN
#include <xtd/tunit>
#include <string>

using namespace xtd::tunit;

namespace unit_tests {
  // The class test must be declared with test_class_ helper.
  class test_class_(test) {
  public:
    void test_method_(test_case1) {
      std::string s = "Hello";
      assert::is_true(s == "Hello");
    }
  };
}

// This code can produce the following output:
//
// Start 2 tests from 1 test case
//   Start 2 tests from test
//     SUCCEED test_case1 (0 ms total)
//     SUCCEED test_case2 (0 ms total)
//   End 2 tests from test (0 ms total)
//
//   Summary :
//     SUCCEED 2 tests.
// End 2 tests from 1 test case ran. (0 ms total)
//
// You have 1 ignored test
