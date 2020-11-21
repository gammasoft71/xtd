#include <xtd/xtd.tunit>
#include <sstream>

using namespace std;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case1) {
    }
  };
}

int main() {
  return console_unit_test().run();
  // is same :
  // return unit_test(std::make_unique<ostream_event_listener>(cout)).run();
}

// This code can produce the following output:
//
// Start 1 test from 1 test case
// Run tests:
//   SUCCEED test.test_case1 (0 ms total)
//
// Test results:
//   SUCCEED 1 test.
// End 1 test from 1 test case ran. (0 ms total)
