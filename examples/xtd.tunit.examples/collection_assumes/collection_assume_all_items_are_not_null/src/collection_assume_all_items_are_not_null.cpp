#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
    void test_method_(test_case_succeed) {
      auto i1 = 1;
      auto i2 = 2;
      auto a = vector {&i1, &i2};
      collection_assume::all_items_are_not_null(a);
    }
    
    void test_method_(test_case_aborted) {
      auto i1 = 1;
      auto i2 = 2;
      auto a = vector<int*> {&i1, &i2, nullptr};
      collection_assume::all_items_are_not_null(a);
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
//     Expected: all items are not null
//     But was:  < 0x7ffeefbfc8d4, 0x7ffeefbfc8d0, 0x0 >
//     Stack Trace: in |---OMITTED---|/collection_assume_all_items_are_not_null.cpp:15
//
// Test results:
//   SUCCEED 1 test.
//   ABORTED 1 test.
// End 2 tests from 1 test case ran. (0 ms total)
