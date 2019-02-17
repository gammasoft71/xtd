#include <xtd/tunit>
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

// The main entry point for the application.
int main(int argc, char* argv[]) {
  std::stringstream ss;
  int result = ostream_unit_test(ss, argv, argc).run();
  cout << ss.str();
  return result;
}

// This code can produce the following output:
//
// Start 1 tests from 1 test case
//   Start 1 tests from test
//     PASSED test_case1 (0 ms total)
//   End 1 tests from test (0 ms total)
//
//   Summary :
//     PASSED & tests.
// End 1 tests from 1 test case ran. (0 ms total)
