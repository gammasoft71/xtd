| [Home](home.md) | [Downloads](downloads.md) | [Examples](examples.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd.tunit) | [Project](https://sourceforge.net/projects/tunitpro/) | [Contact](contact.md) | [Gammasoft](https://gammasoft71.wixsite.com/gammasoft) |

# Example

The classic first application 'Hello World'.

src/tunit_hello_world.cpp:

```c++
#include <xtd/tunit>
#include <string>

using namespace std;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(hello_world_test) {
  public:
    void test_method_(create_string_from_literal) {
      string s = "Hello, World!";
      assert::are_equal_("Hello, World!", s);
    }
    
    void test_method_(create_string_from_chars) {
      string s = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
      assert::are_equal_("Hello, World!", s);
    }
  };
}

// The main entry point for the application.
int main(int argc, char* argv[]) {
  return console_unit_test(argv, argc).run();
}
```

CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.3)

project(tunit_hello_world)
find_package(xtd.tunit REQUIRED)
add_executable(${PROJECT_NAME} src/tunit_hello_world.cpp)
target_link_libraries(${PROJECT_NAME} xtd.tunit)
```

Output:
```
Start 2 tests from 1 test case
  Start 2 tests from hello_world_test
    PASSED create_string_from_literal (0 ms total)
    PASSED create_string_from_chars (0 ms total)
  End 2 tests from hello_world_test (0 ms total) 

  Summary :
    PASSED 2 tests.
End 2 tests from 1 test case ran. (0 ms total)
```

[Click gere to see more examples](../examples)

______________________________________________________________________________________________

© 2019 Gammasoft.
