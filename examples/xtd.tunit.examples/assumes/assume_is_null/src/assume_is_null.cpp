#include <xtd/xtd.tunit>
#include <memory>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case_succeed) {
      auto s = shared_ptr<ustring> {};
      assume::is_null(s);
    }
    
    void test_method_(test_case_aborted) {
      auto s = make_shared<ustring>("string");
      assume::is_null(s);
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
//     Expected: null
//     But was:  not null
//     Stack Trace: in |---OMITTED---|/assume_is_null.cpp:15
//
// Test results:
//   SUCCEED 1 test.
//   ABORTED 1 test.
// End 2 tests from 1 test case ran. (0 ms total)
