#include <xtd/xtd.tunit>
#include <memory>

using namespace std;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case_succeed) {
      shared_ptr<string> s;
      assert::is_null(s);
    }

    void test_method_(test_case_failed) {
      shared_ptr<string> s = make_shared<string>("string");
      assert::is_null(s);
    }
  };
}

int main() {
  return console_unit_test().run();
}

// This code produces the following output:
//
// Start 2 tests from 1 test case
// Run tests:
//   SUCCEED test.test_case_succeed (0 ms total)
//   FAILED  test.test_case_failed (0 ms total)
//     Expected: null
//     But was:  not null
//     Stack Trace: in |---OMITTED---|/assert_is_null.cpp:15
//
// Test results:
//   SUCCEED 1 test.
//   FAILED  1 test.
// End 2 tests from 1 test case ran. (0 ms total)
