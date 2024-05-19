#include <xtd/xtd.tunit>
#include <sstream>

using namespace std;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
    void test_method_(test_case1) {
    }
  };
}

auto main() -> int {
  // create your own ostream in this case a string stream for example
  auto ss = stringstream {};
  
  // create and run an ostream_unit_test
  auto result = ostream_unit_test(ss).run();
  
  // display string stream on cout line by line
  auto line = string {};
  while (std::getline(ss, line))
    cout << line << endl;
    
  return result;
}

// This code can produce the following output:
//
// Start 1 test from 1 test case
// Run tests:
//   SUCCEED unit_tests::test.test_case1 (0 ms total)
//
// Test results:
//   SUCCEED 1 test.
// End 1 test from 1 test case ran. (0 ms total)
