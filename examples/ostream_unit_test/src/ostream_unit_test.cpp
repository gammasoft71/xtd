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
  // create your own ostream in this case a string stream for example
  stringstream ss;
  
  // create and run an ostream_unit_test
  int result = ostream_unit_test(ss, argv, argc).run();
  
  // display string stream on cout line by line
  string line;
  while(std::getline(ss, line))
    cout << line << endl;
  
  return result;
}

// This code can produce the following output:
//
// Start 1 test from 1 test case
//   Start 1 test from test
//     PASSED test_case1 (0 ms total)
//   End 1 test from test (0 ms total)
//
//   Summary :
//     PASSED 1 test.
// End 1 test from 1 test case ran. (0 ms total)
