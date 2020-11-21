#include <xtd/xtd.tunit>

using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case_succeed) {
      int i1 = 1;
      int i2 = 2;
      std::vector<int*> a = {&i1, &i2};
      collection_assert::all_items_are_not_null(a);
    }
    
    void test_method_(test_case_Failed) {
      int i1 = 1;
      int i2 = 2;
      std::vector<int*> a = {&i1, &i2, nullptr};
      collection_assert::all_items_are_not_null(a);
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
//   FAILED  test.test_case_Failed (0 ms total)
//     Expected: all items are not null
//     But was:  < 0x7ffeefbfc8d4, 0x7ffeefbfc8d0, 0x0 >
//     Stack Trace: in |---OMITTED---|/collection_assert_all_items_are_not_null.cpp:15
//
// Test results:
//   SUCCEED 1 test.
//   FAILED  1 test.
// End 2 tests from 1 test case ran. (0 ms total)
