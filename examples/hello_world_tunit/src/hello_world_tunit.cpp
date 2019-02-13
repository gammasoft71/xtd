#include <xtd/xtd>
#include <string>

using namespace std;
using namespace xtd::tunit

namespace unit_tests {
  class test_class_(hello_world_test) {
  public:
    void test_method_(create_string_from_literal) {
      string s = "Hello, World!";
      sssert::are_equal("Hello, World!", s);
    }
    
    void test_method_(create_string_from_chars) {
      string s = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
      assert::are_equal("Hello, World!", s);
    }
  };
}

// The main entry point for the application.
int main(int argc, char* argv[]) {
  return unit_test(argv, argc).run();
}

// This code produces the following output:
//
// Start 2 tests from 1 test case
//   Start 2 tests from hello_world_test
//     PASSED hello_world_test.create_string_from_literal (0 ms)
//     PASSED hello_world_test.create_string_from_chars (0 ms)
//   End 2 tests from hello_world_test (3 ms total)
//
//   Summary :
//     PASSED 2 tests.
// End 2 tests from 1 test case ran. (4 ms total)
