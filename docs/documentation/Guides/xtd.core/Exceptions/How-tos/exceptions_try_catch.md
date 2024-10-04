# How to use the try/catch block to catch exceptions (xtd.core)

Place any code statements that might raise or throw an exception in a `try` block, and place statements used to handle the exception or exceptions in one or more `catch` blocks below the `try` block. 
Each `catch` block includes the exception type and can contain additional statements needed to handle that exception type.

In the following example, a [stream_reader](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1stream__reader.html) opens a file called *data.txt* and retrieves a line from the file.
Since the code might throw any of three exceptions, it's placed in a `try` block. 
Three `catch` blocks catch the exceptions and handle them by displaying the results to the console.

```cpp
#include <xtd/xtd>

using namespace xtd;
using namespace xtd::io;

class process_file {
public:
  static void main() {
    try {
      block_scope_ (auto sr = stream_reader {"data.txt"}) {
        console::write_line("The first line of this file is {}", sr.read_line());
      }
    } catch (const file_not_found_exception& e) {
      console::write_line("The file was not found: '{}'", e);
    } catch (const directory_not_found_exception& e) {
      console::write_line("The directory was not found: '{}'", e);
    } catch (const io_exception& e) {
      console::write_line("The file could not be opened: '{}'", e);
    }
  }
};

startup_(process_file::main);
```

# See also
​
* [Exceptions](/docs/documentation/Guides/xtd.core/Exceptions/overview)
* [Guides](/docs/documentation/Guides)
* [Documentation](/docs/documentation)

[//]: # (https://learn.microsoft.com/en-us/dotnet/standard/exceptions/how-to-use-the-try-catch-block-to-catch-exceptions)
