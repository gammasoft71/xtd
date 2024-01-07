#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case_succeed) {
      auto a = vector {1, 2, 3, 4};
      collection_assume::is_not_empty(a);
    }
    
    void test_method_(test_case_aborted) {
      auto a = vector<int> {};
      collection_assume::is_not_empty(a);
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
//   SUCCEED test.test_case_succeed (0 ms total)
//   ABORTED test.test_case_aborted (0 ms total)
//     Test aborted
//     Expected: not <empty>
//     But was:  <empty>
//     Stack Trace: in |---OMITTED---|/collection_assume_is_not_empty.cpp:13
//
// Test results:
//   SUCCEED 1 test.
//   ABORTED 1 test.
// End 2 tests from 1 test case ran. (0 ms total)
