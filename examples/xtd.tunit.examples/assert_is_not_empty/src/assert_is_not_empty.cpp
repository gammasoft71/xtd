#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case_collection_succeed) {
      assert::is_not_empty({0, 1, 2, 3});
    }
    
    void test_method_(test_case_collection_failed) {
      assert::is_not_empty(initializer_list<int> {});
    }
    
    void test_method_(test_case_string_succeed) {
      assert::is_not_empty("string");
    }
    
    void test_method_(test_case_string_failed) {
      assert::is_not_empty("");
    }
  };
}

int main() {
  return console_unit_test().run();
}

// This code produces the following output:
//
// Start 4 tests from 1 test case
// Run tests:
//   SUCCEED test.test_case_collection_succeed (0 ms total)
//   FAILED  test.test_case_collection_failed (0 ms total)
//     Expected: collection not <empty>
//     But was:  <empty>
//     Stack Trace: in |---OMITTED---|/assert_is_not_empty.cpp:13
//   SUCCEED test.test_case_string_succeed (0 ms total)
//   FAILED  test.test_case_string_failed (0 ms total)
//     Expected: collection not <empty>
//     But was:  <empty>
//     Stack Trace: in |---OMITTED---|/assert_is_not_empty.cpp:21
//
// Test results:
//   SUCCEED 2 tests.
//   FAILED  2 tests.
// End 4 tests from 1 test case ran. (0 ms total)
