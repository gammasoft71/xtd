| [Home](home.md) | [Downloads](downloads.md) | [Examples](examples.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd.strings) | [Project](https://sourceforge.net/projects/stringspro/) | [Contact](contact.md) | [Gammasoft](https://gammasoft71.wixsite.com/gammasoft) |

# Example

The classic first application 'Hello World'.

src/strings_hello_world.cpp:

```c++
#include <xtd/strings>
#include <iostream>

using namespace std;
using namespace string_literals;
using namespace xtd;

// The main entry point for the application.
int main() {
  cout << strings::format("{}, {}!", "Hello", "World"s) << endl;
}```

CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.3)

project(strings_hello_world)
find_package(xtd.tunit REQUIRED)
add_executable(${PROJECT_NAME} src/tstrings_hello_world.cpp)
target_link_libraries(${PROJECT_NAME} xtd.strings)
```

Output:

```
Hello, World!
```

[Click here to see more examples](../examples)

______________________________________________________________________________________________

© 2019 Gammasoft.
